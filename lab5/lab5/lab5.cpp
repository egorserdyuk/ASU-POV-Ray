// simple.cpp: пример простейшего Windows-приложения.
//

//#undef UNICODE
//#undef _UNICODE

#include "stdafx.h"
#include "lab5.h"
#include <fstream>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

#define M_PI  3.14159265358979323846
#define MAX_LOADSTRING 100
#define _CRT_SECURE_NO_WARNINGS

// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

// Глобальная структура для параметров программы.
struct Params
{
	int x1, x2, y1, y2, mode1, mode2, n;
	std::vector<std::vector<int>> vec;
} params;

//
//   ФУНКЦИЯ: ReadParams()
//
//   НАЗНАЧЕНИЕ: присваивает глобальным переменным значения параметров программы.
//
//   КОММЕНТАРИИ:
//
//        Тело функции реализовано простейшим способом. Обычно присваиваемые значения 
//		  читаются из файла настроек или командной строки.
//
void ReadParams()
{
	std::ifstream fin;
	fin.open("params.dat");
	fin >> params.mode1;
	fin >> params.mode2;
	if (params.mode2 == 2)
	{
		fin >> params.x1;
		fin >> params.y1;
		fin >> params.x2;
		fin >> params.y2;
	}

	fin.close();
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: разместите свой код здесь.
	// Читать значения параметров программы из файла или командной строки 
	ReadParams();


	MSG msg;
	HACCEL hAccelTable;

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LAB5, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB5));

	// Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
//  КОММЕНТАРИИ:
//
//    Эта функция и ее использование необходимы только в случае, если нужно, чтобы данный код
//    был совместим с системами Win32, не имеющими функции RegisterClassEx'
//    которая была добавлена в Windows 95. Вызов этой функции важен для того,
//    чтобы приложение получило "качественные" мелкие значки и установило связь
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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB5));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_LAB5);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

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

//функция для рисования отрезка красного цвета
void drawLine(HDC hdc, int x1, int y1, int x2, int y2)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;

	SetPixel(hdc, x2, y2, RGB(250, 0, 0));
	while (x1 != x2 || y1 != y2)
	{
		SetPixel(hdc, x1, y1, RGB(250, 0, 0));
		const int error2 = error * 2;

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

}

//функция для рисования отрезка заданного цвета
void drawLine(HDC hdc, int x1, int y1, int x2, int y2, int c1, int c2, int c3)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;

	int error = deltaX - deltaY;

	SetPixel(hdc, x2, y2, RGB(c1, c2, c3));
	while (x1 != x2 || y1 != y2)
	{
		SetPixel(hdc, x1, y1, RGB(c1, c2, c3));
		const int error2 = error * 2;

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

}

void swap(std::vector<int>& a, std::vector<int>& b)
{
	std::vector<int> c;
	c = a;
	a = b;
	b = c;
}

void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

//функция для рисования многоугольника
void fillPolygon(HDC hdc, std::vector<std::vector<int>> vec)
{
	std::map<int, std::vector<int>> a;
	std::map<int, std::vector<int>>::iterator it;
	int i, j;
	int x1, y1, x2, y2;

	for (i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i][1] < vec[i + 1][1]) { x1 = vec[i][0]; x2 = vec[i + 1][0]; y1 = vec[i][1]; y2 = vec[i + 1][1]; }
		else { x1 = vec[i + 1][0]; x2 = vec[i][0]; y1 = vec[i + 1][1]; y2 = vec[i][1]; }
		for (j = y1; j < y2; j++)
			a[j].push_back((j - y1) * (x2 - x1) / (y2 - y1) + x1);
	}
	if (vec[0][1] < vec[vec.size() - 1][1]) { x1 = vec[0][0]; x2 = vec[vec.size() - 1][0]; y1 = vec[0][1]; y2 = vec[vec.size() - 1][1]; }
	else { x1 = vec[vec.size() - 1][0]; x2 = vec[0][0]; y1 = vec[vec.size() - 1][1]; y2 = vec[0][1]; }
	for (j = y1; j < y2; j++)
		a[j].push_back((j - y1) * (x2 - x1) / (y2 - y1) + x1);

	for (it = a.begin(); it != a.end(); it++)
	{
		std::sort(it->second.begin(), it->second.end());
		drawLine(hdc, it->second[0], it->first, it->second[1], it->first);
	}
}

