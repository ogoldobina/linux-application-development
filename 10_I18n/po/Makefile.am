pkgdata_DATA = ru/LC_MESSAGES/guess_num.mo
ru/LC_MESSAGES/guess_num.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	guess_num.pot ../src/guess_num.c
	xgettext -k_ -c ../src/guess_num.c -o messages.new.pot
	cp guess_num.pot messages.pot
	msgmerge -U messages.pot messages.new.pot
