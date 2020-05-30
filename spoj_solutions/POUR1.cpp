#include<bits/stdc++.h>
using namespace std;
int calgcd(int a,int b);
int main()
{
	int t;
	cin>>t;
	while(t--){
	  int a,b,c;
	  int sum=0;
	  cin>>a;
	  cin>>b;
	  cin>>c;
	  int x=0;
	  int flag=0;
	  int sum1=0;
	  if(c==a||c==b){
	    flag=1;
	    cout<<"1\n";
	
	}
	  else if((c>a&&c>b)||(a==b&&a!=c)||(c<calgcd(a,b)||c%(calgcd(a,b))!=0)){
	  	  flag=1;
	      cout<<"-1\n";
	  }
	  else{
	  	if(c%a==0||c%b==0)
	  	   {
	  	   	  if(c%b==0)
	  	   	     sum1=2*(c/b)+1;
	  	   	  else
				 sum1=2*(c/a)+1;   
	  	   }
	 	   
	  	int a1=a;
	  	int b1=b;
	  	  if(a>=b){
	      while(a!=c){
	      	
	           if(a%b==c%b){
	                sum=1+2*(a-c)/b+sum;
	                a=c;
	                b=0;
			   }
			   else{
			      sum=1+2*(a/b)+sum;
			      x=(a%b);
			      a=a1-(b-x);
			      if(a==c){
			      	sum=sum+3;
			        break;
			    }
			      sum=sum+4;
			   }
	}
		if(sum>sum1&&sum1!=0)
		   sum=sum1;  
}
		  else{
		    while(b!=c){
	      	
	           if(b%a==c%a){
	                sum=1+2*(b-c)/a+sum;
	                b=c;
	                a=0;
			   }
			   else{
			      sum=1+2*(b/a)+sum;
			      x=(b%a);
			      b=b1-(a-x);
			        if(b==c){
			      	sum=sum+3;
			        break;
			    }
			      sum=sum+4;
			   }
		    }
		  if(sum>sum1&&sum1!=0)
		   sum=sum1;
		    
		  }
	}
	  
	  if(flag!=1)
	 cout<<sum-1<<endl;  
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
