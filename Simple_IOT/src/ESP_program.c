/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 30 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<string.h>
#include<stdio.h>

#include "USART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

char Quotes	[]	 = "\""		;
char Comma 	[]	 = {", "};
char Closing[]	 = "\r\n"	;

void HESP_voidInit(void)
{
	u8 Local_u8ValidFlag = 0;
	while(Local_u8ValidFlag == 0)
	{
		/*Stop Echo*/
		MUSART1_voidTransmit("ATE0\r\n");
		/*	Check command is done right
			ATE0 returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd("\r\nOK\r\n");
	}
	
	Local_u8ValidFlag = 0;
	
	while(Local_u8ValidFlag == 0)
	{
		/*Set ESP station mode*/
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
		/*	Check command is done right
			AT+CWMODE=1 returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd("OK");
	}
}


void HESP_voidConnctToRouter(char* Copy_u8StrSsid, char* Copy_u8StrPassword)
{
	u8 Local_u8ValidFlag = 0;
	char Command[50];
	
	strcat(Command, "AT+CWJAP_CUR=");

	strcat(Command, Quotes);
	strcat(Command, Copy_u8StrSsid);
	strcat(Command, Quotes);
	
	strcat(Command, Comma);
	
	strcat(Command, Quotes);
	strcat(Command, Copy_u8StrPassword);
	strcat(Command, Quotes);
	
	strcat(Command, Closing);
	
	while(Local_u8ValidFlag == 0)
	{
		/*Connect to WiFi of name Copy_u8StrSsid and password Copy_u8StrPassword*/
		MUSART1_voidTransmit(Command);
		/*	Check command is done right
			AT+CWJAP_CUR="SSID","Pass" returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd("OK");
	}
}

void HESP_voidConnectToServer(char* Copy_u8StrMode, char* Copy_u8StrIP, char* Copy_u8StrPort)
{
	u8 Local_u8ValidFlag = 0;
	char Command[42];

	strcat(Command, "AT+CIPSTART=");
	
	strcat(Command, Quotes);
	strcat(Command, Copy_u8StrMode);
	strcat(Command, Quotes);
	
	strcat(Command, Comma);
	
	strcat(Command, Quotes);
	strcat(Command, Copy_u8StrIP);
	strcat(Command, Quotes);
	
	strcat(Command, Comma);
	
	strcat(Command, Copy_u8StrPort);
	
	strcat(Command, Closing);
	
	while(Local_u8ValidFlag == 0)
	{
		/*	Connect to Server of IP Copy_u8StrIP with Copy_u8StrMode potocol
			Either TCP or UDP and on Port Copy_u8StrPort*/
		MUSART1_voidTransmit(Command);
		/*	Check command is done right
			AT+CIPSTART="MODE","IP",PORT returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd("OK");
		Local_u8ValidFlag = u8ValidateCmd("ALREADY CONNECTED");
	}
}

void HESP_voidExecuteRequest(char* Copy_u8StrRequest)
{
	u8 Local_u8ValidFlag = 0;
	char Command[14] = "AT+CIPSEND=";
	char Temp_str[2];
	/*calculate request length and add 2 for \r\n*/	
	u8 NumberOfLetters = strlen(Copy_u8StrRequest) + 2;
	/*Convert the number to String*/
	sprintf(Temp_str, "%i", NumberOfLetters);
	
	strcat(Command, Temp_str);
	
	strcat(Command, Closing);
	
	while(Local_u8ValidFlag == 0)
	{
		/*	Send number of letter from the coming request*/
		MUSART1_voidTransmit(Command);
		/*	Check command is done right
			AT+CIPSEND=NUMBER returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd("OK");
	}
	
	Local_u8ValidFlag = 0;
	
	while(Local_u8ValidFlag == 0)
	{
		/*	Send number of letter from the coming request*/
		MUSART1_voidTransmit(strcat(Copy_u8StrRequest, Closing));
		/*	Check command is done right
			AT+CIPSEND=NUMBER returns OK if all is okay*/
		Local_u8ValidFlag = u8ValidateCmd("OK");
	}
	
}

u8 u8ValidateCmd(char Copy_u8StrCmd[])
{
	u8 Local_u8ValidFlag = 0;
	u8 Local_u8Response[100] ={0};
	u8 Counter = 0;
	
	while (Local_u8Response[Counter-1] != 255)
	{
		Local_u8Response[Counter] = MUSART1_u8Receive();
		Counter++;
	}
	Local_u8Response[Counter-1] = 0;
	/*Strcmp returns 0 if the two strings are iqentical*/
	//Local_u8ValidFlag = strcmp(Copy_u8StrCmd, Local_u8Response);
	Local_u8ValidFlag = (Local_u8Response[2] == 'O' && Local_u8Response[3] == 'K');
	
	return Local_u8ValidFlag;
}
