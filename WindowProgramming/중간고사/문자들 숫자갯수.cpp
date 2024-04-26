#include <Windows.h>
#include <stdio.h>
#include <ctype.h>

// 전역 변수
HWND g_hButton; // 버튼 핸들

// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        // 버튼 생성
        g_hButton = CreateWindow(TEXT("BUTTON"), TEXT("Click Me"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            10, 10, 100, 30, hwnd, (HMENU)1, NULL, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) { // 버튼 클릭 이벤트 처리
            HANDLE hFileIn, hFileOut;
            DWORD dwBytesRead, dwBytesWritten;
            char buffer[256];
            DWORD numCount = 0;
            char charBuffer[256];
            DWORD charBufferSize = 0;

            // 입력 파일 열기
            hFileIn = CreateFile(TEXT("a.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFileIn == INVALID_HANDLE_VALUE) {
                MessageBox(hwnd, TEXT("Failed to open input file."), TEXT("Error"), MB_OK | MB_ICONERROR);
                return 0;
            }

            // 출력 파일 열기
            hFileOut = CreateFile(TEXT("b.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFileOut == INVALID_HANDLE_VALUE) {
                MessageBox(hwnd, TEXT("Failed to open output file."), TEXT("Error"), MB_OK | MB_ICONERROR);
                CloseHandle(hFileIn);
                return 0;
            }

            // 파일 읽기
            while (ReadFile(hFileIn, buffer, sizeof(buffer), &dwBytesRead, NULL) && dwBytesRead > 0) {
                for (DWORD i = 0; i < dwBytesRead; i++) {
                    if (isdigit(buffer[i])) {
                        numCount++;
                    }
                    else if (isalpha(buffer[i])) {
                        charBuffer[charBufferSize++] = buffer[i];
                    }
                }
            }

            // 숫자 개수를 문자열로 변환
            char numCountString[100];
            sprintf_s(numCountString, "%d ", numCount);

            // 숫자 개수 파일에 쓰기
            WriteFile(hFileOut, numCountString, strlen(numCountString), &dwBytesWritten, NULL);

            // 문자열 파일에 쓰기
            WriteFile(hFileOut, charBuffer, charBufferSize, &dwBytesWritten, NULL);

            // 파일 닫기
            CloseHandle(hFileIn);
            CloseHandle(hFileOut);

            // 메시지 박스로 결과 출력
            MessageBox(hwnd, TEXT("Numbers count and characters extracted successfully."), TEXT("Result"), MB_OK | MB_ICONINFORMATION);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// 진입점
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 윈도우 클래스 등록
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = TEXT("MyWindowClass");

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // 윈도우 생성
    HWND hwnd = CreateWindow(TEXT("MyWindowClass"), TEXT("Count Numbers and Extract Characters"),
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 240, 120, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, TEXT("Window Creation Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // 윈도우 표시
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 메시지 루프
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
