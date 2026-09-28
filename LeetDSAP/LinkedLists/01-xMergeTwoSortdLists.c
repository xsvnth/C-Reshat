#include "List.h"

t_List* mergeLists(t_List *list1, t_List *list2) {
    t_List *movingNode;
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (list1->val < list2->val) {
        movingNode = list1;
        list1 = list1->next;
    }
    else {
        movingNode = list2;
        list2 = list2->next;
    }
    t_List *tail = movingNode;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return movingNode;
}
int main() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    t_List *list1 = createList(arr1, 3);
    t_List *list2 = createList(arr2, 3);
    t_List *merged = mergeLists(list1, list2);
    printList(merged);
    freeList(merged);
}
