#include <stdio.h>

int main() {
    int v[100], numero, i, j, temp, opcao, pos, novo;
    FILE *arq;

    do {
        printf("\n1 - Criar arquivo");
        printf("\n2 - Ordenar numeros");
        printf("\n3 - Alterar valor");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            arq = fopen("dados.txt", "w");

            printf("Quantidade de numeros (maximo 100): ");
            scanf("%d", &numero);

            if (numero < 1 || numero > 100) {
                printf("Quantidade invalida!\n");
                fclose(arq);
                continue;
            }

            for (i = 0; i < numero; i++) {
                printf("Digite um numero: ");
                scanf("%d", &v[i]);
                fprintf(arq, "%d\n", v[i]);
            }

            fclose(arq);
            printf("Arquivo criado!\n");
        }

        else if (opcao == 2) {
            arq = fopen("dados.txt", "r");

            if (arq == NULL) {
                printf("Crie o arquivo primeiro!\n");
                continue;
            }

            numero = 0;
            while (numero < 100 && fscanf(arq, "%d", &v[numero]) == 1)
                numero++;

            fclose(arq);

            for (i = 0; i < numero - 1; i++) {
                for (j = 0; j < numero - i - 1; j++) {
                    if (v[j] > v[j + 1]) {
                        temp = v[j];
                        v[j] = v[j + 1];
                        v[j + 1] = temp;
                    }
                }
            }

            arq = fopen("ordenado.txt", "w");

            if (arq == NULL) {
                printf("Erro ao salvar!\n");
                continue;
            }

            for (i = 0; i < numero; i++) {
                printf("%d ", v[i]);
                fprintf(arq, "%d\n", v[i]);
            }

            fclose(arq);
            printf("\nOrdenado e salvo!\n");
        }

        else if (opcao == 3) {
            arq = fopen("dados.txt", "r");

            if (arq == NULL) {
                printf("Crie o arquivo primeiro!\n");
                continue;
            }

            numero = 0;
            while (numero < 100 && fscanf(arq, "%d", &v[numero]) == 1)
                numero++;

            fclose(arq);

            printf("Posicao para alterar (1 a %d): ", numero);
            scanf("%d", &pos);

            if (pos < 1 || pos > numero) {
                printf("Posicao invalida!\n");
                continue;
            }

            printf("Novo valor: ");
            scanf("%d", &novo);
            v[pos - 1] = novo;

            arq = fopen("dados.txt", "w");

            if (arq == NULL) {
                printf("Erro ao atualizar!\n");
                continue;
            }

            for (i = 0; i < numero; i++)
                fprintf(arq, "%d\n", v[i]);

            fclose(arq);
            printf("Valor alterado! Ordene novamente pela opcao 2.\n");
        }

    } while (opcao != 4);

    return 0;
}
