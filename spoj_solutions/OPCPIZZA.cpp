#include<bits/stdc++.h>
using namespace std;
int _Bsearch(vector<int> &v,int low,int high,vector<int> &counter,int m);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
	int n,m,i;
	scanf("%d%d",&n,&m);
	  int arr[n];
	  for(i=0;i<n;i++)
	     scanf("%d",&arr[i]);
	 vector<int> v(arr,arr+n);
	 vector<int> counter(n,0);
	 int count=0;
	 sort(v.begin(),v.end());
	   for(i=0;i<n;i++){
            if(counter[i]!=1&&_Bsearch(v,i+1,n-1,counter,m-v[i]))
		     count=count+1;  
	  }
	  printf("%d\n",count);
	}
	
	return 0;
}
int _Bsearch(vector<int> &v,int low,int high,vector<int> &counter,int m)
{
	int mid;
	while(low<=high){
	    mid=low+(high-low)/2;
	    if(v[mid]>m)
	       high=mid-1;
	    else if(v[mid]<m)
	       low=mid+1;
	    else{
	       counter[mid]=1;
	       return 1;
	  }
	}
return 0;	
}