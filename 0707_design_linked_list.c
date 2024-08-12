/*
* 707. 设计链表
* 中等/相关标签/相关企业
* 你可以选择使用单链表或者双链表，设计并实现自己的链表。
* 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
* 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

* 实现 MyLinkedList 类：
* MyLinkedList() 初始化 MyLinkedList 对象。
* int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
* void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
* void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
* void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
* void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList{
    int val;
    struct MyLinkedList *next;
} MyLinkedList;


// 创建链表头
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head = (MyLinkedList*)malloc(sizeof(MyLinkedList));   //开辟head的内存
    head->next = NULL;                                                  //并指向NULL
    return head;
}

// 根据index来读取链表节点值
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    while (i++ != index && obj != NULL) {   //移动链表节点到index的位置，过程中要保证节点不为NULL
        obj = obj->next;
    }
    if (obj !=NULL && obj->next != NULL) {  //确保此时节点，和其下一个节点均不为NULL
        return obj->next->val;                  //读取下一个节点的值，考虑了头节点
    }
    else {                                  //否则就返回-1
        return -1;
    }
}

//在链表的前部，增加新节点
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {        
    MyLinkedList *node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->val = val;            //新节点赋值
    node->next = obj->next;     //新节点指向头部的下一个节点，即插入
    obj->next = node;           //最后让头部，指向新节点，完成链接。
}

//在链表的尾部，增加新节点
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *tail = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    tail->val = val;            //新节点赋值
    tail->next = NULL;          //新节点指向NULL，因为是尾部
    while (obj->next != NULL) { //移动指针到尾部，只要其下一个节点为NULL，此时节点就是尾部了
        obj = obj->next;
    }
    obj->next = tail;           //让最后的节点指向新节点，即添加完成
}

//根据Index插入链表新节点
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->val = val;                        //新节点赋值，但不用设置指向
    int i = 0;
    while (i++ != index && obj != NULL) {   //移动节点到index位置，需要考虑此时节点不为NULL
        obj = obj->next;                        //移动头节点到下一个
    }
    
    if (obj != NULL) {                      //需要考虑index是否超出了链表的实际长度
        node->next = obj->next;                 //新节点，指向此时的头节点的下一个
        obj->next = node;                       //此时的头节点，指向新节点，完成插入
    }    
}

//根据index删除链表中的节点
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    //考虑index为0的情况
    if (index == 0) {
        MyLinkedList *dummy = obj->next;    //新节点，就是头节点的下一个节点
        if (dummy != NULL) {                //只要这个新节点不为NULL
            obj->next = dummy->next;            //头部就指向新节点的下一个，即跳过新节点
            free(dummy);                        //最后释放新节点的空间
        }
        return;                             //如果是这种情况，就结束了。
    }

    //考虑index不为0的情况
    int i = 0;
    while (i++ != index && obj != NULL) {   //如果节点不为空，指针就移动到下一个节点，否则就到尾部
        obj = obj->next;        
    }

    //当移动到Index的位置时，需要判断此时index就是尾部
    MyLinkedList *dummy;
    if (obj != NULL && obj->next != NULL) { //考虑此时的节点和其下一个节点不为NULL
        dummy = obj->next;                      //新节点就指向此时头节点的下一个节点
        obj->next = dummy->next;                //此时的头节点，指向新节点的下一个，即跳过
        free(dummy);                            //最后释放新节点的空间
    }
}

//释放链表空间
void myLinkedListFree(MyLinkedList* obj) {
    while (obj != NULL) {               //只要节点不为NULL，就移动链表指针到下一个节点
        MyLinkedList *dummy = obj;          //首先，新节点指向此时的头节点
        obj = obj->next;                    //移动头节点指针到下一个节点
        free(dummy);                        //释放新节点的空间，即上一个节点的空间
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

//打印链表内的所有节点
void printLinkedList(struct MyLinkedList *head) {
    while (head->next != NULL) {            //考虑节点的下一个不为NULL，也就是判断是不是尾部节点
        printf("%d\t", head->next->val);        //打印下一个节点的值
        head = head->next;                      //移动头节点到下一个节点
    }
    printf("Done\n");
}

//测试用例1
void testCase1() {
    MyLinkedList *head;                 //创建头节点
    int ans;                            //创建ans变量来保存返回值
    //创建新的空链表
    head = myLinkedListCreate();
    //在链表的前部增加节点，值为1
    myLinkedListAddAtHead(head, 1);
    printLinkedList(head);
    //在链表的尾部增加节点，值为3
    myLinkedListAddAtTail(head, 3);
    printLinkedList(head);
    //在链表Index=1的位置，增加节点，值为2
    myLinkedListAddAtIndex(head, 1, 2);
    printLinkedList(head);
    //返回链表index=1的节点的值
    ans = myLinkedListGet(head, 1);
    printf("%d\r\n", ans);
    //删除链表index=1的节点
    myLinkedListDeleteAtIndex(head, 1);
    printLinkedList(head);
    //返回链表index=1的节点的值
    ans = myLinkedListGet(head, 1);
    printf("%d\r\n", ans);
    //打印最终的链表内容
    printLinkedList(head);
    //释放链表的内存空间
    myLinkedListFree(head);
}
//测试用例2
void testCase2() {
    MyLinkedList *head;
    int ans;

    head = myLinkedListCreate();
    // printLinkedList(head);

    myLinkedListAddAtHead(head, 4);
    printLinkedList(head);

    ans = myLinkedListGet(head, 1);
    printf("%d\r\n", ans);

    myLinkedListAddAtHead(head, 1);
    printLinkedList(head);

    myLinkedListAddAtHead(head, 5);
    printLinkedList(head);

    myLinkedListDeleteAtIndex(head, 3);
    printLinkedList(head);

    myLinkedListAddAtHead(head, 7);
    printLinkedList(head);

    ans = myLinkedListGet(head, 3);
    printf("%d\r\n", ans);
    ans = myLinkedListGet(head, 3);
    printf("%d\r\n", ans);
    ans = myLinkedListGet(head, 3);
    printf("%d\r\n", ans);

    myLinkedListAddAtHead(head, 1);
    printLinkedList(head);

    myLinkedListDeleteAtIndex(head, 4);
    printLinkedList(head);

    myLinkedListFree(head);
}
//测试用例3
void testCase3() {
    MyLinkedList *head;
    int ans;

    head = myLinkedListCreate();

    myLinkedListAddAtHead(head, 1);
    printLinkedList(head);

    myLinkedListAddAtTail(head, 3);
    printLinkedList(head);

    myLinkedListAddAtIndex(head, 1, 2);
    printLinkedList(head);

    ans = myLinkedListGet(head, 1);
    printf("%d\r\n", ans);

    myLinkedListDeleteAtIndex(head, 1);
    printLinkedList(head);

    ans = myLinkedListGet(head, 1);
    printf("%d\r\n", ans);

    ans = myLinkedListGet(head, 3);
    printf("%d\r\n", ans);

    ans = myLinkedListGet(head, 3);
    printf("%d\r\n", ans);

    myLinkedListDeleteAtIndex(head, 3);
    printLinkedList(head);

    myLinkedListDeleteAtIndex(head, 0);
    printLinkedList(head);

    ans = myLinkedListGet(head, 0);
    printf("%d\r\n", ans);

    myLinkedListDeleteAtIndex(head, 0);
    printLinkedList(head);

    ans = myLinkedListGet(head, 0);
    printf("%d\r\n", ans);

    myLinkedListFree(head);
}
//测试用例4
void testCase4() {
    MyLinkedList *head;
    int ans;
    head = myLinkedListCreate();

    myLinkedListAddAtHead(head, 1);
    printLinkedList(head);

    myLinkedListAddAtTail(head, 3);
    printLinkedList(head);

    myLinkedListAddAtIndex(head, 3, 2);
    printLinkedList(head);

    myLinkedListFree(head);
}

int main() {
    // testCase1();
    // testCase2();
    // testCase3();
    testCase4();

    return 0;
}