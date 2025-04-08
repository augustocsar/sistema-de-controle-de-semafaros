#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// Função da Thread 1: Calcula a soma de números pares em um intervalo
void *soma_pares(void *arg) {
  long intervalo = *((long *)arg); // Usando long para suportar números maiores
  long long soma = 0;              // Usando long long para evitar overflow
  for (long i = 0; i <= intervalo; i += 2) {
    soma += i;
    usleep(100); // Pequeno atraso para simular processamento
  }
  printf("Thread 1 (Cruzamento %d): Soma dos pares até %ld = %lld\n", getpid(),
         intervalo, soma);
  return NULL;
}

// Função da Thread 2: Calcula o fatorial de um número
void *calcula_fatorial(void *arg) {
  int numero = *((int *)arg);
  unsigned long long fatorial = 1;
  for (int i = 1; i <= numero; i++) {
    fatorial *= i;
    usleep(100); // Pequeno atraso para simular processamento
  }
  printf("Thread 2 (Cruzamento %d): Fatorial de %d = %llu\n", getpid(), numero,
         fatorial);
  return NULL;
}

// Função para simular o controle de um cruzamento
void controlar_cruzamento(int id_cruzamento, long intervalo, int capacidade) {
  pthread_t thread1, thread2;

  // Criando Thread 1
  pthread_create(&thread1, NULL, soma_pares, &intervalo);
  // Criando Thread 2
  pthread_create(&thread2, NULL, calcula_fatorial, &capacidade);

  // Sincronizando as threads
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("Cruzamento %d (PID %d) finalizado.\n", id_cruzamento, getpid());
}

int main() {
  pid_t pid1, pid2;
  long intervalo1, intervalo2;
  int capacidade1, capacidade2;

  // Solicitando entradas para o Cruzamento 1
  printf("=== Configuração do Cruzamento 1 ===\n");
  printf("Digite o intervalo para a soma dos pares (ex.: 1000000): ");
  scanf("%ld", &intervalo1);
  printf("Digite o número para calcular o fatorial (ex.: 15): ");
  scanf("%d", &capacidade1);

  // Solicitando entradas para o Cruzamento 2
  printf("\n=== Configuração do Cruzamento 2 ===\n");
  printf("Digite o intervalo para a soma dos pares (ex.: 2000000): ");
  scanf("%ld", &intervalo2);
  printf("Digite o número para calcular o fatorial (ex.: 16): ");
  scanf("%d", &capacidade2);

  // Criando o primeiro processo filho (Cruzamento 1)
  pid1 = fork();
  if (pid1 < 0) {
    perror("Erro ao criar processo para Cruzamento 1");
    exit(1);
  } else if (pid1 == 0) {
    // Processo filho 1: Cruzamento 1
    controlar_cruzamento(1, intervalo1, capacidade1);
    exit(0);
  }

  // Criando o segundo processo filho (Cruzamento 2)
  pid2 = fork();
  if (pid2 < 0) {
    perror("Erro ao criar processo para Cruzamento 2");
    exit(1);
  } else if (pid2 == 0) {
    // Processo filho 2: Cruzamento 2
    controlar_cruzamento(2, intervalo2, capacidade2);
    exit(0);
  }

  // Processo pai espera os filhos terminarem
  wait(NULL); // Espera o primeiro filho
  wait(NULL); // Espera o segundo filho

  printf("Processo pai (PID %d) finalizado.\n", getpid());
  return 0;
}