#include <stido.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define int long long // 64 bit target

int token;  //current token
char *src, *old_src; //pointer to source code string
int poolsize;
int line;
int *text,            // text segment
    *old_text,        // for dump text segment
    *stack;           // stack
char *data;           // data segment
int *pc, *bp, *sp, ax, cycle; // virtual machine registers

// instructions
enum { LEA ,IMM ,JMP ,CALL,JZ  ,JNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PUSH,
       OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,
       OPEN,READ,CLOS,PRTF,MALC,MSET,MCMP,EXIT };

void next() {
	token = *src++;
	return;
}

void expression(int level) {
	// right now does nothing
}

void program() {
	next();
	while (token > 0) {
		printf("token is: %c\n", token);
		next();
	}
}

int eval() {
	// right now does nothing
	return 0;
}

int main(int argc, char **argv) {
	int i, fd;

	argc--;
	argv++;

	poolsize = 256*1024; //random size
	line = 1;

	if((fd = open(*argv,0)) < 0) {
		printf("could not open(%s)\n", *argv);
		return -1;
	}

	if(!(src = old_src = malloc(poolsize))) {
		printf("could not open(%d) for source area\n", poolsize);
		return -1;
	}

	//read the source file

	if ((i = read(fd, src, poolsize-1)) <= 0) {
		printf("read() returned %d\n", i);
		return -1;
	}

	src[i] = 0; //adding EOF character
	close(fd);

	program();
	return eval();
}