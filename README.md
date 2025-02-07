# Algoritmos e Estruturas de Dados em C

Este repositório contém implementações modulares de algoritmos e estruturas de dados utilizando a linguagem C. O objetivo é criar uma biblioteca reutilizável que auxilie no aprendizado, prática e consulta de conceitos fundamentais e avançados em programação.

---

## 📂 Estrutura do Repositório

O repositório é organizado em pastas para facilitar a navegação e separação de responsabilidades:

```
/algorithms
    /search
    /sorting
/structures
    /lists
    /trees
    /graphs
```

- **algorithms/**: Contém implementações de algoritmos, como busca e ordenação.
- **structures/**: Inclui estruturas de dados fundamentais e avançadas.

---

## 📑 Implementações

### Estruturas de Dados
1. **Listas Ligadas**
   - Inserção no início/fim.
   - Remoção de nós.
   - Busca em uma lista.
   - Arquivos: `linked_list.h`, `linked_list.c`.

2. **Pilhas e Filas**
   - Pilhas (push, pop, peek).
   - Filas (enqueue, dequeue, front).
   - Arquivos: `stack.h`, `queue.h`.

3. **Vetores Dinâmicos**
   - Criação dinâmica.
   - Inserção, remoção e obtenção de tamanho.
   - Arquivos: `vector.h`.

4. **Árvores**
   - Árvores Binárias e Árvores de Busca Binária (BST).
   - Travessias: In-Order, Pre-Order, Post-Order.
   - Arquivos: `tree.h`.

5. **Heaps**
   - Min-Heap e Max-Heap.
   - Operações de inserção, remoção e heapify.
   - Arquivos: `heap.h`.

6. **Tabelas Hash**
   - Gerenciamento de colisões (separação encadeada).
   - Inserção, remoção e busca.
   - Arquivos: `hash_table.h`.

7. **Grafos**
   - Representação por listas e matrizes de adjacências.
   - Adicionar/remover arestas e vértices.
   - Busca por vizinhos.
   - Arquivos: `graph.h`.

---

### Algoritmos
1. **Busca**
   - Busca Binária (`binary_search.h`).
   - Busca em Largura (BFS, `bfs.h`).
   - Busca em Profundidade (DFS, `dfs.h`).

2. **Ordenação**
   - Merge Sort.
   - Quick Sort.
   - Bubble Sort.
   - Arquivos: `sorting.h`.

3. **Algoritmos para Árvores**
   - Inserção, busca e remoção em BSTs.
   - Travessias.
   - Arquivos: `tree_algorithms.h`.

---

## 🛠️ Como Usar

### 1. Compilação
Para compilar as bibliotecas, utilize o Makefile:

Na raiz do projeto, digite:
```bash
mingw32-make
```

### 2. Execução
Rode o executável gerado na pasta bin:

```bash
.\main
```

---

## 🧪 Testes

Os testes básicos podem ser feitos com um arquivo `main.c`.

---

## 🧰 Ferramentas Recomendadas
- **Compilador:** GCC.
- **Depuração:** GDB.
- **Validação de Memória:** Valgrind.
- **Editor:** VSCode ou CLion.

---

## 💡 Contribuição
Sinta-se à vontade para abrir issues ou enviar pull requests para melhorias no repositório.

---
