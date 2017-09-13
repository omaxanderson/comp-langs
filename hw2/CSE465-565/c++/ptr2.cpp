#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

int a = 10;
char c1 = 'Z';
char c2 = 'Y';
int b[4] = { 0x7ABBCCDD, 0x01, 10, 0x7F0000AA };
float c[3] = { 3.14, 2.17, 0 };
char str[] = "ABC";
char ex = '!';
int d = 0xffffffff;

void dump(byte *ptr, int nb) {
	int i;
	for (i=0; i<nb; i++, ptr++)
		printf("%p %x\n", ptr, *ptr);	
}

void s1() {
	int *ptr;
	ptr = &a;
	*ptr = 0x54;
	*ptr += 1;

	char *cptr1 = &c1;
	char *cptr2 = &c2;
	char tmp = *cptr1;
	*cptr1 = *cptr2;
	*cptr2 = tmp;
}

void s2() {
	int *p = b;
	*p = 0x11;
	*(p+1) = 0x22;
	p[2] = 0x33;
	
	char *q = &ex;
	q[0] = (char)100;
}

void s3() {
	float *ptr = c;
	*(ptr + 1) = 3.14;
	ptr[-3] = 3.14;
}

void s4() {
	char *ptr = (char*)&d;
	ptr[0] = 0x00;
	ptr[1] = 0x01;
	ptr[2] = 0x02;
	ptr[3] = 0x03;
}

void s5() {
	long *long1 = (long *)&a;
	long *long2 = (long *)(&c1+1);
	*long2 = *long1;
}

int main(int argc, char *argv [])
{
	printf("&a = %p\n", &a);
	printf("&c1 = %p\n", &c1);
	printf("&c2 = %p\n", &c2);
	printf("b = %p\n", b);
	printf("c = %p\n", c);
	printf("str = %p\n", str);
	printf("&ex = %p\n", &ex);
	printf("&d = %p\n", &d);
	s5();
	dump((byte *)&a, 53);
}
