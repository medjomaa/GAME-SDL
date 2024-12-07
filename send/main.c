#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enemy.h"
 
 
int main(int argc, char *argv[])
{
SDL_Surface *ecran = NULL, *fond = NULL ;
SDL_Rect posfond;
posfond.x=0;
posfond.y=0;


enemy e;


init(&e);

SDL_Init(SDL_INIT_EVERYTHING);
SDL_Event event;

	

ecran = SDL_SetVideoMode(900,673, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);    
SDL_WM_SetCaption("Mouvement enemi", NULL);
fond=IMG_Load("niveau11.png");
	

   
   

int continuer=1;
int i=0;
	while(continuer)
{
 SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
move(&e);
afficher(e,ecran,fond,posfond,&i);
if(e.position.x==200)
{
e.direction=2;
}
if(e.position.x==10)
{
e.direction=1;
}



   
}//endwhile
    




destruct(&e);
SDL_FreeSurface(fond);
SDL_FreeSurface(ecran);
    SDL_Quit();

    return EXIT_SUCCESS;
}











 
