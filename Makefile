CC=main.c server.c
OUT=bombtimer
LIB= -lonion -ljson-c

all:
	(cd arduino-serial/ && make)
	gcc $(CC) arduino-serial/arduino-serial-lib.o $(LIB) -o $(OUT)

