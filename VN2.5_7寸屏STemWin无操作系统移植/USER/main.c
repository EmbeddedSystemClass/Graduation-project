/*************************************
 * ar+Stemwin
 *
 * @team       AR   
 * @author     ronglong
 * @brief      STM32RCT6	
 * @version    VN2.5
 * @date       2019-2-15
 ************************************/
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "ILI93xx.h"
#include "usart.h"	 
#include "24cxx.h"
#include "flash.h"
#include "touch.h"
#include "sram.h"
#include "timer.h"
#include "malloc.h"
#include "GUI.h"
#include "GUIDemo.h"
#include "includes.h"
extern void LCD_Init(void);

int main(void)
{	 

	u32 sd_size;
	delay_init();	    	//延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			    //LED端口初始化
	LCD_Init();			//LCD初始化	
	KEY_Init();	 			//按键初始化
 	TP_Init();				//触摸屏初始化


	mem_init(); 			//初始化内部内存池
	
  
	exfuns_init();			//为fatfs文件系统分配内存
	f_mount(fs[0],"0:",1);	//挂载SD卡
	f_mount(fs[1],"1:",1);	//挂载FLASH
			
		/****版本控制*****/
  LCD_ShowString(60,50,700,16,16,"AR_IOT_Controller VN2.5");		
                          
	printf("AR_IOT_Controller VN2.5\r\n");
	
	printf("build date is %s\r\n",__DATE__);
	printf("build time is %s\r\n",__TIME__);
	

	while(SD_Initialize())//检测不到SD卡
	{
		POINT_COLOR=	RED;
		LCD_ShowString(60,150,200,16,16,"SD Card Error!");
		delay_ms(500);					
		LCD_ShowString(60,150,200,16,16,"Please Check! ");
		delay_ms(500);
		LED0=!LED0;//DS0闪烁
	}
 	POINT_COLOR=BLUE;//设置字体为蓝色 
	
	//检测SD卡成功 									
	    delay_ms(500);
	LCD_ShowString(60,150,200,16,16,"SD Card OK    ");
			delay_ms(500);
	LCD_ShowString(60,170,200,16,16,"SD Card Size:     MB");
	sd_size=SD_GetSectorCount();//得到扇区数
	LCD_ShowNum(164,170,sd_size>>11,5,16);//显示SD卡容量
	
	
	/**********************初始化字库********************************/
 	while(font_init())		//初始化字库
	{
		LCD_ShowString(30,70,200,16,16,"Font Error!");
		while(SD_Initialize())	//检测SD卡
		{
			LCD_ShowString(30,90,200,16,16,"SD Card Failed!");
			delay_ms(200);
			LCD_Fill(30,90,200+30,70+16,WHITE);
			delay_ms(200);		    
		}
		update_font(30,90,16);	//如果字库不存在就更新字库
		delay_ms(2000);
		LCD_Clear(WHITE);	//清屏
		break;
	} 
	
/*****************************************************************/
	delay_ms(1000);
	TIM3_Int_Init(999,71);	//1KHZ 定时器1ms 
	TIM6_Int_Init(999,719);	//10ms中断

	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC,ENABLE);//使能CRC时钟，否则STemWin不能使用 
	WM_SetCreateFlags(WM_CF_MEMDEV);
	GUI_Init();

	GUI_SetBkColor(GUI_BLACK);
	GUI_Clear();
	GUI_CURSOR_Show();

	//BUTTON_SetDefaultSkin(BUTTON_SKIN_FLEX); 




 Createar_BKWindow();
 //TIM4_Int_Init(999,719*90);	//--内存占用

	
	while(1)
	{
	//GUI_Exec();	
	GUI_Delay(1);

	}
}


