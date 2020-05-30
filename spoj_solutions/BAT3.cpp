#include<bits/stdc++.h>

using namespace std;

int CalcLen(vector<int > &v,int n,int ul); 
int CeilIndex(vector<int > &tail,int high,int key);
int main() {
         
         int t;
         cin>>t;
         while(t--) {
	         int n;
	         int i,index,x;
	         cin>>n;
	         cin>>index;
	         vector<int > v(n,0);
	         for(i=0;i<n;i++) {
	               cin>>x;
	               v[i]=x;
		    }
	         vector<int> vback,vfront;
		    for(i=n-1;i>index;i--) 
	             vback.push_back(v[i]);
		    
		    for(i=index-1;i>=0;i--)
		        vfront.push_back(v[i]);
	         int len2=CalcLen(vback,n-index-1,-1);
	         int len3=CalcLen(vfront,index,v[index]);
              reverse(v.begin(),v.end());
              int len1=CalcLen(v,n,-1);
	         if(len2+len3+1>len1)
	            cout<<len2+len3+1<<endl;
	         else
	            cout<<len1<<endl;
	    }
         return 0;
}
int CalcLen(vector<int > &v,int n,int ul) {
     if(n==0)
       return 0;
        
        int length=1;
        vector<int> tail(n,0);
        int i=0;
        while(i<n&&v[i]<=ul)
           i++;
        if(i==n)
	      return 0;   
        tail[0]=v[i];
        int x=0;
        for( ;i<n;i++) {
        	  
		  if(v[i]<=ul)
        	    continue;
            if(v[i]<tail[0])
                tail[0]=v[i];
            else if(v[i]>tail[length-1])
                tail[length++]=v[i];
            else {
               x=CeilIndex(tail,length-1,v[i]);
               tail[x+1]=v[i];
		  }
                
	   }
	   return length; 
}
int CeilIndex(vector<int > &tail,int high,int key) {
	int low=0;
     int x;
     while(low<high) {
         x=low+(high-low+1)/2;
         if(tail[x]<=key)
            low=x;
         else
           high=x-1;
	}
	if(tail[low]==key)
	   low=low-1;
	return low;
}