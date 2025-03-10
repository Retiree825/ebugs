#include "MYUSART.h"
//AT指令集
char cmed0[]="AT+RST\r\n";
char cmed1[]="AT+CWMODE=1\r\n";
char cmed2[]="AT+CIPMUX=0\r\n";
char cmed3[]="AT+CWJAP=\"MERCURY_86AD\",\"123456789\"\r\n";
char cmed4[]="AT+CIPSTART=\"TCP\",\"quan.suning.com\",80\r\n";
char cmed5[]="AT+CIPMODE=1\r\n";
char cmed6[]="AT+CIPSEND\r\n";
char cmed7[]="GET\r\n";
/* 发送AT指令并接受返回

@param 接受返回数据的缓存区

*/
void Sed_read_AT(char*read)
{
	HAL_UART_Transmit(&huart2,(uint8_t*)cmed0,sizeof(cmed0),HAL_MAX_DELAY);
	  HAL_Delay(5000);
	
	HAL_UART_Transmit(&huart2,(uint8_t*)cmed1,sizeof(cmed1),HAL_MAX_DELAY);
	  HAL_Delay(5000);
	
	HAL_UART_Transmit(&huart2,(uint8_t*)cmed2,sizeof(cmed2),HAL_MAX_DELAY);
	  HAL_Delay(5000);
	
	HAL_UART_Transmit(&huart2,(uint8_t*)cmed3,sizeof(cmed3),HAL_MAX_DELAY);
	 HAL_Delay(5000);
	
	HAL_UART_Transmit(&huart2,(uint8_t*)cmed4,sizeof(cmed4),HAL_MAX_DELAY);
	  HAL_Delay(10000);
	
	HAL_UART_Transmit(&huart2,(uint8_t*)cmed5,sizeof(cmed5),HAL_MAX_DELAY);
	  HAL_Delay(5000);
	
	HAL_UART_Transmit(&huart2,(uint8_t*)cmed6,sizeof(cmed6),HAL_MAX_DELAY);
	  HAL_Delay(5000);
	  HAL_UART_Transmit(&huart2,(uint8_t*)cmed7,sizeof(cmed7),HAL_MAX_DELAY);
//	  HAL_UART_Transmit(&huart3,(uint8_t*)read,100,HAL_MAX_DELAY);
     HAL_UART_Receive(&huart2,(uint8_t*)read,2,10000);
	HAL_UART_Transmit(&huart3,(uint8_t*)read,sizeof(read),HAL_MAX_DELAY);
}












