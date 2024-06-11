#include "raylib.h"

int main()
{
	int width = 350;
	int height = 200;
	
	InitWindow(width, height, "Dapper_Dasher");

	// Load the icon image
	Image icon = LoadImage("../Axe_Game/Icon.png"); // Make sure you have an icon.png in your project directory
	SetWindowIcon(icon);
	UnloadImage(icon); // Unload the image after setting the icon

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(WHITE);
		EndDrawing();
	}

	return 0;
}