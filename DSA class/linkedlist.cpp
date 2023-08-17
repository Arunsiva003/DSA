#include <bits/stdc++.h>
using namespace std;



class Node{
    public:
    int val;
    Node* next;
    //constructor for node class
    explicit  Node(int x){
        this->val =x ;
        this->next=NULL;}
        void setNextNode (Node *n) {this -> next = n;}
};

class LinkedList{
    Node* head;
    public :
    //constructor for linked list class
    LinkedList(){head = NULL;}
    void insert(int x){
        Node* node = new Node(x);
        if(head==NULL){
            head=node;
            head->next=NULL;
        }

        Node* temp = head;
        while(temp->next){
            temp=temp->next;
        }
        temp->setNextNode(node);
    }

};
    

int main(){

    return 0;
}