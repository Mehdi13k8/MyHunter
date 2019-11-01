/*
** EPITECH PROJECT, 2017
** hunter
** File description:
** mehdi
*/

# include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	int	i = -1;

	while (str[++i] != '\0')
		my_putchar(str[i]);
}
int	check_flags(int ac, char **av)
{
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
	{
		my_putstr("You have to aim the ducks in the head if you are skill'd\n");
		my_putstr("You have 3 lives, each shot out of target make u lose one\n");
		my_putstr("If you game over you can replay by push R key\n");
		my_putstr("To close the game press escape ;) have fun...\n");
		return (0);
	}
	else
		return (84);
	return (3);
}
