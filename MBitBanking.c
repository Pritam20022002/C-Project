#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void main_menu();

struct information{
    char name[50];
    char mob[10];
    char password[50];
};

void create(){

    //Collecting data and creating account---->.

    char name1[50],name2[50],num[10],pass1[50],pass2[50];
    int n=1;
    printf("\nWelcome to MBit Banking.Thanks for choosing us. >>>");
    printf("\n---------------------------------------------------\n");
    printf("Enter your first name : ");
    scanf("%s",&name1);
    printf("Enter your last name : ");
    scanf("%s",&name2);
    printf("NOTE : You should remember the phone number and the password as it will be required every time you deposite or withdraw money.");
    printf("\nEnter 10-Digit mobile number : +91 ");
    scanf("%s",&num);
    printf("Create Password (must be atleast of 8-Charecters) : ");
    scanf("%s",&pass1);  
    printf("Re-Enter Password : ");
    scanf("%s",&pass2);  

    struct information info;
    strcpy(info.name,name1);

    while(n==1){
        if(strlen(num)==10){
            strcpy(info.mob,num);
            break;
        }
        else{
            printf("\nEnter valid phone number!\n");
            n=0;
        }
    }
    while(n==1){
        if(strlen(pass1)>=8 && strcmp(pass1,pass2)==0){
            strcpy(info.password,pass1);
            break;
        }
        else{
            printf("\nCheck your password and enter again!\n");
            n=0;
        }
    }
    if(n==1){
        system("cls");
        
        FILE* fptr;
        fptr = fopen(info.mob, "r");
        if(fptr==NULL){
            fptr = fopen(info.mob, "w");
            fprintf(fptr,"0");
        }
        else{
            system("cls");
            printf("Account already exists!");
            main_menu();
        }
        fclose(fptr);
        printf("\n\nHello Mr/Mrs %s your account has been created successfully.\n\n",info.name);
    }
    else{
        printf("Task uncessful!");
    }
    main_menu();
}

void deposite(){

    // Taking the user ammount to deposite ----->
    
    struct information info;
    char num[10],pass1[50],pass2[50];
    char abalance[99999];
    char abalance2[99999];
    int n=1,intbal,add,newBalance;

    printf("Enter 10-Digit mobile number : +91 ");
    scanf("%s",&num);
    printf("Enter Password (must be atleast of 8-Charecters) : ");
    scanf("%s",&pass1);  
    printf("Re-Enter Password : ");
    scanf("%s",&pass2); 
    while(n==1){
        if(strlen(num)==10){
            strcpy(info.mob,num);
            break;
        }
        else{
            printf("\nEnter valid phone number!\n");
            n=0;
        }
    }
    while(n==1){
        if(strlen(pass1)>=8 && strcmp(pass1,pass2)==0){
            strcpy(info.password,pass1);
            break;
        }
        else{
            printf("\nCheck your password and enter again!\n");
            n=0;
        }
    }
    FILE* fptr;
    fptr = fopen(info.mob, "r");
    if(fptr==NULL){
        system("cls");
        printf("Oops! The password you have entered is wrong or this number dosent have any account linked to it!");
        main_menu();
    }
    else{
        printf("Enter the ammount you want to deposite : Rs ");
        scanf("%d",&add);
        while(fscanf(fptr,"%s\n",abalance)!=EOF){
            intbal=atoi(abalance);
            newBalance = intbal+add;
            printf("\nAmmount of Rs %d has been credited to your account.\n",add);
            printf("New Balance : Rs %d",newBalance);
            fclose(fptr);

            sprintf(abalance2,"%d",newBalance);
            remove(info.mob);
            FILE* f2ptr;
            f2ptr = fopen(info.mob, "w");
            fprintf(f2ptr,abalance2);
            fclose(f2ptr);
        }
    }  
    main_menu();
}

void withdraw(){

    // Taking the user ammount to withdraw ----->
    
    struct information info;
    char num[10],pass1[50],pass2[50];
    char abalance[99999];
    char abalance2[99999];
    int n=1,intbal,sub,newBalance;

    printf("Enter 10-Digit mobile number : +91 ");
    scanf("%s",&num);
    printf("Enter Password (must be atleast of 8-Charecters) : ");
    scanf("%s",&pass1);  
    printf("Re-Enter Password : ");
    scanf("%s",&pass2); 
    while(n==1){
        if(strlen(num)==10){
            strcpy(info.mob,num);
            break;
        }
        else{
            printf("\nEnter valid phone number!\n");
            n=0;
        }
    }
    while(n==1){
        if(strlen(pass1)>=8 && strcmp(pass1,pass2)==0){
            strcpy(info.password,pass1);
            break;
        }
        else{
            printf("\nCheck your password and enter again!\n");
            n=0;
        }
    }
    FILE* fptr;
    fptr = fopen(info.mob, "r");
    if(fptr==NULL){
        system("cls");
        printf("Oops! The password you have entered is wrong or this number dosent have any account linked to it!");
        main_menu();
    }
    else{
        printf("Enter the ammount you want to withdraw : Rs ");
        scanf("%d",&sub);
        while(fscanf(fptr,"%s\n",abalance)!=EOF){
            intbal=atoi(abalance);
            if(intbal>=sub){
                newBalance = intbal-sub;
                printf("\nAmmount of Rs %d has been debited from your account.\n",sub);
                printf("New Balance : Rs %d",newBalance);
                fclose(fptr);

                sprintf(abalance2,"%d",newBalance);
                remove(info.mob);
                FILE* f2ptr;
                f2ptr = fopen(info.mob, "w");
                fprintf(f2ptr,abalance2);
                fclose(f2ptr);
            }
            else{
                printf("\nInsufficient balance! can not withdraw this ammount.\n");
                break;
            }
        }
    }  
    main_menu();
}

