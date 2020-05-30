#include<bits/stdc++.h>
using namespace std;
int _BST(int arr1[],int low,int high,int tar);
int main()
{
	int n,k,i;
	cin>>n;
	cin>>k;
	int arr[n];
	int count=0;
	for(i=0;i<n;i++)
	    cin>>arr[i];
	sort(arr,arr+n);
	for(i=0;i<n-1;i++)
	   count=count+_BST(arr,i+1,n-1,arr[i]+k);
	   cout<<count<<endl;
	return 0;
}
int _BST(int arr1[],int low,int high,int tar)
{
     int i=low;
     int x=0;
 	while(low<=high){
	  x=low+(high-low)/2;
	  if(arr1[x]<tar)
	      low=x+1;
	  else if(arr1[x]>tar)
	      high=x-1;
	  else{
	     return 1;
	 }
	}
	return 0;
}