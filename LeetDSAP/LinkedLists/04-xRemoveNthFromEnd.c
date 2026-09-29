#include "List.h"

t_List *removeNthFromEnd(t_List * head, int n) {
    t_List *slow = head;
    t_List *fast = head;
    while (n--)
        fast = fast->next;
    if (!fast)
        return head->next;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    t_List *movingNode = head;
    while (movingNode) {
        if (movingNode->next == slow) {
            movingNode->next = slow->next;
            break;
        }
        movingNode = movingNode->next;
    }
    return head;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};

    t_List *ret = createList(arr, 5);
    removeNthFromEnd(ret, 2);
    printList(ret);
}
