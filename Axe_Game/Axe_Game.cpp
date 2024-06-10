#include "raylib.h"

int main()
{
	//Window dimension
	int height = 200;
	int width = 350;

	InitWindow(width, height, "Khalil");

	// Load the icon image
	Image icon = LoadImage("Icon.png"); // Make sure you have an icon.png in your project directory
	SetWindowIcon(icon);
	UnloadImage(icon); // Unload the image after setting the icon

	SetTargetFPS(60);

	// Circle dimension
	int circle_x{ width / 2 };
	int circle_y{ height / 2 };
	int rad{ 25 };

	// Update loop
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(WHITE);

		//Game logic
		DrawCircle(circle_x, circle_y, rad, BLUE);
		if (IsKeyDown(KEY_D)) {
			circle_x += 10;
		}
		if (IsKeyDown(KEY_A)) {
			circle_x -= 10;
		}

		EndDrawing();
	}
	return 0;
}