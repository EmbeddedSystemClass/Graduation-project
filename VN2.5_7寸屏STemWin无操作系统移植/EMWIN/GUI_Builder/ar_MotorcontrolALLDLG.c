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
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x10)
#define ID_DROPDOWN_0 (GUI_ID_USER + 0x11)
#define ID_TEXT_0 (GUI_ID_USER + 0x12)
#define ID_BUTTON_0 (GUI_ID_USER + 0x13)
#define ID_BUTTON_1 (GUI_ID_USER + 0x14)
#define ID_BUTTON_2 (GUI_ID_USER + 0x15)



extern char sw_flag23 ;
extern char sw_flag67 ;
extern char sw_flag1011 ;
extern char sw_flag1415 ;
extern char sw_flag1819 ;
extern char sw_flag2223 ;
extern char sw_flag2627;
extern char sw_flag2930 ;
extern char sw_flag3132 ;
extern char ar_fuwei_zhengfan;
char switchSpeed = 0;

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
  { FRAMEWIN_CreateIndirect, "ar_MotorcontrolALL", ID_FRAMEWIN_0, 485, 250, 310, 225, 0, 0x0, 0 },
  { DROPDOWN_CreateIndirect, "speedT", ID_DROPDOWN_0, 140, 25, 100, 90, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "一键调速", ID_TEXT_0, 30, 30, 100, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "设备复位", ID_BUTTON_0, 30, 75, 100, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "急停", ID_BUTTON_1, 190, 160, 90, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "设备自检", ID_BUTTON_2, 30, 125, 100, 30, 0, 0x0, 0 },
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
    // Initialization of 'ar_MotorcontrolALL'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetTitleVis(hItem, 0);
    //
    // Initialization of 'speedT'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0);
    DROPDOWN_SetFont(hItem, &GUI_FontHZ24);
    DROPDOWN_AddString(hItem, "低速");
    DROPDOWN_AddString(hItem, "中速");
    DROPDOWN_AddString(hItem, "高速");
    //
    // Initialization of 'speedTtext'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetFont(hItem, &GUI_FontHZ24);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    //
    // Initialization of 'fuwei'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    //
    // Initialization of 'tingzhi'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    //
    // Initialization of 'shebeizijian'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_DROPDOWN_0: // Notifications sent by 'speedT'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
		  if (DROPDOWN_GetSel(WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0)) == 0)
		  {
			  switchSpeed = 0;
		  }
		  else if (DROPDOWN_GetSel(WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_0)) == 1)
		  {
			  switchSpeed = 1;
		  }
		  else
		  {
			  switchSpeed = 2;
		  }
		  WM_SendMessageNoPara(WM_GetParent(pMsg->hWin), ar_WM_switchSpeed);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_0: // Notifications sent by 'fuwei'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
		   sw_flag23 = 3;
		   sw_flag67 = 7;
		   sw_flag1011 = 11;
		   sw_flag1415 = 15;
		   sw_flag1819 = 19;
		   sw_flag2223 = 23;
		   sw_flag2627 = 27;
		   sw_flag2930 = 30;
		   sw_flag3132 = 32;

		   ar_fuwei_zhengfan = 1;
		  // WM_InvalidateWindow(WM_GetParent(pMsg->hWin));
		   WM_SendMessageNoPara(WM_GetParent(pMsg->hWin), ar_WM_fuwei);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'tingzhi'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
		  sw_flag23 = 3;
		  sw_flag67 = 7;
		  sw_flag1011 = 11;
		  sw_flag1415 = 15;
		  sw_flag1819 = 19;
		  sw_flag2223 = 23;
		  sw_flag2627 = 27;

		  WM_SendMessageNoPara(WM_GetParent(pMsg->hWin), ar_WM_fuwei);
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
    case ID_BUTTON_2: // Notifications sent by 'shebeizijian'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
		  WM_SendMessageNoPara(WM_GetParent(pMsg->hWin), ar_WM_zijian);
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
*       Createar_MotorcontrolALL
*/
WM_HWIN Createar_MotorcontrolALL(WM_HWIN hWiin);
WM_HWIN Createar_MotorcontrolALL(WM_HWIN hWiin) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, hWiin, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
