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
