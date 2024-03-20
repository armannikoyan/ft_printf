#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main()
{
	printf("\nMine: %d\n", ft_printf("!%40.36d!", -1205487050));
	printf("\n");
	printf("\nOrig: %d\n", printf("!%40.36d!", -1205487050));
	printf("\nMine: %d\n", ft_printf("!%40.36d!", 1205487050));
	printf("\n");
	printf("\nOrig: %d\n", printf("!%40.36d!", 1205487050));
	printf("\nMine: %d\n", ft_printf(">------------<%21.2d>------------<", -1718311780));
	printf("\n");
	printf("\nOrig: %d\n", printf(">------------<%21.2d>------------<", -1718311780));
	printf("\nMine: %d\n", ft_printf("\\!/%24.10d\\!/", -320539927));
	printf("\n");
	printf("\nOrig: %d\n", printf("\\!/%24.10d\\!/", -320539927));
	printf("\nMine: %d\n", ft_printf("42% 50.2d42", -29892224));
	printf("\n");
	printf("\nOrig: %d\n", printf("42% 50.2d42", -29892224));
	printf("\nMine: %d\n", ft_printf("\\!/%+60.42d\\!/", 0));
	printf("\n");
	printf("\nOrig: %d\n", printf("\\!/%+60.42d\\!/", 0));
	
	printf("\nMine: %d\n", ft_printf("\\!/% -16.13d\\!/", 0));
	printf("\n");
	printf("\nOrig: %d\n", printf("\\!/% -16.13d\\!/", 0));
}
