#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
   WPARAM wParam, LPARAM lParam);

LPCTSTR lpszClass = TEXT("New Title Hong Gil Dong");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, //WINAPI :           α׷  ̶    ǹ 
   LPSTR lpszCmdLine, int nCmdShow)                   //hInstance :  ü     Ŀ             α׷     ο    ID
{                                                 //szCmdLine : Ŀ  Ʈ      󿡼     α׷             ޵     ڿ 
   HWND   hwnd;                                     //iCmdShow :      찡 ȭ 鿡   µ      
   MSG      msg;
   WNDCLASS WndClass;                                  //WndClass         ü                                 
   WndClass.style = CS_HREDRAW | CS_VREDRAW;          //  ½ Ÿ   :     /         ȭ    ٽ   ׸ 
   WndClass.lpfnWndProc = WndProc;                      //   ν     Լ   
   WndClass.cbClsExtra = 0;                         //O/S           ޸  (Class)
   WndClass.cbWndExtra = 0;                         //O/s           ޸  (Window)
   WndClass.hInstance = hInstance;                   //        α׷  ID
   WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);    //           
   WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);       //Ŀ       
   WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//       
   WndClass.lpszMenuName = NULL;                         // ޴   ̸ 
   WndClass.lpszClassName = lpszClass;                   //Ŭ      ̸ 
   RegisterClass(&WndClass);                            // ռ                Ŭ        ּ 

   hwnd = CreateWindow(lpszClass,                         //     찡      Ǹ   ڵ (hwnd)     ȯ
      lpszClass,                                     //       Ŭ    , Ÿ  Ʋ  ̸ 
      WS_OVERLAPPEDWINDOW,                            //         Ÿ  
      100,                                  //         ġ, x  ǥ
      50,                                  //         ġ, y  ǥ
      600,                                  //            
      400,                                  //              
      NULL,                                        // θ          ڵ     
      NULL,                                        // ޴   ڵ 
      hInstance,                                      //        α׷  ID
      NULL                                          //                  
   );
   ShowWindow(hwnd, nCmdShow);                            //         ȭ      
   UpdateWindow(hwnd);                                  //O/S    WM_PAINT  ޽        

   while (GetMessage(&msg, NULL, 0, 0))                      //WinProc()     PostQuitMessage() ȣ          ó  
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);                            //WinMain -> WinProc  
   }
   return (int)msg.wParam;
}

HDC hdc;


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

   PAINTSTRUCT ps;

   static char linebfr[256] = { 0, };
   static int i, col, x, y, old_x, old_y;

   switch (iMsg)
   {
   case WM_CREATE:
      strcpy_s(linebfr, "Wind");
      col = 0;
      old_x = x = 300;
      old_y = y = 200;
      break;

   case WM_CHAR:
      switch (wParam)
      {
      case 'i': // UP
         y -= 3;
         break;
      case 'j': // LEFT
         x -= 5;
         break;
      case 'k': // RIGHT
         x += 5;
         break;
      case 'm': // DOWN
         y += 10;
         break;
      }

      InvalidateRect(hwnd, NULL, FALSE);
      break;

   case WM_PAINT:
      hdc = BeginPaint(hwnd, &ps);

      TextOut(hdc, old_x, old_y, "       ", 5);
      TextOut(hdc, x, y, linebfr, strlen(linebfr));
      old_x = x;
      old_y = y;

      EndPaint(hwnd, &ps);
      break;

   case WM_DESTROY:
      PostQuitMessage(0);
      break;
   }
   return DefWindowProc(hwnd, iMsg, wParam, lParam);          //CASE        ǵ          ޽      Ŀ     ó   ϵ     ޽        
}
