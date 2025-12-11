#include<stdio.h>
//to get the first day of the year..
int getfirstdayofyear(int year)
{
    int day;
    day = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}
//checks whether the year is leap year or not
int leapyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//to print the calender of the year
void printmonth(int year)
{
    char *month[] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};//array of months
    
    int daysinamonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};//array of days in a month

    if (leapyear(year))
    {
        daysinamonth[1] = 29;//if the year is leap year then the days in the february changes
    }

    int startday = getfirstdayofyear(year);
    FILE *calender;//creating a file pointer
    calender=fopen("calender.txt","a");//opening the file calender.txt
    //print the months of the calender
    for (int i = 0; i < 12; i++)
    {
        fprintf(calender,"\n\n-------------%s %d-------------\n", month[i], year);
        fprintf(calender,"Sun Mon Tue Wed Thu Fri Sat\n");

        for (int k = 0; k < startday; k++)
        {
            fprintf(calender,"    ");//print the gaps in the calender in the file
        }

        for (int day = 1; day <= daysinamonth[i]; day++)//toprint the days in the calender in the file
        {
            fprintf(calender,"%3d ", day);
            startday++;
            if (startday > 6)
            {
                startday = 0;
                fprintf(calender,"\n");
            }
        }

        if (startday != 0) fprintf(calender,"\n");      
    }
    fclose(calender);//closing the file
    //for printing the calender in the terminal
    for (int i = 0; i < 12; i++)//print the months
    {
        printf("\n\n-------------%s %d-------------\n", month[i], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        for (int k = 0; k < startday; k++)//to print the space
        {
            printf("    ");
        }

        for (int day = 1; day <= daysinamonth[i]; day++)//to print the days in the month
        {
            printf("%3d ", day);
            startday++;
            if (startday > 6)
            {
                startday = 0;
                printf("\n");
            }
        }

        if (startday != 0) printf("\n");      
    }
}

int main()
{
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    printmonth(year);//calling the function to print the calender 

    return 0;
}
