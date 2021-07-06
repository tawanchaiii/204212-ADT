#include<stdio.h>
int day = 1;
int cmonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char monthname[][20] =  {
         "January",
         "February",
         "March",
         "April",
         "May",
         "June",
         "July",
         "August",
         "September",
         "October",
         "November",
         "December"};
int main(){
    int year,month,i,j; 
    printf("Enter year: "); scanf("%d",&year);
    printf("Enter month: "); scanf("%d",&month);
    for(i=1990;i<year;i++) {
        if((i%4==0 && i%100!=0) || i%400==0) day+=366;
        else day+=365;
    }
    if((year%4==0 && year%100!=0) || year%400==0) cmonth[1] = 29;
    for(i=0;i<month-1;i++) day+=cmonth[i];
    int state = day%7;
    printf("====================\n");
    printf("%s %d\n",monthname[month-1],year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for(i=0;i<state;i++) printf("    ");
    int rr = 1;
    while(rr<=cmonth[month-1]){
        if(state%7 == 0 || rr == 1)  printf("%3d",rr);
        else printf("%4d",rr);
        rr++; state++;
        if (state%7 == 0) printf("\n");
    }
}