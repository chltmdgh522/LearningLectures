#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
    WPARAM wParam, LPARAM lParam);

LPCTSTR lpszClass = TEXT("New Title Hong Gil Dong");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, //WINAPI : ������ ���α׷��̶�� �ǹ�
    LPSTR lpszCmdLine, int nCmdShow)                         //hInstance : �ü���� Ŀ���� ���� ���α׷��� �ο��� ID
{                                                                //szCmdLine : Ŀ��Ʈ���� �󿡼� ���α׷� ���� �� ���޵� ���ڿ�
    HWND hwnd;                                                 //iCmdShow : �����찡 ȭ�鿡 ��µ� ����
    MSG        msg;
    WNDCLASS WndClass;                                         //WndClass ��� ����ü ����                                     
    WndClass.style = CS_HREDRAW | CS_VREDRAW;             //��½�Ÿ�� : ����/������ ��ȭ�� �ٽ� �׸�
    WndClass.lpfnWndProc = WndProc;                             //���ν��� �Լ���
    WndClass.cbClsExtra = 0;                                 //O/S ��� ���� �޸� (Class)
    WndClass.cbWndExtra = 0;                                 //O/s ��� ���� �޸� (Window)
    WndClass.hInstance = hInstance;                         //���� ���α׷� ID
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);     //������ ����
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);         //Ŀ�� ����
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//����   
    WndClass.lpszMenuName = NULL;                                 //�޴� �̸�
    WndClass.lpszClassName = lpszClass;                         //Ŭ���� �̸�
    RegisterClass(&WndClass);                                     //�ռ� ������ ������ Ŭ������ �ּ�

    hwnd = CreateWindow(lpszClass,                                 //�����찡 �����Ǹ� �ڵ�(hwnd)�� ��ȯ
        lpszClass,                                                 //������ Ŭ����, Ÿ��Ʋ �̸�
        WS_OVERLAPPEDWINDOW,                                     //������ ��Ÿ��
        100,                                                //������ ��ġ, x��ǥ
        50,                                                //������ ��ġ, y��ǥ
        600,                                                //������ ��   
        400,                                                //������ ����   
        NULL,                                                     //�θ� ������ �ڵ�    
        NULL,                                                     //�޴� �ڵ�
        hInstance,                                                 //���� ���α׷� ID
        NULL                                                      //������ ������ ����
    );
    ShowWindow(hwnd, nCmdShow);                                     //�������� ȭ�� ���
    UpdateWindow(hwnd);                                             //O/S �� WM_PAINT �޽��� ����

    while (GetMessage(&msg, NULL, 0, 0))                             //WinProc()���� PostQuitMessage() ȣ�� ������ ó��
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);                                     //WinMain -> WinProc  
    }
    return (int)msg.wParam;
}

HDC hdc;

static int x, y, dx = 5, dy = 5; // dx, dy 는 각각 x와 y의 증가량 (속도)
void CALLBACK TimerProc(HWND hwnd, UINT iMsg, UINT_PTR ievent, DWORD dwTime)
{
    x += dx;
    y += dy;

    RECT clientRect;
    GetClientRect(hwnd, &clientRect); // 클라이언트 영역의 크기를 얻어옴

    // 화면 경계에 닿았을 때 반대 방향으로 튕기는 로직
    if (x <= 0 || x >= clientRect.right - 20) { // 20은 텍스트가 그려지는 폭을 고려하여 임의로 설정한 값입니다.
        dx = -dx; // x 방향 반전
    }
    if (y <= 0 || y >= clientRect.bottom - 20) { // 20은 텍스트가 그려지는 높이를 고려하여 임의로 설정한 값입니다.
        dy = -dy; // y 방향 반전
    }

    InvalidateRect(hwnd, NULL, FALSE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

    PAINTSTRUCT ps;

    static char linebfr[256] = { 0, };
    static int oldX, oldY, left_button;


    switch (iMsg)
    {
    case WM_CREATE:
        SetTimer(hwnd, 1, 50, TimerProc); // 타이머 간격을 조절하여 속도 조절
        x = 0;
        y = 0;
        break;

    case WM_CHAR:
        InvalidateRect(hwnd, NULL, FALSE);
        break;

    case WM_LBUTTONDOWN:
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        left_button = TRUE;
        InvalidateRect(hwnd, NULL, FALSE);
        break;

    case WM_RBUTTONDOWN:
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        left_button = FALSE;
        InvalidateRect(hwnd, NULL, FALSE);
        break;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        // 이전에 그렸던 문자 삭제
        TextOut(hdc, oldX, oldY, "   ", 3);
        // 현재 위치에 새로운 문자 그리기
        TextOut(hdc, x, y, "H", 1);

        oldX = x;
        oldY = y;

        EndPaint(hwnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);             //CASE���� ���ǵ
}
