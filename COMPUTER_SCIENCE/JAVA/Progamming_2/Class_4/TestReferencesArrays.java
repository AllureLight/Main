package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_4;

public class TestReferencesArrays {
    public static void main(String[] args){
        Person[] peoples = new Person[3];
        peoples[0] = new Person("Alice");
        peoples[1] = new Person("Bob");
        int i = 0;
        while(peoples[i] != null && i < peoples.length){
            System.out.println("Person name: " + peoples[i].getName());
            i++;
        }
    }
}
