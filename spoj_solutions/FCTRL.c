#include <stdio.h>
#include <math.h>
int main(void) {
	// your code here
 int i,t,j,n;
   int sum1;
 scanf("%d",&t);
 for(j=0;j<t;j++)
   {  scanf("%d",&n);
      for(i=1,sum1=0; ;i++)
        { if(n/pow(5,i)!=0)
		  sum1=sum1+(n/pow(5,i));
		  else
		  break;
	}
printf("%d\n",sum1);
}

	return 0;
}