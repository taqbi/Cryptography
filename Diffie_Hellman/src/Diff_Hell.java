import java.util.Vector;
import java.util.Scanner;
public class Diff_Hell {
 public static int power(int a,int b, int p)
 {
	 if(b==1)
		 return a;
	 return((int)Math.pow(a, b)%p);
 }


static int pr_root (int p) {
	    Vector<Integer> fact = new Vector<Integer>();
	    int phi = p-1,  n = phi;
	    for (int i=2; i*i<=n; ++i)
	        if (n % i == 0) {
	            fact.add (i);
	            while (n % i == 0)
	                n /= i;
	        }
	    if (n > 1)
	        fact.add (n);

	    for (int res=2; res<=p; ++res) {
	        boolean ok = true;
	        for ( int i=0; i<fact.size() && ok; ++i)
	            ok &= power(res, phi / fact.get(i), p) != 1;
	        if (ok)  return res;
	    }
	    return -1;
	}
 
 public static void main(String args[])
 {
	 int p,alpha,a,b,x,y,ka,kb;
	 System.out.println("Enter the value of P");
	Scanner s = new Scanner(System.in);
    p = s.nextInt();
    
    alpha =pr_root(p);
    System.out.println("The primitive root of"+ p +"  is " +alpha);
    System.out.println("Enter the private key of Sender");
    a = s.nextInt();
    x = power(alpha,a,p);
   
    System.out.println("Enter the private key of receiver");
    b = s.nextInt();
    y = power(alpha,b,p);
    ka = power(y, a, p);
    kb = power(x, b, p);
    System.out.println("The key generated at sender is: " + ka);
    System.out.println("The key generated at receiver is: "+ kb);
	s.close();
	
 } 
 
}
