#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
    printf("    21. Seno Hiperbolico (sinh)\n");  
    printf("    22. Cosseno Hiperbolico (cosh)\n"); 
    printf("    23. Tangente Hiperbolica (tanh)\n"); 
    printf("    24. Inverso (1/x)\n");           
    printf("    25. Arredondar para o Inteiro mais Proximo (round)\n");

    printf("  0. Sair\n");
    printf("-----------------------------------\n");
}

long long int fatorial(int n) {
    if (n < 0) {
        printf("Erro: Fatorial de numero negativo nao existe.\n");
        return 0;
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
    int int_num; 

    do {
        exibirMenu();
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: 
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 + num2;
                printf("Resultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 2: 
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 - num2;
                printf("Resultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 3: 
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 * num2;
                printf("Resultado: %.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 4:
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
            case 5: 
                printf("Digite a base: ");
                scanf("%lf", &num1);
                printf("Digite o expoente: ");
                scanf("%lf", &num2);
                resultado = pow(num1, num2);
                printf("Resultado: %.2lf ^ %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 6: 
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 >= 0) {
                    resultado = sqrt(num1);
                    printf("Resultado: Raiz quadrada de %.2lf = %.2lf\n", num1, resultado);
                } else {
                    printf("Erro: Nao e possivel calcular a raiz quadrada de um numero negativo.\n");
                }
                break;
            case 7: 
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = sin(num1);
                printf("Resultado: Seno(%.4lf rad) = %.4lf\n", num1, resultado);
                break;
            case 8: 
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = cos(num1);
                printf("Resultado: Cosseno(%.4lf rad) = %.4lf\n", num1, resultado);
                break;
            case 9: 
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
        
                if (fmod(num1, M_PI / 2) != 0 || (int)(num1 / (M_PI / 2)) % 2 == 0) {
                     resultado = tan(num1);
                     printf("Resultado: Tangente(%.4lf rad) = %.4lf\n", num1, resultado);
                } else {
                     printf("Erro: Tangente indefinida para este angulo (multiplo impar de PI/2).\n");
                }
                break;
            case 10:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 > 0) {
                    resultado = log(num1);
                    printf("Resultado: ln(%.2lf) = %.4lf\n", num1, resultado);
                } else {
                    printf("Erro: Logaritmo natural de numero nao positivo e indefinido.\n");
                }
                break;
            case 11:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 > 0) {
                    resultado = log10(num1);
                    printf("Resultado: log10(%.2lf) = %.4lf\n", num1, resultado);
                } else {
                    printf("Erro: Logaritmo base 10 de numero nao positivo e indefinido.\n");
                }
                break;
            case 12: 
                printf("Digite o expoente: ");
                scanf("%lf", &num1);
                resultado = exp(num1);
                printf("Resultado: e^(%.2lf) = %.4lf\n", num1, resultado);
                break;
            case 13:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = fabs(num1); 
                printf("Resultado: |%.2lf| = %.2lf\n", num1, resultado);
                break;
            case 14: 
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = ceil(num1);
                printf("Resultado: ceil(%.2lf) = %.2lf\n", num1, resultado);
                break;
            case 15: 
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = floor(num1);
                printf("Resultado: floor(%.2lf) = %.2lf\n", num1, resultado);
                break;
            case 16: 
                printf("Digite um numero inteiro nao negativo: ");
                scanf("%d", &int_num);
                if (int_num >= 0) {
                    long long int fat_resultado = fatorial(int_num);
                    if (fat_resultado != 0) { 
                        printf("Resultado: %d! = %lld\n", int_num, fat_resultado);
                    }
                } else {
                    printf("Erro: Fatorial de numero negativo nao existe.\n");
                }
                break;
            case 17: 
                printf("Digite o dividendo (inteiro): ");
                scanf("%lf", &num1);
                printf("Digite o divisor (inteiro): ");
                scanf("%lf", &num2); 

                if ((int)num2 != 0) {
                    resultado = fmod(num1, num2); 
                    printf("Resultado: %.0lf %% %.0lf = %.0lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisao por zero para o modulo!\n");
                }
                break;
            case 18:
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
            case 19: 
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = num1 * (180.0 / M_PI);
                printf("Resultado: %.4lf radianos = %.4lf graus\n", num1, resultado);
                break;
            case 20: 
                printf("Digite o angulo em graus: ");
                scanf("%lf", &num1);
                resultado = num1 * (M_PI / 180.0);
                printf("Resultado: %.4lf graus = %.4lf radianos\n", num1, resultado);
                break;
            case 21:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = sinh(num1);
                printf("Resultado: sinh(%.2lf) = %.4lf\n", num1, resultado);
                break;
            case 22:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = cosh(num1);
                printf("Resultado: cosh(%.2lf) = %.4lf\n", num1, resultado);
                break;
            case 23:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = tanh(num1);
                printf("Resultado: tanh(%.2lf) = %.4lf\n", num1, resultado);
                break;
            case 24: 
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 != 0) {
                    resultado = 1.0 / num1;
                    printf("Resultado: 1/%.2lf = %.4lf\n", num1, resultado);
                } else {
                    printf("Erro: Nao e possivel calcular o inverso de zero.\n");
                }
                break;
            case 25:
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = round(num1);
                printf("Resultado: round(%.2lf) = %.0lf\n", num1, resultado);
                break;
            case 0: 
                printf("Saindo da calculadora. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
        printf("\nPressione Enter para continuar...");
        getchar();
        getchar(); 
    } while (escolha != 0);

    return 0;
}
