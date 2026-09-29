#include "List.h"

tNode *removeNthFromEnd(tNode * head, int n) {
    tNode *slow = head;
    tNode *fast = head;
    while (n--)
        fast = fast->next;
    if (!fast)
        return head->next;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    tNode *movingNode = head;
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

    tNode *ret = createList(arr, 5);
    removeNthFromEnd(ret, 2);
    printList(ret);
}
