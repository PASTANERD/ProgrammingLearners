package bruteforce_recursion;

import java.util.HashMap;

class A{
   static int x;
   int y;
   
   public A(int x, int y) {
      this.x = x;
      this.y = y;
   }

   @Override
   public boolean equals(Object obj) {
      A another = (A)obj;
      if(another.x == this.x && another.y == this.y)
         return true;
      return false;
   }
}

class Test{
   public static void main(String[] args) {
	  String[] s = new String[10];
      HashMap<A, Integer> map = new HashMap<>();
      A a = new A(1, 2);
      map.put(a, 10);
      if(map.containsKey(new A(1,2)))
         System.out.println("true");
      else
         System.out.println("false");
   }
}
