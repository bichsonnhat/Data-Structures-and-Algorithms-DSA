#include <iostream>
using namespace std;

class BST{
    struct Node{
        int key;
        Node *pLeft, *pRight;
    };

    typedef Node* TREE;

    Node* root;

    Node* getNode(int value){
        Node* nodeChild = new Node();
        nodeChild -> key = value;
        nodeChild -> pLeft = nodeChild -> pRight = nullptr;
        return nodeChild;
    }

    Node* insertNode(Node* &T, int value){
        if (T == nullptr){
            T = new Node();
            T -> key = value;
            T -> pLeft = T -> pRight = nullptr;
        } else {
            if (value < T -> key){
                T -> pLeft = insertNode(T -> pLeft, value);
            } else {
                T -> pRight = insertNode(T -> pRight, value);
            }
        }
        return T;
    }

    Node* findMin(Node* T){
        if (T == nullptr){
            return T;
        }

        if (T -> pLeft == nullptr){
            return T;
        }

        return findMin(T -> pLeft);
    }

    Node* findMax(Node* T){
        if (T == nullptr){
            return T;
        }

        if (T -> pRight == nullptr){
            return T;
        }

        return findMax(T -> pRight);
    }

    Node* deleteNode(Node* &T, int value) {
        if (T == nullptr) {
            return T;
        }

        if (value < T -> key) {
            T -> pLeft = deleteNode(T -> pLeft, value);
        } else if (value > T -> key) {
            T -> pRight = deleteNode(T -> pRight, value);
        } else {
            Node* curNode;
            // NodeLeaf or have one childNode
            if (T -> pLeft == nullptr || T -> pRight == nullptr) {
                curNode = T;
                T = (T -> pLeft != nullptr) ? T -> pLeft : T -> pRight;
                delete curNode;
            } else { // Node have two childNode
                curNode = findMin(T -> pRight); // or curNode = findMax(T->pLeft);
                T -> key = curNode -> key;
                T -> pRight = deleteNode(T -> pRight, T -> key);
            }
        }
        return T;
    }

    void removeTree(Node* &T){
        if (T != nullptr){
            removeTree(T -> pLeft);
            removeTree(T -> pRight);
            delete T;
        }
    }

    void travelTree(Node* T){
        if (T == nullptr){
            return;
        }
        cout << T -> key << ' ';
        travelTree(T -> pLeft);
        travelTree(T -> pRight);
    }

    public:
        BST(){
            root = nullptr;
        }

        ~BST(){
            removeTree(root);
        }

        void insert(int value){
            root = insertNode(root, value);
        }

        void remove(int value){
            root = deleteNode(root, value);
        }

        void displayTree(){
            travelTree(root);
        }

};

int main(){
    BST Tree;
    int numberNodes; cin >> numberNodes;
    for (int i = 0; i < numberNodes; ++i){
        int nodeValue; cin >> nodeValue;
        Tree.insert(nodeValue);
    }

    Tree.displayTree(); cout << endl;
    int nodeDel; cin >> nodeDel;
    Tree.remove(nodeDel);
    Tree.displayTree();
    return 0;
}
