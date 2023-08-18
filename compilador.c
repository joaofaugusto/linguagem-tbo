#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivoSaida;
    char linha[100];
    int resultado = 0;

    arquivoSaida = fopen("tokens.txt", "r");

    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivoSaida)) {
        int posicaoDoMultiplique = -1;
        int posicaoDoSome = -1;
        int posicaoDoDiminua = -1;
        char instrucao[20];
        int num;

        if (sscanf(linha, "%s %d", instrucao, &num) == 2) {
            if (strcmp(instrucao, "multiplique") == 0) {
                posicaoDoMultiplique = num;
            } else if (strcmp(instrucao, "some") == 0) {
                posicaoDoSome = num;
            } else if (strcmp(instrucao, "diminua") == 0) {
                posicaoDoDiminua = num;
            }
        }

        if (posicaoDoMultiplique != -1) {
            int sentencaAnterior = posicaoDoMultiplique - 1;
            int sentencaPosterior = posicaoDoMultiplique + 1;
            resultado = sentencaAnterior * sentencaPosterior;
            printf("Resultado: %d\n", resultado);
        } else {
            if (posicaoDoSome != -1) {
                int sentencaAnterior = posicaoDoSome - 1;
                int sentencaPosterior = posicaoDoSome + 1;
                resultado = sentencaAnterior + sentencaPosterior;
                printf("Resultado: %d\n", resultado);
            } else {
                if (posicaoDoDiminua != -1) {
                    int sentencaAnterior = posicaoDoDiminua - 1;
                    int sentencaPosterior = posicaoDoDiminua + 1;
                    resultado = sentencaAnterior - sentencaPosterior;
                    printf("Resultado: %d\n", resultado);
                }
            }
        }
    }

    fclose(arquivoSaida);

    return 0;
}