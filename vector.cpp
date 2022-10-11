//vector intro

#include<iostream>
#include<vector> //needs to be included to use the vectors
using namespace std;

//push_back checks if there is enough space left to add new element and checks if there is requirement to double the size of vector
//So make sure to use push_back for insertion to change or retrive the elements we can use array operations
//if we insert using push_back after inserting using array operation the array opertaions are ignored
int main(){
    //vector<int> * vp = new vector<int>(); //dynamic allocation
    vector<int> v; //statically created
    v.push_back(10); //vector insertion 
    v.push_back(20); //remember the insertion is done from the rear end
    v.push_back(30);
    
    v[1] = 100; //changing the already present element can be done using array operations
    
    v.push_back(40);
    
    cout<<v[0]<<endl; //retrive the values
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v.at(3)<<endl; //alternative to the above array method
    // the advantage of this method it gives error insted of garbage value in the case of array operation
    cout<<v.size()<<endl;//prints out the size of the array 
    cout<<v.capacity()<<endl; //this gives the total array capacity
    
    //to delete the last elements
    v.pop_back();
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    
    
}
