CFLAGS = -Wall -Wextra -std=c99 -lraylib -lm

all: raycaster
	make clean
	make run

c: raycaster

run: raycaster
	./raycaster

raycaster: main.c map.c player.c
	gcc main.c map.c player.c -o raycaster $(CFLAGS)

clean:
	rm raycaster
