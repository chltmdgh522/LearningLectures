#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    MSG msg;
    HWND hwnd;
    WNDCLASS wndClass;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
    wndClass.hIcon = (HICON)LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hInstance = hInstance;
    wndClass.lpfnWndProc = WndProc;
    wndClass.lpszClassName = "Window Class";
    wndClass.lpszMenuName = "NULL";
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wndClass);
    hwnd = CreateWindow("Window Class",
        "메모장",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    static char str[10][100]; //모든 행에 대한 문자를 저장하는 것 str[0] 첫번째 행에 대한 문자열
    static int count, line;
    static SIZE size;
    int i;
    switch (iMsg)
    {
    case WM_CREATE:
        CreateCaret(hwnd, NULL, 3, 15);
        ShowCaret(hwnd);
        count = 0;
        line = 0;
        break;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        for (i = 0; i < line + 1; i++)
        {
            GetTextExtentPoint(hdc, str[i], strlen(str[i]), &size);
            TextOut(hdc, 0, i * 20, str[i], strlen(str[i]));
            SetCaretPos(size.cx, i * 20);
        }
        EndPaint(hwnd, &ps);
        break;
    case WM_CHAR:
        if (count > 10)
        {
            MessageBox(NULL, "더 이상 입력 할 수 없습니다.", "경고", MB_OK);
            count--;
        }
        else if (wParam == VK_BACK)
        {
            count--;
            if (count < 0)
            {
                line--;
                count = strlen(str[line]);
            }
            if (count == 0 && line == 0)
            {
                MessageBox(NULL, "한번만 더 누르면 큰일난다.", "경고한다", MB_OK);
            }
        }
        else if (wParam == VK_RETURN)
        {
            if (line < 9)
            {
                count = 0;
                line++;
            }
            else
            {
                MessageBox(NULL, "10번이상 Enter금지.", "Warning", MB_OK);
            }
        }
        else str[line][count++] = wParam;
        str[line][count] = '\0';
        InvalidateRgn(hwnd, NULL, TRUE);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
