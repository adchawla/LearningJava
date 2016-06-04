
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
	   
	   // Native method that receives a Java String and return a Java String
	   private native String sayHello3(String msg);
	   
	   // Declare a native method sumAndAverage() that receives an int[] and
	   //  return a double[2] array with [0] as sum and [1] as average
	   private native double[] sumAndAverage(int[] numbers);
	   
	   // member variables
	   public int number = 89;
	   private String message = "I am the private member";
	   
	   // a native method which can change the instance variables of the object.
	   private native void modifyInstanceVariables();
	   
	   // Test Driver
	   public static void main(String[] args) {
		  HelloJNI obj = new HelloJNI();
	      obj.sayHello();  // invoke the native method
	      System.out.println("In Java, the average is " + obj.average(3, 2));
	      String result = obj.sayHello2("Hello from Java to C");
	      System.out.println("In Java, the returned string is: " + result);
	      result = obj.sayHello3("Hello from Java to C++");
	      System.out.println("In Java, the returned string is: " + result);
	      
	      int[] numbers = {22, 33, 33};
	      double[] results = obj.sumAndAverage(numbers);
	      System.out.println("In Java, the sum is " + results[0]);
	      System.out.println("In Java, the average is " + results[1]);
	      System.out.println("Before invocation of moidfyInstanceVariables function: number = "
	    		  + obj.number +" message = \"" + obj.message + "\"");
	      obj.modifyInstanceVariables();
	      System.out.println("After invocation of moidfyInstanceVariables function: number = "
	    		  + obj.number +" message = \"" + obj.message + "\"");
	      
	   }

}
