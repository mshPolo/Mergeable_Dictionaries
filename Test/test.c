//#include "../Dictionary_Linked_List/dictionary_linked_list.c"
#include <time.h>
#include <math.h>
#include "../Dictionary_Search_Tree/dictionary_search_tree.c"
//#include "../Dictionary_Linked_List/dictionary_linked_list.c"
//#include "../Dictionary_Dynamic_List/dictionary_dynamic_list.c"
//#include "../dictionary.h"

Dictionary ** init_rand_test(int size, int amount);

int compare_function2(const void * a, const void * b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

/*
void init(Dictionary * a, int min, int max, int step){
    int i;
    for(i = min; i < max; i += step){
        insert(a, i);
    }
}
*/
/*
void splitMergeTest(Dictionary ** c, int k){
    int i;
    for(i = 0; i < 10; i++){
        Dictionary * a;
        Dictionary * b;
        split(*c,k,&a,&b);
        printDictionary(*c);
        *c = merge(a,b);
        printDictionary(*c);
    }
}
*/
/*
void insertDeleteTest(Dictionary * a, int k){
    int i;
    for(i = 0; i < 100; i++){
        //printDictionary(a);
        insert(a, k);
        //printDictionary(a);
        delete(a, k);
    }
}
*/
/*
void splitMergeTest(Dictionary ** c, int min, int max, int step){
    int i;
    for(i = min; i < max; i += step){
        Dictionary * a;
        Dictionary * b;
        split(*c,i,&a,&b);
        //printDictionary(*c);
        *c = merge(a,b);
        //printDictionary(*c);
    }
}

void insertDeleteTest(Dictionary * a, int min, int max, int step){
    int i;
    for(i = min; i < max; i += step){
        insert(a, i);
        delete(a, i);
    }
}

void searchTest(Dictionary * a, int min, int max, int step){
    int i;
    for(i = min; i < max; i += step){
        //printf("%d\n", i);
        //fflush(stdout);
        search(a,i);
    }
}
*/

//Dictionary * 

void allTests(){
    //Dictionary * a = newDictionary(10);
    /*
    printf("1\n");
    printDictionary(a);
    fflush(stdout);
    init(a);
    printf("2\n");
    printDictionary(a);
    fflush(stdout);
    insertDeleteTest(a, 4201);
    printf("3\n");
    printDictionary(a);
    fflush(stdout);
    splitMergeTest(&a, 4201);
    printf("4\n");
    printDictionary(a);
    fflush(stdout);
    searchTest(a, 1, 10000000, 1000);
    printf("5\n");
    printDictionary(a);
    fflush(stdout);
    */
   /*
    init(a, 0, 10000000, 10);
    insertDeleteTest(a, 1, 10000001, 100000);
    splitMergeTest(&a, 1, 10000001, 100000);
    searchTest(a, 1, 10000001, 100000);
    //printDictionary(a);
    */
}



//void insert_test_rand(Dictionary ** c){
// Dictionary ** init_rand_test(int size, int amount){
//     Dictionary ** dictionaries = (Dictionary **) malloc(size * sizeof(Dictionary *));
//     int i;
//     for(i = 0; i < amount; i++){
//         dictionaries[i] = newDictionary();
//         int k;
//         int seed = 420 * 101 * i ; 
//         srand(seed);
//         for(k = 0; k < size; k++){
//             int j = rand();
//             /*
//             if(k == 71){
//                 inOrderTraversal(dictionaries[i]->root);
//                 printf("\n%d ", j);
//             }
//             */
//             insert(dictionaries[i],j);
//         }
//     }
//     return dictionaries; 
// }


void insert_rand_test(Dictionary ** dictionaries, int amount){
    int i = 0;
    int k;
    for(k = 0; k < amount; k++){
        int j = rand();
        insert(dictionaries[i],j);
    }
}

void delete_rand_test(Dictionary ** dictionaries, int amount){
    int seed = 420 * 101; 
    int i = 0;
    int k;
    for(k = 0; k < amount; k++){
        int j = rand();
        insert(dictionaries[i],j);
    }
}

void split_rand_test(Dictionary ** dictionaries, int amount){
    int i;
    for(i = 0; i < amount; i++){
        Dictionary * a = NULL;
        Dictionary * b = NULL;
        int j = rand();
        split(dictionaries[i],j, &a,&b);
    }
}

void merge_rand_test(Dictionary ** dictionaries, int amount){
    int i;
    for(i = 1; i < amount; i += 2){
        merge(dictionaries[i-1], dictionaries[i]);
    }
}

void merge_test_1(Dictionary ** dictionaries){
    //preOrderTraversal(dictionaries[1]->root); fflush(stdout);
    //printf("SIZE 0: %d\n", countTraversal(dictionaries[0]->root));fflush(stdout);
    //printf("SIZE 1: %d\n", countTraversal(dictionaries[1]->root));fflush(stdout);
    //inOrderTraversal(dictionaries[0]->root); printf("\n");
    //inOrderTraversal(dictionaries[1]->root); printf("\n");
    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
    //inOrderTraversal(dictionaries[0]->root); printf("\n");
    //printf("SIZE 1: %d\n", countTraversal(dictionaries[0]->root));fflush(stdout);
    //preOrderTraversal(dictionaries[0]->root); fflush(stdout);
    dictionaries[1] = merge(dictionaries[2], dictionaries[3]);
    //printf("SIZE 1: %d\n", countTraversal(dictionaries[1]->root));fflush(stdout);
    dictionaries[2] = merge(dictionaries[4], dictionaries[5]);
    dictionaries[3] = merge(dictionaries[6], dictionaries[7]);
    dictionaries[4] = merge(dictionaries[8], dictionaries[9]);
    dictionaries[5] = merge(dictionaries[10], dictionaries[11]);
    dictionaries[6] = merge(dictionaries[12], dictionaries[13]);
    dictionaries[7] = merge(dictionaries[14], dictionaries[15]);
    // int number = (countTraversal(dictionaries[0]->root));
    // int * list = (int *) malloc(number*sizeof(int));
    // int i = 0;
    // inOrderToList(dictionaries[0]->root,list,i);
    // for(int j = 1; j < number; j++){
    //     if(list[i-1] > list[i]){
    //         printf("NOOOOOOO\nNOOOOO\n");
    //         return;
    //     }

    // }
    //printf("SIZE 1: %d\n", countTraversal(dictionaries[0]->root));fflush(stdout);
    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
    //printf("SIZE 1: %d\n", countTraversal(dictionaries[0]->root));fflush(stdout);
    dictionaries[1] = merge(dictionaries[2], dictionaries[3]);
    dictionaries[2] = merge(dictionaries[4], dictionaries[5]);
    dictionaries[3] = merge(dictionaries[6], dictionaries[7]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
    dictionaries[1] = merge(dictionaries[2], dictionaries[3]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
    //printf("SIZE: %d\n", countTraversal(dictionaries[0]->root));fflush(stdout);
    //inOrderTraversal(dictionaries[0]->root);
    //int number = (countTraversal(dictionaries[0]->root));
    //int * list = (int *) malloc(number*sizeof(int));
    //int i = 0;
    //inOrderToList(dictionaries[0]->root,list,i);
}


void split_merge_test_1(Dictionary ** dictionaries){
    Dictionary * a;
    Dictionary * b;
    for(int i = 0; i < 10; i++){ 
        int j = rand();
        //printf("j = %d \n", j);
        //inOrderTraversal(dictionaries[0]->root);printf("\n");fflush(stdout);
        split(dictionaries[0], j, &a, &b);
        //printf("cake\n"); fflush(stdout);
        //inOrderTraversal(a->root);printf("\n");fflush(stdout);
        //inOrderTraversal(b->root);printf("\n");fflush(stdout);
        dictionaries[0] = merge(a, b);
    }
}

void split_merge_test_2(Dictionary ** dictionaries_2){
    Dictionary ** dictionaries = (Dictionary **) malloc(16 * sizeof(Dictionary *)); 
    dictionaries[0] = dictionaries_2[0];
    //inOrderTraversal(dictionaries_2[0]->root);printf("\n");
    //inOrderTraversal(dictionaries[0]->root);printf("\n");
    int list[15];
    for(int i = 0; i < 15; i++){
        list[i] = rand();
    }
    qsort(list, 16, sizeof(int), compare_function2);
    Dictionary * a;
    Dictionary * b;
    for(int i = 0; i < 15; i++){ 
        //printf("j = %d \n", list[i]); fflush(stdout);
        //printf("dictionary is %d, root is %d", dictionaries[i], dictionaries[i]->root); fflush(stdout);
        //inOrderTraversal(dictionaries[i]->root); printf("\n\n\n\n"); fflush(stdout);

        split(dictionaries[i], list[i], &a, &b);
        //printf("f = %d \n", list[i]); fflush(stdout);
        //printf("\n\n A: \n", list[i]); fflush(stdout);
        //preOrderTraversal(a->root);printf("\n"); fflush(stdout);
        //printf("\n\n B:\n", list[i]); fflush(stdout);
        //preOrderTraversal(b->root);printf("\n"); fflush(stdout);
        dictionaries[i] = a;
        dictionaries[i+1] = b;
        //printf("f2 = %d %d\n", list[i], i);fflush(stdout);
    }
    //printf("CAKE\n"); fflush(stdout);
    //inOrderTraversal(dictionaries[0]->root); printf("\n");
    //inOrderTraversal(dictionaries[1]->root); printf("\n");
    fflush(stdout);
    //printDictionary(dictionaries[0]);
    //printDictionary(dictionaries[1]);
    dictionaries[0] = merge(dictionaries[0], dictionaries[15]);
    //printf("CAKE\n"); fflush(stdout);
    dictionaries[1] = merge(dictionaries[1], dictionaries[14]);
    dictionaries[2] = merge(dictionaries[2], dictionaries[13]);
    dictionaries[3] = merge(dictionaries[3], dictionaries[12]);
    dictionaries[4] = merge(dictionaries[4], dictionaries[11]);
    dictionaries[5] = merge(dictionaries[5], dictionaries[10]);
    dictionaries[6] = merge(dictionaries[6], dictionaries[9]);
    dictionaries[7] = merge(dictionaries[7], dictionaries[8]);
    //dictionaries[8] = merge(dictionaries[16], dictionaries[]);
    dictionaries[0] = merge(dictionaries[0], dictionaries[7]);
    dictionaries[1] = merge(dictionaries[1], dictionaries[6]);
    dictionaries[2] = merge(dictionaries[2], dictionaries[5]);
    dictionaries[3] = merge(dictionaries[3], dictionaries[4]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[3]);
    dictionaries[1] = merge(dictionaries[1], dictionaries[2]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
}
/*
void merge_rand_test(Dictionary ** dictionaries, int amount){
    int i;
    for(i = 1; i < amount; i += 2){
        int j = rand();
        merge(dictionaries[i-1], dictionaries[i]);
    }
}
*/
void all_random_tests(int size){
    //int size = 10000;
    int number = 10;
    Dictionary ** dictionaries = init_rand_test(size,number);
    clock_t begin, end;
    int amount = 1;
    double time_spent;

    // //Insert
    // amount = 1000;
    // begin = clock();
    // insert_rand_test(dictionaries,amount);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("Time spent on insert:\t %8.8f, time per insert:\t %8.8f\n", time_spent, time_spent/amount);

    // //Merge
    // dictionaries = init_rand_test(size,number); 
    // //printf("1234"); fflush(stdout);
    // begin = clock();
    // merge_rand_test(dictionaries,number);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("Time spent on merge:\t %8.8f, time per merge:\t %8.8f\n", time_spent, time_spent/(number/2));

    // //Split
    // dictionaries = init_rand_test(size,number); 
    // amount = number;
    // begin = clock();
    // split_rand_test(dictionaries,amount);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("Time spent on split:\t %8.8f, time per split:\t %8.8f\n", time_spent, time_spent/amount);

    // //Delete
    // dictionaries = init_rand_test(size,1); 
    // amount = 1000;
    // begin = clock();
    // delete_rand_test(dictionaries,amount);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("Time spent on delete:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);

    // size = 100000;
    // dictionaries = init_rand_test(size,16); 
    // amount = 1000;
    // begin = clock();
    // merge_test_1(dictionaries);
    // end = clock();
    // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("Time spent on Merge_test_1:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);

    size = 100000;
    dictionaries = init_rand_test(size,16); 
    amount = 1000;
    begin = clock();
    merge_test_1(dictionaries);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on Merge_test_1:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    size = 1000000;
    dictionaries = init_rand_test(size,1); 
    amount = 1000;
    begin = clock();
    split_merge_test_1(dictionaries);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on Split_Merge_test_1:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    size = 1000000;
    dictionaries = init_rand_test(size,1); 
    amount = 1000;
    begin = clock();
    split_merge_test_2(dictionaries);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on Split_Merge_test_1:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    return;
}

Dictionary * init_rand_test2(int size, int i){
    int * list = (int *) malloc(size*sizeof(int));
    int k;
    int seed = 420 * 101 * (i+1) ; 
    srand(seed);
    for(k = 0; k < size; k++){
        int j = rand();
        list[k] = j;
    }
    Dictionary * dict = init_rand_test_from_array(list,size);
    return dict; 
}

Dictionary ** init_rand_test(int size, int amount){
    Dictionary ** dictionaries = (Dictionary **) malloc(amount * sizeof(Dictionary *)); 
    for(int i = 0; i < amount; i++){
        dictionaries[i] = init_rand_test2(size,i);
    }
    return dictionaries; 
}
