#include "raylib.h"

int main()
{
	int height = 200;
	int width = 350;

	InitWindow(width, height, "Khalil");

	// Load the icon image
	Image icon = LoadImage("Icon.png"); // Make sure you have an icon.png in your project directory
	SetWindowIcon(icon);
	UnloadImage(icon); // Unload the image after setting the icon

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(WHITE);
		DrawCircle(width / 2, height / 2, 25, BLUE);
		EndDrawing();
	}
	return 0;
}