#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "STD_types.h"
#include "func.h"
#include<ctype.h>

extern C_acc head;
extern A_acc e1;
extern u32 sign	,op,acc_type;
extern u8 user[20];
extern u8 pass[20];
extern u8 id[10];
extern u8 c_id[10];

u32 global_u32clientLength = 0;
u32 global_u32adminLength = 0;

void Add_admin(void)
{
	 if (global_u32adminLength==0)
    {
		printf("\n\t\tWelcome To IMT Bank!\n\n");		
		A_acc *last = &e1;
		for(;;)
		{
			u8 N_spaceCount=0;
			u8 N_Uppercase=0;
			printf("Enter Your Username to create the fist Admin account: ");
			fflush(stdin);
			scanf("%[^\n]s",last->a_user);
			for(int i=0 ; last->a_user[i]!= '\0' ; i++)
			{
				if(last->a_user[i] == ' ')
				{
					N_spaceCount++;
				}
				if(isupper(last->a_user[i]))
				{
					N_Uppercase++;
				}
			}
			if((strlen(last->a_user) >= 4) && (N_spaceCount == 0) && (N_Uppercase >= 1))
			{
				break;
			}
			printf("Username Must Conatain at least 4 characters, at least 1 Upper Case character and no spaces\n\n");
		}
		for(;;)
		{
			u8 P_spaceCount=0;
			u8 P_Uppercase=0;
			printf("Enter your Password: ");
			fflush(stdin);
			scanf("%s",last->a_pass);
			for(int i =0; last->a_pass[i]!= '\0' ; i++)
			{
				if(last->a_pass[i] == ' ')
				{
					P_spaceCount++;
				}
				if(isupper(last->a_pass[i]))
				{
					P_Uppercase++;
				}
			}
			if((strlen(last->a_pass) >= 4) && (P_spaceCount == 0) && (P_Uppercase >= 1))
			{
				break;
			}
			printf("Password Must Conatain at least 4 characters, at least 1 Upper Case character and no spaces\n\n");
		}
		e1.next = NULL;
    }
    else
    {
        A_acc *last;
		A_acc *new = (A_acc *) malloc(sizeof(A_acc));
		for(;;)
		{
			u8 N_spaceCount=0;
			u8 N_Uppercase=0;
			printf("Enter Your Username: ");
			fflush(stdin);
			scanf("%[^\n]s",new->a_user);
			for(int i=0 ; new->a_user[i]!='\0' ; i++)
				{
					if(new->a_user[i] == ' ')
					{
						N_spaceCount++;
					}
					if(isupper(new->a_user[i]))
					{
						N_Uppercase++;
					}
				}
				if((strlen(new->a_user) >= 4) && (N_spaceCount == 0) && (N_Uppercase >= 1))
				{
					break;
				}
				printf("Username Must Conatain at least 4 characters, at least 1 Upper Case character and no spaces\n\n");
		}
		for(;;)
		{
			u8 P_spaceCount=0;
			u8 P_Uppercase=0;
			printf("Enter your Password: ");
			fflush(stdin);
			scanf("%s",new->a_pass);
			for(int i=0 ; new->a_pass[i]!='\0' ; i++)
			{
				if(new->a_pass[i] == ' ')
				{
					P_spaceCount++;
				}
				if(isupper( new->a_pass[i]))
				{
					P_Uppercase++;
				}
			}
			if((strlen(new->a_pass) >= 4) && (P_spaceCount == 0) && (P_Uppercase >= 1))
			{
				break;
			}
			printf("Password Must Conatain at least 4 characters, at least 1 Upper Case character and no spaces\n\n");
		}
        new -> next = NULL;
        last = &e1;
        while ((last -> next)!=NULL)
        {
            last = last -> next;
        }
        last -> next = new;
	}

    global_u32adminLength++;
	

}

void sign_in(void)
{
	printf("\t\tWelcome To IMT Bank!\n\nPlease Choose Your Sign in Option:\n1.Admin\n2.Client\n3.Exit\n");
	scanf("%u",&sign);
		switch(sign)
	{
		case 1:  Admin_login();
				 break;
		case 2:  Client_login();
				 break;
		case 3:  exit(0);
				 break;
		default: printf("Sign in Option you choosed is Invalid\nPlease Try Again\n");
				 sign_in();
				 break;
	}

}

