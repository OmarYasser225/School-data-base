//
// Created by omarn on 11/2/2023.
//

#include "operation.h"


void string_scan(char * name , int gen)
{
    int j;
    setColor(7);
    printf("Please enter the name");
    if (gen == 1)
        printf(" of student : ");
    else if(gen == 2)
        printf(" of father : ");
    else if(gen == 3)
        printf(" of mother : ");
    setColor(4);
    for ( j = 0; name[j-1]!='\n' && j<20 ; ++j)
    {
        scanf("%c",&name[j]);
    }
    setColor(15);
    name[j-1]=0;
    return;
}

int search_id(STD * s , int range )
{
    int id;
    setColor(7);
    printf("Please enter the ID: ");
    setColor(4);
    scanf("%d",&id);
    setColor(15);
    for (int i = 0; i < range ; ++i)
    {
        if(s[i].id == id)
        {
            setColor(4);
            printf("-----------------------------------------\n");
            printf("FOUNDED AT (%d)\n",i);
            printf("-----------------------------------------\n");
            setColor(15);
            return i;
        }
    }
    setColor(4);
    printf("NOT FOUND\n");
    setColor(15);
    return -1;
}

void edit(STD * stud ,int index)
{
    int choose;
    setColor(5);
    printf("-----------------------------------------\n");
    setColor(7);
    printf("Do you want to edit on\n\n1)student name\n2)age\n3)telephone\n4)father name\n5)mother name\n6)number of brothers\n");
    setColor(5);
    printf("-----------------------------------------\n");
    setColor(7);
    printf("Please enter your choice: ");
    setColor(4);
    scanf("%d",&choose);
    setColor(15);
    while(getchar() != '\n');
    if(choose==1)
    {
        setColor(5);
        printf("-----------------------------------------\n");
        string_scan(stud[index].name,1);
    }
    else if(choose==2)
    {
        setColor(5);
        printf("-----------------------------------------\n");
        setColor(7);
        printf("Please enter the age: ");
        setColor(4);
        scanf("%d",&stud[index].age);
        setColor(15);
    }
    else if(choose==3)
    {
        setColor(5);
        printf("-----------------------------------------\n");
        setColor(7);
        printf("Please enter the telephone: ");
        setColor(4);
        scanf("%d",&stud[index].number);
        setColor(15);
    }
    else if(choose==4)
    {
        setColor(5);
        printf("-----------------------------------------\n");
        string_scan(stud[index].name,2);
    }
    else if(choose==5)
    {
        setColor(5);
        printf("-----------------------------------------\n");
        string_scan(stud[index].name,3);
    }
    else if(choose==6)
    {
        setColor(5);
        printf("-----------------------------------------\n");
        setColor(7);
        printf("Please enter the number of brother: ");
        setColor(4);
        scanf("%d",&stud[index].family.number_brothers);
        setColor(15);
    }

}

int string_compare(const char* name1 ,const char* name2)
{
    printf("%s\n",name1);
    printf("%s\n",name2);
    for (int i = 1; i <= 20 && name1[i-1]!=0 && name2[i-1]!=0 ; ++i)
    {
        if(name1[i-1] == name2[i-1])
        {
            continue;
        }
        else
        {
            return 0;
        }

    }
    return 1;

}

int search_name(STD * s,int range)
{
    int index;
    char student_name[20];
    char father_name[20];
    while(getchar()!='\n');
    string_scan(student_name,1);
    string_scan(father_name,2);

    setColor(5);
    printf("-----------------------------------------\n");
    setColor(7);
    for (int i = 0; i < range ; ++i)
    {
        int c1 = string_compare(student_name,s[i].name);
        int c2 = string_compare(father_name,s[i].family.father_name);

        if(c1==1 && c2==1)
        {
            setColor(4);
            printf("-----------------------------------------\n");
            printf("FOUNDED AT (%d)\n",i);
            printf("-----------------------------------------\n");
            setColor(15);
            return i;
        }
    }
    setColor(4);
    printf("NOT FOUND\n");
    setColor(15);
    return -1;
}

void space(int len , int num , int mode)
{
    if(len <= num && mode==0)
    {
        len = (len-num)+5;
    }
    else
    {
        len = (num-len)+5;
    }
    for (int j = 0; j < len ; ++j)
    {
        printf(" ");
    }
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void swap_struct(STD *s1 ,STD *s2)
{
    STD temp = *(s1);
    *s1 = *s2;
    *s2 = temp;
}

void change_id( STD *s , int id)
{
    s->id = id;
}

void delete(STD *s)
{
    for (int i = 1; i <= 20  &&  s->name[i-1]!=0; ++i)
    {
        s->name[i-1]=' ';
    }
    for (int i = 1; i <= 20  &&  s->family.father_name[i-1]!=0; ++i)
    {
        s->family.father_name[i-1]=' ';
    }
    for (int i = 1; i <= 20  &&  s->family.mother_name[i-1]!=0; ++i)
    {
        s->family.mother_name[i-1]=' ';
    }
    s->id=0;
    s->number=0;
    s->age=0;
    s->family.number_brothers=0;
}