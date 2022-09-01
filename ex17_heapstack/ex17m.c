#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

struct Connection *CONN;

int are_equal_strings(char *str1, char *str2)
{
    return (strcmp(str1, str2) == 0);
}
void Address_print(struct Address *addr);
void Database_close(struct Connection *CONN);

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_close(struct Connection *CONN)
{
    if (CONN) {
        if (CONN->file)
            fclose(CONN->file);
        if (CONN->db)
            free(CONN->db);
        free(CONN);
    }
}

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    if (CONN) Database_close(CONN);

    exit(1);
}

void Database_load(struct Connection *CONN)
{
    int rc = fread(CONN->db, sizeof(struct Database), 1, CONN->file);
    if (rc != 1)
        die("Failed to load database");
}

struct Connection *Database_open(const char *filename, char mode)
{
    CONN = malloc(sizeof(struct Connection));
    if (!CONN)
        die("Memory error");

    CONN->db = malloc(sizeof(struct Database));
    if (!CONN)
        die("Memory error");

    if (mode == 'c') {
        CONN->file = fopen(filename, "w");
    } else {
        CONN->file = fopen(filename, "r+");

        if (CONN->file) {
            Database_load(CONN);
        }
    }

    if (!CONN->file)
        die("Failed to open the file");

    return CONN;
}

void Database_write(struct Connection *CONN)
{
    rewind(CONN->file);

    int rc = fwrite(CONN->db, sizeof(struct Database), 1, CONN->file);
    if (rc != 1)
        die("Failed to write database.");

    rc = fflush(CONN->file);
    if (rc == -1)
        die("Cannot flush database.");
}

void Database_create(struct Connection *CONN)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0 };
        // then just assign it
        CONN->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *CONN, int id, const char *name, const char *email)
{
    struct Address *addr = &CONN->db->rows[id];
    if (addr->set)
        die("Already set, delete it first");

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix

   char *res = strncpy(addr->name, name, MAX_DATA);
  // demonstrate strncpy bug
  if (!res)
     die("Name copy failed");

  res = strncpy(addr->email, email, MAX_DATA);
  if (!res)
     die("Email copy failed");
}

void Database_get(struct Connection *CONN, int id)
{
    struct Address *addr = &CONN->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *CONN, int id)
{
    struct Address addr = { .id = id, .set = 0 };
    CONN->db->rows[id] = addr;
}

void Database_list(struct Connection *CONN)
{
    int i = 0;
    struct Database *db = CONN->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if (cur->set) {
            Address_print(cur);
        }
    }
}

void Database_find_by_name(struct Connection *CONN, char *name)
{
    int i = 0;
    struct Database *db = CONN->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if (cur->set && are_equal_strings(cur->name, name)) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *CONN = Database_open(filename, action);

    int id = 0;

    if (argc > 3 ) id = atoi(argv[3]);
    if (id >= MAX_ROWS) die("There's not that many records.");

    switch (action) {
        case 'c':
            Database_create(CONN);
            Database_write(CONN);
            break;

        case 'g':
            if (argc != 4)
                die("Need an id to get");

            Database_get(CONN, id);
            break;

        case 's':
            if (argc != 6)
                die("Need id, name, email to set");

            Database_set(CONN, id, argv[4], argv[5]);
            Database_write(CONN);
            break;

        case 'd':
            if (argc != 4)
                die("Need id to delete");

            Database_delete(CONN, id);
            Database_write(CONN);
            break;

        case 'l':
            Database_list(CONN);
            break;

        case 'f':
            if (argc != 4)
                die("Need a name to find by");
            Database_find_by_name(CONN, argv[3]);
            break;

        default:
            die("Invalid action; c=create, g=get, s=set, d=del, l=list, f=find");
    }

    Database_close(CONN);

    return 0;
}


