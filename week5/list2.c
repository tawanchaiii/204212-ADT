#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100000
typedef struct node{
    int number;
    double real;
    char str[20];
    int type;
}NODE;
typedef struct list{
    NODE *arr;
    int count;
}list_t;

list_t create(){
    list_t l = {NULL,0};
    l.arr = (NODE*)malloc(sizeof(NODE)*SIZE);
    return l;
}
void append(list_t* L,int type,int data0,double data1,char data2[]){
    if (type == 0){
        L->arr[L->count].number = data0; 
        L->arr[L->count].type = 0;
    }
    else if (type == 1){
        L->arr[L->count].real = data1; 
        L->arr[L->count].type = 1;
    }
    else if (type == 2){
        strcpy(L->arr[L->count].str,data2);
        L->arr[L->count].type = 2;
    }
    L->count++;
}
void show(list_t L){
    for(int i=0;i<L.count;i++){
        if (L.arr[i].type == 0){
            printf("%d ",L.arr[i].number);
        }
        else if (L.arr[i].type == 1){
            printf("%lf ",L.arr[i].real);
        }
        else if (L.arr[i].type == 2){
            printf("%s ",L.arr[i].str);
        }
    }
    printf("\n");
}

void show_reverse(list_t L){
    for(int i=L.count-1;i>=0;i--){
        if (L.arr[i].type == 0){
            printf("%d ",L.arr[i].number);
        }
        else if (L.arr[i].type == 1){
            printf("%lf ",L.arr[i].real);
        }
        else if (L.arr[i].type == 2){
            printf("%s ",L.arr[i].str);
        }
    }
    printf("\n");
}

void get(list_t L,int i){
    if (L.arr[i].type == 0){
        printf("%d\n",L.arr[i].number);
    }
    else if (L.arr[i].type == 1){
        printf("%lf\n",L.arr[i].real);
    }
    else if (L.arr[i].type == 2){
        printf("%s\n",L.arr[i].str);
    }
}
void insert(list_t* L,int index,int type,int data0,double data1,char data2[]){
    index++;
    for(int i = L->count-1;i>=index;i--) {
        if (L->arr[i].type == 0){
            L->arr[i+1].number = L->arr[i].number; 
            L->arr[i+1].type = 0;
        }
        else if (L->arr[i].type == 1){
            L->arr[i+1].real = L->arr[i].real; 
            L->arr[i+1].type = 1;
        }
        else if (L->arr[i].type == 2){
            strcpy(L->arr[i+1].str,L->arr[i].str);
            L->arr[i+1].type = 2;
        }
    }
    if (type == 0){
        L->arr[index].number = data0; 
        L->arr[index].type = 0;
    }
    else if (type == 1){
        L->arr[index].real = data1; 
        L->arr[index].type= 1;
    }
    else if (type == 2){
        strcpy(L->arr[index].str,data2);
        L->arr[index].type = 2;
    }
    L->count++;
}
void delete(list_t* L,int index){
    for(int i = index+1;i<L->count;i++) {
        if (L->arr[i].type == 0){
            L->arr[i-1].number = L->arr[i].number; 
            L->arr[i-1].type = 0;
        }
        else if (L->arr[i].type == 1){
            L->arr[i-1].real = L->arr[i].real; 
            L->arr[i-1].type = 1;
        }
        else if (L->arr[i].type == 2){
            strcpy(L->arr[i-1].str,L->arr[i].str);
            L->arr[i-1].type = 2;
        }
    }
    L->count--;
}
void change(list_t* L,int index,int type,int data0,double data1,char data2[]){
    if (type == 0){
        L->arr[index].number = data0; 
        L->arr[index].type = 0;
    }
    else if (type == 1){
        L->arr[index].real = data1; 
        L->arr[index].type= 1;
    }
    else if (type == 2){
        strcpy(L->arr[index].str,data2);
        L->arr[index].type = 2;
    }
}
void is_empty(list_t L){
    if (L.count == 0) printf("Empty\n");
    else printf("Not Empty\n");
}
void length(list_t L){
    printf("%d\n",L.count);
}

int main(){
    int t; scanf("%d",&t);
    list_t L = create();
    while(t--){
        char menu; scanf(" %c",&menu);
        if (menu == 'A'){
            int type; scanf(" %d",&type);
            if (type == 0){
                int data; scanf(" %d",&data);
                append(&L,0,data,0,"0");
            }
            else if (type == 1){
                double data; scanf(" %lf",&data);
                append(&L,1,0,data,"0");
            }
            else if (type == 2){
                char data[20]; scanf(" %s",data);
                append(&L,2,0,0,data);
            }
        }
        if (menu == 'G'){
            int index; scanf(" %d",&index);
            get(L,index);
        }
        if (menu == 'S'){
            show(L);
        }
        if (menu == 'R'){
            show_reverse(L);
        }
        if (menu == 'I'){
            int type,index; scanf(" %d %d",&index,&type);
            if (type == 0){
                int data; scanf(" %d",&data);
                insert(&L,index,0,data,0,"0");
            }
            else if (type == 1){
                double data; scanf(" %lf",&data);
                insert(&L,index,1,0,data,"0");
            }
            else if (type == 2){
                char data[20]; scanf(" %s",data);
                insert(&L,index,2,0,0,data);
            }
        }
        if (menu == 'C'){
            int type,index; scanf(" %d %d",&index,&type);
            if (type == 0){
                int data; scanf(" %d",&data);
                change(&L,index,0,data,0,"0");
            }
            else if (type == 1){
                double data; scanf(" %lf",&data);
                change(&L,index,1,0,data,"0");
            }
            else if (type == 2){
                char data[20]; scanf(" %s",data);
                change(&L,index,2,0,0,data);
            }
        }
        if (menu == 'D'){
            int index; scanf(" %d",&index);
            delete(&L,index);
        }
        if (menu == 'E'){
            is_empty(L);
        }
        if (menu == 'L'){
            length(L);
        }
    }
    return 0;
}