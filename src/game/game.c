#include <SDL.h>
#include <emscripten.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

SDL_Window* window;
SDL_Renderer* renderer;

const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;

const int MAP_WIDTH = 5120;
const int MAP_HEIGHT = 5120;

const float THRUST = 0.1;
const float ROTATION_THRUST = 0.001;

const int NUMBER_OF_STARS = 1024;

float cameraX;
float cameraY;
int cameraWidth = 512;
int cameraHeight = 512;

struct Star {
	int x;
	int y;
	int z;
};

struct Star stars[NUMBER_OF_STARS];

struct Point {
	float x;
	float y;
};

struct Object {
	float x;
	float y;
	float rotation;
	float velocity_rotation;
	float velocity_x;
	float velocity_y;
};

struct Object player = {
	.x = MAP_WIDTH/2,
	.y = MAP_HEIGHT/2,
	.rotation = 0,
	.velocity_rotation = 0,
	.velocity_x = 0,
	.velocity_y = 0
};

struct Point rotatePoint(struct Point p, float angle){
	struct Point result;

	result.x = p.x*cos(angle) - p.y*sin(angle);
	result.y = p.y*cos(angle) + p.x*sin(angle);

	return result;
}

void drawShip(){
	float centerX = player.x - cameraX;
	float centerY = player.y - cameraY;

	int PLAYER_WIDTH = 16;

	struct Point top = {0, -PLAYER_WIDTH*0.75};
	struct Point bottom = {0,0};
	struct Point left = {-PLAYER_WIDTH/2, PLAYER_WIDTH/4};
	struct Point right = {PLAYER_WIDTH/2, PLAYER_WIDTH/4};

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	top = rotatePoint(top, player.rotation);
	bottom = rotatePoint(bottom, player.rotation);
	left = rotatePoint(left, player.rotation);
	right = rotatePoint(right, player.rotation);

	SDL_RenderDrawLine(renderer, centerX+left.x, centerY+left.y, centerX+top.x, centerY+top.y);
	SDL_RenderDrawLine(renderer, centerX+right.x, centerY+right.y, centerX + top.x, centerY+top.y);
	SDL_RenderDrawLine(renderer, centerX+left.x, centerY+left.y, centerX + bottom.x, centerY + bottom.y);
	SDL_RenderDrawLine(renderer, centerX+right.x, centerY+right.y, centerX + bottom.x, centerY + bottom.y);
}

void drawStars(){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	// TODO: Culling
	for(int i = 0; i < NUMBER_OF_STARS; i++){
		SDL_Rect rect = {stars[i].x - cameraX, stars[i].y - cameraY, stars[i].z, stars[i].z};
		SDL_RenderFillRect(renderer, &rect);
	}
}

void initialiseStars(){
	for(int i = 0; i < NUMBER_OF_STARS; i++){
		stars[i].x = rand() % MAP_WIDTH;
		stars[i].y = rand() % MAP_HEIGHT;
		stars[i].z = rand() % 3;
	}
}

void draw(){
	SDL_RenderClear(renderer);
	drawShip();
	drawStars();
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderPresent(renderer);
}

void updatePlayerVelocity(bool up, bool down, bool left, bool right) {
	if (up){
		player.velocity_y -= THRUST*cos(player.rotation);
		player.velocity_x += THRUST*sin(player.rotation);
	}
	if (down){
		player.velocity_y += THRUST*cos(player.rotation);
		player.velocity_x -= THRUST*sin(player.rotation);
	}
	if(left){
		player.velocity_rotation -= ROTATION_THRUST;
	}
	if(right){
		player.velocity_rotation += ROTATION_THRUST;
	}
}

void handleKeyboardInput(){
	bool up = false, down = false, left = false, right = false;
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);	
	if(currentKeyStates[SDL_SCANCODE_UP])
		up=true;
	if(currentKeyStates[SDL_SCANCODE_DOWN])
		down = true;
	if(currentKeyStates[SDL_SCANCODE_LEFT])
		left = true;
	if(currentKeyStates[SDL_SCANCODE_RIGHT])
		right = true;

	updatePlayerVelocity(up, down, left, right);
}

void updatePhysics(){
	player.x += player.velocity_x;
	player.y += player.velocity_y;
	player.rotation += player.velocity_rotation;
}

void updateCamera(){
	cameraX = player.x - SCREEN_WIDTH/2;
	cameraY = player.y - SCREEN_HEIGHT/2;

	if(cameraX < 0){
		cameraX = 0;
	}
	if(cameraY < 0){
		cameraY = 0;
	}
	if( cameraX > MAP_WIDTH - cameraWidth){
		cameraX = MAP_WIDTH;
	}
	if (cameraX > MAP_HEIGHT - cameraHeight){
		cameraY = MAP_HEIGHT;
	}
}

void gameLoop(){
	handleKeyboardInput();
	updatePhysics();
	updateCamera();
	draw();
}

int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

	initialiseStars();

	emscripten_set_main_loop(gameLoop, 0, 1);
}