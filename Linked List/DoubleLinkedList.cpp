#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* nextNode;
    Node* prevNode;
};

struct ListNode{
    Node* pHead;
    Node* pTail;
};

ListNode L;

void preCompute(ListNode &L){
    L.pHead = L.pTail = nullptr;
}

Node* getNode(int value){
    Node* p = new Node();
    p -> data = value;
    p -> prevNode = nullptr;
    p -> nextNode = nullptr;
    return p;
}

void addHead(ListNode &L, Node* p){
    if (L.pHead == nullptr){
        L.pHead = L.pTail = p;
        return;
    }

    p -> nextNode = L.pHead;
    L.pHead -> prevNode = p;
    L.pHead = p; 
}

void addTail(ListNode &L, Node* p){
    if (L.pHead == nullptr){
        L.pHead = L.pTail = p;
        return;
    }

    p -> prevNode = L.pTail;
    L.pTail -> nextNode = p;
    L.pTail = p;
}

void printDoubleLinkedList(ListNode L){
    Node* cur = L.pHead;
    while (cur != nullptr){
        cout << cur -> data << ' ';
        cur = cur -> nextNode;
    }
    cout << endl;
    return;
}

void insertAfter(ListNode &L, Node* p, Node* q){
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("TRAINING.INP","r",stdin);
        // freopen("TRAINING.OUT","w",stdout);
    #endif
    preCompute(L);
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int value; cin >> value;
        addTail(L, getNode(value));
    }
    printDoubleLinkedList(L);
    return 0;
}