#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[])
{
    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;
    SDL_Init(SDL_INIT_AUDIO);
    hello = SDL_LoadBMP("hello.bmp");
    SDL_BlitSurface(hello,NULL,screen,NULL);
    SDL_Delay(2000);
    SDL_Quit();
    return 0;
}