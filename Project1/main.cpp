#include <iostream>
#include <raylib.h>
#include "gamemanager.hpp"
#include "point.hpp"
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main() {
	Core::GameManager gameManager;
	SetTargetFPS(144);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Curves"); 
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if(IsKeyPressed(KEY_A)) {
			gameManager.CreatePoint();
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			gameManager.MovePoint();
		}
		if (IsKeyPressed(KEY_C)) {
			gameManager.DeleteAllPoints();
		}
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			for (int i = 0; i < gameManager.pvec.size(); i++) {
				gameManager.pvec[i].held = false;
			}
		}
		gameManager.DrawLerp();
		gameManager.DrawLines();
		gameManager.DrawPoints();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}