#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdarg.h>
#include <unistd.h>
#define JUST_FLAG 0x8
#define PLUS_FLAG 0x4
#define SPACE_FLAG 0x2
#define ZERO_FLAG 0x1
typedef struct spec {
	char flags;
	char length;
	int width;
	int prec;
	int stride;
	int (*func)(struct spec *, va_list);
} spec_t;
typedef struct {
	char symbol;
	int (*func)(spec_t *, va_list);
} conv_func_t;
void get_spec(const char *, spec_t *);
int setflags(const char *, spec_t *);
int setwidth(const char *, spec_t *);
int setprec(const char *, spec_t *);
int setlength(const char *, spec_t *);
int settype(const char *, spec_t *);
int conv_pc(spec_t *, va_list);
int conv_i(spec_t *, va_list);
int conv_u(spec_t *, va_list);
int conv_f(spec_t *, va_list);
int conv_e(spec_t *, va_list);
int conv_E(spec_t *, va_list);
int conv_x(spec_t *, va_list);
int conv_X(spec_t *, va_list);
int conv_o(spec_t *, va_list);
int conv_s(spec_t *, va_list);
int conv_c(spec_t *, va_list);
int conv_p(spec_t *, va_list);
int conv_a(spec_t *, va_list);
int conv_A(spec_t *, va_list);
int _isdigit(char);
int _printf(const char *format, ...);
#endif /* _HOLBERTON_H_ */
