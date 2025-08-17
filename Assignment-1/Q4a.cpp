#include <iostream>
using namespace std;

int main() {
   int n;
   int arr[100];
   cout<<"enter the size of array:";
   cin>>n;

   cout<<"enter the element of array:";
   for (int i=0; i<n; i++){
        cin>>arr[i];
   }

   for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
   }

   cout<<"reversed array is :";
        for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
   }

    return 0;
}