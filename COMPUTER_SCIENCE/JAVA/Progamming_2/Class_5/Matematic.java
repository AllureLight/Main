package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_5;

//Abstract nao permite instanciar objetos diretamente
public abstract class Matematic {
    public static int factorial(int n){
        if(n == 0){
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
}
