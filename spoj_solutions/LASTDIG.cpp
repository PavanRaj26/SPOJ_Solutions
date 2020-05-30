#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(i=0;i<n;i++) 
typedef vector< vector<int > > matrix;
matrix v(10);
int main() {

        int i;
        int j;
        rep(i,10) {
        	int k=i;
        	v[i].push_back(0);
        	rep(j,4) {
        		v[i].push_back(k%10);
        		k=k*i;
        	}
        	v[i][0]=v[i][4];
        }
        int t;
        cin>>t;
        while(t--) {
        	int a,b;
        	cin>>a>>b;
        	if(b==0) cout<<1<<endl;
        	else
        	cout<<v[a%10][b%4]<<endl;
        }
	return 0; 			


}