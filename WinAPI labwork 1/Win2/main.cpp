#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include <time.h>
#include <stdlib.h>

#define WIDTH 800
#define HEGHT 400

LRESULT CALLBACK WndProc(HWND hWnd,  UINT uMessage,
	                     WPARAM wParam, LPARAM lParam)
{
	static int des_x;
	static int des_y;
	static int counter, step;
	RECT rect;
	HWND hST[5];
	switch (uMessage)
	{
		
	case WM_CREATE: SystemParametersInfo(SPI_GETWORKAREA,
		                                   0, &rect, 0);
		des_x = rect.right;
		des_y = rect.bottom;
		counter = 0;
		step = 20;
		
		SetTimer(hWnd, 1, 1000, NULL);
		SetTimer(hWnd, 2, 10000, NULL);
		
	case WM_KEYDOWN:
		if (wParam == VK_RETURN) {
			MoveWindow(hWnd, des_x - WIDTH, 0,
				                     WIDTH, HEGHT, true);
		}

	case WM_TIMER: 
	
		switch (wParam)
		{
			case 1:
				SetClassLong(hWnd, GCL_HBRBACKGROUND,
					(LONG)CreateSolidBrush(RGB(rand() % 400,
				     rand() % 400, rand() % 400)));
				InvalidateRect(hWnd, NULL, true);
				break;
			case 2:
				++counter;
				if (counter < 5)
				hST[counter] = CreateWindowEx(NULL,
					TEXT("STATIC"),
					TEXT("Hello"),
					WS_CHILD | WS_VISIBLE,
					step, 20, 100, 40,
					hWnd, 
					NULL,
					GetModuleHandle(NULL),
					NULL);
				SetClassLong(hWnd, GCL_HBRBACKGROUND, 
					   ShowWindow(hST[counter], SW_RESTORE));
				InvalidateRect(hWnd, NULL, true);
				step += 110;
				break;	
		default:
			break;
		}
	
	case WM_SYSKEYDOWN:
		if (wParam == VK_DOWN) {
			ShowWindow(hWnd, SW_SHOWMAXIMIZED);
		}
		else if (wParam == VK_UP) {
			ShowWindow(hWnd, SW_SHOWMINIMIZED);
		}
		else if (wParam == VK_LEFT || wParam == VK_RIGHT) {
			ShowWindow(hWnd, SW_NORMAL);
		}
		break;
	case WM_CHAR:
		if (wParam == 'Q' || wParam == 'q') {
			MessageBox(NULL, TEXT("warnings :("),
				             TEXT("...  "), MB_OK | MB_ICONERROR);
			MessageBox(NULL, TEXT("Attention:("),
				             TEXT("Error"), MB_OKCANCEL | MB_ICONERROR);
			MessageBox(NULL, TEXT("question :("), 
				             TEXT("close a window"), MB_YESNO | MB_ICONERROR);
			MessageBox(NULL, TEXT("Sorry... :("),
				             TEXT("Error"), MB_YESNOCANCEL | MB_ICONERROR);
		}
	case WM_LBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HCURSOR,
			(LONG)LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(102)));
		break;
	case WM_LBUTTONDOWN:
		SetClassLong(hWnd, GCL_HCURSOR,
			(LONG)LoadCursor(NULL, IDC_ARROW));
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd, TEXT("Вы действительно хотите завершить работу приложения?"),
			                 TEXT("Информация"), MB_YESNO) == IDYES) {
			DestroyWindow(hWnd);
		}
		break;

	case WM_DESTROY:

		KillTimer(hWnd, 1);
		KillTimer(hWnd, 2);

		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
	               LPSTR lpszCmdLine, int nCmdShow)
{
	
	WNDCLASSEX wnd;

	wnd.cbSize = sizeof(wnd);
	wnd.lpszClassName = TEXT("Window");
	wnd.style = CS_HREDRAW | CS_VREDRAW;
	wnd.lpfnWndProc = WndProc;
	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hInstance = hInstance;
	//hInstance - 
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(102));
	wnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));// IDI_ICON1
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);
	wnd.lpszMenuName = NULL;
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&wnd)) {
		MessageBox(NULL, TEXT("Sorry :("), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	HWND hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, TEXT("Window"), TEXT("Hello"),
		WS_OVERLAPPEDWINDOW ^ WS_MINIMIZEBOX ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEGHT,
		NULL, NULL, hInstance, NULL);// HWND_DESKTOP

	if (!hWnd) {
		MessageBox(NULL, TEXT("Sorry... :("), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