void check(){

// Taking user details to check balance ----->

 struct information info;
    char num[10],pass1[50],pass2[50];
    char abalance[99999];
    char abalance2[99999];
    int n=1,intbal,newBalance;

    printf("Enter 10-Digit mobile number : +91 ");
    scanf("%s",&num);
    printf("Enter Password (must be atleast of 8-Charecters) : ");
    scanf("%s",&pass1);  
    printf("Re-Enter Password : ");
    scanf("%s",&pass2); 
    while(n==1){
        if(strlen(num)==10){
            strcpy(info.mob,num);
            break;
        }
        else{
            printf("\nEnter valid phone number!\n");
            n=0;
        }
    }
    while(n==1){
        if(strlen(pass1)>=8 && strcmp(pass1,pass2)==0){
            strcpy(info.password,pass1);
            break;
        }
        else{
            printf("\nCheck your password and enter again!\n");
            n=0;
        }
    }
    FILE* fptr;
    fptr = fopen(info.mob, "r");
    if(fptr==NULL){
        system("cls");
        printf("Oops! The password you have entered is wrong or this number dosent have any account linked to it!");
        main_menu();
    }
    else{
        while(fscanf(fptr,"%s\n",abalance)!=EOF){
            intbal=atoi(abalance);
            printf("Your current available balance is Rs %d",intbal);
        }
    }
    main_menu();
}

void delete(){

// Taking user details to delete account. ----->
    struct information info;
    char num[10],pass1[50],pass2[50];
    char abalance[99999];
    char abalance2[99999];
    int n=1,intbal,newBalance;

    printf("Enter 10-Digit mobile number : +91 ");
    scanf("%s",&num);
    printf("Enter Password (must be atleast of 8-Charecters) : ");
    scanf("%s",&pass1);  
    printf("Re-Enter Password : ");
    scanf("%s",&pass2); 
    while(n==1){
        if(strlen(num)==10){
            strcpy(info.mob,num);
            break;
        }
        else{
            printf("\nEnter valid phone number!\n");
            n=0;
        }
    }
    while(n==1){
        if(strlen(pass1)>=8 && strcmp(pass1,pass2)==0){
            strcpy(info.password,pass1);
            break;
        }
        else{
            printf("\nCheck your password and enter again!\n");
            n=0;
        }
    }
    FILE* fptr;
    fptr = fopen(info.mob, "r");
    if(fptr==NULL){
        system("cls");
        printf("Oops! The password you have entered is wrong or this number dosent have any account linked to it!");
        main_menu();
    }
    else{
        while(fscanf(fptr,"%s\n",abalance)!=EOF){
            intbal=atoi(abalance);
            if(intbal==0){
                fclose(fptr);
                remove(info.mob);
                system("cls");
                printf("Account Successfully deleted.");
                break;
            }
            else{
                printf("\nYou are having Rs %d left in your account.Please withdraw the ammount inorder to delete the account\n",intbal);
                break;
            }
        }
    }
    main_menu();
}




void main_menu(){

    //Display Main menu----->

    int choice;
    printf("\n\nWELCOME TO MBit Bank. ---> How can we help you.\n");
    printf("\n-----------------------------------------------\n");
    printf("\nEnter 1 to Create new account.\n");
    printf("\nEnter 2 to Deposite money.\n");
    printf("\nEnter 3 to Withdraw money.\n");
    printf("\nEnter 4 to Check balance.\n");
    printf("\nEnter 5 to Delete account.\n");
    printf("\n-----------------------------------------------\n");
    scanf("%d",&choice);
        
    switch(choice){
        case 1:
            create();
        break;

        case 2:
            deposite();
        break;

        case 3:
            withdraw();
        break;

        case 4:
            check();
        break;

        case 5:
            delete();
        break;

        default:
        printf("Invalid request!");
    }
}


int main(){
    system("cls");
    main_menu();
    return 0;
}