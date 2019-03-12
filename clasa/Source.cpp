#include <windows.h>
#include <windowsx.h>
#include <string>
#include "player.cpp"

using namespace std;

int x = 100;
int y = 100;
int z = 700;
int w = 100;
int contor = 0;
int contor2 = 0;
int contorXY = 0;

HWND hwnd;
HWND hDisplay;
void addControls(HWND hwnd);
void addPics();
HWND player1;
HWND player1bis;
HWND player2;
HWND player2bis;
HWND impact;
HBITMAP hplayer1;
HBITMAP hplayer2;
HBITMAP hplayer1bis;
HBITMAP hplayer2bis;
HBITMAP himpact;

HWND EditP1;
HWND EditP2;
HWND Button1;

HWND hDisplayP11x;
HWND hDisplayP12x;
HWND hDisplayP13x;
HWND hDisplayP14x;
HWND hDisplayP15x;
HWND hDisplayP16x;
HWND hDisplayP17x;
HWND hDisplayP18x;
HWND hDisplayP19x;
HWND hDisplayP110x;
HWND hDisplayP21x;
HWND hDisplayP22x;
HWND hDisplayP23x;
HWND hDisplayP24x;
HWND hDisplayP25x;
HWND hDisplayP26x;
HWND hDisplayP27x;
HWND hDisplayP28x;
HWND hDisplayP29x;
HWND hDisplayP210x;
HWND hDisplayP11y;
HWND hDisplayP12y;
HWND hDisplayP13y;
HWND hDisplayP14y;
HWND hDisplayP15y;
HWND hDisplayP16y;
HWND hDisplayP17y;
HWND hDisplayP18y;
HWND hDisplayP19y;
HWND hDisplayP110y;
HWND hDisplayP21y;
HWND hDisplayP22y;
HWND hDisplayP23y;
HWND hDisplayP24y;
HWND hDisplayP25y;
HWND hDisplayP26y;
HWND hDisplayP27y;
HWND hDisplayP28y;
HWND hDisplayP29y;
HWND hDisplayP210y;
HWND hDisplayContor;
HWND hDisplayContorStatic;

HWND p1x;
HWND p1y;
HWND p2x;
HWND p2y;

int verificaTouch();

player p1;
player p2;


