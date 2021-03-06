/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "includes.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_TEXT_0 (GUI_ID_USER + 0x01)
#define ID_BUTTON_0 (GUI_ID_USER + 0x02)
#define ID_BUTTON_1 (GUI_ID_USER + 0x03)
#define ID_BUTTON_2 (GUI_ID_USER + 0x04)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "ar_BKWindow", ID_WINDOW_0, 0, 0, 800, 480, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "物联网工业控制系统", ID_TEXT_0, 440, 10, 350, 76, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "ar_BKbutton_left", ID_BUTTON_0, 65, 350, 115, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "ar_BKbutton_mid", ID_BUTTON_1, 220, 350, 115, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "ar_BKbutton_right", ID_BUTTON_2, 376, 350, 115, 50, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:                                                                                                                                                                                                                                                                                                                                              
    //
    // Initialization of 'ar_BKWindow'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, 0x80808080);
    //
    // Initialization of 'ar_IOT_System'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetFont(hItem, &GUI_FontHZ24);
    TEXT_SetTextColor(hItem, 0x00FFFFFF);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    //
    // Initialization of 'ar_BKbutton_left'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetText(hItem, "设备调试");
    //
    // Initialization of 'ar_BKbutton_mid'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetText(hItem, "生产模式");
    //
    // Initialization of 'ar_BKbutton_right'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetText(hItem, "联系我们");
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'ar_BKbutton_left'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
			printf("Enter device debugging!");
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
		  GUI_EndDialog(pMsg->hWin, 0);
		  Createar_MotorcontrolWindow();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'ar_BKbutton_mid'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
				printf("Enter production mode!");
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
		  GUI_EndDialog(pMsg->hWin, 0);
		  Createar_ProductionWind();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'ar_BKbutton_right'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
		  WM_DisableWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0));
		  WM_DisableWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1));
		  WM_DisableWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2));
		 GUI_MessageBox("\nOur Number:\n     18398630962   \n", "About us", GUI_MESSAGEBOX_CF_MOVEABLE);
		 WM_EnableWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0));
		 WM_EnableWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1));
		 WM_EnableWindow(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2));
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       Createar_BKWindow
*/
WM_HWIN Createar_BKWindow(void);
WM_HWIN Createar_BKWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
