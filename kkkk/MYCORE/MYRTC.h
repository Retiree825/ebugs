#ifndef __MYRTC_H
#define __MYRTC_H

#include "main.h"
#include "dma.h"
#include "rtc.h"
#include "spi.h"

#include "usart.h"
#include "gpio.h"
#include "MYUSART.h"
#include "RGB.h"
extern uint8_t time[3];

void GET_time(uint8_t time[3]);
void Show_time(uint8_t time[3]);
void Alarm();
#endif
