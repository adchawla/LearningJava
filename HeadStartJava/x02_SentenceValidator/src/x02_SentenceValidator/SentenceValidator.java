package x02_SentenceValidator;

public class SentenceValidator {

	private static boolean innerSentenceValidator(String string, int start, IntRef end) {
		if ( start > end.get() ) return true;
		int iend = end.get();
		if ( Dictionary.isValidWord(string, start, end.get()) ) {
			 end.set(start-1);
			 return true;
		}
		
		if ( start != end.get() ) {
			innerSentenceValidator(string, start + 1, end );
			if ( iend != end.get() ) {
				if ( Dictionary.isValidWord(string, start, end.get()) ) {
					 end.set(start-1);
					 return true;
				}
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) {
		Dictionary.Init();
		String input = "ilikeicecreaminputter";
		System.out.println(innerSentenceValidator(input, 0, new IntRef(input.length()-1)));
	}
		
}
