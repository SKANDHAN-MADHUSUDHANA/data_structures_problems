//////////////////// FIND THE LARGEST ELEMENT IN AN ARRAY
///// The below approach is by using a max variable

#include <iostream>
using namespace std;

int maximumArr(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    int ans = maximumArr(arr, n);
    cout<<"The maximum element in the array is :"<<ans<<endl;
}


///// The second approach is by sorting the array in increasing order and returning the last element (the sorting algorithm i have used is selection sort)

#include <iostream>
using namespace std;

int maximumArr(int arr[], int n){
    // selection sort used for sorting the array
    for(int i = 0; i < n-1; i++){
        int min = arr[i];
        int min_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<min){
                min = arr[j];
                min_index = j;
            }
        }
        if(min_index != i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
    return arr[n-1];
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    int ans = maximumArr(arr, n);
    cout<<"The maximum element in the array is :"<<ans<<endl;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
///////////////// TO FIND THE SECOND LARGEST ELEMENT IN THE ARRAY
//////// we can find any element in the array if the array is sorted but make sure that the array has no duplicate elements below is the program for this particualar approach
  
#include <iostream>
using namespace std;

int secondMaximumArr(int arr[], int n){
    // selection sort used for sorting the array
    if(n==1){
        return -1;
    }
    for(int i = 0; i < n-1; i++){
        int min = arr[i];
        int min_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<min){
                min = arr[j];
                min_index = j;
            }
        }
        if(min_index != i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
    return arr[n-2];
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    cout<<"Make sure that there are no duplicate elements int the array"<<endl;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    int ans = secondMaximumArr(arr, n);
    (ans==-1)?cout<<"There is only one element in the array so cannot find the required ans" << endl :cout<<"The second largest element in the array is :"<<ans<<endl;
}

////// we can get any elements using the below approach

#include<bits/stdc++.h>
using namespace std;
void getElements(int arr[],int n)
{
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
    sort(arr,arr+n);
    int small=arr[1];
    int large=arr[n-2];
    cout<<"Second smallest is "<<small<<endl;
    cout<<"Second largest is "<<large<<endl;
}
int main()
{
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    return 0;
}

///////// In order to overcome the problem of not having duplicate elements and to elemenate the requirement of sorting we use another approach where we scan through the array twice and use two variables and get the solution

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int secondlargestArr(int arr[], int n){
    if(n==1){
        return -1;
    }
    // INT_MIN initializes the minimum value for a variable type which is int in this case and the value is -2147483647
    //remeber to include #include <bits/stdc++.h> header when we use this particular initialization 
    int largest = INT_MIN;
    int secondlargest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    
    for(int j = 1; j < n; j++){
        if(arr[j]<largest && arr[j]>secondlargest){
            secondlargest = arr[j];
        }
    }
    return secondlargest;
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    cout<<"Make sure that there are no duplicate elements int the array"<<endl;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    int ans = secondlargestArr(arr, n);
    (ans==-1)?cout<<"There is only one element in the array so cannot find the required ans" << endl :cout<<"The second largest element in the array is :"<<ans<<endl;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
////////////////////////// TO CHECK IF THE GIVEN ARRAY IS SORTED 
////// The solution given below is for ascending(increasing order) the same solution with the change in the conditon holds for decreasing order
    
#include <bits/stdc++.h>
using namespace std;

int isSorted(int arr[], int n){
    
    for(int i = 0; i < n-1; i++){
        // for decreasing change the below condition to if(arr[i]<arr[i+1])
        if(arr[i]>arr[i+1]){
            return -1;
        }
    }
    return 1;
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    int ans = isSorted(arr, n);
    (ans==-1)?cout<<"The given array is not sorted" << endl :cout<<"The given array is sorted"<<endl;
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

////////////////////////// TO FIND THE TOTAL NUMBER OF UNIQUE ELEMENTS IN THE ARRAY AND PLACING THEM IN THE STARTING PART OF THE ARRAY AND RETURNING THE TOTAL NUMBER OF UNIQUE NUMBER OF ELEMENTS IN THE ARRAY

#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int removeDuplicates(int arr[], int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[j]!=arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    cout<<"Array before removing duplicates :";
    printarr(arr,n);
    
    int ans = removeDuplicates(arr, n);
    
    cout<<"The total no of unique elements in the array are :"<<ans<< endl ;
    
    cout<<"Array after removing duplicates :";
    printarr(arr,ans);
    
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//////////////////////// LEFT ROTATE ARRAY BY ONE POSITION

    
#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void leftRotate(int arr[], int n){
    if(n==1||n==0){
        cout<<"The array is tooo small to rotate"<<endl;
        return;
    }
    int temp = arr[0];
    int i;
    for(i = 0; i < n - 1; i++){
        arr[i]=arr[i+1];
    }
    arr[i]=temp;
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    cout<<"Array before rotating :";
    printarr(arr,n);
    
    leftRotate(arr, n);
    
    cout<<"Array after rotating :";
    printarr(arr,n);
    
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//////////////////////////// ROTATING AN ARRAY KEY TIMES TOWARDS RIGHT DIRECTION
    
#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void leftRotateNtimes(int arr[], int n, int key){
    if(n==1||n==0){
        cout<<"The array is tooo small to rotate"<<endl;
        return;
    }
    for(int j = key; j > 0; j--){
    int temp = arr[n-1];
    int i;
    for(i = n-1; i > 0 ; i--){
        arr[i]=arr[i-1];
    }
    arr[i]=temp;
 }
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    cout<<"Array before rotating :";
    printarr(arr,n);
    
    int key;
    cout<<"Enter the number of times you want to ratate the above array :"<<endl;
    cin>>key;
    
    leftRotateNtimes(arr, n , key);
    
    cout<<"Array after rotating :";
    printarr(arr,n);
    
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/////////////////////////   MOVE ALL ZEROS TO THE END OF THE ARRAY

#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void moveAllZerosToEnd(int arr[], int n){
    int temp[n];
    int k = 0;
    for (int i = 0; i < n; i++){
        if(arr[i]!=0){
            temp[k++]=arr[i];
        }
    }
    while(k<n){
        temp[k++]=0;
    }
    
    k = 0;
    
    for(int l = 0 ; l < n ; l++){
        arr[l]=temp[k++];
    }
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    cout<<"Array before moving :";
    printarr(arr,n);
    
    moveAllZerosToEnd(arr, n);
    
    cout<<"Array after moving :";
    printarr(arr,n);
    
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
///////////////////////////// LENEAR SEARCH (SEARCHING FOR ELEMENTS IN THE ARRAY BY TRAVERSING LEMEARLY)
    
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i]==key){
            return i;
        }
    }    
    return -1;
}