//функция для определения положения точки относительно прямой, -1 если ниже-левее, 1 если выше-правее, 0 если точка на прямой
int det_sign(int x, int y, int x1, int y1, int x2, int y2)
{
	if (x * (y1 - y2) + y * (x2 - x1) + (x1 * y2 - x2 * y1) < 0)
		return -1;
	else if (x * (y1 - y2) + y * (x2 - x1) + (x1 * y2 - x2 * y1) > 0)
		return 1;
	else
		return 0;
}
//функция для пересечения отрезков, которые лежат на одной прямой
bool inside(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, int& x4, int& y4)
{
	//упорядочивание координат
	if (x1 > x2 || x1 == x2 && y1 > y2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	//упорядочивание координат
	if (x3 > x4 || x3 == x4 && y3 > y4)
	{
		swap(x3, x4);
		swap(y3, y4);
	}

	if (x1 >= x4 || x2 <= x3)
		return false;

	if (x1 < x3)
	{
		swap(x1, x3);
		swap(y1, y3);
	}

	if (x2 > x4)
	{
		swap(x2, x4);
		swap(y2, y4);
	}

	return true;
}

//функция с реализацией алгоритма
bool PavlidPolyClip(int& x1, int& y1, int& x2, int& y2, std::vector<std::vector<int>> vec) // координаты начала и конца отрезка и массив с координатами многоугольника
{
	int i;
	std::vector<int> u; //содержит информацию о положении вершин многоугольника относительно прямой, содержащей заданный отрезок
	int count0 = 0; //счётчик нулевых в векторе u
	int count1 = 0; //счётчик пар элементов с разными знаками в векторе u
	std::vector<int> coord; //координаты хорды, соединящей ребра, через которые проходит исходная прямая, хорда также ей принадлежит

	for (i = 0; i < vec.size(); i++)
		u.push_back(det_sign(vec[i][0], vec[i][1], x1, y1, x2, y2));

	for (i = 0; i < vec.size() - 1; i++)
		if (u[i] == 0) count0++;
		else if (u[i] * u[i + 1] < 0) count1++;
	if (u[vec.size() - 1] == 0) count0++;
	else if (u[vec.size() - 1] * u[0] < 0) count1++;

	//различные случаи
	if (count0 == 0 && count1 == 0) //1, прямая не пересекает многоугольник
		return false;

	if (count0 == 1 && count1 == 0) //2, прямая касается многоугольника, то еть всего одна общая точка
		return false;

	//случаи 3,4 и 5 из презентации объеденины в общий алгоритм
	for (i = 0; i < u.size() - 1; i++)
	{
		if (u[i] == 0) //если u[i]=0 значит прямая проходит через i-ю вершину многоугольника, запихиваем её в coord
		{
			coord.push_back(vec[i][0]);
			coord.push_back(vec[i][1]);
		}

		if (u[i] * u[i + 1] < 0) //если произведение соседних имеет отрицательный знак, значит через ребро u[i],u[i+1] проходит исходная прмая
		{
			//в coord засовываем точку пересечения исходной прямой и прямой, содержпщей это ребро
			int x3, y3, x4, y4;
			x3 = vec[i][0];
			y3 = vec[i][1];
			x4 = vec[i + 1][0];
			y4 = vec[i + 1][1];
			coord.push_back(((x1 * y2 - x2 * y1) * (x3 - x4) - (x1 - x2) * (x3 * y4 - x4 * y3)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)));
			coord.push_back(((x1 * y2 - x2 * y1) * (y3 - y4) - (y1 - y2) * (x3 * y4 - x4 * y3)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)));
		}
	}
	if (u[u.size() - 1] == 0)
	{
		coord.push_back(vec[i][0]);
		coord.push_back(vec[i][1]);
	}

	if (u[u.size() - 1] * u[0] < 0)
	{
		int x3, y3, x4, y4;
		x3 = vec[u.size() - 1][0];
		y3 = vec[u.size() - 1][1];
		x4 = vec[0][0];
		y4 = vec[0][1];
		coord.push_back(((x1 * y2 - x2 * y1) * (x3 - x4) - (x1 - x2) * (x3 * y4 - x4 * y3)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)));
		coord.push_back(((x1 * y2 - x2 * y1) * (y3 - y4) - (y1 - y2) * (x3 * y4 - x4 * y3)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)));
	}
	if (inside(x1, y1, x2, y2, coord[0], coord[1], coord[2], coord[3])) //проверяем, лежит ли отрезок внутри многоугольника, если да, то оставляем в x1,y1,x2,y2 часть, которая попала
		return true;
	else
		return false;
}

#define LEFT  1  /* двоичное 0001 */
#define RIGHT 2  /* двоичное 0010 */
#define BOT   4  /* двоичное 0100 */
#define TOP   8  /* двоичное 1000 */

/* вычисление кода точки*/
#define vcode(vec, x, y) \
	(((x < vec[0][0]) ? LEFT : 0)  +  /* +1 если точка левее прямоугольника */ \
	 ((x > vec[2][0]) ? RIGHT : 0) +  /* +2 если точка правее прямоугольника */\
	 ((y < vec[0][1]) ? BOT : 0)   +  /* +4 если точка ниже прямоугольника */  \
	 ((y > vec[2][1]) ? TOP : 0))     /* +8 если точка выше прямоугольника */

