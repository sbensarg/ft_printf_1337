#include <stdio.h>
#include <fcntl.h>
#include "ft_printf.h"

int main(void)
{
 ft_printf("|%2.3d|\n", 100);
	ft_printf("|%3.3d|\n", 100);
	ft_printf("|a%3.3da|\n", 100);
	ft_printf("|%4.3d|\n", 100);
	ft_printf("|%2.3d|\n", -100);
	ft_printf("|%3.3d|\n", -100);
	ft_printf("|%4.3d|\n", -100);
	ft_printf("|%4.3d|\n", 0);
	ft_printf("|%1.3d|\n", 0);
	ft_printf("|a%1.3da|\n", 0);
	ft_printf("|%2.0d|\n", 100);
	ft_printf("|%3.0d|\n", 100);
	ft_printf("|a%3.0da|\n", 100);
	ft_printf("|%4.0d|\n", 100);
	ft_printf("|%2.0d|\n", -100);
	ft_printf("|%3.0d|\n", -100);
	ft_printf("|%4.0d|\n", -100);
	ft_printf("|%4.0d|\n", 0);
	ft_printf("|%1.0d|\n", 0);
	ft_printf("|%4.d|\n", 100);
	ft_printf("|%2.d|\n", -100);
	ft_printf("|%3.d|\n", -100);
	ft_printf("|%4.d|\n", -100);
	ft_printf("|%4.d|\n", 0);
	ft_printf("|%1.d|\n", 0);
	ft_printf("|a%1.0da|\n", 0);
	ft_printf("|%2.7d|\n", 100);
	ft_printf("|%15.7d|\n", 100);
	ft_printf("|a%3.7da|\n", 100);
	ft_printf("|%4.7d|\n", 100);
	ft_printf("|%2.7d|\n", -100);
	ft_printf("|%3.7d|\n", -100);
	ft_printf("|%15.7d|\n", -100);
	ft_printf("|%4.7d|\n", 0);
	ft_printf("|%1.7d|\n", 0);
	ft_printf("|a%1.7da|\n", 0);
	ft_printf("|%5.d|\n", 0);
	ft_printf("|%-5.d|\n", 0);
	ft_printf("|%0.d|\n", 0);
	ft_printf("|%1.d|\n", 0);
	ft_printf("|%.d|\n", 0);
	ft_printf("|%5.d|\n", 5);
	ft_printf("|%-5.d|\n", 5);
	ft_printf("|%0.d|\n", 5);
	ft_printf("|%1.d|\n", 5);
	ft_printf("|%.d|\n", 5);
	ft_printf("|%5.d|\n", -5);
	ft_printf("|%-5.d|\n", -5);
	ft_printf("|%0.d|\n", -5);
	ft_printf("|%1.d|\n", -5);
	ft_printf("|%.d|\n", -5);
	ft_printf("|%*.d|\n", 0, 0);
	ft_printf("|%*.d|\n", -5, 0);
	ft_printf("|%*.d|\n", 5, 0);
	ft_printf("|%*.d|\n", 1, 0);
	ft_printf("|%*.d|\n", 0, 5);
	ft_printf("|%*.d|\n", 1, -5);
	ft_printf("|%*.d|\n", -0, 5);
	ft_printf("|%*.d|\n", -5, 5);
	ft_printf("|%*.d|\n", 1, 5);
	ft_printf("|%*.d|\n", -5, -5);
	ft_printf("|%.*d|\n", 0, 0);
	ft_printf("|%.*d|\n", -5, 0);
	ft_printf("|%.*d|\n", 5, 0);
	ft_printf("|%.*d|\n", 1, 0);
	ft_printf("|%.*d|\n", -5, 5);
	ft_printf("|%.*d|\n", 5, -5);
	ft_printf("|%.*d|\n", 5, 5);
	ft_printf("|%.*d|\n", -5, -5);
	ft_printf("|%.*d|\n", 1, -1);
	ft_printf("|%.*d|\n", -1, 1);
	ft_printf("|%.*d|\n", 0, -5);
	ft_printf("|%.*d|\n", 0, 5);
	ft_printf("|%.*d|\n", 0, 1);
	ft_printf("|%.*d|\n", 0, -1);
	ft_printf("|%.*d|\n", -1, -1);
	ft_printf("|%.*d|\n", 1, 1);
	ft_printf("|%*.*d|\n", 1, 1, 1);
	ft_printf("|%*.*d|\n", -1, 1, 1);
	ft_printf("|%*.*d|\n", 1, -1, 1);
	ft_printf("|%*.*d|\n", 1, 1, -1);
	ft_printf("|%*.*d|\n", -1, -1, 1);
	ft_printf("|%*.*d|\n", 1, -1, -1);
	ft_printf("|%*.*d|\n", -1, -1, -1);
	ft_printf("|%*.*d|\n", 0, 0, 0);
	ft_printf("|%*.*d|\n", -1, 0, 1);
	ft_printf("|%*.*d|\n", 0, -1, -1);
	ft_printf("|%*.*d|\n", -1, -1, 0);
	ft_printf("|%*.*d|\n", 0, 0, -1);
	ft_printf("|%*.*d|\n", 5, 5, 1);
	ft_printf("|%*.*d|\n", -5, -5, 1);
	ft_printf("|%*.*d|\n", -5, 5, 1);
	ft_printf("|%*.*d|\n", 5, -5, 1);
	ft_printf("|%*.*d|\n", -5, 5, -15);
	ft_printf("|%*.*d|\n", 5, -5, -15);
	ft_printf("|%*.*d|\n", -15, -5, 1);
	ft_printf("|%*.*d|\n", 15, -5, 1);
	ft_printf("|%*.*d|\n", 5, -15, 1);
	ft_printf("|%*.*d|\n", -5, -15, 1);
	ft_printf("|%*.*d|\n", -15, -5, 0);
	ft_printf("|%*.*d|\n", 15, -5, -1);
	ft_printf("|%*.*d|\n", 5, -15, 0);
	ft_printf("|%*.*d|\n", -5, -15, -1);
	ft_printf("|%*.*d|\n", 5, -5, 1);
	ft_printf("|%*.*d|\n", 1, 1, 10);
	ft_printf("|%*.*d|\n", -1, 10, 1);
	ft_printf("|%*.*d|\n", 10, -1, 1);
	ft_printf("|%*.*d|\n", 1, 10, -1);
	ft_printf("|%*.*d|\n", -1, -10, 1);
	ft_printf("|%*.*d|\n", 1, 1, -21);
	ft_printf("|%*.*d|\n", -1, 1, 10);
	ft_printf("|%*.*d|\n", 1, -10, 10);
	ft_printf("|%*.*d|\n", 10, 10, -1);
	ft_printf("|%*.*d|\n", -1, -10, 1);
	ft_printf("|%*.*d|\n", -1, 10, 1);
	ft_printf("|%*.*d|\n", 1, -10, 1);
	ft_printf("|%*.*d|\n", 1, 10, -1);
	ft_printf("|%*.*d|\n", -10, -1, 10);
	ft_printf("|%02.3d|\n", 100);
	ft_printf("|%03.3d|\n", 100);
	ft_printf("|a%03.3da|\n", 100);
	ft_printf("|%04.3d|\n", 100);
	ft_printf("|%02.3d|\n", -100);
	ft_printf("|%03.3d|\n", -100);
	ft_printf("|%04.3d|\n", -100);
	ft_printf("|%04.3d|\n", 0);
	ft_printf("|%01.3d|\n", 0);
	ft_printf("|a%01.3da|\n", 0);
	ft_printf("|%02.0d|\n", 100);
	ft_printf("|%03.0d|\n", 100);
	ft_printf("|a%03.0da|\n", 100);
	ft_printf("|%04.0d|\n", 100);
	ft_printf("|%02.0d|\n", -100);
	ft_printf("|%03.0d|\n", -100);
	ft_printf("|%04.0d|\n", -100);
	ft_printf("|%04.0d|\n", 0);
	ft_printf("|%01.0d|\n", 0);
	ft_printf("|%04.d|\n", 100);
	ft_printf("|%02.d|\n", -100);
	ft_printf("|%03.d|\n", -100);
	ft_printf("|%04.d|\n", -100);
	ft_printf("|%04.d|\n", 0);
	ft_printf("|%01.d|\n", 0);
	ft_printf("|a%01.0da|\n", 0);
	ft_printf("|%02.7d|\n", 100);
	ft_printf("|%015.7d|\n", 100);
	ft_printf("|a%03.7da|\n", 100);
	ft_printf("|%04.7d|\n", 100);
	ft_printf("|%02.7d|\n", -100);
	ft_printf("|%03.7d|\n", -100);
	ft_printf("|%015.7d|\n", -100);
	ft_printf("|%04.7d|\n", 0);
	ft_printf("|%01.7d|\n", 0);
	ft_printf("|a%01.7da|\n", 0);
	ft_printf("|%05.d|\n", 0);
	ft_printf("|%05.d|\n", 0);
	ft_printf("|%00.d|\n", 0);
	ft_printf("|%01.d|\n", 0);
	ft_printf("|%0.d|\n", 0);
	ft_printf("|%05.d|\n", 5);
	ft_printf("|%05.d|\n", 5);
	ft_printf("|%00.d|\n", 5);
	ft_printf("|%01.d|\n", 5);
	ft_printf("|%0.d|\n", 5);
	ft_printf("|%05.d|\n", -5);
	ft_printf("|%05.d|\n", -5);
	ft_printf("|%00.d|\n", -5);
	ft_printf("|%01.d|\n", -5);
	ft_printf("|%0.d|\n", -5);
	ft_printf("|%0*.d|\n", 0, 0);
	ft_printf("|%0*.d|\n", -5, 0);
	ft_printf("|%0*.d|\n", 5, 0);
	ft_printf("|%0*.d|\n", 1, 0);
	ft_printf("|%0*.d|\n", 0, 5);
	ft_printf("|%0*.d|\n", 1, -5);
	ft_printf("|%0*.d|\n", -0, 5);
	ft_printf("|%0*.d|\n", -5, 5);
	ft_printf("|%0*.d|\n", 1, 5);
	ft_printf("|%0*.d|\n", -5, -5);
	ft_printf("|%0.*d|\n", 0, 0);
	ft_printf("|%0.*d|\n", -5, 0);
	ft_printf("|%0.*d|\n", 5, 0);
	ft_printf("|%0.*d|\n", 1, 0);
	ft_printf("|%0.*d|\n", -5, 5);
	ft_printf("|%0.*d|\n", 5, -5);
	ft_printf("|%0.*d|\n", 5, 5);
	ft_printf("|%0.*d|\n", -5, -5);
	ft_printf("|%0.*d|\n", 1, -1);
	ft_printf("|%0.*d|\n", -1, 1);
	ft_printf("|%0.*d|\n", 0, -5);
	ft_printf("|%0.*d|\n", 0, 5);
	ft_printf("|%0.*d|\n", 0, 1);
	ft_printf("|%0.*d|\n", 0, -1);
	ft_printf("|%0.*d|\n", -1, -1);
	ft_printf("|%0.*d|\n", 1, 1);
	ft_printf("|%0*.*d|\n", 1, 1, 1);
	ft_printf("|%0*.*d|\n", -1, 1, 1);
	ft_printf("|%0*.*d|\n", 1, -1, 1);
	ft_printf("|%0*.*d|\n", 1, 1, -1);
	ft_printf("|%0*.*d|\n", -1, -1, 1);
	ft_printf("|%0*.*d|\n", 1, -1, -1);
	ft_printf("|%0*.*d|\n", -1, -1, -1);
	ft_printf("|%0*.*d|\n", 0, 0, 0);
	ft_printf("|%0*.*d|\n", -1, 0, 1);
	ft_printf("|%0*.*d|\n", 0, -1, -1);
	ft_printf("|%0*.*d|\n", -1, -1, 0);
	ft_printf("|%0*.*d|\n", 0, 0, -1);
	ft_printf("|%0*.*d|\n", 5, 5, 1);
	ft_printf("|%0*.*d|\n", -5, -5, 1);
	ft_printf("|%0*.*d|\n", -5, 5, 1);
	ft_printf("|%0*.*d|\n", 5, -5, 1);
	ft_printf("|%0*.*d|\n", -5, 5, -15);
	ft_printf("|%0*.*d|\n", 5, -5, -15);
	ft_printf("|%0*.*d|\n", -15, -5, 1);
	ft_printf("|%0*.*d|\n", 15, -5, 1);
	ft_printf("|%0*.*d|\n", 5, -15, 1);
	ft_printf("|%0*.*d|\n", -5, -15, 1);
	ft_printf("|%0*.*d|\n", -15, -5, 0);
	ft_printf("|%0*.*d|\n", 15, -5, -1);
	ft_printf("|%0*.*d|\n", 5, -15, 0);
	ft_printf("|%0*.*d|\n", -5, -15, -1);
	ft_printf("|%0*.*d|\n", 5, -5, 1);
	ft_printf("|%0*.*d|\n", 1, 1, 10);
	ft_printf("|%0*.*d|\n", -1, 10, 1);
	ft_printf("|%0*.*d|\n", 10, -1, 1);
	ft_printf("|%0*.*d|\n", 1, 10, -1);
	ft_printf("|%0*.*d|\n", -1, -10, 1);
	ft_printf("|%0*.*d|\n", 1, 1, -21);
	ft_printf("|%0*.*d|\n", -1, 1, 10);
	ft_printf("|%0*.*d|\n", 1, -10, 10);
	ft_printf("|%0*.*d|\n", 10, 10, -1);
	ft_printf("|%0*.*d|\n", -1, -10, 1);
	ft_printf("|%0*.*d|\n", -1, 10, 1);
	ft_printf("|%0*.*d|\n", 1, -10, 1);
	ft_printf("|%0*.*d|\n", 1, 10, -1);
	ft_printf("|%0*.*d|\n", -10, -1, 10);

}