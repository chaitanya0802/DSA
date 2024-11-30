//persondatatype in arraylist
package Java.DataStructures;
import java.util.ArrayList;

public class person {
    private String name;
    private int age;

    public person(String name, int age) {
        this.name=name;
        this.age=age;
    }
     public void displaydata(){
         System.out.println(name+" "+age);
     }
}
class adderdemo{
    public static void main(String[] args) {
        ArrayList<person> plist =new ArrayList<>(5);
        plist.add(new person("dfdff",20));
        //OR
        person p2=new person("ravi",10);
        plist.add(p2);

        plist.add(new person("ffdfc",30));
        plist.add(new person("Crrvv",40));
        plist.add(new person("hnhn",50));

        plist.forEach(p->p.displaydata());
    }
 }
