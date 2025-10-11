#include <iostream>
#include <vector>
using namespace std;
// Write program using functions for binary tree traversals: Pre-order, In-order and Post order using recursive approach.
class Node {

public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data=val;
        left=right=NULL;
    }
};
    Node* insert(Node *root,int val) {
        if (root==NULL) {
 return new Node(val);
        }
        if (val<root->data) {
            root->left=insert(root->left,val);
        }
        if (val>root->data) {
            root->right=insert(root->right,val);
        }
        return root;
    }
    Node* inordersuccessor(Node* root) {
        while (root->left!=NULL) {
            root=root->left;
        }
        return root;
    }

    Node* dlt(Node *root, int target) {



        if (root->data>target) {
            root->left=dlt(root->left,target);
        }
        if (root->data<target) {
            root->right=dlt(root->right,target);
        }
if (root->data==target) {
    if (root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }
    if (root->left==NULL) {
        Node *temp= root->right;
        delete root;
        return temp;
    }
    if (root->right==NULL) {
        Node *temp=root->left;
        delete root;
        return temp;
    }
    else {
        Node* temp=inordersuccessor(root->right);
        root->data=temp->data;
        delete temp;

    }

}
return root;
    }

void inorder(Node *root) {
        if (root == NULL) return;

        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
        cout<<endl;

    }
    void postorder(Node *root) {
        if (root == NULL) return;

        postorder(root->left);
        postorder(root->right);
        cout<<root->data;
        cout<<endl;
    }
    Node* buildnew(vector<int>arr) {
        Node *root=NULL;
        for (int val: arr) {
            root=insert(root,val);
        }
        return root;
    }


int main() {
vector<int>arr={1,2,3,4,5,6};
    Node* root=buildnew(arr);
        root=insert(root,7);
        root=insert(root,10);
        inorder(root);
        dlt(root,5);
        dlt(root,4);
        postorder(root);

}