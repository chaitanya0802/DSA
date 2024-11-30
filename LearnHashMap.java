package Java.DataStructures;

import java.util.ConcurrentModificationException;
import java.util.HashMap;
import java.util.Map;

public class LearnHashMap {

    public static void main(String[] args) {
        HashMap<Integer,String> hm1=new HashMap<>(10, 0.50f);

        System.out.println("Adding kay and values.");
        hm1.put(16,"Chaitanya");
        hm1.put(17,"fddfvd");
        hm1.put(18,"hdjj");
        hm1.put(19,"ghngh");
        hm1.put(10,"kjkjk");
        hm1.put(11,"efwfaf");

        System.out.println("Display: "+hm1);

        System.out.println("Updating values");
        hm1.put(10,"hello");
        System.out.println(hm1);

        System.out.println("Removing");
        hm1.remove(18);
        System.out.println(hm1);

        System.out.println("entrySet()");
        System.out.println(hm1.entrySet());

        System.out.println("Iteration");
        for(Map.Entry<Integer,String> i: hm1.entrySet()) {
            System.out.print("Key is: " + i.getKey() + "Value is: " + i.getValue());
        }


        System.out.println("hm1.clear() is used to remove all key and values");

        System.out.println("clone()");
        HashMap<Integer,String> hm2=new HashMap<>();
        hm2=(HashMap<Integer,String>) hm1.clone();
        System.out.println("second HashMap is:  " + hm2);

        System.out.println("compute()");
        try{
            hm1.compute(16, (key, value) -> value.concat(" Malshikare"));
            System.out.println(hm1);
        }
        catch(ConcurrentModificationException e){
            System.out.println(e);
        }

        System.out.println("containskey()");
        System.out.println(hm1.containsKey(100));

        System.out.println("containsValue()");
        System.out.println(hm1.containsValue("sdfer"));

        System.out.println("entrySet()");
        System.out.println(hm1.entrySet());

        System.out.println("get()");
        System.out.println(hm1.get(10));

        System.out.println("isEmpty()");
        System.out.println(hm1.isEmpty());

        System.out.println("keySet()");
        System.out.println(hm1.keySet());

        System.out.println("putAll()");
        hm1.putAll(hm2);
        System.out.println(hm1);

        System.out.println("remove()");
        System.out.println("Removed value is: "+hm1.remove(11));

        System.out.println("size()");
        System.out.println("the size of hashmap is: "+hm1.size());

        System.out.println("value()");
        System.out.println(hm1.values());

    }
}
