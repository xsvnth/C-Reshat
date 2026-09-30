#include "List.h"

typedef struct s_pair {
    t_randomNode *original;
    t_randomNode *copy;
    struct s_pair *next;
} t_pair;

t_randomNode *copyRandomList(t_randomNode *head) {
    t_randomNode *movingNode = head;
    t_randomNode *copy;
    t_randomNode *copyHead = NULL;
    t_randomNode *copyMoving = NULL;
    t_pair *savingPair;
    t_pair *pairHead = NULL;
    t_pair *pairMoving = NULL;
    while (movingNode) {
        copy = malloc(sizeof(t_randomNode));
        savingPair = malloc(sizeof(t_pair));
        savingPair->next = NULL;
        copy->val = movingNode->val;
        copy->next = NULL;
        copy->random = NULL;
        savingPair->copy = copy;
        savingPair->original = movingNode;
        savingPair->next = NULL;
        if (!copyHead) {
            copyHead = copy;
            copyMoving = copy;
        }
        else {
            copyMoving->next = copy;
            copyMoving = copy;
        }
        if (!pairHead) {
            pairHead = savingPair;
            pairMoving = savingPair;
        }
        else {
            pairMoving->next = savingPair;
            pairMoving = savingPair;
        }
        movingNode = movingNode->next;
    }
    movingNode = head;
    copy = copyHead;
    while (movingNode) {
        t_pair *pairCheck = pairHead;
        while (pairCheck) {
            if (movingNode->random == pairCheck->original){
                copy->random = pairCheck->copy;
                break;
            }
            pairCheck = pairCheck->next;
        }
        movingNode = movingNode->next;
        copy = copy->next;
    }
    return copyHead;
}
t_randomNode *createRandomNode(int val) { 
    t_randomNode *node = malloc(sizeof(t_randomNode));
    node->val = val;
    node->next = NULL;
    node->random = NULL;
    return node;
} 
int main(void) { 
    t_randomNode *a = createRandomNode(1);
    t_randomNode *b = createRandomNode(2);
    t_randomNode *c = createRandomNode(3);
    a->next = b; b->next = c; 
    a->random = c; b->random = a; c->random = b; 
    t_randomNode *copy = copyRandomList(a);
    printf("Original:\n");
    printf("1 -> random: %d\n", a->random->val);
    printf("2 -> random: %d\n", b->random->val);
    printf("3 -> random: %d\n", c->random->val);
    printf("\nCopy:\n");
    printf("1 -> random: %d\n", copy->random->val);
    printf("2 -> random: %d\n", copy->next->random->val);
    printf("3 -> random: %d\n", copy->next->next->random->val);
    return 0; 
}
