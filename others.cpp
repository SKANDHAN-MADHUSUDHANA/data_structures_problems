//this file has some of the important concepts like templates vectors etc


//the below program has the implementation of tamplates
//and it also has object nesting using templates
//that is an object inside a particular part other object
//using the class pairs to implement triplets

#include<iostream>
using namespace std;

template <typename T, typename V>
class Pairs
{
    T x;
    V y;
    
    public:
    
    void setX(T x)
    {
        this -> x = x;
    }
    
    T getX()
    {
        return x;
    }
    
    void setY(V y)
    {
        this -> y = y;
    }
    
    V getY()
    {
        return y;
    }
};

int main()
{
    Pairs<int , char> p;
    p.setX(10);
    p.setY('a');
    
    cout<<p.getX()<<" "<<p.getY()<<endl;
    //creating triplet
    Pairs<Pairs<int,int>,int> p1;
    p1.setY(10);
    cout<<p1.getY()<<endl;
  //creating an object that is inserted inside X of the privious object
    Pairs<int , int> p4;
    p4.setX(11);
    p4.setY(12);
    p1.setX(p4);
    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY()<<endl;
    
}
