#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	   int n,k,i;
	   cin>>n>>k;
	   int arr[101];
	   int S[101];
	   int N[101];
	   
	   for(i=1;i<=k;i++)
	       cin>>arr[i];
        S[0]=0;
        N[0]=1;
	   for(i=1;i<=k;i++){
           if(arr[i]==-1)
              S[i]=100001;
           else
              S[i]=arr[i];
            N[i]=1;
	    }
        int j=0;      
       for(i=1;i<=k;i++){
            for( j=1;j<=i;j++){
            	if(arr[j]==-1)
            	  continue;
                if(arr[j]+S[i-j]<S[i]){
                   S[i]=S[i-j]+arr[j];
                   N[i]=1+N[i-j];
			 }
		  }
               
          }	
        if(N[k]>n||S[k]>=100001)
	     cout<<"-1"<<endl;
	   else
	     cout<<S[k]<<endl;	  
	    cin.clear(); 
	    
	}
	return 0;
}