#include<bits/stdc++.h>

using namespace std;
typedef long long int ij;
int Function(pair<ij,ij> p1,pair<ij,ij> p2);
int Bsearch(vector<pair<ij,ij > > &v1,pair<ij,ij> &key,int high);
int True(pair<ij,ij > a,pair <ij,ij > b);
bool cmp(const pair<ij,ij> &a, const pair<ij,ij> &b)
{
    return Function(a,b);
}

int main() {

        
            int n;
            cin>>n;
            vector<pair<ij,ij > > v(n);
            int i;
            ij x,y;
            ij count=0;
		  for(i=0;i<n;i++) {
		   
		          cin>>x;
		          cin>>y;
		          v[i].first=x;
		          v[i].second=y;
		  }
		  for(i=0;i<n;i++) {
		  
                      vector<pair<ij,ij > > v1(n-1);		            
		            int s=0,j=0;
		            for(j=0;j<i;j++) {
				     
					v1[s].first=v[j].first-v[i].first; 
				     v1[s].second=v[j].second-v[i].second;
				     s++;
				  }
				  for(j=i+1;j<n;j++) {
                         
					v1[s].first=v[j].first-v[i].first; 
				     v1[s].second=v[j].second-v[i].second;
				     s++;			  
				  }
                      sort(v1.begin(),v1.end(),cmp);
				     
				     ij count1=0;
				     ij count2=0;
				  for(int ii=0;ii<n-1;ii++) {
			              
			              pair<ij,ij> key;
			              key.second=v1[ii].first;
			              key.first=-v1[ii].second;
			     	    if(v1[ii].first==0&&v1[ii].second!=0)
					         count1++;
					    else if(v1[ii].second==0&&v1[ii].first!=0)
					         count2++;
					    else if(Bsearch(v1,key,n-2)) {
			                 count++;			                 
			             }  
				  }
				  count=count+count1*count2;
		  }
	
            cout<<count<<endl;
            return 0;
}
int Function(pair<ij,ij> p1,pair<ij,ij> p2) {
    
      ij a=p1.first;
      ij b=p1.second;
      ij c=p2.first;
      ij d=p2.second;
      ij s1,s2;
      if (b < 0 || (b == 0 && a < 0))
      s1 = -1;
      else
	 s1=1; 
      if (d < 0 || (d == 0 && c < 0))
      s2 = -1;
      else
      s2=1;
      if(s1*s2*(a*d-b*c)<0)
          return 1;
      else
	     return 0;    
}
int Bsearch(vector<pair<ij,ij > > &v1,pair<ij,ij> &key,int high) {

     int x=0;
     int low=0;
     while(low<=high) {
        
        x=low+(high-low)/2;
        
           if(True(v1[x],key))
               return 1;
           else if(Function(v1[x],key))
               low=x+1;
           else
               high=x-1;
	}
	return 0;
}
int True(pair<ij,ij > a,pair <ij,ij > b) {
       
       if((a.first==b.first)&&(a.second==b.second))
           return 1;       
        return 0;   
}