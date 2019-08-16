/*remove duplicate words from a string using regular expression*/

package regex;
import java.util.regex.*;
import java.util.*;

public class regexDuplicateString {

	public static void main(String[] args) {
		
		String regex = "(\\b\\w+\\b)(\\s\\1\\b)+";
		Pattern p = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		while(n >= 0)
		{
			String input = sc.nextLine();
			
			Matcher m = p.matcher(input);
			
			while(m.find())
			{
				input = input.replaceAll(m.group(), m.group(1));
			}
			
			System.out.println(input);
			n--;
		}
		sc.close();

	}

}
