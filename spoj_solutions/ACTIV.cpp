#include<bits/stdc++.h>
using namespace std;
typedef long long int ii;
void Bsearch(int low,int n,vector< pair<ii,ii> > &v,vector<ii > &store,vector<ii> &B);
int calc(ii a);
#define M 100000000
int main()
{
	int n;
	cin>>n;
	while(n!=-1){
	  ii x,y;
	  int i;
	  ii count=0;
	  vector< pair <ii,ii > > v;
	  for(i=0;i<n;i++){
	    cin>>x;
         cin>>y;
         v.push_back(make_pair(x,y));
}
       
       vector<ii > store(100001,1);   
       vector<ii> B(100001,0);
       sort(v.begin(),v.end());  
	  B[n-1]=1; 
	    for(int i=n-2;i>=0;i--){
	      Bsearch(i,n,v,store,B);
	      B[i]=(store[i]+B[i+1])%M;
	 }
	   
	    int dig=calc(B[0]);
	    for(i=0;i<8-dig;i++)
	      cout<<"0";
	    cout<<B[0]<<endl;
	    cin>>n;
	}
}
void Bsearch(int low,int n,vector< pair<ii,ii> > &v,vector<ii > &store,vector<ii> &B)
{
	   int j=low;
        ii key=v[low].second;
	   low=low+1;	  
        int high=n-1,x;
	   while(low<high){
	     x=low+(high-low)/2;
	     if(v[x].first>=key)
	       high=x;
	     else
	       low=x+1;
	   }
	   if(v[j].second>v[low].first)
	      store[j]=store[low];  
	   else
           store[j]=(store[j]+B[low])%M;
}
int calc(ii a){
  int k=a;
  int cot=0;
  while(k){
    cot++;
    k=k/10;
  }
  return cot;
}