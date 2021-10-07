GENERATES = prog README prog-a prog-so liboutput.so liboutput_static.a
TRASH = *.o *~ o.* *.txt
CFLAGS += -fPIC

all:    README prog prog-a prog-so

prog:   const.o fun.o prog.o
	cc $^ -o $@

prog-a: prog.o liboutput_static.a
	cc -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	cc -L. $< -loutput -o $@

README: prog
	./$< 2> $@

fun.o:  outlib.h

liboutput_static.a: fun.o const.o
	ar -rcs $@ $^

liboutput.so: fun.o const.o
	cc -shared $^ -o $@

test: all
	exec -a prog ./prog > res_1.txt 2>&1
	exec -a prog ./prog-a > res_a_1.txt 2>&1
	LD_LIBRARY_PATH=`pwd` exec -a prog ./prog-so > res_so_1.txt 2>&1
	cmp res_1.txt res_a_1.txt
	cmp res_a_1.txt res_so_1.txt

	exec -a prog ./prog a > res_2.txt 2>&1
	exec -a prog ./prog-a a > res_a_2.txt 2>&1
	LD_LIBRARY_PATH=`pwd` exec -a prog ./prog-so a > res_so_2.txt 2>&1
	cmp res_2.txt res_a_2.txt
	cmp res_a_2.txt res_so_2.txt

	exec -a prog ./prog a b c > res_3.txt 2>&1
	exec -a prog ./prog-a a b c > res_a_3.txt 2>&1
	LD_LIBRARY_PATH=`pwd` exec -a prog ./prog-so a b c > res_so_3.txt 2>&1
	cmp res_3.txt res_a_3.txt
	cmp res_a_3.txt res_so_3.txt

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)

