#ifndef FLOYD_VIEW_H
#define FLOYD_VIEW_H

#define FLOYD_VIEW_WINDOW_WIDTH 500
#define FLOYD_VIEW_WINDOW_HEIGHT 500
#define FLOYD_VIEW_WIDTH 50

#include <SDL2/SDL.h>
#include "floyd_warshall.h"

int FLOYD_VIEW_main(GRAFOA *grafoa, IBILBIDEA *ibilbidea);
void FLOYD_VIEW_kotxea(SDL_Renderer* renderer, GRAFOA *grafoa, IBILBIDEA *ibilbidea);
void FLOYD_VIEW_drawBackground(SDL_Renderer *renderer);
void FLOYD_VIEW_circle(Uint32 *pixels, int width, int height, SDL_Point c, int radius, Uint32 color);
int FLOYD_VIEW_distanceSquared(SDL_Point p1, SDL_Point p2);
SDL_Texture *FLOYD_VIEW_createPaths(SDL_Renderer *renderer, GRAFOA *g);
SDL_Texture *FLOYD_VIEW_createForeground(SDL_Renderer *renderer);
SDL_Texture *FLOYD_VIEW_createCar(SDL_Renderer *renderer);

#endif
