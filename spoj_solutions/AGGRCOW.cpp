#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	long int n,c,i=0,x;
	cin>>n;
	cin>>c;
	vector <long int > v;
	for(i=0;i<n;i++){
	cin>>x;	
	v.push_back(x);
    }
    sort(v.begin(),v.end());
    long int min,max,low,high;
    low=min=v[1]-v[0];
    high=max=v[n-1]-v[0];
    while(low<high){
     x=low+(high-low+1)/2;	
     long int currload=0,required=1;
     
      for(i=n-2;i>=0;i--)
         {  
              if(currload+v[i+1]-v[i]<x)
                 currload=currload+v[i+1]-v[i];
              else{
		        ++required;
		        currload=0;
		     }
         	 
      }
       if(required>=c)
           low=x;
       else
	       high=x-1;    
          
   }
   cout<<low<<endl;
}
	return 0;
}