bool mid_point(int& x1, int& y1, int& x2, int& y2, std::vector<std::vector<int>> vec)
{
	int code_a, code_b, code; /* код концов отрезка */
	int x, y;

	code_a = vcode(vec, x1, y1);
	code_b = vcode(vec, x2, y2);

	/* пока одна из точек отрезка вне прямоугольника */
	while (code_a | code_b)
	{
		/* если обе точки с одной стороны прямоугольника, то отрезок не пересекает прямоугольник */
		if (code_a & code_b)
			return false;

		/* выбираем точку c с ненулевым кодом */
		if (code_a)
		{
			code = code_a;
			x = x1;
			y = y1;
		}
		else
		{
			code = code_b;
			x = x2;
			y = y2;
		}
		/* если точка левее прямоугольника, то передвигаем точку на прямую x = vec[0][0]
		   если точка правее прямоугольника, то передвигаем точку на прямую x = vec[3][0] */
		if (code & LEFT)
		{
			y += (y1 - y2) * (vec[0][0] - x) / (x1 - x2);
			x = vec[0][0];
		}
		else if (code & RIGHT)
		{
			y += (y1 - y2) * (vec[2][0] - x) / (x1 - x2);
			x = vec[2][0];
		}
		/* если точка ниже прямоугольника, то передвигаем точку на прямую y = vec[0][1]
			если точка выше прямоугольника, то передвигаем точку на прямую y = vec[3][1] */
		else if (code & BOT)
		{
			x += (x1 - x2) * (vec[0][1] - y) / (y1 - y2);
			y = vec[0][1];
		}
		else if (code & TOP)
		{
			x += (x1 - x2) * (vec[2][1] - y) / (y1 - y2);
			y = vec[2][1];
		}

		/* обновляем код */
		if (code == code_a)
		{
			x1 = x;
			y1 = y;
			code_a = vcode(vec, x1, y1);
		}
		else
		{
			x2 = x;
			y2 = y;
			code_b = vcode(vec, x2, y2);
		}
	}
	/* оба кода равны 0, следовательно обе точки в прямоугольнике */
	return true;
}

void myProg(HDC hdc)
{
	srand(time(0));
	int i, n, x, y;
	std::ifstream fin;
	fin.open("test.txt");
	std::vector<std::vector<int>> vec;
	fin >> n;
	for (int i(0); i < n; i++)
	{
		fin >> x >> y;
		std::vector<int> tmp;
		tmp.push_back(x);
		tmp.push_back(y);
		vec.push_back(tmp);
	}
	fillPolygon(hdc, vec); //отрисовка многоугольника

	if (params.mode1 == 1)
		if (params.mode2 == 1)
		{
			int x1, x2, y1, y2;
			n = rand() % 14 + 1;
			for (int i = 0; i < n; i++)
			{
				x1 = rand() % 500;
				y1 = rand() % 500;
				x2 = rand() % 500;
				y2 = rand() % 500;
				drawLine(hdc, x1, y1, x2, y2, 0, 0, 0);

				if (PavlidPolyClip(x1, y1, x2, y2, vec))
					drawLine(hdc, x1, y1, x2, y2, 255, 255, 255);
			}
		}
		else
		{
			drawLine(hdc, params.x1, params.y1, params.x2, params.y2);
			if (PavlidPolyClip(params.x1, params.y1, params.x2, params.y2, vec))
				drawLine(hdc, params.x1, params.y1, params.x2, params.y2, 255, 255, 255);
		}
	else
		if (params.mode2 == 1)
		{
			int x1, x2, y1, y2;
			n = rand() % 14 + 1;
			for (int i = 0; i < n; i++)
			{
				x1 = rand() % 500;
				y1 = rand() % 500;
				x2 = rand() % 500;
				y2 = rand() % 500;

				drawLine(hdc, x1, y1, x2, y2, 0, 0, 0);
				if (mid_point(x1, y1, x2, y2, vec))
					drawLine(hdc, x1, y1, x2, y2, 255, 255, 255);
			}
		}
		else
		{
			drawLine(hdc, params.x1, params.y1, params.x2, params.y2, 0, 0, 0);
			if (mid_point(params.x1, params.y1, params.x2, params.y2, vec))
				drawLine(hdc, params.x1, params.y1, params.x2, params.y2, 255, 255, 255);
		}
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND	- обработка меню приложения
//  WM_PAINT	-Закрасить главное окно
//  WM_DESTROY	 - ввести сообщение о выходе и вернуться.
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
		// Разобрать выбор в меню:
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

		// Нарисовать горизонтальную прямую с параметрами params  
		myProg(hdc);

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

// Обработчик сообщений для окна "О программе".
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
