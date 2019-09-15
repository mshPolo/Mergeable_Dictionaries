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

Node * newNode(int value);
void rightRotate(Node * node);
void leftRotate(Node * node);
void splay(Node * node);

Dictionary * newDictionary(){
    Dictionary * dictionary = (Dictionary *) malloc(sizeof(dictionary));
    dictionary->root = NULL;
    dictionary->size = 0;
    return dictionary;
}

int search(Dictionary * dictionary, int value){
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
}

void insert(Dictionary * dictionary, int value){
    int k = 0;
    Node * new = newNode(value);
    if(dictionary->root == NULL)
        dictionary->root = new;
    else{
        Node * current = dictionary->root;
        while(current != NULL && k++ < 10){
            printf("current : %d, left : %d, right %d, parent %d\n", current->value, current->left, current->right, current->parent); fflush(stdout);
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
        splay(new);
        //if(current->value == value) return;
        dictionary->root = new;
    }
}

void someFunction(Node * node){
    if(!node) printf("NULL\n");
    else
        printf("val: %d, current : %d, left : %d, right %d, parent %d\n", node->value, node, node->left, node->right, node->parent);
        fflush(stdout);
}

//THIS LOOKS A LOT LIKE THE SPLAY FUNCTION ON WIKIPEDIA IN CASE YOU NEED TO HAND THIS IN
void splay(Node * node){
    int k = 0;
    printf("\n");
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

void preOrderTraversal(Node * node){
    //if(node == NULL) return;
    if(node == NULL){
        printf("NULL ");
        return;
    }
    printf("%d ", node->value);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

Node * newNode(int value){
    Node * node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

