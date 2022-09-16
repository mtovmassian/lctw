blah: blah.o
	gcc blah.o -o blah # Runs third

blah.o: blah.c
	gcc -c blah.c -o blah.o # Runs second

blah.c:
	printf "#include <stdio.h>\nint main() { printf(\"BLAH!%s\"); return 0; }" "\n" > blah.c # Runs first

run: clean blah
	./blah

clean:
	rm blah*
