//Basic linked list 
//creation of node class
//creating node class objects both statically and dynamically
//linking the nodes in both the cases and creating the head pointer and printing the first nodes data

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    
    
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

int main(){
    // static allocation
    Node n1(1);
    Node * head = &n1;
    Node n2(2);
    n1.next = &n2;
    cout<<head->next->data<<endl;
    
    //dynamic allocation 
    Node *n3 = new Node(3);
    Node *head1 = n3;
    Node *n4 = new Node(4);
    n3->next = n4; 
    
    cout<<n3->data<<endl;
}

//Function to print the data parts of the Linked list for statically craeted Nodes

#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node * next;
    
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

//print function
void printLinkedList(Node *head){
    Node * cur = head;
    while(cur != NULL){ //make sure to remember the loop condition its cur!=NULL and not cur->next!=NULL
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
}

int main(){
    //creation of nodes statically
    
    Node n1(1);
    Node *head = &n1; // creation of head pointer
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    
    //connecting each nodes
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    
    printLinkedList(head);
}


//same problem where the nodes are created dynamically

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

  //dynamic creation of nodes here we can send any node as the starting node as each one of them is represented by a pointer
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(20);
    Node *node4 = new Node(20);
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    print(node2);
}
