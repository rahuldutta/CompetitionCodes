import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class uva10643
{

    public static void main(String[] args) throws IOException 
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        BigInteger[] fct= new BigInteger[250];
        fct[0]=BigInteger.ONE; 
        for(int j=1;j<250;j++)
        {
        fct[j]=fct[j-1].multiply(BigInteger.valueOf(4*(2*(j+1)-1))).divide(BigInteger.valueOf(2*(j+1)));
        }
        String m="";
         while((m= br.readLine()) !=null) 
        {
            int x=Integer.parseInt(m);
            for(int i=1;i<=x;i++)
            {
            int y=Integer.parseInt(br.readLine());
            System.out.println("Case "+i+": "+fct[y/2-1]);
            }
        }
        
        System.exit(0);
    }
    
 
}
