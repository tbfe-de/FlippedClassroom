all: main
	@./main

main: StrDupper.o main.cpp NamedValue.h Makefile
	g++ main.cpp StrDupper.o -o $@

StrDupper.o: StrDupper.h StrDupper.cpp
	g++ -c StrDupper.cpp -o $@

clean:
	@rm -f a.out core *.o
