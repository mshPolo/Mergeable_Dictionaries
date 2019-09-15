#include <stdio.h>
#include <stdlib.h>
//#include "Test/test.c"
//#include "Test/test.h"
//#include "Dictionary/dictionary.c"
//#include "Dictionary_Linked_List/dictionary_linked_list.c"
#include "Dictionary_Search_Tree/dictionary_search_tree.c"

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

   //LINKED_LIST
   /*
    Dictionary * a = newDictionary();
    Dictionary * b = newDictionary();
    int i;
    for(i = 1; i < 40; i += 5){
        insert(a,i);
        insert(b,i+2);
    }
    printDictionary(a);
    printDictionary(b);
    fflush(stdout);
    Dictionary * c = merge(a,b);
    printDictionary(c);
    split(NULL,17,&a,&b);
    printDictionary(a);
    printDictionary(b);
*/
    Dictionary * dictionary = newDictionary();
    printf("A\n");
    inOrderTraversal(dictionary->root);
    insert(dictionary,5);
    insert(dictionary,2);
    insert(dictionary,21);
    insert(dictionary,6);
    insert(dictionary,5);
    insert(dictionary,8);
    insert(dictionary,12);
    insert(dictionary,14);
    printf("\nB\n");
    inOrderTraversal(dictionary->root);
    printf("\nC\n");
    preOrderTraversal(dictionary->root);
    printf("\n%d\n", search(dictionary,11));
    return 0;
    
}