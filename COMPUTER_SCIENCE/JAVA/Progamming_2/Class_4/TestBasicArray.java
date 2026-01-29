package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_4;

public class TestBasicArray {
    public static void main(String[] args) {
        //declaration : type[] variableName;
        //instaciation : variableName = new type[size];
        //get length: variableName.length;

        //simple array of integers
        int[] v1 = {2, -10};

        System.out.println("Vetor inteiros: {" + v1[0] + ", " + v1[1] + "}");

        //array de caracteres em que cada caractere é um valor inteiro
        char[] v2 = {66, 114, 117, 110, 111};

        for(int i = 0; i < v2.length; i++) {
            System.out.print(v2[i]);
        }
        System.out.println();

        char[] letras = new char[26];
        for(int i = 0; i < letras.length; i++) {
            letras[i] = (char)(i+97);
            System.out.println(letras[i]);
        }
    }
}
