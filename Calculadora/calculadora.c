#include <stdio.h> // Para entrada e saída (printf, scanf)
#include <math.h>  // Para funções matemáticas (sqrt, pow, sin, cos, etc.)
#include <stdlib.h> // Para funções como abs (valor absoluto de int), embora fabs de math.h seja para double

// Define M_PI se não estiver automaticamente definido por math.h.
// M_PI é a constante para o valor de PI (aproximadamente 3.14159...).
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Função: exibirMenu
// Propósito: Exibe o menu de opções da calculadora para o usuário.
// Retorno: Nenhum (void).
// Variáveis internas: Nenhuma, apenas imprime texto.
void exibirMenu() {
    // Imprime um título para o menu.
    printf("\n--- Calculadora Cientifica em C ---\n");
    // Imprime a instrução principal.
    printf("Escolha uma operacao:\n");
    // Categorias de operações para organização.
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
    // Opção para sair da calculadora.
    printf("  0. Sair\n");
    // Linha divisória para estética.
    printf("-----------------------------------\n");
}

// Função: fatorial
// Propósito: Calcula o fatorial de um número inteiro não negativo.
// Parâmetros:
//   - int n: O número para o qual o fatorial será calculado.
// Retorno: long long int, o resultado do fatorial, ou 0 em caso de erro.
// Variáveis internas:
//   - long long int res: Armazena o resultado do cálculo do fatorial, usando long long
//     para suportar números maiores.
//   - int i: Variável de controle para o loop for.
long long int fatorial(int n) {
    // Verifica se a entrada é um número negativo (fatorial não definido).
    if (n < 0) {
        printf("Erro: Fatorial de numero negativo nao existe.\n");
        return 0; // Retorna 0 para indicar um erro.
    }
    // Casos base: fatorial de 0 ou 1 é 1.
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Inicializa o resultado com 1.
        long long int res = 1;
        // Loop para multiplicar os números de 2 até n.
        for (int i = 2; i <= n; i++) {
            res *= i; // Multiplica o resultado pelo próximo número.
        }
        return res; // Retorna o fatorial calculado.
    }
}

