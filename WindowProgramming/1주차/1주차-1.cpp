#include <windows.h>

//여기에 400 200 윈도우
//모니터 좌상단 기준 우측으로 400떨어진 곳에 윈도우의 좌상단을 위치
//윈도우 바닥 중앙에 자신의 이름을 출력 

// WinMain 함수에서 참조하므로 함수 원형을 선언한다.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) //초기화, 메시지 루프 
    // hinstance는 윈도우 프밍에서 사용하는 데이터 형식 
    //lpstr은 문자열을 가리키는 포인터 
{
    WNDCLASS wndclass;
    HWND hwnd;
    MSG msg;

    // 윈도우 클래스를 초기화하고 운영체제에 등록한다.
    wndclass.style = CS_HREDRAW | CS_VREDRAW; // 스타일 지정
    wndclass.lpfnWndProc = WndProc; // 윈도우 프로시저 이름
    wndclass.cbClsExtra = 0; // 여분 메모리(0바이트)
    wndclass.cbWndExtra = 0; // 여분 메모리(0바이트)
    wndclass.hInstance = hInstance; // 인스턴스 핸들
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 아이콘 모양
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // 커서 모양

    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 배경(흰색)
    wndclass.lpszMenuName = NULL; // 메뉴(NULL->메뉴 없음)
    wndclass.lpszClassName = "HelloClass"; // 윈도우 클래스 이름
    if (!RegisterClass(&wndclass)) return 1;

    // 윈도우를 생성하고 화면에 보이게 한다.
    hwnd = CreateWindow("HelloClass", "HelloSDK", WS_OVERLAPPEDWINDOW,
        400, 0, 400, 200, // 가로 400, 세로 200, // 4가지는 폭 지금은 디폴트 값임   CW_USEDEFAULT
        NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);

    // 메시지 큐에서 메시지를 하나씩 꺼내서 처리한다.
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, //메시지 종류와 상세 내용 
    WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps; //윈도우 그래픽에서 사용하는 구조체 
    const char* str = "choi seung ho";
    const char* str1 = "choi seung ho";


    // 발생한 메시지의 종류에 따라 적절히 처리한다.
    switch (message) {
    case WM_CREATE:
        return 0;
    case WM_LBUTTONDOWN:
        MessageBox(hwnd, "마우스를 클릭했습니다.", "마우스 메시지", MB_OK);
        return 0;

    case WM_PAINT: //출력용 메시지 자료구조바뀌면 실행 ㄱ
        hdc = BeginPaint(hwnd, &ps);
        TextOut(hdc, 150, 140, str, lstrlen(str)); //어디에 그리냐면 hdc
        //TextOut(hdc, 100, 150, str1, lstrlen(str1)); //어디에 그리냐면 hdc
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    // 응용 프로그램이 처리하지 않은 메시지는 운영체제가 처리한다.
    return DefWindowProc(hwnd, message, wParam, lParam);
}
