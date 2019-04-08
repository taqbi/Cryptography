public class Receiver 
{
	  private int b,p,alpha,kb;
	  public int y;
	  Receiver(int primitive,int G, int pr, int x)
	  {
		  this.p = primitive;
		  this.alpha = G;
		  this.b = pr;
		  
	  }
	  public static int power(int a,int b, int p)
	  {
	 	 if(b==1)
	 		 return a;
	 	 return((int)Math.pow(a, b)%p);
	  }
	  public int Key_gen_rec(int p,int alpha,int x)
	  {
		  
		    x = power(alpha,b,p); 
		    kb = power(x, b, p);
		    System.out.println("The Key generated at sender is: " + kb);
	  }  
	  