/*
	Doerthous

	修改于 2016/11/10 19:09
	修改了ustr,xstr,istr使其能够用paddingChar
	调补到最小minSize. 实现了%08x格式
*/

#include <spstdio.h>
#include <spctype.h>

// buffer size is deficient
#define BADBUF -99


/*
	将给定数字转化为以0结尾的字符串
	num:	给定的无符号整数
	str: 	缓冲区
	size: 	缓冲区大小(size >= num数字个数+1)
	return: 如果成功, 返回字符串长度(不包括结尾0). 否则返回0
*/
static size_t ustr(unsigned int num, char * str, 
	size_t size, int minSize, char paddingChar) {
	char tab[16] = {'0','1','2','3','4','5','6','7','8','9'};
	int idx = size - 1;
	str[idx--] = 0;
	for(--minSize; idx >= 0; --minSize){
		str[idx--] = tab[num%10];
		num /= 10;
		if(!num) {		
			for(; minSize > 0 && idx >= 0; --minSize) // 填充
				str[idx--] = paddingChar;
			size_t distance = ++idx;
			if(distance > 1) // 前移
				for(; idx <= size; ++idx)
					str[idx-distance] = str[idx];
			return size-distance-1; 
		}
	}
	return 0; 
}

static size_t istr(int num, char * str, 
	size_t size, int minSize, char paddingChar) {
	if(num < 0){
		num = -num;
		str[0] = '-';
		num = ustr(num, str+1, size-1, minSize-1, paddingChar); 
		return num == 0 ? num : num+1;
	} 
	else {
		return ustr(num, str, size, minSize, paddingChar);
	}
}

static size_t str2u(const char * str, size_t size) {
	size_t i = 1, num = 0;
	for(; size; i *= 10, --size){
		num += (str[size-1] - '0')*i;
	}
	return num;
} 

static size_t xstr(unsigned int num, char * str, size_t size, int minSize, char paddingChar) {
	char tab[16] = {'0','1','2','3','4','5','6','7',
					'8','9','A','B','C','D','E','F'};
	int idx = size - 1;
	str[idx--] = 0;
	for(--minSize; idx >= 0; --minSize){
		str[idx--] = tab[num%16];
		num >>= 4;
		if(!num) {		
			for(; minSize > 0 && idx >= 0; --minSize) // 填充
				str[idx--] = paddingChar;
			size_t distance = ++idx;
			if(distance > 1) // 前移
				for(; idx <= size; ++idx)
					str[idx-distance] = str[idx];
			return size-distance-1; 
		}
	}
	return 0; 
}

int spsnprintf(char * mem, size_t size, const char * fmt, ...) {
	char tbuf[1024];
	va_list argPt;
	va_start(argPt, fmt);
	int i, j, t;
	for(i = 0, j = 0; j < size-1 && fmt[i]; ++i){
		if(fmt[i] != '%'){ // 其他字符 
			mem[j] = fmt[i];
			++j;
		}else{ // 格式化数据 
			char padding = ' ';
			int numB = i+1, numE = i+1;
			while(spisdigit(fmt[++i]));
			numE = i;
			int minSize = str2u(fmt+numB, numE-numB);
			if(fmt[numB] == '0')
				padding = '0';
			switch(fmt[i]){ // 判断格式
				case 'd':{
					t = istr(va_arg(argPt, int), &mem[j], size-j, minSize, padding);
				} break;
				case 'u':{
					t = ustr(va_arg(argPt, int), &mem[j], size-j, minSize, padding);
				} break;
				case 'x':{
					t = xstr(va_arg(argPt, int), &mem[j], size-j, minSize, padding);	
				} break;
				default :{
					for(--numB, t = numB; t <= numE; ++t){
						mem[j+t-numB] = fmt[t];
					}
					t -= numB;
				}
			}
			if(t<0)return -1; // buffer不足 
			j += t;
		} 
	}
	mem[j] = 0;
	va_end(argPt);
	return 0;
}