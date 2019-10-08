#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define CREATE_MAGIC_3_BTN 1
#define CREATE_MAGIC_4_BTN 2
#define QUIT_BTN 3
#define QUIT_BTN_3 4
#define GENERATE_BTN_3 5
#define GENERATE_BTN_3_NORMAL 9
#define CLOSE_BTN_3 6
#define GENERATE_BTN_4 7
#define CLOSE_BTN_4 8
#define GENERATE_BTN_4_NORMAL 10


// оголошення вікон winapi
HWND hMainWindow, MagicSquare, generate_3, generate_3_normal, quit3, _title, close_3, __title, generate_4, generate_4_normal, close_4, magic_sum, magic_sum_title;
HWND _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16;
HWND  __1, __2, __3, __4, __5, __6, __7, __8, __9;
HWND magic_3, magic_4;

HFONT hFont, hFont2;
HBRUSH hbrBkgnd;

HINSTANCE hInst;

// оголошення глобальних змінних для обчислень
int special_case = 144;

int i = 0;
int j = 0;
int n = 34;
	

// функція створення головного меню програми
void AddMenu(HWND hwnd) {
	HWND magic_3, magic_4, quit;

	MagicSquare = CreateWindowW(
		L"Static",  // Predefined class; Unicode assumed 
		L"Magic square",      // Button text 
		WS_VISIBLE | WS_CHILD,  // Styles 
		200,         // x position 
		40,         // y position 
		240,		// button width
		47,        // Button height
		hwnd,     // Parent window
		(HMENU)CREATE_MAGIC_3_BTN,       // Matrix_3.
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);      // Pointer not needed.

	magic_3 = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Generate square 3x3.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		650,         // x position 
		250,         // y position 
		200,		// button width
		77,        // Button height
		hwnd,     // Parent window
		(HMENU)CREATE_MAGIC_3_BTN,       // Matrix_3.
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);      // Pointer not needed.

	magic_4 = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Generate square 4x4.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		650,         // x position 
		120,         // y position 
		200,        // Button width
		77,        // Button height
		hwnd,     // Parent window
		(HMENU)CREATE_MAGIC_4_BTN,       // Matrix_4.
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);      // Pointer not needed.

	quit = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Quit.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		650,         // x position 
		380,         // y position 
		140,        // Button width
		77,        // Button height
		hwnd,     // Parent window
		(HMENU)QUIT_BTN,       // Matrix_4.
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);      // Pointer not needed.);

	SendMessage(MagicSquare, WM_SETFONT, (WPARAM)hFont2, (LPARAM)MAKELONG(TRUE, 0));
	SendMessage(magic_3, WM_SETFONT, (WPARAM)hFont, (LPARAM)MAKELONG(TRUE, 0));
	SendMessage(magic_4, WM_SETFONT, (WPARAM)hFont, (LPARAM)MAKELONG(TRUE, 0));
	SendMessage(quit, WM_SETFONT, (WPARAM)hFont, (LPARAM)MAKELONG(TRUE, 0));
}


