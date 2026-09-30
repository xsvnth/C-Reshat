#include "List.h"

tNode * addTwoNumbers(tNode* l1, tNode* l2) {
    tNode *movingL1 = l1;
    tNode *movingL2 = l2;
    tNode *retL;
    tNode *retHead = NULL;
    tNode *movingRet = NULL;
    int carry = 0;
    while (movingL1 || movingL2 || carry) {
        retL = malloc(sizeof(tNode));
        int val1 = 0, val2 = 0;
        if (movingL1)
            val1 = movingL1->val;
        if (movingL2)
            val2 = movingL2->val; 
        int sum = val1 + val2 + carry;
        retL->val = sum % 10;
        retL->next = NULL;
        carry = sum / 10;
        if (!retHead) {
            retHead = retL;
            movingRet = retL;
        }
        else {
            movingRet->next = retL;
            movingRet = retL; 
        }
        if (movingL1)
            movingL1 = movingL1->next;
        if (movingL2)
            movingL2 = movingL2->next;
    }
    return retHead;
}

int main(void)
{
    //int arr1[] = {9, 9, 9, 9, 9, 9, 9};
    //int arr2[] = {1};
    int arr1[] = {1, 2, 2, 6};
    int arr2[] = {0, 1, 1, 1};
    tNode *l1 = createList(arr1, 4);
    tNode *l2 = createList(arr2, 4);
    tNode *ret = addTwoNumbers(l1, l2);
    printList((tNode *)ret);
    freeList(l1);
    freeList(l2);
    freeList((tNode *)ret);
}
