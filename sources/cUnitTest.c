#include "../includes/cUnit.h"

/*
** Allocates memory for a new unit test
** Param id     :   test id
** Param name   :   test designation
*/
t_unitTest          *newUnitTest(int id, char *name)
{
    t_unitTest  *nTest;

    nTest = (t_unitTest*)malloc(sizeof(*nTest));
    if (!nTest)
        return (NULL);
    nTest->id = id;
    nTest->name = strdup(name);
    nTest->pass = UTSUCCESS;
    return (nTest);
}

/*
** Frees memory from a unit test
** Param uTest :   a unit test structure
*/
void                deleteUnitTest(t_unitTest **uTest)
{
    if (*uTest != NULL)
    {
        if ((*uTest)->name != NULL)
            free((*uTest)->name);
        free(*uTest);
    }
    uTest = NULL;
}

/*
** Allocates memory for a new unit test
*/
t_lUTest            *newUnitTestList(void)
{
    t_lUTest    *nList;

    if (!(nList = (t_lUTest*)malloc(sizeof(*nList))))
        return (NULL);
    nList->cursor = NULL;
    nList->next = NULL;
    return (nList);
}
