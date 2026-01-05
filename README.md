# Sistema de Roteamento de Ambulância - Águas Molhadas

## Visão Geral

Solução completa para otimizar o roteamento de ambulâncias em um município através de algoritmos de teoria dos grafos. O sistema modela a rede viária como um grafo, permitindo encontrar rotas eficientes entre o posto de saúde e diferentes regiões.

## Características Principais

### 🏗️ Arquitetura Modular e Reutilizável
- **Separação de Responsabilidades**: Cada módulo possui uma responsabilidade única bem definida
  - `fila_dinamica.c/h`: Gerenciamento de filas dinâmicas com alocação de memória em tempo de execução
  - `ambulanciaTrabalho.c/h`: Lógica do grafo e algoritmos de busca
  - `main.c`: Interface de usuário
  
### 📊 Estruturas de Dados Fundamentais
- **Grafo com Lista de Adjacência**: Implementação eficiente de grafos para representação de redes
  - Encapsulação de dados privados através de structs opacas
  - Contrato de interface clara através do arquivo `.h`
  
- **Fila Dinâmica**: Estrutura de dados genérica baseada em lista ligada
  - Alocação dinâmica de memória
  - Operações FIFO com complexidade O(1)

### 🔄 Padrões de Implementação
- **Abstração**: Tipos opacos (`Grafo`, `Fila`, `Lista`) que ocultam detalhes de implementação
- **Encapsulamento**: Interfaces públicas bem definidas com proteção de dados internos
- **Composição**: Estruturas compostas (`Vertice` contém `Lista_adjacencia`)

### ⚙️ Funcionalidades
- Criação dinâmica de grafos com número de vértices parametrizado
- Adição de arestas com validação
- Busca em largura (BFS) para encontrar caminho mais curto
- Fila de prioridades para gestão de chamadas
- Interface interativa com menu de navegação

## Especificação Técnica

### Estrutura de Dados Principal

```
Grafo
├── num_Vertices: quantidade de nós
├── num_Arestas: quantidade de conexões
└── no[]: array de vértices
    └── Vertice
        └── nos_adj: lista ligada de adjacência
            └── Lista_adjacencia
                ├── vertices: destino
                └── prox: próximo elemento
```

## Requisitos

- Compilador C (GCC)
- Linux/Unix ou compatível
- Make (opcional)

## Compilação e Execução

```bash
# Compilar
make

# Executar
./ambulancia

# Limpar objetos
make clean
```

## Como Usar

1. **Iniciar o programa**: O sistema cria uma rede de 7 vilas interconectadas
2. **Selecionar Posto de Saúde**: Escolha em qual vila está localizado
3. **Operações Disponíveis**:
   - Buscar rota mais curta entre dois pontos
   - Verificar conectividade da rede
   - Listar vizinhos (vilas adjacentes)
   - Exibir mapa do município

## Autores

- Matheus Henrique Alves
- Vitor Hugo França de Paula
- Pedro Henrique Souza

**Professor**: Liliane Gade  
**Instituição**: Colégio Técnico de Minas Gerais (COLTEC-UFMG)  
**Classe**: 203

## Conceitos Aplicados

- **Teoria dos Grafos**: Representação e algoritmos em grafos
- **Estruturas de Dados Dinâmicas**: Alocação de memória em tempo de execução
- **Algoritmos de Busca**: BFS para caminho mais curto
- **Programação Modular**: Código reutilizável e mantível
- **Gestão de Recursos**: Alocação e liberação adequada de memória

## Próximas Melhorias

- [ ] Implementar algoritmo de Dijkstra para arestas ponderadas
- [ ] Adicionar persistência de dados em arquivo
- [ ] Interface gráfica
- [ ] Suporte a múltiplas ambulâncias simultâneas
- [ ] Tratamento robusto de erros
