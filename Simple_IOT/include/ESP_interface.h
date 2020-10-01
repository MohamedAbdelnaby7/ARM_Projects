/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 30 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

void HESP_voidInit(void);
void HESP_voidConnctToRouter(char* Copy_u8StrSsid, char* Copy_u8StrPassword);
void HESP_voidConnectToServer(char* Copy_u8StrMode, char* Copy_u8StrIP, char* Copy_u8StrPort);
u8 HESP_u8ExecuteRequest(char* Copy_u8StrRequest);

#endif
