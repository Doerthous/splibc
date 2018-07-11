#include <spstdio.h>
#include <spstring.h>

struct number {
	unsigned int num;
	int fmt;
};
static void putchars(const char *s) {
	while (s && *s) {
		spputchar(*s++);
	}
}
static int print_number(void *param, int (func)(int)) {
	struct number *p = (struct number*)param;
	struct number num;
	num.num = p->num;
	num.fmt = p->fmt;
	int count = 1;
	static char table[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	unsigned int h = num.num / num.fmt;
	unsigned int l = num.num % num.fmt;
	if (h) {
		num.num = h;
		count = print_number(&num, func) + 1;
	}
	func ? func(table[l]) : 0;
	return count;
}
static int print_string(void *param, int (func)(int)) {
	char *s = (char *)param;
	int len = 0;
	while (*s) {
		func ? func(*s) : 0;
		++len;
		++s;
	}
	return len;
}
static int print_char(void *param, int (func)(int)) {
	func ? func((int)param) : 0;
	return 1;
}
static void duxsc(void *param, int width, char paddingChar,
	int (f)(void *, int (*)(int)),
	void *before, void *after,
	char *prefix, char *suffix) {
	int pLen = prefix ? spstrlen(prefix) : 0;
	int sLen = suffix ? spstrlen(suffix) : 0;
	if (before) {
		putchars(prefix);
	}
	int start = f(param, (int(*)(int))before) + pLen + sLen;
	if (before) {
		putchars(suffix);
	}
	for (int i = start; i < width; ++i) {
		spputchar(paddingChar);
	}
	if (after) {
		putchars(prefix);
	}
	f(param, (int(*)(int))after);
	if (after) {
		putchars(suffix);
	}
}
// 
static char get_type(const char **end) { // 使p指向type的后一个字符
	char type = 0;
	const char *begin = *end;
	int has_found = 0;
	while (**end && !has_found) {
		switch (**end) {
		case 'd':
		case 'u':
		case 'x':
		case 's':
		case 'c':
			type = **end;
			has_found = 1;
			break;
		}
		++(*end);
	}
	if (!has_found) // 没有检测到有效的类型
		*end = begin;
	return type;
}
static char get_flag(const char **b) {
	char flag = 0;
	switch (**b) {
		case '+': // 输出正负号
		case '-': // 左对齐，默认右对齐
		case ' ': // 前面补空格，正数不输出正号，负数输出负号
		case '0': // 前面补0
		case '#': // 增加前缀
			flag = **b;
			++(*b);
			break;
	}
	return flag;
}
static int get_width(const char **b, va_list ap) {
	int width = 0;
	if (**b == '*') {
		width = va_arg(ap, int);
		++(*b);
	}
	else {
		while ('0' <= **b && **b <= '9') {
			width *= 10;
			width += **b - '0';
			++(*b);
		}
	}
	return width;
}
static int get_precision(const char **b, va_list ap) {
	int precision = 0;
	if (**b == '.') {
		++(*b);
		precision = get_width(b, ap);
	}
	return precision;
}
static int get_length(const char **b, const char *end) {
	while (*b != end) {
		++(*b);
	}
	return 0;
}
//
static void print(char type, char flag, int width, int precision, int length, va_list *ap) {
	void *bFunc = NULL, *aFunc = NULL;
	char *p = NULL, *s = NULL;
	char pCh = '0';
	int (*f)(void *, int(*)(int));
	void *param;
	struct number num;
	// 选择填充字符和对齐方式
	pCh = ' ';
	if (flag == '0') {
		pCh = '0';
	}
	if (flag == '-') {
		bFunc = spputchar;
		aFunc = NULL;
	}
	else {
		bFunc = NULL;
		aFunc = spputchar;
	}
	//
	int sNum = 0;
	switch (type) {
		case 'x':
		case 'u':
		case 'd':
			// 判断格式和前缀
			num.fmt = 10;
			if (type == 'x') {
				num.fmt = 16;
				if (flag == '#') {
					p = "0x";
				}
			}
			sNum = va_arg(*ap, int);
			// 负数转正
			if (type == 'd' && flag == '+') {
				p = "+";
				if (sNum < 0) {
					p = "-";
					sNum = -sNum;
				}
			}
			else if (type == 'd' && sNum < 0) {
				p = "-";
				sNum = -sNum;
			}
			num.num = sNum;
			param = &num;
			f = print_number;
			break;
		case 's':
		case 'c':
			// 选择类型
			p = s = 0;
			if (type == 's') {
				f = print_string;
				param = va_arg(*ap, char *);
			}
			else {
				f = print_char;
				param = (void *)va_arg(*ap, int);
			}	
			break;
	}
	duxsc(param, width, pCh, f, bFunc, aFunc, p, s);
}

int spprintf(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	int has_type = 1;
	while (*fmt) {
		if (*fmt == '%' && has_type) {
			char type = 0, flag = 0;
			int width = 0, precision = 0, length = 0;
			const char *begin = fmt, *end = fmt;
			if (has_type = type = get_type(&end)) {
				++begin;
				flag = get_flag(&begin);
				width = get_width(&begin, ap);
				precision = get_precision(&begin, ap);
				get_length(&begin, end);
				print(type, flag, width, precision, length, &ap);
			}
			fmt = end;
		}
		else {
			spputchar(*fmt++);
		}
	}
	va_end(ap);
	return 0;
}