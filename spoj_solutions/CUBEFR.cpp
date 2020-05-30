#include<bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;

const int N=1000010;
vector<vector<int> > T(11,vector<int>(N));
int ans[N+10];
int p[N+10];
int main() {

        int i,j;
        p[1]=0;
        for(i=2;i<=100;i++) {
                  int val=i*i*i;
                  for(j=val;j<=N;j+=val) p[j]=1;
        }
        int s=1;
        for(i=1;i<N;i++)
           if(p[i]==0) {ans[i]=s;s++;}
        int t;
        cin>>t;
        for(j=1;j<=t;j++) {
        	int n;
        	cin>>n;
        	cout<<"Case "<<j<<": ";
        	if(ans[n]==0) cout<<"Not Cube Free"<<endl;
        	else cout<<ans[n]<<endl;

        }
	return 0; 			

}