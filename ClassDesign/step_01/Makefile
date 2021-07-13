all: main
	@./main

OBJS=clock2.o ChainCounter.o

main: main.cpp $(OBJS) Clock.h ChainCounter.h Makefile
	g++ -std=c++14 main.cpp $(OBJS) -o $@

clock2.o: Clock.cpp Clock.h
	g++ -std=c++14 -c Clock.cpp -o $@
ChainCounter.o: ChainCounter.cpp ChainCounter.h
	g++ -std=c++14 -c ChainCounter.cpp -o $@

clean:
	rm -f a.out core *.o
