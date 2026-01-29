package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

public class TestsClasses {
    public static void main(String[] args){
        Manager manager = new Manager();
        manager.setName("Alice");
        manager.setCpf("123456789");
        manager.setSector("Setor x");

        Programmer p1 = new Programmer();
        p1.setName("Bob");
        p1.setCpf("987654321");
        p1.setProgrammingLanguage("Java");

        manager.displayInfo();
        System.out.println("-----");
        p1.displayInfo();
    }
}
