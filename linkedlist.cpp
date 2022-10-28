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

----------------------------------------------------------------------------------
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

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Taking the input from the user and creating the linked list on its own
//and printing the data parts of the linked list
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

Node * takeInput(){ // since we are returning the head node its return type is a pointer which is of type head
    int data;
    cout<<"Enter the data of the new Node (Enter -1 to terminate)"<<endl;
    cin>>data;
    Node * head = NULL; //initializing pointer variable to NULL so that it can be used to assign only once
    while(data != -1){ //the terminator is -1
        Node * newNode = new Node(data); //creating new node dynamically so that it is not lost due to scope of variables
        if(head == NULL){
            head = newNode;  //initializing the first node to the head pointer
        }
        
        //the linking of rest of the nodes in the list is taken care by the below code
        
        else{
            Node * temp = head;
            while(temp->next!=NULL){
                temp = temp -> next;
            }
            temp->next = newNode;
        }
        cout<<"Enter the data of the new Node (Enter -1 to terminate)"<<endl;    
        cin>>data;
    }
    
    return head;
}


void print(Node * head){
    Node * cur = head;
    cout<<"The elements in the linked list are : ";
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<endl;
}


int main(){
    Node * head = takeInput();
    print(head);
}


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
    // taling input functions time complexity is being reduced using an extra tail node instead of finding the last node for each insertion
    
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

Node * takeInput_better(){
    int data;
    cout<<"Enter the data of the linked list node (use -1 to terminate)"<<endl;
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    
    while(data != -1){
        Node * newNode = new Node(data); 
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
    cout<<"Enter the data of the linked list node (use -1 to terminate)"<<endl;
    cin>>data;
    }
    return head;
}

void print(Node * head){
    Node * temp = head;
    cout<<"The elements of the linked list are : ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node * head = takeInput_better();
    print(head);
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
//gives the count of total number of elements in the linked list
    
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *  next;
        
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

Node * takeInput_tail(){
    int data;
    cout<<"Enter the data of the node to be inserted (use -1 as the terminator)"<<endl;
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cout<<"Enter the data of the node to be inserted (use -1 as the terminator)"<<endl;
        cin>>data;
    }
    
    return head;
}

void print(Node * head){
    Node * temp = head;
    cout<<"The elements in the linked list are : ";
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int totalNumberOfNodes(Node * head){
    Node * temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

int main(){
    Node * head = takeInput_tail();
    print(head);
    int ans = totalNumberOfNodes(head);
    cout<<"The total number of nodes in the linked list is : "<<ans<<endl;
}

///// giving out the element found at a particular position which is given by the user
//the count starts from 0 and goes on

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *  next;
        
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

Node * takeInput_tail(){
    int data;
    cout<<"Enter the data of the node to be inserted (use -1 as the terminator)"<<endl;
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cout<<"Enter the data of the node to be inserted (use -1 as the terminator)"<<endl;
        cin>>data;
    }
    
    return head;
}

void print(Node * head){
    Node * temp = head;
    cout<<"The elements in the linked list are : ";
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int totalNumberOfNodes(Node * head){
    Node * temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

int findElement(Node * head , int n){
    Node * cur = head;
    while(n != 0){
        cur = cur -> next;
        n--;
    }
    
    return cur -> data;
}

int main(){
    int key;
    Node * head = takeInput_tail();
    cout<<"enter the position you wish (make sure its less than the total number of input elements)"<<endl;
    cin>>key;
    int ans = findElement(head,key);
    cout<<"The element at the provided postion is  : "<<ans<<endl;
    print(head);
}


/// insertion of node at keyTH position 
// it can handel insertion at front and also insertion at any position
//it can also handel NULL errors or segmentaion faults

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

Node * takeInput(){
    int data;
    cout<<"Enter the value of the Node to be inserted (use -1 to terminate) : ";
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cout<<"Enter the value of the Node to be inserted (use -1 to terminate) : ";
        cin>>data;
    }
    return head;
}

void printLinkedList(Node * head){
    if(head == NULL){
        cout<<"The linked list is empty"<<endl;
        return;
    }
    Node * temp = head;
    cout<<"The elements in the linked list are : ";
    while (temp != NULL){
        cout<<temp->data<<" "; 
        temp = temp -> next;
    }
    cout<<endl;
}

Node * insertNode(Node * head, int key, int data){
    Node * newNode = new Node(data);
    Node * temp = head; 
    if (key == 0){  // this is for insertion at zero position or insertion at front
        newNode -> next = head;
        head = newNode;
        return head;
    }
    int count = 0;
    while(temp != NULL && count < key - 1 ){ //this is to handle segmentation fault or to handle NULL exceptions
        temp = temp -> next;
        count++ ;
    }
    if(temp != NULL){
    Node * forget = temp -> next;
    temp -> next = newNode;
    newNode -> next = forget;
    }
    return head;
}

int main(){
    int n, data;
    Node * head = takeInput();
    cout<<"Linked list before insertion at a postion " <<endl;
    printLinkedList(head);
    cout<<"Enter the postion of insertion : ";
    cin>>n;
    cout<<"Enter the data of the Node to be inserted : ";
    cin>>data;
    head = insertNode(head , n , data);
    cout<<"Linked list after insertion at a postion " <<endl;
    printLinkedList(head);
}


///delete node at any position and also at the start and it controlls seegmentation faults or NULL errors

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

Node * input(){
    int data;
    cout<<"Enter the value of the node to be inserted (Use -1 as a terminator) : ";
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
    cout<<"Enter the value of the node to be inserted (Use -1 as a terminator) : ";
    cin>>data;
    }
    return head;
}

void print(Node * head){
    if(head == NULL){
        cout<<"The linked list is empty!"<<endl;
        return;
    }
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node * deleteAtPositon(Node * head, int key){
    Node * temp = head;
    if( key == 0){ // to delete if the position is 0 or delete at front
        head = head -> next;
        delete(temp);
        return head;
    }
    int count = 0; // delete at any postition
    while(temp != NULL && count < key - 1){
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
    Node * cur = temp -> next;
    Node * point = cur -> next;
    temp -> next = point ;
    cur -> next = NULL;
    delete(cur);
    }
    return head; 
}

int main(){
    Node * head = input();
    print(head);
    int key;
    cout<<"Enter the postion at which the node needs to be delete : ";
    cin>>key;
    head = deleteAtPositon(head, key);
    print(head);
}

///inserting at postittion recursively

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


Node * takeInput(){
    int data;
    cout<<"Enter the data of the node to be inserted ( use -1 to terminate the insertion ) : ";
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next=newNode;
            tail = tail -> next;
        }
    cout<<"Enter the data of the node to be inserted ( use -1 to terminate the insertion ) : ";
    cin>>data;
    }
    
    return head;
}

