/*
** EPITECH PROJECT, 2017
** hunter
** File description:
** norm'd
*/

#include "my.h"

void	is_mouse(sf_list *nein)
{
	sfVector2i veci;
	if (nein->event.type == sfEvtMouseButtonPressed)
	{
		veci = sfMouse_getPositionRenderWindow(nein->window);
		if (veci.x >= sfSprite_getPosition(nein->sprite).x &&
		    veci.x <= sfSprite_getPosition(nein->sprite).x +110
		    &&   veci.y >= sfSprite_getPosition(nein->sprite).y &&
		    veci.y <= sfSprite_getPosition(nein->sprite).y + 110) {
				sfMusic_play(nein->shoot);
				nein->scale.x = -110;
				nein->scale.y = rand() % 500;
		}
		else
			nein->nb = nein->nb - 1;
	}
}
int	is_keyormouse(sf_list *nein)
{
	if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
		nein->nb = 3;
	if (nein->event.type == sfEvtClosed) {
		sfMusic_destroy(nein->music);
		sfMusic_destroy(nein->shoot);
		sfRenderWindow_close(nein->window);
		return (1);
	}
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	{
		sfMusic_destroy(nein->music);
		sfMusic_destroy(nein->shoot);
		sfRenderWindow_close(nein->window);
		return (1);
	}
	if (nein->nb > 0)
		is_mouse(nein);
	return (0);
}

void	clock_rect(sf_list *nein)
{
	sfRenderWindow_clear(nein->window, sfBlack);
	sfRenderWindow_drawSprite(nein->window, nein->sprite2, NULL);
	if (nein->slow >= 0.4) {
		if (nein->rect.left == 0 || nein->rect.left == 110)
			nein->rect.left = nein->rect.left + 110;
		else if (nein->rect.left == 220)
			nein->rect.left = 0;
		sfSprite_setTexture(nein->sprite, nein->texture, sfTrue);
		sfSprite_setTextureRect(nein->sprite, nein->rect);
		sfRenderWindow_drawSprite(nein->window, nein->sprite, NULL);
		sfClock_restart(nein->Clock);
	}
}

void	over_aff(sf_list *nein)
{
	if (nein->nb > 0)
		sfRenderWindow_drawSprite(nein->window, nein->sprite, NULL);
	nein->scale.x = nein->scale.x + 15;
	if (nein->scale.x >= 1280)
	{
		sfRenderWindow_drawSprite(nein->window, nein->sprite, NULL);
		nein->scale.x = -110;
	}
	sfSprite_setPosition(nein->sprite, nein->scale);
	is_done(nein);
	sfRenderWindow_display(nein->window);
}
int	main(int ac, char **av)
{
	sf_list		nein;

	nein.nb = 3;
	if (ac >= 2 && check_flags(ac, av) == 84)
		return (84);
	if (ac == 1) {
		my_ini(&nein);
		while (sfRenderWindow_isOpen(nein.window))
		{
			before_pollevent(&nein);
			while (sfRenderWindow_pollEvent(nein.window, &nein.event))
			{
				if (is_keyormouse(&nein) == 1)
					return (0);
			}
			clock_rect(&nein);
			over_aff(&nein);
		}
		my_destroy(&nein);
	}
}
