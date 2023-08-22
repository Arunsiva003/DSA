// linked list implementation ?
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next=nullptr;
    }
};


int main(){
    Node* node;
    node->val = 1;
    node->next = new Node(1);
}