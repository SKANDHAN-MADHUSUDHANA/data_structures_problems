//this below program contains all the basic menu driven processes that can be performed on a linked list

    #include<iostream>
    using namespace std;
    
    class Node
    {
        public:
            int data;
            Node * next;
            
        Node(int data)
        {
            this -> data = data;
            next = NULL;
        }
    };
    Node * head = NULL;
    
    Node * createLinkedList(){
        head = NULL;
        int data;
        cout<<"Enter the data of the node to be added to the list (use -1 to terminate) : ";
        cin>>data;
        Node * tail = NULL;
        while(data != -1)
        {
            Node * newNode = new Node(data);
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail -> next = newNode;
                tail = tail -> next;
            }
            cout<<"Enter the data of the node to be added to the list (use -1 to terminate) : ";
            cin>>data;
        }
        return head;
    }
    
    void displayLinkedList()
    {
        if(head == NULL)
        {
            cout<<"The linked list is empty !"<<endl;
            return;
        }
        Node * temp = head;
        cout<<"The linked list is : ";
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
    
    Node * inserAtFront()
    {
        int data;
        cout<<"Enter the data of the node that needs to be inserted : ";
        cin>>data;
        Node * newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;    
        }
        else
        {
            newNode -> next = head;
            head = newNode;
        }
        return head;
    }
    
    Node * insetAtEnd()
    {
        int data;
        cout<<"Enter the data of the node that needs to be inserted : ";
        cin>>data;
        Node * newNode = new Node(data);
        Node * temp = head;
        if(head == NULL)
        {
            newNode = head;
            return head;
        }
        else
        {
            while(temp -> next != NULL)
            {
                temp = temp -> next;    
            }
            temp -> next = newNode;
        }
        return head;
    }
    
    Node * insertAtPosition()
    {
        int data, pos, count = 1;
        cout<<"Enter the positon for insertion : ";
        cin>>pos;
        cout<<"Enter the data of insertion : ";
        cin>>data;
        Node * newNode = new Node(data);
        Node * temp = head;
        if(head == NULL && pos != 1)
        {
            cout<<"There are no elements in the linked list so if u want to insert at position 1 choose option 3 !"<<endl;
            return head;
        }
        while(count < pos - 1 && temp != NULL)
        {
            temp = temp -> next;
            count++;
        }
        if(temp != NULL)
        {
        newNode -> next = temp -> next;
        temp -> next = newNode;
        }
        else
        {
            cout<<"U have entered a position greater than the length of the existing linked list ! "<<endl;
            cout<<"If u wish to insert it at the last choose option 4 ! "<<endl;
        }
        return head;
    }
    
    Node * deleteAtFront()
    {
        Node * temp = head;
        if(head == NULL)
        {
            cout<<"Cannot delete as there are no nodes to delete ! ";
            return head;
        }
        else
        {
            head = head -> next;
            temp -> next = NULL;
            delete(temp);
        }
        return head;
    }
    
    Node * deleteAtEnd()
    {
        Node * temp = head;
        Node * del = NULL;
        if(head == NULL)
        {
            cout<<"Can not delete at the end as there are no nodes ! "<<endl;
            return head;
        }
        if(head -> next == NULL)
        {
            temp = head -> next;
            head = NULL;
            delete(temp);
        }
        else
        {
            while(temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }
            del = temp -> next;
            temp -> next = NULL;
            delete(del);
        }
        return head;
    }
    
    Node * deleteAtPosition()
    {
        int pos, count = 1;
        cout<<"Enter the position for deletion : ";
        cin>>pos;
        Node * temp = head;
        Node * del = NULL;
        if(head == NULL)
        {
            cout<<"can not delete from an empty linked list try adding few nodes before deletion! "<<endl;        
            return head;
        }
        while(count < pos - 1 &&  temp != NULL)
        {
            temp = temp -> next;
            count++;
        }
        if(head == NULL)
        {
            cout<<"The position entered is more than the length of the list ! "<<endl;
            return head;
        }
        else
        {
            del = temp -> next;
            temp -> next = del -> next;
            delete(del);
        }
        return head;
    }
    
    void SearchAnElement()
    {
        int data , count = 1;
        cout<<"Enter the data of the node you want to search : ";
        cin>>data;
        Node * temp = head;
        if(head == NULL)
        {
            cout<<"The linked list is empty insert few nodes before searching ! "<<endl;
            return;
        }
        else
        {
            while (temp != NULL)
            {
                if(temp -> data == data)
                {
                    cout <<"The node you are searching for is present at the position : "<<count<<endl;
                    return;
                }
                else
                {
                    temp = temp -> next;
                    count++;
                }
            }
        }
        cout<<"The node you are searching for is not present in the linked list ! "<<endl;
        return;
    }
    
    int MidPointOfTheList()
    {
        Node * slow = head;
        Node * fast = head;
        if(head == NULL)
        {
            cout<<"The linked list is empty so we cannot find the mid point of the list ! "<<endl;
            return 0;
        }
        else
        {
            while(fast != NULL && fast -> next != NULL)
            {
                slow = slow -> next;
                fast = fast -> next -> next;
            }
        }
        
        cout<<"The mid point of the list is : "<<slow -> data<<endl;
        return 0;
    }
    
    int LengthOfTheList()
    {
        int count = 0;
        Node * temp = head;
        if(head == NULL)
        {
            cout<<"The list is empty hence the length is 0 !"<<endl;
            return 0;
        }
        else
        {
            while(temp != NULL)
            {
                temp = temp -> next;
                count++;
            }
        }
        cout<<"The length of the linked list is : "<<count<<endl;
        return 0;
    }
    
    Node * ReverseList()
    {
        Node * cur = head;
        Node * next = head;
        Node * prev = NULL;
        if(head == NULL || head -> next == NULL)
        {
            cout<<"Empty or list with single node cannot be reversed : "<<endl;
            return head;
        }
        else
        {
            while(cur != NULL)
            {
                next = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = next;
            }
            head = prev;
        }
        return head;
    }
    
    int main()
    {
        int n;
        
        while(true)
        {
            cout<<"******************************************************************"<<endl;
            cout<<"Choose the operation u want to perform on a linked list ! "<<endl;
            cout<<"1. Create"<<endl<<"2. Display"<<endl<<"3. Insert at Front"<<endl<<"4. Insert at End"<<endl<<"5. Insert at a Position"<<endl<<"6. Delete at Front"<<endl<<"7. Delete at end"<<endl<<"8. Delete at a position"<<endl
            <<"9. Search for an element"<<endl<<"10. Mid point of the list"<<endl<<"11. Length of the list"<<endl<<"12. Reverse the list"<<endl<<"13. Exit"<<endl;
            cout<<"******************************************************************"<<endl;
            cout<<"Enter your choice : ";
            cin>>n;
            cout<<"******************************************************************"<<endl;
            switch(n)
            {
                case 1: createLinkedList();
                        break;
                case 2: displayLinkedList();
                        break;
                case 3: inserAtFront();
                        break;
                case 4: insetAtEnd();
                        break;
                case 5: insertAtPosition();
                        break;
                case 6: deleteAtFront();
                        break;
                case 7: deleteAtEnd();
                        break;
                case 8: deleteAtPosition();
                        break;
                case 9: SearchAnElement();
                        break;
                case 10: MidPointOfTheList();
                        break;
                case 11: LengthOfTheList();
                        break;
                case 12: ReverseList();
                        break;
                case 13:cout<<"Thank You !"<<endl;
                        cout<<"******************************************************************"<<endl;
                        exit(0);
                default: cout<<"Enter a valid choice !"<<endl;
            } 
        }    
    }


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


