#ifndef _FUNC_H_
#define _FUNC_H_

typedef struct admin_account A_acc;
struct admin_account{
	u8 a_user[20];
	u8 a_pass[20];
	A_acc *next;
};

typedef struct client_account C_acc;
struct client_account{
	u8   name[70];
	u8   address[100];
	u8   national_id[15];
	u32  age;
	u8   bank_id[11];
	u8   g_name[70];
	u8   g_national_id[15];
	u32  acc_status;
	f32  balance;
	u8   c_pass[5];
	C_acc *next;
};

void Add_admin(void); //CODE LINE 19

void sign_in(void); //CODE LINE 141

void Admin_login(void); //CODE LINE 160

void Client_login(void); //CODE LINE 212

void user_id (void); //CODE LINE 263

void A_op(void); //CODE LINE 287

void A_op2 (C_acc *ptr); //CODE LINE 324

void Add_client (void); //CODE LINE 351

void C_op (C_acc *ptr); //CODE LINE 613

void print_client_data(C_acc *ptr); //CODE LINE 640

void Make_transaction(C_acc *ptr); //CODE LINE 668

void Change_acc_status (C_acc *ptr); //CODE LINE 720

void Get_cash (C_acc *ptr); //CODE LINE 728

void Deposit (C_acc *ptr); //CODE LINE 751

void Change_pass (C_acc *ptr); //CODE LINE 767


#endif