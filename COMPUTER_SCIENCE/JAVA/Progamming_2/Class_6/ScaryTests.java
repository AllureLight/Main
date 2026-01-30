package COMPUTER_SCIENCE.JAVA.Progamming_2.Class_6;

public class ScaryTests {
    public static void main(String[] args) {

        //Um supertipo de referência pode apontar para qualquer subtipo
        //Monster m = new Mumia();

        //Monstro por ser abstrato nao pode ser instanciado
        //Entretanto pode ser usado como tipo de referencia
        //Pode ser criado um array de Monstros
        Monster[] monsters = new Monster[3];
        monsters[0] = new Mumia();
        monsters[1] = new Dracula();
        monsters[2] = new Zumbi();

        //Mumia mu = new Mumia();
        //Dracula conde = new Dracula();
        //Zumbi wd = new Zumbi();

        //mu.scare();
        //mu.scare(3); //Essa chamada, a superclasse nn tem, é apenas da subclasse Mumia
        //conde.scare();
        //conde.scare(3);
        //wd.scare();

        for(int i = 0; i < monsters.length; i++) {
            monsters[i].scare();
        }
    }
}
