#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pii pair<ii,ii>
typedef long long int ii;
int Function(ii s,int i,vector< pii > &v,vector<char> &T);
int B1search(ii s,int i,vector<char> &T,vector< pii > &v);
int main() {
	
        int n;
	   ii s;
        scanf("%d%lld",&n,&s);
        vector< pii > v(n-1);
        vector<ii> counter(n-1,0);
        vector<ii> pos(n-1,0);
        vector<char> T(n-1,'.');
        ii first;
        scanf("%lld",&first);
        int i;
	   ii x;
        for(i=0;i<n-1;i++) {
            scanf("%lld",&x);
            v[i].f=x;
            v[i].s=i;
	   }
        for(i=0;i<n-1;i++) {

		  if(v[i].f<0) {
               counter[i]=1;
               v[i].f=0-v[i].f;
		  }

 	   }
        ii temp=0;
        int j;
        sort(v.begin(),v.end());
 	    ii k;
	    int flag=1;
	   ii sum=0;
         for(i=0;i<n-1;i++)
            sum=sum+v[i].f;
          cout<<sum<<endl;  
          sum=2*sum;
	   i=n-2;
	   if(s-first>sum||s-first<(0-sum))
              printf("Impossible\n");
	   else {
             s=s-first;
             s=sum-s;
		   if(s-4*v[i].f>=0) { 
			 flag=0;
			 k=s-4*v[i].f;
			 T[v[i].s]='~';
	           if(!Function(k,i-1,v,T)){  
          			T[v[i].s]='.';
			  		flag=1;
			}
	        }
	        if(s-3*v[i].f>=0&&flag==1) {
			 flag=0;
			 k=s-3*v[i].f;
			 T[v[i].s]='-';
			 if(!Function(k,i-1,v,T)){
          			T[v[i].s]='.';
                      flag=1;
                 }
			 
		   }
		   if(s-v[i].f>=0&&flag==1) {
		   	 flag=0;
			    k=s-v[i].f;
			 T[v[i].s]='+';
		      if(!Function(k,i-1,v,T)) {
          			T[v[i].s]='.';
              	    flag=1;
              }
		   }
		   if(flag==1) {
		   	flag=0;
                   T[v[i].s]='.';
		        if(!B1search(s,i,T,v))
		           flag=1;
             }
             if(flag!=1)   {
	           for(i=0;i<n-1;i++) {
                if(counter[i]==1){
                if(T[i]=='.')
                  T[i]='~';
                else if(T[i]=='+')
                  T[i]='-';
                else if(T[i]=='-')
                  T[i]='+';
                else 
                  T[i]='.';
		      }
                printf("%c",T[i]);
                }
                printf("\n");
            }
            else
              printf("Impossible\n");
          
	   }

	   return 0;
}

int Function(ii s,int i,vector< pii > &v,vector<char> &T) {
  if(s==0)
   return 1;
  if(i<0)
    return 0;
    ii k;
    if(v[i].f==0) {
       if(s==0)
         return 1;
       return 0;
    }
    int flag=1;
              if(s-4*v[i].f>=0) { 
			 flag=0;
			 k=s-4*v[i].f;
			 T[v[i].s]='~';
	           if(!Function(k,i-1,v,T)){  
          			T[v[i].s]='.';
			  		flag=1;
			}
			
	         }
              if(s-3*v[i].f>=0&&flag==1) {
			 flag=0;
			 k=s-3*v[i].f;
			 T[v[i].s]='-';
			 if(!Function(k,i-1,v,T)){
          		  T[v[i].s]='.';
                      flag=1;
                 }
			 
		    }
		    if(s-v[i].f>=0&&flag==1) {
		   	 flag=0;
			 k=s-v[i].f;
			 T[v[i].s]='+';
		      if(!Function(k,i-1,v,T)) {
          	      T[v[i].s]='.';
              	      flag=1;
                }
		    }
		   if(flag==1) {
		   	flag=0;
                   T[v[i].s]='.';
		        if(!B1search(s,i,T,v)) 
		           flag=1;
		      
             }
  if(flag==0)
     return 1;
  else
   return 0;
}
int B1search(ii s,int i,vector<char> &T,vector< pii > &v) {
     if(s==0)
     return 1;
     int low=0;
     int high=i;
     int x=0;
    while(low<=high) {

       x=low+(high-low)/2;
       if(v[x].f<s)
         low=x+1;
       else if(v[x].f>s)
         high=x-1;
       else if(v[x].f==s) {
         T[v[x].s]='+';
         return 1;
	  }
   }
   low=0;
   high=i;
   while(low<=high) {

       x=low+(high-low)/2;
       if(3*v[x].f<s)
         low=x+1;
       else if(3*v[x].f>s)
         high=x-1;
       else if(3*v[x].f==s) {
         T[v[x].s]='-';
         return 1;
	  }
   }
   low=0;
   high=i;
   while(low<=high) {

       x=low+(high-low)/2;
       if(4*v[x].f<s)
         low=x+1;
       else if(4*v[x].f>s)
         high=x-1;
       else if(4*v[x].f==s) {
         T[v[x].s]='~';
         return 1;
	  }
   }
  return 0;
}
