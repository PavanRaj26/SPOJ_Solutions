#include<bits/stdc++.h>
using namespace std;
typedef long long int ii;
typedef vector< vector< ii > > matrix;
int main() {
    int t;
    cin>>t;
    while(t--) {
    matrix T1(102,vector<ii>(102,0));
    matrix T2(102,vector<ii>(102,INT_MAX));
    string s;
    cin>>s;
    int i=0;
    int len=s.size();
    for(i=1;i<=len;i+=2) {
       T1[i][i]=s[i-1]-'0';
       T2[i][i]=s[i-1]-'0';
  }
    int l,k,j;
    ii q;
    for(l=2;l<=len/2+1;l++) {
     
         for(i=1;i<=len-2*(l-1);i+=2) {
              j=i+2*(l-1);
              for(k=i+1;k<=j-1;k+=2) {
                if(s[k-1]=='+') {
                   
			    q=T1[i][k-1]+T1[k+1][j];
                   if(q>T1[i][j])
                     T1[i][j]=q;
                   q=T2[i][k-1]+T2[k+1][j]; 
                   if(q<T2[i][j])
                     T2[i][j]=q;
 			    }
                else {
                   q=T1[i][k-1]*T1[k+1][j];
                   if(q>T1[i][j])
                     T1[i][j]=q;
                   q=T2[i][k-1]*T2[k+1][j]; 
                   if(q<T2[i][j])
                     T2[i][j]=q;
 			     
			    }
		     }
		          
          }
    }
    
    cout<<T1[1][len]<<" "<<T2[1][len]<<endl;
}
  return 0;
}