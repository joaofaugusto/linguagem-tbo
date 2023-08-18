#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivoSaida;
    char linha[100];

    arquivoSaida = fopen("teste.joao", "r");

    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivoSaida)) {
        int resultado = 0;
        int num, temp;
        char instrucao[20];
        char *token;
        int multiplicacao = 0;

        token = strtok(linha, " ");

        while (token != NULL) {
            if (multiplicacao) {
                token = strtok(NULL, " ");
                num = atoi(token);
                resultado *= num;
                multiplicacao = 0;
            } else {
                strcpy(instrucao, token);

                if (strcmp(instrucao, "multiplique") == 0) {
                    multiplicacao = 1;
                } else {
                    token = strtok(NULL, " ");
                    num = atoi(token);

                    if (strcmp(instrucao, "some") == 0) {
                        resultado += num;
                    } else if (strcmp(instrucao, "diminua") == 0) {
                        resultado -= num;
                    }
                }
            }
            token = strtok(NULL, " ");
        }

        printf("tbo-compiler: %d\n", resultado);
    }

    fclose(arquivoSaida);

    return 0;
}
