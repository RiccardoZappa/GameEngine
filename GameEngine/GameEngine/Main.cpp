// Main.cpp : Defines the entry point for the application.
#include "GameEngine.h"

using namespace GameEngine;

int main(int argc, char* argv[])
{
	CGameEngine game_engine;

	bool success = game_engine.Initialize();

	if (success)
	{
		game_engine.RunLoop();
	}

	game_engine.ShutDown();

	return 0;
}
