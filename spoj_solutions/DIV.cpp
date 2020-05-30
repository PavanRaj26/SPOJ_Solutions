#include<bits/stdc++.h>

using namespace std;

vector<int> count1(1000001,0);
vector<int> v(1000001,0);
int main() {

		vector<int> res;
		v[0]=1;
		v[1]=0;
		int i,j;
		for(i=2;i<=1000000;i++)
		     v[i]=i;		
		for(i=2;i<=sqrt(1000000);i++) {
		
			if(v[i]==i) {
				   for(j=i+i;j<=1000000;j+=i) {
			
						
					if(v[j]==j)
					   v[j]=i;
				}
			
			}
			
		}
		for(i=2;i<=1000000;i++) {
		
			
				int key=v[i];
				int n=i;
				int count=1;
				int ans=1;
				//cout<<i<<endl;
				while(n%key==0) {
					  n=n/key;
					  count++;
				}
				ans=ans*count;
				if(n==1) {
					if(count1[ans]==1)
					    res.push_back(i);
					continue;
				}
				key=v[n];
				count=1;
				while(n%key==0) {
					n=n/key;
					count++;
				}
				ans=ans*count;
				if(n==1) {
				
					if(ans==4) 
					   count1[i]=1;
					if(count1[ans]==1)
				   	   res.push_back(i);
				}
		}
		for(i=8;i<res.size();i+=9)
		    cout<<res[i]<<endl;
		return 0;
}