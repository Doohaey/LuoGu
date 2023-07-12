#include <iostream>

struct Node{
    int data;
    Node* next;
};

int main(){
    int n, m;
    std::cin >> n >> m;

    Node* head = new Node();
    head->data = 1;
    Node* pre = head;
    for (int i = 2; i <= n; i++){
        Node* node = new Node();
        node->data = i;
        pre->next = node;
        pre = node;
    }
    pre->next = head;

    Node* pointer = head;
    while(n--){
        for (int i = 1; i < m; i++){
            pre = pointer;
            pointer = pointer->next;
        }

        std::cout << pointer->data << ((n == 0) ? "\n" : " ");
        pre->next = pointer->next;
        delete pointer;
        pointer = pre ->next;
    }

    return 0;
}