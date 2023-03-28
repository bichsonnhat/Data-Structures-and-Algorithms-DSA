#include <bits/stdc++.h>
using namespace std;

const int N = 100;
struct ListNode{
	int data;
	ListNode* nextNode;
};

ListNode* pHead;
int n;
int a[N];

void SelectionSort(ListNode* pHead){
    ListNode* i;
    ListNode* j;
    for (i = pHead; i != NULL; i = i -> nextNode){
    	int minn = i -> data;
    	for (j = i -> nextNode; j != NULL; j = j -> nextNode){
    		if (j -> data < minn){
    			minn = j -> data;
    		}
    	}
    	if (i -> data != minn){
    		for (j = i -> nextNode; j != NULL; j = j -> nextNode){
    			if (j -> data == minn){
    				int cur = i -> data;
	    			i -> data = j -> data;
	    			j -> data = cur;
	    			break;
    			}
    		}
    	}
    }
}


void insert(ListNode **head_ref, ListNode *new_node) {
    ListNode *current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->nextNode = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->nextNode != NULL && current->nextNode->data < new_node->data) {
            current = current->nextNode;
        }
        new_node->nextNode = current->nextNode;
        current->nextNode = new_node;
    }
}

void InsertionSort(ListNode **head_ref){
    ListNode *sorted = NULL;
    ListNode *current = *head_ref;

    while (current != NULL) {
        ListNode *next = current->nextNode;
        insert(&sorted, current);
        current = next;
    }

    *head_ref = sorted;
}

void InterchangeSort(ListNode* pHead){
    ListNode* i;
    ListNode* j;
    for (i = pHead; i != NULL; i = i -> nextNode){
    	for (j = i -> nextNode; j != NULL; j = j -> nextNode){
    		if (i -> data > j -> data){
    			int cur = i -> data;
    			i -> data = j -> data;
    			j -> data = cur;
    		}
    	}
    }
}
int main(){
    cin >> n;

    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }

    reverse(a, a + n);

    for (int i = 0; i < n; ++i){
    	ListNode* newNode = new ListNode();
    	newNode -> data = a[i];
    	newNode -> nextNode = pHead;
    	pHead = newNode;
    }

    SelectionSort(pHead);
    InsertionSort(&pHead);
    InterchangeSort(pHead);

    while (pHead != NULL){
    	cout << pHead -> data << ' ';
    	pHead = pHead -> nextNode;
    }
    return 0;
}