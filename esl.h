#ifndef ESL_H_INCLUDED
#define ESL_H_INCLUDED

#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
Logic v0.12.0
The program is designed to simulate logic circuits and elements
Date 16.01.2019
AUTOR Centrix
**/

// Макрос для приведения примитовов к политипам
// Здесь p - это примитив приводимый к политипу n - значение нового политипа
#define to_poly(p, n) {p.ch_val = n;}\
{p.real_val = atof(p.ch_val);}

// Макросы для замены операторов словами (использование слов вместо стандартных операторов опционально)
#define and &
#define not ~
#define or |
#define xor ^
#define shir >>
#define shil <<
#define $(n) += n 
#define _(n) -= n

// Макросы для сообщений об ошибках
#define BTE -1
#define PVE -2
#define AVE -3

// Макросы для описания аналоговых состояний
#define z -1

typedef unsigned short int usi;

// Строка, указание длинны опционально
typedef struct {
	char* str;
	int size;
} string;

// Политип, все поля заполняются макросом to_poly()
typedef struct {
	char* ch_val;
	double real_val;
} poly;

// Тип elm является новым способом создания логических элементов
typedef struct {
	char type;
	usi len;
	usi a;
	usi b;
	usi c;
	usi d;
	usi e;
	usi f;
	usi g;
	usi h;
	usi i;
	usi j;
} elm;

/* Прототипы функций (Function prototype) */
/* Элементы */
int And(usi args[], usi len, usi digits);
int Or(usi args[], usi len, usi digits);
int Not(usi i1, usi digits);
int Nand(usi args[], usi len, usi digits);
int Xor(usi args[], usi len, usi digits);
int Nor(usi args[], usi len, usi digits);
int conBuff(usi conSignal, usi mainSignal);
int conInv(usi conSignal, usi mainSignal);
int d_trigg(usi dataIn, usi powerIn, usi digits);
/* Дополнительные функции */
void setInput(usi args[], usi len, usi digits);
int button();
int impulse(usi doIt);
void SevenSegmentIndicator(usi pins[]);
void SSI_SimpleOutput(char character);
void Result(usi digits);
void regInversion(usi reg[], usi len);
void regSetValue(usi reg[], usi values[], usi len);
void regInc(usi reg[], usi len);
void regDec(usi reg[], usi len);
int castElm(elm e);
int customElm43(usi table[4][3], usi i1, usi i2);
int bus(usi input[], usi output[], usi lenIn, usi lenOut); 
int toBool(double signal);
int transistor(double signalCon, double signalMain);
/* Система поиска ошибок */
int isBool(usi value); 
int isBoola(usi values[], usi len);
int isBoolat(usi values[4][3], usi len1, usi len2);
int isPoly(poly p); 
void error(int type); 

/* Глобальные переменные (Global variables) */
usi imp = 0;
usi analogMode = 0;
double limit;
const double maximum = 15.0;

usi Output4[4];
usi Output8[8];
usi Input4[4];
usi Input8[8];

/* Регистры с объявленным размером */

usi reg1[8];
usi reg2[8];
usi reg3[16];
usi reg4[16];
usi reg5[32];
usi reg6[32];
usi reg7[64];
usi reg8[64];

/* Коды символов для семисегментного индикатора */
/* Numbers */
usi zero[8] = {1, 1, 1, 1, 1, 1, 0, 1};
usi one[8] = {0, 0, 0, 0, 1, 1, 0, 1};
usi two[8] = {1, 0, 1, 1, 0, 1, 1, 1};
usi three[8] = {1, 0, 0, 1, 1, 1, 1, 1};
usi four[8] = {0, 1, 0, 0, 1, 1, 1, 1};
usi five[8] = {1, 1, 0, 1, 1, 0, 1, 1};
usi six[8] = {1, 1, 1, 1, 1, 0, 1, 1};
usi seven[8] = {1, 0, 0, 0, 1, 1, 0, 1};
usi eight[8] = {1, 1, 1, 1, 1, 1, 1, 1};
usi nine[8] = {1, 1, 0, 1, 1, 1, 1, 1};
/* Letters */
usi lettA[8] = {1, 1, 1, 0, 1, 1, 1, 1};
usi lettB[8] = {0, 1, 1, 1, 1, 0, 1, 1};
usi lettC[8] = {1, 1, 1, 1, 0, 0, 0, 0};
usi lettE[8] = {1, 1, 1, 1, 0, 0, 1, 1};
usi lettF[8] = {1, 1, 1, 0, 0, 0, 1, 1};
usi lettG[8] = {1, 1, 1, 1, 1, 0, 0, 1};
usi lettH[8] = {0, 1, 1, 0, 1, 1, 1, 1};
usi lettJ[8] = {0, 0, 1, 1, 1, 1, 0, 1};
usi lettL[8] = {0, 1, 1, 1, 0, 0, 0, 1};
usi lettP[8] = {1, 1, 1, 0, 1, 0, 1, 1};
usi lettR[8] = {1, 1, 1, 0, 0, 0, 0, 1};
usi lettU[8] = {0, 1, 1, 1, 1, 1, 0, 1};

