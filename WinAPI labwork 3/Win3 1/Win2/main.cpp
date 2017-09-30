#include <Windows.h> 
#include "resource.h"
#include <vector>
#include <conio.h>

#define VEC_SIZE 6
#define ID_DOG1  113
#define ID_START 1002
#define ID_DOGS  3000
#define ID_CATS  3001
#define ID_FIRST 3002
#define ID_SLOW  3003

std::vector<HBITMAP> vecHbitmapDogs;
std::vector<HBITMAP> vecHbitmapCats;

HWND _hDogs, _hCats, _hFirst, _hSlow,
         _hPicture, _hStar, _hFinish;


void ImageCreation(const std::vector<HBITMAP>& vecHbitmap){
	// отправляем сообщение на перерисовку bitmap
	SendMessage(_hPicture, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP,
		(LPARAM)vecHbitmap.at(rand() % VEC_SIZE));
}


bool ChoiceActionImageCreation(HWND hWnd, HWND scrollingSpeed){
	if (SendMessage(scrollingSpeed, BM_GETSTATE, 0, 0)) {
		if (SendMessage(_hDogs, BM_GETCHECK, 0, 0) &&
			SendMessage(_hCats, BM_GETCHECK, 0, 0)) {
			if (rand() % 2) {
				ImageCreation(vecHbitmapCats);
				return true;
			}
			else {
				ImageCreation(vecHbitmapDogs);
				return true;
			}
		}
		else if (SendMessage(_hDogs, BM_GETCHECK, 0, 0)) {
			ImageCreation(vecHbitmapDogs);
			return true;
		}
		else if (SendMessage(GetDlgItem(hWnd, ID_CATS),
			BM_GETCHECK, 0, 0)) {
			ImageCreation(vecHbitmapCats);
			return true;
		}
	}
	return true;
}


BOOL CALLBACK MainDlgProc(HWND hWnd, UINT uMsg,
	                      WPARAM wParam, LPARAM lParam) 
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		// почему-то не видит инициализацию
		SetTimer(hWnd, 1, 500, NULL);
		SetTimer(hWnd, 2, 2400, NULL);
		return true;
	case WM_COMMAND:
		switch (wParam)
		{
		case ID_START:
			if (SendMessage(_hStar, BM_GETSTATE, 0, 0)) {
				SendMessage(_hStar, BM_SETSTATE, TRUE, 0);
				return true;
			}
		case ID_FINISH:
			if (SendMessage(_hFinish, BM_GETSTATE, 0, 0)) {
				SendMessage(_hStar, BM_SETSTATE, FALSE, 0);
				return true;
			}
		}
		return true;
	case WM_TIMER:
		if (SendMessage(_hStar, BM_GETSTATE, 0, 0)) {
			switch (wParam)
			 {
			  case(1): ChoiceActionImageCreation(hWnd, _hFirst);
			     return true;
			  case(2): ChoiceActionImageCreation(hWnd,  _hSlow);
				 return true;
		     }
		    }
			return true;
	case WM_CLOSE:
			KillTimer(hWnd, 1);
			KillTimer(hWnd, 2);
			DestroyWindow(hWnd);
			PostQuitMessage(0);
			return true;
		}
	return false;
	}
	

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR
	cmdArgs, int nCmdShow) {
	HWND hWnd = CreateDialog(hInst, MAKEINTRESOURCE(101), NULL,
		                                   (DLGPROC)MainDlgProc);
	ShowWindow(hWnd, 1);
	HWND hDogs = CreateWindow(L"BUTTON", L"dogs",
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		20, 20, 80, 30, hWnd,(HMENU)ID_DOGS,
		GetModuleHandle(NULL), NULL);

	HWND hCats = CreateWindow(L"BUTTON", L"cats",
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		20, 50, 80, 30, hWnd, (HMENU)ID_CATS, 
		GetModuleHandle(NULL), NULL);

	HWND hFirst = CreateWindow(L"BUTTON", L"first",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		20, 150, 80, 30, hWnd, (HMENU)ID_FIRST, 
		GetModuleHandle(NULL), NULL);

	HWND hSlow = CreateWindow(L"BUTTON", L"slow",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		20, 180, 80, 30, hWnd, (HMENU)ID_SLOW, 
		GetModuleHandle(NULL), NULL);
	
	// вектор кошек
	for (int i(IDB_CAT1); i <= IDB_CAT1 + VEC_SIZE; i++) {
		vecHbitmapCats.push_back(LoadBitmap(  hInst, 
			MAKEINTRESOURCE(i))); 
	}

	// вектор собак
	for (int i(ID_DOG1); i < ID_DOG1 + VEC_SIZE; i++) {
		vecHbitmapDogs.push_back(LoadBitmap(hInst,
			MAKEINTRESOURCE(i)));
	}

	_hStar    = GetDlgItem(hWnd, ID_START);
	_hFinish  = GetDlgItem(hWnd, ID_FINISH);
	_hSlow    = GetDlgItem(hWnd, ID_SLOW);
	_hFirst   = GetDlgItem(hWnd, ID_FIRST);
	_hDogs    = GetDlgItem(hWnd, ID_DOGS);
	_hCats    = GetDlgItem(hWnd, ID_CATS);
	_hPicture = GetDlgItem(hWnd, 1001);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (INT)msg.wParam;
}
