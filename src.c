/*
** EPITECH PROJECT, 2017
** src_hunter
** File description:
** mehdi
*/

# include "my.h"

void	nani(sf_list *nein)
{
	nein->gameovere = sfSprite_create();
	sfSprite_setTexture(nein->gameovere, nein->gameover, sfTrue);
	sfSprite_setTexture(nein->sprite2, nein->texture2, sfTrue);
	sfRenderWindow_setFramerateLimit(nein->window, 60);
	nein->music = sfMusic_createFromFile("Duke_Nukem.ogg");
	nein->shoot = sfMusic_createFromFile("Shooter.ogg");
	sfMusic_play(nein->music);
	sfMusic_setLoop(nein->music, sfTrue);
}
void	my_ini(sf_list *nein)
{
	char *a = "Touch my ducks";
	sfVideoMode mod = {1280, 780, 32};

	nein->window = sfRenderWindow_create(mod, a, sfResize |sfClose, NULL);
	nein->Clock = sfClock_create();
	nein->rect.left = 0;
	nein->rect.top = 0;
	nein->rect.width = 110;
	nein->rect.height = 90;
	nein->texture = sfTexture_createFromFile("spritesheet.png", NULL);
	nein->texture2 = sfTexture_createFromFile("background.png", NULL);
	nein->gameover = sfTexture_createFromFile("death4.png", NULL);
	nein->sprite = sfSprite_create();
	nein->sprite2 = sfSprite_create();
	nani(nein);
}

void	my_destroy(sf_list *nein)
{
	sfSprite_destroy(nein->sprite);
	sfSprite_destroy(nein->sprite2);
	sfSprite_destroy(nein->gameovere);
	sfMusic_destroy(nein->music);
	sfTexture_destroy(nein->texture);
	sfTexture_destroy(nein->gameover);
	sfTexture_destroy(nein->texture2);
	sfClock_destroy(nein->Clock);
	sfRenderWindow_destroy(nein->window);
}
void	is_done(sf_list *nein)
{
	if (nein->nb == 0) {
		sfRenderWindow_clear(nein->window, sfBlack);
		sfRenderWindow_drawSprite(nein->window, nein->gameovere, NULL);
	}
}

void	before_pollevent(sf_list *nein)
{
	sfVector2f veca;

	veca.x = -300;
	veca.y = -100;
	sfSprite_setPosition(nein->gameovere, veca);
	sfRenderWindow_clear(nein->window, sfBlack);
	sfRenderWindow_drawSprite(nein->window, nein->gameovere, NULL);
	nein->time = sfClock_getElapsedTime(nein->Clock);
	nein->slow = nein->time.microseconds / 1000000.0;
}
