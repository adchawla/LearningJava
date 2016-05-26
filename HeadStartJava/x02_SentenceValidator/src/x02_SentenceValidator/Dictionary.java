package x02_SentenceValidator;

import java.util.Arrays;

public class Dictionary {
	
	static public void Init() {
		Arrays.sort(words);
	}
	public static boolean isValidWord(String characters, int offset, int lastCharacterOffset) {
		String stringToSearch = characters.substring(offset, lastCharacterOffset+1);
		int indexFound = Arrays.binarySearch(words, stringToSearch);
		return indexFound < 0 ? false : true;
	}
	
	static private String[] words = { "i", "like", "icecream", "ice", "cream", "input", "ter" };
}
