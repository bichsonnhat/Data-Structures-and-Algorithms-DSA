#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e3 + 5;
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
                T = (T -> pLeft != nullptr) ? T->pLeft : T -> pRight;
                delete curNode;
            } else { // Node have two childNode
                curNode = findMin(T -> pRight); // or curNode = findMax(T->pLeft);
                T -> key = curNode->key;
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

    void LNR(Node* T){
        if (T == nullptr){
            return;
        }
        LNR(T -> pLeft);
        cout << T -> key << ' ';
        LNR(T -> pRight);
    }

    void NLR(Node* T){
        if (T == nullptr){
            return;
        }
        cout << T -> key << ' ';
        NLR(T -> pLeft);
        NLR(T -> pRight);
    }

    void RNL(Node* T){
        if (T == nullptr){
            return;
        }
        RNL(T -> pRight);
        cout << T -> key << ' ';
        RNL(T -> pLeft);
    }

    int cntNodeLeaf(Node* T){
        if (T == nullptr){
            return 0;
        }
        int ans = cntNodeLeaf(T -> pLeft) + cntNodeLeaf(T -> pRight);

        ans += (T -> pLeft == nullptr && T -> pRight == nullptr);

        return ans;
    };

    int cntNodeTwoChild(Node* T){
        if (T == nullptr){
            return 0;
        }

        int ans = cntNodeTwoChild(T -> pLeft) + cntNodeTwoChild(T -> pRight);

        ans += (T -> pLeft and T -> pRight);

        return ans;
    }

    int cntNodeLeft(Node* T){
        if (T == nullptr){
            return 0;
        }

        int ans = cntNodeLeft(T -> pLeft) + cntNodeLeft(T -> pRight);

        ans += (T -> pLeft and T -> pRight == nullptr);

        return ans;
    }

    int cntNodeRight(Node* T){
        if (T == nullptr){
            return 0;
        }

        int ans = cntNodeRight(T -> pLeft) + cntNodeRight(T -> pRight);

        ans += (T -> pLeft == nullptr and T -> pRight);

        return ans;
    }

    int cntNodeOneChild(Node* T){
        if (T == nullptr){
            return 0;
        }

        int ans = cntNodeOneChild(T -> pLeft) + cntNodeOneChild(T -> pRight);

        ans += ((T -> pLeft == nullptr && T -> pRight) || (T -> pRight == nullptr && T -> pLeft));

        return ans;
    }

    int highOfTree(Node* T){
        if (T == nullptr){
            return 0;
        }
        return max(highOfTree(T -> pLeft), highOfTree(T -> pRight)) + 1;
    }

    void Level(Node* T){
        queue <pair <Node*, int> > q;
        vector <int> d(N, -1);
        q.push({T, 0});
        d[T -> key] = 0;
        int max_level = 0;
        while (!q.empty()){
            Node* u = q.front().first; 
            int level = q.front().second;
            max_level = max(max_level, level);
            q.pop();
            if (u -> pLeft){
                d[u -> pLeft -> key] = level + 1;
                q.push({u -> pLeft, level + 1});
            }

            if (u -> pRight){
                d[u -> pRight -> key] = level + 1;
                q.push({u -> pRight, level + 1});
            }
        }

        for (int i = 0; i <= max_level; ++i){
            cout << "Muc " << i << " : ";
            for (int j = 1; j <= 1000; ++j){
                if (d[j] == i) cout << j << ' ';
            }
            cout << endl;
        }
    }

    void travelEvenKey(Node* T){
        if (T == nullptr){
            return;
        }

        if (T -> key % 2 == 0) cout << T -> key << ' ';
        travelEvenKey(T -> pLeft);
        travelEvenKey(T -> pRight);
    }

    void travelTreeValueX(Node* T, int X){
        if (T == nullptr){
            return;
        }

        if (T -> key > X) cout << T -> key << ' ';
        travelTreeValueX(T -> pLeft, X);
        travelTreeValueX(T -> pRight, X);
    }

    int cntNode(Node* T){
        if (T == nullptr){
            return 0;
        }

        int ans = cntNode(T -> pLeft) + cntNode(T -> pRight);

        ans += (T != nullptr);

        return ans;
    }

    Node* findNodeX(Node* T, int X){
        if (T == nullptr || T -> key == X){
            return T;
        }

        if (X < T -> key) return findNodeX(T -> pLeft, X);
        
        return findNodeX(T -> pRight, X);
    }

    Node* findMaxValue(Node* T){
        if (T == nullptr){
            return nullptr;
        }

        while (T -> pRight){
            T = T -> pRight;
        }

        return T;
    }

    Node* minimumRightSubTree(Node* T){
        if (T == nullptr){
            return nullptr;
        }
        T = T -> pRight;
        while (T -> pLeft == nullptr && T != nullptr) T = T -> pRight;
        while (T -> pLeft && T != nullptr){
            T = T -> pLeft;
        }

        return T;
    }

    void findDist(Node* T){
        queue <pair <Node*, int> > q;
        vector <int> d(N, 0);
        q.push({T, 0});
        while (!q.empty()){
            Node* u = q.front().first; 
            int dist = q.front().second;
            q.pop();
            if (u -> pLeft){
                d[u -> pLeft -> key] = dist + 1;
                q.push({u -> pLeft, dist + 1});
            }

            if (u -> pRight){
                d[u -> pRight -> key] = dist + 1;
                q.push({u -> pRight, dist + 1});
            }
        }

        for (int i = 0; i <= 1000; ++i){
            if (d[i] != 0){
                cout << "From Root to Node " << i << " is: " << d[i] << '\n';
            }
        }
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

        void displayLNR(){
            LNR(root); cout << endl;
        }

        void displayNLR(){
            NLR(root); cout << endl;
        }

        void displayRNL(){
            RNL(root); cout << endl;
        }

        int countNodeLeaf(){
            return cntNodeLeaf(root);
        }

        int countNodeTwoChild(){
            return cntNodeTwoChild(root);
        }

        int countNodeLeft(){
            return cntNodeLeft(root);
        }

        int countNodeRight(){
            return cntNodeRight(root);
        }

        int countNodeOneChild(){
            return cntNodeOneChild(root);
        }

        int findHigh(){
            return highOfTree(root);
        }

        void travelLevel(){
            Level(root);
        }

        void EvenKey(){
            travelEvenKey(root);
        }

        void printNodeX(int X){
            travelTreeValueX(root, X);
        }

        int countNode(){
            return cntNode(root);
        }

        Node* findX(int X){
            return findNodeX(root, X);
        }

        Node* findMaxNodeValue(){
            return findMaxValue(root);
        }

        Node* findMinValueRightSubTree(){
            return minimumRightSubTree(root);
        }

        void distanceFromRootToNode(){
            findDist(root);
        }
};

int main(){
    BST Tree;
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int u; cin >> u;
        Tree.insert(u);
    }

    // 1.Print Node have key even
    Tree.EvenKey(); cout << endl;

    // 2.Print Node have Value bigger than X
    int X; cin >> X;
    Tree.printNodeX(X); cout << endl;

    // 3.Count Node
    cout << Tree.countNode() << endl;
 
    // 4.Find the depth of tree
    cout << Tree.findHigh() << endl;

    // 5.Find node have value X
    cin >> X;
    cout << Tree.findX(X) << endl;

    // 6.Find node have max value
    cout << Tree.findMaxNodeValue() << endl;

    // 7.Find node have min value in Right Sub Tree
    cout << Tree.findMinValueRightSubTree();
    
    // 8. Count Node Leaf
    cout << Tree.countNodeLeaf() << endl;

    // 9. Count Node have one Child
    cout << Tree.countNodeOneChild() << endl;

    // 10. Count Node have Right Sub Tree
    cout << Tree.countNodeRight() << endl;

    // 11. Count Node have Left Sub Tree
    cout << Tree.countNodeLeft() << endl;

    // 12. Count Node have 2 Child
    cout << Tree.countNodeTwoChild() << endl;

    // 13. Print Node for each level
    Tree.travelLevel(); 

    // 14. Find distance from root to each node
    Tree.distanceFromRootToNode();
    return 0;   
}