//merging of two sorted linked list in ascending order

    #include<iostream>
    using namespace std;
    
    //this is the creation of node class which is used to create a node of the linked list
    class Node
    {
        public:
            int data;
            Node * next;
            
        Node(int data)
        {
            this -> data = data;
            next = NULL;
        }
    };

    //this is the creation of linked list 
    //-1 is used as the termimator or to stop taking input
    Node * takeInput()
    {
        int data;
        cout<<"Enter the data of the node to be inserted (use -1 as the terminator) : ";
        cin>>data;
        Node * head = NULL;
        Node * tail = NULL;
        
        while(data != -1)
        {
            Node * newNode = new Node(data);
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail -> next = newNode;
                tail = tail -> next;
            }
            cout<<"Enter the data of the node to be inserted (use -1 as the terminator) : ";
            cin>>data;
        }
        return head;
    }

    //this is the function that helps in printing the linked list
    void printLinkedList(Node * head)
    {
        if(head == NULL)
        {
            return;
        }
        Node * temp = head;
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    //this is the function where two sorted ascending ordered linked list are merged    
    Node * mergeSortedLinkedList(Node * head1 , Node * head2)
    {
        Node * head = NULL;  //head of the merged linked list
        Node * tail = NULL;  //tail of the merged linked list
        if(head1 == NULL && head2 == NULL) //condition when both the linked list are empty
        {
            cout<<"cannot merge empty linked list ! "<<endl;
            return head;
        }
        if(head1 == NULL and head2 != NULL) //condition when first linked list is empty
        {
            head = head2;
            return head;
        }
        if(head2 == NULL and head1 != NULL) //condition when second linked list is empty
        {
            head = head1;
            return head;
        }
        if(head1->data < head2-> data) //for the first itteration to assign the merged linked list head and tail
            {
                head = head1;
                tail = head1;
                head1 = head1 -> next;
            }
            else
            {
                head = head2;
                tail = head2;
                head2 = head2 -> next;
            }
        while(head1 != NULL and head2 != NULL) //from here it takes care of the whole processes
        {
            if(head1->data <= head2-> data)
            {
                tail -> next = head1;
                tail = tail -> next;
                head1 = head1 -> next;
            }
            else
            {
                tail -> next = head2;
                tail = tail -> next;
                head2 = head2 -> next;
            }
        }
        if(head1 == NULL) //if 1st linked list is smaller than the second linked list
        {
            tail -> next = head2;
        }
        if(head2 == NULL) //if 2nd linked list is smaller than the first linked list
        {
            tail -> next = head1;
        }
        return head;
    }
    
    //this is the main from where all the functions are called accordingly
    int main()
    {
        cout<<"Enter the data of the first linked list ! (make sure its sorted and is in ascending order) "<<endl;
        Node * head1 = takeInput();
        cout<<"The first Linked List is : "; 
        printLinkedList(head1);
        cout<<endl<<"********************************************************************************************"<<endl;
        cout<<"********************************************************************************************"<<endl;
        cout<<"Enter the data of the second linked list ! (make sure its sorted and is in ascending order) "<<endl;
        Node * head2 = takeInput();
        cout<<"The second Liked list is : ";
        printLinkedList(head2);
        cout<<endl<<"********************************************************************************************"<<endl;
        cout<<"********************************************************************************************"<<endl;
        Node * head = mergeSortedLinkedList(head1, head2);
        cout<<"The resulting sorted linked list is : ";
        printLinkedList(head);
        cout<<endl<<"--------------------------------------------------------------------------------------------"<<endl;
        cout<<"--------------------------------------------------------------------------------------------"<<endl;
    }