void Admin_login(void)
{
	A_acc *ptr=&e1;
	printf("Please Enter The Username: ");
	fflush(stdin);
	scanf("%[^\n]s",user);
	while(ptr!=NULL)
	{
		if(strcmp(user,ptr->a_user)==0)
		{
			u32 i=0;
			printf("Enter You Password: ");
			fflush(stdin);
			scanf("%s",pass);
			if(strcmp(pass,ptr->a_pass)==0)
				{
					A_op();
					break;
				}
			else
			{
				for( i ; i<2 ; i++)
				{				
					printf("Password is incorrect\nPlease Try Again\nEnter You Password: ");
					fflush(stdin);
					scanf("%s",pass);
					if(strcmp(pass,ptr->a_pass)==0)
					{
						A_op();
						break;
					}		
				}
			}
			if(i==2)
			{
				printf("Incorrect passowrd for 3 times, No More Tries\n");
				sign_in();
			}
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	if(ptr==NULL)
	{
		printf("Username you entered is invalid\n\n");
		sign_in();
	}
}

void Client_login(void)
{
	printf("Please Enter Bank ID: ");
	scanf("%s",id);
	C_acc *ptr=&head;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->bank_id,id)==0)
		{
			u32 i=0;
			printf("Enter You Password: ");
			fflush(stdin);
			scanf("%s",pass);
			if(strcmp(pass,ptr->c_pass)==0)
				{
					C_op(ptr);
					break;
				}
			else
			{
				for( i ; i<2 ; i++)
				{	
					printf("Incorrect Password \nPlease Try Again\nEnter You Password: ");
					fflush(stdin);
					scanf("%s",pass);
					if(strcmp(pass,ptr->c_pass)==0)
					{
						C_op(ptr);
						break;
					}
				}
			}
			if(i==2)
			{
				printf("Incorrect passowrd for 3 times, No More Tries\n");
				sign_in();
			}
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	if(ptr==NULL)
	{
		printf("ID is not registered \n\n");
		sign_in();
	}
}

void user_id (void)
{
	printf("Please Enter Bank ID: ");
	scanf("%s",c_id);
	C_acc *ptr=&head;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->bank_id,c_id)==0)
		{
			A_op2(ptr);	
			break;
		}
		else
		{
		ptr=ptr->next;
		}
	}
	if(ptr==NULL)
	{
		printf("ID is not registered \n\n");
		A_op();
	}
}

void A_op(void)
{
	printf("Choose The Operation\n1.Create New Acount\n2.Open Existing Account\n3.Exit System\n");
	scanf("%u",&op);
	switch(op)
	{
		case 1: for(;;)
				{
					printf("1-Add an Admin account \t 2-Add a Client account\n");
					scanf("%u",&acc_type);
					if(acc_type==1)
					{
						Add_admin();
						break;
					}
					else if(acc_type==2)
					{
						Add_client();
						break;
					}
					else
					{
						printf("Wrong choice please Try Again\n");
					}
				}
				A_op();
				break;
		case 2: user_id();
				break;
		case 3: sign_in();
				break;
		default:printf("Operation Number you choosed is not available\nPlease Try Again\n");
				A_op();
				break;
	}
}

void A_op2 (C_acc *ptr)
{
	print_client_data(ptr);
	printf("\nChoose The Operation\n1.Make a Transaction\n2.Change Account Status\n3.Get Cash\n4.Deposit in Account\n5.Return to previous menu\n");
	scanf("%u",&op);
	switch(op)
	{
		case 1: Make_transaction(ptr);
				A_op2(ptr);
				break;
		case 2: Change_acc_status(ptr);
				A_op2(ptr);
				break;
		case 3: Get_cash(ptr);
				A_op2(ptr);
				break;
		case 4: Deposit(ptr);
				A_op2(ptr);
				break;
		case 5: A_op();
				break;
		default:printf("Operation Number you choosed is not available\nPlease Try Again\n");
				A_op2(ptr);
				break;
	}	
}

