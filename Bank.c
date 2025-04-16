#include<stdio.h>
#include "STD_types.h"
#include "func.h"

C_acc head;
A_acc e1;
u32 sign,op,acc_type;
u8 user[20];
u8 pass[20];
u8 id[10];
u8 c_id[10];

int main()
{	
	Add_admin();
	sign_in();
}	