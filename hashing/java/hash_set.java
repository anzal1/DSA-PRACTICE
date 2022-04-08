import java.util.*;

 class test
{
    public void hasher()
    {
    HashSet<String> h=new HashSet<String>();
    h.add("gfg");
    h.add("courses");
    h.add("ide");
    System.out.println(h.size());
    h.remove("ide");
    System.out.println(h.size());
    for(String s:h)
    {
   System.out.println(s+" ");
    }
    System.out.println(h.isEmpty());

    }
}


// time complexity is o(1) for these activies
