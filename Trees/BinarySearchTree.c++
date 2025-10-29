#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left=right=NULL;
    }
};

void printTree(Node* root, vector<int>& arr){
    if(root == NULL){
        return;
    }
    printTree(root -> left, arr);
    cout << root -> data << " ";
    printTree(root -> right, arr);
}

vector<int> printTree(Node* root){
    vector<int> arr;
    printTree(root, arr);
    return arr;
}

bool search(Node* root, int target){
    while(root != NULL){
        if(root -> data == target){
            return true;
        }
        if(root -> data > target){
            root = root -> left;
        }else{
            root = root -> right;
        }
        
    }
    return false;
}
int main(){
    Node* root = new Node(9);
    root -> left = new Node(4);
    root -> right = new Node(59);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(7);
    root -> left -> left -> right = new Node(3);
    root -> right -> left = new Node(11);
    root -> right -> right = new Node(76);

    cout << "Binary Search Tree: "<< endl;
    printTree(root);
    cout << endl;

    int target = 11;
    if(search(root, target)){
        cout << "Target found in BST" << endl;
    }else{
        cout << "Target not found in BST" << endl;
    }
    return 0;
}