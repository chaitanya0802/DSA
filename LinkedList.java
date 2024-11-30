//Singly LinkedList (without JCF) to insert,traverse,print and delete node;
package Java.DataStructures;

import java.util.Scanner;

public class LinkedList {
    node head;

    static class node {
        int data;
        node nextlink;

        node(int d) {
             data = d;
             nextlink = null;
        }
    }

    public LinkedList insertatfront(LinkedList list, int data) {
        head=new node(data);
        return list;
    }

    public LinkedList insertatend(LinkedList list, int data) {
        node newnode = new node(data);

        if (list.head == null) {
            list.head = newnode;
        }
        else {
            node last = list.head;
            while (last.nextlink != null) {
                last = last.nextlink;
            }

            last.nextlink = newnode;
        }
        return list;
    }

    public LinkedList insertinbetween(LinkedList list, int data, int after) {
        node newnode = new node(data);
        node currnode = list.head;
        while (currnode.data != after) {
            currnode = currnode.nextlink;
        }
        newnode.nextlink = currnode.nextlink;
        currnode.nextlink = newnode;

        return list;

    }

    public void printlist(LinkedList list) {
        node currnode = list.head;
        while (currnode != null) {
            System.out.print(currnode.data+" --> ");
            currnode = currnode.nextlink;
        }
    }

    public LinkedList deletenode(LinkedList list,int d){
        node temp=list.head;
        node perv=null;

        if(temp!=null && temp.data==d)
        {
            list.head=temp.nextlink;
            System.out.println("node deleted successfully.");
        }
        else if(temp!=null && temp.data!=d) {
                while(temp!=null && temp.data!=d) {
                    perv = temp;
                    temp = temp.nextlink;
                }

                perv.nextlink=temp.nextlink;
                temp.nextlink=null;
                System.out.println("node deleted successfully.");
        }
        return  list;
    }


    //Driver code
    public static void main(String[] args) {
        LinkedList list1 = new LinkedList();
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("\nEnter your choice:");
            System.out.println("1.Enter head node ");
            System.out.println("2.Enter next node ");
            System.out.println("3.Enter node inbetween");
            System.out.println("4.Print List");
            System.out.println("5.Delete node");
            int c = sc.nextInt();

            switch (c) {
                case 1: {
                    System.out.println("Enter the data of head node: ");
                    int headdata = sc.nextInt();
                    list1.insertatfront(list1, headdata);
                    break;
                }

                case 2: {
                    int flag = 1;
                    while (flag == 1) {
                        System.out.println("Enter the data of next node: ");
                        int nextdata = sc.nextInt();
                        list1.insertatend(list1, nextdata);

                        System.out.println("Do you want to insert more? (y(1)/n(0))");
                        int choice = sc.nextInt();
                        if (choice == 0) {
                            flag = 0;
                        }
                    }
                    break;
                }

                case 3: {
                    System.out.println("enter the data you want to insert inbetween: ");
                    int a = sc.nextInt();
                    System.out.println("After which(data) node do you want to enter: ");
                    int b = sc.nextInt();
                    list1.insertinbetween(list1, a, b);
                    break;
                }

                case 4: {
                    list1.printlist(list1);
                    break;
                }

                case 5:{
                    System.out.println("Enter the node(data) you want to delete:");
                    int d=sc.nextInt();
                    list1.deletenode(list1,d);
                }
            }
        }
    }
}
