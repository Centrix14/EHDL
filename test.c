#include <stdio.h>
#include <stdlib.h>
#include "esl.h"
#include "ael.h"

int main() {
    /** Файл для тестирования esl.h **/
    /** File for testing esl.h **/
	usi s, pi;
	halfadder(1, 1, &s, &pi);
	printf("%d\t%d", s, pi);

    return 0;
}
