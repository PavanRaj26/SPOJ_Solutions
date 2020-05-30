#include<bits/stdc++.h>
using namespace std;
#define max(a,b) (a>b?a:b)
int main()
{
    long int n1;
    cin>>n1;
   while(n1){
    long int i,n2;
    long int arra[20002]={0};  
    long int arrb[20002]={0};
    long int sum1[n1+1],arr1[n1];
   for(i=0;i<n1;i++)
         cin>>arr1[i];
         cin>>n2;
    
    long int sum2[n2+1],arr2[n2];
   for(i=0;i<n2;i++)
        cin>>arr2[i];      
   for(i=0;i<n1;i++)
        arra[arr1[i]+10001]=i+1;
  for(i=0;i<n2;i++)
        arrb[arr2[i]+10001]=i+1;	    
   sum1[0]=0;
   sum1[1]=arr1[0];
   for(i=2;i<=n1;i++)
     sum1[i]=sum1[i-1]+arr1[i-1];
     sum2[0]=0;
	sum2[1]=arr2[0]; 
   for(i=2;i<=n2;i++)
      sum2[i]=sum2[i-1]+arr2[i-1];
   long int x=0,y=0,prevx=0,prevy=0,sum=0;   
   for(i=0;i<n1;i++)
     {  
           
           if(arra[arr1[i]+10001]>0&&arrb[arr1[i]+10001]>0)
              {
                 x=arra[arr1[i]+10001];
		       y=arrb[arr1[i]+10001];
		       sum=sum+max(sum1[x]-sum1[prevx],sum2[y]-sum2[prevy]);
		       prevx=x;
		       prevy=y;
		    }
}
  if(i==n1)
    sum=sum+max(sum1[n1]-sum1[prevx],sum2[n2]-sum2[prevy]);  
  cout<<sum<<endl;
   cin>>n1;
  }
  return 0;
}