#include<bits/stdc++.h>
using namespace std;
#define min(a,b) (a>b?b:a)
int main()
{
   string s;
  	int t=1;
     cin>>s;
 	while(s[0]!='-'){
	int i=0,count=0,len=s.size();
	char a[]={'{','{','}','}'};
	char b[]={'{','}','{','}'};
	int dp[2001];
	dp[0]=0;
	if(s[0]!=b[0])
	    count++;
	if(s[1]!=b[1])
	    count++;      
     dp[1]=count;
     int j=2,extra=2001,k,x;
	for(j=2;j<=len-1;j+=2){
         int fi=0,se=0,b1=0;
	    extra=2001;
         x=0;
	    i=j/2+1;
         k=i-2;
         while(k){
            if(dp[i-1]==dp[k]){
                x=k;
      	 }
	    k--;
	 }
          if(x!=0){
          	
	        	 k=x;
	        	  x=(x-1)*2;
                 if(s[x]!=a[0])
                   fi++;
                 if(s[x+1]!=a[1])
                   fi++;
	            if(s[j]!=a[2])
                    fi++;
	            if(s[j+1]!=a[3])
                    fi++;  
                 if(s[x]!=b[0])
                    se++;
                 if(s[x+1]!=b[1])
                    se++;
	            if(s[j]!=b[2])
                    se++;
	            if(s[j+1]!=b[3])
                    se++;  
	            extra=dp[k-1]+min(fi,se);
            }
           fi=0;
		 se=0;
		 b1=0; 
         if(s[j-2]!=a[0])
           fi++;
         if(s[j-1]!=a[1])
           fi++;
	    if(s[j]!=a[2])
           fi++;
	    if(s[j+1]!=a[3])
           fi++;  
         if(s[j-2]!=b[0])
           se++;
         if(s[j-1]!=b[1])
           se++;
	    if(s[j]!=b[2]){
           se++;
           b1++;    
      }
	    if(s[j+1]!=b[3]){
           se++;  
           b1++;
	 }
         int minimum=min(fi,se);   
         int x=dp[i-2]+minimum;
         int y=dp[i-1]+b1;
         minimum=min(min(x,y),extra);
         dp[i]=minimum;
         
    }
    cout<<t<<"."<<" "<<dp[len/2]<<endl;
    t++;
    cin.ignore();
    cin>>s;
     	}
	return 0;
}