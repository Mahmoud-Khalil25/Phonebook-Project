#ifndef ADD_DELETE
#define ADD_DELETE
#include "Read.h"

void addnew(n) //Add new contact function
{
    int flag;
    char temp;
    printf("Please enter the following : \n");
    printf("\nFirst Name: ");
    do                                                           //validation for first name in case the user entered nothing
    {
        scanf("%c",&temp);
        scanf("%[^\n]",contacts[i].fname);
    }
    while(validate_fname(contacts,i));

    printf("\nLast Name: ");
    do                                                         //validation for last name in case the user entered nothing
    {
        scanf("%c",&temp);
        scanf("%[^\n]",contacts[i].lname);
    }
    while(validate_lname(contacts,i));

    printf("\nBirthdate in the form Day/Month/Year: ");
    do
    {
        scanf("%c",&temp);
        scanf("%[^/]/%[^/]/%[^\n]",&contacts[i].bd.day,&contacts[i].bd.month,&contacts[i].bd.year);
    }
    while(validate_BD(contacts,i));

    printf("\nAddress: ");
    do
    {
        scanf("%c",&temp);
        scanf("%[^\n]",contacts[i].address);
    }
    while(validate_address(contacts,i));

    printf("\nEmail in the form example@domain.com: ");
    do
    {
        scanf("%c",&temp);
        scanf("%[^\n]",contacts[i].email);
    }
    while(validate_email(contacts,i));

    printf("\nPhone Number: ");
    do
    {
        scanf("%c",&temp);
        scanf("%[^\n]",contacts[i].phone);
    }
    while(validate_phone(contacts,i));

    i++;
    printf("\nContact added successfully\n");
    printf("Press any key to get back to menu...\n");
    getch();
    menu();
}

void del() //To delete a contact
{
    int j=0,l,flag=0;
    printf("Enter last name:\n");
    char lname[30];
    scanf("%s",lname);
    printf("Enter first name:\n");
    char fname[30];
    scanf("%s",fname);

    while(j<=i)
    {
        if(stricmp(contacts[j].lname,lname)==0 && stricmp(contacts[j].fname,fname)==0)
        {
            flag=1;
            for(l=j; l<i-1; l++)
            {
                contacts[l]=contacts[l+1];
            }
            i--;
        }
        j++;
    }
    if(flag==0)
    {
        printf("\nThe name \"%s %s\" is not found !\n",fname,lname);
    }
    else
        printf("\nSuccessfully deleted\nPress any key to get back to menu...\n");
    getch();
    menu();
}


#endif // ADD_DELETE
