#include "raylib.h"

int main()
{
	const int windowsWidth{ 512 };
	const int windowHeight{ 380 };

	InitWindow(windowsWidth, windowHeight, "Dapper Dasher!");

	// Load the icon image
	Image icon = LoadImage("../Axe_Game/Icon.png"); // Make sure you have an icon.png in your project directory
	SetWindowIcon(icon);
	UnloadImage(icon); // Unload the image after setting the icon (for ram manamgment)

	//Character (Rectangle)
	const int width{ 50 };
	const int height{ 80 };
    int posY{ windowHeight - height };

    int velocity{ 0 };


	const int jumpVelocity{ -22 };
	const int gravity{ 1 };
    bool isInAir{ false };

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(WHITE);


		// check if he is on the ground 
		if (posY >= windowHeight - height) {
			velocity = 0;
			isInAir = false;
		}
		else {
			// so he is in the air (so we add gravity)
			velocity += gravity;
			isInAir = true;
		}
		// check if is jumping key pressed then you will add Jumpvelocity 
		if (IsKeyPressed(KEY_SPACE) && !isInAir) {
			velocity += jumpVelocity;
		}

		// update position
		posY += velocity;

		DrawRectangle(windowsWidth / 2, posY, width, height, BLUE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}