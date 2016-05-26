/**
 * 
 */
package x03_Generics;

/**
 * @author amandeep
 *
 */
public class Driver {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Account<String> acc1 = new Account<String>("Sav11717007");
		Account<Integer> acc2 = new Account<Integer>(123);
		System.out.println(acc1.toString());
		System.out.println(acc2.toString());

	}

}
