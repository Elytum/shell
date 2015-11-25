#include <stdio.h>

void	add_to_tab(int tab[8], char c)
{
	printf("tab cell: %i, position in cell: %i\n", c % 8, c / 32);
	tab[c % 8] |= c / 32;
}

int		main(void)
{
	int		tab[8];

	add_to_tab(tab, 100);
	return (0);
}