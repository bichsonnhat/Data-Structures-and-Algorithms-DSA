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
        int hd;
    };

    typedef Node* TREE;

    Node* root;

    Node* getNode(int value){
        Node* nodeChild = new Node();
        nodeChild -> key = value;
        nodeChild -> pLeft = nodeChild -> pRight = nullptr;
        return nodeChild;
    }

    Node* insertNode(Node* &T, int value, int hd){
        if (T == nullptr){
            T = getNode(value);
            T -> hd = hd;
        } else {
            if (value < T -> key){
                T -> pLeft = insertNode(T -> pLeft, value, hd - 1);
            } else {
                T -> pRight = insertNode(T -> pRight, value, hd + 1);
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

        queue <Node*> q;
        q.push(T);

        unordered_map <int, int> hashMap;

        while (!q.empty()){
            Node* curNode = q.front(); q.pop();
            int hd = curNode -> hd;
            if (hashMap.find(hd) == hashMap.end()){
                hashMap[hd] = curNode -> key;
            }

            if (curNode -> pLeft){
                curNode -> pLeft -> hd = hd - 1;
                q.push(curNode -> pLeft);
            }

            if (curNode -> pRight){
                curNode -> pRight -> hd = hd + 1;
                q.push(curNode -> pRight);
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
            root = insertNode(root, value, 0);
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
