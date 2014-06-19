import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;

public class uva787
{
	public static void calculate(ArrayList<Long> ar)
	{
		//BigInteger[] DP=new BigInteger[ar.size()-1];
		//DP[0]=BigInteger.valueOf(ar.get(0));
		BigInteger ov_max=BigInteger.valueOf(ar.get(0));
		for(int i=1;i<ar.size();i++)
		{
			BigInteger max=BigInteger.valueOf(ar.get(i));
			BigInteger mul=BigInteger.valueOf(ar.get(i));
			for(int j=i-1;j>=0;j--)
			{
				mul=mul.multiply(BigInteger.valueOf(ar.get(j)));
				if(mul.compareTo(max)==1)
				{
					max=new BigInteger(mul.toString());
				}
			}
			if(max.compareTo(ov_max)==1)
			{
				ov_max=new BigInteger(max.toString());
			}
		}
		System.out.println(ov_max.toString());
	}
	public static void main(String[] args) throws IOException 
	{
		InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s;
        ArrayList<Long> ar=new ArrayList<Long>();
        while((s=br.readLine())!=null)
        {
        	String[] sarr= s.split(" ");
        	for(int i=0;i<sarr.length;i++)
        	{
        		long no=Long.parseLong(sarr[i]);
        		if(no!=-999999)
        			ar.add(no);
        	}
        	if(Long.parseLong(sarr[sarr.length-1])==-999999)
        	{
        		calculate(ar);
        		ar=new ArrayList<Long>();
        	}
        	
        }
	}
}
