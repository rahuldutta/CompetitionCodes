import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class uva10223
{

    public static void main(String[] args) throws IOException 
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        BigInteger[] fct=new BigInteger[74];
        BigInteger[] catalan=new BigInteger[37];
        
        fct[0]=BigInteger.ONE;
        fct[1]=BigInteger.ONE;
        for(int j=2;j<74;j++)
        {
        fct[j]=BigInteger.valueOf(j).multiply(fct[j-1]);
        }
        int nDigits=2;
        catalan[0]=BigInteger.ONE;
       while(true)
        {
          catalan[nDigits-1]=fct[2*nDigits].divide(fct[nDigits]).divide(fct[nDigits]).divide(BigInteger.valueOf(nDigits+1));
          //System.out.println(catalan[nDigits-1]);
          BigInteger temp1=new BigInteger("4294967295");
          if(catalan[nDigits-1].compareTo(temp1)<=0&&nDigits<37)
          nDigits++;
          else
          break;
         } 

        String m="";
         while ((m = br.readLine()) != null) 
        {
            BigInteger x=new BigInteger(m);
            for(int i=0;i<nDigits;i++)
            {
            if(catalan[i].compareTo(x)==0)
            {
            System.out.println(i+1);
            break;
            }
            }
        }
        
        System.exit(0);
    }
    
   
    
}
