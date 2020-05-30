#include<bits/stdc++.h>
using namespace std;
typedef  int ii;
int main()
{
	int t;
	cin>>t;
	while(t--){
	    ii E,i;
	    cin>>E;
	    ii n;
	    cin>>n;
	    ii arr1[n];
	    ii arr2[n];
	    vector < ii > S;
	    for(i=0;i<n;i++)
	       cin>>arr1[i];
	   for(i=0;i<n;i++)
	       cin>>arr2[i];
         S.push_back(0);
	     for(i=1;i<=E;i++){
	    S.push_back(0);
	    ii q,j;     
		  for(j=0;j<n;j++){
	       	if(arr1[j]>i)
	       	  continue;
	           q=arr2[j]+S[i-arr1[j]];
	           if(q>S[i])
	             S[i]=q;
		 }
	      
	    }
	    cout<<S[E]<<endl;   
	}
	return 0;
}