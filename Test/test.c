#include <time.h>
#include <math.h>
#include "../Dictionary_Search_Tree/dictionary_search_tree.c"
//#include "../Dictionary_Linked_List/dictionary_linked_list.c"
//#include "../Dictionary_Dynamic_List/dictionary_dynamic_list.c"

Dictionary ** init_rand_test(int size, int amount);

int compare_function2(const void * a, const void * b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
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
    srand(seed);
    for(k = 0; k < amount; k++){
        int j = rand();
        delete(dictionaries[i],j);
    }
}

void search_rand_test(Dictionary ** dictionaries, int amount){
    int seed = 420 * 101; 
    int i = 0;
    int k;
    srand(seed);
    for(k = 0; k < amount; k++){
        int j = rand();
        search(dictionaries[i],j);
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
    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
    dictionaries[1] = merge(dictionaries[2], dictionaries[3]);
    dictionaries[2] = merge(dictionaries[4], dictionaries[5]);
    dictionaries[3] = merge(dictionaries[6], dictionaries[7]);
    dictionaries[4] = merge(dictionaries[8], dictionaries[9]);
    dictionaries[5] = merge(dictionaries[10], dictionaries[11]);
    dictionaries[6] = merge(dictionaries[12], dictionaries[13]);
    dictionaries[7] = merge(dictionaries[14], dictionaries[15]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
    dictionaries[1] = merge(dictionaries[2], dictionaries[3]);
    dictionaries[2] = merge(dictionaries[4], dictionaries[5]);
    dictionaries[3] = merge(dictionaries[6], dictionaries[7]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
    dictionaries[1] = merge(dictionaries[2], dictionaries[3]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
}


void split_merge_test_1(Dictionary ** dictionaries){
    Dictionary * a;
    Dictionary * b;
    for(int i = 0; i < 10; i++){ 
        int j = rand();
        split(dictionaries[0], j, &a, &b);
        dictionaries[0] = merge(a, b);
    }
}

void split_merge_test_2(Dictionary ** dictionaries_2){
    Dictionary ** dictionaries = (Dictionary **) malloc(16 * sizeof(Dictionary *)); 
    dictionaries[0] = dictionaries_2[0];
    int list[15];
    for(int i = 0; i < 15; i++){
        list[i] = rand();
    }
    qsort(list, 16, sizeof(int), compare_function2);
    Dictionary * a;
    Dictionary * b;
    for(int i = 0; i < 15; i++){ 
        split(dictionaries[i], list[i], &a, &b);
        dictionaries[i] = a;
        dictionaries[i+1] = b;
    }

    fflush(stdout);
    dictionaries[0] = merge(dictionaries[0], dictionaries[15]);
    dictionaries[1] = merge(dictionaries[1], dictionaries[14]);
    dictionaries[2] = merge(dictionaries[2], dictionaries[13]);
    dictionaries[3] = merge(dictionaries[3], dictionaries[12]);
    dictionaries[4] = merge(dictionaries[4], dictionaries[11]);
    dictionaries[5] = merge(dictionaries[5], dictionaries[10]);
    dictionaries[6] = merge(dictionaries[6], dictionaries[9]);
    dictionaries[7] = merge(dictionaries[7], dictionaries[8]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[7]);
    dictionaries[1] = merge(dictionaries[1], dictionaries[6]);
    dictionaries[2] = merge(dictionaries[2], dictionaries[5]);
    dictionaries[3] = merge(dictionaries[3], dictionaries[4]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[3]);
    dictionaries[1] = merge(dictionaries[1], dictionaries[2]);

    dictionaries[0] = merge(dictionaries[0], dictionaries[1]);
}

void all_random_tests(int size){
    int number = 20;
    Dictionary ** dictionaries = init_rand_test(size,number);
    clock_t begin, end;
    int amount = 1;
    double time_spent;

    //Insert
    amount = 1000;
    begin = clock();
    insert_rand_test(dictionaries,amount);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on insert:\t %8.8f, time per insert:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    //Merge
    dictionaries = init_rand_test(size,number); 
    //printf("1234"); fflush(stdout);
    begin = clock();
    merge_rand_test(dictionaries,number);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on merge:\t %8.8f, time per merge:\t %8.8f\n", time_spent, time_spent/(number/2));
    fflush(stdout);

    //Split
    dictionaries = init_rand_test(size,number); 
    amount = number;
    begin = clock();
    split_rand_test(dictionaries,amount);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on split:\t %8.8f, time per split:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    //Delete
    dictionaries = init_rand_test(size,1); 
    amount = 1000;
    begin = clock();
    delete_rand_test(dictionaries,amount);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on delete:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    Search
    dictionaries = init_rand_test(size,1); 
    amount = 1000;
    begin = clock();
    search_rand_test(dictionaries,amount);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on search:\t %8.8f, time per search:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    size = 100000;
    dictionaries = init_rand_test(size,16); 
    amount = 1000;
    begin = clock();
    merge_test_1(dictionaries);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on Merge_test_1:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);

    size = 200000;
    dictionaries = init_rand_test(size,16); 
    amount = 1000;
    begin = clock();
    merge_test_1(dictionaries);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on Merge_test_1:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    size = 4000000;
    dictionaries = init_rand_test(size,1); 
    amount = 1000;
    begin = clock();
    split_merge_test_1(dictionaries);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on Split_Merge_test_1:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);
    fflush(stdout);

    size = 4000000;
    dictionaries = init_rand_test(size,1); 
    amount = 1000;
    begin = clock();
    split_merge_test_2(dictionaries);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spent on Split_Merge_test_2:\t %8.8f, time per delete:\t %8.8f\n", time_spent, time_spent/amount);
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
