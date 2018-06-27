CC = gcc -O3

game: main.o snake.o draw.o scenes.o linkedlist.o os_func.o sna.h init.o
	$(CC) $^ -o game.exe -g
%.o: %.c sna.h
	$(CC) -c $<
clean:
	rm -f *.out *.exe *.o