void Add_client (void)
{
    if (global_u32clientLength==0)
    {		
		C_acc *last = &head;
		for(;;)
		{	
			u8 Upper_case=0;
			u8 N_spaceCount=0;
			printf("Enter Client's Full Name: ");
			fflush (stdin);
			scanf("%[^\n]s",last->name);		
			for (int i = 0; last->name[i] != '\0'; i++) 
			{
				if (last->name[i] == ' ') 
				{
					N_spaceCount++;
				}
				if (isupper(last->name[i]))
				{
					Upper_case++;
				}
			}
			if ((N_spaceCount == 3) && (Upper_case >= 4))
			{
				break;
			}
			printf("You Must Enter Four Names Starting With Upper Case Letters!\n\n");								
		}
	
		for(;;)
		{
			u8 A_spaceCount=0;
			printf("Enter Client's Full Address: ");
			fflush (stdin);
			scanf("%[^\n]s",last->address);
			for (int i = 0; last->address[i] != '\0'; i++) 
			{
				if (last->address[i] == ' ') 
				{
					A_spaceCount++;
				}
			}
			if (A_spaceCount >= 2) 
			{
				break;
			}
			printf("You Must Enter Full Adress\n");				
		}
		
		for(;;)
			{
				printf("Enter Client's National ID: ");
				scanf("%s",last->national_id);
				if(strlen(last->national_id)==14)
				{
					last->national_id[14]='\0';
					break;
				}
				printf("National ID must consist of Exactly 14 Numbers\n\n");
			}
		
		
		printf("Enter Client's Age: ");
		scanf("%u",&last->age);
		if(last->age < 21)
		{
			for(;;)
			{	
				u8 Upper_case=0;
				u8 N_spaceCount=0;
				printf("Enter Guardian's Full Name: ");
				fflush (stdin);
				scanf("%[^\n]s",last->g_name);		
				for (int i = 0; last->g_name[i] != '\0'; i++) 
				{
					if (last->g_name[i] == ' ') 
					{
						N_spaceCount++;
					}
					if (isupper(last->g_name[i]))
					{
						Upper_case++;
					}
				}
				if ((N_spaceCount == 3) && (Upper_case >= 4))
				{
					break;
				}
				printf("You Must Enter Four Names Starting With Upper Case Letters!\n\n");								
			}
			
			for(;;)
			{
				printf("Enter Guardian's National ID: ");
				scanf("%s",last->g_national_id);
				if(strlen(last->g_national_id)==14)
				{
					last->g_national_id[14]='\0';
					break;
				}
				printf("National ID must consist of Exactly 14 Numbers\n\n");
			}
			
		}
		
		for(int j=0 ; j<10; j++)
		{
			last->bank_id[j] = '0' + (rand() % 10);
		}
		last->bank_id[10] = '\0';	
		
		last->acc_status = 1;
		
		printf("Enter Client's Balance: ");
		scanf("%f",&last->balance);
		
		for(int j=0 ; j<4; j++)
		{
			last->c_pass[j] = '0' + (rand() % 10);
		}
		last->c_pass[4] = '\0';
		
		printf("Your Bank Account ID is %s\n",last->bank_id);
		printf("Your Account Password is %s\n",last->c_pass);				
        head.next = NULL;
    }
    else
    {
        C_acc *last;
		C_acc *new = (C_acc *) malloc(sizeof(C_acc));
		for(;;)
		{	
			u8 N_spaceCount=0;
			u8 Upper_case=0;		
			printf("Enter Client's Full Name: ");
			fflush (stdin);
			scanf("%[^\n]s",new->name);		
			for (int i = 0; new->name[i] != '\0'; i++) 
			{
				if (new->name[i] == ' ') 
				{
					N_spaceCount++;
				}
				if (isupper(new->name[i]))
				{
					Upper_case++;
				}
			}
			if ((N_spaceCount == 3) && (Upper_case >= 4))
			{
				break;
			}
			printf("You Must Enter Four Names Starting With Upper Case Letters!\n\n");							
		}
	
		for(;;)
		{
			u8 A_spaceCount=0;
			printf("Enter Client's Full Address: ");
			fflush (stdin);
			scanf("%[^\n]s",new->address);
			for (int i = 0; new->address[i] != '\0'; i++) 
			{
				if (new->address[i] == ' ') 
				{
					A_spaceCount++;
				}
			}
			if (A_spaceCount >= 2) 
			{
				break;
			}
			printf("You Must Enter Full Adress\n");				
		}
		
		for(;;)
			{
				printf("Enter Client's National ID: ");
				scanf("%s",new->national_id);
				if(strlen(new->national_id)==14)
				{
					new->national_id[14]='\0';
					break;
				}
				printf("National ID must consist of Exactly 14 Numbers\n\n");
			}
		
		
		printf("Enter Client's Age: ");
		scanf("%u",&new->age);
		if(new->age < 21)
		{
			for(;;)
			{	
				u8 Upper_case=0;
				u8 N_spaceCount=0;
				printf("Enter Guardian's Full Name: ");
				fflush (stdin);
				scanf("%[^\n]s",new->g_name);		
				for (int i = 0; new->g_name[i] != '\0'; i++) 
				{
					if (new->g_name[i] == ' ') 
					{
						N_spaceCount++;
					}
					if (isupper(new->g_name[i]))
					{
						Upper_case++;
					}
				}
				if ((N_spaceCount == 3) && (Upper_case >= 4))
				{
					break;
				}
				printf("You Must Enter Four Names Starting With Upper Case Letters!\n\n");								
			}
			
			for(;;)
			{
				printf("Enter Guardian's National ID: ");
				scanf("%s",new->g_national_id);
				if(strlen(new->g_national_id)==14)
				{	
					new->g_national_id[14]='\0';
					break;
				}
				printf("National ID must consist of Exactly 14 Numbers\n\n");
			}
		}
		
		for(int j=0 ; j<10; j++)
		{
			new->bank_id[j] = '0' + (rand() % 10);
		}
		new->bank_id[10] = '\0';
		
		new->acc_status = 1;
		
		printf("Enter Client's Balance: ");
		scanf("%f",&new->balance);
		
		for(int j=0 ; j<=3; j++)
		{
			new->c_pass[j] = '0' + (rand() % 10);
		}
		new->c_pass[4]= '\0' ;
		
		printf("Your Bank Account ID is %s\n",new->bank_id);
		printf("Your Account Password is %s\n",new->c_pass);
				
        new -> next = NULL;
        last = &head;
        while ((last -> next)!=NULL)
        {
            last = last -> next;
        }
        last -> next = new;
    }
    global_u32clientLength++;
}

