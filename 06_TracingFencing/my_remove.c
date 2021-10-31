#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
 
typedef int (*orig_remove_f_type)(const char *pathname);
 
int remove(const char *pathname)
{
    if (strstr(pathname, "PROTECT") != NULL) {
    	fprintf(stdout, "%s\n", "Input file is protected, keeping it.");
	return 0;
    } else {
        orig_remove_f_type orig_remove;
        orig_remove = (orig_remove_f_type)dlsym(RTLD_NEXT, "remove");
        return orig_remove(pathname);
    }
}
