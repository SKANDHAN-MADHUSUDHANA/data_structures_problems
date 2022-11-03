//this is a program containig all the basic functions that can be performed on a queue 
//it is implemented using template and can deal with integer, float, char type of data
//here the queue is implemented using arrays

    #include<iostream>
    using namespace std;
      
    template <typename T>
    class QueueUsingArray
    {
        T * data;
        int nextIndex;
        int firstIndex;
        int size;
        int capacity;
        
        public:
        QueueUsingArray(int s)
        {
            data = new T[s];
            nextIndex = 0;
            firstIndex = -1;
            size = 0;
            capacity = s;
        }
        
        void sizeofQueue()
        {
            cout<<"The total number of elements in the queue is : "<<size<<endl;
        }
        
        void isEmpty()
        {
            if(size == 0)
            {
                cout<<"The Queue is Empty ! "<<endl;
                return;
            }
            cout<<"The queue is not Empty ! "<<endl;
        }
        
        void enqueue(T element)
        {
            if(size == capacity)
            {
                cout<<"The queue is full !"<<endl;
                return;
            }
            data[nextIndex]=element;
            nextIndex = (nextIndex + 1) % capacity;
            if(firstIndex == -1)
            {
                firstIndex = 0;
            }
            size++;
        }
        
        void front()
        {
            if(firstIndex == -1)
            {
                cout<<"The queue is empty !"<<endl;
                return;
            }
            cout<<"The element at the front of the queue is : "<<data[firstIndex]<<endl;
        }
        
        void dequeue()
        {
            if(firstIndex == -1)
            {
                cout<<"The queue is empty"<<endl;
                return;
            }
            cout<<"The element that is dequeued from the queue is : "<<data[firstIndex]<<endl;
            firstIndex = (firstIndex + 1) % capacity ;
            size--;
            if(size == 0)
            {
                firstIndex = -1;
                nextIndex = 0;
            }
        }
    };
    
    
      int main()
    {
        int choiceD, choiceP, size;
        cout<<"1. Integer"<<endl<<"2. Float"<<endl<<"3. Charecter"<<endl;
        cout<<"Enter the type of data u wish to store in the queue : ";
        cin>>choiceD;
        if(choiceD == 1)
        {
            cout<<"Enter the size of the queue you want : ";
            cin>>size;
            QueueUsingArray<int> s(size);
            int element;
            while(true)
            {
                cout<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Front"<<endl<<"4. Size"<<endl<<"5. Empty??"<<endl<<"6. Exit"<<endl;
                cout<<"Chose the operation that you would like to perform on the queue : ";
                cin>>choiceP;
                switch(choiceP)
                {
                    case 1: cout<<"enter the data you wish to add to the queue (remeber to add the type of data that u had chosen earlier) : ";
                            cin>>element;
                            s.enqueue(element);
                            break;
                    case 2: s.dequeue();
                            break;
                    case 3: s.front();
                            break;
                    case 4: s.sizeofQueue();
                            break;
                    case 5: s.isEmpty();
                            break;
                    case 6: exit(0);
                    default: cout<<"Please enter a valid choice ! "<<endl;
                    
                }
            }
        }
        
        else if(choiceD == 2)
        {
            cout<<"Enter the size of the queue you want : ";
            cin>>size;
            QueueUsingArray<float> s(size);
            float element;
            while(true)
            {
                cout<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Front"<<endl<<"4. Size"<<endl<<"5. Empty??"<<endl<<"6. Exit"<<endl;
                cout<<"Chose the operation that you would like to perform on the queue : ";
                cin>>choiceP;
                switch(choiceP)
                {
                    case 1: cout<<"enter the data you wish to add to the queue (remeber to add the type of data that u had chosen earlier) : ";
                            cin>>element;
                            s.enqueue(element);
                            break;
                    case 2: s.dequeue();
                            break;
                    case 3: s.front();
                            break;
                    case 4: s.sizeofQueue();
                            break;
                    case 5: s.isEmpty();
                            break;
                    case 6: exit(0);
                    default: cout<<"Please enter a valid choice ! "<<endl;
                    
                }
            }
        }
        else if(choiceD == 3)
        {
            cout<<"Enter the size of the queue you want : ";
            cin>>size;
            QueueUsingArray<char> s(size);
            char element;
            while(true)
            {
                cout<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Front"<<endl<<"4. Size"<<endl<<"5. Empty??"<<endl<<"6. Exit"<<endl;
                cout<<"Chose the operation that you would like to perform on the queue : ";
                cin>>choiceP;
                switch(choiceP)
                {
                    case 1: cout<<"enter the data you wish to add to the queue (remeber to add the type of data that u had chosen earlier) : ";
                            cin>>element;
                            s.enqueue(element);
                            break;
                    case 2: s.dequeue();
                            break;
                    case 3: s.front();
                            break;
                    case 4: s.sizeofQueue();
                            break;
                    case 5: s.isEmpty();
                            break;
                    case 6: exit(0);
                    default: cout<<"Please enter a valid choice ! "<<endl;
                    
                }
            }
        }
        else
        {
            cout<<"Enter a valid choice ! "<<endl;
        }
    }  
    
      
      
