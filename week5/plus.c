#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100000
int cnt = 0,tod = 0;
char a[SIZE],b[SIZE],result[SIZE];
int main(){
    scanf("%s",a);
    scanf("%s",b);
    if (strlen(a) < strlen(b)){
        char temp[SIZE];
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }
    int sizea = strlen(a)-1,sizeb = strlen(b)-1;
    while(1){
        if (sizea < 0 && tod == 0) break;
        int sum = 0;
        if (sizeb>=0) sum = (a[sizea]-'0') + (b[sizeb]-'0');
        else if (sizea>=0) sum = (a[sizea]-'0');
        result[cnt] = (sum+tod)%10  + '0';
        tod = (sum+tod)/10;
        cnt++;
        sizea--; sizeb--;
    }
    for (int i = cnt-1;i>=0;i--) printf("%c",result[i]);
    return 0;
}