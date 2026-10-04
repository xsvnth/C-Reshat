#include "List.h"

tNode *revList(tNode *head, int k) {
    tNode *prev = NULL;
    tNode *next;
    while (head && k--) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

tNode *reverseKGroup(tNode *head, int k) {
    tNode *movingNode = head;
    tNode *prevTail = NULL;
    while (movingNode) {
        tNode *nextGroup = movingNode;
        int count = 0;
        while (nextGroup && count < k) {
            nextGroup = nextGroup->next;
            count++;
        }
        if (count < k)
            break;
        tNode *newHead = revList(movingNode, k);
        movingNode->next = nextGroup;
        if (prevTail)
            prevTail->next = newHead;
        else
            head = newHead;
        prevTail = movingNode;
        movingNode = nextGroup;
    }
    return head;
}

int main(void) {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8};
    tNode *list1 = createList(arr1, 5);
    tNode *list2 = createList(arr2, 6);
    tNode *list3 = createList(arr3, 8);
    printf("k = 2: ");
    list1 = reverseKGroup(list1, 2);
    printList(list1);
    printf("k = 3: ");
    list2 = reverseKGroup(list2, 3);
    printList(list2);
    printf("k = 4: ");
    list3 = reverseKGroup(list3, 4);
    printList(list3);
    freeList(list1);
    freeList(list2);
    freeList(list3);
    return 0;
}
