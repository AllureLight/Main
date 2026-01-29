package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

public class Manager extends Employeed{
    private String sector;

    @Override
    public void displayInfo(){
        super.displayInfo();
        System.out.println("Sector: " + sector);
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
}
