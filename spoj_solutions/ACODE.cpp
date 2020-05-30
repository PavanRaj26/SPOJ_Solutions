#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;
	while(a[0]!='0'){
	long long int i,s=1,d=0,x;
	   for(i=1;i<a.size();i++){
	   	if(a[i]==48){
		      if(a[i-1]==49||a[i-1]==50){
		       d=s;
		       s=0;
		      }
		      else{
	           d=0;
	           s=0;
	           break;
	          }
	        }
		   x=s;
		   s=s+d;
            if(a[i-1]>50||a[i-1]==48)
		    {
	           
			 d=0;
	           continue;
	         }
	        if(a[i]>54&&a[i-1]>=50){
	           
		   	 d=0;
		   }
	        else
	           d=x; 
	       
	   }
	   cout<<s+d<<endl;       
	cin>>a;
	}
	return 0;
}
