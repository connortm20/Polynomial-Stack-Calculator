
#NOTE: only one of the following two lines can be "active". That is you can
#      either be debuggig your code or you can be optimizing it ... not both
DEBUG = -g # comment this line out if you want kill the "debugger bloat" in code
#OPTIM = -O  # uncomment this line if you want the compier to "optimize" code

OPTS = $(DEBUG) $(OPTIM) -Wall -ansi -pedantic -std=c++20

CC = g++ $(OPTS) -c

LN = g++

OBJS = main.o Term.o Token.o Polynomial.o

termex: $(OBJS)
	$(LN) -o polyCalc $(OBJS)

main.o: main.cpp Polynomial.hpp Term.hpp Token.hpp
	$(CC) main.cpp

Polynomial.o: Polynomial.cpp Polynomial.hpp Term.hpp Token.hpp
	$(CC) Polynomial.cpp

Term.o: Term.cpp Term.hpp Token.hpp
	$(CC) Term.cpp

Token.o: Token.cpp Token.hpp
	$(CC) Token.cpp

Stack.o: Stack.tpp Stack.hpp
	$(CC) Stack.tpp

clean:
	/bin/rm -f termex *.o *~ \#*
