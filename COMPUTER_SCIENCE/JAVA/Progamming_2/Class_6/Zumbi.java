package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_6;

public class Zumbi extends Monster {
    
    @Override
    public void scare() {
        for(int i = 0; i < 3; i++){
            System.out.println("Zumbi moans...");
        }
    }
}