LRESULT CALLBACK WndProc(HWND hwnd, UINT messages, WPARAM wParam, LPARAM lParam)
{
	switch (messages)
	{
	case WM_CLOSE:
	{
		DestroyWindow(hwnd);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	case WM_CREATE:
	{
		addPics();
		addControls(hwnd);
		verificaTouch();
	}

	/*case WM_COMMAND:
	switch (wParam)
	{
	case 1:

	}*/

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			p1.x = p1.x - 10;
			contor++;
			if (verificaTouch() == 0)
				//SendMessage(impact, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)himpact);
				contorXY++;
			if (contor % 2 == 0)
			{
				SendMessage(player1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1);
				MoveWindow(player1, p1.x, p1.y, p1.lungime, p1.latime, TRUE);

			}
			else
			{
				SendMessage(player1bis, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1bis);
				MoveWindow(player1bis, p1.x, p1.y, p1.lungime, p1.latime, TRUE);
			}
			p1.logare(p1.lungime, p1.latime, p1.x, p1.y);
			char bufferL[10];
			_itoa_s(p1.logPozx[0], bufferL, 10);
			SetWindowText(hDisplayP11x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[1], bufferL, 10);
			SetWindowText(hDisplayP12x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[2], bufferL, 10);
			SetWindowText(hDisplayP13x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[3], bufferL, 10);
			SetWindowText(hDisplayP14x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[4], bufferL, 10);
			SetWindowText(hDisplayP15x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[5], bufferL, 10);
			SetWindowText(hDisplayP16x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[6], bufferL, 10);
			SetWindowText(hDisplayP17x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[7], bufferL, 10);
			SetWindowText(hDisplayP18x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[8], bufferL, 10);
			SetWindowText(hDisplayP19x, (LPCSTR)bufferL);
			_itoa_s(p1.logPozx[9], bufferL, 10);
			SetWindowText(hDisplayP110x, (LPCSTR)bufferL);

			_itoa_s(contorXY, bufferL, 10);
			SetWindowText(hDisplayContor, (LPCSTR)bufferL);
			break;
			
		case VK_RIGHT:
			p1.x = p1.x + 10;
			contor++;
			if (verificaTouch() == 0)
				//SendMessage(impact, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)himpact);
				contorXY++;
			if (contor % 2 == 0)
			{
				SendMessage(player1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1);
				MoveWindow(player1, p1.x, p1.y, p1.lungime, p1.latime, TRUE);
			}
			else
			{
				SendMessage(player1bis, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1bis);
				MoveWindow(player1bis, p1.x, p1.y, p1.lungime, p1.latime, TRUE);
			}
			p1.logare(p1.lungime, p1.latime, p1.x, p1.y);
			char bufferR[10];
			_itoa_s(p1.logPozx[0], bufferR, 10);
			SetWindowText(hDisplayP11x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[1], bufferR, 10);
			SetWindowText(hDisplayP12x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[2], bufferR, 10);
			SetWindowText(hDisplayP13x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[3], bufferR, 10);
			SetWindowText(hDisplayP14x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[4], bufferR, 10);
			SetWindowText(hDisplayP15x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[5], bufferR, 10);
			SetWindowText(hDisplayP16x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[6], bufferR, 10);
			SetWindowText(hDisplayP17x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[7], bufferR, 10);
			SetWindowText(hDisplayP18x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[8], bufferR, 10);
			SetWindowText(hDisplayP19x, (LPCSTR)bufferR);
			_itoa_s(p1.logPozx[9], bufferR, 10);
			SetWindowText(hDisplayP110x, (LPCSTR)bufferR);

			_itoa_s(contorXY, bufferR, 10);
			SetWindowText(hDisplayContor, (LPCSTR)bufferR);

			break;

		case VK_UP:
			p1.y = p1.y - 10;
			contor++;
			if (verificaTouch() == 0)
				//SendMessage(impact, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)himpact);
				contorXY++;
			if (contor % 2 == 0)
			{
				SendMessage(player1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1);
				MoveWindow(player1, p1.x, p1.y, p1.lungime, p1.latime, TRUE);
			}
			else
			{
				SendMessage(player1bis, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1bis);
				MoveWindow(player1bis, p1.x, p1.y, p1.lungime, p1.latime, TRUE);
			}
			p1.logare(p1.lungime, p1.latime, p1.x, p1.y);
			char bufferU[10];
			_itoa_s(p1.logPozy[0], bufferU, 10);
			SetWindowText(hDisplayP11y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[1], bufferU, 10);
			SetWindowText(hDisplayP12y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[2], bufferU, 10);
			SetWindowText(hDisplayP13y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[3], bufferU, 10);
			SetWindowText(hDisplayP14y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[4], bufferU, 10);
			SetWindowText(hDisplayP15y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[5], bufferU, 10);
			SetWindowText(hDisplayP16y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[6], bufferU, 10);
			SetWindowText(hDisplayP17y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[7], bufferU, 10);
			SetWindowText(hDisplayP18y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[8], bufferU, 10);
			SetWindowText(hDisplayP19y, (LPCSTR)bufferU);
			_itoa_s(p1.logPozy[9], bufferU, 10);
			SetWindowText(hDisplayP110y, (LPCSTR)bufferU);

			_itoa_s(contorXY, bufferU, 10);
			SetWindowText(hDisplayContor, (LPCSTR)bufferU);

			break;

		case VK_DOWN:
			p1.y = p1.y + 10;
			contor++;
			if (verificaTouch() == 0)
				//SendMessage(impact, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)himpact);
				contorXY++;
			if (contor % 2 == 0)
			{
				SendMessage(player1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1);
				MoveWindow(player1, p1.x, p1.y, p1.lungime, p1.latime, TRUE);
			}
			else
			{
				SendMessage(player1bis, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1bis);
				MoveWindow(player1bis, p1.x, p1.y, p1.lungime, p1.latime, TRUE);
			}
			p1.logare(p1.lungime, p1.latime, p1.x, p1.y);
			char bufferD[10];
			_itoa_s(p1.logPozy[0], bufferD, 10);
			SetWindowText(hDisplayP11y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[1], bufferD, 10);
			SetWindowText(hDisplayP12y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[2], bufferD, 10);
			SetWindowText(hDisplayP13y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[3], bufferD, 10);
			SetWindowText(hDisplayP14y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[4], bufferD, 10);
			SetWindowText(hDisplayP15y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[5], bufferD, 10);
			SetWindowText(hDisplayP16y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[6], bufferD, 10);
			SetWindowText(hDisplayP17y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[7], bufferD, 10);
			SetWindowText(hDisplayP18y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[8], bufferD, 10);
			SetWindowText(hDisplayP19y, (LPCSTR)bufferD);
			_itoa_s(p1.logPozy[9], bufferD, 10);
			SetWindowText(hDisplayP110y, (LPCSTR)bufferD);

			_itoa_s(contorXY, bufferD, 10);
			SetWindowText(hDisplayContor, (LPCSTR)bufferD);

			break;

		case VK_NUMPAD4:
			p2.x = p2.x - 10;
			contor2++;
			if (verificaTouch() == 0)
				//SendMessage(impact, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)himpact);
				contorXY++;
			if (contor2 % 2 == 0)
			{
				SendMessage(player2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2);
				MoveWindow(player2, p2.x, p2.y, p2.lungime, p2.latime, TRUE);
			}
			else
			{
				SendMessage(player2bis, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2bis);
				MoveWindow(player2bis, p2.x, p2.y, p2.lungime, p2.latime, TRUE);
			}
			p2.logare(p2.lungime, p2.latime, p2.x, p2.y);

			char bufferL2[10];
			_itoa_s(p2.logPozx[0], bufferL2, 10);
			SetWindowText(hDisplayP21x, (LPSTR)bufferL2);
			_itoa_s(p2.logPozx[1], bufferL2, 10);
			SetWindowText(hDisplayP22x, (LPCSTR)bufferL2);
			_itoa_s(p2.logPozx[2], bufferL2, 10);
			SetWindowText(hDisplayP23x, (LPCSTR)bufferL2);
			_itoa_s(p2.logPozx[3], bufferL2, 10);
			SetWindowText(hDisplayP24x, (LPCSTR)bufferL2);
			_itoa_s(p2.logPozx[4], bufferL2, 10);
			SetWindowText(hDisplayP25x, (LPCSTR)bufferL2);
			_itoa_s(p2.logPozx[5], bufferL2, 10);
			SetWindowText(hDisplayP26x, (LPCSTR)bufferL2);
			_itoa_s(p2.logPozx[6], bufferL2, 10);
			SetWindowText(hDisplayP27x, (LPCSTR)bufferL2);
			_itoa_s(p2.logPozx[7], bufferL2, 10);
			SetWindowText(hDisplayP28x, (LPCSTR)bufferL2);
			_itoa_s(p2.logPozx[8], bufferL2, 10);
			SetWindowText(hDisplayP29x, (LPCSTR)bufferL2);
			_itoa_s(p2.logPozx[9], bufferL2, 10);
			SetWindowText(hDisplayP210x, (LPCSTR)bufferL2);

			_itoa_s(contorXY, bufferL2, 10);
			SetWindowText(hDisplayContor, (LPCSTR)bufferL2);

			break;

		case VK_NUMPAD6:
			p2.x = p2.x + 10;
			contor2++;
			if (verificaTouch() == 0)
				//SendMessage(impact, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)himpact);
				contorXY++;
			if (contor2 % 2 == 0)
			{
				SendMessage(player2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2);
				MoveWindow(player2, p2.x, p2.y, p2.lungime, p2.latime, TRUE);
			}
			else
			{
				SendMessage(player2bis, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2bis);
				MoveWindow(player2bis, p2.x, p2.y, p2.lungime, p2.latime, TRUE);
			}
			p2.logare(p2.lungime, p2.latime, p2.x, p2.y);
			char bufferR2[10];
			_itoa_s(p2.logPozx[0], bufferR2, 10);
			SetWindowText(hDisplayP21x, (LPSTR)bufferR2);
			_itoa_s(p2.logPozx[1], bufferR2, 10);
			SetWindowText(hDisplayP22x, (LPCSTR)bufferR2);
			_itoa_s(p2.logPozx[2], bufferR2, 10);
			SetWindowText(hDisplayP23x, (LPCSTR)bufferR2);
			_itoa_s(p2.logPozx[3], bufferR2, 10);
			SetWindowText(hDisplayP24x, (LPCSTR)bufferR2);
			_itoa_s(p2.logPozx[4], bufferR2, 10);
			SetWindowText(hDisplayP25x, (LPCSTR)bufferR2);
			_itoa_s(p2.logPozx[5], bufferR2, 10);
			SetWindowText(hDisplayP26x, (LPCSTR)bufferR2);
			_itoa_s(p2.logPozx[6], bufferR2, 10);
			SetWindowText(hDisplayP27x, (LPCSTR)bufferR2);
			_itoa_s(p2.logPozx[7], bufferR2, 10);
			SetWindowText(hDisplayP28x, (LPCSTR)bufferR2);
			_itoa_s(p2.logPozx[8], bufferR2, 10);
			SetWindowText(hDisplayP29x, (LPCSTR)bufferR2);
			_itoa_s(p2.logPozx[9], bufferR2, 10);
			SetWindowText(hDisplayP210x, (LPCSTR)bufferR2);

			_itoa_s(contorXY, bufferR2, 10);
			SetWindowText(hDisplayContor, (LPCSTR)bufferR2);

			break;
		case VK_NUMPAD8:
			p2.y = p2.y - 10;
			contor2++;
			if (verificaTouch() == 0)
				//SendMessage(impact, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)himpact);
				contorXY++;
			if (contor2 % 2 == 0)
			{
				SendMessage(player2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2);
				MoveWindow(player2, p2.x, p2.y, p2.lungime, p2.latime, TRUE);
			}
			else
			{
				SendMessage(player2bis, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2bis);
				MoveWindow(player2bis, p2.x, p2.y, p2.lungime, p2.latime, TRUE);
			}
			p2.logare(p2.lungime, p2.latime, p2.x, p2.y);
			
			char bufferU2[10];
			_itoa_s(p2.logPozy[0], bufferU2, 10);
			SetWindowText(hDisplayP21y, (LPSTR)bufferU2);
			_itoa_s(p2.logPozy[1], bufferU2, 10);
			SetWindowText(hDisplayP22y, (LPCSTR)bufferU2);
			_itoa_s(p2.logPozy[2], bufferU2, 10);
			SetWindowText(hDisplayP23y, (LPCSTR)bufferU2);
			_itoa_s(p2.logPozy[3], bufferU2, 10);
			SetWindowText(hDisplayP24y, (LPCSTR)bufferU2);
			_itoa_s(p2.logPozy[4], bufferU2, 10);
			SetWindowText(hDisplayP25y, (LPCSTR)bufferU2);
			_itoa_s(p2.logPozy[5], bufferU2, 10);
			SetWindowText(hDisplayP26y, (LPCSTR)bufferU2);
			_itoa_s(p2.logPozy[6], bufferU2, 10);
			SetWindowText(hDisplayP27y, (LPCSTR)bufferU2);
			_itoa_s(p2.logPozy[7], bufferU2, 10);
			SetWindowText(hDisplayP28y, (LPCSTR)bufferU2);
			_itoa_s(p2.logPozy[8], bufferU2, 10);
			SetWindowText(hDisplayP29y, (LPCSTR)bufferU2);
			_itoa_s(p2.logPozy[9], bufferU2, 10);
			SetWindowText(hDisplayP210y, (LPCSTR)bufferU2);

			_itoa_s(contorXY, bufferU2, 10);
			SetWindowText(hDisplayContor, (LPCSTR)bufferU2);

			break;
		case VK_NUMPAD2:
			p2.y = p2.y + 10;
			contor2++;
			if (verificaTouch() == 0)
				//SendMessage(impact, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)himpact);
				contorXY++;
			if (contor2 % 2 == 0)
			{
				SendMessage(player2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2);
				MoveWindow(player2, p2.x, p2.y, p2.lungime, p2.latime, TRUE);
			}
			else
			{
				SendMessage(player2bis, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2bis);
				MoveWindow(player2bis, p2.x, p2.y, p2.lungime, p2.latime, TRUE);
			}
			p2.logare(p2.lungime, p2.latime, p2.x, p2.y);

			char bufferD2[10];
			_itoa_s(p2.logPozy[0], bufferD2, 10);
			SetWindowText(hDisplayP21y, (LPSTR)bufferD2);
			_itoa_s(p2.logPozy[1], bufferD2, 10);
			SetWindowText(hDisplayP22y, (LPCSTR)bufferD2);
			_itoa_s(p2.logPozy[2], bufferD2, 10);
			SetWindowText(hDisplayP23y, (LPCSTR)bufferD2);
			_itoa_s(p2.logPozy[3], bufferD2, 10);
			SetWindowText(hDisplayP24y, (LPCSTR)bufferD2);
			_itoa_s(p2.logPozy[4], bufferD2, 10);
			SetWindowText(hDisplayP25y, (LPCSTR)bufferD2);
			_itoa_s(p2.logPozy[5], bufferD2, 10);
			SetWindowText(hDisplayP26y, (LPCSTR)bufferD2);
			_itoa_s(p2.logPozy[6], bufferD2, 10);
			SetWindowText(hDisplayP27y, (LPCSTR)bufferD2);
			_itoa_s(p2.logPozy[7], bufferD2, 10);
			SetWindowText(hDisplayP28y, (LPCSTR)bufferD2);
			_itoa_s(p2.logPozy[8], bufferD2, 10);
			SetWindowText(hDisplayP29y, (LPCSTR)bufferD2);
			_itoa_s(p2.logPozy[9], bufferD2, 10);
			SetWindowText(hDisplayP210y, (LPCSTR)bufferD2);

			_itoa_s(contorXY, bufferD2, 10);
			SetWindowText(hDisplayContor, (LPCSTR)bufferD2);

			break;

		case VK_HOME:
			int d;
			d = MessageBox(hwnd, "Doriti sa modificati dimensiunile pentru player1?", " ", MB_YESNO);
			if (d == 6)
			{
				CreateWindowExA(0, "static", " Noua Latime = ", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 700, 120, 25, hwnd, NULL, NULL, NULL);
				EditP1 = CreateWindowExA(0, "edit", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 140, 700, 50, 25, hwnd, NULL, NULL, NULL);
				CreateWindowExA(0, "static", " Noua Lungime = ", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 730, 120, 25, hwnd, NULL, NULL, NULL);
				EditP1 = CreateWindowExA(0, "edit", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 140, 730, 50, 25, hwnd, NULL, NULL, NULL);
				Button1 = CreateWindow("button", "Schimba", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 200, 700, 70, 58, hwnd, (HMENU)1, NULL, NULL);
			}
		}
	default:
		return DefWindowProc(hwnd, messages, wParam, lParam);
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrev, LPSTR lpszArgument, int nCmdShow)
{
	// START REGISTER Window Class - Pas 1
	char szClassName[] = "Serkan";
	WNDCLASSEX wc;
	MSG messages;
	HWND hwnd;



	wc.hInstance = hIns;
	wc.lpszClassName = szClassName, wc.lpfnWndProc = WndProc;
	wc.style = CS_DBLCLKS, wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION), wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW), wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0, wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	RegisterClassEx(&wc);

	// STOP register Window Class - Pas 1

	// START Creare Fereastra Propriu Zisa si Afisare - Pas 2
	hwnd = CreateWindow(szClassName, szClassName, WS_OVERLAPPEDWINDOW, 10, 0, 1350, 1000, HWND_DESKTOP, NULL, hIns, NULL);
	ShowWindow(hwnd, nCmdShow);


	// STOP Creare Fereastra Propriu Zisa si Afisare - Pas 2

	// START Coada de asteptare mesaje - Pas 3
	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	// STOP Coada de asteptare mesaje - Pas 3

	return messages.wParam;
}

