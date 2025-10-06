#include <stdio.h> // Para entrada e saída (printf, scanf)
#include <math.h>  // Para funções matemáticas (sqrt, pow, sin, cos, etc.)
#include <stdlib.h> // Para funções como abs, e para exit() se necessário

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n--- Calculadora Cientifica em C ---\n");
    printf("Escolha uma operacao:\n");
    printf("  Operacoes Basicas:\n");
    printf("    1. Adicao (+)\n");
    printf("    2. Subtracao (-)\n");
    printf("    3. Multiplicacao (*)\n");
    printf("    4. Divisao (/)\n");
    printf("  Funcoes Matematicas:\n");
    printf("    5. Potencia (x^y)\n");
    printf("    6. Raiz Quadrada (sqrt)\n");
    printf("    7. Seno (sin)\n");
    printf("    8. Cosseno (cos)\n");
    printf("    9. Tangente (tan)\n");
    printf("    10. Logaritmo Natural (ln)\n");
    printf("    11. Logaritmo Base 10 (log10)\n"); 
    printf("    12. Exponencial (e^x)\n");         
    printf("    13. Valor Absoluto (abs)\n");      
    printf("    14. Arredondar para Cima (ceil)\n"); 
    printf("    15. Arredondar para Baixo (floor)\n"); 
    printf("    16. Fatorial (!)\n");              
    printf("  Operacoes Adicionais:\n");
    printf("    17. Resto da Divisao (Modulo %%)\n"); 
    printf("    18. Hipotenusa (hypot)\n");      
    printf("    19. Converter Radianos para Graus (rad2deg)\n"); 
    printf("    20. Converter Graus para Radianos (deg2rad)\n"); 

    printf("  0. Sair\n");
    printf("-----------------------------------\n");
}

// Função para calcular o fatorial (inteiros não negativos)
long long int fatorial(int n) {
    if (n < 0) {
        printf("Erro: Fatorial de numero negativo nao existe.\n");
        return 0; // Ou algum valor de erro
    }
    if (n == 0 || n == 1) {
        return 1;
    } else {
        long long int res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }
}

