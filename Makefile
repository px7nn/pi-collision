CC = gcc
CFLAGS = -Iraylib/include
LDFLAGS = -Lraylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = src/pi-collision.c
OUT = build/pi-collision.exe

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

run: all
	./$(OUT)

clean:
	del $(OUT)