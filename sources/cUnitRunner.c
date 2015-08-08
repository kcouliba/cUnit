#include "../includes/cUnit.h"

/*
** Runs all tests and clear resources
*/
void                    uTRun(int fd, int dFlags)
{
    t_lUTest    *tmp;

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
    t_lUTest    *next;

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
