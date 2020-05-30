#include<bits/stdc++.h>
using namespace std;
typedef  int ii;
typedef vector < vector <ii > > matrix;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
int main(){
   int t;
   cin>>t;
   while(t--){
   	 ii n,i;
   	 cin>>n;
   	 ii a[31]={0};
      matrix p11(31,vector<ii>(31,0));
	 matrix p21(31,vector<ii>(31,0));
	 matrix p1(31,vector<ii>(31,0));
	 matrix p2(31,vector<ii>(31,0));
	 a[0]=0;
      for(i=1;i<=n;i++)
        cin>>a[i];
      ii j=n-1;
      i=0;
      ii l=0;
      for(i=1;i<=n;i++){
         p1[i][i]=a[i];
         p11[i][i]=a[i];
         p21[i][i]=0;
         p2[i][i]=0;
	 }
	 for(l=1;l<n;l++){
	  for(i=1;i<=n-l;i++){
	   j=i+l;
	    p1[i][j]=max(p1[i][i]+p2[i+1][j],p1[j][j]+p2[i][j-1]);
	    p2[i][j]=min(p2[i][i]+p1[i+1][j],p2[j][j]+p1[i][j-1]);
	    p11[i][j]=max(p11[i][i]+p21[i+1][j],p11[j][j]+p21[i][j-1]);
	    p21[i][j]=max(p21[i][i]+p11[i+1][j],p21[j][j]+p11[i][j-1]);
	  }
	 }
      cout<<p11[1][n]<<" "<<p1[1][n]<<endl;
   }
   return 0;
}
