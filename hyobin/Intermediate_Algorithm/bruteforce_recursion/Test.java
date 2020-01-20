package bruteforce_recursion;

import java.util.HashMap;
import java.util.Map;

interface PC {
	default void print() {
		System.out.println("default print");
	}
	
	void game();
	
	static void click() {
		System.out.println("static click ");
	}
}

class Moniter implements PC{

	@Override
	public void game() {
		// TODO Auto-generated method stub
		System.out.println("my game");
	}
	
	public void print() {
		System.out.println("my print");
	}
	
}

public class Test{
	static int a; 
   public static void main(String[] args) {
//	   PC.click();
	   PC pc = new Moniter();
	   pc.print();
	   pc.game();
   }
}
