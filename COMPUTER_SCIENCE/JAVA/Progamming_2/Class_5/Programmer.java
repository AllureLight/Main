package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

public class Programmer extends Employeed{
    private String programmingLanguage;
    private int level;

    public Programmer(String name, String cpf, double salary, String programmingLanguage, int level) {
        super(name, cpf, salary);
        this.programmingLanguage = programmingLanguage;
        this.level = level;
    }

    @Override
    public void displayInfo(){
        super.displayInfo();
        System.out.println("Programming Language: " + programmingLanguage);
        System.out.println("Bonus: " + this.getBonus());
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

    public String getProgrammingLanguage() {
        return programmingLanguage;
    }

    public void setlevel(int level) {
        this.level = level;
    }

    public int getlevel() {
        return level;
    }

    @Override
    public double getBonus() {
        double bonus = 0;
        if(this.level == 1){
            bonus = 0.0;
        } else {
            if(this.level == 2){
                bonus = this.getBaseSalary() * 0.05;
            }
        }
        return bonus;
    }
}
