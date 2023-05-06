#ifndef SORT_LIST
#define SORT_LIST
#include "Read.h"

void list() //To list sorted contacts
{
    int j;
    for(j=0; j<i; j++)
    {
        printf("#%d\n",j+1);
        printf("First Name: %s\n",contacts[j].fname);
        printf("Last Name: %s\n",contacts[j].lname);
        printf("Birthdate: %s/%s/%s\n",contacts[j].bd.day,contacts[j].bd.month,contacts[j].bd.year);
        printf("Address: %s\n",contacts[j].address);
        printf("Email: %s\n",contacts[j].email);
        printf("Phone Number: %s\n\n",contacts[j].phone);
    }
    printf("\nPress any key to get back to menu...\n");
    getch();
    menu();
}

void sorting_menu() //TO choose sorting method
{
    int flag=0;
    char x;
    printf("How would you like to sort?\n1.By Birth date\n2.By Last name\n");

//both methods are done using bubble sort
    do
    {
        scanf("%s",&x);
        switch(x)
        {
        case'1':
                sort_birth();
            break;

        case'2':
                sort_last();
            break;

        default:
            printf("\nWrong input, please choose again:\n");
            flag=1;
            break;
        }
    }
    while (flag==1);
}

void sort_birth() //To sort by Birthdate
{
    int x,j;
    contact temp;

    for(x=0; x<=i; x++)
    {
        for(j=0; j<i-x-1; j++)
        {
            if (stricmp(contacts[j+1].bd.year,contacts[j].bd.year)<0)
            {
                temp=contacts[j];
                contacts[j]=contacts[j+1];
                contacts[j+1]=temp;
            }
            else if (stricmp(contacts[j].bd.year,contacts
                             [j+1].bd.year)==0 && contacts[j+1].bd.month[0]<contacts[j].bd.month[0]&&strlen(contacts[j+1].bd.month)==strlen(contacts[j].bd.month))
            {
                temp=contacts[j];
                contacts[j]=contacts[j+1];
                contacts[j+1]=temp;
            }

            else if (stricmp(contacts[j].bd.year,contacts
                             [j+1].bd.year)==0 && contacts[j+1].bd.month[0]==contacts[j].bd.month[0] && contacts[j+1].bd.month[1]<contacts[j].bd.month[1])
            {
                temp=contacts[j];
                contacts[j]=contacts[j+1];
                contacts[j+1]=temp;
            }

            else if (stricmp(contacts[j].bd.year,contacts[j+1].bd.year)==0 && stricmp(contacts[j].bd.month,contacts[j+1].bd.month)==0 &&
                     contacts[j+1].bd.day[0]<contacts[j].bd.day[0]&&strlen(contacts[j+1].bd.day)==strlen(contacts[j].bd.day))
            {
                temp=contacts[j];
                contacts[j]=contacts[j+1];
                contacts[j+1]=temp;
            }
            else if (stricmp(contacts[j].bd.year,contacts[j+1].bd.year)==0 && stricmp(contacts[j].bd.month,contacts[j+1].bd.month)==0 &&
                     contacts[j+1].bd.day[0]==contacts[j].bd.day[0] && contacts[j+1].bd.day[1]<contacts[j].bd.day[1])

            {
                temp=contacts[j];
                contacts[j]=contacts[j+1];
                contacts[j+1]=temp;
            }

        }
    }

    list();
}

void sort_last() //To sort by Last Name
{
    int x,j,n;
    contact temp;
    for(x=0; x<=i; x++)
        for(j=0; j<i-x-1; j++)
            if(stricmp(contacts[j].lname,contacts[j+1].lname)>0)
            {
                temp=contacts[j];
                contacts[j]=contacts[j+1];
                contacts[j+1]=temp;

            }

    list();
}


#endif // SORT_LIST
