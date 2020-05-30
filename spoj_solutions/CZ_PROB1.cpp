#include<bits/stdc++.h>

using namespace std;

typedef vector< vector<int > > matrix;
int main() {
   
   vector<int > v(8001,1);
   int i,j,k;
   for(i=2;i<=sqrt(8000);i++) {
      if(v[i]==1)
      for(j=2,k=j*i;k<=8000;) {
      	  
         if(v[k]==1)
            v[k]=0;
         j++;
	    k=i*j;   
	 }
   }
   int s=2;
   vector<int > a(550,0);
   a[1]=2;
   for(i=5;i<=8000&&s<=510;i++)
       if(v[i]==1&&i%4==1)
            a[s++]=i;
   matrix p(8001,vector<int>(4,0));
   p[0][3]=1;
   p[0][2]=1;
   p[0][1]=1;
   p[1][2]=1;
   p[1][3]=1;
   p[2][3]=2;   
   for(j=1;j<=8000;j++) {
      p[j][1]=p[j][0]+p[j-1][1]; 
   }
   for(j=2;j<=8000;j++) {
      p[j][2]=p[j][1]+p[j-2][2];
   }
   for(j=3;j<=8000;j++) {
      p[j][3]=p[j][2]+p[j-3][3];
   } 
   
   int t;
   cin>>t;
   while(t--) {
       int n,k;
       cin>>n;
       cin>>k;
       cout<<p[a[n]][k]<<endl;
   }
   return 0;
}