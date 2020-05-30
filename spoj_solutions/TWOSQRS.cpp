#include<bits/stdc++.h>
using namespace std;
int _Know(long long int n);
int main()
{
	long long int t;
	cin>>t;
	while(t--){
	   long long int n;
	   cin>>n;
	   if(n%4==3)
	     cout<<"No"<<endl;
	   else {  
	     if(_Know(n))
	       cout<<"Yes"<<endl;
	     else
	       cout<<"No"<<endl;
	   }
	}
	return 0;
}
int _Know(long long int n)
{
	long long int ul,x,high,low,key,i;
	ul=sqrt(n); 
	for(i=0;i<=ul;i++){
	   key=n-i*i;
	   low=0;
	   high=ul;
	   while(low<=high){
	       x=low+(high-low)/2;
	       if(x*x<key)
	          low=x+1;
	       else if(x*x>key)
		    high=x-1;
		  else
		    return 1;   
	    }
	}
	return 0;  
}