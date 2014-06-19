import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class uva10007
{

    public static void main(String[] args) throws IOException 
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
         while(true) 
        {
            int x=Integer.parseInt(br.readLine());
            if(x==0)
                break;
        if (x==1)
        System.out.println("1");        
        else
        System.out.println(factorial(2*x,x+2));
        }
        
        System.exit(0);
    }
    
    public static BigInteger factorial(int x, int y)
    {
    	if (x==y)
    	return BigInteger.valueOf(x);
    	else
    	 return BigInteger.valueOf(x).multiply(factorial(x-1, y));
    }
    
}
