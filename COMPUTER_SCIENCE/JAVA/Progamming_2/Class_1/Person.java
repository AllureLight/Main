package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_1;

public class Person {
    private String name;
    private double height;

    public String getName() {
        return this.name;
    }

    public double getHeight() {
        return this.height;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public Person() {
    }

    public Person(String name, double height) {
        this.name = name;
        this.height = height;
    }
}
