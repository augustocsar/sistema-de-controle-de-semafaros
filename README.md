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
