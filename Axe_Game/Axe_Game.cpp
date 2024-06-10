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
	int circle_radius{ 25 };
	// Circle Edges
	int l_circle_x{ circle_x - circle_radius };
	int r_circle_x{ circle_x + circle_radius };
	int u_circle_y{ circle_y - circle_radius };
	int b_circle_y{ circle_y + circle_radius };

	// Axe Cordinate
	int axe_x{ 400 };
	int axe_y{ 0 };
	int axe_length{ 50 };
	int axe_direction{ 10 };
	// Axe Edges
	int l_Axe_x{ axe_x };
	int r_Axe_x{ axe_x + axe_length };
	int u_Axe_y{ axe_y };
	int b_Axe_y{ axe_y + axe_length };
	bool collision_with_axe{ false };

	// Update loop
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(WHITE);

		if (collision_with_axe) {
			DrawText("Game Over!", 400, 200, 20, RED);
		}
		else
		{
			//Begin Game logic
			DrawCircle(circle_x, circle_y, circle_radius, BLUE);
			DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
			//Input AND moving Circle Left and Right
			if (IsKeyDown(KEY_D) && circle_x < width) {
				circle_x += 10;
			}
			if (IsKeyDown(KEY_A) && circle_x > 0) {
				circle_x -= 10;
			}
			// Axe falling down
			axe_y += axe_direction;
			if (axe_y > height || axe_y < 0)
			{
				axe_direction = -axe_direction;
			}
			//End Game logic
		}

		EndDrawing();
	}
	return 0;
}