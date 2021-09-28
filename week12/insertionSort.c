#include<stdio.h>
void insertion_sort(int A[],int size){
    for(int i=1;i<size;i++){
        int key = A[i];
        int j = i - 1;
        while (key < A[j] && j>=0)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        for(int i=0;i<size;i++)
            printf("%d ",A[i]);
        printf("\n");
    }
}
int main(){
    int n; scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    insertion_sort(A,n);
}