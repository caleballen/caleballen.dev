#include <SDL.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
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

const SDL_Point SHIP_SHAPE[] = {{0, -12}, {8, 4}, {0, 0}, {-8, 4}, {0, -12}};
const SDL_Point BOI_SHAPE[] = {{-100, -100}, {-100, 100 }, {100, 100}, {100, -100}, {-100, -100}};

#define NUMBER_OF_STARS 1024

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



struct Object {
	float x;
	float y;
	float rotation;
	float velocity_rotation;
	float velocity_x;
	float velocity_y;
	int shape_length;
	const SDL_Point* shape;
};

struct Object player = {
	.x = MAP_WIDTH/2,
	.y = MAP_HEIGHT/2,
	.rotation = 0,
	.velocity_rotation = 0,
	.velocity_x = 0,
	.velocity_y = 0,
	.shape_length = 5,
	.shape = SHIP_SHAPE
};

struct Object boi = {
	.x = MAP_WIDTH/2,
	.y = MAP_HEIGHT/2,
	.velocity_x = 0,
	.velocity_y = 0,
	.rotation = 0,
	.velocity_rotation = 0.1f,
	.shape_length = 5,
	.shape = BOI_SHAPE
};

int numberOfBodies;
struct Object** bodies;

SDL_Point rotatePoint(SDL_Point p, float angle){
	SDL_Point result;

	result.x = p.x*cos(angle) - p.y*sin(angle);
	result.y = p.y*cos(angle) + p.x*sin(angle);

	return result;
}

void drawObject(struct Object* object){
	float centerX = object->x - cameraX;
	float centerY = object->y - cameraY;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Point new_shape[object->shape_length];

	for (int i = 0; i < object->shape_length; i++){
		new_shape[i] = rotatePoint(object->shape[i], object->rotation);
		new_shape[i].x += centerX;
		new_shape[i].y += centerY;
	}

	SDL_RenderDrawLines(renderer, new_shape, object->shape_length);
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

void initialiseBodies(){
	bodies = malloc(sizeof(player)*2);
	bodies[0] = &player;
	bodies[1] = &boi;
	numberOfBodies = 2;
}

void draw(){
	SDL_RenderClear(renderer);
	for (int i = 0; i < 2; i++){
		drawObject(bodies[i]);
	}
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

bool pointsCounterClockwise(SDL_Point A, SDL_Point B, SDL_Point C){
	return (C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x);
}

bool intersect(SDL_Point A, SDL_Point B, SDL_Point C, SDL_Point D){
	return (pointsCounterClockwise(A,C,D) != pointsCounterClockwise(B,C,D)) && (pointsCounterClockwise(A,B,C) != pointsCounterClockwise(A,B,D));
}

bool isTouching(struct Object* o1, struct Object* o2){

	SDL_Point rotated_shape1[o1->shape_length];
	for (int i = 0; i < o1->shape_length; i++){
		rotated_shape1[i] = rotatePoint(o1->shape[i], o1->rotation);
		rotated_shape1[i].x += o1->x;
		rotated_shape1[i].y += o1->y;
	}
	SDL_Point rotated_shape2[o2->shape_length];
	for (int i = 0; i < o2->shape_length; i++){
		rotated_shape2[i] = rotatePoint(o2->shape[i], o2->rotation);
		rotated_shape2[i].x += o2->x;
		rotated_shape2[i].y += o2->y;
	}

	bool intersects = false;
	for (int i = 0; i < o1->shape_length-1; i++){
		for (int j = 0; j < o2->shape_length-1; j++){
			if(intersect(rotated_shape1[i], rotated_shape1[i+1], rotated_shape2[j], rotated_shape2[j+1]))
				intersects = true;
		}
	}
	return intersects;

}

void collisionDetection() {
	printf("touch: %s\n", isTouching(bodies[0], bodies[1]) ? "true" : "false");
}

void updatePhysics(){
	for (int i = 0; i < numberOfBodies; i++){
		bodies[i]->x += bodies[i]->velocity_x;
		bodies[i]->y += bodies[i]->velocity_y;
		bodies[i]->rotation += bodies[i]->velocity_rotation;
	}
	collisionDetection();
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

void initialise(){
	initialiseStars();
	initialiseBodies();
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

	initialise();

	#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(gameLoop, 0, 1);
	#else
	while(1) {
		gameLoop();
	}
	#endif
}