#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int j=0;
	for(j=0;j<t;j++){
	    long int len=0,i=0;
	    cin>>len;
	    char s[len+10];
	    char snext[len+10];
	    cin>>s;
	    long int queries,etapalin=0;
	    cin>>queries;
	    for(i=0;i<len/2;i++)
	    {
	    	if(s[i]!=s[len-i-1])
	    	    etapalin++;
	    	 snext[i]=s[len-i-1];
	    	 snext[len-i-1]=s[i];    		
	    }
	    cout<<"Case "<<j+1<<":"<<endl;
	    while(queries--){
	         long int  i;
	         char x;
	         cin>>i;
	         cin>>x;
	         i=i-1;
	         if(i!=len/2||len%2==0){	   
	         if(s[i]==s[len-i-1]){
	               if(snext[i]!=x)
	                 etapalin++;
		       }
			 else if(snext[i]==x)
			 	     etapalin--;
		}
		     s[i]=x;
	         snext[len-i-1]=x;	 	 
		if(etapalin==0)
		     cout<<"YES"<<endl;
		else
		     cout<<"NO"<<endl;	 	 
		}
	}
	return 0;
}