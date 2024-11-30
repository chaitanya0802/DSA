package Java.DataStructures;

public class LearnHashCode {
    String firstname,lastname;
    int age;

    public LearnHashCode(String f,String l,int a){
        this.firstname=f;
        this.lastname=l;
        this.age=a;
    }

    public int hashCode(){
        return (2*firstname.hashCode()+3*lastname.hashCode()+ age);
    }

    public static void main(String[] args) {
        LearnHashCode obj=new LearnHashCode("Abc","Xyz",44);

        int newhashcode=obj.hashCode();
        System.out.println("hashCode of obj is:"+obj.hashCode());
        System.out.println(newhashcode);
    }
}
