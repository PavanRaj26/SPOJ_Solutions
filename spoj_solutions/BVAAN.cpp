#include<bits/stdc++.h>

using namespace std;

typedef vector< vector< int > > matrix;
typedef vector< vector< char > > matrix1;
int _Apply(int i,int j,matrix1 &b,string &s1,vector<char> &s3,int k);
void _ApplyT(vector<char> &s4,int k,int &max1,int i,string &s1);
int main() {
    
          int t;
          cin>>t;
          while(t--) {
               
			string s1;
               string s2;              
               cin>>s1;
               cin>>s2;
			int i,j;
			int k;
			cin>>k;
               int len1=s1.size();
			int len2=s2.size();
			matrix lcs(len1+2,vector<int>(len2+2,0));       
			matrix1 b(len1+2,vector<char>(len2+2,'1'));
			int flag=0;
			int max1=-1;
			int len=0;
               vector<char > s3(k,0);
               vector<char> s4(k,0);
               int prev=-1;
			for(i=1;i<=len1;i++) {
			    
			      for(j=1;j<=len2;j++) {
			           
					 if(s1[i-1]==s2[j-1]) {
			           
					     lcs[i][j]=1+lcs[i-1][j-1];
					     b[i][j]='d';			               
					     if(lcs[i][j]==k) {
		                       
					        flag=1;
					        len=_Apply(i,j,b,s1,s3,k);
					        if(len>max1) {
					          max1=len;
					          for(int l=0;l<k;l++)
					             s4[l]=s3[l];
						   }
						}
						if(lcs[i][j]>k&&prev!=i) {
						  _ApplyT(s4,k,max1,i-1,s1);
						  prev=i;
						     
						}
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
		
			if(flag==0)
			  cout<<0<<endl;
			else
			  cout<<max1<<endl;
	}
		
          return 0;
}
int _Apply(int i,int j,matrix1 &b,string &s1,vector<char> &s3,int k) {

             int count=0;
             int len=k;
		             while(i>=1&&j>=1) {

		                   if(b[i][j]=='d') {
                                  s3[len-1]=s1[i-1];
                                  count=count+s1[i-1];
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
			return count;	   
}
void _ApplyT(vector<char> &s4,int k,int &max1,int i,string &s1) {

          int j=0;
          char min1='|';
          int index=0;
          for(j=0;j<k;j++)
             if(s4[j]<min1) {
                min1=s4[j];
                index=j;
		 }
		if(s1[i]>min1) {
	        
	        for(j=index;j<k-1;j++) 
	           s4[j]=s4[j+1];
		   s4[k-1]=s1[i];
		   int diff=s1[i]-min1;
		   max1=max1+diff;
		   return ;   
	     }
	     
	  return ;    
                
                 
}
