#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	    long int n,k;
	   cin>>n;
	   cin>>k;
	   long  int i=0;
	   char line[n+1];
	   vector< long int> count(n+1,0);
	     count[0]=0;  
	     for(i=1;i<=n;i++)
	         cin>>line[i];
       for(i=1;i<=n;i++)
          if(line[i]=='1')
           count[i]=count[i-1]+1;
          else
		 count[i]=count[i-1]; 
		 long int sum=0,low,high,x;   
	if(k>count[n])
	  cout<<"0"<<endl;
	 else{	   
	   long int key;
	   for(i=1;i<=n;i++){
		key=count[i]+k;
		if(line[i]=='1')
		  key=key-1;
		low=i;
		high=n;  
		if(key>count[n]||(k==0&&line[i]=='1'))
		  continue;
          while(low<high){
              x=low+(high-low)/2;              
              if(count[x]<key)
                 low=x+1;
              else if(count[x]>=key)
			     high=x;   
		  }
		  vector<long int >::iterator a,b;
		  a=lower_bound(count.begin()+low,count.end(),count[low]);
		  b=upper_bound(count.begin()+low,count.end(),count[low]);       
	       sum=sum+b-a; 
	     }
       cout<<sum<<endl;
        }
	}
	return 0;
}