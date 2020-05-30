# include <bits/stdc++.h> 

using namespace std;

int Satisfies(int i,vector<int> &v);

int GetNum(int x);
int CheckRandom(int digits,vector<int> &arr);
int main() {
ios::sync_with_stdio(false);

               int t;
               
               vector<int> v(100000,1);
               v[0]=0;
               v[1]=0;
               int j,k,r;
               for(j=2;j<=sqrt(100000);j++) {
               
                   if(v[j]==1)
			      for(k=2,r=2*j;r<=100000;) {
			           
				      if(v[r]==1)
				          v[r]=0;
				      k++;
					 r=k*j;       
				 }
			}
			vector<int> v1(100001,0);
			int i;
			
			for(i=1;i<=10000;i++) {
				 
                    if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			for(i=10001;i<=20000;i++) {
				 
                     if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			for(i=20001;i<=30000;i++) {
				 
				if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			for(i=30001;i<=40000;i++) {
				 
				  if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			for(i=40001;i<=50000;i++) {
				 
                     if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			for(i=50001;i<=60000;i++) {
                     if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			for(i=60001;i<=70000;i++) {
				 
				 if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			
			for(i=70001;i<=80000;i++) {
				 
				 if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			for(i=80001;i<=90000;i++) {
				 
				 if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];
			}
			for(i=90001;i<100000;i++) {
				 
				 if(Satisfies(i,v))
				     v1[i]=1+v1[i-1];
				 else
				     v1[i]=v1[i-1];    

			}
		     v1[100000]=1+v1[99999];   
			
               cin>>t;
			while(t--) {
		         
		               int a,b;
					cin>>a;
					cin>>b;
					int i,count=0;
					
					if(b>a)
					 cout<<v1[b]-v1[a-1]<<endl;
					else
					 cout<<v1[a]-v1[b-1]<<endl; 
			}
       		return 0;
}
int Satisfies(int i,vector<int> &v) {
   
	    int digits=GetNum(i);
         int tmp=digits;
         int n=i;
         int a=0;
         vector<int> arr(digits,0);
         vector<int> count(10,0);
         while(tmp--) {
              
              a=n%10;
              arr[digits-1-tmp]=a;
              count[a]++;
              n=n/10;
	    }
	    if(count[3]>=1||count[2]>=1||count[5]>=1||count[7]>=1||count[1]>=2) 
	       return 0;
	    if(CheckRandom(digits,arr))
	        return 0;  
	    int x,sum,k;
	    int s;
	    for(x=0;x<=pow(2,digits);x++) {
	       
	          sum=0;
	          s=0;
	          for(k=0;k<digits;k++) {
       	               
	                 if(x&(1<<k)) {
	                    sum=sum+arr[k]*pow(10,s);
	                    s++;       
	                 }
 			}
 			if(v[sum]==1)
 			   return 0;
	    }
	    return 1;
}
int GetNum(int x) {

       if(x<10)
         return 1;
       if(x<100)
         return 2;
       if(x<1000)
         return 3;
       if(x<10000)
         return 4;
       if(x<100000)
         return 5;
       
}
int CheckRandom(int digits,vector<int> &arr) {

           int i=digits-1;
		 int j=0;
           while(i>=0) {
               if(arr[i]==6||arr[i]==4)
                   break;
                i--;   
		 }
		 while(j<digits) {
		     if(arr[j]==1)
		        break;
		     j++;   
		 }
		 if(i>j)
		    return 1;
		 i=digits-1;
		 j=0;   
		 while(i>=0) {
               if(arr[i]==8||arr[i]==1)
                   break;
                i--;   
		 }
		 while(j<digits) {
		     if(arr[j]==9)
		        break;
		     j++;   
		 }   
		 if(i>j)
		    return 1;
	return 0;
	}