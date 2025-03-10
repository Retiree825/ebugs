#include "RGB.h"


/*
   定义RGB颜色对应的数组x[3]
   x[0]:绿色对应的数值0~8
   x[1]:红色对应的数值0~8
   x[2]:蓝色对应的数值0~8
*/
uint8_t green[3]={8,0,0};
uint8_t red[3]={0,8,0};
uint8_t blue[3]={0,0,8};



//所有灯珠的所有数据的数组(未初始化)
uint8_t RGB_Buffer[RGB_NUM*RGB_BIT]={0};

//初始化所有灯珠的数组
void reset_RGB()
{
for(int i=0;i<24*60;i++)
	RGB_Buffer[i]=RGB_0;
}

/*	
    控制灯珠颜色
	@param1 灯珠的位置（第n个）
	@param2 灯珠颜色对应的数组
*/
void Set_cloor(uint8_t RGBip,uint8_t Cloor[3])
{


//设置一单个灯珠缓存数组
	uint8_t buffer[24]={0};
	
//初始化单个灯珠的数组	
	for(int i=0;i<24;i++)
	{buffer[i]=RGB_0;}
	
//将颜色对应的数组传递到单个灯珠缓存数组中
	   for(uint8_t i=0;i<Cloor[0];i++ )
	   {	 
		   buffer[i]=RGB_1;
	   }

       for(uint8_t i=0;i<Cloor[1];i++ )
	   {	
	  	   buffer[i+8]=RGB_1;
	   }

	   for(uint8_t i=0;i<Cloor[2];i++ )
	   {	
		   buffer[i+16]=RGB_1;
	   }
	
//将缓存数组的数据传递给对应位置的灯
	   for(uint8_t i=0;i<24;i++)
	   {memcpy(&RGB_Buffer[24*RGBip+i],&buffer[i],sizeof(buffer[i]));}	
		
}



//传递数据
void Treasmit_date()
{
	
uint8_t The_Treasmit_date[80+RGB_NUM*RGB_BIT]={0};
memcpy(The_Treasmit_date,RGB_Buffer,sizeof(RGB_Buffer));
HAL_SPI_Transmit_DMA(&hspi1,The_Treasmit_date,sizeof(The_Treasmit_date));
}














