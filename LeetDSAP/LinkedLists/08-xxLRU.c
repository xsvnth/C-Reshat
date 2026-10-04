#include <stdlib.h>

typedef struct tNode {
    int key;
    int val;
    struct tNode *next;
    struct tNode *prev;
} tNode;

typedef struct LRUCache {
    int capacity;
    int size;
    tNode *head;
    tNode *tail;
    tNode **map;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = NULL;
    obj->tail = NULL;
    obj->map = calloc(capacity * 10000, sizeof(tNode *));
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    tNode *movingNode = obj->map[key];
    if (!movingNode)
        return -1;
    if (movingNode != obj->tail) {
        if (movingNode->prev)
            movingNode->prev->next = movingNode->next;
        else
            obj->head = movingNode->next;

        movingNode->next->prev = movingNode->prev;
        movingNode->prev = obj->tail;
        movingNode->next = NULL;
        obj->tail->next = movingNode;
        obj->tail = movingNode;
    }
    return movingNode->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    tNode *movingNode = obj->map[key];
    if (movingNode) {
        movingNode->val = value;
        if (movingNode != obj->tail) {
            if (movingNode->prev)
                movingNode->prev->next = movingNode->next;
            else
                obj->head = movingNode->next;
            movingNode->next->prev = movingNode->prev;
            movingNode->prev = obj->tail;
            movingNode->next = NULL;
            obj->tail->next = movingNode;
            obj->tail = movingNode;
        }
        return;
    }
    if (obj->size == obj->capacity) {
        tNode *oldHead = obj->head;
        obj->head = oldHead->next;
        if (obj->head)
            obj->head->prev = NULL;
        else
            obj->tail = NULL;
        obj->map[oldHead->key] = NULL;
        free(oldHead);
        obj->size--;
    }
    tNode *newNode = malloc(sizeof(tNode));
    newNode->key = key;
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = obj->tail;
    if (obj->tail)
        obj->tail->next = newNode;
    else
        obj->head = newNode;
    obj->tail = newNode;
    obj->map[key] = newNode;
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    tNode *movingNode = obj->head;
    while (movingNode) {
        tNode *next = movingNode->next;
        free(movingNode);
        movingNode = next;
    }
    free(obj->map);
    free(obj);
}
#include <stdio.h>

int main() {
    LRUCache *cache = lRUCacheCreate(2);
    printf("=== Basic ===\n");
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    printf("get(1) = %d\n", lRUCacheGet(cache, 1));
    printf("=== Eviction ===\n");
    lRUCachePut(cache, 3, 3);
    printf("get(2) = %d\n", lRUCacheGet(cache, 2));
    printf("get(3) = %d\n", lRUCacheGet(cache, 3));
    printf("get(1) = %d\n", lRUCacheGet(cache, 1));
    printf("=== Update ===\n");
    lRUCachePut(cache, 3, 30);
    printf("get(3) = %d\n", lRUCacheGet(cache, 3));
    lRUCacheFree(cache);
    printf("\n=== Capacity 1 ===\n");
    LRUCache *small = lRUCacheCreate(1);
    lRUCachePut(small, 1, 10);
    printf("get(1) = %d\n", lRUCacheGet(small, 1));
    lRUCachePut(small, 2, 20);
    printf("get(1) = %d\n", lRUCacheGet(small, 1));
    printf("get(2) = %d\n", lRUCacheGet(small, 2));
    lRUCacheFree(small);
}

