CFLAGS = -Wall -O0 -g

bin_PROGRAMS=esub

esub_SOURCES=esub.c

TESTS=test_01.sh test_02.sh test_03.sh

test_01.sh:
	echo 'test "`./esub a \\"\\b\\" jvdjhvad 2>&1`" = "Can'"'"'t parse escaped character."' > $@
	chmod +x $@

test_02.sh:
	echo 'test "`./esub a \\"\\9\\" jvdjhvad 2>&1`" = "No group with number 9."' > $@
	chmod +x $@

test_03.sh:
	echo 'test "`./esub "([ab]+)(.)+" "\\2===\\1" "abahhhhh" 2>&1`" = "`echo abahhhhh | sed -E '"'"'s/([ab]+)(.)+/\\2===\\1/'"'"'`"' > $@
	chmod +x $@

gitclean:
	git clean -df
