#include <iostream>
#include<sstream>

using namespace std;

class TreeNode{
public:
    // Pointer to the left child
    //  Initialised to nullptr (this syntax is a new C++11 feature)
    TreeNode* left = nullptr;
    // Pointer to the right child
    //  Initialised to nullptr (this syntax is a new C++11 feature)
    TreeNode* right = nullptr;

    // Value in the node
    int value;

    // Constructor, sets the value
    TreeNode(int v) : value(v) {}
    // Destructor, nifty trick to recursively delete all the nodes
    //  be careful though, when you delete just a single node, make
    //  sure that you set left and right = nullptr first
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Tree{
private:
    TreeNode* root = nullptr;

public:
    // These functions do the actual work
    void insert(int v, TreeNode* &subtree){
        if(subtree == nullptr){
           subtree = new TreeNode(v);
        }else if(v < subtree->value){
            insert(v, subtree->left);
        }else{
            insert(v, subtree->right);
        }
    }

    void preOrderTraversal(TreeNode* subtree) const{
        cout<<subtree->value<<" ";
        if(subtree->left!=nullptr){
            preOrderTraversal(subtree->left);
        }
        if(subtree->right!=nullptr){
            preOrderTraversal(subtree->right);
        }
    }

    void inOrderTraversal(TreeNode* subtree) const{
        if(subtree->left!=nullptr){
            inOrderTraversal(subtree->left);
        }
        cout<<subtree->value<<" ";
        if(subtree->right!=nullptr){
            inOrderTraversal(subtree->right);
        }
    }

    void postOrderTraversal(TreeNode* subtree) const{
        if(subtree->left!=nullptr){
            postOrderTraversal(subtree->left);
        }
        if(subtree->right!=nullptr){
            postOrderTraversal(subtree->right);
        }
        cout<<subtree->value<<" ";
    }

    int min(TreeNode* subtree) const{
        if(subtree->left!=nullptr){
            return min(subtree->left);
        }
        else{
            return subtree->value;
        }
    }
    int max(TreeNode* subtree) const{
        if(subtree->right!=nullptr){
            return max(subtree->right);
        }
        else{
            return subtree->value;
        }
    }
    bool contains(int value, TreeNode* subtree) const{
        if(subtree==nullptr){
            return false;
        }
        if(subtree->value==value){
            return true;
        }
        else if(value<subtree->value){
            return contains(value,subtree->left);
        }
        else{
            return contains(value,subtree->right);
        }
    }
    void remove(int value, TreeNode* &subtree){

    }

    void insert(int value){
        insert(value, root);
    }

    void preOrderTraversal(){
        preOrderTraversal(root);
        cout << endl;
    }
    void inOrderTraversal(){
        inOrderTraversal(root);
        cout << endl;
    }
    void postOrderTraversal(){
        postOrderTraversal(root);
        cout << endl;
    }
    int min(){
        return min(root);
    }
    int max(){
        return max(root);
    }
    bool contains(int value){
        return contains(value, root);
    }
    void remove(int value){
        remove(value, root);
    }
    ~Tree(){
        // This ends up deleting all the nodes recursively.
        delete root;
    }
};

int main(){
    Tree t;
    int value;
    stringstream ss("50\n30\n35\n61\n24\n58\n62\n32\n-1");
    // Sample code to read and construct the tree.
    while(cin >> value && value != -1){
        t.insert(value);
    }
    /*while(cin >> value && value != -1){
        if(t.contains(value)){
            cour<<"true"<<endl;
        }
        else {
            cout<<"false"<<endl;
        }
        t.insert(value);
    }*/

    // Do some stuff...
    t.preOrderTraversal();
    t.inOrderTraversal();
    t.postOrderTraversal();

    /*Minimum and Maximum
    cout<<t.min()<<endl;
    cout<<t.max()<<endl;*/

}
