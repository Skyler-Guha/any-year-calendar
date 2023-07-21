#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>



void print_cal(int month, int year)
{
  system("cls");

  int start_date = 1;
  int year_code;
  int month_code=0;
  int century_code=0;
  int day_range = 0;
  int leap = 0;
  int leap_code = 0;

  /*calculating year code*/
  year_code=year%100;
  year_code= (year_code+(year_code/4))%7;

  /*calculating month code*/
  if(month == 1||month==10) month_code=0;
  else if(month == 5) month_code=1;
  else if(month == 8) month_code=2;
  else if(month == 2||month==3||month==11) month_code=3;
  else if(month == 6) month_code=4;
  else if(month == 9||month == 12) month_code=5;
  else if(month == 4||month == 7) month_code=6;
  else printf("error(1)");


  /*calculating century code*/
  century_code = year;
  while(century_code >= 100)
  {
    century_code = century_code / 100;
  }
  century_code *= 100;
  if(century_code%400 == 300) century_code=0;
  else if(century_code%400 == 200) century_code=2;
  else if(century_code%400 == 100) century_code=4;
  else if(century_code%400 == 0) century_code=6;
  else printf("error(2)");


  /*calculating if leap year*/
  if (year % 400 == 0) leap = 1;
  else if (year % 100 == 0) leap = 0;
  else if (year % 4 == 0) leap = 1;
  else leap = 0;


  /*calculating leap code*/
  if(leap==1&&month==1 || leap==1&&month==2)leap_code=1;

  /*calculating days in month*/
  if(month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)
  day_range=31;
  else if(month == 4||month == 6||month == 9||month == 11)
  day_range=30;
  else if(month == 2)
  {
    if(leap == 0)day_range=28;
    else day_range=29;
  }
  else printf("error(3)");


  /***********calculating day*************/
  int day_of_month;
  day_of_month = (year_code+month_code+century_code+start_date-leap_code)%7;

  int day_count = 1;


  //printing
  printf(" ");
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),62);
  switch(month)
  {
    case 1: printf("      || Jan %d ||      \n\n",year);break;
    case 2: printf("      || Feb %d ||      \n\n",year);break;
    case 3: printf("      || Mar %d ||      \n\n",year);break;
    case 4: printf("      || Apr %d ||      \n\n",year);break;
    case 5: printf("      || May %d ||      \n\n",year);break;
    case 6: printf("      || Jun %d ||      \n\n",year);break;
    case 7: printf("      || Jul %d ||      \n\n",year);break;
    case 8: printf("      || Aug %d ||      \n\n",year);break;
    case 9: printf("      || Sep %d ||      \n\n",year);break;
    case 10: printf("      || Oct %d ||      \n\n",year);break;
    case 11: printf("      || Nov %d ||      \n\n",year);break;
    case 12: printf("      || Dec %d ||      \n\n",year);break;
  }
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

  for (int i = 1; i<= 49; i++)
  {
    switch (i)
    {
      case 1:
      {
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
        printf("mo");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" ");
        break;
      }
      case 2:
      {
          printf(" ");
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
          printf("tu");
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          printf(" ");
          break;
      }
      case 3:
      {
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
        printf("we");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" ");
        break;
      }
      case 4:
      {
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
        printf("th");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" ");
        break;
      }
      case 5:
      {
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
        printf("fr");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" ");
      break;
      }
      case 6:
      {
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
        printf("sa");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" ");
      break;
      }
      case 7:
      {
        printf(" ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
        printf("su");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      break;
      }
    }


    if(i%7==0)printf("\n");


    //code for sunday
    if(day_of_month==0 && i>7 && i<14 )
    printf("    ");

    if(day_of_month==0 && i>=13 && day_count <= day_range)
    {
      printf(" ");
      int n = day_count;
      int count = 0;
      while (n != 0) {
          n /= 10;     // n = n/10
          ++count;
      }
      if(count==1)
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf(" %d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf(" %d",day_count);
      }
      else
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf("%d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf("%d",day_count);
      }
      printf(" ");
      day_count++;
    }

    //code for monday
    if(day_of_month==1 && i>=7 && day_count <= day_range)
    {
      printf(" ");
      int n = day_count;
      int count = 0;
      while (n != 0) {
          n /= 10;     // n = n/10
          ++count;
      }
      if(count==1)
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf(" %d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf(" %d",day_count);
      }
      else
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf("%d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf("%d",day_count);
      }
      printf(" ");
      day_count++;
    }

    //code for tusday
    if(day_of_month==2 && i>6 && i<8 )
    printf("    ");

    if(day_of_month==2 && i>=8 && day_count <= day_range)
    {
      printf(" ");
      int n = day_count;
      int count = 0;
      while (n != 0) {
          n /= 10;     // n = n/10
          ++count;
      }
      if(count==1)
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf(" %d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf(" %d",day_count);
      }
      else
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf("%d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf("%d",day_count);
      }
      printf(" ");
      day_count++;
    }


    //code for wednesday
    if(day_of_month==3 && i>6 && i<9 )
    printf("    ");

    if(day_of_month==3 && i>=9 && day_count <= day_range)
    {
      printf(" ");
      int n = day_count;
      int count = 0;
      while (n != 0) {
          n /= 10;     // n = n/10
          ++count;
      }
      if(count==1)
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf(" %d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf(" %d",day_count);
      }
      else
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf("%d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf("%d",day_count);
      }
      printf(" ");
      day_count++;
    }

    //code for thirsday
    if(day_of_month==4 && i>6 && i<10 )
    printf("    ");

    if(day_of_month==4 && i>=10 && day_count <= day_range)
    {
      printf(" ");
      int n = day_count;
      int count = 0;
      while (n != 0) {
          n /= 10;     // n = n/10
          ++count;
      }
      if(count==1)
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf(" %d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf(" %d",day_count);
      }
      else
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf("%d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf("%d",day_count);
      }
      printf(" ");
      day_count++;
  }


    //code for friday
    if(day_of_month==5 && i>6 && i<11 )
    printf("    ");

    if(day_of_month==5 && i>=11 && day_count <= day_range)
    {
      printf(" ");
      int n = day_count;
      int count = 0;
      while (n != 0) {
          n /= 10;     // n = n/10
          ++count;
      }
      if(count==1)
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf(" %d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf(" %d",day_count);
      }
      else
      {
        if(i%7==6)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
          printf("%d",day_count);
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
         else printf("%d",day_count);
      }
      printf(" ");
      day_count++;}

      //code for saturday
      if(day_of_month==6 && i>6 && i<12 )
      printf("    ");

      if(day_of_month==6 && i>=12 && day_count <= day_range)
      {
        printf(" ");
        int n = day_count;
        int count = 0;
        while (n != 0) {
            n /= 10;     // n = n/10
            ++count;
        }
        if(count==1)
        {
          if(i%7==6)
          {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
            printf(" %d",day_count);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          }
           else printf(" %d",day_count);
        }
        else
        {
          if(i%7==6)
          {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),335);
            printf("%d",day_count);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
          }
           else printf("%d",day_count);
        }
        printf(" ");
        day_count++;}

  }//for loop end
  system("pause");
}






