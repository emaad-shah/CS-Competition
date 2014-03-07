import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

//-------------------------------------------------------------------------------------
// Author: Syed Emaad Shah
// Identify all of the words in the English language that have an even number of 
// letters, such that the letter at index i of the word, where i is an even integer, 
// immediately precedes alphabetically the letter that is at position i+1 of the word.
// For example, one such word is STOP, because the letter S precedes the letter T in 
// the alphabet, and the letter O precedes the letter P. However, the word LION is not 
// one of these words, because L does not precede I, and O does not precede N. The word 
// ABET is also not one of these words, because although A precedes B alphabetically, E 
// is not immediately followed by T in the alphabet.
//-------------------------------------------------------------------------------------

public class wordCheck 
{
	// Read the words from the dictionary
	// and store it in an array
	public static void readFile(String [] dict)
	{
		int count = 0;
		File file = new File("WordList.txt"); 
		try 
	    {
			Scanner scanner = new Scanner(file);
	 
			while (scanner.hasNextLine()) 
			{
				String line = scanner.nextLine();
				dict[count] = line;
				count++;
			}
			scanner.close();
        } 
	    catch (FileNotFoundException e) 
	    {
	    	e.printStackTrace();
	    }
	}
	
	// Check if a string is even
	public static boolean isEven(String word)
	{
		return word.length() % 2 == 0;
	}
	
	// Compare chars in a string
	public static boolean compareChar(String word)
	{
		for (int i = 0; i < word.length(); i = i + 2)
		{
			if (word.charAt(i) > word.charAt(i+1))
				return false;
		}
		return true;
	}
	
	public static void check(String [] dict)
	{
		for (int i = 0; i < dict.length; i++)
		{
			String word = dict[i];
			if (isEven(word) && compareChar(word))
				System.out.println(dict[i]);
		}
	}
	
	public static void main(String args[])
	{
		// Size of the dictionary of words
		int size = 109580;
		String dict[] = new String[size];
		readFile(dict);
		check(dict);
	}
}
