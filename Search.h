#ifndef SEARCH
#define SEARCH
#include "Read.h"

void search() //multi searching function
{
    contact a,s[MAXSIZE];
    char fname[50],lname[50],address[150],email[150],phone[15],year[13],temp;
    int n=0,flag=0,count=1;
    printf("Type the info you know about the contact and leave the rest blank: \n\n");
    printf("Enter contact's first name you want to search for: \n");
    scanf("%c",&temp);
    scanf("%[^\n]",fname);
    printf("Enter contact's last name you want to search for: \n");
    scanf("%c",&temp);
    scanf("%[^\n]",lname);
    printf("Enter contact's birthday year you want to search for: \n");
    scanf("%c",&temp);
    scanf("%[^\n]",year);
    printf("Enter contact's address you want to search for: \n");
    scanf("%c",&temp);
    scanf("%[^\n]",address);
    printf("Enter contact's email you want to search for: \n");
    scanf("%c",&temp);
    scanf("%[^\n]",email);
    printf("Enter contact's phone number you want to search for: \n");
    scanf("%c",&temp);
    scanf("%[^\n]",phone);
    int p=i,marker,marker2,b=0,u;
    for(p=0; p<i; p++)                              //linear searching method ((multi searching technique))
    {
        marker=1,marker2=0;
        u=strlen(fname);
        if(u>0)
        {
            marker2++;
            if(stricmp(fname,contacts[p].fname)!=0)
            {
                marker=0;
            }
        }
        u=strlen(lname);
        if(u>0)
        {
            marker2++;
            if(stricmp(lname,contacts[p].lname)!=0)
            {
                marker=0;

            }
        }

        u=strlen(year);
        if(u>0)
        {
            marker2++;
            if(stricmp(year,contacts[p].bd.year)!=0)
            {
                marker=0;
            }
        }

        u=strlen(address);
        if(u>0)
        {
            marker2++;
            if(stricmp(address,contacts[p].address)!=0)
            {
                marker=0;

            }
        }

        u=strlen(email);
        if(u>0)
        {
            marker2++;
            if(stricmp(email,contacts[p].email)!=0)
            {
                marker=0;

            }
        }
        u=strlen(phone);
        if(u>0)
        {
            marker2++;
            if(stricmp(phone,contacts[p].phone)!=0)
            {
                marker=0;

            }
        }
        if(marker==1&&marker2>0)
        {
            s[b]=contacts[p];
            b++;
        }
    }
    if(b==0)
        printf("No contacts were found\n");
    int j;
    for(j=0; j<b; j++)
    {
        printf("#%d\n",j+1);
        printf("First Name: %s\n",s[j].fname);
        printf("Last Name: %s\n",s[j].lname);
        printf("Birthdate: %s/%s/%s\n",s[j].bd.day,s[j].bd.month,s[j].bd.year);
        printf("Address: %s\n",s[j].address);
        printf("Email: %s\n",s[j].email);
        printf("Phone Number: %s\n\n",s[j].phone);
    }


    printf("\nPress any key to get back to menu...\n");
    getch();
    menu();
}


#endif // SEARCH
