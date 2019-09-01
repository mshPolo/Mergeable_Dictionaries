#include <stdio.h>
#include "Dictionary/dictionary.c"

int main() {
    
    //printf("cake\n");
    Dictionary * a = newDictionary(100);
    Dictionary * b = newDictionary(100);
    Dictionary * a2;
    Dictionary * a3;
    int i;
    //printf("1");
    for(i = 0; i < 5000; i += 200){
        insertDictionary(a, i);
    }
    //printf("2");
    for(i = 100; i < 5000; i += 200){
        insertDictionary(b, i);
    }

    

    //printf("3");
    printDictionary(a);
    //delete(a,400);
    //delete(a,800);
    //delete(a,900);
    //printDictionary(a);
    //printDictionary(b);

    printDictionary(a);
    splitDictionary(a, 1750,&a2,&a3);

    printDictionary(a2);
    printDictionary(a3);

    //mergeDictionary(a,b);
    //Dictionary * c = mergeDictionary(a,b);
    //printf("4");
    //printDictionary(c);

    //printf("%d\n",search(c, 430));
    //printf("%d\n",search(c, 901));
    //printf("%d\n",search(c, 4900));
    
    return 0;
    
}