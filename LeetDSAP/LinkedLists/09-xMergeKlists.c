#include "List.h"

typedef struct s_Q {
    tNode **node;
    int size;
    int capacity;
} t_Q;

void bubbleDown(t_Q *Queue, int pos) {
    while (1) {
        int smallest = pos;
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;

        if (left < Queue->size
            && Queue->node[left]->val < Queue->node[smallest]->val)
            smallest = left;
        if (right < Queue->size
            && Queue->node[right]->val < Queue->node[smallest]->val)
            smallest = right;
        if (smallest == pos)
            break;
        tNode *tmp = Queue->node[pos];
        Queue->node[pos] = Queue->node[smallest];
        Queue->node[smallest] = tmp;
        pos = smallest;
    }
}

tNode *mergeKsrtdLists(tNode **lists, int listsSize) {
    if (listsSize == 0)
        return NULL;
    t_Q *Queue = malloc(sizeof(t_Q));
    Queue->node = malloc(sizeof(tNode *) * listsSize);
    Queue->size = 0;
    Queue->capacity = listsSize;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            Queue->node[Queue->size] = lists[i];
            Queue->size++;
        }
    }
    for (int i = Queue->size / 2 - 1; i >= 0; i--)
        bubbleDown(Queue, i);
    tNode *mergedHead = NULL;
    tNode *tail = NULL;
    while (Queue->size) {
        tNode *smallest = Queue->node[0];
        tNode *next = smallest->next;
        if (!mergedHead) {
            mergedHead = smallest;
            tail = smallest;
        }
        else {
            tail->next = smallest;
            tail = smallest;
        }
        if (next) 
            Queue->node[0] = next;
        else { 
            Queue->node[0] = Queue->node[Queue->size - 1];
            Queue->size--;
        }
        if (Queue->size)
            bubbleDown(Queue, 0);
    }
    free(Queue->node);
    free(Queue);
    return mergedHead;
}

int main() {
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};
    tNode *list1 = createList(arr1, 3);
    tNode *list2 = createList(arr2, 3);
    tNode *list3 = createList(arr3, 2);
    tNode *lists[] = {
        list1,
        list2,
        list3,
        NULL
    };
    tNode *merged = mergeKsrtdLists(lists, 4);
    printf("Merged: ");
    printList(merged);
    freeList(merged);
    return 0;
}
