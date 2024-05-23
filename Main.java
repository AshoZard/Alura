import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        float numero;
        float soma = 0f;
        int contador = 0;
        for(int i = 0; i<10; i++){
            try{
                numero = scanner.nextFloat();
                soma += numero;
                contador++;
            }catch (Exception ex){
                scanner.next();
            }
        }
        soma /= contador;
        System.out.printf("Entradas aceitas: %d, média: %.2f\r\n", contador, soma);
    }

    public String getTemperatura(double vetor[], int indice){
        try{
            return("Temperatura["+indice+"]: "+vetor[indice]);
        }catch (Exception ex){
            return ("Erro! Dados da exceção: " + ex.getMessage());
        }
    }
}