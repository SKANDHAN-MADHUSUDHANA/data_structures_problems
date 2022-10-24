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
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<i;
        }
        cout<<endl;
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
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<j;
        }
        cout<<endl;
    }
}

// The pattern is

/*
4321
4321
4321
4321

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows "<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<(n-j+1);
        }
        cout<<endl;
    }
}

///////// Triangualar patterns
//The patter is
/*
*
**
***
****

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

//The patter is
/*
1
22
333
4444

for n = 4;
*/
#include<iostream>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<i;
        }
        cout<<endl;
    }
}


//The pattern is 
/*

1
12
123
1234

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows "<<endl;
    cin>>n;
    for(int i = 1; i <+ n; i++){
        for(int j = 1; j <+ n; j++){
            cout<<(n-j+1);
        }
        cout<<endl;
    }
}

//The pattern is
/*
1
23
345
4567

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++){
        int p = i ; // this is used to get the desired pattern
        for(int j = 1; j <= i; j++){
            cout<<p++;
        }
        cout<<endl;
    }
}

//The pattern is
/*
1
21
321
4321

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int p = i; //this is used to obtain the desired output
        for(int j = 1; j <= i; j++){
            cout<<p--;
        }
        cout<<endl;
    }
}

//The pattern is
/*
1
23
456
78910

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int p = 1;//this is used to get the desired pattern
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<p++<<" ";
        }
        cout<<endl;
    }
}



///////Charecter paterns

//The pattern is
/*
ABCD
ABCD
ABCD
ABCD

for n = 4;
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char a = 'A' + j - 1;
            cout<<a;
        }
        cout<<endl;
    }
}

//The pattern is
/*
ABCD
BCDE
CDEF
DEFG

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char a = 'A' + i + j - 2; // i is used to get the starting alphabet and j is used to increment through each row
            cout<<a;
        }
        cout<<endl;
    }
}

//The pattern is
/*
A
BC
CDE
DEFG

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n ;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            char a = 'A' + i + j - 2;
            cout<<a;
        }
        cout<<endl;
    }
}

//The pattern is
/*
A
BB
CCC
DDDD

for n = 4;
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            char a = 'A' + i - 1;
            cout<<a;
        }
        cout<<endl;
    }
}

//The pattern is
/*
D
CD
BCD
ABCD

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            char a = 'A' + n - i + j - 1 ;
            cout<<a;
        }
        cout<<endl;
    }
}

//The pattern is
/*
   *
  **
 ***
****

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j > n - i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

//The pattern is
/*
   1
  12
 123
1234

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        int p = 1; // this is used to obtain the required pattern
        for(int j = 1; j <= n; j++){
            if(j > n - i){
                cout<<p++;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

//The pattern is
/*
****
***
**
*

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}


//The pattern is
/*
1234
123
12
1

for n = 4;
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        int p = 1; // we need this to arrive at the desired result
        for(int j = 1; j <= n - i + 1; j++){
            cout<<p++;
        }
        cout<<endl;
    }
}
