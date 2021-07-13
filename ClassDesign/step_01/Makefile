all: main
	@./main

OBJS=clock2.o ChainCounter.o

main: main.cpp $(OBJS) Makefile
	g++ -std=c++14 main.cpp $(OBJS) -o $@

clock2.o: Clock.cpp
	g++ -std=c++14 -c Clock.cpp -o $@
ChainCounter.o: ChainCounter.cpp
	g++ -std=c++14 -c ChainCounter.cpp -o $@

clean:
	rm -f a.out core *.o
