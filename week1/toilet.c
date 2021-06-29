#include<stdio.h>
int main(){
  float lnew,lold,c,n; 
  int i = 1;
  scanf("%f %f %f %f",&lnew,&lold,&c,&n);
  while((lold*n/1000)*i < (lnew*n/1000)*i+c){ i++;}
  printf("%d",i);
}
