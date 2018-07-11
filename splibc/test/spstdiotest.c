#include "test.h"
#include <spstdio.h>

enum {
	SPSNPRINTF = 1,
	SPPUTCHAR,
	SPPUTS,
	SPPRINTF,
	/*SPSTRNCMP,
	SPSTRRSV,*/
	FUNCTION_COUNT,
};

void spstdiotest() {
	printf("\n");
	char choise;
	while (choise) {
		printf("%d. spsnprintf\n", SPSNPRINTF);
		printf("%d. spputchar\n", SPPUTCHAR);
		printf("%d. spputs\n", SPPUTS);
		printf("%d. spprintf\n", SPPRINTF);
		/*printf("%d. spstrncmp\n", SPSTRNCMP);
		printf("%d. spstrrsv\n", SPSTRRSV);*/
		printf("Select the test function: ");
		scanf("%d", &choise);
		switch (choise) {
			case SPSNPRINTF: {
				char string[16];
				spsnprintf(string, 16, "%d", 1234567890);
				printf("%s\n", string);
			} break;
			case SPPUTCHAR: {
				char str[] = "Hello world!\n";
				char *p = str;
				while (*p) {
					spputchar(*p++);
				}
			} break;
			case SPPUTS: {
				char str[] = "Hello world!\n";
				spputs(str);
			} break;
			case SPPRINTF: {
				spprintf("%+65.565hhs\n% 65.565hhs\n%-65.565hhs\n%065.565hhs\n%#65.565hhs\n",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs");
				spprintf("%+6u\n% 6u\n%-6u\n%06u\n%#6u\n", -1, 0, -128, 512, 1024);
				spprintf("%+9x\n% 9x\n%-9x\n%09x\n%#9x\n", -1, 0, -128, 512, 1024);
				spprintf("%+9d\n% 9d\n%-9d\n%09d\n%#9d\n", -1, 0, -128, 512, 1024);
				spprintf("%+9c\n% 9c\n%-9c\n%09c\n%#9c\n", 'c', 32, 'a', 'f', 'd');

				printf("%+65.565hhs\n% 65.565hhs\n%-65.565hhs\n%065.565hhs\n%#65.565hhs\n",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs",
					"%+65.565hhs,%-65.565hhs,% 65.565hhs,%065.565hhs,%#65.565hhs");
				printf("%+6u\n% 6u\n%-6u\n%06u\n%#6u\n", -1, 0, -128, 512, 1024);
				printf("%+9x\n% 9x\n%-9x\n%09x\n%#9x\n", -1, 0, -128, 512, 1024);
				printf("%+9d\n% 9d\n%-9d\n%09d\n%#9d\n", -1, 0, -128, 512, 1024);
				printf("%+9c\n% 9c\n%-9c\n%09c\n%#9c\n", 'c', 32, 'a', 'f', 'd');
			} break;
			/*case SPSTRNCMP: {

			} break;
			case SPSTRRSV: {

			} break;*/
			default: {
				choise = 0;
			}
		}
		printf("\n");
	}
}