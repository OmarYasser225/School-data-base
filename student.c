//
// Created by omarn on 11/2/2023.
//

#include "operation.h"

int RC =995;
static int id=200005;
static int ind = 5;

STD data[CAPACITY] = {{200000,"omar",2313254,25,{"yasser","hanna",2}},
                      {200001,"ahmed",65465464,20,{"mohamed","may",5}},
                      {200002,"mohssen",2212135,26,{"gasser","noha",4}},
                      {200003,"hany",1231456,19,{"micheal","mary",9}},
                      {200004,"hosny",78933,21,{"said","yasmine",1}}
};

// colors (white 15) (green 18) (red 4) (blue 3) (yellow 6)


int HMI(void)
{
    int choose;
    setColor(3);
    printf("----------------------------------\n");
    printf("       Welcome to data base\n");
    printf("----------------------------------\n");
    printf("    The remind capacity (%3d) \n",RC);
    printf("----------------------------------\n");
    setColor(15);
    printf("1) Add student\n2) Edit information\n3) Print specific student\n4) Delete student\n5) Print all school\n");
    setColor(3);
    printf("----------------------------------\n");
    setColor(1);
    printf("Please enter your choice : ");
    setColor(4);
    scanf(" %d",&choose);
    return choose;
}

void add_student(STD* stud)
{
    int n,i;
    system("cls");
    setColor(6);
    printf("-----------------------------------------\n");
    printf("               Add Menu\n");
    printf("-----------------------------------------\n");
    setColor(7);
    printf("Please enter the number of student : ");
    setColor(4);
    scanf(" %d",&n);


    while (getchar() != '\n');

    for ( i = 0; i < n ; ++i)
    {
        // ID
        stud[ind].id=id;

        //NAME
        string_scan(stud[ind].name,1);

        //AGE
        setColor(7);
        printf("Please enter the age of student : ");
        setColor(4);
        scanf(" %d",&stud[ind].age);
        //NUMBER
        setColor(7);
        printf("Please enter the telephone number of student : ");
        setColor(4);
        scanf(" %d",&stud[ind].number);

        //FAMILY
        while (getchar() != '\n');
        string_scan(stud[ind].family.father_name,2);

        string_scan(stud[ind].family.mother_name,3);

        setColor(7);
        printf("Please the number of brothers : ");
        setColor(4);
        scanf(" %d",&stud[ind].family.number_brothers);
        setColor(6);
        printf("-----------------------------------------\n");
        setColor(15);

        // index edit
        ind++;
        id++;
        RC--;
        system("cls");
    }
}

void edit_information(STD* stud)
{
    int choose,index;
    edit:
    system("cls");
    setColor(5);
    printf("-----------------------------------------\n");
    printf("              Edit Menu\n");
    printf("-----------------------------------------\n");
    setColor(15);

    // choose search
    printf("Search using\n1)ID\n2)Name\n");
    setColor(5);
    printf("-----------------------------------------\n");
    setColor(7);
    printf("Please enter your choice: ");
    setColor(4);
    scanf("%d",&choose);
    setColor(5);
    printf("-----------------------------------------\n");

    // search
    if(choose==1)
    {
        index = search_id(stud,(CAPACITY-RC));
        if(index == -1)
        {
            printf("Do you want to search again\n1)YES\n2)NO\n");
            scanf("%d",&choose);
            if (choose==1)
            {
                goto edit;
            }
            else
            {
                system("cls");
                return;
            }
        }
        else
        {
            edit(stud,index);
            system("cls");
        }
    }


    else
    {
        index = search_name(stud,(CAPACITY-RC));
        if(index == -1)
        {
            printf("Do you want to search again\n1)YES\n2)NO\n");
            scanf("%d",&choose);
            if (choose==1)
            {
                goto edit;
            }
            else
            {
                system("cls");
                return;
            }
        }
        else
        {
            edit(stud,index);
            system("cls");
        }

    }
}

void print(STD * stud, int start , int end)
{

    system("cls");
    setColor(3);
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("                                            STUDENTS\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Name     ID       AGE     FATHER_NAME     MOTHER_NAME     BROTHERS_NUMBER       telephone_number\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    setColor(6);
    for (int i = start; i < end ; ++i)
    {
        printf("%s",stud[i].name);
        space((int)strlen(stud[i].name),4,0);

        printf("%d",stud[i].id);
        for (int j = 0; j < 3 ; ++j)
        {
            printf(" ");
        }

        printf("%2d",stud[i].age);
        for (int j = 0; j < 6 ; ++j)
        {
            printf(" ");
        }

        printf("%s",stud[i].family.father_name);
        space((int)strlen(stud[i].family.father_name),11,1);

        printf("%s",stud[i].family.mother_name);
        space((int)strlen(stud[i].family.mother_name),11,1);

        printf("%2d",stud[i].family.number_brothers);

        for (int j = 0; j < 20 ; ++j)
        {
            printf(" ");
        }
        printf("%d\n",stud[i].number);
    }
    setColor(3);
    printf("-------------------------------------------------------------------------------------------------\n");
    setColor(6);
    while(getchar()!='\n');
    printf("Please press on enter to return to menu : ");
    setColor(4);
    scanf("%*c");
    setColor(15);
    system("cls");

}

void delete_menu(STD * stud, int range)
{

    int choose,index;
    system("cls");
    setColor(18);
    printf("-----------------------------------------\n");
    printf("              Delete Menu\n");
    printf("-----------------------------------------\n");
    setColor(15);

    // choose search
    printf("Search using\n1)ID\n2)Name\n");
    setColor(18);
    printf("-----------------------------------------\n");
    setColor(15);
    printf("Please enter your choice: ");
    setColor(4);
    scanf("%d",&choose);
    setColor(18);
    printf("-----------------------------------------\n");

    if(choose==1)
    {
       index = search_id(stud,range);
    }
    else
    {
        index = search_name(stud,range);
    }

    if(index==-1)
    {
        setColor(4);
        printf("NOT FOUNDED\n");
        return;
    }
    delete(&stud[index]);
    for (int i = index; i < (range-1) ; ++i)
    {
        swap_struct(&stud[i],&stud[i+1]);
    }

    int card = 200000;
    for (int i = 0; i < range ; ++i)
    {
        change_id(&stud[i],card);
        card++;
    }

    RC++;
    id--;
    ind--;
}

