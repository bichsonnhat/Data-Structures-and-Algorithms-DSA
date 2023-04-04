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
	p -> nextNode = NULL;
	return p;
}

void addHead(ListNode &L, Node* p){
	if (L.pHead == NULL){
		L.pHead = L.pTail = p;
		return;
	}

	p -> nextNode = L.pHead;
	L.pHead = p;
}

void addTail(ListNode &L, Node* p){
	if (L.pHead == NULL){
		L.pHead = L.pTail = p;
		return;
	}

	L.pTail -> nextNode = p;
	L.pTail = p;
}

void insertAfter(ListNode &L, Node* p, Node* q){
	if (p == NULL){ // List is empty
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

void printfLinkedList(ListNode L){
    while (L.pHead != NULL){
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
		addHead = 5 -> 4 -> 3 -> 2 -> 1 -> NULL;
		addTail = 1 -> 2 -> 3 -> 4 -> 5 -> NULL;
    */

    int val; cin >> val;
    Node* q = getNode(val);
    insertAfter(L, L.pHead -> nextNode -> nextNode, q);
    printfLinkedList(L);    
   	/*
		For example : val = 8
		We need add val after node 3 in 1 -> 2 -> 3 -> 4 -> 5 -> NULL
		=> newListNode 1 -> 2 -> 3 -> 8 -> 4 -> 5
   	*/

    deleteNodeAfter(L, L.pHead -> nextNode -> nextNode);
    printfLinkedList(L);
    /*
		We have listNode: 1 -> 2 -> 3 -> 8 -> 4 -> 5 -> NULL
		We need delete node 3th in List, so we have newListNode:
		1 -> 2 -> 3 -> 4 -> 5 -> NULL
    */
    return 0;
}