void C_op (C_acc *ptr)
{
	printf("\nYour Balance is: %.2f\n",ptr->balance);
	printf("\nChoose The Operation\n1.Make a Transaction\n2.Change Account Password\n3.Get Cash\n4.Deposit in Account\n5.Return to main menu\n");
	scanf("%u",&op);
	switch(op)
	{
		case 1: Make_transaction(ptr);
				C_op(ptr);
				break;
		case 2: Change_pass(ptr);
				C_op(ptr);
				break;
		case 3: Get_cash(ptr);
				C_op(ptr);
				break;
		case 4: Deposit(ptr);
				C_op(ptr);
				break;
		case 5: sign_in();
				break;
		default:printf("Operation Number you choosed is not available\nPlease Try Again\n");
				C_op(ptr);
				break;
	}
}

void print_client_data(C_acc *ptr)
{
	printf("\nFull Name: %s\n",ptr->name);
	printf("Full Address: %s\n",ptr->address);
	printf("National ID: %s\n",ptr->national_id);
	printf("Age: %u\n",ptr->age);
	printf("Bank Account ID: %s\n",ptr->bank_id);
	if(ptr->age < 21)
	{
		printf("Guardian's Full Name: %s\n",ptr->g_name);
		printf("Guardian's National ID: %s\n",ptr->g_national_id);
	}
	if(ptr->acc_status==1)
	{
		printf("Account Status: Active\n");
	}
	else if(ptr->acc_status==2)
	{
		printf("Account Status: Restricted\n");
	}
	else if(ptr->acc_status==3)
	{
		printf("Account Status: Closed\n");
	}
	printf("Balance: %.2f\n",ptr->balance);
	printf("Password: %s\n",ptr->c_pass);
}

