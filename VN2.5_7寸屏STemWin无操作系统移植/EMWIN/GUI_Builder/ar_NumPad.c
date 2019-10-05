
#include "DIALOG.h"

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
//
// Bitmap data for arrow keys
//
static GUI_CONST_STORAGE GUI_COLOR _aColorsArrow[] = {
  0xFFFFFF, 0x000000
};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalArrow = {
  2,	/* number of entries */
  1, 	/* No transparency */
  &_aColorsArrow[0]
};

static GUI_CONST_STORAGE unsigned char _acArrowRight[] = {
  ____XX__, ________,
  ____XXXX, ________,
  XXXXXXXX, XX______,
  ____XXXX, ________,
  ____XX__, ________
};

static GUI_CONST_STORAGE unsigned char _acArrowLeft[] = {
  ____XX__, ________,
  __XXXX__, ________,
  XXXXXXXX, XX______,
  __XXXX__, ________,
  ____XX__, ________
};

static GUI_CONST_STORAGE GUI_BITMAP _bmArrowRight = {
  10,            /* XSize */
  5,             /* YSize */
  2,             /* BytesPerLine */
  1,             /* BitsPerPixel */
  _acArrowRight, /* Pointer to picture data (indices) */
  &_PalArrow     /* Pointer to palette */
};

static GUI_CONST_STORAGE GUI_BITMAP _bmArrowLeft = {
  10,            /* XSize */
  5,             /* YSize */
  2,             /* BytesPerLine */
  1,             /* BitsPerPixel */
  _acArrowLeft,  /* Pointer to picture data (indices) */
  &_PalArrow     /* Pointer to palette */
};
//
// Array of keys
//
static int _aKey[] = {GUI_KEY_DELETE, GUI_KEY_TAB, GUI_KEY_LEFT, GUI_KEY_RIGHT};

//
// Dialog resource of numpad
//
static const GUI_WIDGET_CREATE_INFO _aDialogNumPad[] = {
//
//  Function                 Text      Id                 Px   Py   Dx   Dy
//
  { WINDOW_CreateIndirect,   0,        0,                  5, 250,  230, 225},
  { BUTTON_CreateIndirect,   "7",      GUI_ID_USER +  7,  12,   5,  60,  35},
  { BUTTON_CreateIndirect,   "8",      GUI_ID_USER +  8,  83,   5,  60,  35},
  { BUTTON_CreateIndirect,   "9",      GUI_ID_USER +  9,  154,   5,  60,  35},
  { BUTTON_CreateIndirect,   "4",      GUI_ID_USER +  4,   12,   53,  60,  35},
  { BUTTON_CreateIndirect,   "5",      GUI_ID_USER +  5,  83,   53,  60,  35},
  { BUTTON_CreateIndirect,   "6",      GUI_ID_USER +  6,  154,   53,  60,  35},
  { BUTTON_CreateIndirect,   "1",      GUI_ID_USER +  1,   12,   96,  60,  35},
  { BUTTON_CreateIndirect,   "2",      GUI_ID_USER +  2,  83,   96,  60,  35},
  { BUTTON_CreateIndirect,   "3",      GUI_ID_USER +  3,  154,   96,  60,  35},
  { BUTTON_CreateIndirect,   "0",      GUI_ID_USER +  0,   12,  140,  60,  35},
  { BUTTON_CreateIndirect,   ".",      GUI_ID_USER + 10,  83,  140,  60,  35},
  { BUTTON_CreateIndirect,   "Del",    GUI_ID_USER + 11,  154,  140,  60,  35},
  { BUTTON_CreateIndirect,   "Tab",    GUI_ID_USER + 12,   12,  183,  60,  35},
  { BUTTON_CreateIndirect,   0,        GUI_ID_USER + 13,  83,  183,  60,  35},
  { BUTTON_CreateIndirect,   0,        GUI_ID_USER + 14,  154,  183,  60,  35},
};


