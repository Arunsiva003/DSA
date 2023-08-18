#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            this->data =val ;  
            this->left=NULL;
            this->right= NULL;
        }


        Node* insert(Node* root,int val){
            if(root==NULL) return new Node(val);
            Node* curr;
            if(root->data < val){
                curr = insert(root->right,val);
                root->right = curr;
            }
            else {
                curr  =insert (root ->left ,val);
                root->left=curr;
            }
            return root;
        }

        void inorder(Node* root){
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }


    vector<int> print2(Node* root){
        if(root==NULL) return {};
        vector<int> ans;
        while(root->left->left!=NULL){
            root=root->left;
        }
        ans.push_back(root->left->data);
        if(root->right && root->right->left==NULL && root->left->right==NULL) ans.push_back(root->right->data);
        return ans;

    }
    Node* deleteNode(Node* root, int val){
        if(root==NULL){
            return root;
        }
        if(val<root->data){
            root->left = deleteNode(root->left,val);
        }
        else if(val>root->data){
            root->right = deleteNode(root->right,val);
        }
        else{
            //if leaf
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            else{
                Node* temp = root->left;
                while(temp->right!=NULL){
                    temp = temp->right;
                }
                root->data = temp->data;
                delete temp;
            }
        }
    }
};

int main(){
    Node Tree(0);
    Node* root = NULL;

    vector<int> arr = {20,15,10,5,13};
    int n=arr.size();
    for (int i = 0;i<n;++i) {
        int val=arr[i];
        root = Tree.insert(root,val);
    }
    Tree.inorder(root);
    cout<<"\n";
    Tree.deleteNode(root,2);
    Tree.inorder(root);
    cout<<"\n";
    vector<int> ans =Tree.print2(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}