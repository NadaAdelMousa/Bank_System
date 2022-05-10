#include "AdminWindow.h"

int main(void)
{  
    int choice;
    while(1)
    {
        system(“clear”);
        printf("****Admin Window****\n\n\n");
        printf("1- Create New Account.\n");
        printf("2- Open An Existing Account.\n");
        printf("3- Exit the System.\n\n\n");
        printf("please Enter 1,2 or 3 : ");

        scanf("%d",&choice);

        if (choice==1){

            system(“clear”);
            printf("****Creating New Account****\n\n\n");

            Client* client;

            printf("Enter Full Name: ");
            gets(client->Full_Name);
            fflush(stdin);

            printf("Enter Full Address: ");
            gets(client->Full_Address);
            fflush(stdin);

            printf("Enter National ID: ");
            gets(client->National_ID);
            fflush(stdin);

            printf("Enter Age: ");
            scanf("%d",&client->Age);
            fflush(stdin);

            if (client->Age < 21 ){
                printf("Enter Guardian National ID: ");
                gets(client->Guardian_National_ID);
                fflush(stdin);
            }

            printf("Enter Balance: ");
            scanf("%d",&client->Balance);
            fflush(stdin);

            client->Password = Generate_Password();
            client->Bank_Account_ID = Generate_ID();
            client->Account_Status = "Active";

            if (Create_Account(client) == 1){
                system(“clear”);
                printf("****New Account was created successfully****\n\n\n");
                printf("press any key to return to main window: ");
                scanf("%d",&choice);
            }
        }

        else if(choice==2){
            printf("Enter An Account ID to open: ");
            unsigned long Account_ID;
            scanf("lu",&Account_ID);
            Client* client1 = Open_Account(Account_ID);

            system(“clear”);
            printf("1- Make Transactions.\n");
            printf("2- Change Account Status.\n");
            printf("3- Get Cash.\n");
            printf("4- Deposit In Account.\n\n\n");
            printf("please Enter 1,2,3 or 4 : ");

            scanf("%d",&choice);

            if(choice==1){
                printf("****Making Transaction****\n\n\n");

                printf("Enter An Account ID to Transfer to : ");
                unsigned long Account_ID;
                scanf("lu",&Account_ID);
                Client* client2 = Open_Account(Account_ID);

                printf("Enter Amount of money to transfer : ");
                double amount;
                scanf("lf",&amount);

                if (Make_Transactions(client1,client2,amount) == 1){
                    system(“clear”);
                    printf("****Transaction was made successfully****\n\n\n");
                    printf("press any key to return to main window: ");
                    scanf("%d",&choice);
                }
            }
            else if(choice==2){
                printf("****Change Account Status****\n\n\n");

                printf("Enter the new Status : ");
                gets(client1->Account_Status);
                fflush(stdin);
            }

            else if(choice==3){
                printf("****Get Cash****\n\n\n");

                printf("Enter Amount of money to withdraw : ");
                double amount;
                scanf("lf",&amount);

                if (Get_Cash(client1,amount) == 1){
                    system(“clear”);
                    printf("****Transaction was made successfully****\n\n\n");
                    printf("press any key to return to main window: ");
                    scanf("%d",&choice);
                }
            }
            else if(choice==4){
                printf("****Deposit In Account****\n\n\n");

                printf("Enter Amount of money to deposit : ");
                double amount;
                scanf("lf",&amount);

                if (Deposit_In_Account(client1,amount) == 1){
                    system(“clear”);
                    printf("****Transaction was made successfully****\n\n\n");
                    printf("press any key to return to main window: ");
                    scanf("%d",&choice);
                }
            }

        }
        else if (choice==3){
            return 0;
        }
    }
   
   return 0;
}
