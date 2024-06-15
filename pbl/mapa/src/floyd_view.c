#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "simplexnoise1234.h"
#include "floyd.h"
#include "floyd_view.h"

int FLOYD_VIEW_min(int x, int y)
{
	return x < y ? x : y;
}

int FLOYD_VIEW_max(int x, int y)
{
	return x > y ? x : y;
}

int FLOYD_VIEW_main(GRAFOA *grafoa, IBILBIDEA *ibilbidea)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Errorea SDL hasterakoan: %s\n", SDL_GetError());
	} else {
		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
			fprintf(stderr, "Errorea SDL_IMG hasterakoan: %s\n", SDL_GetError());
		} else {
			 SDL_Window* window = SDL_CreateWindow("Kotxea", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, FLOYD_VIEW_WINDOW_WIDTH, FLOYD_VIEW_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
			 if (window == NULL) {
				fprintf(stderr, "Errorea SDL_CreateWindow egiterakoan: %s\n", SDL_GetError());
			 } else {
				SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				if (renderer == NULL) {
					fprintf(stderr, "Errorea SDL_CreateRenderer egiterakoan: %s\n", SDL_GetError());
				} else {
					FLOYD_VIEW_kotxea(renderer, grafoa, ibilbidea);
					SDL_DestroyRenderer(renderer);
				}
				SDL_DestroyWindow(window);
			 }
			IMG_Quit();
		}
		SDL_Quit();
	}
	return 0;
}

void FLOYD_VIEW_kotxea(SDL_Renderer* renderer, GRAFOA *grafoa, IBILBIDEA *ibilbidea)
{
	SDL_Point lehen, orain, gero;
	SDL_Rect dst;
	struct timespec t1;
	float distantzia;
	int i;
	SDL_Texture *foreground = FLOYD_VIEW_createForeground(renderer);
	SDL_Texture *car = FLOYD_VIEW_createCar(renderer);
	SDL_Texture *paths = FLOYD_VIEW_createPaths(renderer, grafoa);
	t1.tv_sec = 0;
	t1.tv_nsec = 1000000L;
	dst.w = FLOYD_VIEW_WIDTH;
	dst.h = FLOYD_VIEW_WIDTH;
	while (ibilbidea && ibilbidea->ptr_hurrengoa) {
		lehen.x = ibilbidea->elementua.x;
		lehen.y = ibilbidea->elementua.y;
		gero.x = ibilbidea->ptr_hurrengoa->elementua.x;
		gero.y = ibilbidea->ptr_hurrengoa->elementua.y;
		distantzia = sqrtf(FLOYD_VIEW_distanceSquared(lehen, gero));
		for (i = 0; i < distantzia; i += 2) {
			orain.x = lehen.x + (gero.x - lehen.x) * i / distantzia;
			orain.y = lehen.y + (gero.y - lehen.y) * i / distantzia;
			dst.x = orain.x - FLOYD_VIEW_WIDTH / 2;
			dst.y = orain.y - FLOYD_VIEW_WIDTH / 2;
			FLOYD_VIEW_drawBackground(renderer);
			SDL_RenderCopy(renderer, paths, NULL, NULL);
			SDL_RenderCopy(renderer, foreground, NULL, NULL);
			SDL_RenderCopy(renderer, car, NULL, &dst);
			SDL_RenderPresent(renderer);
			nanosleep(&t1, NULL);
		}
		ibilbidea = ibilbidea->ptr_hurrengoa;
	}
	sleep(4);
	SDL_DestroyTexture(foreground);
	SDL_DestroyTexture(paths);
	SDL_DestroyTexture(car);
}

void FLOYD_VIEW_drawBackground(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xA0, 0xC0, 0x40, 0xFF);
	SDL_RenderClear(renderer);
}

