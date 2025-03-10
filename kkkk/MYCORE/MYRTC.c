#include "MYRTC.h"

//RTC_TimeTypeDef STime;
//RTC_DateTypeDef SDate;
//RTC_AlarmTypeDef SAlarm;
/*获取时间
  @param 存放时分秒参数的缓存区
*/
void GET_time(uint8_t time[3])
{
	RTC_TimeTypeDef STime;
	RTC_DateTypeDef SDate;
	HAL_RTC_GetTime(&hrtc,&STime,RTC_FORMAT_BIN);
	HAL_RTC_GetDate (&hrtc,&SDate,RTC_FORMAT_BIN);
	time[0]=STime.Hours;
	time[1]=STime.Minutes;
	time[2]=STime.Seconds;

}
/*显示时间
@param 存放时分秒参数的缓存区，跟上一个函数理论上是同一个
*/

void Show_time(uint8_t time[3])
{
	uint8_t a[6]={0};
    a[0]=time[0]%10;//十位
	a[1]=(time[0]-time[0]*10);//个位
	a[2]=time[1]%10;
	a[3]=(time[1]-time[1]*10);
	a[4]=time[2]%10;
	a[5]=(time[2]-time[2]*10);
	//时
	Set_cloor(19-a[1],green);//1
	Set_cloor(a[0],green);//10
	
	//分
	Set_cloor(39-a[3],green);
	Set_cloor(19+a[2],green);
	//秒
	Set_cloor(59-a[5],green);
	Set_cloor(39+a[4],green);
	
	Treasmit_date();
	
}	
	
//void Alarm()
//{
//	
//	SAlarm.AlarmTime.Seconds=STime.Seconds+1;
//	if(SAlarm.AlarmTime.Seconds==60)
//	  {SAlarm.AlarmTime.Seconds=0;}
//	HAL_RTC_SetAlarm_IT(&hrtc, &SAlarm, RTC_FORMAT_BIN);
//}

