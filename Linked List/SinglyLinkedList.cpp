#include <bits/stdc++.h>
using namespace std;

// SLL.cpp

struct Node{
    int data;
    Node* nextNode;
};

struct ListNode{
    Node* pHead;
    Node* pTail;
};

ListNode L;

Node* getNode(int value){
    Node* p = new Node();
    p -> data = value;
    p -> nextNode = nullptr;
    return p;
}

void addHead(ListNode &L, Node* p){
    if (L.pHead == nullptr){
        L.pHead = L.pTail = p;
        return;
    }

    p -> nextNode = L.pHead;
    L.pHead = p;
}

void addTail(ListNode &L, Node* p){
    if (L.pHead == nullptr){
        L.pHead = L.pTail = p;
        return;
    }

    L.pTail -> nextNode = p;
    L.pTail = p;
}

void insertAfter(ListNode &L, Node* p, Node* q){
    if (p == nullptr){ // List is empty
        addHead(L, q); // or addTail(L, q);
        return;
    }

    if (p == L.pTail){
        addTail(L, q);
        return;
    }

    q -> nextNode = p -> nextNode;
    p -> nextNode = q;
}

void deleteNodeAfter(ListNode &L, Node *p){
    Node* q = p -> nextNode;
    p -> nextNode = q -> nextNode;
    delete q;
}

void deleteHead(ListNode &L){
    if (L.pHead == nullptr) {
        return;
    }
    Node* cur = L.pHead;
    L.pHead = L.pHead -> nextNode;
    delete cur;
}

void deleteTail(ListNode &L){
    if (L.pTail == nullptr){
        return;
    }

    Node* tmp = L.pHead;

    while (tmp -> nextNode -> nextNode != nullptr){
        tmp = tmp -> nextNode;
    }

    Node* cur = tmp -> nextNode;
    tmp -> nextNode = nullptr;
    delete cur;
}

void printfLinkedList(ListNode L){
    while (L.pHead != nullptr){
        cout << L.pHead -> data << ' ';
        L.pHead = L.pHead -> nextNode;
    }
    cout << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("TRAINING.INP","r",stdin);
        // freopen("TRAINING.OUT","w",stdout);
    #endif
    int n; cin >> n; 
    for (int i = 0; i < n; ++i){
        int value; cin >> value;
        Node* newNode = getNode(value);
        // addHead(L, newNode);
        addTail(L, newNode);
    }

    printfLinkedList(L);
    /*
        N = 5
        {1, 2, 3, 4, 5}
        addHead = 5 -> 4 -> 3 -> 2 -> 1 -> nullptr;
        addTail = 1 -> 2 -> 3 -> 4 -> 5 -> nullptr;
    */

    int val; cin >> val;
    Node* q = getNode(val);
    insertAfter(L, L.pHead -> nextNode -> nextNode, q);
    printfLinkedList(L);    
    /*
        For example : val = 8
        We need add val after node 3 in 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
        => newListNode 1 -> 2 -> 3 -> 8 -> 4 -> 5
    */

    deleteNodeAfter(L, L.pHead -> nextNode -> nextNode);
    printfLinkedList(L);
    /*
        We have listNode: 1 -> 2 -> 3 -> 8 -> 4 -> 5 -> nullptr
        We need delete node 3th in List, so we have newListNode:
        1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    */
    deleteHead(L);
    printfLinkedList(L);
    /*
        We have listNode: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
        => delete pHead => 2 -> 3 -> 4 -> 5 -> nullptr
    */
    deleteTail(L);
    printfLinkedList(L);
    /*
        We have listNode 2 -> 3 -> 4 -> 5 -> nullptr
        => delete pTail => 2 -> 3 -> 4 -> nullptr
    */
    return 0;
}
