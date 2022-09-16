CFLAGS=-Wall -g

TARGET=ex21
TARGET_MARTIN=$(TARGET)_martin
SRC=$(TARGET).c
SRC_MARTIN=$(TARGET_MARTIN).c
ARGS=test

build:
	gcc $(CFLAGS) $(SRC) -o $(TARGET)

build-martin:
	gcc $(CFLAGS) $(SRC_MARTIN) -o $(TARGET_MARTIN)

run: 
	gcc $(CFLAGS) $(SRC) -o $(TARGET) && ./$(TARGET) $(ARGS)

run-martin: 
	gcc $(CFLAGS) $(SRC_MARTIN) -o $(TARGET) && ./$(TARGET_MARTIN) $(ARGS)
