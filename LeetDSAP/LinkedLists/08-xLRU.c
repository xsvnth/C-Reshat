#include <stdlib.h>

typedef struct sNode {
    int key;
    int val;
    struct sNode *next;
    struct sNode *prev;
} tNode;

typedef struct s_lru {
    int capacity;
    int size;
    tNode *head;
    tNode *tail;
} t_lru;

t_lru *lRUcreate(int capacity){
    t_lru *obj = malloc(sizeof(t_lru));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = NULL;
    obj->tail = NULL;
    return obj;
}

void moveToTail(t_lru *obj, tNode *node) {
    if (node == obj->tail)
        return;
    if (node->prev)
        node->prev->next = node->next;
    else
        obj->head = node->next;
    node->next->prev = node->prev;
    node->prev = obj->tail;
    node->next = NULL;
    obj->tail->next = node;
    obj->tail = node;
}

int lRUget(t_lru *obj, int key){
    tNode *movingNode = obj->head;
    while (movingNode) {
        if (movingNode->key == key) {
            moveToTail(obj, movingNode);
            return movingNode->val;
        }
        movingNode = movingNode->next;
    }
    return -1;
}

void lruput(t_lru *obj, int key, int val) {
    tNode *movingNode = obj->head;
    while (movingNode) {
        if (movingNode->key == key) {
            movingNode->val = val;
            moveToTail(obj, movingNode);
            return;
        }
        movingNode = movingNode->next;
    }
    if (obj->size == obj->capacity) {
        tNode *oldHead = obj->head;
        obj->head = obj->head->next;
        free(oldHead);
        obj->size--;
        if (obj->head)
            obj->head->prev = NULL;
        else
            obj->tail = NULL;
    }
    tNode *newNode = malloc(sizeof(tNode));
    newNode->key = key;
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = obj->tail;
    if (obj->tail)
        obj->tail->next = newNode;
    else
        obj->head = newNode;
    obj->tail = newNode;
    obj->size++;
}

void lRUfree(t_lru *obj) {
    tNode *movingNode = obj->head;
    while (movingNode) {
        tNode *next = movingNode->next;
        free(movingNode);
        movingNode = next;
    }
    free(obj);
}
#include <stdio.h>
int main() {
    t_lru *cache = lRUcreate(2);
    printf("=== Basic ===\n");
    lruput(cache, 1, 1);
    lruput(cache, 2, 2);
    printf("get(1) = %d\n", lRUget(cache, 1));
    printf("=== Eviction ===\n");
    lruput(cache, 3, 3);
    printf("get(2) = %d\n", lRUget(cache, 2));
    printf("get(3) = %d\n", lRUget(cache, 3));
    printf("get(1) = %d\n", lRUget(cache, 1));
    printf("=== Update ===\n");
    lruput(cache, 3, 30);
    printf("get(3) = %d\n", lRUget(cache, 3));
    lRUfree(cache);
    printf("\n=== Capacity 1 ===\n");
    t_lru *small = lRUcreate(1);
    lruput(small, 1, 10);
    printf("get(1) = %d\n", lRUget(small, 1));
    lruput(small, 2, 20);
    printf("get(1) = %d\n", lRUget(small, 1));
    printf("get(2) = %d\n", lRUget(small, 2));
    lRUfree(small);
}
