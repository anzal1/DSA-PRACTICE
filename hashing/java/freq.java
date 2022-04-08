import java.util.*;
public class freq {

void frequency(int a[])
{
HashMap<Integer,Integer>h=new HashMap<Integer,Integer>();
for (int i : a) {
    h.put(i,h.getOrDefault(i,0)+1);

}
for(Map.Entry<Integer,Integer>e:h.entrySet())
{
    System.out.println(e.getKey()+" "+e.getValue());
}
}
    
}
