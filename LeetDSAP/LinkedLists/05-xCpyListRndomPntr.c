#include "List.h"

tNode *copyRandomList(t_randomNode *head) {
    t_randomNode *movingNode = head;
    t_randomNode *copy;
    t_randomNode *copyHead = NULL;
    t_randomNode *copyMoving = NULL;
    while (movingNode) {
        copy = malloc(sizeof(t_randomNode));
        copy->val = movingNode->val;
        copy->next = NULL;
        copy->random = NULL;
        if (!copyHead) {
            copyHead = copy;
            copyMoving = copy;
        }
        else {
            copyMoving->next = copy;
            copyMoving = copy;
        }
        movingNode = movingNode->next;
    }
}
