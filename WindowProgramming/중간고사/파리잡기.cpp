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

HBITMAP hBitmap; // 비트맵 핸들 선언

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

    // 비트맵 이미지 로드
    hBitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1));

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // 비트맵 해제
    DeleteObject(hBitmap);

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

        case ID_32776: //초록
            TextColor = 0x0000FF00;
            InvalidateRect(hwnd, NULL, TRUE);
            break;

        case ID_32774: //시작
            SetTimer(hwnd, 1, 1500, TimerProc);
            break;

        case ID_32775: // 중지
            KillTimer(hwnd, 1);
            break;

        case ID_32780: //화면종료
            PostMessage(hwnd, WM_CLOSE, 0, 0); // 화면 종료 
            break;

        case ID_32777:
            SetTimer(hwnd, 1, 200, TimerProc); // 0.2초 (200밀리초)
            break;

        case ID_32778:
            SetTimer(hwnd, 1, 500, TimerProc); // 0.5초 (500밀리초)
            break;

        case ID_32779:
            SetTimer(hwnd, 1, 1000, TimerProc); // 1초 (1000밀리초)
            break;

        
        }
        break;

    case WM_CREATE:
        SetTimer(hwnd, 1, 1500, TimerProc); //초기 설정  노말이랑 같게하는게 좋을듯?
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
                score += 10;
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
    {
        hdc = BeginPaint(hwnd, &ps);
        SetTextColor(hdc, TextColor);

        // 이전에 그려진 이미지 지우기
        RECT rect;
        rect.left = oldX;
        rect.top = oldY;
        rect.right = oldX + 50;
        rect.bottom = oldY + 50;
        FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

        // 비트맵 이미지 그리기
        HDC hdcMem = CreateCompatibleDC(hdc);
        SelectObject(hdcMem, hBitmap);
        BitBlt(hdc, x, y, 50, 50, hdcMem, 0, 0, SRCCOPY);
        DeleteDC(hdcMem);

        TCHAR scoreStr[20];
        wsprintf(scoreStr, TEXT("Score: %d"), score);
        TextOut(hdc, 10, 10, scoreStr, lstrlen(scoreStr));

        oldX = x;
        oldY = y;

        EndPaint(hwnd, &ps);
    }
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
