#include<stdio.h>
int main(){
  char a,b; scanf("%c %c",&a,&b);
  if (a<b) printf("%d",b-a);
  else printf("%d",a-b);
}
