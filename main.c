#include <stdio.h>
#include <stdlib.h>
//#include "Test/test.c"
//#include "Test/test.h"
//#include "Dictionary/dictionary.c"
#include "Dictionary_Linked_List/dictionary_linked_list.c"

int main() {
    /*
    //printf("cake\n");
    Dictionary * a = newDictionary(1);
    Dictionary * b = newDictionary(100);
    Dictionary * a2;
    Dictionary * a3;
    int i;
    //printf("1");
    for(i = 100; i < 1000; i += 200){
        //printf("%d\n",i);
        //fflush(stdout);
        insert(a, i);
        //printDictionary(a);
    }
    for(i = 200; i < 5000; i += 200){
        //printf("%d\n",i);
        //fflush(stdout);
        //delete(a, i);
        //printDictionary(a);
    }
    //printf("done\n");
        fflush(stdout);
    //printf("2");
    for(i = 100; i < 5000; i += 200){
        //printf("%d\n",i);
        //fflush(stdout);
        //insert(b, i);
    }

    

    //printf("3");
    //printDictionary(a);
    //delete(a,400);
    //delete(a,800);
    //delete(a,900);
    //printDictionary(a);
    //printDictionary(b);

    //printDictionary(a);
    //split(a, 1750,&a2,&a3);

    //printDictionary(a2);
    //printDictionary(a3);

    //merge(a,b);
    //printDictionary(a);
    splitMergeTest(a, 420);
    //printDictionary(a);
    insertDeleteTest(a, 420);
    //printDictionary(a);

    //printDictionary(b);
    //Dictionary * c = merge(a,b);
    //printf("4");
    //printDictionary(c);

    //printf("%d\n",search(c, 430));
    //printf("%d\n",search(c, 901));
    //printf("%d\n",search(c, 4900));
    */
   //allTests();
   /*
   Dictionary * dictionary = newDictionary();
   int i;
    for(i = 1; i < 50; i += 5){
        //int k = rand() << 4;
        int k = i;
        printf("%d\n", k);
        insert(dictionary,k);
    }
    printDictionary(dictionary);
    delete(dictionary,3);
    printDictionary(dictionary);
    delete(dictionary,7);
    printDictionary(dictionary);
    delete(dictionary,11);
    insert(dictionary,7);
    printDictionary(dictionary);
    printf("%d\n", search(dictionary, 27));
    printf("%d\n", search(dictionary, 26));
    printf("%d\n", search(dictionary, 25));
    printf("%d\n", search(dictionary, 20));
    //printf(RAND_MAX);
    */
    Dictionary * a = newDictionary();
    Dictionary * b = newDictionary();
    int i;
    for(i = 0; i < 40; i += 5){
        insert(a,i);
        insert(b,i+2);
    }
    printDictionary(a);
    printDictionary(b);
    fflush(stdout);
    Dictionary * c = merge(a,b);
    printDictionary(c);


    return 0;
    
}