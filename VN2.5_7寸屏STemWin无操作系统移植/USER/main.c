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
	delay_init();	    	//��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
 	LED_Init();			    //LED�˿ڳ�ʼ��
	LCD_Init();			//LCD��ʼ��	
	KEY_Init();	 			//������ʼ��
 	TP_Init();				//��������ʼ��


	mem_init(); 			//��ʼ���ڲ��ڴ��
	
  
	exfuns_init();			//Ϊfatfs�ļ�ϵͳ�����ڴ�
	f_mount(fs[0],"0:",1);	//����SD��
	f_mount(fs[1],"1:",1);	//����FLASH
			
		/****�汾����*****/
  LCD_ShowString(60,50,700,16,16,"AR_IOT_Controller VN2.5");		
                          
	printf("AR_IOT_Controller VN2.5\r\n");
	
	printf("build date is %s\r\n",__DATE__);
	printf("build time is %s\r\n",__TIME__);
	

	while(SD_Initialize())//��ⲻ��SD��
	{
		POINT_COLOR=	RED;
		LCD_ShowString(60,150,200,16,16,"SD Card Error!");
		delay_ms(500);					
		LCD_ShowString(60,150,200,16,16,"Please Check! ");
		delay_ms(500);
		LED0=!LED0;//DS0��˸
	}
 	POINT_COLOR=BLUE;//��������Ϊ��ɫ 
	
	//���SD���ɹ� 									
	    delay_ms(500);
	LCD_ShowString(60,150,200,16,16,"SD Card OK    ");
			delay_ms(500);
	LCD_ShowString(60,170,200,16,16,"SD Card Size:     MB");
	sd_size=SD_GetSectorCount();//�õ�������
	LCD_ShowNum(164,170,sd_size>>11,5,16);//��ʾSD������
	
	
	/**********************��ʼ���ֿ�********************************/
 	while(font_init())		//��ʼ���ֿ�
	{
		LCD_ShowString(30,70,200,16,16,"Font Error!");
		while(SD_Initialize())	//���SD��
		{
			LCD_ShowString(30,90,200,16,16,"SD Card Failed!");
			delay_ms(200);
			LCD_Fill(30,90,200+30,70+16,WHITE);
			delay_ms(200);		    
		}
		update_font(30,90,16);	//����ֿⲻ���ھ͸����ֿ�
		delay_ms(2000);
		LCD_Clear(WHITE);	//����
		break;
	} 
	
/*****************************************************************/
	delay_ms(1000);
	TIM3_Int_Init(999,71);	//1KHZ ��ʱ��1ms 
	TIM6_Int_Init(999,719);	//10ms�ж�

	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC,ENABLE);//ʹ��CRCʱ�ӣ�����STemWin����ʹ�� 
	WM_SetCreateFlags(WM_CF_MEMDEV);
	GUI_Init();

	GUI_SetBkColor(GUI_BLACK);
	GUI_Clear();
	GUI_CURSOR_Show();

	//BUTTON_SetDefaultSkin(BUTTON_SKIN_FLEX); 




 Createar_BKWindow();
 //TIM4_Int_Init(999,719*90);	//--�ڴ�ռ��

	
	while(1)
	{
	//GUI_Exec();	
	GUI_Delay(1);

	}
}


