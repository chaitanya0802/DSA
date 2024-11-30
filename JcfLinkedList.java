//LinkedList using JCF
package Java.DataStructures;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.NoSuchElementException;

public class JcfLinkedList <T>{

    public static void main(String[] args) throws Exception{
        LinkedList <Integer> ll1=new LinkedList<>();
        LinkedList <Integer> ll2=new LinkedList<>();

        //add to ll1
        ll1.add(2);
        ll1.add(6);
        ll1.add(8);
        ll1.add(1,11);
        ll1.add(87);
        ll1.add(6);
        ll1.add(4);
        ll1.add(6);
        System.out.println(ll1);

        ll2.add(56);
        ll2.add(78);
        ll2.add(56);
        ll2.add(7);
        ll2.add(77);
        ll2.add(88);

        //addAll() method
        ll1.addAll(4,ll2);

        //using Iterator method for display collection may throw exception
        try {
            Iterator itr1 = ll1.iterator();
            while (itr1.hasNext()) {
                System.out.print(itr1.next() + " -> ");
            }
        }
        catch(NoSuchElementException e){
            System.out.println(e);
        }

        System.out.println("\n"+ll2.contains(79));

        System.out.println("clone() method");

        LinkedList temp=new LinkedList<>();
        temp=(LinkedList) ll1.clone();
        System.out.println(temp);

        System.out.println("descendingIterator() method");
        try{
            Iterator itr2 = ll1.descendingIterator();
           while(itr2.hasNext()){
               System.out.print("->"+itr2.next());
           }
        }
        catch(NullPointerException e) {
            System.out.println(e);
        }

        System.out.println("element() method");
        System.out.println(ll1.element());

        System.out.println("get() method");
        System.out.println(ll2.get(5));


        System.out.println(" getFirst() and getLast() method");
        System.out.println(ll2.getFirst());
        System.out.println(ll2.getLast());

        System.out.println("indexOf()");
        System.out.println(ll1.indexOf(87));

        System.out.println("lastIndexOf()");
        System.out.println(ll1.lastIndexOf(6));

        System.out.println("listIterator()");
        try {
            Iterator<Integer> itr3=ll2.listIterator(3);

            while(itr3.hasNext()){
                System.out.print("->"+itr3.next());
            }
        }
        catch(IndexOutOfBoundsException e){
            System.out.println(e);
        }

        System.out.println("offer()");
        ll1.offer(99);
        System.out.println(ll1);

        System.out.println("offerFirst() and offerLast()");
        ll1.offerFirst(799);
        ll1.offerLast(699);
        System.out.println(ll1);

        System.out.println("peek()");
        System.out.println(ll2.peek());


        System.out.println("poll()");
        System.out.println(ll2.poll());
        System.out.println(ll2);

        System.out.println("pollFirst()");
        System.out.println(ll1.pollFirst());
        System.out.println(ll1);

        System.out.println("pollLast()");
        System.out.println(ll1.pollLast());
        System.out.println(ll1);


        System.out.println("pop()");
        ll1.pop();
        System.out.println(ll1);

        System.out.println("push()");
        ll1.push(69);
        System.out.println(ll1);

        System.out.println("remove()");
        System.out.println(ll1.remove());
        System.out.println(ll1);

        System.out.println("remove()");
        System.out.println(ll1.remove(5));
        System.out.println(ll1);

        System.out.println("removeFirstOccurrence()");
        ll1.removeFirstOccurrence(6);

        System.out.println("removeLastOccurrence()");
        ll1.removeLastOccurrence(6);

        System.out.println(ll1);

        ll1.set(4,44);
        System.out.println(ll1);

        System.out.println(ll2.size());

        System.out.println("toArray()");
        Object[] arr=ll1.toArray();
        for(Object element :arr){
            System.out.print(element+",");
        }
        System.out.println("\ntoString()");
        System.out.println(ll2.toString());
    }
}