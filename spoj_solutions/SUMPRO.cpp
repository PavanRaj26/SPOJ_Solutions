#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
	int t;
	cin>>t;
	while(t--){
	   long long int n,x;
	   cin>>n;
	   x=sqrt(n);
	   long long int arr[x+1];
	  long long int i=0,sum=0,k;
	   for(i=1;i<=x;i++){
	       arr[i]=n/i;
	       sum=(sum+i*(n/i))%M;
	  }
	
	for(i=1;i<x;i++)
	   {
	   	n=arr[i];
	   	k=arr[i]-arr[i+1];
	      sum=(sum+i*((2*n*k-k*k+k)/2))%M;
	   }
	   n=arr[x];
      k=arr[x]-x;
      sum=(sum+x*((2*n*k-k*k+k)/2))%M;
      cout<<sum<<endl;
}
	return 0;
}