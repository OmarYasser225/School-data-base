#include "operation.h"

extern STD data[CAPACITY];
extern int RC;
int main()
{
    int choose,index;
    start: choose = HMI();

    switch (choose)
    {
        case 1:
            add_student(data);
            goto start;
            break;
        case 2:
            edit_information(data);
            goto start;
            break;
        case 3:
            system("cls");
            setColor(1);
            printf("----------------------------------\n");
            printf("do you want to search by\n1)ID\n2)name\n");
            printf("----------------------------------\n");
            setColor(7);
            printf("Please enter your choice: ");
            setColor(4);
            scanf("%d",&choose);
            setColor(1);
            printf("----------------------------------\n");

            if(choose==1)
            {
                index=search_id(data,(CAPACITY-RC));
            }
            else
            {
                index=search_name(data,(CAPACITY-RC));
            }
            if(index == -1)
            {
                system("cls");
                setColor(4);
                printf("NOT FOUNDED\n");
                setColor(15);
                delay(2);
                system("cls");
                goto start;
            }
            print(data,index,index+1);
            goto start;
            break;
        case 4:
            delete_menu(data,(CAPACITY-RC));
            system("cls");
            goto start;
            break;
        case 5:
            print(data,0,(CAPACITY-RC));
            goto start;
            break;



    }

}
