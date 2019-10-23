#include <stdlib.h>
#include <stdio.h>

typedef struct Element{
    int value;
    struct Element * next;
}Element;

typedef struct Dictionary{
    int size;
    struct Element * head;
}Dictionary;

Element * newElement(int element);

Dictionary * newDictionary(){
    Dictionary * dictionary = (Dictionary *) malloc(sizeof(Dictionary));
    dictionary->head = NULL;
    dictionary->size = 0;
    return dictionary;
}

void insert(Dictionary * dictionary, int value){
    if(dictionary->head == NULL){
        dictionary->head = newElement(value);
        dictionary->size++;
    }else if(dictionary->head->value > value){
        Element * temp = dictionary->head;
        dictionary->head = newElement(value);
        dictionary->head->next = temp;
        dictionary->size++;
    }else{
            Element * head = dictionary->head;
        while (head->next != NULL && head->next->value < value){
            head = head->next;
        }
        Element * new_list_element = newElement(value);
        Element * temp = head->next;
        head->next = new_list_element;
        new_list_element->next = temp;
        dictionary->size++;
    }
    return;
}

void delete(Dictionary * dictionary, int value){
    if(dictionary->head == NULL){
        return;
    }else if(dictionary->head->next == NULL){
        if (dictionary->head->value == value)
        {
            free(dictionary->head);
            dictionary->head = NULL;
            //TODO FREE MEMORY STUFF HERE
            dictionary->size--;
        }
    }else{
        Element * current = dictionary->head;
        while (current->next != NULL && current->next->value < value){
            current = current->next;
        }
        if(current->next != NULL && current->next->value == value){
            Element * temp = current->next;
            current->next = current->next->next;
            //TODO FREE MEMORY STUFF HERE
            free(temp);
            dictionary->size--;
        }
    }
    return;
}

int search(Dictionary * dictionary, int value){
    if(dictionary->head == NULL){
    }else if(dictionary->head->next == NULL){
        if (dictionary->head->value <= value)
            return dictionary->head->value;
    }else{
        Element * current = dictionary->head;
        while (current->next != NULL && current->next->value <= value)
            current = current->next;
        if(current->value <= value)
            return current->value;
    }
    return -1;
}

Dictionary * merge(Dictionary * a, Dictionary * b){
    Dictionary * c = newDictionary();
    Element * head = NULL;
    Element * current = NULL;
    Element * currentA = a->head;
    Element * currentB = b->head;
    if(a->head != NULL && b->head != NULL){
        if(currentA->value < currentB->value){
            head = a->head;
            currentA = currentA->next;
        }else{
            head = b->head;
            currentB = currentB->next;
        }
        current = head;
        while (currentA != NULL && currentB != NULL)
        {
        if(currentA->value < currentB->value){
            current->next = currentA;
            currentA = currentA->next;
        }else{
            current->next = currentB;
            currentB = currentB->next;
        }
            current = current->next;
        }
    }
    if(a->head != NULL) current->next = currentA;
    if(b->head != NULL) current->next = currentB;
    c->head = head;
    c->size = a->size + b->size;
    return c;
}

void split(Dictionary * c, int value, Dictionary ** a, Dictionary ** b){
    if (c == NULL) return;
    (*a) = newDictionary();
    (*b) = newDictionary();
    //(*a)->head = c->head;
    Element * current = c->head;
    int count = 0;
    if(c->head == NULL){
        (*a)->head = NULL;
        (*a)->size = 0;
        (*b)->head = NULL;
        (*b)->size = 0;

    }else if(current->value > value){
        (*a)->head = NULL;
        (*a)->size = 0;
        (*b)->head = c->head;
        (*b)->size = c->size;
    }else{
        (*a)->head = c->head;
        count++;
        Element * current = c->head;
        while (current->next != NULL && current->next->value <= value){
            current = current->next;
            count++;
        }
        (*b)->head = current->next;
        current->next = NULL;
        (*a)->size = count;
        (*b)->size = c->size - count;
    }
}

Element * newElement(int value){
    Element * dictionary = (Element *) malloc(sizeof(Element));
    dictionary->value = value;
    dictionary->next = NULL;
    return dictionary;
}

void freeElement(Element * element){
    free(element);
}

//TODO: IMPLEMENT FUNCTION TO FREE DICTIONARY

void printDictionary(Dictionary * dictionary){
    Element * head = dictionary->head;
    printf("Size: %d\n", dictionary->size);
    printf("Elements: ");
    while(head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

//TODO: FIX
// Dictionary ** init_rand_test(int size, int amount){
//     Dictionary ** dictionaries = (Dictionary **) malloc(amount * sizeof(Dictionary *));
//     int i;
//     for(i = 0; i < amount; i++){
//         dictionaries[i] = newDictionary();
//         int k;
//         int seed = 420 * 101 * i ; 
//         srand(seed);
//         dictionaries[i]->head = newElement(rand());
//         Element * current = dictionaries[i]->head;
//         for(k = 0; k < size; k++){
//             int j = rand();
//             current->next = newElement(j);
//             current = current->next;
//         }
//     }
//     return dictionaries; 
// }
int compare_function(const void * a, const void * b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

Dictionary * init_rand_test_from_array(int * list,int size){
    qsort(list, size, sizeof(int), compare_function);
    Dictionary * dict = newDictionary();
    insert(dict,list[0]);
    Element * current = dict->head;
    for(int i = 1; i < size; i++){
        current->next = newElement(list[i]);
        current = current->next;
    } 
    dict->size = size;
    return dict;
}