int main(){
    int n;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    int key;
    cout<<"Enter the element u want to search :"<<endl;
    cin>>key;
    
    int ans = linearSearch(arr, n, key);
    if(ans == -1){
        cout<<"The element you are searching for is not present in the array"<<endl;
    }
    else{
        cout<<"The element you are searching for is present in the :"<<ans<<endl;
    }
    
}

---------------------------------------------------------------------------------------------------------------------------------------------------------------------
/////////////////////////// UNINON OF TWO SORTED ARRAY AND THERE ARE NO DUPLICATES IN THAT PARTICULAR ARRAY

#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void unionOfTwoArrays(int arr1[], int arr2[], int n, int m){
    int i=0, j=0;
    while(i<n && j<n){
        if(arr1[i]<arr2[j]){
            cout<<arr1[i++]<<" ";
        }
        else if(arr2[j]<arr1[i]){
            cout<<arr2[j++]<<" ";
        }
        else{
            cout<<arr2[j++]<<" ";
            i++;
        }
    }
    
    while(i<n){
        cout<<arr1[i++]<<" ";
    }
    
    while(j<m){
        cout<<arr2[j++]<<" ";
    }
    
}

int main(){
    int n;
    int arr1[100];
    cout<<"Enter the size of the first array (Make sure its less than 100)"<<endl;
    cin>>n;
    cout<<"Enter the elements of the first array (make sure that it is in increasing sorted order and no duplicate elements)"<<endl;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr1[i];
    }
    
    int m;
    int arr2[100];
    cout<<"Enter the size of the second array (Make sure its less than 100)"<<endl;
    cin>>m;
    cout<<"Enter the elements of the second array (make sure that it is in increasing sorted order and no duplicate elements)"<<endl;
    for(int i = 0; i < m; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr2[i];
    }
    
    unionOfTwoArrays(arr1, arr2, n, m);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
////////////////////////////////// INTERSECTION OF TWO SORTED ARRAYS

#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void intersectionOfTwoArrays(int arr1[], int arr2[], int n, int m){
    int i=0, j=0;
    while(i<n && j<n){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            cout<<arr2[j++]<<" ";
            i++;
        }
    }
}

int main(){
    int n;
    int arr1[100];
    cout<<"Enter the size of the first array (Make sure its less than 100)"<<endl;
    cin>>n;
    cout<<"Enter the elements of the first array (make sure that it is in increasing sorted order )"<<endl;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr1[i];
    }
    
    int m;
    int arr2[100];
    cout<<"Enter the size of the second array (Make sure its less than 100)"<<endl;
    cin>>m;
    cout<<"Enter the elements of the second array (make sure that it is in increasing sorted order )"<<endl;
    for(int i = 0; i < m; i++){
        cout<<"Enter the element to be inserted at postion :"<<i+1<<endl;
        cin>>arr2[i];
    }
    
    intersectionOfTwoArrays(arr1, arr2, n, m);
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
///////////////////////////// TO FIND THE REPEATED AND MISSING ELEMENT IN THE GIVEN INPUT RANGE [1-N] OF A GIVEN ARRAY OF SIZE N
    
#include<iostream>
using namespace std;

void repeatingNmissing(int arr[], int n){
    int temp[n+1];
    
    for(int i = 0; i <= n; i++){
        temp[i]=0;
    }
    
    for(int i = 0; i < n; i++){
        temp[arr[i] - 1] += 1;
    }
    
    int missing,repeated;
    for(int i = 0; i < n; i++){
        if(temp[i]==0){
            missing = i + 1;
        }
        if(temp[i]>1){
            repeated = i + 1;
        }
    }
    
    cout<<"The missing element is :"<<missing<<endl;
    cout<<"The repeated element is :"<<repeated<<endl;
}

int main(){
    int n ;
    int arr[100];
    cout<<"Enter the size of the array (Make sure its less than 100)"<<endl;
    cin>>n;
    
    cout<<"Enter the elements of the array in the range (1 - n) and any one of the number can appear more than once "<<endl;
    for(int i = 0; i < n; i++){
        cout<<"Enter the element to be inserted at position :"<<i+1<<endl;
        cin>>arr[i];
    }
    
    repeatingNmissing(arr, n);
}














