#include <stdio.h>
#include <string.h>

int main(int argc, char *argv []) {
	const int N = 100;
	char buf1[N], buf2[N], buf3[N], buf4[N];
	strcpy(buf1, "Hello");		// potential overruns
	strcpy(buf2, "World");
	strcpy(buf3, "!");
	strcpy(buf4, "CSE");

	char *p1 = buf1;
	char *p2 = buf2;
	char *p3 = &buf3[0];
	char *p4 = buf4 + 2;
	printf("|%s|%s|%s|%s|\n", buf1, buf2, buf3, buf4);
	printf("|%s|%s|%s|%s|\n", p1, p2, p3, p4);

	strcpy(p1, "0123456789");
	strcat(p2, "0123456789");
	*p4 = '#';
	strcat(p4, "0123456789");

	printf("|%s|%s|%s|%s|\n", buf1, buf2, buf3, buf4);
	printf("|%s|%s|%s|%s|\n", p1, p2, p3, p4);
}
