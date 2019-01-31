#ifndef CBL_H_INCLUDED
#define CBL_H_INCLUDED

/* 
Circuit Builder v0.3
28.01.2019
by Centrix
*/

/* Индикатор конца массива */
#define e -1
#define BTE -1

typedef unsigned short int usi;

/* 
Структура реализующая деталь
type - тип детали
pins - входные пины детали
out - выходные пины детали
*/
typedef struct {
	char type;
	usi* pins;
	usi* out;
} det;

/*
Функция которая задаёт значение на выходных пинах детали
*/
void outConf(det d) {
	int i = 0;
	int len = 0; 
	int sum = 0;

	while (d.pins[i] != e) {
		len++;
		i++;
		sum += d.pins[i];
	}

	if (d.type == '&') { // AND
		if (len == sum) {
			d.out = 1;
		}
	}
	else if (d.type == '|') { // OR
		if (sum > 0) {
			d.out = 1;
		}
	}
	else if (d.type == '!') { // NOT
		i = 0;
		while (i < len) {
			d.pins[i] = !d.pins[i];
			i++;
		}
	}
	else if (d.type == '^') { // XOR
		if (sum > 0 && sum != len) {
			d.out = 1;
		}
	}
	else if (d.type == '~') { // NAND
		if (sum == 0 || (sum > 1 && sum != len)) {
			d.out = 1;
		}
	}
	else if (d.type == '#') { // NOR
		if (sum == 0) {
			d.out = 1;
		}
	}
	d.out[1] = e;
}

/* Проверяет корректность детали */
int corrDet(det cd) {
	int i = 0;

	while (cd.pins[i] != e) {
		if (cd.pins[i] == 1 || cd.pins[i] == 0 || cd.pins[i] == e) { ; }
		else {
			return BTE;
		}
		i++;
	}

	i = 0;

	while (cd.out[i] != e) {
		if (cd.out[i] == 1 || cd.out[i] == 0) { ; }
		else {
			return BTE;
		}
		i++;
	}
}

/* Обрабатывает ошибки */
void err(int type) {
	if (type == BTE) {
		printf("\nBTE (Bool Type Error). The type being passed is not logical.\n");
	}
}

#endif // CBL_H_INCLUDED