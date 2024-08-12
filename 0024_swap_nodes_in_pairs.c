/*
* 24. 两两交换链表中的节点
* 中等/相关标签/相关企业
* 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
* 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
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
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;                                         //创建了一个空节点作为虚拟头
    dummyHead->next = head;
    
    struct ListNode* current = head;
    struct ListNode* forward = head->next;
    struct ListNode* tmp = dummyHead;

    while (current != NULL && forward != NULL) {
        current->next = forward->next;                          //开始swap
        forward->next = current;
        tmp->next = forward;                                    //完成swap
        tmp = current;                                          //移动下一轮的头节点
        
        current = current->next;                                //更新节点
        forward = (current != NULL) ? current->next : NULL;     //更新节点的同时，考虑各种可能
    }
    head = dummyHead->next;                                     //更新头节点到虚拟头节点的下一个
    free(dummyHead);                                            //释放虚拟头节点的空间
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
    int array[] = {1,2,3,4};
    int len = sizeof(array) / sizeof(int);

    struct ListNode* head;
    head = createLinkedList(array, len);
    printLinkedList(head);

    head = swapPairs(head);
    printLinkedList(head);

    return 0;
}
