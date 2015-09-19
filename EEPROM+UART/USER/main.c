/********************************************************************************
* �ļ���main.c
* ���ߣ���˧
* ���ڣ�2015/07/25
* ����������������
********************************************************************************/
#include "STC15xx_config.h"
#include "UART.h"
#include "GPIO.h"

//***********************************led**************************************************
sbit	led=P3^0;


void main(){
	
	char str[]="EEPROM!hello!!!\r\n";
	char str_eep[20];
	
	GPIO_config();
	UART1_config();
	EA = 1;
	PrintString1(str);
	EEPROM_SectorErase(0x0000);//д����ǰһ����Ҫ���ǲ�������
	EEPROM_write_n(0x0000,str,20);
	
	EEPROM_read_n(0x0000,str_eep,20);
	
	
	for(;;){
		//PrintString1(str);
		PrintString1(str_eep);
		led=~led;
		delay_ms(500);
		
	}

}