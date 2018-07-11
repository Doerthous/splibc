此目录可单独提出作为 libc 函数库。

所有实现文件或头文件都应包含 spstddef.h，以判断是否作为标准C函数库使用。

所有类型定义保持名字不变，函数在名前加 sp，用宏定义替换标准库函数。

assert.h 
ctype.h 完成
errno.h 完成
float.h 
limits.h 完成
locale.h
math.h
setjmp.h
signal.h
stdarg.h 完成
stddef.h 完成
stdio.h
stdlib.h
string.h
time.h