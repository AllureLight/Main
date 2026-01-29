package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

public class Manager extends Employeed{
    private String sector;
    private int numberProjects;

    public Manager(String name, String cpf, double salary, String sector, int numberProjects) {
        super(name, cpf, salary);
        this.sector = sector;
        this.numberProjects = numberProjects;
    }

    @Override
    public void displayInfo(){
        super.displayInfo();
        System.out.println("Sector: " + this.sector);
        System.out.println("Bonus: " + this.getBonus());
    }

    //Sobrescrevendo o método displayInfo da classe mãe
    /*public void displayInfo(){
        System.out.println("CPF: " + getCpf());
        System.out.println("Name: " + getName());
        System.out.println("Sector: " + sector);
    }*/

    public void setSector(String sector) {
        this.sector = sector;
    }

    public String getSector() {
        return sector;
    }

    public int getnumberProjects() {
        return numberProjects;
    }

    public void setnumberProjects(int numberProjects) {
        this.numberProjects = numberProjects;
    }

    @Override
    public double getBonus() {
        double bonus = 0;
        if(numberProjects > 5){
            bonus = this.getBaseSalary() * 0.1;
        }
        return bonus;
    }
}
