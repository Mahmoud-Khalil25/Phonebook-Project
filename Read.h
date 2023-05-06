#ifndef READ
#define READ

int i=0; //Global Variables

typedef struct //Birthdate struct
{
    char day[5],month[4],year[13];
} birthdate;

typedef struct //Contact struct
{
    char fname[50];
    char lname[50];
    char email[150];
    char address[150];
    char phone[16];
    birthdate bd;
} contact;
contact contacts[MAXSIZE];

void sfx() //Background color and audio
{
    system("cls"); //To clear the output screen
    int Audio;
    system("color 1F"); //To change background color to blue
    for(Audio=0; Audio<2; Audio++) //To make 2 beep sounds
    {
        Beep(7000,500); //First number is for sound frequency, the second is for delay
    }
}

void load() //Load the contacts from the file
{
    FILE *fp;
    fp=fopen("contacts.txt","r");
    if(fp==NULL)
    {
        printf("File not found !\n");
    }
    else
    {
        char test[100];
        fscanf(fp,"%[^,],",test);                        //check if the file is empty or not , if it's empty it won't scan
        if(test!=NULL)
        {
            strcpy(contacts[i].fname,test);
            fscanf(fp,"%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%s\n",contacts[i].lname,contacts[i].bd.day,contacts[i].bd.month,contacts[i].bd.year,contacts[i].address,contacts[i].email,contacts[i].phone);
            i++;
            while(!feof(fp))
            {
                fscanf(fp,"%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%s\n",contacts[i].fname,contacts[i].lname,contacts[i].bd.day,contacts[i].bd.month,contacts[i].bd.year,contacts[i].address,contacts[i].email,contacts[i].phone);
                i++;
            }
        }
    }
    fclose(fp);
}

#endif // READ
