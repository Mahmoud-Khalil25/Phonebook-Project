#ifndef MODIFY
#define MODIFY
#include "Read.h"

void modify() //To modify a contact
{
    int j=0,l,flag=0,flag2=0,count=0,s[500];
    char x,k=0,n=0;
    char temp;
    printf("Enter last name: \n");
    char name[30];
    scanf("%s",name);
    while(j<i)
    {
        if(stricmp(contacts[j].lname,name)==0)
        {
            printf("#%d\n",j);
            count++;
            printf("First Name: %s\n",contacts[j].fname);
            printf("Last Name: %s\n",contacts[j].lname);
            printf("Birthdate: %s/%s/%s\n",contacts[j].bd.day,contacts[j].bd.month,contacts[j].bd.year);
            printf("Address: %s\n",contacts[j].address);
            printf("Email: %s\n",contacts[j].email);
            printf("Phone Number: %s\n\n",contacts[j].phone);
            s[n]=j;
            n++;
        }
        j++;
    }
    if(count>0)
    {
        if(count>1)
        {
            printf("type the index number of the contact you want to modify : \n");
            do
            {
                scanf("%d",&k);
                for(l=0; l<n; l++)
                {
                    if(k==s[l])
                    {
                        flag2=1;
                        break;
                    }
                }
                if(flag2==0)
                {
                    printf("wrong input , please try again : \n");
                }
            }
            while(flag2==0);
        }
        printf("choose what you want to modify : \n");
        printf("1.First name\n2.Last Name\n3.Birthdate\n4.Address\n5.Email\n6.Phone Number\n");
        do
        {
            flag=0;
            scanf("%s",&x);
            switch(x)
            {
            case '1':
                printf("\nFirst Name: ");
                do                                                           //validation for first name in case the user entered nothing
                {
                    scanf("%c",&temp);
                    scanf("%[^\n]",contacts[k].fname);
                }
                while(validate_fname(contacts,k));
                break;

            case '2':
                printf("\nLast Name: ");
                do                                                         //validation for last name in case the user entered nothing
                {
                    scanf("%c",&temp);
                    scanf("%[^\n]",contacts[k].lname);
                }
                while(validate_lname(contacts,k));
                break;

            case '3':
                printf("\nBirthdate in the form Day/Month/Year: ");
                do
                {
                    scanf("%c",&temp);
                    scanf("%[^/]/%[^/]/%[^\n]",&contacts[k].bd.day,&contacts[k].bd.month,&contacts[k].bd.year);
                }
                while(validate_BD(contacts,k));
                break;

            case '4':
                printf("\nAddress: ");
                do
                {
                    scanf("%c",&temp);
                    scanf("%[^\n]",contacts[k].address);
                }
                while(validate_address(contacts,k));
                break;

            case '5':
                printf("\nEmail in the form example@domain.com: ");
                do
                {
                    scanf("%c",&temp);
                    scanf("%[^\n]",contacts[k].email);
                }
                while(validate_email(contacts,k));
                break;
            case '6':
                printf("\nPhone Number: ");
                do
                {
                    scanf("%c",&temp);
                    scanf("%[^\n]",contacts[k].phone);
                }
                while(validate_phone(contacts,k));
                break;
            default:
                printf("\nWrong input, please choose again:\n");
                flag=1;
                break;
            }
        }
        while(flag==1);
    }
    else
    {
        printf("\nThe name \"%s\" is not found !\n",name);
    }
    printf("\nPress any key to get back to menu...\n");
    getch();
    menu();
}

#endif // MODIFY