/* Выбор вводимых значений (Selecting input values) */
void setInput(usi args[], usi len, usi digits) {
    usi i = 0;
	
	error(isBoola(args, len));
	
    switch (digits) {
    case 4:
        while (i < 4) {
            Input4[i] = args[i];
            i++;
        }
        break;

    case 8:
        while (i < 8) {
            Input4[i] = args[i];
            i++;
        }
		break;
    }
}

/* Кнопка возвращает 1 когда какая - либо кнопка нажата (Button returns 1 when any button is pressed) */
int button() {
    getchar();
    return 1;
}

/* Ввод значений в регистр (Enter values in register) */
void regSetValue(usi reg[], usi values[], usi len) {

	error(isBoola(values, len));
	
    usi i = 0;
    while (i < len) {
        reg[i] = values[i];
        i++;
    }
}

/* Увеличение значений в регистре (The increase in the values in the register) */
void regInc(usi reg[], usi len) {

	error(isBoola(reg, len));

    usi i = 0;
    while (i < len) {
        reg[i] = reg[i]++;

        if (reg[i] > 2) {
            reg[i] = 1;
        }

        i++;
    }
}

/* Уменьшение значений в регистре (The decrease in the values in the register) */
void regDec(usi reg[], usi len) {

	error(isBoola(reg, len));

    usi i = 0;
    while (i < len) {
        reg[i] = reg[i]--;
        if (reg[i] < 0) {
            reg[i] = 0;
        }

        i++;
    }
}

/* Инверсия всех значений в регистре (Invert all values in the register) */
void regInversion(usi reg[], usi len) {

	error(isBoola(reg, len));

    usi i = 0;
    while (i < len) {
        reg[i] = !reg[i];
        i++;
    }
}

/* Вывод значений (The output values) */
void Result(usi digits) {
    if (digits == 4) {
        printf("Input: ");
        for (usi i = 0; i < 4; i++) {
            printf("%d", Input4[i]);
        }

        printf("\nOutput: ");
        for (usi i = 0; i < 4; i++) {
            printf("%d", Output4[i]);
        }
    }

    else if (digits == 8) {
        printf("Input: ");
        for (usi i = 0; i < 8; i++) {
            printf("%d", Input4[i]);
        }

        printf("\nOutput: ");
        for (usi i = 0; i < 8; i++) {
            printf("%d", Output4[i]);
        }
    }
}

