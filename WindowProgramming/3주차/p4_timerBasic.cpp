#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);

LPCTSTR lpszClass = TEXT("New Title Hong Gil Dong");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, //WINAPI :           α׷  ̶    ǹ 
	LPSTR lpszCmdLine, int nCmdShow)						 //hInstance :  ü     Ŀ             α׷     ο    ID
{																 //szCmdLine : Ŀ  Ʈ      󿡼     α׷             ޵     ڿ 
	HWND	hwnd;												 //iCmdShow :      찡 ȭ 鿡   µ      
	MSG		msg;
	WNDCLASS WndClass;											 //WndClass         ü     									 
	WndClass.style = CS_HREDRAW | CS_VREDRAW;			 //  ½ Ÿ   :     /         ȭ    ٽ   ׸ 
	WndClass.lpfnWndProc = WndProc;							 //   ν     Լ   
	WndClass.cbClsExtra = 0;								 //O/S           ޸  (Class)
	WndClass.cbWndExtra = 0;								 //O/s           ޸  (Window)
	WndClass.hInstance = hInstance;						 //        α׷  ID
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	 //           
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		 //Ŀ       
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//       
	WndClass.lpszMenuName = NULL;								 // ޴   ̸ 
	WndClass.lpszClassName = lpszClass;						 //Ŭ      ̸ 
	RegisterClass(&WndClass);									 // ռ                Ŭ        ּ 

	hwnd = CreateWindow(lpszClass,								 //     찡      Ǹ   ڵ (hwnd)     ȯ
		lpszClass,												 //       Ŭ    , Ÿ  Ʋ  ̸ 
		WS_OVERLAPPEDWINDOW,									 //         Ÿ  
		100,											 //         ġ, x  ǥ
		50,											 //         ġ, y  ǥ
		600,											 //            
		400,											 //              
		NULL,													 // θ          ڵ 	 
		NULL,													 // ޴   ڵ 
		hInstance,    											 //        α׷  ID
		NULL     												 //                  
	);
	ShowWindow(hwnd, nCmdShow);									 //         ȭ      
	UpdateWindow(hwnd);											 //O/S    WM_PAINT  ޽        

	while (GetMessage(&msg, NULL, 0, 0))							 //WinProc()     PostQuitMessage() ȣ          ó  
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);									 //WinMain -> WinProc  
	}
	return (int)msg.wParam;
}

HDC hdc;


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	PAINTSTRUCT ps;

	static char linebfr[256] = { 0, };
	static int x, y, oldX, oldY, left_button;

	switch (iMsg)
	{
	case WM_CREATE:
		SetTimer(hwnd, 1, 1000, NULL); 
		SetTimer(hwnd, 2, 5000, NULL); //5초에 한번씩 2번시계가 울림
		x = 0;
		y = 0;
		break;

	case WM_TIMER:
		if (wParam == 1)
			x += 10;
		else
			y += 10;
		InvalidateRect(hwnd, NULL, FALSE);
		break;

	case WM_CHAR:
		InvalidateRect(hwnd, NULL, FALSE);
		break;

		/*
		case WM_MOUSEMOVE:
			x = LOWORD(lParam);
			y = HIWORD(lParam);

			//m_count++;
			//itoa(m_count, linebfr, 10);

			InvalidateRect(hwnd, NULL, FALSE);
			break;
		*/

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		left_button = TRUE;
		//m_count++;
		//itoa(m_count, linebfr, 10);

		InvalidateRect(hwnd, NULL, FALSE);
		break;

	case WM_RBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		left_button = FALSE;
		//m_count--;
		//itoa(m_count, linebfr, 10);

		InvalidateRect(hwnd, NULL, FALSE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		//TextOut(hdc, 100, 50, "        ",8 );
		//TextOut(hdc, 100, 50, linebfr,strlen(linebfr) );
		/*if(left_button == TRUE)
			TextOut(hdc, x, y, "M", 1 );
		else
			TextOut(hdc, x, y, "  ", 2 );

		if(left_button == TRUE)
			SetPixel(hdc, x, y, RGB(255, 0, 0));
		*/
		TextOut(hdc, oldX, oldY, "   ", 3);
		TextOut(hdc, x, y, "H", 1);
		oldX = x;
		oldY = y;

		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);			 //CASE        ǵ          ޽      Ŀ     ó   ϵ     ޽        
}

/*
		switch(wParam)
		{
		case 'i' : // UP
			y -= 3;
			break;
		case 'j' : // LEFT
			x -= 5;
			break;
		case 'k' : // RIGHT
			x += 5;
			break;
		case 'm' : // DOWN
			y += 3;
			break;
		}
		*/
