// рисуем окно
// полосы скролинга
// немодальное - может весеть отдельно от гланого
// модальное
#include <Windows.h> 
// CALBACK - только вызывается операционное системой
#include "resource.h"
#include <commdlg.h>
#include <string>
#include <algorithm>


#define UNICODE

#define _CRT_SECURE_NO_WARNINGS
#define IDD_MAINDLG     101
#define ID_STATIC_1     1003
#define ID_STATIC_2     1004
#define ID_STATIC_3     1005
#define IDC_EDIT1       1006
#define IDC_EDIT2       1007
#define IDC_EDIT3       1010
#define ID_AUTO         1008
#define ID_OPEN         1001
#define ID_CLEAR_1      1013
#define ID_CLEAR_2      1017
#define ID_RECORD_1     1018
#define ID_ARROW_1      1014
#define ID_ARROW_2      1015
#define ID_DOUBLE_ARROW 1016




bool counterStrings(wchar_t* wszTemp, DWORD bytesRead) {

	size_t count_n(0), count_r(0);
	for (wchar_t* ptr = wszTemp;
		ptr < wszTemp + (bytesRead * sizeof(wchar_t)); ++ptr) {

		switch (*ptr) {
		case '\n': ++count_n;
			break;
		case '\r': ++count_r;
			break;
		}
		if (count_n == 3 || count_r == 3) {
			return true;
		}
	}
	return false;
}
//255 -битовый 0
void clearEdit(HWND hEdit) {
	// считываем длинну текста
	int szTextDel = SendMessage(hEdit,
		WM_GETTEXTLENGTH, 0, 0);
	// выделяем этот текст в EDIT
	SendMessage(hEdit, EM_SETSEL, 0, szTextDel);
	// удаляем текст
	SendMessage(hEdit, WM_CLEAR, 0, 0);
}

