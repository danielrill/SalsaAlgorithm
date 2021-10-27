#
# Makefile
#
# 28.05.2021
#

CFLAGS= -O3 -std=c99 -pedantic -Wall -Werror
SHELL := bash

.PHONY: clean all

all: test

test: salsa20.o test.o

clean:
		rm -f *.o test
