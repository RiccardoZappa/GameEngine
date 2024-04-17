// GameEngine.cpp : Defines the entry point for the application.
//

void main() // Pong
{
	initGame();
	while (true) // game loop
	{
		readHumanInterfaceDevices();
		if (quitButtonPressed())
		{
			break; // exit the game loop
		}
		movePaddles();
		moveBall();
		collideAndBounceBall();
		528 8. The Game Loop and Real - Time Simulation
			if (ballImpactedSide(LEFT_PLAYER))
			{
				incremenentScore(RIGHT_PLAYER);
				resetBall();
			}
			else if (ballImpactedSide(RIGHT_PLAYER))
			{
				incrementScore(LEFT_PLAYER);
				resetBall();
			}
		renderPlayfield();
	}
}
