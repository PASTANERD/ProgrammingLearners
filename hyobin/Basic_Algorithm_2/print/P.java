package print;

import java.util.ArrayList;

public class P {
	
	public static <T> void print(ArrayList<T>[] AL) {
		for(ArrayList<T> list : AL) {
			for(T t : list) {
				System.out.print(t + " ");
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public static <T> void print(T[][] AL) {
		for(T[] list : AL) {
			for(T t : list) {
				System.out.print(t + " ");
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public static <T> void print(T[] AL) {
		for(T x : AL) {
			System.out.print(x + " ");
		}
		System.out.println();
	}
	
	public static <T> void println(T s) {
		System.out.println(s);
	}
	
	public static <T> void print(T s) {
		System.out.print(s);
	}
	
}

