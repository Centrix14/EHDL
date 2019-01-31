#ifndef AEL_H_INCLUDED
#define AEL_H_INCLUDED

#include "esl.h"

typedef unsigned short int usi;

void summator(usi p, usi a, usi b, usi* s, usi* pi);
void halfadder(usi x, usi y, usi* s, usi* c);
void major(usi x1, usi x2, usi x3, usi* y);


/* 
Добавочая библиотека EHDL v0.1 
28.01.2019
by Centrix
*/

/* Двухвходный XOR */
usi ael_xor(usi i1, usi i2) {
	usi out = 0;
	int sum = i1 + i2;

	if (sum == 2) { ; }
	
	else if (sum == 1) {
		out = 1;
	}

	return out;
}

/* Двухвходный OR */
usi ael_or(usi i1, usi i2) {
	usi out = 0;

	if (i1 != 0 || i2 != 0) {
		out = 1;
	}

	return out;
}

/* Трёхвходовый OR */
usi ael_or3(usi i1, usi i2, usi i3) {
	usi out = 0;

	if (i1 != 0 || i2 != 0 || i3 != 0) {
		out = 1;
	}

	return out;
}

/* Двухвходный AND */
usi ael_and(usi i1, usi i2) {
	usi out = 0;
	int sum = i1 + i2;

	if (sum == 2) {
		out = 1;
	}

	return out;
}

/* Сумматор */
void summator(usi p, usi a, usi b, usi* s, usi* pi) {
	usi xor1 = ael_xor(a, b);
	usi and1 = ael_and(a, b);
	*s = ael_xor(p, xor1);
	usi and2 = ael_and(p, xor1);
	*pi = ael_or(and1, and2);
}

/* Полусумматор */
void halfadder(usi x, usi y, usi* s, usi* c) {
	*s = ael_and(x, y);
	*c = ael_xor(x, y);
}

/* Мажоритарный элемент */
void major(usi x1, usi x2, usi x3, usi* y) {
	usi and1 = ael_and(x1, x2);
	usi and2 = ael_and(x3, x2);
	usi and3 = ael_and(x1, x3);
	*y = ael_or3(and1, and2, and3);
}

#endif // AEL_H_INCLUDED
