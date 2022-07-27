#ifndef _SCREENH_

#define _SCREENH_

#include <SDL.h>

struct Screen;

typedef void (*ScreenDrawF)(struct Screen *screen);
typedef void (*ScreenKeyPressedF)(struct Screen *screen, int sdlscancode);
typedef void (*ScreenKeyReleasedF)(struct Screen *screen, int sdlscancode);
typedef void (*ScreenMousePressedF)(struct Screen *screen, int button);
typedef void (*ScreenMouseReleasedF)(struct Screen *screen, int button);
typedef void (*ScreenMouseMovedF)(struct Screen *screen, int dx, int dy);

struct Screen {
	int Width;
	int Height;
	void *Context1;
	void *Context2;
	char *Title;
	SDL_Texture *Texture;

	ScreenDrawF Draw;
	ScreenKeyPressedF KeyPressed;
	ScreenKeyReleasedF KeyReleased;
	ScreenMousePressedF MousePressed;
	ScreenMouseReleasedF MouseReleased;
	ScreenMouseMovedF MouseMoved;
};

#define MAXSCREENS 16

extern struct Screen Screens[MAXSCREENS];

void ScreenInit();

void ScreenDraw();

void ScreenNext();
void ScreenPrev();

int ScreenProcessEvents();

struct SDL_Texture *ScreenGetTexture(struct Screen *screen);

struct Screen *ScreenCreate(int w, int h, char *title,
							ScreenDrawF draw,
							ScreenKeyPressedF keypressed,
							ScreenKeyReleasedF keyreleased,
							ScreenMousePressedF mousepressed,
							ScreenMouseReleasedF mousereleased,
							ScreenMouseMovedF mousemoved);

#endif