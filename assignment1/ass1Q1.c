#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate)
{
    ptrDate->day=0;
    ptrDate->month=0;
    ptrDate->year=0;
}

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("enter date");
    scanf("%d", &ptrDate->day);
    printf("enter month");
    scanf("%d", &ptrDate->month);
    printf("enter year");
    scanf("%d", &ptrDate->year);
    printf("\n %d:%d:%d",ptrDate->day,ptrDate->month, ptrDate->year);
}

void printDateOnConsole(struct Date* ptrDate)
{
 printf("\n %d:%d:%d",ptrDate->day,ptrDate->month, ptrDate->year);

}
 
 //void acceptDateFromConsole(&Date);
 //void printDateOnConsole( &Date);



int main()
{
struct Date date;
 int choice;

 do{
     printf("\nmenu:\n");
     printf("1.initialise date\n");
     printf("2.print date\n");
     printf("3.accept date\n");
     printf("4. exit\n");
     printf("enter your choice");
     scanf("%d",&choice);

     switch (choice)
     {
     case 1 : initDate(&date);
         break;
    case 2: printDateOnConsole( &date);
        break;

    case 3:acceptDateFromConsole(&date);
        break;
    case 4:
        printf("exiting");
        break;
     
     default:
        printf("invalid choice");
         break;
     }
 }
     while (choice !=4);
     return 0;

 
}
