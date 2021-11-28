SUBDIRS = src tests

gitclean:
	git clean -df

gcov:	check
	$(MAKE) $(MAKEFLAGS) -C src gcov
