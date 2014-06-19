import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.lang.String;
import java.text.DecimalFormat;

public class Main
{

	public static BigInteger[] CallArr;
	public static double p;
	public static double[][] P;
	public static boolean[][] vis;
	public static double DP(int i, int j)
	{
		if(vis[i][j]==true)
		{
			return P[i][j];
		}
		if(i==0&&j==0)
		{
			P[i][j]=-1;
			vis[i][j]=true;
			return -1;
		}
		else if(i==0)
		{
			P[i][j]=1;
			vis[i][j]=true;
			return 1;
		}
		else if(j==0)
		{
			P[i][j]=0;
			vis[i][j]=true;
			return 0;
		}
		else
		{
			 double ans1= p*DP(i-1,j);
			 double ans2= (1-p)*DP(i,j-1);
			 P[i][j]=ans1+ans2;
			 vis[i][j]=true;
			 return ans1+ans2;
		}
	}
	
	public static void prepare()
	{
		CallArr[0]=BigInteger.ONE;
		for(int k=1;k<2001;k++)
		{
			CallArr[k]=new BigInteger(String.valueOf(k));
			CallArr[k]=CallArr[k].multiply(CallArr[k-1]);
		}
		
	}
	public static BigInteger calc_Calls(int i, int j)
	{
		BigInteger Calls;
		Calls=CallArr[i+j];
		BigInteger temp=new BigInteger(String.valueOf(2));
		Calls=Calls.divide(CallArr[i]).divide(CallArr[j]).multiply(temp).subtract(temp);
		return Calls;
	}
	public static void main(String[] args) throws IOException
	{
		InputStreamReader isr = new InputStreamReader(System.in);	
        BufferedReader br = new BufferedReader(isr);
	    String m=null;
	    DecimalFormat df = new DecimalFormat("0.00000");
	    boolean flag=false;
	    while((m = br.readLine())!=null)
	    {
	    	
	    	String[] s=m.split(" ");
    	    p=Double.parseDouble(s[0]);
    	    int N=Integer.parseInt(s[1]);
    	     if(N==0)
    	    	break;
    	    if(flag)
	    		System.out.println();
	    	else
	    		flag=true;
    	    P=new double[1001][1001];
    	    vis=new boolean[1001][1001];
    	    CallArr=new BigInteger[2001];
    	    prepare();
    	   
    	    for(int k=0;k<N;k++)
    	    {
    	    	m=br.readLine();
    	    	s=m.split(" ");
    	    	int i=Integer.parseInt(s[0]);
    	    	int j=Integer.parseInt(s[1]);
    	    	if(i==0&&j==0)
    	    	{
    	    		System.out.println(df.format(-1));
    	    		System.out.println("0");
    	    	}
    	    	else
    	    	{
    	    		double ans=DP(i,j);
			    	System.out.println(df.format(ans));
			    	System.out.println(calc_Calls(i,j));
			    }
			   // if(k!=N-1)
			   //System.out.println();
    	    }
	    }
	    System.exit(0);
	}
}
