#include "../Dictionary/dictionary.c"

void init(Dictionary * a, int min, int max, int step){
    int i;
    for(i = min; i < max; i += step){
        insert(a, i);
    }
}
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

void allTests(){
    Dictionary * a = newDictionary(10);
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
   
    init(a, 0, 10000000, 10);
    insertDeleteTest(a, 1, 10000001, 100000);
    splitMergeTest(&a, 1, 10000001, 100000);
    searchTest(a, 1, 10000001, 10000);

}