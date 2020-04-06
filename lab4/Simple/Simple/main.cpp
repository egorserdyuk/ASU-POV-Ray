// simple.cpp: пример простейшего Windows-приложени¤.
//

//#undef UNICODE
//#undef _UNICODE

#include <cmath>

#include "stdafx.h"
#include "simple.h"

#define MAX_LOADSTRING 100
#define _CRT_SECURE_NO_WARNINGS

// √лобальные переменные:
HINSTANCE hInst;								// текущий экземпл¤р
TCHAR szTitle[MAX_LOADSTRING];					// “екст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// им¤ класса главного окна

// ќтправить объ¤влени¤ функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

// √лобальна¤ структура дл¤ параметров программы.
struct Params {
	int x1, x2, y;
} params;


//
//   ‘”Ќ ÷»я: ReadParams()
//
//   Ќј«Ќј„≈Ќ»≈: присваивает глобальным переменным значени¤ параметров программы.
//
//    ќћћ≈Ќ“ј–»»:
//
//        “ело функции реализовано простейшим способом. ќбычно присваиваемые значени¤ 
//		  читаютс¤ из файла настроек или командной строки.
//
void ReadParams() {
	params.x1 = 10;
	params.x2 = 100;
	params.y = 50;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: разместите свой код здесь.
	// „итать значени¤ параметров программы из файла или командной строки 
	ReadParams();

	MSG msg;
	HACCEL hAccelTable;

	// »нициализаци¤ глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SIMPLE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ¬ыполнить инициализацию приложени¤:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SIMPLE));

	// ÷икл основного сообщени¤:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ‘”Ќ ÷»я: MyRegisterClass()
//
//  Ќј«Ќј„≈Ќ»≈: регистрирует класс окна.
//
//   ќћћ≈Ќ“ј–»»:
//
//    Ёта функци¤ и ее использование необходимы только в случае, если нужно, чтобы данный код
//    был совместим с системами Win32, не имеющими функции RegisterClassEx'
//    котора¤ была добавлена в Windows 95. ¬ызов этой функции важен дл¤ того,
//    чтобы приложение получило "качественные" мелкие значки и установило св¤зь
//    с ними.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SIMPLE));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_SIMPLE);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ‘”Ќ ÷»я: InitInstance(HINSTANCE, int)
//
//   Ќј«Ќј„≈Ќ»≈: сохран¤ет обработку экземпл¤ра и создает главное окно.
//
//    ќћћ≈Ќ“ј–»»:
//
//        ¬ данной функции дескриптор экземпл¤ра сохран¤етс¤ в глобальной переменной, а также
//        создаетс¤ и выводитс¤ на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // —охранить дескриптор экземпл¤ра в глобальной переменной

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  ‘”Ќ ÷»я: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ќј«Ќј„≈Ќ»≈:  обрабатывает сообщени¤ в главном окне.
//
//  WM_COMMAND	- обработка меню приложени¤
//  WM_PAINT	-«акрасить главное окно
//  WM_DESTROY	 - ввести сообщение о выходе и вернутьс¤.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// –азобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: добавьте любой код отрисовки...

		// Ќарисовать горизонтальную пр¤мую с параметрами params  
		for (int x = params.x1; x <= params.x2; x++) {
			SetPixel(hdc, x, params.y, RGB(250, 0, 0));
		}

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ќбработчик сообщений дл¤ окна "ќ программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void setPixel(HWND hWnd, int x, int y, COLORREF& color) {

	HDC hdc = GetDC(hWnd);

	SetPixel(hdc, x, y, color);

	ReleaseDC(hWnd, hdc);

	return;

	// NEVERREACH //

}

void Display(HWND hWnd, int x1, int y1, int x2, int y2) {
	// Get window context
	HDC hDc = GetDC(hWnd);

	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	//
	int error = deltaX - deltaY;
	//
	SetPixel(hDc, x2, y2, 0);
	while (x1 != x2 || y1 != y2)
	{
		SetPixel(hDc, x1, y1, 0);
		const int error2 = error * 2;
		//
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
	for (int i = 0; i < 12; ++i)
		Display(250, 300, 250 + 250 * cos((float)i / 2), 300 + 250 * sin((float)i / 2));
}