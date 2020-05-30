#include <stdio.h>
#include <math.h>
int main(void) {
	// your code here
	float areacal(float ,float,float ,float);
    float discal(float ,float,float ,float);
	 float a,b,c,x,y,z,area,distance,s;
  int i,t;
   scanf("%d",&t);
   for(i=0;i<t;i++)
    {   scanf("%f%f%f%f",&a,&x,&y,&z);
        b=(x/y)*a;
        c=(x/z)*a;
        s=(a+b+c)/2.0;
        area=areacal(s,a,b,c);
        distance=discal(area,a,b,c);
        printf("%.3f %.3f\n",area,distance);
}

	return 0;
}

float areacal(float s,float a,float b,float c)
{   float area;
   area=sqrt(s*(s-a)*(s-b)*(s-c));
   return(area);
}
float discal(float area,float a,float b,float c)
{ float dis,r;
        r=a*b*c/(area*4.0);
        dis=4*r*r-4.0*(a*a+b*b+c*c)/9.0;
  return(dis);
}