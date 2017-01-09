#include "init.h"

void _initGPIO(void)
{
	GPIO_InitTypeDef GPIO;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO.GPIO_Mode = GPIO_Mode_AF;
	GPIO.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO.GPIO_Speed = GPIO_Speed_25MHz;
	
	GPIO_Init(GPIOA, &GPIO);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);
}
void _initTIM(void)
{
	TIM_TimeBaseInitTypeDef TIMER;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIMER.TIM_ClockDivision = TIM_CKD_DIV2;
	TIMER.TIM_CounterMode = TIM_CounterMode_Up;
	TIMER.TIM_Prescaler = 4200 - 1;
	TIMER.TIM_Period = 100;
	
	
	TIM_TimeBaseInit(TIM2, &TIMER);
	TIM_Cmd(TIM2, ENABLE);
}
void _initPWM(void)
{
	TIM_OCInitTypeDef TIMOC;
	TIMOC.TIM_OCMode = TIM_OCMode_PWM2;
  TIMOC.TIM_OutputState = TIM_OutputState_Enable;
  TIMOC.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIMOC.TIM_Pulse = 
	
	TIM_OC1Init(TIM2, &TIMOC);
  TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC2Init(TIM2, &TIMOC);
  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC3Init(TIM2, &TIMOC);
  TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC4Init(TIM2, &TIMOC);
  TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	
}