//======================================================
void print_day(int date, int month, int year)
{
system("cls");

int start_date = date;
int year_code;
int month_code=0;
int century_code=0;
int day_range = 0;
int leap = 0;
int leap_code = 0;

/*calculating year code*/
year_code=year%100;
year_code= (year_code+(year_code/4))%7;

/*calculating month code*/
if(month == 1||month==10) month_code=0;
else if(month == 5) month_code=1;
else if(month == 8) month_code=2;
else if(month == 2||month==3||month==8||month==11) month_code=3;
else if(month == 6) month_code=4;
else if(month == 9||month == 12) month_code=5;
else if(month == 4||month == 7) month_code=6;
else printf("error(1)");


/*calculating century code*/
century_code = year;
while(century_code >= 100)
{
  century_code = century_code / 100;
}
century_code *= 100;
if(century_code%400 == 300) century_code=0;
else if(century_code%400 == 200) century_code=2;
else if(century_code%400 == 100) century_code=4;
else if(century_code%400 == 0) century_code=6;
else printf("error(2)");


/*calculating if leap year*/
if (year % 400 == 0) leap = 1;
else if (year % 100 == 0) leap = 0;
else if (year % 4 == 0) leap = 1;
else leap = 0;


/*calculating leap code*/
if(leap==1&&month==1 || leap==1&&month==2)leap_code=1;


/***********calculating day*************/
int day_of_month;
day_of_month = (year_code+month_code+century_code+start_date-leap_code)%7;

printf("\n");
switch(day_of_month)
{
  case 0:printf("          ||SUNDAY|| ");break;
  case 1:printf("          ||MONDAY|| ");break;
  case 2:printf("          ||TUSDAY|| ");break;
  case 3:printf("          ||WEDNESDAY|| ");break;
  case 4:printf("          ||THIRSDAY|| ");break;
  case 5:printf("          ||FRIDAY|| ");break;
  case 6:printf("          ||SATURDAY|| ");break;

}
printf("\n\n");
system("pause");
}


int main(void)
{

while(1)
{

  int option;
  int exit = 0;
  system("cls");
  printf("Welcome to Any Year Calendar!!\n\n");
  printf("Select an option:\n1)see calendar for a given month and year\n2)find day for a perticular date\n3)exit\n>>> ");
  scanf("%1d",&option);
  system("cls");
  switch(option)
  {
    case 1:
    {
      int month;
      int year;
      printf("Select a month:\n1)Jan\n2)Feb\n3)Mar\n4)April\n5)May\n6)June\n7)July\n8)Aug\n9)Sept\n10)Oct\n11)Nov\n12)Dec\n>>> ");
      scanf("%2d",&month);
      system("cls");
      printf("Enter year:\n>>> ");
      scanf("%4d",&year);
      print_cal(month,year);
      break;

    }
    case 2:
    {
      int date;
      int month;
      int year;
      printf("Enter Date Number:\n>>> ");
      scanf("%2d",&date);
      system("cls");
      printf("Select a month:\n1)Jan\n2)Feb\n3)Mar\n4)April\n5)May\n6)June\n7)July\n8)Aug\n9)Sept\n10)Oct\n11)Nov\n12)Dec\n>>> ");
      scanf("%2d",&month);
      system("cls");
      printf("Enter year:\n>>> ");
      scanf("%4d",&year);
      print_day(date,month,year);
      break;

    }
    case 3:exit = 1;break;
  }
  if(exit==1)break;
}

}
