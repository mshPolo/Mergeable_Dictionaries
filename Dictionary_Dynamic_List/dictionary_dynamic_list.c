//
// Created by Marcus Skov Hansen on 2019-08-27.
//
#include <stdlib.h>
#include <stdio.h>



typedef struct {
    int * list;
    int size;
    int used;
}Dictionary;

void freeDictionary(Dictionary * a);
//Dictionary * newDictionary(int size);
int search(Dictionary * a, int element);
int findPredecessorIndex(Dictionary * a, int element);
void increaseSize(Dictionary * a);
void decreaseSize(Dictionary * a);
void insert(Dictionary * a, int element);
void delete(Dictionary * a, int element);
Dictionary * merge(Dictionary * a, Dictionary * b);
void split(Dictionary * c, int element, Dictionary ** a, Dictionary ** b);
//INSERT
//void delete(Dictionary * a, int element);
//Dictionary * mergeDictionary(Dictionary * a, Dictionary * b);
//void splitDictionary(Dictionary * c, int element, Dictionary ** a, Dictionary * b);

Dictionary * newDictionary() {
    int size = 10;
    Dictionary * a = (Dictionary * ) malloc(sizeof(Dictionary));
    a->list = (int *)malloc(size * sizeof(int));
    a->used = 0;
    a->size = size;
    return a;
}

Dictionary * newDictionaryWithSize(int size) {
    Dictionary * a = (Dictionary * ) malloc(sizeof(Dictionary));
    a->list = (int *)malloc(size * sizeof(int));
    a->used = 0;
    a->size = size;
    return a;
}

int search(Dictionary * a, int element){
    //TODO: what if contains no elements
    int i = findPredecessorIndex(a,element);
    return a->list[i];
}

void insert(Dictionary * a, int element){
    if(a->used >= a->size) increaseSize(a);
    //TODO: should not insert duplicates
    //TODO: use binary search
    //int i = 0;
    /*
    while(i < a->used && a->list[i] < element) i++;
    int temp1  = a->list[i];
    a->list[i++] = element;
    */
    int i;
    if(a->used == 0 || a->list[0] > element){
        i = 0;
    }else{
        i = findPredecessorIndex(a,element);
        //printf("%d\n", i);
        if(a->list[i] == element) return;
        i++;
    }
    int temp1;
    int temp2 = a->list[i];
    a->list[i] = element;
    a->used++;
    i++;
    while(i < a->used){
        temp1 = temp2;
        temp2 = a->list[i];
        a->list[i] = temp1;
        i++;
        /*
         int current = a->list[i];
         a->list[i] = temp1;
         temp1 = current;
         i++;
         */
    }
    //a->used++;
}

void delete(Dictionary * a, int element){
    int i = findPredecessorIndex(a,element);
    if(a->list[i] != element) return;
    while(i < a->used){
         int current = a->list[i+1];
         a->list[i++] = current;
    }
    a->used--;
    if(a->used < a->size) decreaseSize(a);
}

Dictionary * merge(Dictionary * a, Dictionary * b){
    Dictionary * c = newDictionaryWithSize(2*(a->used+b->used));
    int countA = 0,countB = 0, i = 0, size = a->used + b->used;
    while (countA < a->used && countB < b->used){
        if(a->list[countA] < b->list[countB]){
            c->list[i] = a->list[countA];
            countA++;
            i++;
        } else if(a->list[countA] == b->list[countB]) {
            c->list[i] = a->list[countA];
            countA++; 
            countB++;
            i++;
            size--;
        } else {
            c->list[i] = b->list[countB];
            countB++;
            i++;
        }
    }
    
    while (countA < a->used) c->list[i++] = a->list[countA++];
    while (countB < b->used) c->list[i++] = b->list[countB++];
    c->used = size;

    freeDictionary(a);
    freeDictionary(b);
    
    return c;
}

void split(Dictionary * c, int element, Dictionary ** a, Dictionary ** b){
    int i = findPredecessorIndex(c,element);
    *a = newDictionaryWithSize(2 * i);
    *b = newDictionaryWithSize(2 * (c->used - i));
    int j;
    //Assumes no duplicates
    for(j = 0; j <= i; j++){
        (*a)->list[j] = c->list[j];
        (*a)->used++;
    }
    i++;
    for(j = 0; j < c->used - i; j++){
        (*b)->list[j] = c->list[j+i];
        (*b)->used++;
    }
    freeDictionary(c);    
}


int findPredecessorIndex(Dictionary * a, int element){
    int left = 0;
    int right = a->used-1;
    //int k = 0;
    //printf("before while\n"); 
    //fflush(stdout);
    while(left < right){
            int middle = (left + right)/2;
        if(a->list[middle] < element){
            left = middle + 1;
        }else{
            right = middle;
        }
    }
    //printf("after while\n"); 
    //fflush(stdout);
    if(a->list[left] > element && left > 0){
        return left-1;
    }else{
        return left;
    }
}

void freeDictionary(Dictionary * a){
    free(a->list);
    free(a);
}

void increaseSize(Dictionary * a){
    if (a->used < a->size) return;
    a->size = 2*a->size;
    int * newList = (int *) malloc(a->size*sizeof(int));
    int i;
    for(i = 0; i < a->used; i++){
        newList[i] = a->list[i];
    }
    free(a->list);
    a->list = newList;
}

void decreaseSize(Dictionary * a){
    if (a->used >= a->size/4) return;
    a->size = (a->size+1)/2;
    int * newList = (int *) malloc(a->size*sizeof(int));
    int i;
    for(i = 0; i < a->used; i++){
        newList[i] = a->list[i];
    }
    free(a->list);
    a->list = newList;
}

void printDictionary(Dictionary * list){
    printf("#elements: %d\n", list->used);
    printf("Allocated size: %d\n", list->size);
    printf("elements: ");
    int i;
    for(i = 0; i < list->used; i++){
        printf("%d ", list->list[i]);
    }
    printf("\n\n");
    fflush(stdout);
}

//TODO: FIX
// Dictionary ** init_rand_test(int size, int amount){
//     Dictionary ** dictionaries = (Dictionary **) malloc(amount * sizeof(Dictionary *));
//     int i;
//     for(i = 0; i < amount; i++){
//         dictionaries[i] = newDictionaryWithSize(size);
//         int k;
//         int seed = 420 * 101 * i ; 
//         srand(seed);
//         for(k = 0; k < size; k++){
//             int j = rand();
//             dictionaries[i]->list[k] = j;
//         }
//     }
//     return dictionaries; 
// }

Dictionary * init_rand_test_from_array(int * list,int size){
    Dictionary * dict = newDictionaryWithSize(size+1);
    dict->list = list;
    dict->used = size;
    return dict;
}