/**
Эта низкоуровневая функция предназначенная для непосредственного доступа к сегментам индикатора
This low-level function is intended for direct access to the indicator segments
**/
void SevenSegmentIndicator(usi pins[]) {

	error(isBoola(pins, 8));

    char segment1 = 95; /* _ */
    char segment2 = 124; /* | */
    char dot = 46; /* . */
    char space = 32; /* Пробел */

    if (pins[0] == 1) {
        printf("\n %c\n", segment1); /* _ (A) */
    }
    else {
        printf("\n %c\n", space); /* Пробел чтобы не съезжало (Space to not move out) */
    }
    if (pins[1] == 1) {
        printf("%c", segment2); /* | (B) */
    }
    else {
        printf("%c", space); /* Пробел чтобы не съезжало (Space to not move out) */
    }
    if (pins[6] == 1) {
        printf("%c", segment1); /* _ (C) */
    }
    else {
        printf("%c", space); /* Пробел чтобы не съезжало (Space to not move out) */
    }
    if (pins[5] == 1) {
        printf("%c\n", segment2); /* | (F) */
    }
    else {
        printf("%c\n", space); /* Пробел чтобы не съезжало (Space to not move out) */
    }
    if (pins[2] == 1) {
        printf("%c", segment2); /* | (C) */
    }
    else {
        printf("%c", space); /* Пробел чтобы не съезжало (Space to not move out) */
    }
    if (pins[3] == 1) {
        printf("%c", segment1); /* _ (D) */
    }
    else {
        printf("%c", space); /* Пробел чтобы не съезжало (Space to not move out) */
    }
    if (pins[4] == 1) {
        printf("%c", segment2); /* | (E) */
    }
    else {
        printf("%c", space); /* Пробел чтобы не съезжало (Space to not move out) */
    }
    if (pins[7] == 1) {
        printf("%c\n", dot); /* . (P) */
    }
    else {
        printf("%c\n", space); /* Пробел чтобы не съезжало (Space to not move out) */
    }
}

/**
Это высокоуровневая функция взаимодействующая с самим символом который нужно вывести
(is a high-level function interacting with the symbol to be output)
**/
void SSI_SimpleOutput(char character) {
    /* Переключатель для вывода символа */
    switch (character) {
    case 48:
        SevenSegmentIndicator(zero);
        break;
    case 49:
        SevenSegmentIndicator(one);
        break;
    case 50:
        SevenSegmentIndicator(two);
        break;
    case 51:
        SevenSegmentIndicator(three);
        break;
    case 52:
        SevenSegmentIndicator(four);
        break;
    case 53:
        SevenSegmentIndicator(five);
        break;
    case 54:
        SevenSegmentIndicator(six);
        break;
    case 55:
        SevenSegmentIndicator(seven);
        break;
    case 56:
        SevenSegmentIndicator(eight);
        break;
    case 57:
        SevenSegmentIndicator(nine);
        break;
    case 65:
        SevenSegmentIndicator(lettA);
        break;
    case 66:
        SevenSegmentIndicator(lettB);
        break;
    case 67:
        SevenSegmentIndicator(lettC);
        break;
    case 69:
        SevenSegmentIndicator(lettE);
        break;
    case 70:
        SevenSegmentIndicator(lettF);
        break;
    case 71:
        SevenSegmentIndicator(lettG);
        break;
    case 72:
        SevenSegmentIndicator(lettH);
        break;
    case 76:
        SevenSegmentIndicator(lettL);
        break;
    case 80:
        SevenSegmentIndicator(lettP);
        break;
    }
}

// Управляемый диод
int conBuff(usi conSignal, usi mainSignal) {

	error(isBool(conSignal));
	error(isBool(mainSignal));

    if (conSignal == 1) {
        return mainSignal;
    }
    else if (conSignal == 0) {
        return 0;
    }
}

// Управляемый инвертор
int conInv(usi conSignal, usi mainSignal) {

	error(isBool(conSignal));
	error(isBool(mainSignal));

    if (conSignal == 1) {
        return !mainSignal;
    }
    else if (conSignal == 0) {
        return 0;
    }
}

// Импульс
int impulse(usi doIt) {

	error(isBool(doIt));

    if (doIt == 1) {
        imp = 1;
    }
    else if (doIt == 0) {
        imp = 0;
    }
    return imp;
}

// D - триггер
int d_trigg(usi dataIn, usi powerIn, usi digits) {

	error(isBool(dataIn));
	error(isBool(powerIn));

    usi out = 0;
    if (digits == 4) {
        if (powerIn == 1) {
            Output4[3] = dataIn;
            out = 1;
        }
        else if (powerIn == 0) {
            Output4[3] = 0;
            out = 0;
        }
    }
    else if (digits == 8) {
        if (powerIn == 1) {
            Output8[7] = dataIn;
            out = 1;
        }
        else if (powerIn == 0) {
            Output8[7] = 0;
            out = 0;
        }
    }
    impulse(0);
    return out;
}

