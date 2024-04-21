// Main.cpp : Defines the entry point for the application.
#include <Windows.h>

#define MAX_NAME_STRING 256;
#define HInstance() GetModuleHandle(NULL);

WCHAR WindowClass [MAX_NAME_STRING];

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{

	/* Initialize global variables*/
	wcscpy_s(WindowClass, TEXT("TutorialWindow"));

	/*Create a window*/
	WNDCLASSEX WndCex;
	WndCex.cbSize = sizeof(WNDCLASSEX);
	WndCex.style = CS_HREDRAW | CS_VREDRAW;
	WndCex.cbClsExtra = 0;
	WndCex.cbWndExtra = 0;
	   
	WndCex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	WndCex.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));

	WndCex.hIcon = LoadIcon(0, IDI_APPLICATION);
	WndCex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	WndCex.lpszMenuName = WindowClass;

	WndCex.lpszMenuName = nullptr;
	WndCex.hInstance = HInstance();

	WndCex.lpfnWndProc = DefWindowProc;
	RegisterClassEx(&WndCex);

	return 0;
}

