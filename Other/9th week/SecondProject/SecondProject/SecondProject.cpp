// SecondProject.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SecondProject.h"
#include <string>
#include <CommCtrl.h> // Lab7 8-th week

#define MAX_LOADSTRING 100
#define TIMER1 500 // Lab7 8-th week

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
LRESULT CALLBACK LAB5(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK LAB6(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

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
	LoadString(hInstance, IDC_SECONDPROJECT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SECONDPROJECT));

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
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SECONDPROJECT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SECONDPROJECT);
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
	int wmId, wmEvent;    // Lab 9
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
		case ID_MENUEXAMP_ADD: ////////
			{
				HMENU hMenu=GetMenu(hWnd); // izvlichame menu
				if(GetMenuState(hMenu,ID_MENUEXAMP_ADD+1000,MF_BYCOMMAND)==-1) // връща 1 ако Delete me го има вече
					                                                            // ако е -1 няма го
				{
				MENUITEMINFO mii; //съдържа описание
				ZeroMemory(&mii,sizeof(mii)); //почистваме паметта
				mii.cbSize=sizeof(mii);
				mii.fMask=MIIM_ID | MIIM_TYPE | MIIM_STATE;
				mii.wID=ID_MENUEXAMP_ADD + 1000;
				mii.fType=MFT_STRING;
				mii.dwTypeData=TEXT("Delete me");
				mii.fState=MFS_ENABLED;
				InsertMenuItem(hMenu,ID_MENUEXAMP_ADD, FALSE,&mii);
				}
			}
			break;
		case ID_MENUEXAMP_ADD + 1000: // id na butona delete pri natiskane na delete me iztriva butona
			{
			HMENU hMenu=GetMenu(hWnd);
			DeleteMenu(hMenu,ID_MENUEXAMP_ADD+1000,MF_BYCOMMAND);
			}
			break;
		case ID_MENUEXAMP_ENABLE:  ////
			{
				HMENU hMenu = GetMenu(hWnd); // izvlichame menu
				UINT res=GetMenuState(hMenu,ID_MENUEXAMP_DISABLE, MF_BYCOMMAND);

				if(res == MF_DISABLED)
				{
					EnableMenuItem(hMenu,ID_MENUEXAMP_DISABLE,MF_ENABLED);
				}
			}
			break;
			case ID_MENUEXAMP_DISABLE:  ////
			{
				HMENU hMenu = GetMenu(hWnd); // izvlichame menu
				UINT res=GetMenuState(hMenu,ID_MENUEXAMP_ENABLE, MF_BYCOMMAND);

				if(res == MF_DISABLED)
				{
					EnableMenuItem(hMenu,ID_MENUEXAMP_ENABLE,MF_DISABLED);
				}
			}
			break;
			case ID_POP_OPEN: /////
				{
			      int res=  MessageBox(hWnd, L"YES_No_Cancel", L"Title", MB_YESNOCANCEL| MB_ICONQUESTION); // id

				  switch(res)
				  {
					case IDYES:
					  {
					  MessageBox(hWnd, L"Message", L"Information", MB_OK | MB_ICONINFORMATION);
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
			case ID_LAB4_INTEGER:  //////
				{
					DialogBox(hInst,(LPCTSTR)IDD_DIALOG1,hWnd,(DLGPROC)Integer);  //LPCTSTR tipa danni
				}
				break;
				case ID_LAB5_REAL:  //////
				{
					DialogBox(hInst,(LPCTSTR)IDD_DIALOG2,hWnd,(DLGPROC)LAB5);  //LPCTSTR tipa danni
				}
				break;
				case ID_LAB6_OPEN:
					{
						DialogBox(hInst,(LPCTSTR)IDD_DIALOG3,hWnd,(DLGPROC)LAB6);
					}
					break;
			case ID_MENUEXAMP_CHECK: /////// pri klikane na check "button" da izchezne check simvola
				{
					HMENU hMenu=GetMenu(hWnd);
					UINT res=GetMenuState(hMenu,ID_MENUEXAMP_CHECK,MF_BYCOMMAND);

					if (res==MF_CHECKED)
					{
						CheckMenuItem(hMenu,ID_MENUEXAMP_CHECK,MF_UNCHECKED);
					}

					else
					{
						CheckMenuItem(hMenu,ID_MENUEXAMP_CHECK,MF_CHECKED);
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
	case WM_PAINT: // 9-th week
		{
		   hdc = BeginPaint(hWnd, &ps);
		   // TODO: Add any drawing code here...
		   //HBRUSH hBrush1 = CreateSolidBrush(RGB(0xFF, 0xFF, 0x00)); // first example from .docx file
			//SelectObject(hdc, hBrush1);
			//Rectangle(hdc, 134, 456, 324, 190); // first, second -> upeer top angle

			//HBRUSH hBrush2 = CreatePatternBrush(LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP1));
			//SelectObject(hdc, hBrush2);
			//Rectangle(hdc, 634, 456, 340, 190);
			//HBITMAP hBmp = LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP2);
			//
			//HBRUSH hBrush4 = CreatePatternBrush(hBmp);
			//SelectObject(hdc, hBrush4);
			//Ellipse(hdc, 134, 456, 324, 190);
			//
			//HBRUSH hBrush3 = CreateHatchBrush(HS_DIAGCROSS, RGB(0x88, 0x88, 0x20));
			//SelectObject(hdc, hBrush3);
			//Ellipse(hdc, 590, 410, 370, 230);
			//
			//HBITMAP hBmp1 = LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP3);
			//HBRUSH hBrush14 = CreatePatternBrush(hBmp1);
			//SelectObject(hdc, hBrush14);
			//POINT pp[4];
			//pp[0].x = 760; pp[0].y = 500;
			//pp[1].x = 925; pp[1].y = 380;
			//pp[2].x = 990; pp[2].y = 500;
			//pp[3].x = 890; pp[3].y = 600;
			//Polygon(hdc, pp, 4);
			//
			//hBrush1 = CreateSolidBrush(RGB(255, 255, 0));
			//SelectObject(hdc, hBrush1);
			//Ellipse(hdc, 0, 0, 80, 100);
			//hBrush1 = CreateSolidBrush(RGB(0, 255, 255));
			//SelectObject(hdc, hBrush1);
			//pp[0].x = 20; pp[0].y = 20;
			//pp[1].x = 10; pp[1].y = 30;
			//pp[2].x = 30; pp[2].y = 30;
			//Polygon(hdc, pp, 3);
			//pp[0].x = 60; pp[0].y = 20;
			//pp[1].x = 50; pp[1].y = 30;
			//pp[2].x = 70; pp[2].y = 30;
			//Polygon(hdc, pp, 3);
			//hBrush1 = CreateSolidBrush(RGB(255, 0, 0));
			//Rectangle(hdc, 30, 60, 50, 70);

			HBRUSH hBrush1 = CreateSolidBrush(RGB(255,255,0)); // pravoagalnik
			SelectObject(hdc, hBrush1);
			Rectangle(hdc, 100, 100, 200, 400);

			HBITMAP hBmp1 = LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP3); // triagalnik nos
			HBRUSH hBrush14 = CreatePatternBrush(hBmp1);
			SelectObject(hdc, hBrush14);
			POINT pp[3];
			pp[0].x = 100; pp[0].y = 100;
			pp[1].x = 200; pp[1].y = 100;
			pp[2].x = 150; pp[2].y = 50;
			Polygon(hdc, pp, 3);


			HBRUSH hBrush3 = CreateHatchBrush(HS_BDIAGONAL, RGB(0x88, 0x88, 0x20)); // krag v raketata
			SelectObject(hdc, hBrush3);
			Ellipse(hdc, 125, 125, 175, 175);

			HBITMAP hBmp2 = LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP3); // lavo krilo
			HBRUSH hBrush15 = CreatePatternBrush(hBmp2);
			SelectObject(hdc, hBrush15);
			POINT ppp[3];
			ppp[0].x = 100; ppp[0].y = 250;
			ppp[1].x = 100; ppp[1].y = 350;
			ppp[2].x = 50; ppp[2].y = 350;
			Polygon(hdc, ppp, 3);

			HBITMAP hBmp3 = LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP3); // dasno krilo
			HBRUSH hBrush16 = CreatePatternBrush(hBmp3);
			SelectObject(hdc, hBrush16);
			POINT pppp[3];
			pppp[0].x = 200; pppp[0].y = 250;
			pppp[1].x = 200; pppp[1].y = 350;
			pppp[2].x = 250; pppp[2].y = 350;
			Polygon(hdc, pppp, 3);

		   EndPaint(hWnd, &ps);
		}
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

// za DialogBox
LRESULT CALLBACK Integer(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam) //napravih prototip
{
	switch(message)
		{
			case WM_INITDIALOG:
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
					 int c = a+b;
					 SetDlgItemInt(hDlg,IDC_EDIT3,c,TRUE);
				 }
				 break;
				 case IDC_BUTTON2:
				 {
					 BOOL *SLt=NULL;
					 BOOL SIG=TRUE;

					 int a=GetDlgItemInt(hDlg,IDC_EDIT4,SLt,SIG);
					 int b = GetDlgItemInt(hDlg,IDC_EDIT5,SLt,SIG);
					 int c = a*b;
					 SetDlgItemInt(hDlg,IDC_EDIT6,c,TRUE);
				 }
				 break;
				  case IDC_BUTTON3:
				 {
					 BOOL *SLt=NULL;
					 BOOL SIG=TRUE;

					 int a=GetDlgItemInt(hDlg,IDC_EDIT7,SLt,SIG);
					 int b = GetDlgItemInt(hDlg,IDC_EDIT8,SLt,SIG);

					 if(b==0)
					 {
					   MessageBox(hDlg,L"Ima grashka",L"Result",MB_OK);
					 }
					 else
					 {
					 int c = a/b;
					 SetDlgItemInt(hDlg,IDC_EDIT9,c,TRUE);
					 std::wstring s = std::to_wstring((long double)c);
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

LRESULT CALLBACK LAB5(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam) //napravih prototip
{
	switch(message)
		{
			case WM_INITDIALOG:
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
					 int c = a+b;
					 SetDlgItemInt(hDlg,IDC_EDIT3,c,TRUE);
				 }
				 break;
				  case IDC_BUTTON4:
				 {
					 TCHAR buff[100], *st;

					 GetDlgItemText(hDlg,IDC_EDIT4,buff,sizeof(buff));
					

					 long double a= _tcstod(buff,&st);

					 GetDlgItemText(hDlg,IDC_EDIT5,buff,sizeof(buff));

					 long double b = _tcstod(buff,&st);
					 long double c = a+b;

					 std::wstring s=std::to_wstring(c);
					 SetDlgItemText(hDlg,IDC_EDIT10,s.c_str());
				 }
				 break;
				  case IDC_BUTTON5:
				 {
					 TCHAR buff[100], *st;

					 GetDlgItemText(hDlg,IDC_EDIT7,buff,sizeof(buff));
					

					 long double a= _tcstod(buff,&st);

					 GetDlgItemText(hDlg,IDC_EDIT8,buff,sizeof(buff));

					 long double b = _tcstod(buff,&st);
					 long double c = a*b;

					 std::wstring s=std::to_wstring(c);
					 SetDlgItemText(hDlg,IDC_EDIT11,s.c_str());
				 }
				 break;
				  case IDC_BUTTON6:
				 {
					 TCHAR buff[100], *st;

					 GetDlgItemText(hDlg,IDC_EDIT12,buff,sizeof(buff));
					

					 long double a= _tcstod(buff,&st);

					 GetDlgItemText(hDlg,IDC_EDIT13,buff,sizeof(buff));

					 long double b = _tcstod(buff,&st);
					 long double c = a-b;

					 std::wstring s=std::to_wstring(c);
					 SetDlgItemText(hDlg,IDC_EDIT14,s.c_str());
				 }
				 break;
				  case IDC_BUTTON7:
				 {
					 TCHAR buff[100], *st;

					 GetDlgItemText(hDlg,IDC_EDIT15,buff,sizeof(buff));
					

					 long double a= _tcstod(buff,&st);

					 GetDlgItemText(hDlg,IDC_EDIT16,buff,sizeof(buff));

					 long double b = _tcstod(buff,&st);
					 long double c = a/b;

					 std::wstring s=std::to_wstring(c);
					 SetDlgItemText(hDlg,IDC_EDIT17,s.c_str());
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

LRESULT CALLBACK LAB6(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam) //napravih prototip
{
	switch(message)
    {
	case WM_TIMER: //8th week
	 {
	 	int a = GetDlgItemInt(hDlg, IDC_EDIT3, NULL, TRUE);
	 	a += 5;
	 	SetDlgItemInt(hDlg, IDC_EDIT3, a, TRUE);
	 
	 	int pos = SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0);
	 
	 	if(pos < 300){
	 	pos++;
	 	}else{
	 		pos=0;
	 	}
	 
	 	SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, pos, 0);
	 }
	 break;
	case WM_INITDIALOG: // инициализираме диалоговата кутия  8th week Lab7
	 {
	   for(long double i=1;i<=10;i++)
	   {
	   	std::wstring s = std::to_wstring(i);
	   	SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)s.c_str());
	   	SendDlgItemMessage(hDlg,IDC_COMBO1,CB_ADDSTRING,0,(LPARAM)s.c_str());
	   }
	   SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETRANGE,0,MAKELPARAM(0, 300));
	   SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, 0, 0);
	   
	   return TRUE;
	 }
	case WM_COMMAND:
	 switch(wParam)
	 {
	    case IDC_BUTTON1:  ////////
	      {
	     	 if(IsDlgButtonChecked(hDlg,IDC_CHECK1)) // pri list box
	     	 {
	     		 if(IsDlgButtonChecked(hDlg,IDC_RADIO1))
	     		 {
	     			 TCHAR buff[100];
	     			 GetDlgItemText(hDlg,IDC_EDIT1,buff,sizeof(buff));
	     			 SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buff);
	     		 }
	     
	     		 if(IsDlgButtonChecked(hDlg,IDC_RADIO2)) // za delete markirai v list box togawa delete
	     		 {
	     			 int index=SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0);
	     			 SendDlgItemMessage(hDlg,IDC_LIST1,LB_DELETESTRING,index,0);
	     		 }
	     
	     		  if(IsDlgButtonChecked(hDlg,IDC_RADIO3)) // za find markirai v list box togawa delete
	     		 {
	     			 TCHAR buff[100];
	     			 GetDlgItemText(hDlg,IDC_EDIT1,buff,sizeof(buff));
	     			 int index=SendDlgItemMessage(hDlg,IDC_LIST1,LB_FINDSTRING,0,(LPARAM)buff);
	     			 SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,index,0);
	     		 }
	     	 }
	     
	     	 if(IsDlgButtonChecked(hDlg,IDC_CHECK2)) // pri combo box
	     	 {
	     		 if(IsDlgButtonChecked(hDlg,IDC_RADIO1))
	     		 {
	     			 TCHAR buff[100];
	     			 GetDlgItemText(hDlg,IDC_EDIT2,buff,sizeof(buff));
	     			 SendDlgItemMessage(hDlg,IDC_COMBO1,CB_ADDSTRING,0,(LPARAM)buff);
	     		 }
	     
	     		  if(IsDlgButtonChecked(hDlg,IDC_RADIO2)) // delete pri kombo box
	     		 {
	     			 TCHAR buff[100];
	     			 GetDlgItemText(hDlg,IDC_EDIT2,buff,sizeof(buff));
	     			 SendDlgItemMessage(hDlg,IDC_COMBO1,CB_DELETESTRING,0,(LPARAM)buff);
	     		 }
	     
	     		   if(IsDlgButtonChecked(hDlg,IDC_RADIO3)) // za find markirai v list box togawa delete
	     		 {
	     			 TCHAR buff[100];
	     			 GetDlgItemText(hDlg,IDC_EDIT2,buff,sizeof(buff));
	     			 int index=SendDlgItemMessage(hDlg,IDC_COMBO1,CB_FINDSTRING,0,(LPARAM)buff);
	     			 SendDlgItemMessage(hDlg,IDC_COMBO1,CB_SETCURSEL,index,0);
	     		 }
	     	 }
	      }
			   break;

			 case IDC_BUTTON2:  // 8th week
			  {
			 	SetTimer(hDlg,TIMER1,1,NULL);
			 	SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, 0, 0);
			  }
			  break;

			case IDC_BUTTON3:  //8th week
			 {
				KillTimer(hDlg,TIMER1);
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