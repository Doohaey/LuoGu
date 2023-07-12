#include <iostream>

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, m;
    std::cin >> n >> m;
    
    Node* head = new Node();
    head->data = 1;
    Node* prev = head;

    // 创建循环链表
    for(int i = 2; i <= n; i++) {
        Node* node = new Node();
        node->data = i;
        prev->next = node;
        prev = node;
    }
    prev->next = head;  // 使其成为一个循环链表

    Node* ptr = head;
    Node* pre_ptr = prev;  // 记录ptr前一个节点的指针，用于删除节点
    while(n--) {  // 当链表为空时退出
        for(int i = 1; i < m; i++) {  // 找到要删除的节点和其前一个节点
            pre_ptr = ptr;
            ptr = ptr->next;
        }
        pre_ptr->next = ptr->next;  // 删除节点
        std::cout << ptr->data << " ";  // 输出删除节点的编号
        delete ptr;  // 释放内存
        ptr = pre_ptr->next;  // 更新ptr
    }

    return 0;
}