// Função: main
// Propósito: É a função principal onde o programa começa a execução.
// Retorno: int, geralmente 0 para indicar sucesso.
// Variáveis internas:
//   - int escolha: Armazena a opção selecionada pelo usuário no menu.
//   - double num1, num2: Usadas para armazenar os números de entrada para a maioria das operações
//     (tipo double para números decimais).
//   - double resultado: Armazena o resultado de uma operação.
//   - int int_num: Usada especificamente para funções que precisam de uma entrada inteira, como fatorial.
int main() {
    int escolha;
    double num1, num2, resultado;
    int int_num;

    // Loop do-while: Garante que a calculadora continue rodando até o usuário escolher "0" (Sair).
    do {
        // Chama a função para exibir o menu.
        exibirMenu();
        // Pede ao usuário para digitar sua escolha.
        printf("Digite sua escolha: ");
        // Lê a escolha do usuário (um inteiro) e armazena na variável 'escolha'.
        scanf("%d", &escolha);

        // Bloco switch: Executa o código correspondente à opção escolhida pelo usuário.
        switch (escolha) {
            case 1: // Adição
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1); // Lê o primeiro número (double).
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2); // Lê o segundo número (double).
                resultado = num1 + num2; // Realiza a soma.
                printf("Resultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado); // Exibe o resultado formatado.
                break; // Sai do switch.
            case 2: // Subtração
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 - num2; // Realiza a subtração.
                printf("Resultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 3: // Multiplicação
                printf("Digite o primeiro numero: ");
                scanf("%lf", &num1);
                printf("Digite o segundo numero: ");
                scanf("%lf", &num2);
                resultado = num1 * num2; // Realiza a multiplicação.
                printf("Resultado: %.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 4: // Divisão
                printf("Digite o dividendo: ");
                scanf("%lf", &num1);
                printf("Digite o divisor: ");
                scanf("%lf", &num2);
                // Verifica se o divisor não é zero para evitar erro de divisão por zero.
                if (num2 != 0) {
                    resultado = num1 / num2; // Realiza a divisão.
                    printf("Resultado: %.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisao por zero!\n"); // Mensagem de erro.
                }
                break;
            case 5: // Potência (x^y)
                printf("Digite a base: ");
                scanf("%lf", &num1);
                printf("Digite o expoente: ");
                scanf("%lf", &num2);
                resultado = pow(num1, num2); // Calcula a potência usando a função pow() de math.h.
                printf("Resultado: %.2lf ^ %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case 6: // Raiz Quadrada (sqrt)
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                // Verifica se o número não é negativo para evitar erro de raiz de número negativo.
                if (num1 >= 0) {
                    resultado = sqrt(num1); // Calcula a raiz quadrada usando a função sqrt() de math.h.
                    printf("Resultado: Raiz quadrada de %.2lf = %.2lf\n", num1, resultado);
                } else {
                    printf("Erro: Nao e possivel calcular a raiz quadrada de um numero negativo.\n");
                }
                break;
            case 7: // Seno (sin) - Espera o ângulo em radianos.
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = sin(num1); // Calcula o seno usando a função sin() de math.h.
                printf("Resultado: Seno(%.4lf rad) = %.4lf\n", num1, resultado);
                break;
            case 8: // Cosseno (cos) - Espera o ângulo em radianos.
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = cos(num1); // Calcula o cosseno usando a função cos() de math.h.
                printf("Resultado: Cosseno(%.4lf rad) = %.4lf\n", num1, resultado);
                break;
            case 9: // Tangente (tan) - Espera o ângulo em radianos.
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                // Verifica se o ângulo não é um múltiplo ímpar de PI/2 (onde tan é indefinida).
                // fmod(num1, M_PI / 2) != 0: verifica se não é múltiplo exato.
                // (int)(num1 / (M_PI / 2)) % 2 == 0: verifica se o múltiplo é par (para evitar 90, 270, etc. graus).
                if (fmod(num1, M_PI / 2) != 0 || (int)(num1 / (M_PI / 2)) % 2 == 0) {
                     resultado = tan(num1); // Calcula a tangente usando a função tan() de math.h.
                     printf("Resultado: Tangente(%.4lf rad) = %.4lf\n", num1, resultado);
                } else {
                     printf("Erro: Tangente indefinida para este angulo (multiplo impar de PI/2).\n");
                }
                break;
            case 10: // Logaritmo Natural (ln ou log)
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                // Verifica se o número é positivo (log de 0 ou negativo é indefinido).
                if (num1 > 0) {
                    resultado = log(num1); // Calcula o logaritmo natural usando a função log() de math.h.
                    printf("Resultado: ln(%.2lf) = %.4lf\n", num1, resultado);
                } else {
                    printf("Erro: Logaritmo natural de numero nao positivo e indefinido.\n");
                }
                break;
            case 11: // Logaritmo Base 10 (log10)
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                if (num1 > 0) {
                    resultado = log10(num1); // Calcula o logaritmo base 10 usando a função log10() de math.h.
                    printf("Resultado: log10(%.2lf) = %.4lf\n", num1, resultado);
                } else {
                    printf("Erro: Logaritmo base 10 de numero nao positivo e indefinido.\n");
                }
                break;
            case 12: // Exponencial (e^x)
                printf("Digite o expoente: ");
                scanf("%lf", &num1);
                resultado = exp(num1); // Calcula e (base do logaritmo natural) elevado a num1 usando exp() de math.h.
                printf("Resultado: e^(%.2lf) = %.4lf\n", num1, resultado);
                break;
            case 13: // Valor Absoluto (fabs)
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = fabs(num1); // Calcula o valor absoluto (sem sinal) usando fabs() de math.h (para double).
                printf("Resultado: |%.2lf| = %.2lf\n", num1, resultado);
                break;
            case 14: // Arredondar para Cima (ceil)
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = ceil(num1); // Arredonda para o menor inteiro que é maior ou igual a num1, usando ceil() de math.h.
                printf("Resultado: ceil(%.2lf) = %.2lf\n", num1, resultado);
                break;
            case 15: // Arredondar para Baixo (floor)
                printf("Digite o numero: ");
                scanf("%lf", &num1);
                resultado = floor(num1); // Arredonda para o maior inteiro que é menor ou igual a num1, usando floor() de math.h.
                printf("Resultado: floor(%.2lf) = %.2lf\n", num1, resultado);
                break;
            case 16: // Fatorial
                printf("Digite um numero inteiro nao negativo: ");
                scanf("%d", &int_num); // Lê um número inteiro para o fatorial.
                if (int_num >= 0) {
                    long long int fat_resultado = fatorial(int_num); // Chama a função fatorial auxiliar.
                    if (fat_resultado != 0) { // Se o fatorial foi calculado sem erro.
                        printf("Resultado: %d! = %lld\n", int_num, fat_resultado);
                    }
                } else {
                    printf("Erro: Fatorial de numero negativo nao existe.\n");
                }
                break;
            case 17: // Resto da Divisão (Modulo %) para doubles
                printf("Digite o dividendo (inteiro): ");
                scanf("%lf", &num1);
                printf("Digite o divisor (inteiro): ");
                scanf("%lf", &num2);
                if ((int)num2 != 0) { // Converte num2 para int para verificar divisão por zero.
                    resultado = fmod(num1, num2); // Calcula o resto da divisão para doubles usando fmod() de math.h.
                    printf("Resultado: %.0lf %% %.0lf = %.0lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisao por zero para o modulo!\n");
                }
                break;
            case 18: // Hipotenusa (hypot)
                printf("Digite o comprimento do primeiro cateto: ");
                scanf("%lf", &num1);
                printf("Digite o comprimento do segundo cateto: ");
                scanf("%lf", &num2);
                // Catetos não podem ser negativos.
                if (num1 >= 0 && num2 >= 0) {
                    resultado = hypot(num1, num2); // Calcula a hipotenusa usando hypot() de math.h (sqrt(a^2 + b^2)).
                    printf("Resultado: Hipotenusa de catetos %.2lf e %.2lf = %.2lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Catetos devem ser valores nao negativos.\n");
                }
                break;
            case 19: // Converter Radianos para Graus
                printf("Digite o angulo em radianos: ");
                scanf("%lf", &num1);
                resultado = num1 * (180.0 / M_PI); // Fórmula: radianos * (180 / PI).
                printf("Resultado: %.4lf radianos = %.4lf graus\n", num1, resultado);
                break;
            case 20: // Converter Graus para Radianos
                printf("Digite o angulo em graus: ");
                scanf("%lf", &num1);
                resultado = num1 * (M_PI / 180.0); // Fórmula: graus * (PI / 180).
                printf("Resultado: %.4lf graus = %.4lf radianos\n", num1, resultado);
                break;
            case 0: // Sair da calculadora
                printf("Saindo da calculadora. Ate mais!\n");
                break; // Sai do switch e o loop 'do-while' terminará.
            default: // Opção inválida
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
                break;
        }
        // Condição para pausar a tela, exceto quando o usuário escolhe sair.
        if (escolha != 0) {
            printf("\nPressione Enter para continuar...");
            // Consome o caractere '\n' que pode ter sobrado do scanf anterior.
            // Isso evita que o segundo getchar() seja ignorado.
            getchar();
            // Espera o usuário pressionar Enter antes de exibir o menu novamente.
            getchar();
        }
    } while (escolha != 0); // O loop continua enquanto a escolha não for 0.

    return 0; // Indica que o programa terminou com sucesso.
}