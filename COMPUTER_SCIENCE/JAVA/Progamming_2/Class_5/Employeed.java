package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

public class Employeed {
    private String cpf;
    private String name;

    public void displayInfo() {
        System.out.println("CPF: " + cpf);
        System.out.println("Name: " + name);
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getName() {
        return name;
    }

    public String getCpf() {
        return cpf;
    }
}
