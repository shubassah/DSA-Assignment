#include<iostream>
using namespace std;

int binarysearch(int arr[],int n, int key){
    int s=0;
    int e=n;
    while(s<=n){
        int mid=(s+e)/2;

        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }

    }
    return -1;
}

int main(){
    int arrr[100], n , key;

    cout<<"\n enter the size of array:";
    cin>>n;

    cout<<"\n enter the element of array:";
    for(int i=0; i<n; i++){
        cin>>arrr[i];
    }

    cout<<"\n enter the element to search:";
    cin>>key;

    cout<<"\nthe element found is:"<<binarysearch(arrr, n, key);

    return 0;
}