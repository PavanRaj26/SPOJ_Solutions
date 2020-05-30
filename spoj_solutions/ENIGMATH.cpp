#include<bits/stdc++.h>
using namespace std;
int calgcd(int a,int b);
int main()
{
	int t;
	cin>>t;
	int i=0;
	for(i=0;i<t;i++){
	     int a,b;
	     cin>>a;
	     cin>>b;
	     int x=0,y=0;
	     if(b%a==0){
	        x=b/a;
			y=1;
		 }
		 else if(a%b==0)
		   {
		      x=1;
		      y=a/b;
		   }
		 else {
	       x=b/calgcd(a,b);
	       y=a/calgcd(a,b);
	}
	  cout<<x<<" "<<y;
	  cout<<endl; 
	}
	return 0;
}
int calgcd(int a,int b)
{
	 int temp=0;

	 if(b>a){
	    temp=a;
	    a=b;
	    b=temp;
	 }
	 int x=a%b;
     int rem=a%b;
	 while(rem!=0){
	     
		 rem=a%b;
	     a=b;
	     b=rem;
	     x=a;
	 }
	 return x;	
}