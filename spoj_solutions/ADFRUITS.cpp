#include<bits/stdc++.h>

using namespace std;

typedef vector< vector< int > > matrix;
typedef vector< vector< char > > matrix1;
int main() {
    
          string s1;
          string s2;
          while(cin>>s1&&cin>>s2) {
              
               int i,j;
               int len1=s1.size();
			int len2=s2.size();
			matrix lcs(len1+2,vector<int>(len2+2,0));       
			matrix1 b(len1+2,vector<char>(len2+2,'1'));
			for(i=1;i<=len1;i++) {
			    
			      for(j=1;j<=len2;j++) {
			           
					 if(s1[i-1]==s2[j-1]) {
			           
					     lcs[i][j]=1+lcs[i-1][j-1];
					     b[i][j]='d';			               
					 }
			           else  {
				          if(lcs[i][j-1]>=lcs[i-1][j]) {
				              
						    lcs[i][j]=lcs[i][j-1];
				              b[i][j]='l';
					     }  
					     else {
					         
					         lcs[i][j]=lcs[i-1][j];
					         b[i][j]='u';
						}
				      }
				 }
			}
			i=len1;
			j=len2;
		
			int len=lcs[i][j];    
			int m=len;
			vector< pair<int,int > > v(len+1);
		             while(i>=1&&j>=1) {

		                   if(b[i][j]=='d') {
						    v[len].first=i-1;
		                   	    v[len].second=j-1;
		                   	    len--;
		                   	    i=i-1;
		                   	    j=j-1;
		                   }
		                   else if(b[i][j]=='l') {
		                   	    j=j-1; 
		                   }
		                   else {
		                   	    i=i-1;
		                   }
				   }
			int a=-1;
			int b1=-1;
			int k=1;
			int l;
			while(k<=m) {
			    i=a;
			    a=v[k].first;
			    for(l=i+1;l<a;l++)
			       cout<<s1[l];
			    j=b1;
			    b1=v[k].second;
			    for(l=j+1;l<b1;l++)
			       cout<<s2[l];
			    cout<<s1[v[k].first];
			    k++;
			    
			}
			for(l=a+1;l<len1;l++)
			   cout<<s1[l];
			for(l=b1+1;l<len2;l++)
			   cout<<s2[l];   
			cout<<endl;   
			
		}
          return 0;
}