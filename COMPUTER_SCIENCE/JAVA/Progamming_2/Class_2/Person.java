package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_2;

public class Person {
    static int NumberOfPeople = 0;

    String nome;

    public Person(String nome){
        NumberOfPeople++;
        this.nome = nome;
    }

    public static void main(String[] args){
        Person p1 = new Person("Guilherme");
        System.out.println(p1.nome);
        System.out.println(p1.NumberOfPeople);

        Person p2 = new Person("Bruno");

        System.out.println(p1.NumberOfPeople);
        System.out.println(p2.NumberOfPeople);
        System.out.println(Person.NumberOfPeople);
        System.out.println(p2.nome);

        p2 = null;
        Person.NumberOfPeople--;
        System.out.println(p2.NumberOfPeople);
    }
}
