#include <stdlib.h>
typedef struct sNode {
    int val;
    struct sNode *next;
} tNode;

tNode *revList(tNode *head) {
    tNode *prev = NULL;
    tNode *next;
    while (head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
#include <stdio.h>
int main() { 
    tNode *head, *node1, *node2, *node3;
    node1 = malloc(sizeof(tNode)); 
    node2 = malloc(sizeof(tNode)); 
    node3 = malloc(sizeof(tNode)); 
    node1->val = 1; 
    node2->val = 2; 
    node3->val = 3; 
    node1->next = node2; 
    node2->next = node3;
    node3->next = NULL;
    head = node1;
    printf("Before: ");
    tNode *tmp = head;
    while (tmp) { 
        printf("%d ", tmp->val);
        tmp = tmp->next;
    } 
    head = revList(head);
    printf("\nAfter: ");
    tmp = head; 
    while (tmp) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    } 
    printf("\n");
    free(node1); 
    free(node2);
    free(node3); 
}
