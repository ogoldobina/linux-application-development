#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rhash.h>
#include <ctype.h>
#include <errno.h>
#include <readline/readline.h>
#include "config.h"

int main() {
    char *line = NULL;

#ifndef HAVE_LIBREADLINE
    size_t len = 0;
    ssize_t nread;
#endif

    while (1) {

#ifdef HAVE_LIBREADLINE
        line = readline(">");
        if (line == NULL) break;
#else
        putc('>', stdout);
        nread = getline(&line, &len, stdin);
        if (nread == -1) break;
#endif

        char *hashalg, *input;

        line[strcspn(line, "\n")] = 0;

        hashalg = strtok(line, " ");
        input = strtok(NULL, " ");

        if (hashalg == NULL || input == NULL) {
            fprintf(stderr, "%s\n", "Wrong number of arguments!");
            continue;
        }

        int FORMAT = islower(hashalg[0]) ? RHPR_BASE64 : RHPR_HEX;
        for (char *p = hashalg; *p; ++p) *p = (char) tolower(*p);

        int RHASH_ALG;
        if (!strcmp(hashalg, "sha1")) RHASH_ALG = RHASH_SHA1;
        else if (!strcmp(hashalg, "md5")) RHASH_ALG = RHASH_MD5;
        else if (!strcmp(hashalg, "tth")) RHASH_ALG = RHASH_TTH;
        else {
            fprintf(stderr, "%s\n", "Unsupported hash algorithm.");
            continue;
        }


        unsigned char digest[64];
        char output[130];
        rhash_library_init();

        if (input[0] != '"') {
            int res = rhash_file(RHASH_ALG, input, digest);
            if (res < 0) {
                fprintf(stderr, "LibRHash error %s: %s\n", input, strerror(errno));
                continue;
            }
        } else {
            if (input[strlen(input) - 1] != '"') {
                fprintf(stderr, "Unexpected end of string\n");
                continue;
            }
            // remove outer "" from string
            char *p = input, *q = input;
            int i = 0;
            for (; *p; ++p, ++i) {
                if (i != 0 && i != strlen(input) - 1) {
                    *q = *p;
                    ++q;
                }
            }
            *q = *p;

            int res = rhash_msg(RHASH_ALG, input, strlen(input), digest);
            if (res < 0) {
                fprintf(stderr, "Message digest calculation error\n");
                continue;
            }
        }

        rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_ALG), FORMAT);
        printf("%s (\"%s\") = %s\n", rhash_get_name(RHASH_ALG), input, output);

#ifdef HAVE_LIBREADLINE
        free(line);
#endif

    }

    free(line);
}