BOOL CALLBACK MainDlgProc(HWND hWnd, UINT uMsg, WPARAM
	wParam, LPARAM lParam) {
	static OPENFILENAME openFile, saveFile;
	static wchar_t szFileName[256];
	static wchar_t szFileTitle[100];
	static HWND hStatOrigText, hStatYourtext, hStatDiction,
		        hEditOrigText, hEditYourtext, hEditDiction,
	            hAuto, hOpen, hClear,hArrow_1, hArrow_2,
		        hDoubleArrow;
	
	static HANDLE hFile = INVALID_HANDLE_VALUE;
	static HANDLE hFileSave = INVALID_HANDLE_VALUE;
    int szTextDel = 0;
	char    *szFileContent = NULL;
	static DWORD dwFileSize = 0, bytesToRead = 0, bytesRead = 0;
	static DWORD bytesToWrite = 0, bytesWrite = 0;
	switch (uMsg)
	{
	case WM_INITDIALOG:
		hStatOrigText = GetDlgItem(hWnd, ID_STATIC_1);
		hStatYourtext = GetDlgItem(hWnd, ID_STATIC_2);
		hStatDiction = GetDlgItem(hWnd, ID_STATIC_3);
		hEditOrigText = GetDlgItem(hWnd, IDC_EDIT1);
		hEditYourtext = GetDlgItem(hWnd, IDC_EDIT2);
		hEditDiction = GetDlgItem(hWnd, IDC_EDIT3);
		hAuto = GetDlgItem(hWnd, ID_AUTO);
		hOpen = GetDlgItem(hWnd, ID_OPEN);
		hClear = GetDlgItem(hWnd, ID_CLEAR);
		hArrow_1 = GetDlgItem(hWnd, ID_ARROW_1);
		hArrow_2 = GetDlgItem(hWnd, ID_ARROW_2);
		hDoubleArrow = GetDlgItem(hWnd, ID_DOUBLE_ARROW);
		//EnableWindow(hOpen,  false);
		//EnableWindow(hClear, false);


		ZeroMemory(&openFile, sizeof(OPENFILENAME));//заполняем структуру
		openFile.lStructSize = sizeof(OPENFILENAME);
		openFile.hInstance = GetModuleHandle(NULL);
		openFile.hwndOwner = hWnd;
		openFile.lpstrFilter = L"Текстовый файл (*.txt)\0*.txt\0\0";
		openFile.nMaxFile = 256;
		openFile.nMaxFileTitle = 30;
		openFile.lpstrFileTitle = szFileTitle;
		openFile.lpstrFile = szFileTitle;

		ZeroMemory(&saveFile, sizeof(OPENFILENAME));//заполняем структуру
		saveFile.lStructSize = sizeof(OPENFILENAME);
		saveFile.hInstance = GetModuleHandle(NULL);
		saveFile.hwndOwner = hWnd;
		saveFile.lpstrFilter = L"Текстовый файл (*.txt)\0*.txt\0\0";
		saveFile.nMaxFile = 256;
		saveFile.nMaxFileTitle = 30;
		saveFile.lpstrFileTitle = szFileTitle;
		saveFile.lpstrFile = szFileTitle;
	case WM_COMMAND:
		switch (wParam)
		{
		case ID_AUTO:
			MessageBox(NULL, TEXT("Эта функция пока недоступна"),
				TEXT("Извените..."), MB_ICONINFORMATION);
			return true;
		case ID_OPEN:
			if (GetOpenFileName(&openFile))
			{
				//создаем дискриптор файла
				hFile = CreateFile(openFile.lpstrFile, GENERIC_READ, 0,
					NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

				// возвращает специальное значение если фаел не открылся
				if (hFile == INVALID_HANDLE_VALUE)
					return FALSE;

				//извлекаем размер выброного файла
				dwFileSize = GetFileSize(hFile, NULL);

				szFileContent = (char*)malloc(dwFileSize + 1);
				// чистим буфер
				memset(szFileContent, 0, dwFileSize + 1);

				//читать содержимое файлов в буфер
				if (ReadFile(hFile, szFileContent, dwFileSize, &bytesRead, NULL))
				{
					wchar_t *wszTemp = (wchar_t*)malloc(bytesRead * sizeof(wchar_t));

					//преобразуем ис мультибайтовых строк в дином. масс.
					mbstowcs(wszTemp, szFileContent, bytesRead);
					//проверяем на количество строк
					if (counterStrings(wszTemp, bytesRead)) {
						SetWindowText(hEditOrigText, wszTemp);
					}
					else {
						MessageBox(NULL, TEXT("В файле менее четырех строк"),
							TEXT("Извените..."), MB_ICONINFORMATION);
					}
					//Освобожлаем память под строку
					free(wszTemp);
				}
				//Освобожлаем ресурс
				free(szFileContent);
				CloseHandle(hFile);
			}
			return true;
		case ID_CLEAR_1:
			clearEdit(hEditOrigText);
			return true;
		case ID_CLEAR_2:
			clearEdit(hEditYourtext);
			return true;
		case ID_ARROW_1:
			int  index;
			index = SendMessage(hEditOrigText, LB_GETCURSEL, 0, 0);
			SendMessage(hEditOrigText, WM_COPY, 0, szTextDel);
			SendMessage(hEditYourtext, WM_PASTE, 0, 0);
			
			return true;
		case ID_DOUBLE_ARROW:
			int szTextDel;
			szTextDel = SendMessage(hEditOrigText,
			WM_GETTEXTLENGTH, 0, 0);
			wchar_t* buf;
			buf = (wchar_t*)malloc(szTextDel * sizeof(wchar_t));;
			//LRESULT t = SendMessage(hEditOrigText, EM_SETSEL, 0, szTextDel);

			GetWindowText(hEditOrigText, buf, szTextDel);
			SetWindowText(hEditYourtext, buf);
			free(buf);
			return true;
		case ID_RECORD_1:
			if (GetSaveFileName(&saveFile))
			{
				//создаем дискриптор файла
				hFileSave = CreateFile(saveFile.lpstrFile, GENERIC_WRITE, 0,
					NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

				// возвращает специальное значение если фаел не открылся
				if (hFileSave == INVALID_HANDLE_VALUE)
					return FALSE;

				//извлекаем размер выброного файла
				dwFileSize = GetFileSize(hFileSave, NULL);

				szFileContent = (char*)malloc(dwFileSize + 1);
				// чистим буфер
				memset(szFileContent, 0, dwFileSize + 1);

				//читать содержимое файлов в буфер
				WriteFile(hFileSave, szFileContent, dwFileSize, &bytesWrite, NULL);
				
				//Освобожлаем ресурс
				free(szFileContent);
				CloseHandle(hFileSave);
				return true;
			}
		}
	    
		return true;
	
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}


INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR
	cmdArgs, int nCmdShow) {
	HWND hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MAINDLG), NULL,
		(DLGPROC)MainDlgProc);
	ShowWindow(hWnd, 1);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
