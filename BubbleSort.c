#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SortAscending(int v[], int tam) {
    int troca;
    do {
        troca = 0;
        for (int i = 0; i < tam - 1; i++) {
            if (v[i] > v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                troca = 1;
            }
        }
        tam--;
    } while (troca != 0);
}

void SortAscendingOrder(int v[], int tam) {
    int troca;
    do {
        troca = 0;
        for (int i = 0; i < tam - 1; i++) {
            if (v[i] > v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                troca = 1;
            }
        }
        tam--;
    } while (troca != 0);
}

void SortDescending(int v[], int tam) {
    int troca;
    do {
        troca = 0;
        for (int i = 0; i < tam - 1; i++) {
            if (v[i] < v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                troca = 1;
            }
        }
        tam--;
    } while (troca != 0);
}

int main() {
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int *v = (int *)malloc(tam * sizeof(int));
    if (v == NULL) {
        printf("Falha de memória!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % 10000;
    }

    clock_t start = clock();
    SortAscending(v, tam);
    clock_t end = clock();

    double exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução do SortAscending: %.2f ms\n", exec_time);

    start = clock();
    SortAscendingOrder(v, tam);
    end = clock();
    exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução para ordenar em ordem crescente: %.2f ms\n", exec_time);

    start = clock();
    SortDescending(v, tam);
    end = clock();
    exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução para ordenar em ordem decrescente: %.2f ms\n", exec_time);

    free(v);
    return 0;
}
