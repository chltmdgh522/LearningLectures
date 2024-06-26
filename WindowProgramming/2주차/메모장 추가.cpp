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
    static int count, line, pos; // pos 변수 추가하여 현재 커서 위치 저장
    static SIZE size;
    int i;
    switch (iMsg)
    {
    case WM_CREATE:
        CreateCaret(hwnd, NULL, 3, 15);
        ShowCaret(hwnd);
        count = 0;
        line = 0;
        pos = 0; // 초기 커서 위치는 0으로 설정
        break;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        for (i = 0; i < line + 1; i++)
        {
            GetTextExtentPoint(hdc, str[i], strlen(str[i]), &size);
            TextOut(hdc, 0, i * 20, str[i], strlen(str[i]));
        }
        SetCaretPos(size.cx, pos * 20); // 커서 위치 설정
        EndPaint(hwnd, &ps);
        break;
    case WM_CHAR:
        if (count > 99)
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
                pos = line; // 라인이 변경될 때 커서도 함께 이동
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
                pos = line; // 엔터키 눌렀을 때 커서 이동
            }
            else
            {
                MessageBox(NULL, "10번이상 Enter금지.", "Warning", MB_OK);
            }
        }
        else if (pos <= line) // 현재 라인보다 높은 라인에서는 입력하지 않음
        {
            if (count < strlen(str[pos])) // 커서 위치부터 입력이 시작됨
            {
                for (i = strlen(str[pos]); i >= count; i--)
                {
                    str[pos][i + 1] = str[pos][i];
                }
                str[pos][count] = wParam;
                count++;
            }
            else
            {
                str[pos][count++] = wParam;
            }
            str[pos][count] = '\0';
        }
        InvalidateRgn(hwnd, NULL, TRUE);
        break;
    case WM_KEYDOWN: // 키보드 입력 처리
        switch (wParam)
        {

        case VK_UP: // 위 화살표 눌렀을 때
            if (line < 9)
            {
                count = 5;
                line--;
                pos = line; // 엔터키 눌렀을 때 커서 이동
            }
            else
            {
                MessageBox(NULL, "10번이상 Enter금지.", "Warning", MB_OK);
            }
            break;
        case VK_DOWN: // 아래 화살표 눌렀을 때
            if (pos < line)
                pos++; // 커서를 아래로 이동
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
