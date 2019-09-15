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
    Node * new = newNode(value);
    if(dictionary->root == NULL)
        dictionary->root = new;
    else{
        Node * current = dictionary->root;
        while(current != NULL && current->value != value){
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
    }
}

void inOrderTraversal(Node * node){
    if(node == NULL) return;
    inOrderTraversal(node->left);
    printf("%d ", node->value);
    inOrderTraversal(node->right);
}

void preOrderTraversal(Node * node){
    if(node == NULL) return;
    /*
    if(node == NULL){
        printf("NULL ");
        return;
    }
    */
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

