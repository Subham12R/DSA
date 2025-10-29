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

void inorder(Node* root, vector<int>& arr){
    if(root == NULL){
        return;
    }

    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
};

vector<int> inorderTraversal(Node* root){
    vector<int> arr;
    inorder(root, arr);
    return arr;
};


int main(){
    Node* root = new Node(1);
    root -> right = new Node(3);
    root -> left =new Node(2);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(6);
    root -> right -> right = new Node(7);

    vector<int> result = inorderTraversal(root);
    cout << "Inorder Traversal: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}   