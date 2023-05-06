#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 1000
//My Functions Headers
#include "Read.h"
#include "Menu.h"
#include "Modify.h"
#include "Sort_List.h"
#include "Validate.h"
#include "Search.h"
#include "Add_Delete.h"
#include "Save_Quit.h"


int main()
{
    load();
    menu();

    return 0;
}
