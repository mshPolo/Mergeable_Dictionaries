#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

#include "Test/test.c"

//#include "Test/test.h"
//#include "Dictionary/dictionary.c"
//#include "Dictionary_Linked_List/dictionary_linked_list.c"
//#include "Dictionary_Search_Tree/dictionary_search_tree.c"
/*
int compare_function(const void * a, const void * b) {
int *x = (int *) a;
int *y = (int *) b;
return *x - *y;
//return a - b;
}
*/
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
/*
    Dictionary * dictionary = newDictionary();
    //printf("A\n");
    inOrderTraversal(dictionary->root);
    insert(dictionary,5);
    insert(dictionary,2);
    insert(dictionary,21);
    insert(dictionary,6);
    //preOrderTraversal(dictionary->root);
    //printf("\n");
    fflush(stdout);
    insert(dictionary,5);
    //preOrderTraversal(dictionary->root);
    //printf("\n");
    fflush(stdout);
    insert(dictionary,8);
    //preOrderTraversal(dictionary->root);
    //printf("\n");
    fflush(stdout);
    insert(dictionary,12);
    //preOrderTraversal(dictionary->root);
    //printf("\n");
    fflush(stdout);
    insert(dictionary,14);
    insert(dictionary,11);
    insert(dictionary,3);
    //preOrderTraversal(dictionary->root);
    //printf("\n");
    fflush(stdout);
    //printf("\nB\n");
    //inOrderTraversal(dictionary->root);
    //printf("\n");
    fflush(stdout);
    //printf("\nC\n");
    //preOrderTraversal(dictionary->root);
    fflush(stdout);
    //printf("\n%d\n", search(dictionary,11));
    */
    /*
    printf("%d\n", countTraversal(dictionary->root));
    int size = countTraversal(dictionary->root);
    int * arrayA = (int *) malloc(size*sizeof(int));
    int i = 0;
    inOrderToList(dictionary->root,arrayA,&i);
    for(int k = 0; k < size; k++){
        printf("%d\n", arrayA[k]);
    }
    */
/*
   int * a = (int *) malloc(10*sizeof(int));
   int * b = (int *) malloc(10*sizeof(int));
   int * c = (int *) malloc(20*sizeof(int));
    for(int i = 0; i < 5; i++){
        a[i] = i;
        b[i] = 4*i;
    }
    int size = mergeArrays(c,a,5,b,5);
    for(int i = 0; i < size; i++){
        printf("%d\t",c[i]);
    }
    printf("\nSize = %d\n", size);
    fflush(stdout);
    Node * node = BSTFromArray(c,0,size-1,NULL);
    inOrderTraversal(node);
    printf("\n");
    preOrderTraversal(node);
    */
   /*
   Dictionary * a = newDictionary();
   Dictionary * b = newDictionary();
   for(int i = 0; i < 4; i++){
       insert(a,4*i);
       insert(b,4*(i+2));
   }
   
   Dictionary * c = merge(a,b);
    inOrderTraversal(c->root);
    printf("\n");
    //preOrderTraversal(c->root);
    fflush(stdout);
    //search(c,28);
    delete(c,28);
    //printf("1234\n");
    fflush(stdout);
    inOrderTraversal(c->root);
    */

    /*
    Dictionary * a = NULL;
    Dictionary * b = NULL;
    printf("%d\n", search(dictionary,1));
    split(dictionary,1,&a,&b);
    fflush(stdout);
    inOrderTraversal(a->root);
    printf("\n");
    fflush(stdout);
    inOrderTraversal(b->root);
    printf("\n");
    fflush(stdout);
    printf("%d", countTraversal(b));
    */
    //srand(2);
    //printf("\n %d ", rand());
    //printf("%d", RAND_MAX);
    /*
    int size = 1;
    Dictionary ** dictionaries = init_rand_test(size);
    
    for(int i = 0; i < size; i++){
        printf("%d", countTraversal(dictionaries[i]->root));
        printf("\n");
    }
    */
    /*
    clock_t begin = clock();
    init_rand_test(3);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    */
    //all_random_tests();

    // Dictionary * a = newDictionary();
    // Dictionary * b = newDictionary();
    // //printf("A\n");
    // //inOrderTraversal(dictionary->root);
    // insert(a,50);
    // insert(a,5);
    // insert(a,10);
    // insert(a,15);
    // insert(a,20);
    // insert(b,40);
    // insert(b,1);
    // insert(b,2);
    // insert(b,22);
    // insert(b,27);
    // insert(a,2);
    // insert(a,3);
    // insert(a,13);
    // insert(a,19);
    // insert(a,20);
    // insert(b,120);
    // insert(b,3);
    // insert(b,5);
    // insert(b,23);
    // insert(b,26);
    //inOrderTraversal(a->root);
    //inOrderTraversal(b->root);
    
    // fflush(stdout);
    //Dictionary * c = merge(a,b);
    // printf("\n");
    // preOrderTraversal(c->root); 
    //inOrderTraversal(c->root); 
    // fflush(stdout); 
    //return 0;
    /*
    int size = 10;
    int * list = init_rand_test2(size,1);

    for(int k = 0; k < size; k++){
        printf("%d\n", list[k]);
    }
    */
   //int list[] = {5,4,3,1,2};
   //qsort(list, 5, sizeof(int), compare_function);
   //Dictionary * dict = init_rand_test_from_array(list,5);
   //printDictionary(dict);
   //printf("%d %d %d", list, &list[0], &list[1]);
   //all_random_tests(1000000);
   //Dictionary * dict = init_rand_test_from_array(list,size);
    //printDictionary(dict);
    //inOrderTraversal(dict->root);
    all_random_tests(100000);
    return 0;
}