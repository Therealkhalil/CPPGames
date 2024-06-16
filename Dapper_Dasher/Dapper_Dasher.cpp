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
	/*const int width{ 50 };
	const int height{ 80 };
	int posY{ windowHeight - height };*/

	// Physics
	int velocity{ 0 };
	const int jumpVelocity{ -600 }; // jumpvel : pixel per second
	const int gravity{ 1'000 }; // gravity : (pixel/sec) per second
	bool isInAir{ false };
	//for nebula velocity
	int velocityNebula{ -200 };

	//Enemy Nebula (Sprite)
	Texture2D nebula = LoadTexture("../Dapper_Dasher/textures/12_nebula_spritesheet.png");
	Rectangle nebulaRect;
	Vector2 nebulaPos;

	nebulaRect.x = 0;
	nebulaRect.y = 0;
	nebulaRect.width = nebula.width / 8;
	nebulaRect.height = nebula.height / 8;

	nebulaPos.x = windowsWidth;
	nebulaPos.y = windowHeight - nebulaRect.height;

	//Character Scrafy (Sprite)
	Texture2D scarfy = LoadTexture("../Dapper_Dasher/textures/scarfy.png");
	Rectangle scarfyRect;
	Vector2 scarfyPos;

	scarfyRect.x = 0;
	scarfyRect.y = 0;
	scarfyRect.width = scarfy.width / 6;
	scarfyRect.height = scarfy.height;

	scarfyPos.x = windowsWidth / 2 - scarfyRect.width / 2;
	scarfyPos.y = windowHeight - scarfyRect.height;

	//Animation Frame Setup
	const float updateTime{ 1.0 / 12.0 };
	const float updateTimeNebula{ 1.0 / 12.0 };

	//for scarfy
	int frame{};
	float runningTime{};

	//for nebula
	int frameNebula{};
	float runningTimeNebula{};





	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		//Delta time init (time since last frame)
		const float dT{ GetFrameTime() };

		BeginDrawing();
		ClearBackground(WHITE);


		// check if he is on the ground 
		if (scarfyPos.y >= windowHeight - scarfyRect.height) {
			velocity = 0;
			isInAir = false;
		}
		else {
			// so he is in the air (so we add gravity)
			velocity += gravity * dT;
			isInAir = true;
		}
		// check if is jumping key pressed then you will add Jumpvelocity 
		if (IsKeyPressed(KEY_SPACE) && !isInAir) {
			velocity += jumpVelocity;
		}

		// Update position
		scarfyPos.y += velocity * dT;


		//nebula update position
		nebulaPos.x += velocityNebula * dT;

		// Animation system
		// Scarfy
		if (!isInAir)
		{
			runningTime += dT;
			if (runningTime >= updateTime) {
				runningTime = 0;
				scarfyRect.x = frame * scarfyRect.width;
				frame++;
				if (frame > 5) {
					frame = 0;
				}
			}
		}

		//Nebula
		runningTimeNebula += dT;
		if (runningTimeNebula >= updateTimeNebula) {
			runningTimeNebula = 0;
			nebulaRect.x = frameNebula * nebulaRect.width;
			frameNebula++;
			if (frameNebula > 5) {
				frameNebula = 0;
			}
		}

		//draw characters
		DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);
		DrawTextureRec(nebula, nebulaRect, nebulaPos, WHITE);
		EndDrawing();
	}
	UnloadTexture(scarfy);
	UnloadTexture(nebula);
	CloseWindow();
	return 0;
}