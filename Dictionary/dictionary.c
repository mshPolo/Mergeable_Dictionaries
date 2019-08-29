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

Dictionary * newDictionary(int size) {
    Dictionary * a = (Dictionary * ) malloc(sizeof(Dictionary));
    a->list = (int *)malloc(size * sizeof(int));
    a->used = 0;
    a->size = size;
    return a;
}

int search(Dictionary * a, int element){
    //TODO
    return 0;
}

void insertDictionary(Dictionary * list, int element){
    //TODO: if used = size update
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

Dictionary * mergeDictionary(Dictionary * a, Dictionary * b){
    Dictionary * newList = newDictionary(a->used+b->used);
    int countA = 0,countB = 0;
    while (countA < a->used && countB < b->used){
        if(a->list[countA] < b->list[countB]){
            newList->list[countA+countB] = a->list[countA];
            countA++;
        }else{
            newList->list[countA+countB] = b->list[countB];
            countB++;
        }
    }

    while (countA < a->used){ newList->list[countA+countB] = a->list[countA]; countA++; }
    while (countB < b->used){ newList->list[countA+countB] = b->list[countB]; countA++; }
    
    newList->used = a->used + b->used;
    //TODO: FREE a AND b

    return newList;
}

void splitDictionary(Dictionary * c, int e, Dictionary * a, Dictionary * b){
    //TODO
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

