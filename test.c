#include <stdio.h>
#include <stdlib.h>
#include "esl.h"

int main() {
    /** Файл для тестирования esl.h **/
    /** File for testing esl.h **/
	usi first[2] = { 1, 0 };
	usi second[2] = { 0, 0 };
	bus(first, second, 2, 2);
	printf("%d\t%d", second[0], second[1]);
    return 0;
}
