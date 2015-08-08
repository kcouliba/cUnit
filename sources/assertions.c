#include "../includes/cUnit.h"

/*
** Asserts that char values are equals
*/
size_t      assertEqualsChar(char a, char b)
{
    return (a == b);
}

/*
** Asserts that int values are equals
*/
size_t      assertEqualsInt(int a, int b)
{
    return (a == b);
}

/*
** Asserts that double values are equals
*/
size_t      assertEqualsDouble(double a, double b)
{
    return (a == b);
}

/*
** Asserts that float values are equals
*/
size_t      assertEqualsFloat(float a, float b)
{
    return (a == b);
}

/*
** Asserts that predicate is true (!= 0)
*/
size_t      assertTrue(size_t predicate)
{
    return (predicate == 1);
}

/*
** Asserts that predicate is false (0)
*/
size_t      assertFalse(size_t predicate)
{
    return (predicate == 0);
}

/*
** Asserts that pointer is NULL
*/
size_t      assertNullPtr(void *ptr)
{
    return (ptr == NULL);
}

/*
** Asserts that pointers are pointing the same address
*/
size_t      assertEqualsPtr(void *ptrA, void *ptrB)
{
    return (ptrA == ptrB);
}