void Make_transaction(C_acc *ptr)
{
	if(ptr->acc_status == 1)
	{
		u8 id1[10];
		f32 money;
		printf("please Enter the Bank Account ID you want to transfere money to: ");
		scanf("%s",&id1);
		C_acc *last=&head;
		while(last!=NULL)
		{
			if(strcmp(last->bank_id,id1)==0)
			{
				if(last->acc_status == 1)
				{
					printf("please Enter the amount of money to be transfered: ");
					scanf("%f",&money);
					if(money < ptr->balance)
					{
						(last->balance)=(last->balance)+money;
						(ptr->balance)=(ptr->balance)-money;
						printf("Transaction Successful\n");
						break;
					}
					else
					{
						printf("Transaction Failed!\nYour Balance is insufficient\n");
						break;
					}
				}
				else
				{
					printf("Operation Denied\nReceiving Account is Restricted or Closed \n");
					break;
				}
			}
			else
			{
				last=last->next;
			}
		}
		if(last==NULL)
		{
			printf("ID of Receiving account is not registered \n");
		}
	}
	else
	{
		printf("Operation Denied\nClient's Account is Restricted or Closed \n");
	}
}

void Change_acc_status (C_acc *ptr)
{
	u32 status;
	printf("Choose Account Status:\n1.Active\n2.Restricted\n3.Closed\n");
	scanf("%u",&status);
	ptr->acc_status=status;
}

void Get_cash (C_acc *ptr)
{
	if(ptr->acc_status ==1)
	{
		f32 cash;
		printf("Enter the amount of money to be withdrawn: ");
		scanf("%f",&cash);
		if(cash < ptr->balance)
		{
			(ptr->balance)=(ptr->balance)-cash;
			printf("Process Successful\n");
		}
		else
		{
			printf("Process Failed\nYour Balance is insufficient\n");
		}
	}
	else
	{
		printf("Operation Denied\nClient's Account is Restricted or Closed \n");
	}
}

void Deposit (C_acc *ptr)
{
	if(ptr->acc_status == 1)
	{
		f32 cash;
		printf("Enter the amount of money you want to add to your balance: ");
		scanf("%f",&cash);
		(ptr->balance)=(ptr->balance)+cash;
		printf("Process Successful\n");
	}
	else
	{
		printf("Operation Denied\nClient's Account is Restricted or Closed \n");
	}
}

void Change_pass (C_acc *ptr)
{
	if(ptr->acc_status == 1)
	{
		u8 old_pass[4];
		u32 i=0;
		printf("Enter You Password: ");
		fflush(stdin);
		scanf("%s",old_pass);
		if(strcmp(old_pass, ptr->c_pass)==0)
		{
			for(;;)
			{
				printf("Enter The New Password: ");
				scanf("%s",ptr->c_pass);
				if(strlen(ptr->c_pass)==4)
				{
					break;
				}
				printf("Password must consist of 4 Numbers\n\n");
			}
		}
		else
		{
			for( i ; i<2 ; i++)
			{	
				printf("Incorrect Password\nPlease Try Again\nEnter You Password: ");
				fflush(stdin);
				scanf("%s",old_pass);
				if(strcmp(old_pass, ptr->c_pass)==0)
				{
					for(;;)
					{
						printf("Enter The New Password: ");
						scanf("%s",ptr->c_pass);
						if(strlen(ptr->c_pass)==4)
						{
							break;
						}
						printf("Password must consist of 4 Numbers\n\n");
					}
					break;
				}
			}
		}
		if(i==2)
		{
			printf("Incorrect passowrd for 3 times, No More Tries\n");
		}
	}
	else
	{
		printf("Operation Denied\nClient's Account is Restricted or Closed \n");
	}
}