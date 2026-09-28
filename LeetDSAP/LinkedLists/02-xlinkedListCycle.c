#include "List.h"
#include <linux/limits.h>
int hasCycle(t_List *head) {
    t_List *slow = head;
    t_List *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    t_List *list = createList(arr, 5);
    list->next->next->next->next->next = list;
    printf("Cycle : %d\n", hasCycle(list));
}
