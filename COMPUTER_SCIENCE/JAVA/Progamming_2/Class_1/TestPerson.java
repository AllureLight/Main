package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_1;

public class TestPerson {
    public static void main(String[] args) {
        //criação de um objeto
        //instanciação da classe Pessoa
        Person p0 = new Person();
        Person p1 = new Person("Bruno", 1.75);

        System.out.println("Name: " + p0.getName());
        System.out.println("Height: " + p0.getHeight() + "\n");

        System.out.println("Name: " + p1.getName());
        System.out.println("Height: " + p1.getHeight() + "\n");

        p1.setName("David");
        p1.setHeight(100);
        
        System.out.println("Name: " + p1.getName());
        System.out.println("Height: " + p1.getHeight());
    }
}
