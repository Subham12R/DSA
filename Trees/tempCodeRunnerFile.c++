vector<int> preorderTraversal(Node* root){
    vector<int> arr;
    preorder(root, arr);
    return arr;
};
