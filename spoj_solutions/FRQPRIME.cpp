#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
    long long int i,j;
	long long int v[100001]={0};
	v[0]=1;
	v[1]=1;
	for(i=2;i<317;i++)
	   for(j=2;j*i<=100000;j++)
	        if(v[i*j]==0)
	           v[i*j]=1;
   long long int count[100001]={0};
   count[0]=0;
   count[1]=0;
   for(i=2;i<=100000;i++)
       if(v[i]==0)
          count[i]=count[i-1]+1;
       else
	      count[i]=count[i-1];   
	while(t--){
	long long int n,k;
	cin>>n;
	cin>>k;
	if(k>=n)
	cout<<"0"<<endl;
	else if(n==2&&k<=1)
	cout<<"1"<<endl;
	else{
  long long int lb,low,high,subrange=0;
  long long int temp=0,x=0;
   for(lb=2;lb<=n-k+1;lb++){
      temp=0;
      low=lb;
      high=n;
	  if(v[lb]==0)
            temp=1;
            
      while(low<high){
         x=low+(high-low)/2;
         if(count[x]-count[lb]+temp>=k)
              high=x;
         else
           low=x+1;
	  }
	 if(count[low]-count[lb]+temp>=k) 
	 subrange=subrange+n-low+1; 
   }
   cout<<subrange<<endl;
}
}
   return 0;	           
}