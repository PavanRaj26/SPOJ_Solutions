import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	
	   Scanner s= new Scanner(System.in);
		 int n=s.nextInt();
		 BigInteger b1,b2,b3;
		 b1=new BigInteger ("1");
		 b2=new BigInteger ("1");
		 b3=new BigInteger ("1");
	     for(int i=1;i<=n;i++)
	       {
              b3=b1.add(b2);
              b2=b1;
              b1=b3;
	       }
	      System.out.println(b3); 
	      System.out.println("\n");	
	}
}