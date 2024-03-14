#include <windows.h>
#include <string.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

LPCTSTR lpszClass = TEXT("New Title Hong Gil Dong");

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
        NULL,
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

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    static char linebfr[256] = "abcdefghij";
    static int i;

    switch (iMsg)
    {
    case WM_CREATE:
        i = 10;
        linebfr[0] = ' ';
        break;

    case WM_CHAR:
        linebfr[i--] = (char)wParam;
        linebfr[i] = '\0';
        InvalidateRect(hwnd, NULL, FALSE);
        break;

    case WM_PAINT:
    {
        HDC hdc;
        hdc = BeginPaint(hwnd, &ps);
        TextOut(hdc, 100, 100, linebfr, strlen(linebfr));
        EndPaint(hwnd, &ps);
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
