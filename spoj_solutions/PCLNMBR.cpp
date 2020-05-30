#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b);
long long int lcm1(long long int a,long long int b,long long int c);
long long int _Function(long long int a,long long int b,long long int x,long long int n,long long int c);
long long int _BST(long long int a,long long int n,long long int x,long long int mid);
int main()
{
	long long int a,b,c,m;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>m;
	while(m--){
	     long long int n,x;
	     cin>>n;
	     if(a==1&&b==1&&c==1)
	        cout<<n<<endl;
	     else if(a==1&&b==1){
            cout<<c*n<<endl; 
         }
		 else if(a==1&&c==1){
	        cout<<n<<endl;
		 }
		 else if(b==1&&c==1){
		    cout<<a*n<<endl;
		 }
		 else if(a==1){
		    x=(b*c)/gcd(b,c);
		    cout<<_Function(1,b,x,n,c)<<endl;
			
		 }
		 else if(b==1){
		    cout<<(a*c)/gcd(a,c)*n<<endl;
		 }
		 else if(c==1){
            cout<<a*n<<endl;		    
		 }
		 else if((b%a==0&&a%c==0)||(a%b==0&&a%c==0)||(a%b==0&&b%c==0)||(b%a==0&&b%c==0)||(a%c==0&&c%b==0)||(c%a==0&&b%c==0)){
		    cout<<a*n<<endl;
		 }
		 /*
		 else if((b%a!=0&&c%a!=0&&a%b!=0&&a%c==0)||(a%b!=0&&c%b!=0&&b%a!=0&&b%c==0)){
		    //cout<<_Function(a,b,x,n)<<endl;
			cout<<a*n<<endl;
		 }
		 else if((a%c==0&&b%c!=0&&c%b!=0)||(b%c==0&&a%c!=0&&c%a!=0)){
		    //cout<<_Function(a,b,x,n)<<endl;
            cout<<a*n<<endl;			 
		 }
		 else if((b%a==0&&c%a!=0&&a%c!=0)||(c%a==0&&b%a!=0&&a%b!=0)){
		    x=(c*b)/gcd(c,b);
		    if(a==b)
		    cout<<x*n<<endl;
		    else
			cout<<_Function(a,b,x,n,c)<<endl;
		
		 }
		 else if((a%b!=0&&c%b!=0&&b%a==0&&b%c!=0)||(a%c!=0&&b%c!=0&&c%a==0&&c%b!=0)){
		    x=(c*b)/gcd(c,b);
		    cout<<_Function(a,b,x,n,c)<<endl;
			
		 }
		 else if((c%b==0&&a%b!=0&&b%a!=0)||(a%c!=0&&b%c!=0&&c%a!=0&&c%b==0)){
			x=(a*c)/gcd(a,c);
		    cout<<_Function(a,b,x,n,c)<<endl;
			
		 }
		 else if((c%b==0&&a%b!=0&&b%a==0)||(a%c!=0&&b%c!=0&&c%a==0&&c%b==0)){
		     cout<<_Function(a,b,c,n,c)<<endl;
			
		 }*/
		 else if((b%a!=0&&c%a!=0&&a%b==0&&a%c!=0)||(a%b==0&&c%b!=0&&b%c!=0)){
		     cout<<(a*c)/gcd(a,c)*n<<endl;
		 }
		 else if((c%a==0&&b%a!=0&&a%b==0)){
		     cout<<c*n<<endl;
		 }
		 else{
		     x=lcm1(a,b,c);
			 cout<<_Function(a,b,x,n,c)<<endl;
			 
		 }
		 
         
	}
	return 0;
}
long long int gcd(long long int a,long long int b){
    long long int temp=0;
	if(a<b){
      temp=a;
      a=b;
      b=temp;
	}
	long long int rem=a%b;
	
	while(b){
	  rem=a%b;
      a=b;
	  b=rem;	  
	}
	return a;
}
long long int lcm1(long long int a,long long int b,long long int c)
{
  return (a*b*c)/(gcd(a,b)*gcd(b,c)*gcd(a,c));
}
long long int _Function(long long int a,long long int b,long long int x,long long int n,long long int c)
{
	long long int i,count=0,shift=0;
    long long int mofb,mofx,prevb=0,prevx=0;
    long long int ab=gcd(a,b);
    long long int ax=gcd(a,x);
    long long int p=mofb=n*ab/b;
    long long int q=mofx=n*ax/x;
    shift=p-q;
	while(p!=0||q!=0){
	  mofb=(n+shift)*ab/b;
      mofx=(n+shift)*ax/x;
      if(p>=0)
	  p=mofb-p-prevb;
	  if(q>=0)
      q=mofx-q-prevx;
      shift=shift+p-q;
	  prevb=mofb-p;
	  prevx=mofx-q;
	}
	
	   return a*(n+mofb-mofx);   

}
