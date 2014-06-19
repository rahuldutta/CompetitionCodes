import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.lang.String;
public class Main
{
	
    public static void main(String[] args) throws IOException 
    {
    	int[] input=new int[100000];
		BigInteger[] DP=new BigInteger[100001];
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s;
        while((s=br.readLine()) !=null ) 
        {
			int N=Integer.parseInt(s);
			String line=br.readLine();
			String[] ar=line.split(" ");
			for(int i=0;i<ar.length;i++)
			{
				input[i]=Integer.parseInt(ar[i]);
			}	
			line=br.readLine();
			int T=Integer.parseInt(line);
			DP[0]= BigInteger.ONE;
			for(int i=1;i<=N;i++)
			{
				BigInteger bigInt = new BigInteger(String.valueOf(input[i-1]));
				DP[i]=bigInt.multiply(DP[i-1]);
			}
			for(int j=0;j<T;j++)
			{
				line=br.readLine();
				ar=line.split(" ");
				int li=Integer.parseInt(ar[0]);
				int ri=Integer.parseInt(ar[1]);
				int mid=Integer.parseInt(ar[2]);
				BigInteger bigint = new BigInteger(String.valueOf(mid));
				System.out.println(DP[ri].divide(DP[li-1]).mod(bigint));
			}
			
        }
        
        System.exit(0);
    }
}
