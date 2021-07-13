all: main
	@./main

OBJS=clock3.o LimitCounter.o OverflowCounter.o

main: main.cpp $(OBJS) Clock.h LimitCounter.h OverflowCounter.h Makefile
	g++ -std=c++14 main.cpp $(OBJS) -o $@

clock3.o: Clock.cpp Clock.h LimitCounter.h OverflowCOunter.h
	g++ -std=c++14 -c Clock.cpp -o $@
LimitCounter.o: LimitCounter.cpp LimitCounter.h
	g++ -std=c++14 -c LimitCounter.cpp -o $@
OverflowCounter.o: OverflowCounter.cpp OverflowCounter.h LimitCounter.h
	g++ -std=c++14 -c OverflowCounter.cpp -o $@

clean:
	rm -f a.out core *.o
