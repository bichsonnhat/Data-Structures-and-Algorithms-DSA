#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
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

    void removeTree(Node* &T){
        if (T != nullptr){
            removeTree(T -> pLeft);
            removeTree(T -> pRight);
            delete T;
        }
    }

    void findNodeTopView(Node* T){
        if (root == nullptr){
            return;
        }

        queue <pair <Node*, int> > q;
        q.push({T, 0});

        map <int, int> hashMap;

        while (!q.empty()){
            auto alpha = q.front(); q.pop();
            Node* curNode = alpha.first;
            int hd = alpha.second;

            if (hashMap.find(hd) == hashMap.end()){
                hashMap[hd] = curNode -> key;
            }

            if (curNode -> pLeft){
                q.push({curNode -> pLeft, hd - 1});
            } 

            if (curNode -> pRight){
                q.push({curNode -> pRight, hd + 1});
            }
        }

        vector <int> ans;

        for (auto u : hashMap){
            ans.emplace_back(u.second);
        }

        sort(ans.begin(), ans.end());

        for (auto u : ans){
            cout << u << ' ';
        }
        
        cout << '\n';
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

        void topView(){
            findNodeTopView(root);
        }
};

int main(){ 
    BST Tree;
    int numberNodes; cin >> numberNodes;
    for (int i = 0; i < numberNodes; ++i){
        int nodeValue; cin >> nodeValue;
        Tree.insert(nodeValue);
    }

    Tree.topView();
    return 0;
}