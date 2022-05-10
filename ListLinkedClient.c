/********************************************************/
/*        Auother    :     Asmaa Mohy                   */
/*        Description  :   List Linked of Client        */
/*        Date    :   10/5                              */
/********************************************************/

/********************************************************/
/*********** Preprocessing section **********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client
{
    /* data */
    char Full_Name[50];
   char Full_Address[50];
   char National_ID[15];
   int Age;
   char Guardian_National_ID[15];
   char Account_Status[12];
   double Balance;
   unsigned long Bank_Account_ID;
   char Password[11];
    struct client* next;
}Client;


typedef struct List
{
    /* data */
    Client* head;
    int size;

}List;

/********************************************************/
/*********** Functions prototype ************************/
void List_voidInti(List* pl);
void List_voidInsertList(int pos, List* pl,char name[50],char address[50],char national_id[15],int age,char gn_id[15],char status[12],double balance,unsigned long account_id,char passward[11]);
void List_voidDeleteList(int pos, List* pl,char *name[50],char *address[50],char *national_id[15],int *age,char *gn_id[15],char *status[12],double *balance,unsigned long *account_id,char *passward[11]);
void List_voidRetrieveList(int pos, List* pl,char *name[50],char *address[50],char *national_id[15],int *age,char *gn_id[15],char *status[12],double *balance,unsigned long *account_id,char *passward[11]);
void List_voidPrintElements(List* pl);
void List_voidDestroy(List* pl);
int List_intIsFull(List* pl);
int List_intIsEmpty(List* pl);
int List_intSize(List* pl);



int main()
{
    List l;
    char name[50]="Mohamed Salah Hamed Mahrous";
   char address[50]="Hussien Wassef, From El-Dokki st, Giza";
   char n_id[15]="29805070100179";
   int age=25;
   char gn_id[15]="29805070100179";
   char status[12]="Restricted";
   double balance=75000;
   unsigned long account_id=1000000000;
   char password[11]="6 Hussien Wassef, From El-Dokki st, Giza";


   /*name="Mohamed Salah Hamed Mahrous";
   address="Hussien Wassef, From El-Dokki st, Giza";
   n_id="29805070100179";
   age=25;
   gn_id="29805070100179";
   status="Restricted";
   balance=75000;
   account_id=1000000000;
   password="6 Hussien Wassef, From El-Dokki st, Giza";*/

   List_voidInti(&l);
   List_voidInsertList(0,&l,name,address,n_id,age,gn_id,status,balance,account_id,password);
   List_voidPrintElements(&l);


    return 0;
}

/********************************************************/
/*********** Functions Definitions **********************/

void List_voidInti(List* pl)
{
    pl->head = NULL;
    pl->size =0;
}
void List_voidInsertList(int pos, List* pl,char name[50],char address[50],char national_id[15],int age,char gn_id[15],char status[12],double balance,unsigned long account_id,char passward[11])
{ 
    Client* pn = (Client*)malloc(sizeof(Client));
    // insert data
    strcpy(pn->Full_Name, name);
    strcpy(pn->Full_Address,address);
    strcpy(pn->National_ID,national_id);
    pn->Age=age;
    strcpy(pn->Guardian_National_ID,gn_id);
    strcpy(pn->Account_Status,status);
    pn->Balance=balance;
    pn->Bank_Account_ID=account_id;
    strcpy(pn->Password,passward);

    pn->next=NULL;
    if(pos == 0)
    {
       pn->next=pl->head;
       pl->head=pn;
    }
    else
    {
       Client*q;
       int i;
       for(q=pl->head,i=0;i<pos-1;i++)
       {
           q=q->next;
       }
       pn->next=q->next;
       q->next=pn;
    }
    pl->size++;
}

void List_voidDeleteList(int pos, List* pl,char *name[50],char *address[50],char *national_id[15],int *age,char *gn_id[15],char *status[12],double *balance,unsigned long *account_id,char *passward[11])
{
    Client* pn;
    if(pos == 0)
    {
       
       // delete data
    *name =pl->head->Full_Name;
    *address=pl->head->Full_Address;
    *national_id=pl->head->National_ID;
    *age=pl->head->Age;
    *gn_id=pl->head->Guardian_National_ID;
    *status= pl->head->Account_Status;
    *balance=pl->head->Balance;
    *account_id=pl->head->Bank_Account_ID;
    *passward=pl->head->Password;



       pn=pl->head->next;
       free(pl->head);
       pl->head=pn;
    }
    else
    {
       Client*q;
       int i;
       for(q=pl->head,i=0;i<pos-1;i++)
       {
           q=q->next;
       }
       // delete data
    *name =pl->head->Full_Name;
    *address=pl->head->Full_Address;
    *national_id=pl->head->National_ID;
    *age=pl->head->Age;
    *gn_id=pl->head->Guardian_National_ID;
    *status= pl->head->Account_Status;
    *balance=pl->head->Balance;
    *account_id=pl->head->Bank_Account_ID;
    *passward=pl->head->Password;
       pn=q->next->next;
       free(q->next);
       q->next=pn;
    }
    pl->size--;
}
void List_voidRetrieveList(int pos, List* pl,char *name[50],char *address[50],char *national_id[15],int *age,char *gn_id[15],char *status[12],double *balance,unsigned long *account_id,char *passward[11])
{
    Client*q;
    int i;
    for(q=pl->head,i=0;i<pos;i++)
    {
        q=q->next;
    }
    *name =pl->head->Full_Name;
    *address=pl->head->Full_Address;
    *national_id=pl->head->National_ID;
    *age=pl->head->Age;
    *gn_id=pl->head->Guardian_National_ID;
    *status= pl->head->Account_Status;
    *balance=pl->head->Balance;
    *account_id=pl->head->Bank_Account_ID;
    *passward=pl->head->Password;
}
void List_voidPrintElements(List* pl)
{
    Client*tmp =pl->head;
    while (tmp !=NULL)
    {
        printf(" Full Name of Client %c\n",tmp->Full_Name);
        printf(" Full Address of Client %c\n",tmp->Full_Address);
        printf(" Age of Client %d\n",tmp->Age);
        printf(" Account Status of Client %c\n",tmp->Account_Status);
        printf(" Balance of Client %lf\n",tmp->Balance);
        printf(" Bank Account ID of Client %lld\n",tmp->Bank_Account_ID);
        tmp= tmp->next;
    }
    

}
void List_voidDestroy(List* pl)
{
    Client*tmp =pl->head;
    while (pl->head !=NULL)
    {
        tmp= pl->head->next;
        free(pl->head);
        pl->head=tmp;
    }
    pl->size=0;
}
int List_intIsFull(List* pl)
{
    return 0;
}
int List_intIsEmpty(List* pl)
{
    return (pl->head == NULL);
}
int List_intSize(List* pl)
{
    return pl->size;
}

