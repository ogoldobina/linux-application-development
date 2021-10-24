CFLAGS += -O0 -g
GENERATES = range range.dSYM output*.txt
SHELL:=/bin/bash
MAKEFLAGS += --quiet

all: test

range: range.c

test: range
	echo TEST 01:
	sudo gdb -x gdb_script_01.txt range 2> /dev/null | grep "M=" > output_01.txt

	if diff correct_output_01.txt output_01.txt;\
	then echo test_01 OK;\
	else echo test_01 FAIL;\
	fi;

	echo TEST 02:
	sudo gdb -x gdb_script_02.txt range 2> /dev/null | grep "M=" > output_02.txt

	if diff correct_output_02.txt output_02.txt;\
	then echo test_02 OK;\
	else echo test_02 FAIL;\
	fi;

clear:
	rm -rf $(GENERATES)