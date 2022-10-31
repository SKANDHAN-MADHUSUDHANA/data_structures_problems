//the program below consists of a menu driven approach to perform all the basic operations on a stack
//it uses array implementation
//use class and object approach

    #include<iostream>
    using namespace std;
    
    class StackUsingArray
    {
        int * data;
        int nextInput;
        int capacity;
        
        public:
        //the private array size is initialized using a constructor which takes the sice of the input
        StackUsingArray(int totalSize)
        {
            data = new int[totalSize];
            nextInput = 0;
            capacity = totalSize;
        }
        
        
        //the following functions are defined using public functions to manipulate the private array
        //push 
        //pop
        //display
        //top
        //size
        //isEmpty
        
        
        //the following function is used to add data into stack that is the data is pushed untill the stack is full
        void push(int element)
        {
            if(nextInput == capacity)
            {
                cout<<"The Stack is full !"<<endl;
                return;
            }
            data[nextInput] = element;
            nextInput++;
        }
        
        //the following function is to rempve the element that is present on the top of the Stack
        void pop()
        {
            if(nextInput == 0)
            {
                cout<<"The stack is empty !"<<endl;
                return;
            }
            nextInput--;
            cout<<"The poped element is : "<<data[nextInput]<<endl;
        }
        
        //this is the function that is used to display the elements in the stack
        void display()
        {
            if(nextInput == 0)
            {
                cout<<"The stack is empty !"<<endl;
                return;
            }
            for(int i = 0; i < nextInput; i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
        
        //this fuction just displays the element at the top of the stack
        void top()
        {
            if(nextInput == 0)
            {
                cout<<"The stack is empty !"<<endl;
                return;
            }
            cout<<"The element on top of the stack is : "<<data[nextInput - 1]<<endl;
        }
        
        //the function returns the size of the stack that is the number of elements in the stack
        void size()
        {
            cout<<"The total number of elements in the stack is : "<<nextInput<<endl;
        }
        
        //this function helps us to know wether the stack is empty or not
        void isEmpty()
        {
            if(nextInput == 0)
            {
                cout<<"The stack is empty !"<<endl;
            }
            else
            {
                cout<<"The stack is not empty !"<<endl;
            }
        }
    };
    
    
    int main()
    {
        int n,size,element;
        cout<<"Before performing any operations on the stack choose the size of the array that stores the stack data : ";
        cin>>size;
        StackUsingArray s(size);
        while(true)
        {
            cout<<"**********************************************************************************************"<<endl;
            cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display"<<endl<<"4. Top"<<endl<<"5. size"<<endl<<"6. Empty??"<<endl<<"7. Exit"<<endl;
            cout<<"**********************************************************************************************"<<endl;
            cout<<"Chose the opertaion you wish to perform on the stack : ";
            cin>>n;
            cout<<"**********************************************************************************************"<<endl;
            switch(n)
            {
                case 1: cout<<"Enter the data you want to insert on top of the stack : ";
                        cin>>element;
                        s.push(element);
                        break;
                case 2: s.pop();
                        break;
                case 3: s.display();
                        break;
                case 4: s.top();
                        break;
                case 5: s.size();
                        break;
                case 6: s.isEmpty();
                        break;
                case 7: exit(0);
                default: cout<<"Enter a valid choice ! "<<endl;
                        break;
            }
        }
    }



//////// 
//the below code is same as the above one here the only change is that we are not asking for array size from the user instead
// we assisng certain random capacity and once the capcity is used up the capcity is doubled up using dynamic allocation
    #include<iostream>
    using namespace std;
    
    class StackUsingArray
    {
        int * data;
        int nextInput;
        int capacity;
        
        
        public:
        StackUsingArray()
        {
            data = new int[4];
            nextInput = 0;
            capacity = 4; //lets just assign a random capacity and later we double it everytime the capacity is used up
        }
        
        //this is the function where the array size is getting doubles when it is getting full
        void push(int element)
        {
            if(nextInput == capacity)
            {
                cout<<"The capacity of the stack was full but is now doubled so don't worry ! "<<endl;
                int * newData = new int[2 * capacity];
                for(int i = 0; i < capacity; i++)
                {
                    newData[i] = data[i];
                }
                delete [] data;
                data = newData;
                capacity = capacity * 2;
            }
            data[nextInput] = element;
            nextInput++;
        }
        
        void pop()
        {
            if(nextInput == 0)
            {
                cout<<"The stack is empty !"<<endl;
                return;
            }
            nextInput--;
            cout<<"The poped element is : "<<data[nextInput]<<endl;
        }
        
        //this is the function that is used to display the elements in the stack
        void display()
        {
            if(nextInput == 0)
            {
                cout<<"The stack is empty !"<<endl;
                return;
            }
            for(int i = 0; i < nextInput; i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
        
        //this fuction just displays the element at the top of the stack
        void top()
        {
            if(nextInput == 0)
            {
                cout<<"The stack is empty !"<<endl;
                return;
            }
            cout<<"The element on top of the stack is : "<<data[nextInput - 1]<<endl;
        }
        
        //the function returns the size of the stack that is the number of elements in the stack
        void size()
        {
            cout<<"The total number of elements in the stack is : "<<nextInput<<endl;
        }
        
        //this function helps us to know wether the stack is empty or not
        void isEmpty()
        {
            if(nextInput == 0)
            {
                cout<<"The stack is empty !"<<endl;
            }
            else
            {
                cout<<"The stack is not empty !"<<endl;
            }
        }
    };
    
    
    int main()
    {
        int n,element;
        StackUsingArray s;
        while(true)
        {
            cout<<"**********************************************************************************************"<<endl;
            cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display"<<endl<<"4. Top"<<endl<<"5. size"<<endl<<"6. Empty??"<<endl<<"7. Exit"<<endl;
            cout<<"**********************************************************************************************"<<endl;
            cout<<"Chose the opertaion you wish to perform on the stack : ";
            cin>>n;
            cout<<"**********************************************************************************************"<<endl;
            switch(n)
            {
                case 1: cout<<"Enter the data you want to insert on top of the stack : ";
                        cin>>element;
                        s.push(element);
                        break;
                case 2: s.pop();
                        break;
                case 3: s.display();
                        break;
                case 4: s.top();
                        break;
                case 5: s.size();
                        break;
                case 6: s.isEmpty();
                        break;
                case 7: exit(0);
                default: cout<<"Enter a valid choice ! "<<endl;
                        break;
            }
        }
    }
