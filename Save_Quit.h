#ifndef SAVE_QUIT
#define SAVE_QUIT
#include "Read.h"

void save() //To save changes made to contacts
{
    FILE *fw;
    fw=fopen("contacts.txt","w");
    int j;
    for(j=0; j<i; j++)
        fprintf(fw,"%s,%s,%s/%s/%s,%s,%s,%s\n",contacts[j].fname,contacts[j].lname,contacts[j].bd.day,contacts[j].bd.month,contacts[j].bd.year,contacts[j].address,contacts[j].email,contacts[j].phone);
    fclose(fw);
    printf("your data have been saved\n");
    printf("Press any key to get back to menu...\n");
    getch();
    menu();
}

void quit() //To quit program
{
    printf("\nWarning ! Any unsaved changes will be discarded, Are you sure you want to quit ?\n");
    char YN;
    int flag=0;
    do
    {
        printf("\n1.Yes\n2.No\n");
        scanf("%s",&YN);
        switch(YN)
        {
        case '1':
            exit(0);
            break;

        case '2':
            main();
            break;

        default:
            printf("\nwrong input, please choose again:\n");
            flag=1;
            break;
        }
    }
    while(flag==1);
}



#endif // SAVE_QUIT
