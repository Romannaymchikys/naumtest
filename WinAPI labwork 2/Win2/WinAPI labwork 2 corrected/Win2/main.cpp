#include <windows.h>
#include <tchar.h>
#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 500
#define HEGHT 400
#include "resource.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <string>
//srand(time(NULL));

                          
 
int CalculationStep(bool value,  int& step,
	                unsigned int& i, unsigned int& sum, unsigned int& j,
	                const int range_w, const int range_h) {
	++j; ++i; sum += i;
	// ���� ����� ������ �� ��������� � �����
	if (value) {
		// ���� i ������ ��  ��������� �� ���������
		if (i % 2) {  step = -1 * (range_w); }
		else {  step = 0; }
	}
	else {
		if (i % 2) { step = 0; }
		else { step = -1 * (range_h); }
	}
	return step;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hd�;// ������ �� ����������� ����������
	PAINTSTRUCT ps;// ��������� ��� ���������
	RECT rect;// ��������� �������� ���������� ���� 
	TEXTMETRIC tm;// ��������� � ����������� ������
	// static ��� ���� ����� int des_x �� ������� � ������� ��������� ���� ��������
	

	static int des_x;
	static int des_y;
	
	static int step_vertical;
	static int step_horizontal;
	static bool selector;
	static int step;
	static unsigned int i, sum, j;
	static int range_h;
	static int range_w;

	static int height;
	//�������� ������ �� �����  ����
	HWND hST;
	switch (uMessage)
	{
		//SystemParametersInfo ������� ���������  ���������
	case WM_CREATE: SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
		des_x = rect.right;
		des_y = rect.bottom;
		
		SetTimer(hWnd, 1, 10000, NULL);
		SetTimer(hWnd, 2, 10, NULL);
		SetTimer(hWnd, 3, 1000, NULL);

		step_vertical = 0;
		step_horizontal = 0;
		selector = false;
		step = 0;
		i = 2, sum = 3, j = 1;
		range_h = rect.bottom - HEGHT;
		range_w = rect.right  - WIDTH;


		step_horizontal = rect.right - WIDTH;
		
		// ������� ������ �� �����������
		hd� = GetDC(hWnd);
		// ������ ��������� ���������
		GetTextMetrics(hd�, &tm);

		height = tm.tmExternalLeading + tm.tmItalic;
		ReleaseDC(hWnd, hd�);


	case WM_KEYDOWN:
		if (wParam == VK_RETURN) {
			MoveWindow(hWnd, des_x - WIDTH, 0, WIDTH, HEGHT, true);
			selector = true;
		}
    
	case WM_TIMER: 
	// ��������� wParam
		switch (wParam)
		{
		case(1):
			if (MessageBox(hWnd, _TEXT("to close a window? "),
				        _TEXT("attention"), MB_YESNO) == IDYES) {
				DestroyWindow(hWnd);
			}
			break;
		case(2):
		{
			if (selector) {
				++step;
				// ��������� �� ���������
				if (j % 2) {
					
					if (range_h != abs(step) && abs(step) != 0) {
						step_vertical = abs(step);
					}
					else {
						CalculationStep(sum % 2, step, i, sum, j, range_w, range_h);
					}
				}
				else {
					if (range_w != abs(step) && abs(step) != 0) {
						step_horizontal = abs(step);
					}
					else {
						CalculationStep(!(sum % 2), step, i, sum, j, range_w, range_h);
					}

				}
				SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
				SetClassLong(hWnd, GCL_HBRBACKGROUND,
					        MoveWindow(hWnd, step_horizontal, 
						    step_vertical, WIDTH, HEGHT, true));
				InvalidateRect(hWnd, NULL, true);
			}
			break;
		case(3):
		{
			SendMessage(hWnd, WM_PAINT, 0, 0);
			// �������������� ����
			RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW);
		}
		break;
		default: break;
		}
	}
	case WM_PAINT:
		char buffer[20];
		time_t rawtime;
		struct tm * timeinfo;

		hd� = BeginPaint(hWnd, &ps);
		setlocale(LC_CTYPE, "");
		
		rawtime =  
		timeinfo = localtime(&rawtime); 
		strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo); 

		TextOut(hd�, 200, 200, buffer, strlen(buffer)); 
		break;

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
			MessageBox(NULL, TEXT("Sorry... :("),
				             TEXT("Error"), MB_OK | MB_ICONERROR);
		}
	case WM_LBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HCURSOR,
			        (LONG)LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(102)));//
		break;
	case WM_LBUTTONDOWN:
		SetClassLong(hWnd, GCL_HCURSOR,
			        (LONG)LoadCursor(NULL, IDC_ARROW));// ������ ������ �� �����������
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd, TEXT("�� ������������� ������ ��������� ������ ����������?"),
			TEXT("����������"), MB_YESNO) == IDYES) {
			DestroyWindow(hWnd);
		}
		break;
	
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		KillTimer(hWnd, 2);
		KillTimer(hWnd, 3);
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
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);//���
	wnd.lpszMenuName = NULL;
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&wnd)) {
		MessageBox(NULL, TEXT("Sorry :("), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}
	// ������� �������� ����
	HWND hWnd = CreateWindowEx(WS_EX_WINDOWEDGE,
		TEXT("Window"),
		TEXT("Hello"),
		WS_OVERLAPPEDWINDOW ^ WS_MINIMIZEBOX ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WIDTH,
		HEGHT,
		NULL, 
		NULL,
		hInstance,
		NULL);// HWND_DESKTOP

	if (!hWnd) {
		MessageBox(NULL, TEXT("Sorry... :("), 
			             TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);// ������������ ��� �� ����������
		DispatchMessage(&msg); // ��������������� ���������� ���������
	}
	return msg.wParam;
}

