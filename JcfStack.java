package Java.DataStructures;

import java.util.Stack;

public class JcfStack {
    public static void main(String[] args) {
        Stack<Integer> stack1=new Stack<>();

        System.out.println("push()");
        System.out.println(stack1.push(11)+" pushed successfully");
        System.out.println(stack1.push(12)+" pushed successfully");
        System.out.println(stack1.push(13)+" pushed successfully");
        System.out.println(stack1.push(14)+" pushed successfully");
        System.out.println(stack1.push(15)+" pushed successfully");
        System.out.println(stack1.push(16)+" pushed successfully");

        System.out.println(stack1);

        System.out.println("pop()");
        System.out.println(stack1.pop()+" is popped");

        System.out.println(stack1);

        System.out.println("pop()");
        System.out.println("top element is: " + stack1.peek());

        System.out.println("search() it returns the position of element from top");
        System.out.println("position of 12 : " +stack1.search(12));

    }
}
