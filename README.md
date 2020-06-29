# ft_printf

A re-coding of the C library function printf.

```ft_printf(const char *, ...)```

This project involved creating a library in C from scratch to mimic a large portion of the funcitonality of the original printf C lib function. The project only allowed use of the external C functions ```malloc```, ```free``` and ```write```, as well as the C library macros ```va_start```, ```va_arg```, ```va_copy``` and ```va_end```.

## Details

This ft_printf library includes the following features form the original printf:

* the conversions ```%c```, ```%s```, ```%p```, ```%d```, ```%i```, ```%u```, ```%x```, ```%X```, ```%n```, ```%f```, ```%g```, ```%e``` and ```%```
* the flags ```-```, ```0```, ```.```, ```*```, ```l```, ```ll```, ```h```, ```hh```, ```#```, ``` ```, and ```+```.


## Compilation and Usage

A Makefile is included, simply use ```make``` to compile the ```.c``` files and link into the library ```libftprintf.a```.

This library can then be linked with other projects, provided the ```libftprintf.h``` header file is included.

## Resources

* [*Format specification syntax: printf and wprintf functions* by Microsoft](https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019)
* [*Secrets of “printf”* by Prof. Don Colton](https://www.cypress.com/file/54441/download)