// функція створення меню роботи з магічними квадратами 3х3
void create3(HWND hwnd) {
	
	__1 = CreateWindowW(L"Button", "1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 230, 160, 40, 40, hwnd, NULL, NULL, NULL);
	__2 = CreateWindowW(L"Button", "2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 300, 160, 40, 40, hwnd, NULL, NULL, NULL);
	__3 = CreateWindowW(L"Button", "3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 370, 160, 40, 40, hwnd, NULL, NULL, NULL);
	__4 = CreateWindowW(L"Button", "4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 230, 230, 40, 40, hwnd, NULL, NULL, NULL);
	__5 = CreateWindowW(L"Button", "5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 300, 230, 40, 40, hwnd, NULL, NULL, NULL);
	__6 = CreateWindowW(L"Button", "6", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 370, 230, 40, 40, hwnd, NULL, NULL, NULL);
	__7 = CreateWindowW(L"Button", "7", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 230, 300, 40, 40, hwnd, NULL, NULL, NULL);
	__8 = CreateWindowW(L"Button", "8", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 300, 300, 40, 40, hwnd, NULL, NULL, NULL);
	__9 = CreateWindowW(L"Button", "9", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | BS_DEFPUSHBUTTON, 370, 300, 40, 40, hwnd, NULL, NULL, NULL);

	magic_sum_title = CreateWindowA("Static", "Magic sum - ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 270, 374, 94, 20, hwnd, NULL, NULL, NULL);
	magic_sum = CreateWindowA("Static", "", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 366, 374, 24, 20, hwnd, NULL, NULL, NULL);

	generate_3 = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Generate.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		250,         // x position 
		420,         // y position 
		140,        // Button width
		40,        // Button height
		hwnd,     // Parent window
		(HMENU)GENERATE_BTN_3, 
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);      // Pointer not needed.;

	generate_3_normal = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Generate Normal.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		100,         // x position 
		420,         // y position 
		140,        // Button width
		40,        // Button height
		hwnd,     // Parent window
		(HMENU)GENERATE_BTN_3_NORMAL,
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);      // Pointer not needed.;

	close_3 = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Close.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		400,         // x position 
		420,         // y position 
		140,        // Button width
		40,        // Button height
		hwnd,     // Parent window
		(HMENU)CLOSE_BTN_3,
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);
}


// функція генерації нормального магічного квадрату 3х3
void generate3_normal(HWND hwnd) {
	int MagicSquareArray3[8][9] = { {8, 1, 6, 3, 5, 7, 4, 9, 2}, {6, 1, 8, 7, 5, 3, 2, 9, 4}, {4, 9, 2, 3, 5, 7, 8, 1, 6}, {2, 9, 4, 7, 5, 3, 6, 1, 8}, {8, 3, 4, 1, 5, 9, 6, 7, 2}, {4, 3, 8, 9, 5, 1, 2, 7, 6}, {6, 7, 2, 1, 5, 9, 8, 3, 4}, {2, 7, 6, 9, 5, 1, 4, 3, 8} };
	int sum = 0;


	int a_1 = MagicSquareArray3[i][0];
	const char b_1[20];
	sprintf(b_1, "%d", a_1);
	sum += a_1;

	int a_2 = MagicSquareArray3[i][1];
	const char b_2[20];
	sprintf(b_2, "%d", a_2);
	sum += a_2;

	int a_3 = MagicSquareArray3[i][2];
	const char b_3[20];
	sprintf(b_3, "%d", a_3);
	sum += a_3;

	int a_4 = MagicSquareArray3[i][3];
	const char b_4[20];
	sprintf(b_4, "%d", a_4);

	int a_5 = MagicSquareArray3[i][4];
	const char b_5[20];
	sprintf(b_5, "%d", a_5);

	int a_6 = MagicSquareArray3[i][5];
	const char b_6[20];
	sprintf(b_6, "%d", a_6);

	int a_7 = MagicSquareArray3[i][6];
	const char b_7[20];
	sprintf(b_7, "%d", a_7);

	int a_8 = MagicSquareArray3[i][7];
	const char b_8[20];
	sprintf(b_8, "%d", a_8);

	int a_9 = MagicSquareArray3[i][8];
	const char b_9[20];
	sprintf(b_9, "%d", a_9);


	const char b_10[20];
	sprintf(b_10, "%d", sum);


	SendMessageA(__1, WM_SETTEXT, NULL, b_1);
	SendMessageA(__2, WM_SETTEXT, NULL, b_2);
	SendMessageA(__3, WM_SETTEXT, NULL, b_3);
	SendMessageA(__4, WM_SETTEXT, NULL, b_4);
	SendMessageA(__5, WM_SETTEXT, NULL, b_5);
	SendMessageA(__6, WM_SETTEXT, NULL, b_6);
	SendMessageA(__7, WM_SETTEXT, NULL, b_7);
	SendMessageA(__8, WM_SETTEXT, NULL, b_8);
	SendMessageA(__9, WM_SETTEXT, NULL, b_9);
	SendMessageA(magic_sum, WM_SETTEXT, NULL, b_10);

	
	if (i < 6)
		i++;
	else
		i = 0;
	
}


// функція генерації довільного магічного квадрату 4х4
void generate3(HWND hwnd) {
	int m1, m2, m3;
	int sum = 0;

	m1 = rand() % 134 + 1;
	m2 = rand() % 133 + 1;
	m3 = rand() % 144 + 1;
	if (m1 == m2 || m1 == m3)
		m1 = rand() % 134 + 1;
	if (m2 == m3)
		m2 = rand() % 134 + 1;
	int MagicSquareArray3[9];

	MagicSquareArray3[0] = m1 + m2;
	MagicSquareArray3[1] = m1 - (m2 + m3);
	MagicSquareArray3[2] = m1 + m3;
	MagicSquareArray3[3] = m1 - (m2 - m3);
	MagicSquareArray3[4] = m1;
	MagicSquareArray3[5] = m1 + (m2 - m3);
	MagicSquareArray3[6] = m1 - m3;
	MagicSquareArray3[7] = m1 + (m2 + m3);
	MagicSquareArray3[8] = m1 - m2;

	
	int a_1 = MagicSquareArray3[0];
	const char b_1[20];
	sprintf(b_1, "%d", a_1);

	int a_2 = MagicSquareArray3[1];
	const char b_2[20];
	sprintf(b_2, "%d", a_2);

	int a_3 = MagicSquareArray3[2];
	const char b_3[20];
	sprintf(b_3, "%d", a_3);

	int a_4 = MagicSquareArray3[3];
	const char b_4[20];
	sprintf(b_4, "%d", a_4);

	int a_5 = MagicSquareArray3[4];
	const char b_5[20];
	sprintf(b_5, "%d", a_5);

	int a_6 = MagicSquareArray3[5];
	const char b_6[20];
	sprintf(b_6, "%d", a_6);

	int a_7 = MagicSquareArray3[6];
	const char b_7[20];
	sprintf(b_7, "%d", a_7);

	int a_8 = MagicSquareArray3[7];
	const char b_8[20];
	sprintf(b_8, "%d", a_8);

	int a_9 = MagicSquareArray3[8];
	const char b_9[20];
	sprintf(b_9, "%d", a_9);
	
	for (int p = 0; p < 2; p++)
		sum += MagicSquareArray3[p];


	const char b_10[20];
	sprintf(b_10, "%d", sum);


	SendMessageA(__1, WM_SETTEXT, NULL, b_1);
	SendMessageA(__2, WM_SETTEXT, NULL, b_2);
	SendMessageA(__3, WM_SETTEXT, NULL, b_3);
	SendMessageA(__4, WM_SETTEXT, NULL, b_4);
	SendMessageA(__5, WM_SETTEXT, NULL, b_5);
	SendMessageA(__6, WM_SETTEXT, NULL, b_6);
	SendMessageA(__7, WM_SETTEXT, NULL, b_7);
	SendMessageA(__8, WM_SETTEXT, NULL, b_8);
	SendMessageA(__9, WM_SETTEXT, NULL, b_9);
	SendMessageA(magic_sum, WM_SETTEXT, NULL, b_10);


}


// допоміжна функція, що перевіряє, чи є елемент 'a' у списку 'array'
int is_there(int a, int array[], int len) {
	for (int i = 0; i < len; i++)
		if (a == array[i])
			return 1;
	return 0;
}


// допоміжна функція, яка перевіряє, чи утворюють елементи 'array' магічну суму
int check_sum(int array[]) {
	int x_1 = array[0];
	if (x_1 > 16 || x_1 <= 0)
		return 0;
	int x_2 = array[1];
	if (x_2 > 16 || x_2 <= 0)
		return 0;
	int x_3 = array[2];
	if (x_3 > 16 || x_3 <= 0)
		return 0;
	int x_4 = array[3];
	if (x_4 > 16 || x_4 <= 0)
		return 0;
	int x_5 = array[4];
	if (x_5 > 16 || x_5 <= 0)
		return 0;
	int x_6 = array[5];
	if (x_6 > 16 || x_6 <= 0)
		return 0;
	int x_7 = array[6];
	if (x_7 > 16 || x_7 <= 0)
		return 0;
	int x_8 = array[7];
	if (x_8 > 16 || x_8 <= 0)
		return 0;
	int x_9 = array[8];
	if (x_9 > 16 || x_9 <= 0)
		return 0;
	int x_10 = array[9];
	if (x_10 > 16 || x_10 <= 0)
		return 0;
	int x_11 = array[10];
	if (x_11 > 16 || x_11 <= 0)
		return 0;
	int x_12 = array[11];
	if (x_12 > 16 || x_12 <= 0)
		return 0;
	int x_13 = array[12];
	if (x_13 > 16 || x_13 <= 0)
		return 0;
	int x_14 = array[13];
	if (x_14 > 16 || x_14 <= 0)
		return 0;
	int x_15 = array[14];
	if (x_15 > 16 || x_15 <= 0)
		return 0;
	int x_16 = array[15];
	if (x_16 > 16 || x_16 <= 0)
		return 0;
	if ((x_1 + x_2 + x_3 + x_4 == 34) && (x_5 + x_6 + x_7 + x_8 == 34) && (x_9 + x_10 + x_11 + x_12 == 34) && (x_1 + x_5 + x_9 + x_13 == 34) && (x_2 + x_6 + x_10 + x_14 == 34) && (x_3 + x_7 + x_11 + x_15 == 34)
		&& (x_4 + x_8 + x_12 + x_16 == 34) && (x_1 + x_6 + x_11 + x_16 == 34) && (x_4 + x_7 + x_10 + x_13 == 34))
		return 1;
	else
		return 0;
}


// функція, що утворює нормальний магічний квадрат 4х4
void generate4_normal(HWND hwnd) {
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int array[16];
	int x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, x_10, x_11, x_12, x_13, x_14, x_15, x_16;
	int permutation[8];
	int j;
	

	do {

		j = 0;

		x_1 = rand() % 15 + 1;
		permutation[j] = x_1;
		array[0] = x_1;
		j++;


		do {
			x_2 = rand() % 15 + 1;
		} while (is_there(x_2, permutation, 8));
		permutation[j] = x_2;
		array[1] = x_2;
		j++;

		do {
			x_3 = rand() % 15 + 1;
		} while (is_there(x_3, permutation, 8));
		permutation[j] = x_3;
		array[2] = x_3;
		j++;

		do {
			x_5 = rand() % 15 + 1;
		} while (is_there(x_5, permutation, 8));
		permutation[j] = x_5;
		array[4] = x_5;
		j++;

		do {
			x_6 = rand() % 15 + 1;
		} while (is_there(x_6, permutation, 8));
		permutation[j] = x_6;
		array[5] = x_6;
		j++;

		do {
			x_7 = rand() % 15 + 1;
		} while (is_there(x_7, permutation, 8));
		permutation[j] = x_7;
		array[6] = x_7;
		j++;

		do {
			x_9 = rand() % 15 + 1;
		} while (is_there(x_9, permutation, 8));
		permutation[j] = x_9;
		array[8] = x_9;
		j++;

		x_4 = 34 - x_1 - x_2 - x_3;
		if (is_there(x_4, array, j + 1))
			continue;
		j++;
		array[3] = x_4;

		x_8 = 34 - x_5 - x_6 - x_7;
		if (is_there(x_8, array, j + 1))
			continue;
		j++;
		array[7] = x_8;

		x_10 = x_1 + x_5 + x_9 - x_4 - x_7;
		if (is_there(x_10, array, j + 1))
			continue;
		j++;
		array[9] = x_10;

		x_11 = (2 * x_4 + x_7 + x_8 - 2 * x_1 - x_5 - x_6 - 2 * x_9 + 34) / 2;
		if (is_there(x_11, array, j + 1))
			continue;
		j++; 
		array[10] = x_11;

		x_12 = x_1 + x_6 + x_11 - x_4 - x_8;
		if (is_there(x_12, array, j + 1))
			continue;
		j++;
		array[11] = x_12;

		x_13 = 34 - x_1 - x_5 - x_9;
		if (is_there(x_13, array, j + 1))
			continue;
		j++;
		array[12] = x_13;

		x_14 = 34 - x_2 - x_6 - x_10;
		if (is_there(x_14, array, j + 1))
			continue;
		j++;
		array[13] = x_14;

		x_15 = 34 - x_3 - x_7 - x_11;
		if (is_there(x_15, array, j + 1))
			continue;
		j++;
		array[14] = x_15;

		x_16 = 34 - x_4 - x_8 - x_12;
		if (is_there(x_16, array, j + 1))
			continue;
		j++;
		array[15] = x_16;

	} while (!(check_sum(array)));

	const char b_1[20];
	sprintf(b_1, "%d", x_1);

	const char b_2[20];
	sprintf(b_2, "%d", x_2);

	const char b_3[20];
	sprintf(b_3, "%d", x_3);

	const char b_4[20];
	sprintf(b_4, "%d", x_4);

	const char b_5[20];
	sprintf(b_5, "%d", x_5);

	const char b_6[20];
	sprintf(b_6, "%d", x_6);

	const char b_7[20];
	sprintf(b_7, "%d", x_7);

	const char b_8[20];
	sprintf(b_8, "%d", x_8);

	const char b_9[20];
	sprintf(b_9, "%d", x_9);

	const char b_10[20];
	sprintf(b_10, "%d", x_10);

	const char b_11[20];
	sprintf(b_11, "%d", x_11);

	const char b_12[20];
	sprintf(b_12, "%d", x_12);

	const char b_13[20];
	sprintf(b_13, "%d", x_13);

	const char b_14[20];
	sprintf(b_14, "%d", x_14);

	const char b_15[20];
	sprintf(b_15, "%d", x_15);

	const char b_16[20];
	sprintf(b_16, "%d", x_16);


	int sum = x_1 + x_2 + x_3 + x_4;
	const char b_sum[20];
	sprintf(b_sum, "%d", sum);


	SendMessageA(_1, WM_SETTEXT, NULL, b_1);
	SendMessageA(_2, WM_SETTEXT, NULL, b_2);
	SendMessageA(_3, WM_SETTEXT, NULL, b_3);
	SendMessageA(_4, WM_SETTEXT, NULL, b_4);
	SendMessageA(_5, WM_SETTEXT, NULL, b_5);
	SendMessageA(_6, WM_SETTEXT, NULL, b_6);
	SendMessageA(_7, WM_SETTEXT, NULL, b_7);
	SendMessageA(_8, WM_SETTEXT, NULL, b_8);
	SendMessageA(_9, WM_SETTEXT, NULL, b_9);
	SendMessageA(_10, WM_SETTEXT, NULL, b_10);
	SendMessageA(_11, WM_SETTEXT, NULL, b_11);
	SendMessageA(_12, WM_SETTEXT, NULL, b_12);
	SendMessageA(_13, WM_SETTEXT, NULL, b_13);
	SendMessageA(_14, WM_SETTEXT, NULL, b_14);
	SendMessageA(_15, WM_SETTEXT, NULL, b_15);
	SendMessageA(_16, WM_SETTEXT, NULL, b_16);
	SendMessageA(magic_sum, WM_SETTEXT, NULL, b_sum);


}


// функція утворення довільного магічного квадрату 4х4
void generate4(HWND hwnd) {
	srand(time(NULL));

	int x_1, x_2, x_3, x_4, x_5;

	x_1 = rand() % 64 + 4;

	do {
		x_2 = rand() % 64 + 4;
	} while (x_2 == x_1);

	do {
		x_3 = rand() % 64 + 4;
	} while (x_3 == x_1 || x_3 == x_2);

	do {
		x_4 = rand() % 64 + 4;
	} while (x_4 == x_1 || x_4 == x_2 || x_4 == x_3);

	do {
		x_5 = rand() % 64 + 4;
	} while (x_5 == x_1 || x_5 == x_2 || x_5 == x_3 || x_5 == x_4);


	int a_1 = x_1;
	const char b_1[20];
	sprintf(b_1, "%d", a_1);

	int a_2 = x_1 + x_2 + x_3 + x_5;
	const char b_2[20];
	sprintf(b_2, "%d", a_2);

	int a_3 = x_1 + x_3 + x_4;
	const char b_3[20];
	sprintf(b_3, "%d", a_3);

	int a_4 = x_1 + x_2 + x_4 + x_5;
	const char b_4[20];
	sprintf(b_4, "%d", a_4);

	int a_5 = x_1 + x_2 + x_3 + x_4;
	const char b_5[20];
	sprintf(b_5, "%d", a_5);

	int a_6 = x_1 + x_4 + x_5;
	const char b_6[20];
	sprintf(b_6, "%d", a_6);

	int a_7 = x_1 + x_2;
	const char b_7[20];
	sprintf(b_7, "%d", a_7);

	int a_8 = x_1 + x_3 + x_5;
	const char b_8[20];
	sprintf(b_8, "%d", a_8);

	int a_9 = x_1 + x_2 + x_5;
	const char b_9[20];
	sprintf(b_9, "%d", a_9);

	int a_10 = x_1 + x_3;
	const char b_10[20];
	sprintf(b_10, "%d", a_10);

	int a_11 = x_1 + x_2 + x_3 + x_4 + x_5;
	const char b_11[20];
	sprintf(b_11, "%d", a_11);

	int a_12 = x_1 + x_4;
	const char b_12[20];
	sprintf(b_12, "%d", a_12);

	int a_13 = x_1 + x_3 + x_4 + x_5;
	const char b_13[20];
	sprintf(b_13, "%d", a_13);

	int a_14 = x_1 + x_2 + x_4;
	const char b_14[20];
	sprintf(b_14, "%d", a_14);

	int a_15 = x_1 + x_5;
	const char b_15[20];
	sprintf(b_15, "%d", a_15);

	int a_16 = x_1 + x_2 + x_3;
	const char b_16[20];
	sprintf(b_16, "%d", a_16);

	int sum = a_4 + a_2 + a_3 + a_1;
	const char b_sum[20];
	sprintf(b_sum, "%d", sum);

	SendMessageA(_1, WM_SETTEXT, NULL, b_1);
	SendMessageA(_2, WM_SETTEXT, NULL, b_2);
	SendMessageA(_3, WM_SETTEXT, NULL, b_3);
	SendMessageA(_4, WM_SETTEXT, NULL, b_4);
	SendMessageA(_5, WM_SETTEXT, NULL, b_5);
	SendMessageA(_6, WM_SETTEXT, NULL, b_6);
	SendMessageA(_7, WM_SETTEXT, NULL, b_7);
	SendMessageA(_8, WM_SETTEXT, NULL, b_8);
	SendMessageA(_9, WM_SETTEXT, NULL, b_9);
	SendMessageA(_10, WM_SETTEXT, NULL, b_10);
	SendMessageA(_11, WM_SETTEXT, NULL, b_11);
	SendMessageA(_12, WM_SETTEXT, NULL, b_12);
	SendMessageA(_13, WM_SETTEXT, NULL, b_13);
	SendMessageA(_14, WM_SETTEXT, NULL, b_14);
	SendMessageA(_15, WM_SETTEXT, NULL, b_15);
	SendMessageA(_16, WM_SETTEXT, NULL, b_16);
	SendMessageA(magic_sum, WM_SETTEXT, NULL, b_sum);


}


// функція очищення вікна після роботи з магічним квадратом 3х3
void Destroy3(void) {
	DestroyWindow(__1);
	DestroyWindow(__2);
	DestroyWindow(__3);
	DestroyWindow(__4);
	DestroyWindow(__5);
	DestroyWindow(__6);
	DestroyWindow(__7);
	DestroyWindow(__8);
	DestroyWindow(__9);
	DestroyWindow(generate_3);
	DestroyWindow(generate_3_normal);
	DestroyWindow(close_3);
	DestroyWindow(_title);
	DestroyWindow(magic_sum);
	DestroyWindow(magic_sum_title);
}


// функція очищення вікна після роботи з магічним квадратом 4х4
void Destroy4(void) {
	DestroyWindow(_1);
	DestroyWindow(_2);
	DestroyWindow(_3);
	DestroyWindow(_4);
	DestroyWindow(_5);
	DestroyWindow(_6);
	DestroyWindow(_7);
	DestroyWindow(_8);
	DestroyWindow(_9);
	DestroyWindow(_10);
	DestroyWindow(_11);
	DestroyWindow(_12);
	DestroyWindow(_13);
	DestroyWindow(_14);
	DestroyWindow(_15);
	DestroyWindow(_16);
	DestroyWindow(generate_4);
	DestroyWindow(generate_4_normal);
	DestroyWindow(close_4);
	DestroyWindow(__title);
	DestroyWindow(_title);
	DestroyWindow(magic_sum_title);
	DestroyWindow(magic_sum);
}


// функція створення вікна для роботи з магічними квадратами 4х4
void create4(HWND hwnd) {
	
	_1 = CreateWindowW(L"Button", "1", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 180, 120, 40, 40, hwnd, NULL, NULL, NULL);
	_2 = CreateWindowW(L"Button", "2", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 260, 120, 40, 40, hwnd, NULL, NULL, NULL);
	_3 = CreateWindowW(L"Button", "3", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 340, 120, 40, 40, hwnd, NULL, NULL, NULL);
	_4 = CreateWindowW(L"Button", "4", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 420, 120, 40, 40, hwnd, NULL, NULL, NULL);
	_5 = CreateWindowW(L"Button", "5", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 180, 190, 40, 40, hwnd, NULL, NULL, NULL);
	_6 = CreateWindowW(L"Button", "6", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 260, 190, 40, 40, hwnd, NULL, NULL, NULL);
	_7 = CreateWindowW(L"Button", "7", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 340, 190, 40, 40, hwnd, NULL, NULL, NULL);
	_8 = CreateWindowW(L"Button", "8", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 420, 190, 40, 40, hwnd, NULL, NULL, NULL);
	_9 = CreateWindowW(L"Button", "9", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 180, 260, 40, 40, hwnd, NULL, NULL, NULL);
	_10 = CreateWindowW(L"Button", L"10", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 260, 260, 40, 40, hwnd, NULL, NULL, NULL);
	_11 = CreateWindowW(L"Button", L"11", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 340, 260, 40, 40, hwnd, NULL, NULL, NULL);
	_12 = CreateWindowW(L"Button", L"12", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 420, 260, 40, 40, hwnd, NULL, NULL, NULL);
	_13 = CreateWindowW(L"Button", L"13", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 180, 330, 40, 40, hwnd, NULL, NULL, NULL);
	_14 = CreateWindowW(L"Button", L"14", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 260, 330, 40, 40, hwnd, NULL, NULL, NULL);
	_15 = CreateWindowW(L"Button", L"15", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 340, 330, 40, 40, hwnd, NULL, NULL, NULL);
	_16 = CreateWindowW(L"Button", L"16", WS_TABSTOP | BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 420, 330, 40, 40, hwnd, NULL, NULL, NULL);

	magic_sum_title = CreateWindowA("Static", "Magic sum is - ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 270, 390, 94, 20, hwnd, NULL, NULL, NULL);
	magic_sum = CreateWindowA("Static", "", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 366, 390, 26, 20, hwnd, NULL, NULL, NULL);

	generate_4 = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Generate.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		250,         // x position 
		440,         // y position 
		140,        // Button width
		40,        // Button height
		hwnd,     // Parent window
		(HMENU)GENERATE_BTN_4,
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);      // Pointer not needed.);

	generate_4_normal = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Generate normal.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		100,         // x position 
		440,         // y position 
		140,        // Button width
		40,        // Button height
		hwnd,     // Parent window
		(HMENU)GENERATE_BTN_4_NORMAL,
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);      // Pointer not needed.);


	close_4 = CreateWindowW(
		L"Button",  // Predefined class; Unicode assumed 
		L"Close.",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		400,         // x position 
		440,         // y position 
		140,        // Button width
		40,        // Button height
		hwnd,     // Parent window
		(HMENU)CLOSE_BTN_4,
		(HINSTANCE)GetModuleHandle(NULL),
		NULL);
}


// функція оброблення екрану й вводу/виводу
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	
	switch (msg) {
	case WM_CREATE:
		hFont = (HFONT)CreateFontA(25,
			10,
			NULL,
			NULL,
			FW_THIN,
			0,
			0,
			0,
			ANSI_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			CLEARTYPE_QUALITY,
			FF_DECORATIVE,
			"Marina");
		hFont2 = (HFONT)CreateFontA(44,
			17,
			NULL,
			NULL,
			FW_THIN,
			0,
			0,
			0,
			ANSI_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			CLEARTYPE_QUALITY,
			FF_DECORATIVE,
			"Marina2");
		AddMenu(hwnd);		
		break;

	case WM_CTLCOLORSTATIC:
	{
		HDC hdcStatic = (HDC)wp;
		SetTextColor(hdcStatic, RGB(255, 255, 255));
		SetBkColor(hdcStatic, RGB(21, 191, 234));

		if (hbrBkgnd == NULL)
		{
			hbrBkgnd = CreateSolidBrush(RGB(21, 191, 234));
		}
		return (INT_PTR)hbrBkgnd;
	}

	case WM_DRAWITEM:
	{
		DRAWITEMSTRUCT* dis = (DRAWITEMSTRUCT*)lp;
		return TRUE;
	}

	case WM_COMMAND:
		switch (wp) {

		// magic 3x3 block
		case CREATE_MAGIC_3_BTN:
			create3(hwnd);
			break;

		case GENERATE_BTN_3:
			generate3(hwnd);
			break;

		case GENERATE_BTN_3_NORMAL:
			generate3_normal(hwnd);
			break;

		case CLOSE_BTN_3:
			Destroy3();
			break;
		// end of block

		// magic 4x4 block
		case CREATE_MAGIC_4_BTN:
			create4(hwnd);
			break;

		case GENERATE_BTN_4:
			generate4(hwnd);
			break;

		case GENERATE_BTN_4_NORMAL:
			generate4_normal(hwnd);
			break;

		case CLOSE_BTN_4:
			Destroy4();
			break;
		// end of block
		
		case QUIT_BTN:
			DestroyWindow(hwnd);
			break;

		
		}

			
		
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		DefWindowProc(hwnd, msg, wp, lp);
	}
}


// головна функція роботи з winapi
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	WNDCLASSW wc = { 0 };

	// window color
	HBRUSH wind_color = CreateSolidBrush(RGB(21, 191, 234));

	//Step 1: Registering the Window Class
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)wind_color;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"myWindowClass";

	if (!RegisterClass(&wc))
		return -1;

	hMainWindow = CreateWindow(
		L"myWindowClass",
		"Main Window",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		640, 220,
		940, 640,
		NULL, NULL, NULL, NULL
	);

	MSG msg;

	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
