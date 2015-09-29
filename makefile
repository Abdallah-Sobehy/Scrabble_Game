CFLAGS += -g

main: main.o bag.o tile.o board.o ui.o dictionary.o

#test.o: test.c
#bag.o: bag.c bag.h
#tile.o: tile.c tile.h


clean :
	rm -f *.o
