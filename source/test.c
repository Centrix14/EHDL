#include <stdio.h>
#include <stdlib.h>
#include "lio.h"

int main() {
    /** Файл для тестирования EHDL_MWE **/
    /** File for testing EHDL_MWE **/

	Console.out = printf;
	Console.out("Hello world!");

    return 0;
}
