#include <spctype.h>

static int iselem(char *str, char ch) {
	char *p = str;
	while (*p++) {
		if (ch == *p) {
			return 1;
		}
	}
	return 0;
}

/*
	检查所传的字符是否是字母和数字。
*/
int spisalnum(int ch) {
	return spisalpha(ch) || spisdigit(ch);
}

/*
	检查所传的字符是否是字母。
*/
int spisalpha(int ch) {
	return ('a' <= ch && ch <= 'z') || 
			('A' <= ch && ch <= 'Z');
}

/*
	检查所传的字符是否是控制字符。
	根据标准 ASCII 字符集，控制字符的 ASCII 编码介于 
	0x00 (NUL) 和 0x1f (US) 之间，以及 0x7f (DEL)，
	某些平台的特定编译器实现还可以在扩展字符集（0x7f 以上）
	中定义额外的控制字符。
*/
int spiscntrl(int ch) {
	return (0x00 <= ch && ch <= 0x1f) ||
			ch == 0x7f;
}

/*
	检查所传的字符是否是十进制数字。
*/
int spisdigit(int ch) {
	return '0' <= ch && ch <= '9';
}

/*
	检查所传的字符是否有图形表示法。
	带有图形表示法的字符是除了空白字符
	（比如 ' '）以外的所有可打印的字符。
	字母数字字符以及标点符号字符的集合。
*/
int spisgraph(int ch) {
	return spisalnum(ch) || spispunct(ch);
}

/*
	检查所传的字符是否是小写字母。
*/
int spislower(int ch) {
	return 'a' <= ch && ch <= 'z';
}

/*
	检查所传的字符是否是大写字母。
*/
int spisupper(int ch) {
	return 'A' <= ch && ch <= 'Z';
}

/*
	检查所传的字符是否是可打印的。
	可打印字符是非控制字符的字符。字母数字字符、标点符
	号字符和空格字符的集合。
*/
int spisprint(int ch) {
	return spisgraph(ch) || spisspace(ch);
}

/*
	检查所传的字符是否是标点符号字符。
	标点符号字符：
		! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
*/
int spispunct(int ch) {
	return iselem("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~", ch);
}

/*
	检查所传的字符是否是空白字符。
*/
int spisspace(int ch) {
	return iselem(" \t\n\v\f\r", ch);
}

/*
	检查所传的字符是否是十六进制数字。
*/
int spisxdigit(int ch) {
	return spisdigit(ch) &&
			(('a' <= ch && ch <= 'f') ||
			('A' <= ch && ch <= 'Z'));
}

/*
	把大写字母转换为小写字母。
*/
int sptolower(int ch) {
	if (spisupper(ch)) {
		return ch + ('a' - 'A');
	}
	return ch;
}

/*
	把小写字母转换为大写字母。
*/
int sptoupper(int ch) {
	if (spislower(ch)) {
		return ch - ('a' - 'A');
	}
	return ch;
}
