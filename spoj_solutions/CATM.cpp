#include<bits/stdc++.h>
using namespace std;
typedef  vector< vector < char > > matrix;
int main(){
	int n,m;
	cin>>n;
	cin>>m;
	int t;
	cin>>t;
	while(t--){
	  int mx,my,c1x,c1y,c2x,c2y;
	  cin>>mx;
	  cin>>my;
	  cin>>c1x;
	  cin>>c1y;
	  cin>>c2x;
	  cin>>c2y;
	  if(mx==c1x&&my==c1y||mx==c2x&&my==c2y)
	     cout<<"NO"<<endl;
	  else if(c1x>=mx&&c2x>=mx||c1x<=mx&&c2x<=mx)
	     cout<<"YES"<<endl;
	  else if(c1y>=my&&c2y>=my||c1y<=my&&c2y<=my)
	     cout<<"YES"<<endl;
	  else if(mx==n||mx==1||my==1||my==m)
	     cout<<"YES"<<endl;
	  else if((c1x-c1y==c2x-c2y&&c2x-c2y==mx-my)||(c1x+c1y==c2x+c2y&&c2x+c2y==mx+my))
	     cout<<"NO"<<endl;   
	     
	}
   return 0;
}
