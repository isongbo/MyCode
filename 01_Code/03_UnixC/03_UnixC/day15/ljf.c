#include <stdio.h>
#include <string.h>
int main (void) {
	char a[3] = "12";
	char b[3] = "AB";
	printf ("%s, %s\n", a, b);
	strcpy (b, "abcde");
	printf ("%s, %s\n", a, b);
	return 0;
}
