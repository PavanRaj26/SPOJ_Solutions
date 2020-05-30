#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	   string s;
	   cin>>s;
	   int i,n=s.size();
	   int arr[n+5];
	   int sum[n+5];
	   int countk=0;
	   for(i=0;i<n;i++){
	      arr[i]=0;
	      sum[i]=0;
	 }
	   int k=1,loop=0;
	   for(int j=0;j<n;j++){
	     if(s[j]!='K'&&s[j]!='E')
	       continue;
	     else if(s[j]=='E')
	       loop++;
	     else if(s[j]=='K'){
	       arr[k]=arr[k-1]+countk*loop;
	       countk=countk+1;
	       loop=0;
	       sum[k]=sum[k-1]+arr[k];
	       k++;
	     }
	   }
	      
	      cout<<sum[k-1]<<endl;
	}
	return 0;
}