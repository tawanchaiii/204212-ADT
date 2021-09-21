#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
  item_t *table;
  int    size;
  int    hash_key;
} hash_t;

unsigned int func(hash_t* hash,char* str,int i){
    if (i==0){
        return (int)str[i];
    }
    return (hash->hash_key*func(hash,str,i-1)) + (int)str[i];
}
unsigned int hashed(hash_t* hash,char* str,unsigned int i){
    return (func(hash,str,strlen(str)-1) + (i+i*i)/2 ) %  (hash->size);
}
hash_t* init_hashtable(int m, int hash_key){
    hash_t* hash  = (hash_t*)malloc(sizeof(hash_t));
    hash->size = m;
    hash->hash_key = hash_key;
    hash->table = (item_t*)malloc(sizeof(item_t)*(m+2));
    for(int i=0;i<m;i++){
        
        hash->table[i] = NULL;
    }
    return hash;
}
void insert(hash_t* hash,char text[]){
    unsigned int ind  = hashed(hash,text,0);
    if (hash->table[ind] == NULL){
        hash->table[ind] = (char*)malloc(sizeof(char)*TEXTSIZE);
        strcpy(hash->table[ind],text);
    }
    else{
        int x = 1;
        while(1){
            ind = hashed(hash,text,x);
            if(hash->table[ind] == NULL)
                break;
            x++;
        }
        hash->table[ind] = (char*)malloc(sizeof(char)*TEXTSIZE);
        strcpy(hash->table[ind],text);
    }
}
int search(hash_t* hash,char text[]){
    unsigned int ind  = hashed(hash,text,0);
    if (hash->table[ind] == NULL){
        return -1;
    }
    else{
        int x = 0;
        while(1){
            ind = hashed(hash,text,x);
            if(hash->table[ind] == NULL)
                return -1;
            if(strcmp(hash->table[ind],text)==0)
                return ind;
            x++;
        }
        
    }
}
int main(void) {
  hash_t *hashtable = NULL;
  char   *text = NULL;
  int    m, n, i, hash_key;
  int    command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
      case 1:
        insert(hashtable, text);
        break;
      case 2:
        printf("%d\n", search(hashtable, text));
        break;
      }
  }
  return 0;
}