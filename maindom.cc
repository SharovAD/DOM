
#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>
#include <cmath>

#include <SDL2/SDL.h>

constexpr double Pi = acos(-1.);

#ifdef _WIN32
# include <SDL2/SDL_main.h>
#endif

constexpr int WIDTH = 800, HEIGHT = 600;

int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	auto win = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
						"DOM",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT,
						SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);
	if (win == nullptr) {
		std::cerr << "При создании окна произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (ren == nullptr) {
		std::cerr << "При создании renderer-а произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Event event;

	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) return 0;
		}

		SDL_SetRenderDrawColor(ren.get(), 0, 20, 44, 255);
		SDL_RenderClear(ren.get());
		SDL_SetRenderDrawColor(ren.get(), 0, 255, 255, 255);
		SDL_RenderDrawLine(ren.get(), 200, 200, 200, 500);//дом
		SDL_RenderDrawLine(ren.get(), 200, 500, 500, 500);
		SDL_RenderDrawLine(ren.get(), 500, 500, 500, 200);
		SDL_RenderDrawLine(ren.get(), 500, 200, 200, 200);
		SDL_RenderDrawLine(ren.get(), 200, 200, 350, 50);//крыша
		SDL_RenderDrawLine(ren.get(), 500, 200, 350, 50);
		SDL_RenderDrawLine(ren.get(), 250, 150, 250, 50);//труба
		SDL_RenderDrawLine(ren.get(), 270, 130, 270, 50);
		SDL_RenderDrawLine(ren.get(), 250, 50, 270, 50);
		SDL_RenderDrawLine(ren.get(), 300, 300, 300, 400);//окно
		SDL_RenderDrawLine(ren.get(), 300, 400, 400, 400);
		SDL_RenderDrawLine(ren.get(), 400, 400, 400, 300);
		SDL_RenderDrawLine(ren.get(), 400, 300, 300, 300);
		SDL_RenderDrawLine(ren.get(), 500, 200, 700, 150);//профиль
		SDL_RenderDrawLine(ren.get(), 500, 500, 700, 450);
		SDL_RenderDrawLine(ren.get(), 350, 50, 550, 0 );
		SDL_RenderDrawLine(ren.get(), 700, 150, 700, 450);
		SDL_RenderDrawLine(ren.get(), 550, 0, 700, 150);
		SDL_RenderDrawLine(ren.get(), 550, 488, 550, 280);//дверь
		SDL_RenderDrawLine(ren.get(), 650, 464, 650, 255);
		SDL_RenderDrawLine(ren.get(), 550, 280, 650, 255);
		SDL_RenderPresent(ren.get());
	}


	return 0;
}

