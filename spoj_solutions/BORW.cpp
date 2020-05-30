#include<bits/stdc++.h>

using namespace std;

int LIS1(vector<int > &v,vector<int > &counter,int n);
int LIS(vector<int > &v,vector<int > &counter,int n,vector<int > &pi);
int Check(vector<int > &a,vector<int> &b,int n);
int main() {

	   int n;
        cin>>n;
        while(n!=-1) {
	            
                 int i,x;
                 vector<int> v(n,0);
                 vector<int> v1(n,0);
                 vector<int> counter1(n,0);
                 vector<int> counter3(n,0);
			  vector<int> counter2(n,0);
	            vector<int> counter4(n,0);
			  vector<int> pi(n,0);        
			  vector<int> pi2(n,0);
                 for(i=0;i<n;i++) {
                      cin>>x;
                      v[i]=x;
	            }
	            //reversing
	            for(i=n-1;i>=0;i--)
	                 v1[n-i-1]=v[i];
	            //1
	            int len1=LIS(v,counter1,n,pi);
     	       for(i=0;i<n;i++)
	                 counter3[i]=counter1[i];
	            reverse(counter1.begin(),counter1.end());
	            //2
	            int len2=LIS1(v1,counter1,n);
	            int max1=len1+len2;
	            //3
	            int len3=LIS(v1,counter2,n,pi2); 
	            reverse(counter2.begin(),counter2.end());
	            for(i=0;i<n;i++)
	               counter4[i]=counter2[i];
	            //4
	            int len4=LIS1(v,counter2,n);
	            int max2=len3+len4;
	            int temp=Check(counter3,counter4,n);
	            int flag=0;
	            if(temp!=-1){
	                
				  int lentemp=0;
	                 counter3[temp]=0;
	                 for(i=temp+1;i<n;i++) {
	                      if(pi[i]==pi[temp]&&counter3[i]==0) {
	                           
					       counter3[i]=1;
	                           reverse(counter3.begin(),counter3.end());
	                           lentemp= LIS1(v1,counter3,n);
						  if(lentemp+len1>max1&&lentemp+len1>max2) {
						      flag=1;
						      cout<<n-(lentemp+len1)<<endl;    
						      break;
					       }
					       else {
					           reverse(counter3.begin(),counter3.end());
					           counter3[i]=0; 
						  }
				       }
			      }
			      counter4[temp]=0;
			      if(flag!=1) {
			                 
					  for(i=temp-1;i>=0;i--) {
	                            
						      if(pi2[i]==pi2[temp]&&counter4[i]==0) {
	                           
						              counter4[i]=1;
	                                       lentemp= LIS1(v,counter4,n);
						              if(lentemp+len3>max1&&lentemp+len3>max2) {
						                  flag=1;
						                  cout<<n-(lentemp+len3)<<endl;    
						                  break;
					                   }
					                   else {
					                       counter4[i]=0; 
						             }
				                }
			            }  
			         
				 }
		       }
		       if(flag==0) {
		          if(max1>max2)
		             cout<<n-max1<<endl;
		          else
		             cout<<n-max2<<endl;
		       }
			    cin>>n;   
	}
        return 0;
}
int LIS(vector<int > &v,vector<int > &counter,int n,vector<int> &pi) {
    if(n==0)
       return 0;
     int i,j;
     int l[n];
     for(i=0;i<n;i++)
         l[i]=1;
     for(i=0;i<n;i++)
         pi[i]=i;
     for(i=1;i<n;i++) {
         for(j=0;j<i;j++) {
             if(v[j]<v[i]&&l[i]<l[j]+1) {
                 l[i]=l[j]+1;
                 pi[i]=j; 
		   }
	    }
	}
	int max1=l[0];
	int index=0;
     for(i=1;i<n;i++) 
		if(l[i]>max1) {
		   max1 = l[i];
		   index = i;
		}
		counter[index]=1;
		int len2=max1-1;
	while(len2--) {
          counter[pi[index]]=1;
		index=pi[index];    
     }
	
       return max1;
}
int LIS1(vector<int > &v,vector<int > &counter,int n) {
    if(n==0)
      return 0;
    int i=0,j=0;
    int l[n];
    for(i=0;i<n;i++)
        l[i]=0;
    if(counter[0]!=1)
         l[0]=1;   
	    for(i=1;i<n;i++) {
         if(counter[i]==1)
            continue;
         l[i]=1;
	    for(j=0;j<i;j++) {
           if(counter[j]==1)
            continue;
	        if(v[j]<v[i]&&l[i]<l[j]+1) {
                 l[i]=l[j]+1;
             }
	    }
	}
	int max1=l[0];
     for(i=1;i<n;i++) 
		if(l[i]>max1) {
			max1 = l[i];
		}
		return max1;
}
int Check(vector<int > &a,vector<int> &b,int n) {
    for(int i=0;i<n;i++)
        if(a[i]==1&&b[i]==1)
           return i;
    return -1 ;
}
