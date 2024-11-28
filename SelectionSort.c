#include <stdlib.h>
#include <time.h>

void SortAscending(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tam; ++j) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }
}

void SortIncreasing(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tam; ++j) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }
}

void SortDecreasing(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < tam; ++j) {
            if (v[j] > v[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = v[i];
        v[i] = v[maxIndex];
        v[maxIndex] = temp;
    }
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
    SortIncreasing(v, tam);
    end = clock();
    exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução para ordenar em ordem crescente: %.2f ms\n", exec_time);

    start = clock();
    SortDecreasing(v, tam);
    end = clock();
    exec_time = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execução para ordenar em ordem decrescente: %.2f ms\n", exec_time);

    free(v);
    return 0;
}
