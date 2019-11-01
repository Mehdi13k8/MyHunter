/*
** EPITECH PROJECT, 2017
** hunter
** File description:
** .h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>

typedef struct s_list
{
	float		x,b;
	sfVector2f	scale;
	sfVideoMode   mode;
	sfRenderWindow*	window;
	sfTexture*	texture;
	sfTexture*	texture2;
	sfTexture*	gameover;
	sfSprite*	sprite;
	sfSprite*	gameovere;
	sfSprite*	sprite2;
	sfIntRect	rect;
	sfEvent		event;
	sfTime		time;
	sfClock*	Clock;
	float		slow;
	sfMusic*	music;
	sfMusic*	shoot;
	int		nb;  
}sf_list;

int	check_flags(int ac, char **av);
void    nani(sf_list *nein);
void	my_ini(sf_list *nein);
void    my_destroy(sf_list *nein);
void    is_done(sf_list *nein);
void    before_pollevent(sf_list *nein);
int	main(int ac, char **av);
void	clock_rect(sf_list *nein);
void	over_aff(sf_list *nein);
int	is_keyormouse(sf_list *nein);
void    is_mouse(sf_list *nein);
void    before_pollevent(sf_list *nein);

# endif /* MY_H_ */
