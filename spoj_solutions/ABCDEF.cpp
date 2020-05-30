#include<bits/stdc++.h>
using namespace std;
typedef long int ii;
int main()
{
	long int i=0,j=0,x,n;
    long int count=0;
	cin>>n;
	vector <ii > v;
	vector <ii > v1,v2;
	vector <ii > v3,v4;
	 for(i=0;i<n;i++){
	     cin>>x;	
	     v.push_back(x);
	  }
	 sort(v.begin(),v.end());
	 
	map <string,int > m1,m2;     
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	       v1.push_back(v[i]*v[j]); 
	for(i=0;i<n*n;i++)
	    for(j=0;j<n;j++){
		      x=v1[i]+v[j];
		     v2.push_back(x);
		  }
    for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
		   v3.push_back(v[i]+v[j]);
	for(i=0;i<n*n;i++)
	    for(j=0;j<n;j++)
	         if(v[j]!=0){
		      x=v[j]*v3[i];
		      v4.push_back(x);
		 }
	count=0;
	sort(v2.begin(),v2.end());
	sort(v4.begin(),v4.end());
	vector<long int>::iterator it1=v2.begin();
     vector<long int>::iterator it2=v4.begin();
     vector<long int>::iterator low,high;
     for(it1=v2.begin();it1!=v2.end();){
     	long int key=(*it1);
         if(binary_search(v4.begin(),v.end(),key)){       
		low=lower_bound(v2.begin(),v2.end(),key);
          high=upper_bound(v2.begin(),v2.end(),key);
          long int x=high-low;
          low=lower_bound(v4.begin(),v4.end(),key);
          high=upper_bound(v4.begin(),v4.end(),key);
          long int y=high-low;
          count=count+x*y;
          it1=it1+x;
     }
        else
         it1++;
    }
	cout<<count<<endl;
	return 0;
}