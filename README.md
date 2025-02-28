### Run the experiment

Compile the C function. This will get called from Fortran
```console
gcc -c -o print_array_values.o print_array_values.c
```

Then compile the C program
```console
gcc -o indexing indexing.c print_array_values.o
```

Now compile the Fortran program
```console
gfortran -std=legacy -o indexing_f indexing.f print_array_values.o
```

The result of the two programs is the same!

### What did I learn about C and Fortran ordering?

The loops above both iterate over i first, then j, and finally k.
The same result occurs because of the indexing semantics.
The C array is constructed in (k,j,i) order.
In Fortran array is constructed in (i,j,k) order.
If there is really any difference, it is due to cache locality.

So the shape of memory in C and Fortran is the same.
The indexing in the languages is not.
C iterates over the outermost index first, and works inward so to say.
Fortran does the opposite.
If you do not use (k,j,i) ordering to iterate over an array in Fortran, you will suffer the consequences of poor cache performance.
The Fortran program above demonstrates proper (k,j,i) indexing.
