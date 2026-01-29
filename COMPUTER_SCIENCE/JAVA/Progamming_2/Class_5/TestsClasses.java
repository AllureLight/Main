package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

public class TestsClasses {
    public static void main(String[] args){

        //Instanciando objetos sem o Construtor definido
        /*Manager m1 = new Manager();
        m1.setName("Alice");
        m1.setCpf("123456789");
        m1.setSector("Setor x");
        m1.setnumberProjects(3);
        m1.setSalary(1000.00);
        ------------------------------------
        Programmer p1 = new Programmer();
        p1.setName("Bob");
        p1.setCpf("987654321");
        p1.setProgrammingLanguage("Java");
        p1.setlevel(1);
        p1.setSalary(800);*/

        //instanciando objetos com o Construtor definido
        Manager m1 = new Manager("Alice", "123456789", 1000.00, "Setor X", 3);
        Manager m2 = new Manager("Carol", "555666777", 1200.00, "Setor Y", 7);
        Programmer p1 = new Programmer("Bob", "987654321", 800.00, "Java", 1);
        Programmer p2 = new Programmer("David", "456789123", 800.00, "Python", 2);

        //Exibindo as informações dos objetos
        System.out.println("Managers: ");
        m1.displayInfo();
        System.out.println();
        m2.displayInfo();
        System.out.println("\n--------------\n");
        System.out.println("Programmers: ");
        p1.displayInfo();
        System.out.println();
        p2.displayInfo();


        //Devido o abstract, nao funciona
        //Employeed E = new Employeed();


        //exemplo aleatorio do fatorial
        System.out.println("\n" + Matematic.factorial(10));
    }
}
