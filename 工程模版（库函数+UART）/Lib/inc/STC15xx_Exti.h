
#ifndef	__STC15xx_EXTI_H
#define	__STC15xx_EXTI_H

#include	"STC15xx_config.h"

#define	EXT_MODE_RiseFall	0	//������/�½����ж�
#define	EXT_MODE_Fall		1	//�½����ж�

typedef struct
{
	u8	EXTI_Mode;			//�ж�ģʽ,  	EXT_MODE_RiseFall, EXT_MODE_Fall
	u8	EXTI_Polity;		//���ȼ�����	PolityHigh,PolityLow
	u8	EXTI_Interrupt;		//�ж�����		ENABLE,DISABLE
} EXTI_InitTypeDef;

u8	Ext_Inilize(u8 EXT, EXTI_InitTypeDef *INTx);

#endif