/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _cbDialogNumPad
*
* Function description
*   Callback function of the numpad.
*/
static void _cbDialogNumPad(WM_MESSAGE * pMsg) {
  GUI_RECT r;
  unsigned i; 
  int      NCode;
  unsigned Id;
  int      Pressed;
  WM_HWIN  hDlg;
  WM_HWIN  hItem;
  
  Pressed = 0;
  hDlg = pMsg->hWin;
  switch (pMsg->MsgId) {
  case WM_PAINT:
    WM_GetClientRect(&r);
    GUI_SetColor(0x000000);
    GUI_DrawRect(r.x0, r.y0, r.x1, r.y1);          /* Draw rectangle around it */
    /* Draw the bright sides */
    GUI_SetColor(0xffffff);
    GUI_DrawHLine(r.y0 + 1, r.x0 + 1, r.x1 - 2);   /* Draw top line */
    GUI_DrawVLine(r.x0 + 1, r.y0 + 1, r.y1 - 2);
    /* Draw the dark sides */
    GUI_SetColor(0x555555);
    GUI_DrawHLine(r.y1-1, r.x0 + 1, r.x1 - 1);
    GUI_DrawVLine(r.x1-1, r.y0 + 1, r.y1 - 2);
    break;
  case WM_INIT_DIALOG:
    for (i = 0; i < GUI_COUNTOF(_aDialogNumPad) - 1; i++) {
      hItem = WM_GetDialogItem(hDlg, GUI_ID_USER + i);
      BUTTON_SetFocussable(hItem, 0);                       /* Set all buttons non focussable */
      switch (i) {
      case 13:
        BUTTON_SetBitmapEx(hItem, 0, &_bmArrowLeft, 7, 7);  /* Set bitmap for arrow left button (unpressed) */
        BUTTON_SetBitmapEx(hItem, 1, &_bmArrowLeft, 7, 7);  /* Set bitmap for arrow left button (pressed) */
        break;
      case 14:
        BUTTON_SetBitmapEx(hItem, 0, &_bmArrowRight, 7, 7); /* Set bitmap for arrow right button (unpressed) */
        BUTTON_SetBitmapEx(hItem, 1, &_bmArrowRight, 7, 7); /* Set bitmap for arrow right button (pressed) */
        break;
      }
    }
    WM_GetDialogItem(hDlg, GUI_ID_USER + 12);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);      /* Id of widget */
    NCode = pMsg->Data.v;                 /* Notification code */
    switch (NCode) {
    case WM_NOTIFICATION_CLICKED:
      Pressed = 1;
    case WM_NOTIFICATION_RELEASED:
      if ((Id >= GUI_ID_USER) && (Id <= (GUI_ID_USER + GUI_COUNTOF(_aDialogNumPad) - 1))) {
        int Key;
        if (Id < GUI_ID_USER + 11) {
          char acBuffer[10];
          BUTTON_GetText(pMsg->hWinSrc, acBuffer, sizeof(acBuffer)); /* Get the text of the button */
          Key = acBuffer[0];
        } else {
          Key = _aKey[Id - GUI_ID_USER - 11];                        /* Get the text from the array */
        }
        GUI_SendKeyMsg(Key, Pressed);                                /* Send a key message to the focussed window */
      }
      break;
    }
  default:
    WM_DefaultProc(pMsg);
  }
}



WM_HWIN ar_NumpadCreat(WM_HWIN hWiin);
WM_HWIN ar_NumpadCreat(WM_HWIN hWiin) {
	WM_HWIN hNumPad;


	hNumPad = GUI_CreateDialogBox(_aDialogNumPad,
		GUI_COUNTOF(_aDialogNumPad),
		_cbDialogNumPad, hWiin, 0, 0);

	WM_SetStayOnTop(hNumPad, 1);
	return hNumPad;
}


/*************************** End of file ****************************/

