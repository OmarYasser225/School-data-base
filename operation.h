//
// Created by omarn on 11/2/2023.
//

#ifndef DATABASE_OPERATION_H
#define DATABASE_OPERATION_H

// protect for stdio
#ifndef STDIO_H_
#define STDIO_H_
#include <stdio.h>
#endif

#include<time.h>
#include "feature.h"
#include "student.h"

void string_scan(char * name , int gen);
int search_id(STD * s , int range );
void edit(STD * stud ,int index);
int search_name(STD * s,int range);
void space(int len , int num, int mode);
void delay(int number_of_seconds);
void swap_struct(STD *s1 ,STD *s2);
void change_id( STD *s , int id);
void delete(STD *s);

#endif //DATABASE_OPERATION_H
