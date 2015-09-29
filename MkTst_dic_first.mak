CFLAGS += -g

test : test.o bag.o tile.o board.o ui.o dictionary.o

Clean : clean
	rm -f ./test

clean :
	rm -f *.o
