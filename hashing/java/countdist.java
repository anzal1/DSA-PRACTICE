import java.util.*;
public class countdist {


int countDist(int a[])
{
    HashSet<Integer>s=new HashSet<Integer>();
    for(int i=0;i<a.length;i++)
    {
        s.add(a[i]);
    }
    return s.size();
}
    

//efficient 

int efficount(Integer a [])
{
    HashSet<Integer>s=new HashSet<Integer>(Arrays.asList(a));
    return s.size();
}
}
