CC = g++
LEVEL ?= EASY
OP ?=
CFLAGS = $(OP) -Wall -Werror -std=c++17 -o
DEBUG = -D__DEBUG__
test:
	@$(CC) $(CFLAGS) test.out test.cpp sort.cpp -D__$(LEVEL)TEST__ $(DEBUG) && ./test.out
clean:
	@rm -f *.out
