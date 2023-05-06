#ifndef VALIDATE
#define VALIDATE
#include "Read.h"

int validate_fname(contact contacts[],int k)
{
    int flag=0;
    if(strlen(contacts[k].fname)==0)
    {
        flag=1;
        printf("Nothing was entered ,please try again : ");
    }
    return(flag);
}

int validate_lname(contact contacts[],int k)
{
    int flag=0;
    if(strlen(contacts[k].lname)==0)
    {
        flag=1;
        printf("Nothing was entered ,please try again : ");
    }
    return(flag);
}

int validate_BD(contact contacts[],int k)
{
    time_t T= time(NULL);
    struct tm tm = *localtime(&T);
    int m;
    int yyyy=atoi(contacts[k].bd.year);
    int mm=atoi(contacts[k].bd.month);
    int dd=atoi(contacts[k].bd.day);

    if(yyyy>=1900 && yyyy<=(tm.tm_year+1900))
    {

        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                m=0;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                m=0;
            else if((dd>=1 && dd<=28) && (mm==2))
                m=0;
            else if(dd==29 && mm==2 && (yyyy%400==0 ||(yyyy%4==0 && yyyy%100!=0)))
                m=0;
            else
            {
                m=1;
                printf("Day is invalid , please try again : \n");
            }
        }
        else
        {
            m=1;
            printf("Month is not valid , please try again : \n");
        }
    }
    else
    {
        m=1;
        printf("Year is not valid , please try again : \n");
    }

    if((yyyy==tm.tm_year+1900&&mm>tm.tm_mon+1)||(yyyy==tm.tm_year+1900&&mm==tm.tm_mon+1&&dd>tm.tm_mday))
    {
        m=1;
        printf("Invalid date , please try again : \n");
    }
    return(m);
}

int validate_address(contact contacts[],int k)
{
    int flag=0;
    if(strlen(contacts[k].address)==0)
    {
        flag=1;
        printf("Nothing was entered ,please try again : ");
    }
    return(flag);
}

int validate_email(contact contacts[],int s)
{
    int flag=0,flag2=0,l,j,k;
    int n=strlen(contacts[s].email);
    for(l=0; l<n; l++)
    {
        if(contacts[s].email[l]=='@')
        {
            j=l;
            flag++;
        }
        else if(contacts[s].email[l]=='.')
        {
            k=l;
            flag2++;
        }
    }
    if(flag!=1||flag2!=1)           //check for existence of one "@" and 1 dot
    {
        printf("email format is not valid , please try again : ");
        return(1);
    }
    else if(contacts[s].email[0]=='@'||j>k||j==n||k==j+1||k!=n-4)     //check for positions of "@" and dot
    {
        printf("email format is not valid , please try again : ");
        return(1);
    }
    else if(contacts[s].email[n-3]!='c'||contacts[s].email[n-2]!='o'||contacts[s].email[n-1]!='m') //check for ".com"
    {
        printf("email format is not valid , please try again : ");
        return(1);
    }
    else
        return(0);
}

int validate_phone(contact contacts[],int k)
{
    int l;
    int flag=0;
    for(l=0; l<strlen(contacts[k].phone); l++)
    {
        if(contacts[k].phone[l]>57 ||contacts[k].phone[l]<48)
        {
            printf("wrong input please enter the number again : \n");
            flag=1;
            break;
        }
        else if(strlen(contacts[k].phone)>15)              //a number cannot exceed 15 digits according to the international standards
        {
            printf("number is too long please try again : ");
            flag=1;
            break;
        }

    }
    return(flag);
}


#endif // VALIDATE
