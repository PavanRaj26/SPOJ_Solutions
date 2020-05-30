#include <stdio.h>

int main(void) {
	// your code here
  int i,j=0;
  int l,t;
  char str[400];
  char str1[400],strf[400];
  char *p=strf,*q=str1;
  char *s=p;
  scanf("%d",&t);
  for(l=0;l<t+1;l++)
   {   gets(str);
      for(i=0;str[i]!='\0';i++)
	        {  if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122))
			      { *p=str[i];   
			         p++;
			      }
			   else if(str[i]=='(')
			    {    *(q+j)=str[i];
				       j++;
			    }
				else if(str[i]==')')
				{    for(  ;  ;j--)
				          if(*(q+j-1)=='(')
						     { j=j-1;
							   break;
						     }
						  else
						     {  *p=*(q+j-1);
			                    p++;
			                 }
			   }
			   else
			    {  *(q+j)=str[i];
			        j++;
			    }
		   }
	 *p='\0';
	 printf("%s\n",strf);
	 p=s;
	 *p='\0';	   
   }

	return 0;
}