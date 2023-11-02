
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"



int main ()
{
	u8 flag=0,flag2=0;
	u8 Local_u8Operation,loop=0;
	u32 Temp,Local_u8Key1=0,Local_u8Key2=0,Local_u8Result;
	PORT_voidInit();
	CLCD_voidInit();

	while(1)
	{

		do
		{
			Temp=KPD_u8GetPressedKey();
		}while(Temp == 0xff);

		if ((loop==1)&&(Temp=='@'))
		{
			CLCD_voidSendCommand(1);
			Local_u8Result=0;
			Local_u8Key1=0;
			Local_u8Key2=0;
			loop=0;
			flag=0;
			flag2=0;
		}

		if ((Temp =='+')||(Temp=='-')||(Temp=='*')||(Temp=='/'))
		{
			Local_u8Operation=Temp;
			CLCD_voidSendData(Local_u8Operation);
			while(loop != 1)
			{
				do
				{
					Temp=KPD_u8GetPressedKey();
				}while(Temp == 0xff);

				if(Temp =='=')
				{
					CLCD_voidSendData(Temp);
					switch (Local_u8Operation)
					{
					case '+':Local_u8Result=Local_u8Key1+Local_u8Key2;break;
					case '-':Local_u8Result=Local_u8Key1-Local_u8Key2;break;
					case '*':Local_u8Result=Local_u8Key1*Local_u8Key2;break;
					case '/':Local_u8Result=Local_u8Key1/Local_u8Key2;break;
					}
					if (Local_u8Operation=='/' && Local_u8Key2 ==0)
					{
						CLCD_voidSendString("ERROR");
						loop = 1;
					}
					else if((Local_u8Operation == '-') && (Local_u8Key2>Local_u8Key1))
					{
						CLCD_voidSendData('-');
						Local_u8Result=0;
						Local_u8Result=Local_u8Key2-Local_u8Key1;
						CLCD_voidWriteNumber(Local_u8Result);
						loop=1;
					}
					else
					{
						CLCD_voidWriteNumber(Local_u8Result);
						loop=1;
						/*if the user wanted to add another number*/
					}

				}
				else
				{
					flag2++;
					if (flag2==1)
					{
						Local_u8Key2=Temp;
						CLCD_voidSendData(Local_u8Key2+'0');
					}
					else if(flag2==2)
					{
						Local_u8Key2=(Local_u8Key2*10)+Temp;
						CLCD_voidSendData(Temp+'0');
					}
					else if(flag2==3)
					{
						Local_u8Key2=(Local_u8Key2*10)+Temp;
						CLCD_voidSendData(Temp+'0');
					}
					else if(flag2==4)
					{
						Local_u8Key2=(Local_u8Key2*10)+Temp;
						CLCD_voidSendData(Temp+'0');
					}
					else if(flag2==5)
					{
						Local_u8Key2=(Local_u8Key2*10)+Temp;
						CLCD_voidSendData(Temp+'0');
					}
				}

			}

		}
		else if(Temp!='@')
		{
			flag++;
			if (flag==1)
			{
				Local_u8Key1=Temp;
				CLCD_voidSendData(Local_u8Key1+'0');
			}
			else if(flag==2)
			{
				Local_u8Key1=(Local_u8Key1*10)+Temp;
				CLCD_voidSendData(Temp+'0');
			}
			else if(flag==3)
			{
				Local_u8Key1=((Local_u8Key1*10))+Temp;
				CLCD_voidSendData(Temp+'0');
			}
			else if(flag==4)
			{
				Local_u8Key1=(Local_u8Key1*10)+Temp;
				CLCD_voidSendData(Temp+'0');
			}
			else if(flag==5)
			{
				Local_u8Key1=(Local_u8Key1*10)+Temp;
				CLCD_voidWriteNumber(Temp);
			}

		}
		else
		{
			//do nothing
		}
	}
}
