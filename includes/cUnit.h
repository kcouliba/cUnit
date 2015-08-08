#ifndef UNITTEST_H
# define UNITTEST_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define    RED             4
# define    GREEN           2
# define    UTFAIL          0
# define    UTSUCCESS       1
# define    INITFAIL        0
# define    INITSUCCESS     1
# define    EXIT_SUCCESS    0
# define    EXIT_FAILURE    1
# define    DISP_FAILURE    1
# define    DISP_SUCCESS    2
# define    DISP_ALL        3

typedef struct              s_unitTest
{
    int                     id;
    char                    *name;
    size_t                  pass;
}                           t_unitTest;

typedef struct              s_unitTestList
{
    t_unitTest              *cursor;
    struct s_unitTestList   *next;
}                           t_unitTestList;

typedef t_unitTestList      t_lUTest;

t_unitTest                  *newUnitTest(int id, char *name);
t_lUTest                    *newUnitTestList(void);
void                        deleteUnitTest(t_unitTest **uTest);
void                        uTInit(void);
void                        uTSubscribe(char *name, size_t pass);
void                        uTRun(int fd, int dFlags);
void                        uTClear(void);
size_t                      assertEqualsChar(char a, char b);
size_t                      assertEqualsInt(int a, int b);
size_t                      assertEqualsDouble(double a, double b);
size_t                      assertEqualsFloat(float a, float b);
size_t                      assertTrue(size_t a);
size_t                      assertFalse(size_t predicate);
size_t                      assertNullPtr(void *ptr);
size_t                      assertEqualsPtr(void *ptrA, void *ptrB);

/*
** global variable
*/
t_lUTest                    *uTlist;

#endif // UNITTEST_H
