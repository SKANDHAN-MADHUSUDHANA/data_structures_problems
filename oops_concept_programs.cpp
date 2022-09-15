#include<iostream>
using namespace std;
//If the class is declared in a different file then we need to include in the file where obects of that class are declared
//#include "student.cpp"

//class is basically a template that defines the properties and functions of an object
//object is nothing but an instance of the class

//class
class student {
    //ACCESS MODIFIERS ther are three of them (public,private,protected)
    //If the MODIFIER is private than it can only be used inside the class and cannot be used anywhere else
    //If the MODIFIER is public than we can use it anywhere we want to use it
    //default MODIFIER in C++ is private that is if no MODIFIER is set than it will of type private so if u want to use it anywhere else than declare it as public explicitly
    public :
    int rollNumber;
    int age;
};

int main(){
    //whenever we initialize an object statically the amout of space is usually sum of the space taken by each property in the class  plus a bit more
    //and once we initialize it some garbage value will be stored (this in case of c++)
    
    // create object statically
    student s1;
    student s2;
    
    //we can also initialize all of them at once like normal datatypes
    student s3, s4, s5;
    
    //we can also initialize them dynamically 
    //In this case 8bytes of memory is used to store the pointer in the stack and the size of the class is stored in the heap
    student * s6 = new student;
    
    //to initialize the values to the obects we need to follow the syntax (objectname.propertyname = value;)
    s1.age = 29;
    s1.rollNumber = 420;
    
    //to print out the values also we follow the same syntax
    cout<<s1.age<<endl;
    cout<<s1.rollNumber<<endl;
    
    //to set the value for the objects that are initialized dynamically we use the following syntax [(*objectname).propertyname = value;]
    (*s6).age = 21;
    (*s6).rollNumber = 240;
    
    //other than that there is one more way in which we can initialize the value of the dynamically allocated objects [objectname -> propertyname = value;]
    s6 -> age = 24;
    s6 -> rollNumber = 240;
    
    //To print out also we can use any of the two syntaxes available
    cout<<(*s6).age<<endl;
    cout<<s6 -> rollNumber<<endl;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
///////////////// PROGRAM AND BIT OF THEORY REGARDING SETTING AND RETRIVING VALUES OF PRIVATE ATTRIBUTE OF A CLASS USING PUBLIC FUMCTION DEFINED OR DECLARED IN THE SAME CLASS
    
   
//Program is about accessing private properties using public function which is defined in the same class as the private property that it is trying to use

#include<iostream>
using namespace std;

class student{
    public :
    int age;
    
    private :
    int rollNumber;
    
    public :
    void display(){
        cout << age <<" "<<rollNumber<<endl;
    }
    
    //to access the private property rollNumber we can do so by creating a public function in the same class
    int getrollNumber(){
        return rollNumber;
    }
    
    //to set the value of a private property also we can have a publlic function defined in the same class
    
    void setrollNumber(int a){
        rollNumber = a;
    }
    
};

int main (){
    student s1;
    s1.age = 29;
    //so now we can get the value of a private property rollnumber using the public function getrollNumber
    cout<<"The rollnumber of s1 is :"<<s1.getrollNumber()<<endl;
    //so now we can set the value of a private property rollnumber using the public function setrollNumber
    s1.setrollNumber(420);
    
    //Below is the syntax to call a function if the object is created statically
    s1.display();
    
    
    student * s2 = new student ;
    //below is the 2 type of syntax to call a function when the object is created dynamicall
    (*s2).age =  21;
    (*s2).display();
    
    s2 -> age = 22;
    s2 -> display();
}

/////////// BUT THE BIG QUESTION IS WHEN WE CAN SOME HOW MANIPULATE THE PRIVATE VALUES WHAT IS THE USE OF HAVING THEM AND AMONG MANY REASON A FEW OF THEM ARE SHOWN BELOW

#include<iostream>
using namespace std;

class student{
    public :
    int age;
    
    private :
    int rollNumber;
    
//one of the use of having private property manipulated by public function is we can add certain constraints so that not all of them can change the value of that particular value    
    void setrollNumber(int a, int pass){

//here we have added the authentication constraint
        if(pass != 123){
            return ;
        }

//here we have added the constraint that the value cannot be negative        
        if(a < 0){
            return ;
        }
        rollNumber = a;
    }
    
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/////////////////////// CONCEPT AND PROGRAM REGARDING GONSTRUCTORS AND THIS KEYWORD
/////////// WE CAN USE CONSTRUCTORS TO AVOID THE DEFAULT GARBAGE VALUE BEING SET TO THE CONSTRUCTOR
    
    
//constructor are called only once while creation of object
//REMEMBER ONCE WE CREATE A CONSTRUCTOR OF ANYTYPE THE DEFAULT CONSTRUCTOR BECOMES INACTIVE SO IF WE WANT parameterized CONSTRUCTOR WE NEED TO ALSO HAVE DEFAULT CONSTRUCTOR EXPLICITLY DECLARED
#include<iostream>
using namespace std;

class student{
    public :
    
    int age;
    int rollnumber;
    
    //default constructor (once we create our own constructor the inbuilt constructor becomes inactive)
    student(){
        cout<<"constructor called"<<endl;
    }
    
    //parameterized constructor in the below case both the variable name is rollnumber and based on the closest scope the net value at the object calling the constructor becomes zero
    //Hence to overcome this problem we use THIS keyword and it stores the address of the current object another solution is to have a different name (and THIS is a pointer)
    student(int rollnumber){
        this -> rollnumber = rollnumber;
        cout<<"parameterized constructor called"<<endl;
    }
    
    student(int a, int r){
        age = a;
        rollnumber = r;
        cout<<"Parameterized constructor 2 called"<<endl;
    }
};
  
int main(){
    //what happens when we create a new object using the below syntax is (a default constructor is called and its syntax is [objectname.classname();] )
    //this constructor creates and allocates garbage value for the properties of that object
    //features of constructors --- same name as class, no return type, no input argument
    //whenever we create a class automatically the default constructor is called 
    student s1;
    
    //Parameterized constructor
    student s2(420);
    //REMEMBER THE SYNTAX TO CALL A CONSTRUCTOR IS SAME AS THAT OF CREATING A NEW OBJECT BUT THAT IS INTURN INTERPERETED IN THE WAY THAT IS MENTIONED ABOVE
    cout<<s2.rollnumber<<endl;
    
    //calling parameterized constructor2
    student * s3 = new student(29, 421);
    cout<<s3 -> age<<endl;
    cout<<(*s3).rollnumber<<endl;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
/////////////////// SOME MORE DEFAULT CONSTRUCTORS (COPY CONSTRUCTOR AND COPY ASSIGNMENT OPERATOR)
    
//DEFAULT CONSTRUCTORS
#include<iostream>
using namespace std;

class student{
    public :
    int age;
    int rollnumber;
    
    public :
    
    //since we have this constructor the default constructor is inactive hence all the objects should be initialized with 2 parameters
    student(int a , int r){
        age = a;
        rollnumber = r;
        cout<<"Parameterized constructor called "<<endl;
    }
    
    void display(){
        cout<<"age :"<<age<<" "<<"rollnumber :"<<rollnumber<<endl;
    }
    
    //copy constructor is a default constructor there is no need to declare it the syntax to use this constructor is (classname objectname(object from which things are copied))
};

int main(){
    student s1(29, 420);
    s1.display();
    
    //copy constructor is used
    student s2(s1);
    s2.display();
    
    //how to use copy constructor in case of dynamic allocation
    student *s3 = new student(229, 420);
    s3 -> display();
    student *s4 = new student(*s3);
    (*s4).display();
    
    //if we want to copy static object values into dynamic then the syntax is
    student *s5 = new student(s1);
    s5 -> display();
    
    //if we want it the other way around
    student s6(*s5);
    s6.display();
    
    //if we want to have the same value for two objects after creation of the object we can use the copy assignment operator 
    //remeber we cannot use constructors twice for any obect so use copy assignment operator insted of equating all the properties
    
    student s7(39, 560);
    s7.display();
    
    s7 = s1;
    s7.display();
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
/////////////////// ALL ABOUT DESTRUCTOR
    
#include<iostream>
using namespace std;

class student{
    public :
    
    int age;
    int rollnumber;
    
    //destructor has the properties as constructor
    //destructor dealocates the memeory of the objects 
    //destructor is differentiated from constructor using ~ symbol
    //destructor is called once at the last
    student(){
        cout<<"constructor called"<<endl;
    }
    ~student(){
        cout<<"destructor called"<<endl;
    }
};

int main(){
    student s1;
    //in case of dynamically allocated memeory destructor is not called untill we explicitly delete it
    student * s2 = new student();
    delete s2;    
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------






