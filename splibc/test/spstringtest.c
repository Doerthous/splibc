#include "test.h"
#include <spstring.h>

enum {
	SPSTRLEN = 0,
	SPSTRCPY, SPSTRNCPY, SPSTRCMP,
	SPSTRNCMP, SPSTRRSV,
	FUNCTION_COUNT,
};

static char *functions[FUNCTION_COUNT] = {
	"spstrlen", "spstrcpy", "spstrncpy",
	"spstrcmp", "spstrncmp", "spstrrsv",
};

static void spstrlentest() {
	char string[] = "Hello world!";
	printf("Test string: %s, length: %d\n", string, spstrlen(string));
}
static void spstrcpytest() {
	char src[] = "Hello world!";
	char dest[] = "00000000000000";
	printf("Before copy: %s(src), %s(dest)\n", src, dest);
	spstrcpy(dest, src);
	printf("After copy: %s(src), %s(dest)\n", src, dest);
}
static void spstrncpytest() {
	char src[] = "Hello world!";
	char dest[] = "00000000000000";
	printf("Before copy: %s(src), %s(dest)\n", src, dest);
	spstrncpy(dest, src, 3);
	printf("After copy: %s(src), %s(dest)\n", src, dest);
}
static void spstrcmptest() {
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
static void spstrncmptest() {

}
static void spstrrsvtest() {

}
static void (*testfunctions[])() = {
	spstrlentest, spstrcpytest, spstrncpytest, 
	spstrcmptest, spstrncmptest, spstrrsvtest, 
};

void spstringtest() {
	printf("\n");
	char choise;
	while (1) {
		for (int i = 0; i < FUNCTION_COUNT; ++i) {
			printf("%d: %s\n", i, functions[i]);
		}
		printf("Select the test function: ");
		scanf("%d", &choise);
		if (choise < 0 || choise >= FUNCTION_COUNT) {
			return;
		}
		if (testfunctions[choise]) {
			testfunctions[choise]();
		}
		printf("\n");
	}
}