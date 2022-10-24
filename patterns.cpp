// This partucualar pattern is quiet simple . it printsout a square of stars with side equal to n

//using while loop

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;
    int i = 1;
    while(i <= n){
        for(int j = 0; j < n; j++){
            cout<<"*";
        }
        cout<<endl;
        i++;
    } 
}

//using only for loops

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<"*";
        }
        cout<<endl;
    } 
}

//same as the aboove pattern but it prints n instead of stars

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<n;
        }
        cout<<endl;
    } 
}
