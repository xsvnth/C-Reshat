#include "List.h"

void reorderlist(tNode *head) {
    if (!head || !head->next)
        return;
    tNode *slow = head;
    tNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    tNode *middle = slow->next;
    tNode *prev = NULL;
    tNode *next;
    while (middle) {
        next = middle->next;
        middle->next = prev;
        prev = middle;
        middle = next;
    }
    slow->next = NULL;
    tNode *nextNode;
    tNode *nextPrev;
    while (head && prev) {
        nextNode = head->next;
        nextPrev = prev->next;
        head->next = prev;
        prev->next = nextNode;
        head = nextNode;
        prev = nextPrev;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    tNode *head = createList(arr, 5);
    reorderlist(head);
    printList(head);
}
