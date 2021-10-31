GENERATES = *.txt *.so move
SHELL:=/bin/bash
# MAKEFLAGS += --quiet

all: move

move: move.c

my_remove.so: my_remove.c
	cc my_remove.c -shared -fPIC -o my_remove.so -ldl

run_tests: test_01 test_02 test_03 test_04

test_04: move my_remove.so
	./test_04.sh

test_%: move
	./$@.sh

clear:
	rm -rf $(GENERATES)
