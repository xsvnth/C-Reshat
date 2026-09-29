#include <stdlib.h>
#include <stdio.h>
typedef struct sNode {
    int val;
    struct sNode *next;
} tNode;

typedef struct s_randomNode {
    int val;
    struct s_randomNode *next;
    struct s_randomNode *random;
} t_randomNode;

tNode *createNode(int val) {
    tNode *node = malloc(sizeof(tNode));
    node->val = val;
    node->next = NULL;
    return node;
}

tNode *createList(int *arr, int size) {
    if (size <= 0)
        return NULL;
    tNode *list = createNode(arr[0]);
    tNode *ptr = list;
    for (int i = 1; i < size; i++) {
        ptr->next = createNode(arr[i]);
        ptr = ptr->next;
    }
    return list;
}

void    printList(tNode *head) {
    tNode *ptr = head;
    while (ptr){
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void    freeList(tNode *head) {
    tNode *next;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
}
