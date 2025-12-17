//QUESTAO UM
public class Retangulo{
    private double lado1;
    private double lado2;

    public Retangulo(double lado1, double lado2){
        this.lado1 = lado1;
        this.lado2 = lado2;
    }

    public Retangulo(){
    }

    public double getLado1(){
        return lado1;
    }

    public double getLado2(){
        return lado2;
    }

    public void setLado1(double lado1){
        this.lado1 = lado1;
    }

    public void setLado2(double lado2){
        this.lado2 = lado2;
    }

    public double Area(){
        return lado1 * lado2;
    }
}

public class Main{
    public static void main(String[] args){
        Retangulo r1 = new Retangulo(2,3);
        Retangulo r2 = new Retangulo();

        r2.setLado1(4);
        r2.setLado2(5);

        System.out.prinln(r1.Area);
        System.out.prinln(r2.Area);
    }
}


//QUESTAO DOIS
public class Carro{
    private String marca;
    private String modelo;
    private int ano;
    private Roda[] rodas;

    public Carro(String marca, String modelo, int ano){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.rodas = new Roda[4];
        for(int i = 0; i < 4; i++){
            this.rodas[i] = new Roda();
        }
    }
}

public class Roda{
    private int aro;
    private String tipo;
}


//QUESTAO TRES
int[] v = {1, 2, 3, 4, 5}
int chave = 4;
for(int i = 0; i < v.length; i++){
    if(chave == v[i])
        System.out.println(i);
}


//QUESTAO QUATRO
public class QuestaoQuatro{
    public static void main(String[] args){
        int[][] matriz = new int[3][3];
        int contador = 1, somaLinha;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                matriz[i][j] = contador;
                contador++;
            }
        }

        for(int i = 0; i < 3 ; i++){
            somaLinha = 0;
            for(int j = 0; j < 3; j++){
                somaLinha += matriz[i][j];
            }
            System.out.println(¨ Soma da Linha ¨ + i + ¨ = ¨ + somaLinha);
        }
    }
}


//QUESTAO BONUS
public class QuestaoBonus{
    //duas variaveis apontando para o mesmo objeto
    Carro c1 = new Carro("Toyota");
    Carro c2 = c1;
    //        +-----------------+
    //c1 ---> |  Carro("Toyota")|
    //        +-----------------+
    //           ^
    //           |
    //c2 --------

    //duas variaveis apontando para objetos diferentes
    Carro c1 = new Carro("Toyota");
    Carro c2 = new Carro("Toyota");
    //c1 ---> [ Carro("Toyota") ]
    //c2 ---> [ Carro("Toyota") ]
}