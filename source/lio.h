#ifndef LIO_H_INCLUDED
#define LIO_H_INCLUDED

/* 
library input / output v0.1 
31.01.2019
by Centrix
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG(x) puts(#x)
#define nMSG(...) printf(__VA_ARGS__)

struct io {
	char* (*in) ();
	char* (*out) ();
} Console;

#endif // LIO_H_INCLUDED
