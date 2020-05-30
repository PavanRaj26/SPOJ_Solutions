#include<stdio.h>
int main() {
     int t;
     scanf("%d",&t);
     while(t--) {
         long long int n;
         scanf("%lld",&n);
         if(n==1||n==2)
            printf("1\n");
         else if(n%4==1||n%4==3) {
            printf("%lld\n",n/2);
	    }
	    else if(n%4==2) {
	       printf("%lld\n",n/2-2);
	    }
	    else
	       printf("%lld\n",n/2-1);
	}
	return 0;
}