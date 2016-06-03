
public class HelloJNI {

	static {
	      System.loadLibrary("hello"); // hello.dll (Windows) or libhello.so (Unixes)
	   }
	 
	   // Declare native method
	   private native void sayHello();
	 
	   // Declare a native method average() that receives two ints and return a double containing the average
	   private native double average(int n1, int n2);
	 
	   // Test Driver
	   public static void main(String[] args) {
		  HelloJNI obj = new HelloJNI();
	      obj.sayHello();  // invoke the native method
	      System.out.println("In Java, the average is " + obj.average(3, 2));
	   }

}
