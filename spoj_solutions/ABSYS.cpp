#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	fflush(stdin);
	while(t--){
	  string s;
	  char c;
	  string s1,s2,s3;
	  cin>>s1;
	  cin>>c;
	  cin>>s2;
	  cin>>c;
	  cin>>s3;
	  int flag1=0,flag2=0,flag3=0;
	  int i=0;
	  while(s1[i]!='\0')
	     if(s1[i++]=='m')
	        {
	        	flag1=1;
	        	break;
	        }
	        i=0;
	  if(flag1!=1)      
	  while(s2[i]!='\0')
	     if(s2[i++]=='m')
	        {
	        	flag2=1;
	        	break;
	        }
	   i=0;     
	  if(flag1!=1&&flag2!=1)      
	  while(s3[i]!='\0')
	     if(s3[i++]=='m')
	        {
	        	flag3=1;
	        	break;
	        }      
	 int a,b;
	 if(flag1==1){
	    a=atoi(&s3[0]);
	    b=atoi(&s2[0]);	
	   int x=a-b;
	   cout<<x<<" + "<<b<<" = "<<a<<endl;  
     }
	 else if(flag2==1){
	 	a=atoi(&s3[0]);
	    b=atoi(&s1[0]);
	 	int x=a-b;
	   cout<<b<<" + "<<x<<" = "<<a<<endl;
     }    
	 else if(flag3==1){
	 	a=atoi(&s2[0]);
	    b=atoi(&s1[0]);
		 int x=a+b;
	   cout<<b<<" + "<<a<<" = "<<x<<endl;
     }
     
	}
	
	return 0;
}
