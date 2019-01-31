#ifndef ESD_H_INCLUDED
#define ESD_H_INCLUDED

/* 
EHDL Standart Debuger v1.0
28.01.2019
by Centrix
*/

void go(int block1, int block2, int block3, int block4);
void part1();
void part2();
void part3();
void part4();

/* Запускает процесс отладки */
void go(int block1, int block2, int block3, int block4) {
	if (block1) {
		part1();
	}
	if (block2) {
		part2();
	}
	if (block3) {
		part3();
	}
	if (block4) {
		part4();
	}
}

#endif // ESD

