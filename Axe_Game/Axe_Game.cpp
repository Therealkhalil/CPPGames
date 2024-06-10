#include "raylib.h"

int main()
{
	//Window dimension
	int height = 450;
	int width = 800;

	InitWindow(width, height, "Khalil");

	// Load the icon image
	Image icon = LoadImage("Icon.png"); // Make sure you have an icon.png in your project directory
	SetWindowIcon(icon);
	UnloadImage(icon); // Unload the image after setting the icon

	SetTargetFPS(60);

	// Circle dimension
	int circle_x{ width / 2 };
	int circle_y{ height / 2 };
	int circle_rad{ 25 };

	// Axe Cordinate
	int axe_x{ 400 };
	int axe_y{ 0 };
	int axe_size_x{ 50 };
	int axe_size_y{ 50 };
	// Update loop
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(WHITE);

		//Game logic
		DrawCircle(circle_x, circle_y, circle_rad, BLUE);
		DrawRectangle(axe_x, axe_y, axe_size_x, axe_size_y, RED);

		if (IsKeyDown(KEY_D) && circle_x < width) {
			circle_x += 10;
		}
		if (IsKeyDown(KEY_A) && circle_x > 0) {
			circle_x -= 10;
		}
		// axe falling down
		if(axe_y < height-50)
		axe_y += 10;
		EndDrawing();
	}
	return 0;
}