int main() {
    int escolha;
    double num1, num2, resultado;
    int int_num; // Para funções que exigem um inteiro

    do {
        exibirMenu();
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: // Adição
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 + num2;
                printf("Resultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 2: // Subtração
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 - num2;
                printf("Resultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 3: // Multiplicação
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 * num2;
                printf("Resultado: %.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 4: // Divisão
                printf("Digite o dividendo: ");
                scanf("%lf", &num1);
                printf("Digite o divisor: ");
                scanf("%lf", &num2);
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisao por zero!\n");
                }
                break;
            case 5: // Potência
                printf("Digite a base: ");
                scanf("%lf", &num1);
                printf("Digite o expoente: ");
                scanf("%lf", &num2);
                resultado = pow(num1, num2);
                printf("Resultado: %.2lf ^ %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 6: // Raiz Quadrada
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    resultado = sqrt(num1);
                    printf("Resultado: Raiz quadrada de %.2lf = %.2lf\n", num1, resultado);
                } else {
                    printf("Erro: Nao e possivel calcular a raiz quadrada de um numero negativo.\n");
                }
                break;
            case 7: // Seno (em radianos)
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = sin(num1);
                printf("Resultado: Seno(%.4lf rad) = %.4lf\n", num1, resultado);
                break;
            case 8: // Cosseno (em radianos)
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = cos(num1);
                printf("Resultado: Cosseno(%.4lf rad) = %.4lf\n", num1, resultado);
                break;
            case 9: // Tangente (em radianos)
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                // Verifica se o ângulo não é um múltiplo ímpar de PI/2, onde a tangente é indefinida
                if (fmod(num1, M_PI / 2) != 0 || (int)(num1 / (M_PI / 2)) % 2 == 0) { // Simplificação, mas cuidado com precisão de float
                     resultado = tan(num1);
                     printf("Resultado: Tangente(%.4lf rad) = %.4lf\n", num1, resultado);
                } else {
                     printf("Erro: Tangente indefinida para este angulo (multiplo impar de PI/2).\n");
                }
                break;
            case 10: // Logaritmo Natural (ln)
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 > 0) {
                    resultado = log(num1);
                    printf("Resultado: ln(%.2lf) = %.4lf\n", num1, resultado);
                } else {
                    printf("Erro: Logaritmo natural de numero nao positivo e indefinido.\n");
                }
                break;
            case 11: // Logaritmo Base 10 (log10) - Adicionada
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 > 0) {
                    resultado = log10(num1);
                    printf("Resultado: log10(%.2lf) = %.4lf\n", num1, resultado);
                } else {
                    printf("Erro: Logaritmo base 10 de numero nao positivo e indefinido.\n");
                }
                break;
            case 12: // Exponencial (e^x) - Adicionada
                printf("Digite o expoente: ");
                scanf("%lf", &num1);
                resultado = exp(num1);
                printf("Resultado: e^(%.2lf) = %.4lf\n", num1, resultado);
                break;
            case 13: // Valor Absoluto (abs para inteiros, fabs para doubles) - Adicionada
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = fabs(num1); // fabs para double
                printf("Resultado: |%.2lf| = %.2lf\n", num1, resultado);
                break;
            case 14: // Arredondar para Cima (ceil) - Adicionada
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = ceil(num1);
                printf("Resultado: ceil(%.2lf) = %.2lf\n", num1, resultado);
                break;
            case 15: // Arredondar para Baixo (floor) - Adicionada
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = floor(num1);
                printf("Resultado: floor(%.2lf) = %.2lf\n", num1, resultado);
                break;
            case 16: // Fatorial
                printf("Digite um numero inteiro nao negativo: ");
                scanf("%d", &int_num);
                if (int_num >= 0) {
                    long long int fat_resultado = fatorial(int_num);
                    if (fat_resultado != 0) { // 0 é o valor de erro retornado por fatorial
                        printf("Resultado: %d! = %lld\n", int_num, fat_resultado);
                    }
                } else {
                    printf("Erro: Fatorial de numero negativo nao existe.\n");
                }
                break;
            case 17: // Resto da Divisao (Modulo %) - Adicionada
                printf("Digite o dividendo (inteiro): ");
                scanf("%lf", &num1); // Ler como double para consistência, converter para int
                printf("Digite o divisor (inteiro): ");
                scanf("%lf", &num2); // Ler como double, converter para int

                if ((int)num2 != 0) {
                    resultado = fmod(num1, num2); // fmod para doubles
                    printf("Resultado: %.0lf %% %.0lf = %.0lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisao por zero para o modulo!\n");
                }
                break;
            case 18: // Hipotenusa (hypot) - Adicionada
                printf("Digite o comprimento do primeiro cateto: ");
                scanf("%lf", &num1);
                printf("Digite o comprimento do segundo cateto: ");
                scanf("%lf", &num2);
                if (num1 >= 0 && num2 >= 0) {
                    resultado = hypot(num1, num2);
                    printf("Resultado: Hipotenusa de catetos %.2lf e %.2lf = %.2lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Catetos devem ser valores nao negativos.\n");
                }
                break;
            case 19: // Converter Radianos para Graus (rad2deg) - Adicionada
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = num1 * (180.0 / M_PI);
                printf("Resultado: %.4lf radianos = %.4lf graus\n", num1, resultado);
                break;
            case 20: // Converter Graus para Radianos (deg2rad) - Adicionada
                printf("Digite o angulo em graus: ");
                scanf("%lf", &num1);
                resultado = num1 * (M_PI / 180.0);
                printf("Resultado: %.4lf graus = %.4lf radianos\n", num1, resultado);
                break;
            case 0: // Sair
                printf("Saindo da calculadora. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
        printf("\nPressione Enter para continuar...");
        getchar(); // Consome o '\n' restante do scanf
        getchar(); // Espera por outro Enter
    } while (escolha != 0);

    return 0;
}
