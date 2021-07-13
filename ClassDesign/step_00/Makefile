all: main
	@./main

OBJS=clock1.o 

main: main.cpp $(OBJS) Clock.h Makefile
	g++ -std=c++14 main.cpp $(OBJS) -o $@

clock1.o: Clock.cpp Clock.h
	g++ -std=c++14 -c Clock.cpp -o $@

clean:
	rm -f a.out core *.o
