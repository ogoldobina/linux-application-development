#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>

int N_MATCH = 10;
int MSG_SIZE = 256;

void process_error(int err, regex_t *preg) {
    char msg[MSG_SIZE];
    regerror(err, preg, msg, MSG_SIZE);
    fprintf(stderr, "%s\n", msg);
}

int parse_substitution(char *substitution, regmatch_t *pmatch) {
	int group = 0;
	char *p;
	for (p = substitution; *p; ++p) {
		if (*p == '\\') {
			group = !group;
		} else if (group) {
			if (!isdigit(*p)) {
				fprintf(stderr, "Can't parse escaped character.\n");
				return -1;
			} 

			int n_gr = *p - '0';
			if (pmatch[n_gr].rm_so < 0) {
	            fprintf(stderr, "No group with number %d.\n", n_gr);
	            return -1;
			}

			group = 0;
		}
	}

    if (group) {
        fprintf(stderr, "Can't parse escaped character.\n");
        return -1;
    }

    return 0;
}

void print_result(char *string, char *substitution, regmatch_t *pmatch) {
	printf("%.*s", (int) pmatch[0].rm_so, string);

	char *p;
	int group = 0;
	for (p = substitution; *p; ++p) {
		if (*p == '\\') {
            if (group) putchar(*p);
            group = 1 - group;
        } else if (group) {
	        int n_gr = *p - '0';
	        int so = (int) pmatch[n_gr].rm_so, eo = (int) pmatch[n_gr].rm_eo;
			printf("%.*s", eo - so, string + so);

	        group = 0;
	    } else putchar(*p);
	}

	printf("%s\n", string + pmatch[0].rm_eo);
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("esub - replace a substring satisfying a regular expression\n" \
			   "usage:\n\tesub regexp substitution string\n");
		return 0;
	} else if (argc != 4) {
		fprintf(stderr, "%s\n", "Wrong number of arguments.");
		return 1;
	}

	char *regexp = argv[1], *substitution = argv[2], *string = argv[3];

	regex_t preg;
    int err;

    err = regcomp(&preg, regexp, REG_EXTENDED);
    if (err) {
        process_error(err, &preg);
        regfree(&preg);
        return 2;
    }

    regmatch_t pmatch[N_MATCH];
    err = regexec(&preg, string, N_MATCH, pmatch, 0);

    regfree(&preg);
    if (err == 0) {
        if (parse_substitution(substitution, pmatch) != -1) {
        	print_result(string, substitution, pmatch);
	        return 0;
	    } else return 3;
    } else if (err == REG_NOMATCH) {
        printf("%s\n", string);
        return 0;
    } else {
        process_error(err, &preg);
        return 4;
    }
}