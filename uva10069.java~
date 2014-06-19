import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.lang.String;

public class Main
{
	
	public static BigInteger DP(String X, String Z)
	{
		BigInteger[][] res= new BigInteger[X.length()+1][Z.length()+1];
		for(int i=X.length();i>=0;i--)
		{
			for(int k=Z.length();k>=0;k--)
			{
				
				if(i==X.length() && k!=Z.length())
					res[i][k]= BigInteger.ZERO;
				else if(k==Z.length())
					res[i][k]= BigInteger.ONE;
				else
				{
					if(X.charAt(i)==Z.charAt(k))
					{
						res[i][k]=res[i+1][k+1].add(res[i+1][k]);
					}
					else
					{
						res[i][k]=res[i+1][k];
					}
				}

			}
		}
		return res[0][0];
				
	} 
	
	public static void main(String[] args) throws IOException 
	{
		InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String m = br.readLine();
        int cases=Integer.parseInt(m);
        while(cases--!=0)
        {
        	String X=br.readLine();
        	String Z=br.readLine();
			System.out.println(DP(X,Z));
        }
        System.exit(0);
	}
}
