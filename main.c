
#include <stdio.h>
#include <string.h>

int main() {
    char nomeArquivo[50];
    char linha[100];
    FILE *arquivoEntrada, *arquivoSaida;

    printf("lscompiler: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    arquivoEntrada = fopen(nomeArquivo, "r");
    arquivoSaida = fopen("tokens.txt", "w");

    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivoEntrada)) {
        int num;
        char instrucao[20];

        if (sscanf(linha, "%s %d", instrucao, &num) == 2) {
            if (strcmp(instrucao, "multiplique") == 0) {
                num *= 2;  // Ação específica para "multiplique"
            } else if (strcmp(instrucao, "some") == 0) {
                // Ação para "some"
            } else if (strcmp(instrucao, "diminua") == 0) {
                // Ação para "diminua"
            }

            fprintf(arquivoSaida, "%s %d\n", instrucao, num);
        } else {
            fprintf(arquivoSaida, "%s", linha);
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("lscompiler");

    return 0;
}