void addControls(HWND hwnd)
{

	p1.x = 100;
	p1.y = 100;
	p1.lungime = 100;
	p1.latime = 100;

	p2.x = 700;
	p2.y = 100;
	p2.lungime = 100;
	p2.latime = 100;

	hDisplay = CreateWindowEx(0, "static", "Catch me game!", WS_VISIBLE | WS_CHILD | WS_BORDER, 70, 50, 760, 600, hwnd, NULL, NULL, NULL);
	player1 = CreateWindowEx(0, "static", "Catch me game!", WS_VISIBLE | WS_CHILD | SS_BITMAP, p1.x, p1.y, p1.lungime, p1.latime, hwnd, NULL, NULL, NULL);
	player1bis = CreateWindowEx(0, "static", "Catch me game!", WS_VISIBLE | WS_CHILD | SS_BITMAP, p1.x, p1.y, p1.lungime, p1.latime, hwnd, NULL, NULL, NULL);
	SendMessage(player1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer1);
	player2 = CreateWindowEx(0, "static", "Catch me game!", WS_VISIBLE | WS_CHILD | SS_BITMAP, p2.x, p2.y, p2.lungime, p2.latime, hwnd, NULL, NULL, NULL);
	player2bis = CreateWindowEx(0, "static", "Catch me game!", WS_VISIBLE | WS_CHILD | SS_BITMAP, p2.x, p2.y, p2.lungime, p2.latime, hwnd, NULL, NULL, NULL);
	SendMessage(player2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hplayer2);
	impact = CreateWindowEx(0, "static", "Catch me game!", WS_VISIBLE | WS_CHILD | SS_BITMAP, 120, 100, 720, 500, hwnd, NULL, NULL, NULL);

	hDisplayP11x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 840, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP12x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 880, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP13x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 920, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP14x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 960, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP15x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1000, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP16x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1040, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP17x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1080, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP18x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1120, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP19x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1160, 130, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP110x = CreateWindowEx(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1200, 130, 40, 25, hwnd, NULL, NULL, NULL);
	p1x = CreateWindowEx(0, "static", "P1x", WS_VISIBLE | WS_CHILD | WS_BORDER, 1250, 130, 40, 25, hwnd, NULL, NULL, NULL);;

	hDisplayP11y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 840, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP12y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 880, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP13y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 920, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP14y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 960, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP15y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1000, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP16y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1040, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP17y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1080, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP18y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1120, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP19y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1160, 160, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP110y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1200, 160, 40, 25, hwnd, NULL, NULL, NULL);
	p1y = CreateWindowExA(0, "static", "P1y", WS_VISIBLE | WS_CHILD | WS_BORDER, 1250, 160, 40, 25, hwnd, NULL, NULL, NULL);
	
	hDisplayP21x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 840, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP22x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 880, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP23x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 920, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP24x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 960, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP25x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1000, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP26x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1040, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP27x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1080, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP28x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1120, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP29x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1160, 190, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP210x = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1200, 190, 40, 25, hwnd, NULL, NULL, NULL);
	p2x = CreateWindowExA(0, "static", "P2x", WS_VISIBLE | WS_CHILD | WS_BORDER, 1250, 190, 40, 25, hwnd, NULL, NULL, NULL);
	
	hDisplayP21y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 840, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP22y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 880, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP23y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 920, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP24y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 960, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP25y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1000, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP26y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1040, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP27y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1080, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP28y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1120, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP29y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1160, 220, 40, 25, hwnd, NULL, NULL, NULL);
	hDisplayP210y = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 1200, 220, 40, 25, hwnd, NULL, NULL, NULL);
	p2y = CreateWindowExA(0, "static", "P2y", WS_VISIBLE | WS_CHILD | WS_BORDER, 1250, 220, 40, 25, hwnd, NULL, NULL, NULL);

	
	hDisplayContorStatic = CreateWindowEx(0, "static", "Counter:", WS_VISIBLE | WS_CHILD | WS_BORDER, 840, 300, 60, 25, hwnd, NULL, NULL, NULL);
	hDisplayContor = CreateWindowExA(0, "static", " ", WS_VISIBLE | WS_CHILD | WS_BORDER, 910, 300, 40, 25, hwnd, NULL, NULL, NULL);
}

void addPics()
{
	hplayer1 = (HBITMAP)LoadImageA(NULL, "player1.bmp", IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
	hplayer2 = (HBITMAP)LoadImageA(NULL, "player2.bmp", IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
	hplayer1bis = (HBITMAP)LoadImageA(NULL, "player1bis.bmp", IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
	hplayer2bis = (HBITMAP)LoadImageA(NULL, "player2bis.bmp", IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
	himpact = (HBITMAP)LoadImageA(NULL, "impact.bmp", IMAGE_BITMAP, 720, 500, LR_LOADFROMFILE);
}



int verificaTouch()
{
	if ((p1.x + p1.lungime > p2.x) && (p1.x < p2.x + p1.lungime))
	{
		if (p1.y + p1.lungime > p2.y)
		{
			if (p2.y + p2.lungime > p1.y)

				return 0;
		}
	}
}