
public class HelloJNI {

	static {
	      System.loadLibrary("hello"); // hello.dll (Windows) or libhello.so (Unixes)
	   }
	 
	   // Declare native method
	   private native void sayHello();
	 
	   // Declare a native method average() that receives two ints and return a double containing the average
	   private native double average(int n1, int n2);
	 
	// Native method that receives a Java String and return a Java String
	   private native String sayHello2(String msg);
	   
	   // Test Driver
	   public static void main(String[] args) {
		  HelloJNI obj = new HelloJNI();
	      obj.sayHello();  // invoke the native method
	      System.out.println("In Java, the average is " + obj.average(3, 2));
	      String result = obj.sayHello2("Hello from Java");
	      System.out.println("In Java, the returned string is: " + result);
	   }

}
