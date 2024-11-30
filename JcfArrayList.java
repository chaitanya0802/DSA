package Java.DataStructures;

import java.util.ArrayList;
import java.util.Comparator;

public class JcfArrayList {
    public static void main(String[] args) {
        ArrayList <Integer> number = new ArrayList<>(10);
        number.add(33);
        number.add(45);
        number.add(55);
        number.add(34);

        number.add(3,5);

        ArrayList<Integer> num=new ArrayList<>();

        num=(ArrayList)number.clone();
        System.out.println(num);

        System.out.println(num.contains(88));

        System.out.println(number.equals(num));

        number.set(0,89);
        System.out.println(number);

        number.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1.compareTo(o2);
            }
        });
        System.out.println(number);


    }
}
