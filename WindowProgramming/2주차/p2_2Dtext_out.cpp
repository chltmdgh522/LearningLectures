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

   static char linebfr[10][256] = { 0, };
   static int i, row, col;

   switch (iMsg)
   {
   case WM_CREATE:
      row = 0;
      col = 0;
      break;

   case WM_CHAR:
      if (wParam == VK_RETURN) { //VK_UP
         row++;
         col = 0;
      }
      if(wParam == VK_UP) { //VK_UP
         row++;
         col = col-1;
      }
      else {
         linebfr[row][col++] = wParam;
         linebfr[row][col] = '\0';
      }

      InvalidateRect(hwnd, NULL, FALSE);
      break;

   case WM_PAINT:
      hdc = BeginPaint(hwnd, &ps);

      for (i = 0; i < 10; i++)
         TextOut(hdc, 100, 100 + 20 * i, linebfr[i], strlen(linebfr[i]));

      EndPaint(hwnd, &ps);
      break;

   case WM_DESTROY:
      PostQuitMessage(0);
      break;
   }
   return DefWindowProc(hwnd, iMsg, wParam, lParam);          //CASE        ǵ          ޽      Ŀ     ó   ϵ     ޽        
}
