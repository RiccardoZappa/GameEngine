// Main.cpp : Defines the entry point for the application.
#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hIstance, HINSTANCE, LPSTR lpCmdLine, INT nCmdshow)
{

	/*Create a window*/
	WNDCLASSEX Wnd;
	Wnd.cbSize = sizeof(WNDCLASSEX);
	Wnd.style = CS_HREDRAW | CS_VREDRAW;
	Wnd.cbClsExtra = 0;
	Wnd.cbWndExtra = 0;


	return 0;
}

