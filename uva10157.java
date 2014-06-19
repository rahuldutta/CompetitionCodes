import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.lang.String;

//Took hint from uva discussion

/*
Basically, every non-empty bracketing B of length n and depth <= d must be of this form: 

B = (X)Y 
where X, Y are some valid bracketings, possibly empty. 

Let k be the length of the part `(X)'. Then the length of `X' is (k - 2) and the length of `Y' is (n - k). 
Clearly, k must satisfy: 2 <= k <= n (otherwise the length of `X' or `Y' would become negative, which is impossible), 
and k must also be an even integer (since every valid bracketing has even length.) 

Since `B' has depth <= d, then, by the definition of depth, the depths of both `(X)' and `Y' are also <= d, 
and the depth of `X' is <= (d - 1). 

In summary, I've found that for fixed k: 
1. `X' has length (k - 2), and depth <= (d - 1), 
2. `Y' has length (n - k), and depth <= d. 

Thus you have f(k-2, d-1) possible choices for `X' and f(n-k, d) choices for `Y'. 
Applying the product rule of counting, you have: f(k-2, d-1) * f(n-k, d) choices for `B' (for fixed k.) 

The total number of bracketings B is the sum of the above expression 
over all possible values of k. (that's due to the sum rule of counting.) 
*/
public class Main
{
		public static BigInteger[][] res= new BigInteger[301][151];
        public static void DP()
        {
        	for(int i=0;i<=300;i+=2)
        	{
        		for(int j=0;j<=150;j++)
        		{
        			if(i==0)
        				res[i][j]=BigInteger.ONE;
        			else
        			{
        				BigInteger sum=BigInteger.ZERO;
        				for(int k=2;k<=i;k+=2)
        				{
        					if(j-1<0)
        						continue;
        					sum=sum.add(res[k-2][j-1].multiply(res[i-k][j]));
        				}
        				res[i][j]=sum;
        			}
        		}
        	}
        }
		 public static void main(String[] args) throws IOException
        {
        	DP();
			InputStreamReader isr = new InputStreamReader(System.in);	
	        BufferedReader br = new BufferedReader(isr);
    	    String m=null;
    	    while((m = br.readLine())!=null)
    	    {
    	    	String[] s=m.split(" ");
    	    	int n=Integer.parseInt(s[0]);
    	    	int d=Integer.parseInt(s[1]);
    	    	if(n%2!=0)
    	    		System.out.println("0");
    	    	else
    	    		System.out.println(res[n][d].subtract(res[n][d-1]));
    	    }
    	    System.exit(0);
    	    
	}
	}