void FLOYD_VIEW_circle(Uint32 *pixels, int width, int height, SDL_Point c, int radius, Uint32 color)
{
	SDL_Point u = { radius - 1, 0 };
	SDL_Point v;
	SDL_Point du = { 1, 1 };
	int err = du.x - (radius << 1);

	while (u.x >= u.y)
	{
		v.x = c.x + u.x;
		for (v.y = c.y - u.y; v.y < c.y + u.y; ++v.y) {
			if (v.x >= 0 && v.y >= 0 && v.x < width && v.y < height) {
				pixels[v.x + v.y * width] = color;
			}
		}
		v.x = c.x + u.y;
		for (v.y = c.y - u.x; v.y < c.y + u.x; ++v.y) {
			if (v.x >= 0 && v.y >= 0 && v.x < width && v.y < height) {
				pixels[v.x + v.y * width] = color;
			}
		}
		v.x = c.x - u.x;
		for (v.y = c.y - u.y; v.y < c.y + u.y; ++v.y) {
			if (v.x >= 0 && v.y >= 0 && v.x < width && v.y < height) {
				pixels[v.x + v.y * width] = color;
			}
		}
		v.x = c.x - u.y;
		for (v.y = c.y - u.x; v.y < c.y + u.x; ++v.y) {
			if (v.x >= 0 && v.y >= 0 && v.x < width && v.y < height) {
				pixels[v.x + v.y * width] = color;
			}
		}

		if (err <= 0)
		{
			u.y++;
			err += du.y;
			du.y += 2;
		}

		if (err > 0)
		{
			u.x--;
			du.x += 2;
			err += du.x - (radius << 1);
		}
	}

}

int FLOYD_VIEW_distanceSquared(SDL_Point p1, SDL_Point p2)
{
	SDL_Point v = { p2.x - p1.x, p2.y - p1.y };
	return v.x * v.x + v.y * v.y;
}

void FLOYD_VIEW_rectangle(Uint32 *pixels, SDL_Point center, SDL_Point otherCenter, int width, Uint32 color)
{
	int nSq1, nSq2, nSq3, nSq4, nSq5, xMin, xMax, yMin, yMax;
	SDL_Point tmp, vector = { otherCenter.x - center.x, otherCenter.y - center.y };
	SDL_Point vPerp = { vector.y, -vector.x };
	float vPerpModulus = sqrtf(vPerp.x * vPerp.x + vPerp.y * vPerp.y);
	SDL_Point vPerpWidth = { vPerp.x / vPerpModulus / 2.0f * width, vPerp.y / vPerpModulus / 2.0f * width };
	SDL_Point erpinak[4] = {
		{ center.x + vPerpWidth.x, center.y + vPerpWidth.y },
		{ center.x - vPerpWidth.x, center.y - vPerpWidth.y },
		{ otherCenter.x - vPerpWidth.x, otherCenter.y - vPerpWidth.y },
		{ otherCenter.x + vPerpWidth.x, otherCenter.y + vPerpWidth.y },
	};
	nSq1 = FLOYD_VIEW_distanceSquared(erpinak[0], erpinak[1]);
	nSq2 = FLOYD_VIEW_distanceSquared(erpinak[0], erpinak[3]);
	xMin = FLOYD_VIEW_min(FLOYD_VIEW_min(erpinak[0].x, erpinak[1].x), FLOYD_VIEW_min(erpinak[2].x, erpinak[3].x));
	yMin = FLOYD_VIEW_min(FLOYD_VIEW_min(erpinak[0].y, erpinak[1].y), FLOYD_VIEW_min(erpinak[2].y, erpinak[3].y));
	xMax = FLOYD_VIEW_max(FLOYD_VIEW_max(erpinak[0].x, erpinak[1].x), FLOYD_VIEW_max(erpinak[2].x, erpinak[3].x));
	yMax = FLOYD_VIEW_max(FLOYD_VIEW_max(erpinak[0].y, erpinak[1].y), FLOYD_VIEW_max(erpinak[2].y, erpinak[3].y));
	for (tmp.x = xMin; tmp.x < xMax; ++tmp.x) {
		for (tmp.y = yMin; tmp.y < yMax; ++tmp.y) {
			nSq3 = FLOYD_VIEW_distanceSquared(erpinak[0], tmp);
			nSq4 = FLOYD_VIEW_distanceSquared(erpinak[1], tmp);
			nSq5 = FLOYD_VIEW_distanceSquared(erpinak[3], tmp);
			if (abs(nSq3 - nSq4) < nSq1 && abs(nSq3 - nSq5) < nSq2) {
				if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < FLOYD_VIEW_WINDOW_WIDTH && tmp.y < FLOYD_VIEW_WINDOW_HEIGHT) {
					pixels[tmp.x + tmp.y * FLOYD_VIEW_WINDOW_WIDTH] = color;
				}
			}
		}
	}


}

