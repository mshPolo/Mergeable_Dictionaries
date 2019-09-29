#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int value;
    struct Node * left;
    struct Node * right;
    struct Node * parent;
}Node;

typedef struct Dictionary{
    int size;
    Node * root;
}Dictionary;

//Helper functions
Node * newNode(int value);
void rightRotate(Node * node);
void leftRotate(Node * node);
void splay(Node * node);
//Node * findPredecessor(Dictionary * dictionary, int value);
Node * findPredecessor(Node * current, int value);
void inOrderToList(Node * node, int * array, int * index);
int countTraversal(Node * node);
int mergeArrays(int * result, int * a, int sizeA, int * b, int sizeB);
Node * BSTFromArray(int * array, int left, int right, Node * parent);
void someFunction(Node * node);

Dictionary * newDictionary(){
    Dictionary * dictionary = (Dictionary *) malloc(sizeof(dictionary));
    dictionary->root = NULL;
    dictionary->size = 0;
    return dictionary;
}

int search(Dictionary * dictionary, int value){/*
    Node * current = dictionary->root;
    Node * currentPredecessor = current;
    while(current != NULL && current->value != value){
        if(current->value < value){
            if(current->value > currentPredecessor->value){
                currentPredecessor = current;
            }
            current = current->right;
        }else{
            current = current->left;
        }
    }
    return currentPredecessor->value;
    */
   //printf("a\n"); fflush(stdout);
   Node * predecesssor = findPredecessor(dictionary->root,value);
    //printf("ab\n"); fflush(stdout);
   if(!predecesssor) return -1;
      //printf("ac\n"); fflush(stdout);
   splay(predecesssor);
      //printf("ad\n"); fflush(stdout);
   dictionary->root = predecesssor;
   return predecesssor->value;
}

void insert(Dictionary * dictionary, int value){
    //if(value == 824938981) printf();
    //int k = 0;
    Node * new = newNode(value);
    if(dictionary->root == NULL)
        dictionary->root = new;
    else{
        Node * current = dictionary->root;
        while(current != NULL){
            //if(value == 824938981) printf("\ncurrent : %d\n", current->value);
            //printf("current : %d, left : %d, right %d, parent %d\n", current->value, current->left, current->right, current->parent); fflush(stdout);
            if(current->value == value) return;
            if(current->value < value){
                //printf("abcd\n"); fflush(stdout);
                if(current->right == NULL){
                    //printf("abcd2\n"); fflush(stdout);
                    current->right = new;
                    //printf("abcd3\n"); fflush(stdout);
                    new->parent = current;
                    //printf("abcd4\n"); fflush(stdout);
                    break;
                }
                current = current->right;
            }else{
                if(current->left == NULL){
                    current->left = new;
                    new->parent = current;
                    break;
                }
                current = current->left;
            }
        }
        //printf("abcd5\n"); fflush(stdout);
        //if(value == 824938981) printf("\nC: %d\n",countTraversal(dictionary->root));
        splay(new);
        //if(value == 824938981) printf("\nC: %d\n",countTraversal(dictionary->root));
        dictionary->root = new;
        //if(value == 824938981) printf("\nC: %d\n",countTraversal(dictionary->root));
        //if(current->value == value) return;
        //dictionary->root = new;
    }
}

void delete(Dictionary * dictionary, int value){
    //printf("ABCD\n");
    fflush(stdout);
    Node * predecesssor = findPredecessor(dictionary->root,value);
    //printf("ABCD\n");
    fflush(stdout);
    if(!predecesssor || predecesssor-> value != value) return;
    splay(predecesssor);
    //printf("ABCD\n");
    fflush(stdout);
    Node * right = predecesssor->right;
    Node * left = predecesssor->left;
    //someFunction(predecesssor);
    //someFunction(left);
    someFunction(right);
    free(predecesssor);
    if(left) left->parent = NULL;
    if(right) right->parent = NULL;
    //printf("ABCD\n");
    fflush(stdout);
    if(!left){
        dictionary->root = right;
        return;
    }
    Node * maxInLeft = findPredecessor(left,value);
    splay(maxInLeft);
    maxInLeft->right = right;
    if(right) right->parent = maxInLeft;
    dictionary->root = maxInLeft;
}

void split(Dictionary * c, int value, Dictionary ** a, Dictionary ** b){
    if(!c) return;
    Node * predecessor = findPredecessor(c->root,value);
    splay(predecessor);
    c->root = predecessor;
    *a = newDictionary();
    *b = newDictionary();
    (*a)->root = predecessor;
    if(predecessor){
        (*b)->root = predecessor->right;
        predecessor->right = NULL;
        if(predecessor->right){
            predecessor->right->parent = NULL;
        }
    }else{
        (*b)->root = c->root;
    }
}

Dictionary * merge(Dictionary * a, Dictionary * b){
    Dictionary * c = newDictionary();
    int sizeA = countTraversal(a->root);
    int sizeB = countTraversal(b->root);
    int * arrayA = (int *) malloc(sizeA*sizeof(int));
    int * arrayB = (int *) malloc(sizeB*sizeof(int));
    int k = 0;
    inOrderToList(a->root, arrayA, &k);
    k = 0;
    inOrderToList(b->root, arrayB, &k);
    int * arrayAll = (int *) malloc((sizeA+sizeB)*sizeof(int));
    int size = mergeArrays(arrayAll,arrayA,sizeA,arrayB,sizeB);
    Node * root = BSTFromArray(arrayAll, 0, size-1, NULL);
    c->root = root;
    return c;
}


