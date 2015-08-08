# cUnit 
A unit test library for C programming

How to use :
  clone the repository
  compile the library :
    gcc -o bin/ -c sources/*
    ar -rc libcUnit.a bin/*
    ranlib libcUnit.a
  Now copy the generated library and use it in your project.
    link it to your project :
      gcc -o [projectName] -L./[path to the library directory] -lcUnit [project files]

Code sample:

  /*
  ** a method
  */
  int   add(int a, int b)
  {
    return (a + b);
  }
  
  /*
  ** main
  */
  int   main(int argc, char **argv)
  {
    // Initialize the test framework data
    uTInit();
    // Add a test to the testing pool
    uTSubscribe("add function test", assertTrue(add(3, 7) == 10));
    // Run tests
    uTRun(1, DISP_ALL);
    // Releases memory used by cUnit
    uTClear();
    return (0);
  }

Output :
  Test succeeded : add function test
  End of tests
  
Recommendation :
  include cUnit.h in your project for defines and assert methods.