SDL_Texture *FLOYD_VIEW_createPaths(SDL_Renderer *renderer, GRAFOA *g)
{
	SDL_Point center, otherCenter;
	SDL_Texture *ret = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, FLOYD_VIEW_WINDOW_WIDTH, FLOYD_VIEW_WINDOW_HEIGHT);
	SDL_SetTextureBlendMode(ret, SDL_BLENDMODE_BLEND);

	if (ret) {
		Uint32 *pixels = calloc(FLOYD_VIEW_WINDOW_WIDTH * FLOYD_VIEW_WINDOW_HEIGHT, sizeof *pixels);
		if (pixels) {
			while (g) {
				center.x = g->elementua.x;
				center.y = g->elementua.y;
				FLOYD_VIEW_circle(pixels, FLOYD_VIEW_WINDOW_WIDTH, FLOYD_VIEW_WINDOW_HEIGHT, center, FLOYD_VIEW_WIDTH / 2, 0xFF303840);
				GRAFOA_ERTZA_NODOA *ertzak = g->elementua.ertzak;
				while (ertzak) {
					otherCenter.x = ertzak->elementua.nora->x;
					otherCenter.y = ertzak->elementua.nora->y;
					FLOYD_VIEW_rectangle(pixels, center, otherCenter, FLOYD_VIEW_WIDTH, 0xFF303840);
					ertzak = ertzak->ptr_hurrengoa;
				}
				g = g->ptr_hurrengoa;
			}
			SDL_UpdateTexture(ret, NULL, pixels, FLOYD_VIEW_WINDOW_WIDTH * sizeof *pixels);
			free(pixels);
		}
	}
	return ret;
}

SDL_Texture *FLOYD_VIEW_createForeground(SDL_Renderer *renderer)
{
	int i, j;
	float factor = 0.01f;
	float noiseValue;
	SDL_Texture *ret = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, FLOYD_VIEW_WINDOW_WIDTH, FLOYD_VIEW_WINDOW_HEIGHT);
	SDL_SetTextureBlendMode(ret, SDL_BLENDMODE_BLEND);

	if (ret) {
		Uint32 *pixels = malloc(FLOYD_VIEW_WINDOW_WIDTH * FLOYD_VIEW_WINDOW_HEIGHT * sizeof *pixels);

		if (pixels) {
			for (i = 0; i < FLOYD_VIEW_WINDOW_WIDTH; ++i) {
				for (j = 0; j < FLOYD_VIEW_WINDOW_HEIGHT; ++j) {
					noiseValue = snoise2(factor * i, factor * j);
					pixels[i + j * FLOYD_VIEW_WINDOW_WIDTH] = ((0x30 + (int) (noiseValue * 0x20)) << 24) | 0xC0C0C0;
				}
			}
			SDL_UpdateTexture(ret, NULL, pixels, FLOYD_VIEW_WINDOW_WIDTH * sizeof *pixels);
			free(pixels);
		}
	}
	return ret;
}

SDL_Texture *FLOYD_VIEW_createCar(SDL_Renderer *renderer)
{
	SDL_Point center = { FLOYD_VIEW_WIDTH / 2, FLOYD_VIEW_WIDTH / 2 };
	SDL_Texture *ret = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, FLOYD_VIEW_WIDTH, FLOYD_VIEW_WIDTH);
	SDL_SetTextureBlendMode(ret, SDL_BLENDMODE_BLEND);
	if (ret) {
		Uint32 *pixels = calloc(FLOYD_VIEW_WIDTH * FLOYD_VIEW_WIDTH, sizeof *pixels);

		if (pixels) {
			FLOYD_VIEW_circle(pixels, FLOYD_VIEW_WIDTH, FLOYD_VIEW_WIDTH, center, FLOYD_VIEW_WIDTH / 3, 0xFFFFFFFF);
			SDL_UpdateTexture(ret, NULL, pixels, FLOYD_VIEW_WIDTH * sizeof *pixels);
			free(pixels);
		}
	}
	return ret;
}
