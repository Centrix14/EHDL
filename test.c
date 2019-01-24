#include <stdio.h>
#include <stdlib.h>
#include "esl.h"

int main() {
    /** Файл для тестирования EHDL_MWE **/
    /** File for testing EHDL_MWE **/

	usi in[3] = { 1, 1, en };
	usi out[3] = { 0, 0, en };
	And(in, out);
	printf("%d\t\t%d", out[0], out[1]);

    return 0;
}
