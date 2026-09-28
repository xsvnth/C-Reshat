#include <stdlib.h>
#include <stdio.h>
typedef struct s_List {
    int val;
    struct s_List *next;
} t_List;

t_List *createNode(int val) {
    t_List *node = malloc(sizeof(t_List));
    node->val = val;
    node->next = NULL;
    return node;
}

t_List *createList(int *arr, int size) {
    if (size <= 0)
        return NULL;
    t_List *list = createNode(arr[0]);
    t_List *ptr = list;
    for (int i = 1; i < size; i++) {
        ptr->next = createNode(arr[i]);
        ptr = ptr->next;
    }
    return list;
}

void    printList(t_List *head) {
    t_List *ptr = head;
    while (ptr){
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void    freeList(t_List *head) {
    t_List *next;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
}
