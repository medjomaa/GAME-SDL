#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

struct enemy
{
SDL_Rect position;
SDL_Surface *imgR[4]; 
SDL_Surface *imgL[4];
int direction;


};
typedef struct enemy enemy;

void init(enemy *e);
void afficher(enemy e,SDL_Surface *ecran, SDL_Surface *fond,SDL_Rect posfond,int *i);
void move(enemy *e);
void destruct(enemy *e);





#endif // ENEMY_H_INCLUDED
