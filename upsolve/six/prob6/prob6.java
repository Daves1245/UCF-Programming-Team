import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class prob6 
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		String line = scanner.next();
		
		HashSet<String> hs = new HashSet<String>();
		
		hs.add(".");
		hs.add("..");
		hs.add("...");
		hs.add("....");
		hs.add("-");
		hs.add("--");
		hs.add("---");
		hs.add(".-");
		hs.add("-...");
		hs.add("-.-.");
		hs.add("-..");
		hs.add("..-.");
		hs.add("--.");
		hs.add(".---");
		hs.add("-.-");
		hs.add(".-..");
		hs.add("-.");
		hs.add(".--.");
		hs.add("--.-");
		hs.add(".-.");
		hs.add("..-");
		hs.add("...-");
		hs.add(".--");
		hs.add("-..-");
		hs.add("-.--");
		hs.add("--..");
		
		while (line.charAt(0) != '#')
		{
			int[] dp = new int[line.length() + 1];
			dp[0] = 1;
			
			for (int i = 1; i < dp.length; i++)
			{
				int total = 0;
				for (int j = 0; j < i; j++)
				{
					if (hs.contains(line.substring(j, i)))
					{
						total += dp[j];
					}		
				}
				
				dp[i] = total;
				
			}
			
			System.out.println(dp[line.length()]);
			line = scanner.next();
		}
		
	
	}
}
