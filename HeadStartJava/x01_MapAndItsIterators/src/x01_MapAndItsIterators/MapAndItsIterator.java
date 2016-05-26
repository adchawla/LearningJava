package x01_MapAndItsIterators;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MapAndItsIterator {

	public static void main(String[] args) {
		Map<String, String> myMap = new HashMap<String, String>();
		
		myMap.put("A", "a");
		myMap.put("B", "b");
		myMap.put("C", "c");
		
		Set<String> keys = myMap.keySet();
		
		System.out.println("Data before removing \"C\": " + keys.toString() + " -> " + myMap.toString());
		
		myMap.remove("C");
		
		System.out.println("Data after removing: \"C\": " + keys.toString() + " -> " + myMap.toString());
		
		keys.remove("A");
		System.out.println("Data after removing: \"A\": " + keys.toString() + " -> " + myMap.toString());
	}
}