void print(Node * head){
    if(head == NULL){
        cout<<"The linked list id empty !"<<endl;
        return;
    }
    
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node * insertRecursive(Node * head, int data , int key){
    if (head == NULL || key == 0){ // this condition helps in handling insetion at a position greater then length of ll by inserting at end
        Node * newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
    }
    else{
        head -> next = insertRecursive(head -> next , data , key - 1); //breaking down of the problem into smaller problem 
    }
    
    return head;
}

int main(){
    int data, key;
    Node * head = takeInput();
    print(head);
    cout<<"Enter the data of the node to be inserted : ";
    cin>>data;
    cout<<"Enter the position of insertion : ";
    cin>>key;
    head = insertRecursive(head,data,key);
    print(head);
}


//deleting at a position recursively
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


Node * takeInput(){
    int data;
    cout<<"Enter the data of the node to be inserted ( use -1 to terminate the insertion ) : ";
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next=newNode;
            tail = tail -> next;
        }
    cout<<"Enter the data of the node to be inserted ( use -1 to terminate the insertion ) : ";
    cin>>data;
    }
    
    return head;
}

void print(Node * head){
    if(head == NULL){
        cout<<"The linked list id empty !"<<endl;
        return;
    }
    
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node * deleteRecursively(Node * head, int key){
    if(head == NULL){
        return head;
    }
    if(key == 0){
        Node * temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete(temp);
    }
    else{
        head->next = deleteRecursively(head->next , key - 1);
    }
    return head;
}

int main(){
    int  key;
    Node * head = takeInput();
    print(head);
    cout<<"Enter the position of deletion : ";
    cin>>key;
    head = deleteRecursively(head,key);
    print(head);
}


//finding the mid point of the linked list without finding the length of the linked list

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


Node * takeInput(){
    int data;
    cout<<"Enter the data of the node to be inserted ( use -1 to terminate the insertion ) : ";
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next=newNode;
            tail = tail -> next;
        }
    cout<<"Enter the data of the node to be inserted ( use -1 to terminate the insertion ) : ";
    cin>>data;
    }
    
    return head;
}

void print(Node * head){
    if(head == NULL){
        cout<<"The linked list id empty !"<<endl;
        return;
    }
    
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int returnMID(Node * head){
    Node * slow = head;
    Node * fast = head;
    if(head != NULL){
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    }
    return slow->data;
}

int main(){
    int  key;
    Node * head = takeInput();
    print(head);
    int ans = returnMID(head);
    cout<<"The mid point of the linked list is : "<<ans<<endl;
    
}
