all: main
	@./main

OBJS=clock4.o LimitCounter.o OverflowCounter.o

main: main.cpp $(OBJS) main.cpp Clock.h OverflowCounter.h LimitCounter.h Makefile
	g++ -std=c++14 main.cpp $(OBJS) -o $@

clock4.o: Clock.cpp Clock.h OverflowCounter.h LimitCounter.h
	g++ -std=c++14 -c Clock.cpp -o $@
LimitCounter.o: LimitCounter.cpp LimitCounter.h
	g++ -std=c++14 -c LimitCounter.cpp -o $@
OverflowCounter.o: OverflowCounter.cpp OverflowCounter.h LimitCounter.h
	g++ -std=c++14 -c OverflowCounter.cpp -o $@

clean:
	rm -f a.out core *.o
