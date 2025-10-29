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
    arr.push_back(root -> data);
    printTree(root -> left, arr);
    printTree(root -> right, arr);
}

vector<int> printTree(Node* root){
    vector<int> arr;
    printTree(root, arr);
    return arr;
}
int main(){
    Node* root = new Node(1);
    root -> right = new Node(3);
    root -> left =new Node(2);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(6);
    root -> right -> right = new Node(7);

    vector<int> result = printTree(root);   
    cout << "Tree: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}   