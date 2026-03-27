# Notes from C
Everything passed in C is passed by value/copy

e.g: If you pass a single pointer as a function argument, you will be modifying
local copies of the pointer and not the original call scope;

## Gcc Debugging
### [GDB](https://man.archlinux.org/man/gdb.1.en)
- **run** to start the program;
- **list [number]** gives more information 10 lines around the specified number;
    - Can also use **list [number], [number]** to use between those lines;
- **print [variable]** to check in the stdout;
- **set var [variable] = [value]** to set a variable with a certain value;
- To set breakpoints we use **break [line_number]**;
    - Can also use **break [function]** or **break [file][function]**;
- To remove breakpoints we can use **clear [line/function]**;
- **quit** to leave gdb;

## Gcc Profiling
### [Valgrind](https://wiki.archlinux.org/title/Debugging#Valgrind)
Good for checking memory leaks, it does take a lot of time to run the program;

## Double pointers
Pointer points to a location in memory, and thus used to store the address of 
variables.

With double pointers the first pointer contains the address of the second pointer
which points to the location of the actual value;
- e.g: int **[variable]

Inside a function we use double pointers so we can change the actual pointer
and not a copy of that pointer;

You cannot double point a double pointer;

## Function pointers
Function pointers need to be between parentheses so it gets the "value" of the
pointer and not the actual memory address;

## Static Library
Uses static linking (compile time, becomes part of the application);

Each process gets its copy of the code and data;

AKA Archive;

The static libraries type is **.a**;

e.g of how to create the lib file
    
    // create object for [filename].c
    gcc -c [filename].c -o lib_[name].o

    // create lib from object
    ar rcs lib_[name].a lib_[name].o

    // Include file from other folder (the one will use the object functions)
    gcc -I [relative path to folder] -c [filename].c -o [name].o

    // Link [name].o to static library
    gcc -o [name] [name].o [relative path to .a file]

## Dinamic Library
Shared object libraries;

Linked at runtime and are not included into the executable;

Code is shared, data is specific to each process;

The dinamic libraries type is **.so** (shared object);
