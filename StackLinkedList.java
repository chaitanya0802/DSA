package Java.DataStructures;

public class StackLinkedList {
    node head;
    static int top=-1;
    int length=10;

    static class node {
        int data;
        node nextlink;

        node(int d) {
            data = d;
            nextlink = null;
        }
    }

    void push(StackLinkedList list, int a) {

        if (top < list.length - 1) {
            node newnode = new node(a);

            if (list.head == null) {
                list.head = newnode;
                top++;
            }
            else {
                node last = list.head;
                while (last.nextlink != null) {
                    last = last.nextlink;
                }
                last.nextlink = newnode;
                top++;
            }
            System.out.println(a+" pushed Successfull.");
        }
        else{
            System.out.println("StackOverFlow");
        }
    }

    void pop(StackLinkedList list){
        node perv = null;
        if(top!=-1){
            node last=list.head;
            while(last.nextlink!=null){
                perv=last;
                last=last.nextlink;
            }
            perv.nextlink=null;
            System.out.println("element popped successfully");
        }
        else{
            System.out.println("stack is empty.");
        }

    }

    boolean empty(StackLinkedList list){
        if(list.head==null){
            return true;
        }
        else {
            return false;
        }
    }

    void printStack(StackLinkedList list){
        node currnode=list.head;
        while (currnode!=null){
            System.out.println(currnode.data);
            currnode=currnode.nextlink;
        }
    }

    //DriverCode
    public static void main(String[] args) {
        StackLinkedList list1=new StackLinkedList();

        System.out.println("is stack empty: "+list1.empty(list1));

        list1.push(list1,11);
        list1.push(list1,22);
        list1.push(list1,33);
        list1.push(list1,44);
        list1.push(list1,55);
        list1.push(list1,66);

        list1.printStack(list1);

        list1.pop(list1);
        System.out.println("after pop operation");
        list1.printStack(list1);

        System.out.println("is stack empty: "+list1.empty(list1));

        list1.pop(list1);
        System.out.println("after pop operation");
        list1.printStack(list1);
    }
}
