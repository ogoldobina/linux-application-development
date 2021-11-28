#include <check.h>
#include "libbuf.h"


float *a;
long *ai;


#suite Tests
#test init_test
    /* initialization, buf_free() */
    a = 0;
    ck_assert(buf_capacity(a) == 0);
    ck_assert(buf_size(a) == 0);

#test push_test
    a = 0;
    buf_push(a, 1.3f);
    ck_assert(buf_size(a) == 1);
    ck_assert(a[0] == (float)1.3f);

#test clear_test
    a = 0;
    buf_push(a, 1.3f);
    buf_clear(a);
    ck_assert(buf_size(a) == 0);
    ck_assert(a != 0);

#test free_test
    buf_free(a);
    ck_assert(a == 0);

    /* Clearing an NULL pointer is a no-op */
#test clear_null_test
    buf_clear(a);
    ck_assert(buf_size(a) == 0);
    ck_assert(a == 0);

    /* buf_push(), [] operator */
#test indexing_test
    ai = 0;
    for (int i = 0; i < 10000; i++)
        buf_push(ai, i);
    ck_assert(buf_size(ai) == 10000);
    int match = 0;
    for (int i = 0; i < (int)(buf_size(ai)); i++)
        match += ai[i] == i;
    ck_assert(match == 10000);
    buf_free(ai);

    /* buf_grow(), buf_trunc() */
#test grow_test
    buf_grow(ai, 1000);
    ck_assert(buf_capacity(ai) == 1000);
    ck_assert(buf_size(ai) == 0);

#test trunc_test
    buf_trunc(ai, 100);
    ck_assert(buf_capacity(ai) == 100);
    buf_free(ai);

    /* buf_pop() */
#test pop_tase
    buf_push(a, 1.1);
    buf_push(a, 1.2);
    buf_push(a, 1.3);
    buf_push(a, 1.4);
    ck_assert(buf_size(a) == 4);
    ck_assert(buf_pop(a) == (float)1.4f);
    buf_trunc(a, 3);
    ck_assert(buf_size(a) == 3);
    ck_assert(buf_pop(a) == (float)1.3f);
    ck_assert(buf_pop(a) == (float)1.2f);
    ck_assert(buf_pop(a) == (float)1.1f);
    ck_assert(buf_size(a) == 0);
    buf_free(a);
