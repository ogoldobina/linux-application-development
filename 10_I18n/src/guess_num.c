#include <stdio.h>
#include <locale.h>
#include <libgen.h>
#include <libintl.h>
#include <stdlib.h>
#include <string.h>

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "../po"

int main() {

	setlocale (LC_ALL, "");
	bindtextdomain ("guess_num", LOCALE_PATH);
	textdomain ("guess_num");

	printf(_("Please, think of a number from 1 to 100\n"));
	int l = 1, r = 100, m;
	// char c;
	char str[256];

	while (l < r) {
		m = (l + r) / 2;
		printf(_("Is your number > %d? y/n\n"), m);

		fgets(str, sizeof(str), stdin);
		if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';

		while ((strcmp(str, _("y")) != 0) && (strcmp(str, _("n")) != 0)) {
			printf(_("Undefined answer. Enter y/n.\n"));
			fgets(str, sizeof(str), stdin);
			if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
		}


		if ((strcmp(str, _("y")) == 0)) {
			l = m + 1;
		} else {
			r = m;
		}

	}

	printf(_("Your number is %d.\n"), l);
}
