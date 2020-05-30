#include<bits/stdc++.h>
using namespace std;
int calgcd(int a,int b);
int main()
{
	int t;
	cin>>t;
	int i;
	for(i=0;i<t;i++){
		
	int a,b,c;
	 cin>>a;
	 cin>>b;
	 cin>>c;
      if(c%calgcd(a,b)==0)
           cout<<"Case "<<i+1<<": Yes"<<endl;
      else
	       cout<<"Case "<<i+1<<": No"<<endl;
	}
	return 0;
}
int calgcd(int a,int b)
{
	int x=0;
    if(a>b)
       {
       	x=a;
       	a=b;
       	b=x;
       }
	int rem=a%b;
	x=b;
	while(rem!=0){
	    rem=a%b;
	    a=b;
		b=rem;
	    x=a;
	}
	return x;
}