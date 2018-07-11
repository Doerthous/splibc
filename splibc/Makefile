OBJ = splibc/spstring.o splibc/spsnprintf.o splibc/spprintf.o \
		splibc/spstdio.o \
		splibc/spctype.o splibc/spstdlib.o \
		test/spstringtest.o test/spstdiotest.o \
		test/spctypetest.o test/spstdlibtest.o main.o 

CFLAGS = -c -std=c99 -I splibc/include/

run: $(OBJ)
ifeq ($(shell uname), Linux)
	gcc -lm $? -o splibc
else
	gcc $? -o splibc.exe
endif

%.o: %.c
	gcc $(CFLAGS) -c $? -o $@

clean:
	rm -f $(OBJ) splibc.exe