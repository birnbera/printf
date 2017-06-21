# 0x10. C - _printf #
### Prototype ###
int _printf(const char *format, ...)

### Description ###
A function that parses the format string to print to standard output and returns the number of characters printed, excluding the null byte used to end string output.  It shares most of the functionalities with the standard printf function from the C output library, with a few notable differences (see Usage).

### Installation ###
User can clone the repository to their local branch and compile the files. (incldue gif or screenshot)

### Features ###
The _printf function shares the following features as the standard printf function:
* __Conversion Specifier__: *c, s, i, d, p, u, o, x, X, S*
* __Flag__: *-, +, ' ' (space), 0, #*
* __Length Modifier__: *h, l*

The function also implements the width and precision as the standard printf function.

The function offers additional conversion specifiers not present with the standard printf function:
* *r* - print the string in reverse
* *b* - convert the unsigned int argument to binary

### Credits ###
* Andrew Birnberg
  * https://github.com/birnbera
* Tanya Kryukova
  * https://github.com/tanyastropheus
