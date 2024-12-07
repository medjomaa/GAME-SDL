#include "enemy.h"

void init(enemy *e)
{
e->imgR[0]=IMG_Load("enemiepos1r.png");
e->imgR[1]=IMG_Load("enemiepos2r.png");
e->imgR[2]=IMG_Load("enemiepos3r.png");
e->imgR[3]=IMG_Load("enemiepos4r.png");
e->imgL[0]=IMG_Load("enemiepos1l.png");
e->imgL[1]=IMG_Load("enemiepos2l.png");
e->imgL[2]=IMG_Load("enemiepos3l.png");
e->imgL[3]=IMG_Load("enemiepos4l.png");

e->position.x=10;
e->position.y=420;

e->direction=1;

}

void afficher(enemy e,SDL_Surface *ecran, SDL_Surface *fond,SDL_Rect posfond,int *i)
{
SDL_Surface *img=NULL;
if(e.direction==1)
{
SDL_BlitSurface(fond,NULL,ecran,&posfond);
SDL_BlitSurface(e.imgR[*i],NULL,ecran,&e.position);
SDL_Flip(ecran);
SDL_Delay(150);
(*i)++;
if(*i==3)
{
*i=0;
}

}
else
{
SDL_BlitSurface(fond,NULL,ecran,&posfond);
SDL_BlitSurface(e.imgL[*i],NULL,ecran,&e.position);
SDL_Flip(ecran);
SDL_Delay(150);
(*i)++;
if(*i==3)
{
*i=0;
}

}
}
	


void move(enemy *e)
{
if(e->direction==1)
{
e->position.x=e->position.x+5;
}
else
{
e->position.x=e->position.x-5;
}

}



void destruct(enemy *e)
{
for(int i=0;i<3;i++)
{
SDL_FreeSurface(e->imgR[i]);
SDL_FreeSurface(e->imgL[i]);
}
}
