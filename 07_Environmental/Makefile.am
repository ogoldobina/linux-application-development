CFLAGS = -Wall -O0 -g

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c

TESTS=test_01.sh test_02.sh test_03.sh test_04.sh test_05.sh

test_01.sh:
	echo 'test "`echo jbfvjfvj | ./rhasher 2>&1`" = "Wrong number of arguments!"' > $@
	chmod +x $@

test_02.sh:
	echo 'test "`echo MD5 \\\"jdbvjsd\\\" | ./rhasher`" = "MD5 (\"jdbvjsd\") = 6a929dbea9021452e33c7db0c95e7a50"' > $@
	chmod +x $@

test_03.sh:
	echo 'test "`echo SHA1 \\\"jdbvjsd\\\" | ./rhasher`" = "SHA1 (\"jdbvjsd\") = 8964da41df69ad184a89b40a11809d47dcfb6dd7"' > $@
	chmod +x $@

test_04.sh:
	echo 'test "`echo tth \\\"jdbvjsd\\\" | ./rhasher`" = "TTH (\"jdbvjsd\") = 1fSjvnTdfn0T5TPizgi2LHH+GWxKOeaq"' > $@
	chmod +x $@

test_05.sh:
	echo 'test "`echo MD5 rhasher.c | ./rhasher | sed "s/.* = \(.*\)/\1/"`" = "`md5sum rhasher.c | cut -d " " -f1`"' > $@
	chmod +x $@

gitclean:
	git clean -df
