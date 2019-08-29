#include <stdio.h>
#include "Dictionary/dictionary.c"

int main() {
    Dictionary * a = newDictionary(100);
    Dictionary * b = newDictionary(100);
    int i;
    for(i = 1; i < 50; i += 2){
        insertDictionary(a, i);
    }
    
    for(i = 2; i < 50; i += 2){
        insertDictionary(b, i);
    }
    
    printDictionary(a);
    printDictionary(b);

    Dictionary * c = mergeDictionary(a,b);

    printDictionary(c);

    return 0;
}