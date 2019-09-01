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


Dictionary * newDictionary(int size);
int search(Dictionary * a, int element);
int findPredecessorIndex(Dictionary * a, int element);
//INSERT
void delete(Dictionary * a, int element);
Dictionary * mergeDictionary(Dictionary * a, Dictionary * b);
//void splitDictionary(Dictionary * c, int element, Dictionary ** a, Dictionary * b);

Dictionary * newDictionary(int size) {
    Dictionary * a = (Dictionary * ) malloc(sizeof(Dictionary));
    a->list = (int *)malloc(size * sizeof(int));
    a->used = 0;
    a->size = size;
    return a;
}

int search(Dictionary * a, int element){
    int i = findPredecessorIndex(a,element);
    return a->list[i];
}

int findPredecessorIndex(Dictionary * a, int element){
    int left = 0;
    int right = a->used-1;
    int k = 0;
    while(left < right && k++ < 20){
            //printf("left: %d\n", left);
            //printf("right: %d\n", right);
            int middle = (left + right)/2;
            //printf("middle: %d\n", middle);
        if(a->list[middle] < element){
            left = middle + 1;
        }else{
            right = middle;
        }
    }
    if(a->list[left] > element && left > 0){
        return left-1;
    }else{
        return left;
    }
}


void insertDictionary(Dictionary * list, int element){
    //TODO: if used = size update
    //TODO: should not insert duplicates
    //TODO: use binary search
    int i = 0;
    while(i < list->used && list->list[i] < element) i++;
    int temp1  = list->list[i];
    list->list[i++] = element;
    while(i < list->used){
         int current = list->list[i];
         list->list[i++] = temp1;
         temp1 = current;
    }
    list->used++;
}

void delete(Dictionary * a, int element){
    //TODO: if used = size update
    int i = findPredecessorIndex(a,element);
    if(a->list[i] != element) return;
    while(i < a->used){
         int current = a->list[i+1];
         a->list[i++] = current;
    }
    a->used--;
}

Dictionary * mergeDictionary(Dictionary * a, Dictionary * b){
    Dictionary * c = newDictionary(a->used+b->used);
    int countA = 0,countB = 0;
    
    while (countA < a->used && countB < b->used){
        if(a->list[countA] < b->list[countB]){
            c->list[countA+countB] = a->list[countA];
            countA++;
        }else{
            c->list[countA+countB] = b->list[countB];
            countB++;
        }
    }
    
    while (countA < a->used){ c->list[countA+countB] = a->list[countA]; countA++; }
    while (countB < b->used){ c->list[countA+countB] = b->list[countB]; countB++; }
    
    c->used = a->used + b->used;
    //TODO: FREE a AND b
    
    return c;
}

void splitDictionary(Dictionary * c, int element, Dictionary ** a, Dictionary ** b){
    //TODO
    int i = findPredecessorIndex(c,element);
    *a = newDictionary(2 * i);
    *b = newDictionary(2 * (c->used - i));
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
    
    //TODO: FREE c
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
}

