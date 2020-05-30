#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
	cin>>n;
	while(n){
		int count=0,i=0;
	   int arr[n];
	   for(i=0;i<n;i++)
	      cin>>arr[i];
	   sort(arr,arr+n);
	   int j=0,low,high,x;
	   for( i=0;i<n-1;i++){
	      j=i+1;
	     low=j+1;
	     while(j<=n-2){
	     	high=n-1;
	        while(low<high){
	            x=low+(high-low)/2;
	            if(arr[x]<=arr[i]+arr[j])
	               low=x+1;
	           else 
	              high=x;
			}
			if(low==high&&low==n-1)
			   if(arr[i]+arr[j]>=arr[low])
			       count=count-1;
			count=count+n-low;       
			j++;
		 }
	   }
	  cout<<count<<endl; 
	  cin>>n;
	}
	return 0;
}