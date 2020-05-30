#include <stdio.h>

int main(void) {
	// your code here
	  int t,i,j,a,b;
  int c,len1,len2,r;
char  strtot[110],strext[110];
char  strkla[110],strout[110];
for(r=0;r<10;r++)
{   gets(strtot);
    gets(strext);
    len1=strlen(strtot);
    len2=strlen(strext);
    for(i=len1-1,j=len2-1;i>=0;i--,j--)
     {   if(j>=0)
         c=*(strtot+i)-*(strext+j);
         else
         c=*(strtot+i)-'0';
         if(c>=0)
         *(strout+i)=c+48;
         else
      {   c=c+10;
         *(strtot+i-1)=*(strtot+i-1)-'1'+48;
         *(strout+i)=c+48;
     }
 }
 for(t=0,i=0;i<len1;i++)
 {   c=((*(strout+i)-'0')+10*t)/2;
     t=(*(strout+i)-'0')+10*t-2*c;
     *(strout+i)=c+48;
 }
 i=len1-1;
 j=len2-1;
 for(t=(*(strout+i)-'0');i>=0;i--,j--)
 {   a=t;
     if(j>=0)
     b=(*(strext+j)-'0');
     else
     b=0;
     if(a+b>=10)
     {   *(strkla+i)=(a+b)%10+48;
         t=(*(strout+i-1)-'0')+1;
 }
    else 
    { *(strkla+i)=a+b+48;
       t=(*(strout+i-1)-'0');
   }
}

*(strout+len1)='\0';
*(strkla+len1)='\0';
for(i=0;i<len1;i++)
   {  if(*(strkla+i)<='0'||*(strkla+i)>'9')
        continue;
      else
        { printf("%s\n",(strkla+i));
          break;
    }
}
for(i=0;i<len1;i++)
{   if(*(strout+i)<='0'||*(strout+i)>'9')
     continue;
     else
     { printf("%s\n",(strout+i));
       break;
}

}
}

	return 0;
}