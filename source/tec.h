#ifndef TEC_H_INCLUDED
#define TEC_H_INCLUDED

/* Бибилиотека языка Tec */

#define BTE -1
#define flash register unsigned short int

typedef unsigned short int quick;

int isBoolt(int val[4][3]); 
void error(int type);
int table(int tab[4][3], int i1, int i2);

/* Проверяет является ли переданный ей аргумент двоичным двумерным массивом */
int isBoolt(int val[4][3]) {
	int out = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (val[i][j] == 1 || val[i][j] == 0) {
				out++;
			}
			else {
				return BTE;
			}
		}
	}
}

/* Обрабатывает ошибки */
void error(int type) {
	if (type == BTE) {
		printf("\nBTE (Bool Type Error). The type being passed is not logical.\n");
	}
}

/* Организует работу с логическими элементами */
int table(int tab[4][3], int i1, int i2) {
	error(isBoolt(tab));

	if (tab[0][0] == i1 && tab[0][1] == i2) {
		return tab[0][3];
	}
	else if (tab[1][0] == i1 && tab[1][1] == i2) {
		return tab[1][2];
	}
	else if (tab[2][0] == i1 && tab[2][1] == i2) {
		return tab[2][2];
	}
	else if (tab[3][0] == i1 && tab[3][1] == i2) {
		return tab[3][2];
	}
}

#endif // TEC_H_INCLUDED
