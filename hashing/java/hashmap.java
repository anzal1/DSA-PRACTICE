import java.util.HashMap;
import java.util.*;
public class hashmap {
    
public static void main(String args[])
{
    HashMap<String,Integer>m=new HashMap<String,Integer>();
    m.put("gfg",10);
    m.put("ide",15);
    m.put("courses", 20);
  if(m.containsValue(10))
  {
      System.out.println("yes");
  }
  else{
      System.out.println("no");

  }
  System.out.println(m.get("ide"));
  System.out.println(m.get("hehe"));
  

}
}
