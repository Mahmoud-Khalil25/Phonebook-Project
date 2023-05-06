#ifndef MENU
#define MENU
#include "Read.h"

void menu() //Main Menu
{
    sfx();
    char x;
    int flag=0;
    printf("\t\tWelcome to the Phonebook, Please choose: \n\n");
    printf("1.Print Contacts\n\n2.Search Contact\n\n3.Add Contact\n\n4.Modify Contact\n\n5.Delete Contact\n\n6.Save\n\n7.Quit\n\n\n");

    do
    {
        scanf("%s",&x);

        switch (x)
        {
        case'1':
                system("cls");
            sorting_menu();
            break;

        case'2':
                system("cls");
            search();
            break;

        case '3':
            system("cls");
            addnew();
            break;

        case '4':
            system("cls");
            modify();
            break;

        case '5':
            system("cls");
            del();
            break;

        case '6':
            system("cls");
            save();
            break;

        case '7':
            system("cls");
            quit();
            break;

        default:
            printf("\nWrong input, please choose again:\n");
            flag=1;
            break;
        }
    }
    while(flag==1);
}

#endif // MENU