/* Элемент (элм) И */
int And(usi args[], usi len, usi digits) {

	error(isBoola(args, len));

    usi i = 0;
    usi sum = 0;
    usi out = 0;

    while (i < len) {
        sum += args[i];
        i++;
    }

    if (sum == len) {
        if (digits == 4) {
            Output4[3] = 1;
        }
        else if (digits == 8) {
            Output8[7] = 1;
        }
        out = 1;
    }
    else {
        if (digits == 4) {
            Output4[3] = 0;
        }
        else if (digits == 8) {
            Output8[7] = 0;
        }
    }
    impulse(0);
    return out;
}

/* элм ИЛИ */
int Or(usi args[], usi len, usi digits) {

	error(isBoola(args, len));

    usi i = 0;
    usi sum = 0;
    usi out = 0;

    while (i < len) {
        sum += args[i];
        i++;
    }

    if (sum > 1) {
        if (digits == 4) {
            Output4[3] = 1;
        }
        else if (digits == 8) {
            Output8[7] = 1;
        }
        out = 1;
    }
    else {
        if (digits == 4) {
            Output4[3] = 0;
        }
        else if (digits == 8) {
            Output8[7] = 0;
        }
        out = 0;
    }
    impulse(0);
    return out;
}

/* элм НЕ */
int Not(usi i1, usi digits) {

	error(isBool(i1));

    if (digits == 4) {
        Output4[3] = !i1;
    }
    else if (digits == 8) {
        Output8[7] = !i1;
    }
    impulse(0);
    return !i1;
}

/* элм НЕ-И */
int Nand(usi args[], usi len, usi digits) {

	error(isBoola(args, len));

    usi sum = 0;
    usi i = 0;
    usi out = 0;

    while (i < len) {
        sum += args[i];
        i++;
    }

    if (sum == 0) {
        if (digits == 4) {
            Output4[3] = 1;
        }
        else if (digits == 8) {
            Output8[7] = 1;
        }
        out = 1;
    }
    else {
        if (digits == 4) {
            Output4[3] = 0;
        }
        else if (digits == 8) {
            Output8[7] = 0;
        }
    }
    impulse(0);
    return out;
}

/* элм XOR */
int Xor(usi args[], usi len, usi digits) {

	error(isBoola(args, len));

    usi sum = 0;
    usi i = 0;
    usi out = 0;

    while (i < len) {
        sum += args[i];
        i++;
    }

    if (sum == len) {
        if (digits == 4) {
            Output4[3] = 0;
        }
        else if (digits == 8) {
            Output8[7] = 0;
        }
        out = 0;
    }
    else if (sum == 0) {
        if (digits == 4) {
            Output4[3] = 0;
        }
        else if (digits == 8) {
            Output8[7] = 0;
        }
        out = 1;
    }
    else if (sum > 0) {
        if (digits == 4) {
            Output4[3] = 1;
        }
        else if (digits == 8) {
            Output8[7] = 1;
        }
        out = 1;
    }
    impulse(0);
    return out;
}

/* элм НЕ-ИЛИ */
int Nor(usi args[], usi len, usi digits) {

	error(isBoola(args, len));

    usi sum = 0;
    usi i = 0;
    usi out = 0;

    while (i < len) {
        sum += args[i];
        i++;
    }

    if (sum == 0) {
        if (digits == 4) {
            Output4[3] = 1;
        }
        else if (digits == 8) {
            Output8[7] = 1;
        }
        out = 1;
    }
    else if (sum == len || sum < len) {
        if (digits == 4) {
            Output4[3] = 0;
        }
        else if (digits == 8) {
            Output8[7] = 0;
        }
    }
    impulse(0);
    return out;
}

/* Возвращает результат работы элемента elm */
/* Принимает elm как аргумент и запускает его возвращая логическое значение как результат работы элемента */
int castElm(elm e) {
	int out = 0;
	int sum = e.a + e.b + e.c + e.d + e.e + e.f + e.g + e.h + e.i + e.j;

	if (e.type == '&') { // AND
		if (sum == e.len) {
			out = 1;
		}
	}
	else if (e.type == '|') { // OR
		if (sum > 1) {
			out = 1;
		}
	}
	else if (e.type == '!') { // NOT
		out = !e.a;
	}
	else if (e.type == '^') { //XOR
		if (sum > 1 && sum != e.len) {
			out = 1;
		}
	}
	else if (e.type == '~') { // NAND
		if (sum == 0 || (sum > 1 && sum != e.len)) {
			out = 1;
		}
	}
	else if (e.type == '#') { // NOR
		if (sum == 0) {
			out = 1;
		}
	}
	return out;
}

