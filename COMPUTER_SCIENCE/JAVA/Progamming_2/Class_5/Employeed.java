package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

//Abstract nao permite instanciar objetos diretamente
public abstract class Employeed {
    private String cpf;
    private String name;
    private double salary;

    public Employeed(String name, String cpf, double salary) {
        this.name = name;
        this.cpf = cpf;
        this.salary = salary;
    }

    public void displayInfo() {
        System.out.println("CPF: " + cpf);
        System.out.println("Name: " + name);
        System.out.println("Base Salary: " + salary);
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public double getBaseSalary() {
        return salary;
    }

    public String getName() {
        return name;
    }

    public String getCpf() {
        return cpf;
    }

    //Método abstrato - obriga as classes filhas a implementarem esse método
    public abstract double getBonus();
}
