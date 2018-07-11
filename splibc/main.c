#include <stdio.h>
#include "test/test.h"

enum {
	SPSTRING = 0,
	SPSTDIO, SPCTYPE, SPSTDLIB,
	FILE_COUNT,
};

static char *files[FILE_COUNT] = {
	"spstring.h", "spstdio.h", "spctype.h", 
	"spstdlib.h"
};

int main(int argc, char const *argv[]) {
	char choise = 1;
	while (choise) {
		for (int i = 0; i < FILE_COUNT; ++i) {
			printf("%d: %s\n", i, files[i]);
		}
		printf("Select the test file: ");
		scanf("%d", &choise);
		switch (choise) {
			case SPSTRING: {
				spstringtest();
			} break;
			case SPSTDIO: {
				spstdiotest();
			} break;
			case SPCTYPE: {
				spctypetest();
			} break;
			case SPSTDLIB: {
				spstdlibtest();
			} break;
			default: {
				return 0;
			}
		}
		printf("\n");
	}
	return 0;
}