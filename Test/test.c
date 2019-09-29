//#include "../Dictionary_Linked_List/dictionary_linked_list.c"
#include <time.h>
#include "../Dictionary_Search_Tree/dictionary_search_tree.c"
//#include "../Dictionary_Linked_List/dictionary_linked_list.c"
//#include "../Dictionary_Dynamic_List/dictionary_dynamic_list.c"
//#include "../Dictionary/dictionary.h"

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
Dictionary ** init_rand_test(int size, int amount){
    Dictionary ** dictionaries = (Dictionary **) malloc(size * sizeof(Dictionary *));
    int i;
    for(i = 0; i < amount; i++){
        dictionaries[i] = newDictionary();
        int k;
        int seed = 420 * 101 * i ; 
        srand(seed);
        for(k = 0; k < size; k++){
            int j = rand();
            /*
            if(k == 71){
                inOrderTraversal(dictionaries[i]->root);
                printf("\n%d ", j);
            }
            */
            insert(dictionaries[i],j);
        }
    }
    return dictionaries; 
}

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
        int j = rand();
        merge(dictionaries[i-1], dictionaries[i]);
    }
}

void all_random_tests(){
    int size = 2500;
    int number = 10;
    Dictionary ** dictionaries = init_rand_test(size,number);
    clock_t begin, end;
    int amount;
    double time_spent;

    //Insert
    amount = 100;
    begin = clock();
    insert_rand_test(dictionaries,1);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on insert:\t %8.8f, time per insert:\t %8.8f\n", time_spent, time_spent/amount);

    //Merge
    dictionaries = init_rand_test(size,number); 
    amount = number;
    begin = clock();
    merge_rand_test(dictionaries,amount);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on merge:\t %8.8f, time per merge:\t %8.8f\n", time_spent, time_spent/amount);

    //Split
    dictionaries = init_rand_test(size,number/2); 
    amount = number/2;
    begin = clock();
    split_rand_test(dictionaries,amount);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on split:\t %8.8f, time per split:\t %8.8f\n", time_spent, time_spent/amount);

    //Delete
    dictionaries = init_rand_test(size,1); 
    amount = 100;
    begin = clock();
    delete_rand_test(dictionaries,amount);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on delete:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);

    return;
}

