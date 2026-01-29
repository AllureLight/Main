package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_4;

public class TestMatriz {
    public static void main(String[] args) {
        final int linhas = 10;

        int[][] matriz = new int[3][3];

        for(int i = 0; i < matriz.length; i++) {
            for(int j = 0; j < matriz[i].length; j++) {
                matriz[i][j] = i * 2;
            }
        }

        int[][] PascalTriangle = new int[linhas][];

        for(int i = 0;i < PascalTriangle.length; i++) {
            PascalTriangle[i] = new int[i + 1];
            PascalTriangle[i][0] = 1;
            for(int j = 1; j < PascalTriangle[i].length; j++){
                if(i == j){
                    PascalTriangle[i][j] = 1;
                } else {
                    PascalTriangle[i][j] = PascalTriangle[i - 1][j - 1] + PascalTriangle[i - 1][j];
                }
            }
        }

        for(int i = 0; i < PascalTriangle.length; i++) {
            for(int j = 0; j < PascalTriangle[i].length; j++) {
                System.out.print(PascalTriangle[i][j] + " ");
            }
            System.out.println();
        }
    }
}
