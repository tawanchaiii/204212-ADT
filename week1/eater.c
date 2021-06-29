#include<stdio.h>
int main(){
  int x,y,z;  char a,b;  scanf("%d %d %d %c %c",&x,&y,&z,&a,&b);
  if (a>'Z') a-=32;
  if (b>'Z') b-=32;
  int front=x;
  if (a == 'Y') front+=y;
  if (b == 'Y'){
    float temp = (float)front/z;
    if (temp - (int)(front/z) != 0.0) printf("%d",front/z+1);
    else printf("%d",front/z);
  }
  else printf("%d",front);
  return 0;
}
