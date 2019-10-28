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
Node * findPredecessor(Node * current, int value);
void inOrderToList(Node * node, int * array, int * index);
int countTraversal(Node * node);
void inOrderTraversal(Node * node);
void preOrderTraversal(Node * node);
int mergeArrays(int * result, int * a, int sizeA, int * b, int sizeB);
Node * BSTFromArray(int * array, int left, int right, Node * parent);
void someFunction(Node * node);
Node * findMin(Node * current);
Node * findMax(Node * current);
void segmentedMergeWithAMin(Dictionary * a, Dictionary * b, Dictionary * c);
void segmentedMergeAddNext(Dictionary * a, Dictionary * b, Dictionary * c);

Dictionary * newDictionary(){
    Dictionary * dictionary = (Dictionary *) malloc(sizeof(dictionary));
    dictionary->root = NULL;
    dictionary->size = 0;
    return dictionary;
}

int search(Dictionary * dictionary, int value){
   Node * predecesssor = findPredecessor(dictionary->root,value);
   if(!predecesssor) return -1;
   splay(predecesssor);
   dictionary->root = predecesssor;
   return predecesssor->value;
}

void insert(Dictionary * dictionary, int value){
    Node * new = newNode(value);
    if(dictionary->root == NULL)
        dictionary->root = new;
    else{
        Node * current = dictionary->root;
        while(current != NULL){
            if(current->value == value) return;
            if(current->value < value){
                if(current->right == NULL){
                    current->right = new;
                    new->parent = current;
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
        splay(new);
        dictionary->root = new;
    }
}

void delete(Dictionary * dictionary, int value){
    fflush(stdout);
    Node * predecesssor = findPredecessor(dictionary->root,value);
    fflush(stdout);
    if(!predecesssor || predecesssor-> value != value) return;
    splay(predecesssor);
    fflush(stdout);
    Node * right = predecesssor->right;
    Node * left = predecesssor->left;
    free(predecesssor);
    if(left) left->parent = NULL;
    if(right) right->parent = NULL;
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
    if(!predecessor){
        *a = newDictionary();
        *b = newDictionary();
        (*b)->root = c->root;
        return;
    }
    splay(predecessor);
    c->root = predecessor;
    *a = newDictionary();
    *b = newDictionary();
    (*a)->root = predecessor;
    if(predecessor){
        (*b)->root = predecessor->right;
        if(predecessor->right){
            predecessor->right->parent = NULL;
        }
        predecessor->right = NULL;
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

Dictionary * segmentedMerge(Dictionary * a, Dictionary * b){
//Dictionary * merge(Dictionary * a, Dictionary * b){
    Dictionary * c = newDictionary();
    Node * minA = findMin(a->root);
    Node * minB = findMin(b->root);
    if(!minA){
        return b;
    }else if(!minB){
        return a;
    }
    if(minA->value < minB->value){
        segmentedMergeWithAMin(a,b,c);
    }else
    {
        segmentedMergeWithAMin(b,a,c);
    }
    return c;
}

void segmentedMergeWithAMin(Dictionary * a, Dictionary * b, Dictionary * c){
    Node * minB = findMin(b->root);
    Node * a_seg_max = findPredecessor(a->root,minB->value);
    splay(a_seg_max);
    c->root = a_seg_max;
    a->root = a_seg_max->right;
    if(a_seg_max->right)
        a_seg_max->right->parent = NULL;
    a_seg_max->right = NULL;
    int k = 0;

    while(a->root && b->root){
        segmentedMergeAddNext(b,a,c);
        if(b->root){
            segmentedMergeAddNext(a,b,c);
        }
    }
    if(a->root){
        segmentedMergeAddNext(a,b,c);
    }else if (b->root){
        segmentedMergeAddNext(b,a,c);
    }
}

void segmentedMergeAddNext(Dictionary * a, Dictionary * b, Dictionary * c){
    Node * minB = findMin(b->root);
    int minBValue = minB ? minB->value : INT32_MAX;
    //TODO: Replace code below with split
    Node * a_seg_max = findPredecessor(a->root,minBValue);
    splay(a_seg_max);
    c->root->right = a_seg_max;
    a_seg_max->parent = c->root;
    a->root = a_seg_max->right;
    if(a_seg_max->right)
        a_seg_max->right->parent = NULL;
    a_seg_max->right = NULL;
    splay(a_seg_max);
    c->root = a_seg_max;
}

void someFunction(Node * node){
    if(!node) printf("NULL\n");
    //else
        //printf("val: %d, current : %d, left : %d, right %d, parent %d\n", node->value, node, node->left, node->right, node->parent);
        //fflush(stdout);
}

void splay(Node * node){
    if(!node) return;
    int k = 0;
    while(node->parent){
        if(!node->parent->parent){
            if(node->parent->left == node) rightRotate(node);
            else leftRotate(node);
        }else if (node->parent->left == node && node->parent->parent->left == node->parent){
            rightRotate(node->parent);
            rightRotate(node);
        }else if (node->parent->right == node && node->parent->parent->right == node->parent){
            leftRotate(node->parent);
            leftRotate(node);
        }else if (node->parent->left == node && node->parent->parent->right == node->parent){
            rightRotate(node);
            leftRotate(node);
        }else{
            leftRotate(node);
            rightRotate(node);
        }
    }
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
    fflush(stdout);
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
    return countTraversal(node->left) + countTraversal(node->right) + 1;
}

void preOrderTraversal(Node * node){
    someFunction(node);
    if(node == NULL){
        printf("NULL");
        return;
    }
    
    printf("%d ", node->value);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

Node * findPredecessor(Node * current, int value){
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
    return (currentPredecessor);
}

Node * findMin(Node * current){
    Node * currentMin = current;
    while(currentMin && currentMin->left){
        currentMin = currentMin->left;
    }
    return currentMin;
}

Node * findMax(Node * current){
    Node * currentMax = current;
    while(currentMax && currentMax->right){
        currentMax = currentMax->right;
    }
    return currentMax;
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
    Node * node = newNode(array[index]);
    node->parent = parent;
    node->left = BSTFromArray(array,left,index-1,node);
    node->right = BSTFromArray(array,index+1,right,node);
    return node;
}

Dictionary * init_rand_test_from_array(int * list,int size){
    Dictionary * dict = newDictionary();
    for(int i = 0; i < size; i++) insert(dict,list[i]);
    return dict;
}






