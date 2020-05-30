#include <stdio.h>
#include <math.h>
int main(void) {
	// your code here
	int revnum(int );
int numdig(int);
	  int t,i;
   int m,n;
   scanf("%d",&t);
   for(i=0;i<t;i++)
     {  scanf("%d%d",&m,&n);
     	printf("%d\n",revnum(revnum(m)+revnum(n)));
}

	return 0;
}
int revnum(int n)
{ int k,a,sum;
   k=numdig(n);
  for(sum=0;k>=0;k--)
    {  a=n%10;
       n=n/10;
       sum=sum+a*pow(10,k);
    }
    return(sum);
}
int numdig(int n)
{  int i;
   for(i=0;   ;  )
    if((n/=10)==0)
       break;
    else
       i++;
	 return(i);
}