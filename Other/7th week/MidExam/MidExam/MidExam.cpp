// MidExam.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MidExam.h"
#include <string>
#include <math.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK Integer(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
//LRESULT CALLBACK Real(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_MIDEXAM, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MIDEXAM));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MIDEXAM));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_MIDEXAM);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		
			case ID_POP_MESSAGE: /////
				{
			      int res=  MessageBox(hWnd, L"Enable Open", L"Title", MB_YESNOCANCEL| MB_ICONQUESTION); // id

				  switch(res)
				  {
					case IDYES:
					  {
					  MessageBox(hWnd, L"Open is Enabled", L"Information", MB_OK | MB_ICONINFORMATION);
					  HMENU hMenu = GetMenu(hWnd);
						UINT res=GetMenuState(hMenu,ID_TEST1_ENABLE32774, MF_BYCOMMAND);
						EnableMenuItem(hMenu,ID_TEST1_OPEN,MF_ENABLED);
					  }
					  break;
					  case IDNO:
					  {
					  MessageBox(hWnd, L"Message", L"ERROR", MB_OKCANCEL| MB_ICONERROR);
					  }
					  break;
					   case IDCANCEL:
					  {
					  MessageBox(hWnd, L"Message", L"Warning", MB_YESNO| MB_ICONWARNING);
					  }
					  break;
				  }
				}
				break;
			
				case ID_TEST1_OPEN:  
				{
					DialogBox(hInst,(LPCTSTR)IDD_DIALOG1,hWnd,(DLGPROC)Integer);  
				}
				break;

				case ID_TEST1_ENABLE32774:
					{
				HMENU hMenu = GetMenu(hWnd); 
				UINT res=GetMenuState(hMenu,ID_TEST1_OPEN, MF_BYCOMMAND);
				
				if(res == MF_DISABLED)
				{
					EnableMenuItem(hMenu,ID_TEST1_OPEN,MF_ENABLED);
				}
				
				else
				{
					EnableMenuItem(hMenu,ID_TEST1_OPEN,MF_DISABLED);
				}
					}
				break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
			case WM_RBUTTONDOWN: // pri natickane na desen buton da izleze open
		{
			HMENU hMenu=LoadMenu(hInst,(LPCWSTR) IDR_MENU1);
			HMENU hSubMenu=GetSubMenu(hMenu,0);			//vzemame 
			POINT pt={LOWORD(lParam),HIWORD(lParam)}; // koordinati
			ClientToScreen(hWnd,&pt);
			TrackPopupMenu(hSubMenu,TPM_RIGHTBUTTON,pt.x,pt.y,0,hWnd,NULL);
			DestroyMenu(hMenu);
		}
			break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

LRESULT CALLBACK Integer(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam) //napravih prototip
{
	switch(message)
		{
			case WM_INITDIALOG:
				 SetDlgItemInt(hDlg,IDC_EDIT1,36,TRUE);
				  SetDlgItemInt(hDlg,IDC_EDIT2,15,TRUE);
				return TRUE;
			case WM_COMMAND:
			 switch(wParam)
			 {
			 case IDC_BUTTON1:
				 {
					 BOOL *SLt=NULL;
					 BOOL SIG=TRUE;

					 int a=GetDlgItemInt(hDlg,IDC_EDIT1,SLt,SIG);
					 int b = GetDlgItemInt(hDlg,IDC_EDIT2,SLt,SIG);
					 int c = a-b;
					 SetDlgItemInt(hDlg,IDC_EDIT3,c,TRUE);
				 }
				 break;
				  case IDC_BUTTON2:
				 {
					 TCHAR buff[100], *st;

					 GetDlgItemText(hDlg,IDC_EDIT4,buff,sizeof(buff));

					 long double a= _tcstod(buff,&st);

					 GetDlgItemText(hDlg,IDC_EDIT5,buff,sizeof(buff));

					 long double b = _tcstod(buff,&st);


					 GetDlgItemText(hDlg,IDC_EDIT6,buff,sizeof(buff));

					 long double c = _tcstod(buff,&st);
					 long double znamenatel=((a*a)-c);

					  if(((a*a)-c)==0)
					 {
					   MessageBox(hDlg,L"Znamenatel e 0",L"Result",MB_OK);
					 }
					  else
					  {

					 long double y = ((b-a)*(b+a))/((a*a)-c);
					std::wstring s = std::to_wstring((long double)y);
					  MessageBox(hDlg,s.c_str(),L"Result",MB_OK);

					  }
				 }
				 break;
				case IDOK: case IDCANCEL:
					EndDialog(hDlg,LOWORD(wParam));
					return TRUE;
				}
				break;
		}
		return false;
}

//LRESULT CALLBACK Real(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam) //napravih prototip
//{
//	switch(message)
//		{
//			case WM_INITDIALOG:
//				return TRUE;
//			case WM_COMMAND:
//			 switch(wParam)
//			 {
//			 case IDC_BUTTON2:
//				 {
//					 BOOL *SLt=NULL;
//					 BOOL SIG=TRUE;
//
//					 long double a=GetDlgItemInt(hDlg,IDC_EDIT4,SLt,SIG);
//					 long double b = GetDlgItemInt(hDlg,IDC_EDIT5,SLt,SIG);
//					 long double c = GetDlgItemInt(hDlg,IDC_EDIT6,SLt,SIG);;
//					// long double = ((b-a)*(b+a))/a^a-c;
//					 SetDlgItemInt(hDlg,IDC_EDIT7,c,TRUE);
//					  //MessageBox(hDlg,s.c_str(),L"Result",MB_OK);
//				 }
//				 break;
//				case IDOK: case IDCANCEL:
//					EndDialog(hDlg,LOWORD(wParam));
//					return TRUE;
//				}
//				break;
//		}
//		return false;
//