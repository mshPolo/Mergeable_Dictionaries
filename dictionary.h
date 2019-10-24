//
// Created by Marcus Skov Hansen on 2019-08-28.
//

//#include "Dictionary.c"

#ifndef UNTITLED_Dictionary_H
#define UNTITLED_Dictionary_H

typedef struct {
    int * list;
    int size;
    int used;
}Dictionary;

void freeDictionary(Dictionary * a);
Dictionary * newDictionary(int size);
void insert(Dictionary * a, int element);
void delete(Dictionary * a, int element);
int search(Dictionary * a, int element);
Dictionary * merge(Dictionary * a, Dictionary * b);
void split(Dictionary * c, int element, Dictionary ** a, Dictionary ** b);
//int findPredecessorIndex(Dictionary * a, int element);
//void increaseSize(Dictionary * a);
//void decreaseSize(Dictionary * a);
//void printDictionary(Dictionary * list);

#endif //UNTITLED_Dictionary_H
