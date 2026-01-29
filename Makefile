CFLAGS = -Wall -Wextra -std=c99 -lraylib -lm

all: raycaster
	make clean
	make run

c: raycaster

run: raycaster
	./raycaster

raycaster: main.c map.c player.c raycaster.c persistence.c
	gcc main.c map.c player.c raycaster.c persistence.c -o raycaster $(CFLAGS)

clean:
	rm raycaster
