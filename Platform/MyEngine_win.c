#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND hWnd,
			UINT message,
			WPARAM wParam,
			LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPTSTR lpCmdLine,
		int nCmdShow)

{
	HWND hWnd;

	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));


	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VEWDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = loadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = _T("WindowClass1");


	//register the window class
	RegisterClassEx(&wc);

	//create the window and use te result as the handle
	hWnd = CreateWindowEx(0,
			_T("WindowClass1"),//name of the window class
			_T("Hello, Engine!");//title of the window
			WS_OVERLAPPEDWINDOW,//window style
			300,//x-position
			300,//y-position
			500,//width
			400,//height
			NULL,//no parent window
			NULL,//not use menus
			hInstance,//application handle
			NULL);//used with multiple windows, NULL

	//display the window on the screen
	ShowWindow(hWnd, nCmdShow);

	//enter the main loop:
	

	//this struct holds Windows event messages
	MSG msg;

	//wait for the next message in the queue, store the resule in "msg"
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);

		DispatchMessage(&msg);
	}

	//return this part of the WM_QUIT message to Windows
	return msg.wParam;
}

//main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//sort through and find what code to run for the message given
	switch(message)
	{
		case WM_DESTROY:
			{
				//close the application entirely
				PostQuitMessage(0);
				return 0;
			}break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