void someFunction(Node * node){
    if(!node) printf("NULL\n");
    else
        //printf("val: %d, current : %d, left : %d, right %d, parent %d\n", node->value, node, node->left, node->right, node->parent);
        fflush(stdout);
}

//THIS LOOKS A LOT LIKE THE SPLAY FUNCTION ON WIKIPEDIA IN CASE YOU NEED TO HAND THIS IN
void splay(Node * node){
    if(!node) return;
    int k = 0;
    //printf("\n");
    while(node->parent && k++ < 10){
        //someFunction(node);
        //someFunction(node->parent);
        //someFunction(node->parent->parent);
        if (node->parent->parent){
            //printf("%d\n", node->parent->parent->left == node->parent);
            fflush(stdout);
            //printf("%d\n", node->parent->left == node && node->parent->parent->right == node->parent);
            fflush(stdout);
        }
            //printf("%d\n", node->parent->parent->left == node->parent);
            //printf("%d\n", node->parent->left == node && node->parent->parent->left == node->parent);
        fflush(stdout);
        if(!node->parent->parent){
            //printf("A\n");
            fflush(stdout);
            if(node->parent->left == node) rightRotate(node);
            else leftRotate(node);
        }else if (node->parent->left == node && node->parent->parent->left == node->parent){
            //printf("B\n");
            fflush(stdout);
            rightRotate(node->parent);
            rightRotate(node);
        }else if (node->parent->right == node && node->parent->parent->right == node->parent){
            //printf("C\n");
            fflush(stdout);
            leftRotate(node->parent);
            leftRotate(node);
        }else if (node->parent->left == node && node->parent->parent->right == node->parent){
            //printf("D\n");
            fflush(stdout);
            rightRotate(node);
            leftRotate(node);
        }else{
            //printf("E\n");
            fflush(stdout);
            leftRotate(node);
            //printf("1234");
            rightRotate(node);
        }
    }
    //dictionary->root = node;
    //printf("\n");
}

void rightRotate(Node * node){
    Node * parent = node->parent;
    Node * grandParent = parent->parent;
    Node * b = node->right;
    if(grandParent){
        if(grandParent->left == parent)
            grandParent->left = node;
        else
            grandParent->right = node;
    }
    node->parent = parent->parent;
    parent->parent = node;
    parent->left = b;
    node->right = parent;
    if(b){
        b->parent = parent;
    }
}

void leftRotate(Node * node){
    Node * parent = node->parent;
    Node * grandParent = parent->parent;
    Node * b = node->left;
    if(grandParent){
        if(grandParent->left == parent)
            grandParent->left = node;
        else
            grandParent->right = node;
    }
    node->parent = parent->parent;
    parent->parent = node;
    parent->right = b;
    node->left = parent;
    if(b) b->parent = parent;
}

void inOrderTraversal(Node * node){
    if(node == NULL) return;
    inOrderTraversal(node->left);
    printf("%d ", node->value);
    inOrderTraversal(node->right);
}

void inOrderToList(Node * node, int * array, int * index){
    if(node == NULL) return;
    inOrderToList(node->left, array, index);
    array[(*index)++] = node->value;
    inOrderToList(node->right, array, index);
}

int countTraversal(Node * node){
    if(!node) return 0;
    //printf("cake");
    return countTraversal(node->left) + countTraversal(node->right) + 1;
}

void preOrderTraversal(Node * node){
    //if(node == NULL) return;
    //someFunction(node);
    if(node == NULL){
        printf("NULL");
        return;
    }
    
    printf("%d ", node->value);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

//Node * findPredecessor(Dictionary * dictionary, int value){
Node * findPredecessor(Node * current, int value){
    //Node * current = dictionary->root;
    Node * currentPredecessor = NULL;
    while(current != NULL && current->value != value){
        if(current->value < value){
            if(!currentPredecessor || current->value > currentPredecessor->value){
                currentPredecessor = current;
            }
            current = current->right;
        }else{
            current = current->left;
        }
    }
    if(current && current->value == value) currentPredecessor = current;
    //if(!currentPredecessor) printf("pre is NULL\n "); fflush(stdout);
    return (currentPredecessor);
}

Node * newNode(int value){
    Node * node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

//Assumes enough space in result
int mergeArrays(int * result, int * a, int sizeA, int * b, int sizeB){
    int countA = 0,countB = 0, i = 0;
    int sizeResult = sizeA + sizeB;
    while (countA < sizeA && countB < sizeB){
        if(a[countA] < b[countB]){
            result[i++] = a[countA++];
        } else if(a[countA] == b[countB]) {
            result[i++] = a[countA++];
            countB++;
            sizeResult--;
        } else {
            result[i++] = b[countB++];
        }
    }
    while (countA < sizeA) result[i++] = a[countA++];
    while (countB < sizeB) result[i++] = b[countB++];
    return sizeResult;
}

Node * BSTFromArray(int * array, int left, int right, Node * parent){
    int index = (left + right)/2;
    if(left > right) return NULL;
    //printf("left = %d, right = %d, index = %d\n", left, right, index);
    //fflush(stdout);
    Node * node = newNode(array[index]);
    node->parent = parent;
    node->left = BSTFromArray(array,left,index-1,node);
    node->right = BSTFromArray(array,index+1,right,node);
    return node;
}


