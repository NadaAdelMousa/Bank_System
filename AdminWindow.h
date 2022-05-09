/*****************************************/
/*            Author: Nada Adel          */
/*             Banking System            */
/*              9 May 2022               */
/*               Version 1               */
/*****************************************/

#ifndef AdminWindow
#define AdminWindow

#include <stdio.h>
#include <stdlib.h>

typedef struct{
   char Full_Name[50];
   char Full_Address[50];
   char National_ID[15];
   int Age;
   char Guardian_National_ID[15];
   char Account_Status[12];
   double Balance;
   unsigned long Bank_Account_ID;
   char Password[11];
} Client;

char* Generate_Password();
unsigned long Generate_ID();
int Create_Account(Client* client);
Client* Open_Account(unsigned long Account_ID);
int Make_Transactions(Client* client1, Client* client2, double transfered_amonut);
int Change_Account_Status(Client* client, char Account_Status[12]);
int Get_Cash(Client* client, double withdrawned_amonut);
int Deposit_In_Account(Client* client, double deposit_amonut);
void Exit_the_System();

#endif