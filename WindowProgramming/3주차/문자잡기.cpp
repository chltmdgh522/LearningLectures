#include <windows.h>
#include "Resource.h"
#include "framework.h"
#include "Project1.h"
#include "targetver.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

COLORREF TextColor;
LPCTSTR lpszClass = TEXT("New Title Hong Gil Dong");
BOOL bTimerRunning = FALSE;
int score = 0;
BOOL isClicked = FALSE;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hwnd;
    MSG msg;
    WNDCLASS WndClass;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    WndClass.lpfnWndProc = WndProc;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.lpszMenuName = NULL;
    WndClass.lpszClassName = lpszClass;
    RegisterClass(&WndClass);

    hwnd = CreateWindow(lpszClass,
        lpszClass,
        WS_OVERLAPPEDWINDOW,
        100,
        50,
        600,
        400,
        NULL,
        LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1)),
        hInstance,
        NULL
    );
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

HDC hdc;

static int x, y, dx = 5, dy = 5;
void CALLBACK TimerProc(HWND hwnd, UINT iMsg, UINT_PTR ievent, DWORD dwTime)
{
    RECT clientRect;
    GetClientRect(hwnd, &clientRect);

    srand(GetTickCount());
    x = rand() % (clientRect.right - 20);
    y = rand() % (clientRect.bottom - 20);

    InvalidateRect(hwnd, NULL, FALSE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    static int oldX, oldY;

    switch (iMsg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_32773:
            TextColor = 0x000000FF;
            InvalidateRect(hwnd, NULL, TRUE);
            break;

        case ID_32772:
            TextColor = 0x00FF0000;
            InvalidateRect(hwnd, NULL, TRUE);
            break;

        case ID_32774:
            SetTimer(hwnd, 1, 500, TimerProc);
            break;

        case ID_32775:
            KillTimer(hwnd, 1);
            break;
        }
        break;

    case WM_CREATE:
        SetTimer(hwnd, 1, 1500, TimerProc);
        x = 0;
        y = 0;
        break;

    case WM_CHAR:
        InvalidateRect(hwnd, NULL, FALSE);
        break;

    case WM_LBUTTONDOWN:
        POINT pt;
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);
        if (!isClicked) {
            if (x <= pt.x && pt.x <= x + 20 && y <= pt.y && pt.y <= y + 20) {
                score+=10;
            }
            else {
                score--;
            }
            isClicked = TRUE;
            InvalidateRect(hwnd, NULL, FALSE);
        }
        break;

    case WM_RBUTTONDOWN:
        if (!isClicked) {
            score--;
            InvalidateRect(hwnd, NULL, FALSE);
        }
        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        SetTextColor(hdc, TextColor);
        TextOut(hdc, oldX, oldY, "   ", 3);
        TextOut(hdc, x, y, "H", 1);

        TCHAR scoreStr[20];
        wsprintf(scoreStr, TEXT("Score: %d"), score);
        TextOut(hdc, 10, 10, scoreStr, lstrlen(scoreStr));

        oldX = x;
        oldY = y;

        EndPaint(hwnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    if (iMsg == WM_LBUTTONUP || iMsg == WM_RBUTTONUP) {
        isClicked = FALSE;
    }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
