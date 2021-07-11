all: main
	@./main

OBJS=clock1.o clock2.o clock3.o ChainCounter.o LimitCounter.o OverflowCounter.o

main: main.cpp $(OBJS) Makefile
	g++ main.cpp $(OBJS) -o $@

clock1.o:
	cd clock1; g++ -c Clock.cpp -o ../clock1.o
ChainCounter.o:
	cd clock2; g++ -c ChainCounter.cpp -o ../ChainCounter.o
clock2.o:
	cd clock2; g++ -c Clock.cpp -o ../clock2.o

LimitCounter.o:
	cd clock3; g++ -c LimitCounter.cpp -o ../LimitCounter.o
OverflowCounter.o:
	cd clock3; g++ -c OverflowCounter.cpp -o ../OverflowCounter.o
clock3.o:
	cd clock3; g++ -c Clock.cpp -o ../clock3.o

clean:
	rm -f a.out core *.o
