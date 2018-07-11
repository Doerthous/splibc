#include "test.h"
#include <spctype.h>

enum {
	SPISALNUM = 0,
	SPISALPHA, SPISCNTRL, SPISDIGIT,
	SPISGRAPH, SPISLOWER, SPISUPPER,
	SPISPRINT, SPISPUNT, SPISSPACE,
	SPISXDIGIT, SPTOLOWER, SPTOUPPER,
	FUNCTION_COUNT,
};

static char *functions[FUNCTION_COUNT] = {
	"spisalnum", "spisalpha", "spiscntrl",
	"spisdigit", "spisgraph", "spislower",
	"spisupper", "spisprint", "spispunct",
	"spisspace", "spisxdigit", "sptolower",
	"sptoupper",
};

/*
	函数测试函数
*/
#define __SPCTYPE_TEST_FUNC_HELPER(function, type) \
	char string[] = "7as89!@#$&^&\n*TGY78gy&^E%F\tGJ*&*^U%E \
		YDRTYJd f|}{}:LK><>MN<\":KL7a897fda78d90f"; \
	if (strncmp(type, "to", 2)) { \
		int len = strlen(string); \
		for (int i = 0; i < len; ++i) { \
			printf("%c %s %s\n", string[i], \
				function((int)string[i]) ? "is a" : "is not a", \
				type); \
		} \
	} \
	else { \
		char *p = string; \
		printf("Before: %s\n", string); \
		for (; *p; ++p) { \
			*p = (char)function((int)*p); \
		} \
		printf("After: %s\n", string); \
	} 

#define DEFINE_TEST_FUNCTION1(funcname, type) \
static void funcname##test() { \
	__SPCTYPE_TEST_FUNC_HELPER(funcname, type) \
}

DEFINE_TEST_FUNCTION1(spisalnum, "alnum");
DEFINE_TEST_FUNCTION1(spisalpha, "alpha");
DEFINE_TEST_FUNCTION1(spiscntrl, "cntrl");
DEFINE_TEST_FUNCTION1(spisdigit, "digit");
DEFINE_TEST_FUNCTION1(spisgraph, "graph");
DEFINE_TEST_FUNCTION1(spislower, "lower");
DEFINE_TEST_FUNCTION1(spisupper, "upper");
DEFINE_TEST_FUNCTION1(spisprint, "print");
DEFINE_TEST_FUNCTION1(spispunct, "punct");
DEFINE_TEST_FUNCTION1(spisspace, "space");
DEFINE_TEST_FUNCTION1(spisxdigit, "xdigit");
DEFINE_TEST_FUNCTION1(sptolower, "tolower");
DEFINE_TEST_FUNCTION1(sptoupper, "toupper");


static void (*testfunctions[])() = {
	spisalnumtest, spisalphatest, spiscntrltest, 
	spisdigittest, spisgraphtest, spislowertest, 
	spisuppertest, spisprinttest, spispuncttest,
	spisspacetest, spisxdigittest, sptolowertest,
	sptouppertest,
};

/*

*/
void spctypetest() {
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