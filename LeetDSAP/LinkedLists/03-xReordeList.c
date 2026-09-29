#include "List.h"

void reorderlist(t_List *head) {
    if (!head || !head->next)
        return;
    t_List *slow = head;
    t_List *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    t_List *middle = slow->next;
    t_List *prev = NULL;
    t_List *next;
    while (middle) {
        next = middle->next;
        middle->next = prev;
        prev = middle;
        middle = next;
    }
    slow->next = NULL;
    t_List *nextNode;
    t_List *nextPrev;
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
    t_List *head = createList(arr, 5);
    reorderlist(head);
    printList(head);
}
