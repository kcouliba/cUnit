#include "../includes/cUnit.h"

/*
** Set unit test
*/
void                    uTInit(void)
{
    uTlist = newUnitTestList();
}

/*
** Subscribes a new unit test to the unit test list
*/
void                    uTSubscribe(char *name, size_t pass)
{
    int         i = 0;
    t_lUTest    *tmp;

    tmp = uTlist;
    while (tmp->next)
    {
        ++i;
        tmp = tmp->next;
    }
    tmp->cursor = newUnitTest(i, name);
    tmp->cursor->pass = pass;
    tmp->next = newUnitTestList();
}
