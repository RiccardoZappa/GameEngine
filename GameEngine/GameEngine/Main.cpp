// Main.cpp : Defines the entry point for the application.
#include <Windows.h>

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];
INT WindowWidth = 1366;
INT WindowHeight = 768;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{

	/* Initialize global variables*/
	wcscpy_s(WindowClass, MAX_NAME_STRING, L"TutorialWindow");
	wcscpy_s(WindowTitle, MAX_NAME_STRING, L"My First GameEngine Window");

	/*Create  window class*/
	WNDCLASSEX WndCex;
	WndCex.cbSize = sizeof(WNDCLASSEX);
	WndCex.style = CS_HREDRAW | CS_VREDRAW;
	WndCex.cbClsExtra = 0;
	WndCex.cbWndExtra = 0;
	   
	WndCex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	WndCex.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));

	WndCex.hIcon = LoadIcon(0, IDI_APPLICATION);
	WndCex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	WndCex.lpszMenuName = (LPCSTR)WindowClass;

	WndCex.lpszMenuName = nullptr;
	WndCex.hInstance = HInstance();

	WndCex.lpfnWndProc = DefWindowProc;
	RegisterClassEx(&WndCex);

	/*Create and display our window */

	HWND hwn = CreateWindow((LPCSTR)WindowClass, (LPCSTR)WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
	if(!hwn)
	{
		MessageBox(0, "Failed to create the window!", 0, 0);
		return 0;
	}
	ShowWindow(hwn, SW_SHOW);

	/* Listen for message event */

	MSG msg{ 0 };
	while (msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg,0,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
}

int main()
{
	return WinMain(nullptr,nullptr,nullptr,1);
}
