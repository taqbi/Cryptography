import java.util.*;
public class Sender 
{
	  private int a,p,alpha,ka;
	  public int x;
	  Sender(int primitive,int G,int pr,int y)
	  {
		  this.p = primitive;
		  this.alpha = G;
		  this.a = pr;
	  }
	  public static int power(int a,int b, int p)
	  {
	 	 if(b==1)
	 		 return a;
	 	 return((int)Math.pow(a, b)%p);
	  }
	  public int Key_gen_sen(int p,int alpha,int x)
	  {
		 
		    x = power(alpha,a,p); 
		    ka = power(y, a, p);
		    System.out.println("The Key generated at sender is: " + ka);
	  }  
	  
	   
	    
}
