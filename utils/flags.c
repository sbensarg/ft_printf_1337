#include <stdio.h>

int main(void)
{
  char *p = "azerrty";

	printf("width\n");
printf("Controlling integer width with printf\n");
	printf("%5d\n", 0);
	printf("%5d\n", 123456789);
	printf("%5d\n", -10);
	printf("%5d\n", -123456789);
printf("width trick\n");
	printf("[%*s]\n", 5, "sara");
printf("Left-justifying printf integer output\n");
	printf("[%-5d]\n", 4);
	printf("[%-5d]\n", 123456789);
	printf("[%-5d]\n", -10);
	printf("[%-5d]\n", -123456789);
printf("The printf integer zero-fill option\n");
	printf("[%05d]\n", 4);
	printf("[%05d]\n", 1);
	printf("[%05d]\n", 123456789);
	printf("[%05d]\n", -10);
	printf("[%05d]\n", -123456789);
printf("precision\n");
	printf("[%.5d]\n", 2);
	printf("[%.*d]\n", 5, 2);
printf("characters : %c %c \n", 'a', 65);
printf("%s \n", "A string");
printf("[%*s]\n", 15, "A String"); 
printf("%p", p);
}
