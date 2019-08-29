//
// Created by Marcus Skov Hansen on 2019-08-28.
//

#include "Dictionary.c"

#ifndef UNTITLED_Dictionary_H
#define UNTITLED_Dictionary_H

Dictionary * newList(int size);
void insertDictionary(Dictionary * list, int element);
void printDictionary(Dictionary * list);
void printNumber(int i);
Dictionary * mergeDictionary(Dictionary * a, Dictionary * b);

#endif //UNTITLED_Dictionary_H
