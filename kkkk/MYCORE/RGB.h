#ifndef __RGB_H
#define __RGB_H

//头文件声明
#include "main.h"
#include "dma.h"

#include "gpio.h"
#include "spi.h"
#include <string.h>

//定义声明
#define  RGB_1 0xF0
#define  RGB_0 0xC0
#define RGB_NUM 60
#define RGB_BIT 24

//颜色数组声明
extern uint8_t green[3];
extern uint8_t red[3];
extern uint8_t blue[3];


//函数声明
void reset_RGB(); 	
	
void Set_cloor(uint8_t RGBip,uint8_t Cloor[3]);
	
void Treasmit_date();

#endif
