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

## Useful C libraries 
### atoi 
Ascii to integer 
``` C 
int atoi(const char *str);
```
### atof 
Ascii to float/double
``` C
double atof(const char *str);
```
### atol
Ascii to long integer
```C
long int atol(const char *str);
```
### strtod
Converts the string pointed to, by the argument str to a floating point number
type double
```C
double strtod(const char *str, char **endptr);
```
### strtof
Same as strtod but to float instead of double
```C
float strof(const char *str, char **endptr);
```
### strtol
Converts the string pointed to, by the argument str to a long integer (type long int)
- base = 10 -> Decimal
- base = 16 -> Hexadecimal
- base needs to be between 2 and 32, or special value 0
```C
long int strtol(const char *str, char **endptr, int base);
```
### rand 
Provides a random number until RAND_MAX with a minimum of 32767
```C 
int rand(void);
// We can specify the range, for example from 1 to 5 inclusive
rand() % 5 + 1;
// from 0 to 99
rand() % 100;
```

## Threads
To run code with pthread.h included in the file we need to run
***gcc [file].c -lpthread***

### Deadlocks
When using multiple mutexes, we should use the ``pthread_mutex_trylock(&mutex)``
in a loop, instead of just using ``pthread_mutex_lock(&mutex)``.

Inside the loop we should unlock the firstly locked mutex, so the other threads
can free the lock, that way, deadlocks are prevented.

