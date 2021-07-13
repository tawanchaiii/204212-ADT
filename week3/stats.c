#include<stdio.h>
#include<stdlib.h>
void findStats(int nums[],double* avg,int* maxi,int* mini,int* n){
    *avg = 0;
    for(int i =0;i<(*n);i++) *avg+=nums[i];
    *avg = (double) *avg / *n;
    *maxi = nums[0];
    *mini = nums[0];
    for(int i = 1;i<(*n);i++){
        if (nums[i] > *maxi) *maxi = nums[i]; 
        if (nums[i] < *mini) *mini = nums[i]; 
    }
}
int main(){
    int n,i,maxi,mini;
    double avg;
    int* nums;
    scanf("%d",&n);
    nums = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++) scanf("%d",nums+i);
    findStats(nums,&avg,&maxi,&mini,&n);
    printf("%.2f %d %d",avg,maxi,mini);
    return 0;
}