#include "../includes/cUnit.h"

static  t_lUTest    *uTlist = NULL;

/*
** Set unit test
*/
void                    uTInit(void)
{
    uTlist = newUnitTestList();
}

/*
** Subscribes a new unit test to the unit test list
** Param name   :   test designation
** Param pass   :   assert value (UTFAIL, UTSUCCESS)
*/
void                    uTSubscribe(char *name, size_t pass)
{
    int             i = 0;
    t_lUTest        *tmp;

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

/*
** Runs all tests and clear resources
** Param id     :   filedescriptor
** Param dFlags :   display flag (DISP_FAILURE, DISP_SUCCESS, DISP_ALL)
*/
void                    uTRun(int fd, int dFlags)
{
    t_lUTest        *tmp;

    if (fd < 0)
        return ;
    tmp = uTlist;
    while (tmp && (tmp->cursor != NULL))
    {
        if ((tmp->cursor->pass == UTSUCCESS) && (dFlags & DISP_SUCCESS))
        {
            write(fd, "Test succeeded : ", strlen("Test succeeded : "));
            write(fd, tmp->cursor->name, strlen(tmp->cursor->name));
            write(fd, "\n", 1);
        }
        if ((tmp->cursor->pass == UTFAIL) && (dFlags & DISP_FAILURE))
        {
            write(fd, "Test failed : ", strlen("Test failed : "));
            write(fd, tmp->cursor->name, strlen(tmp->cursor->name));
            write(fd, "\n", 1);
        }
        tmp = tmp->next;
    }
    write(fd, "End of tests\n", strlen("End of tests\n"));
}

/*
** Clears unit test list
*/
void                    uTClear(void)
{
    t_lUTest        *next;

    while (uTlist)
    {
        if (uTlist->cursor != NULL)
            deleteUnitTest(&uTlist->cursor);
        next = uTlist->next;
        free(uTlist);
        uTlist = next;
    }
    uTlist = NULL;
}

