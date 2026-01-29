package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

public class Programmer extends Employeed{
    private String programmingLanguage;

    @Override
    public void displayInfo(){
        super.displayInfo();
        System.out.println("Programming Language: " + programmingLanguage);
    }

    //Sobrescrevendo o método displayInfo da classe mãe
    /*public void displayInfo(){
        System.out.println("CPF: " + getCpf());
        System.out.println("Name: " + getName());
        System.out.println("Programming Language: " + programmingLanguage);
    }*/

    public void setProgrammingLanguage(String programmingLanguage) {
        this.programmingLanguage = programmingLanguage;
    }
}
