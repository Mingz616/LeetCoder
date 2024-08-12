/*
* 19. 删除链表的倒数第 N 个结点
* 中等/相关标签/相关企业
* 提示: 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = head;

    struct ListNode* fast = dummyHead;  //指向虚拟头节点，是为了保证可以删除真正的头节点
    struct ListNode* slow = dummyHead;

    while (n-- && fast != NULL) {
        fast = fast->next;          //为了让fast指针超前slow指针N个节点
    }
    fast = fast->next;              //为了保证不删除slow所在的节点，所以再次让fast指针下一一个节点

    while (fast != NULL) {      //当fast移到了尾部，slow的下一个节点就是要删除的节点
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;  //跳过slow的下一个节点并指向下下一个节点，即跳过下一个节点，也即是删除下一个节点
    head = dummyHead->next;         //更新头节点
    free(dummyHead);

    return head;
}

struct ListNode* createLinkedList(int *ptr, int len) {
    if (len == 0) {
        struct ListNode *head = NULL;  
        return head;
    }

    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = ptr[0];
    head->next = NULL;

    struct ListNode *node = head;
    for (int i = 1; i < len; i++) {
        struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = ptr[i];
        node->next = tmp;
        node = tmp;
    }
    node->next = NULL;

    return head;
}

void printLinkedList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d\t", head->val);
        head = head->next;
    }
    printf("\nDone\n");
}

int main() {
    int array[] = {1,2,3,4,5};
    int len = sizeof(array) / sizeof(int);

    struct ListNode* head;
    head = createLinkedList(array, len);
    printLinkedList(head);

    head = removeNthFromEnd(head, 2);
    printLinkedList(head);

    return 0;
}