#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	  int s,c;
	  cin>>s;
	  cin>>c;
	  int arr[101];
	  int last[101];
	  int i,j=s-1;
	  for(i=0;i<s;i++)
	      cin>>arr[i];
	  last[s-1]=arr[s-1];
	  int k,tra=0;
	  while(j!=0){
        k=j;
        for(tra=0;tra<k;tra++){
            arr[tra]=arr[tra+1]-arr[tra];
		  }
		  j--;
		  last[j]=arr[j];
	  }
	  last[0]=arr[0];
	   while(c--){
	    for(tra=0;tra<s-1;tra++){
	          last[tra+1]=last[tra]+last[tra+1];
		  }
		 cout<<last[s-1]<<" ";  
	   }
	  cout<<endl; 
	}
	return 0;
}