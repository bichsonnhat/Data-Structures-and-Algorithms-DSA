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
    if (p == nullptr || p == L.pTail){
        addTail(L, q);
        return;
    }

    q -> nextNode = p -> nextNode;
    q -> prevNode = p;
    p -> nextNode = q;
}

void insertBefore(ListNode &L, Node* p, Node* q){
    if (p == nullptr || p == L.pHead){
        addHead(L, q);
        return;
    }

    q -> nextNode = p;
    q -> prevNode = p -> prevNode;
    p -> prevNode -> nextNode = q;
    p -> prevNode = q;
}

void deleteHead(ListNode &L){
    if (L.pHead == nullptr){
        return;
    }
    Node* cur = L.pHead;
    L.pHead = L.pHead -> nextNode;
    L.pHead -> prevNode = nullptr;
    delete cur;
    if (L.pHead == nullptr){
        L.pTail = nullptr;
    }
}

void deleteTail(ListNode &L){
    if (L.pTail == nullptr){
        return;
    }
    Node* cur = L.pTail;
    L.pTail = L.pTail -> prevNode;
    L.pTail -> nextNode = nullptr;
    delete cur;
    if (L.pTail == nullptr){
        L.pHead = nullptr;
    }
}

void deleteAfter(ListNode &L, Node* p){
    if (p == nullptr || p == L.pTail){
        return;
    }

    Node* cur = p -> nextNode;
    p -> nextNode = cur -> nextNode;
    if (p -> nextNode == nullptr){
        L.pTail = p;
    }
    delete cur;
}

void deleteBefore(ListNode &L, Node* p){
    if (p == nullptr || p == L.pHead){
        return;
    }

    Node* cur = p -> prevNode;
    p -> prevNode = cur -> prevNode;
    if (p -> prevNode == nullptr){
        L.pHead = p;
    }
    delete cur;
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
    // insertAfter(L, L.pHead -> nextNode -> nextNode, getNode(6));
    // insertBefore(L, L.pHead -> nextNode -> nextNode, getNode(6));
    // deleteHead(L);
    // deleteTail(L);
    // deleteBefore(L, L.pHead -> nextNode);
    printDoubleLinkedList(L);
    return 0;
}
