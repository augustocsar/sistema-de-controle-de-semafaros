# Simulador de Controle de Tráfego com Processos e Threads

Este projeto implementa um sistema simples em C que simula o monitoramento de dois cruzamentos de tráfego. Ele utiliza processos (via `fork()`) e threads POSIX (`pthread`) para demonstrar conceitos de concorrência em um ambiente Linux (ou WSL - Windows Subsystem for Linux).

Desenvolvido como parte de um trabalho acadêmico para a disciplina de **[Nome da Disciplina - Substitua aqui]**.

## Funcionalidades

*   Criação de um processo pai que gerencia dois processos filhos.
*   Cada processo filho simula um "cruzamento".
*   Cada processo filho cria e gerencia duas threads para realizar tarefas computacionais:
    *   **Thread 1:** Calcula a soma de números pares até um limite fornecido pelo usuário.
    *   **Thread 2:** Calcula o fatorial de um número fornecido pelo usuário.
*   Demonstra o uso de `fork()` para criação de processos.
*   Demonstra o uso de `pthread_create()` para criação de threads POSIX.
*   Demonstra a sincronização entre processos (`waitpid()`) e threads (`pthread_join()`).
*   Interage com o usuário para obter os parâmetros de cálculo para cada cruzamento.

## Pré-requisitos

*   Um ambiente Linux ou WSL (Windows Subsystem for Linux).
*   Compilador C (como o GCC).
*   Biblioteca `pthreads` (geralmente já inclusa nas distribuições Linux e no GCC).

## Compilação

Para compilar o código, utilize o GCC (ou outro compilador C) com o flag `-lpthread` para linkar a biblioteca de threads:

```bash
gcc controle_trafego.c -o controle_trafego -lpthread
```

Isso criará um executável chamado controle_trafego.
Execução
Para executar o programa compilado:

./controle_trafego

O programa solicitará que você digite:
O limite para a soma dos pares para o Cruzamento 1.
O número para calcular o fatorial para o Cruzamento 1.
O limite para a soma dos pares para o Cruzamento 2.
O número para calcular o fatorial para o Cruzamento 2.
Após receber as entradas, o processo pai criará os processos filhos, que por sua vez criarão as threads. A saída mostrará mensagens indicando o início e o fim dos processos e threads, bem como os resultados dos cálculos.
Estrutura do Código
main(): Função principal executada pelo processo pai. Responsável por obter a entrada do usuário, criar os dois processos filhos (fork()) e esperar que eles terminem (waitpid()).
controlar_cruzamento(): Função executada por cada processo filho. Responsável por criar as duas threads de trabalho (pthread_create()) e esperar que elas terminem (pthread_join()).
soma_pares(): Função executada pela primeira thread de cada processo filho. Calcula a soma dos números pares até o limite especificado.
calcula_fatorial(): Função executada pela segunda thread de cada processo filho. Calcula o fatorial do número especificado.

Autor
Augusto César