/* Проверяет аргумент как булево значение */
/* Функция проверяющаа что переданный ей аргумент имеет булево значение */
int isBool(usi value) {
	int out = 0;
	if (value == 0 || value == 1) {
		out = 1;
	}
	else {
		out = BTE;
	}
	return out;
}

/* Проверяет массив как булево значение */
/* Функция проверяющая что переданный ей массив имеет только булевые значения */
int isBoola(usi values[], usi len) {
	int out = 1, i = 0;
	while (i < len) {
		if (isBool(values[i]) == 1) {;}
		else {
			out = BTE;
		}
		i++;
	}
	return out;
}

/*Проверяет двумерный массив как булево значение*/
/* Функция проверяющая что переданный ей двумерный массив имеет только булевые значения */
int isBoolat(usi values[4][3], usi len1, usi len2) {
	int out = 1;
	
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (isBool(values[i][j]) == 1) {;}
			else {
				out = BTE;
			}
		}
	}
	return out;
}

/* Проверяет аргумент как политип */
/* Функция проверяющая является ли переданный ей аргумент правильным политипом */
int isPoly(poly p) {
	int out = 0;
	double ch_val = atof(p.ch_val);
	double real_val = p.real_val;
	
	if (ch_val == real_val) {
		out = 1;
	}
	else {
		out = PVE;
	}
	return out;
}

/* Функция проверяет является ли переданный ей аргумент допустимым аналоговым значением */
int isAnalog(double signal) {
	int out = 0;
	if (((signal <= limit || signal >= limit) && signal <= maximum) && signal != 0 && analogMode == 1) {
		out = 1;
	}
	else {
		out = AVE;
	}
	return out;
}

/* Индетефицирует ошибки */
/* В эту функцию передаются коды ошибок, а она их обрабатывает */
void error(int type) {
	if (type == BTE) {
		printf("BTE (Bool Type Error). The type being passed is not logical.\n");
		system("pause");
	}
	else if (type == PVE) {
		printf("\nPVE (Polytype Value Error). Polytype field values are not equal.\n");
		system("pause");
	}
	else if (type == AVE) {
		printf("\nAVE (Analog Value Error). The value passed is not analog.\n");
		system("pause");
	}
}

/* Создание собственных элементов через таблицы истинности */
/* 43 означает что передаваемая таблица имеет размер 4х3 */
int customElm43(usi table[4][3], usi i1, usi i2) {
	error(isBoolat(table, 4, 3));
	int  out = 0;
	
	if (table[0][0] == i1 && table[0][1] == i2) {
		out = (int) table[0][2];
	}
	else if (table[1][0] == i1 && table[1][1] == i2) {
		out = table[1][2];
	}
	else if (table[2][0] == i1 && table[2][1] == i2) {
		out = table[2][2];
	}
	else if (table[3][0] == i1 && table[3][1] == i2) {
		out = table[3][2];
	}
	return out;
}

/* Функция реализует шину, предназначена для передачи значений элементов одного массива элементам другого */
int bus(usi input[], usi output[], usi lenIn, usi lenOut) {
	int out = 0;
	error(isBoola(input, lenIn));
	error(isBoola(output, lenOut));

	for (int i = 0; i < lenOut; i++) {
		output[i] = input[i];
	}

	if (input) {
		out = 1;
	}
	return out;
}

/* Функция приводящая аналоговое значение к двоичному */
int toBool(double signal) {
	usi out = 0;
	error(isAnalog(signal));

	if (signal >= limit) {
		out = 1;
	}
	else { ; }
	return out;
}

/* Функция реализующая транзистор */
int transistor(double signalCon, double signalMain) {
	usi out = 0;
	error(isAnalog(signalCon));
	error(isAnalog(signalMain));

	if (toBool(signalCon) == 1) {
		out = signalMain;
	}
	else { ; }

	return out;
}

#endif // ESL_H_INCLUDED
