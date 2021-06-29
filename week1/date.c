#include<stdio.h>
int main(){
  char A[10];
  int day,month,year;
  scanf("%d/%d/%d",&day,&month,&year);
  int mm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if ((year%4 == 0 && year%100!=0) || year%400==0) mm[1] = 29;
  int i = 0;
  for(i = 0 ;i<month-1;i++) day+=mm[i];
  printf("%d",day);
  return 0;
}
