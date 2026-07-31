#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode_t;

ListNode_t* rotateRight(ListNode_t* head, int k) {
    if (head == NULL) return NULL;
    if (k == 0) return head;
    int size = 1;
    ListNode_t* curr = head;
    ListNode_t* tail;
    while (curr->next != NULL) {
        size++;
        curr = curr->next;
    }
    tail = curr;
    k %= size;
    if (k == 0) return head;
    int i;
    curr = head;
    for (i = 0; i < size - k - 1; i++) {
        curr = curr->next;
    }
    tail->next = head;
    head = curr->next;
    curr->next = NULL;
    return head;
}

void print_ls(ListNode_t* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    ListNode_t n5 = {5, NULL};
    ListNode_t n4 = {4, &n5};
    ListNode_t n3 = {3, &n4};
    ListNode_t n2 = {2, &n3};
    ListNode_t n1 = {1, &n2};
    print_ls(rotateRight(&n1, 203));
    return 0;
}