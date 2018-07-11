#include "test.h"
#include <spstdlib.h>

void spstdlibtest() {}

/*enum {
	SPSTRLEN = 1,
	SPSTRCPY,
	SPSTRNCPY,
	SPSTRCMP,
	SPSTRNCMP,
	SPSTRRSV,
	FUNCTION_COUNT,
};

void spstringtest() {
	printf("\n");
	char choise;
	while (1) {
		printf("%d. spstrlen\n", SPSTRLEN);
		printf("%d. spstrcpy\n", SPSTRCPY);
		printf("%d. spstrncpy\n", SPSTRNCPY);
		printf("%d. spstrcmp\n", SPSTRCMP);
		printf("%d. spstrncmp\n", SPSTRNCMP);
		printf("%d. spstrrsv\n", SPSTRRSV);
		printf("Select the test function: ");
		scanf("%d", &choise);
		switch (choise) {
			case SPSTRLEN: {
				char string[] = "Hello world!";
				printf("Test string: %s, length: %d\n", string, spstrlen(string));
			} break;
			case SPSTRCPY: {
				char src[] = "Hello world!";
				char dest[] = "00000000000000";
				printf("Before copy: %s(src), %s(dest)\n", src, dest);
				spstrcpy(dest, src);
				printf("After copy: %s(src), %s(dest)\n", src, dest);
			} break;
			case SPSTRNCPY: {
				char src[] = "Hello world!";
				char dest[] = "00000000000000";
				printf("Before copy: %s(src), %s(dest)\n", src, dest);
				spstrncpy(dest, src, 3);
				printf("After copy: %s(src), %s(dest)\n", src, dest);
			} break;
			case SPSTRCMP: {
				const int str_cnt = 4;
				int result;
				char *str[] = {
					"Hello", "world",
					"world", "Hello",
				};
				for (int i = 0; i < str_cnt-1; ++i) {
					result = spstrcmp(str[i], str[i+1]);
					printf("Compare %s and %s: %s\n", str[i], str[i+1],
							result > 0 ? ">" : result == 0 ? "=" : "<");
				}		
			}
			case SPSTRNCMP: {

			} break;
			case SPSTRRSV: {

			} break;
			default: {
				return;
			}
		}
		printf("\n");
	}
}*/