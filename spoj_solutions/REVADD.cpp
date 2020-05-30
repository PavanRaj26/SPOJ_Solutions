#include<bits/stdc++.h>
using namespace std;
int main()
{
	int  t=500;
	cout<<"121"<<endl; 
	int i=0,j=0;
	for(i=1;i<t;i++)
	{
	    cout<<"11";
		for(j=0;j<i-1;j++)
		    cout<<"0";
		cout<<"11";
		cout<<endl;
		if(i%2==0)
		   {
		   	  cout<<"1";
		   	  for(j=0;j<i+1;j++)
		   	      cout<<"2";
		   	   cout<<"1";
		   	   cout<<endl;
		   }
			
	}
	return 0;
}