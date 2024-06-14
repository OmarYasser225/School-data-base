//
// Created by omarn on 11/2/2023.
//

#ifndef DATABASE_STRUENT_H
#define DATABASE_STRUENT_H

#ifndef STDIO_H_
#define STDIO_H_
#include <stdio.h>
#endif

#include <string.h>


#define CAPACITY 1000

typedef struct family
{
    char father_name[20];
    char mother_name[20];
    int number_brothers;
}FAM;



typedef struct student
{
    int id;
    char name[20];
    int number;
    int age;
    FAM family;
}STD;


int HMI(void);
void add_student(STD* stud);
void edit_information(STD* stud);
void print(STD * stud,int start , int end);
void delete_menu(STD * stud, int range);


#endif //DATABASE_STRUENT_H



