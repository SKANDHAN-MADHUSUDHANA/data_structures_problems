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


// the pattern is
/*
1111
2222
3333
4444

for n = 4
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows "<<endl;
    cin>>n;
    int p = 1; // this is used for getting the desired pattern
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<p;
        }
        cout<<endl;
        p++;
    }
}


// The pattern is 
/* 

1234
1234
1234
1234

for n = 4
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows "<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            cout<<j;
        }
        cout<<endl;
    }
}
