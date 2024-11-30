package Java.DataStructures;

public class StackArray<T> {
        T[] stackarray;           //stack using array
        int length;
        int top;

        StackArray(T[] a)
        {
            stackarray=a;
            length=a.length;
            top=-1;
        }

        void push(T a){
            if(top<=length-1){
                top++;
                stackarray[top]=a;
                System.out.println(a+" added successfully.");
            }
            else{
                System.out.println("StackOverflow");
            }
        }

        T pop(){
            T a=null;
            if(top!=-1){
                a=stackarray[top];
                top--;
            }
            return a;
        }

        boolean empty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }

        void printStack(){
            if (top==-1){
                System.out.println("the stack is empty hence cannot be printed");
            }
            else{
                for(int i=top;i>=0;i--){
                    System.out.println(stackarray[i]);
                }
            }
        }

        void peek(){
            System.out.println(stackarray[top]);
        }

    public static void main(String[] args) {
        Integer [] arr=new Integer[10];
        StackArray<Integer> stk=new StackArray<>(arr);

        System.out.println("Stack is empty: "+stk.empty());

        stk.push(11);
        stk.push(22);
        stk.push(33);
        stk.push(44);
        stk.push(55);
        stk.push(66);
        stk.push(77);

        System.out.println("Stack is empty: "+stk.empty());

        stk.printStack();

        System.out.println("Popped element is : "+stk.pop());

        System.out.println("After popping element.");
        stk.printStack();

        System.out.println("peek the stack: ");
        stk.peek();
    }

}
