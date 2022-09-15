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





