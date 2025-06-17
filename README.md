

# Super Trunfo C 📇⚔️  
Mini‐jogo em linha de comando que cadastra **duas cartas** de cidades brasileiras e exibe seus atributos.  
Feito em **C99** puro, sem dependências externas.

---

## 📑 Índice
1. Visão geral
2. Funcionalidades
3. Pré-requisitos
4. Compilação
5. Uso  
6. Exemplo de sessão  
7. Roadmap de melhorias
8. Licença
9. Autor
---

## Visão geral
Super Trunfo é um jogo de cartas no qual cada carta possui estatísticas comparáveis.  
Esta implementação inicial foca apenas no **cadastro** e **exibição** de duas cartas, servindo como ponto de partida para versões mais completas (comparação de atributos, múltiplos jogadores, IA, etc.).

---

## Funcionalidades
- Estrutura de dados `CartaSuperTrunfo` com sete atributos:
  1. Estado (caractere A → H)  
  2. Código da carta (`A01`, `C12`…)  
  3. Nome da cidade  
  4. População (habitantes)  
  5. Área (km²)  
  6. PIB (bilhões de R$)  
  7. Número de pontos turísticos

- Entrada protegida contra quebra de linha perdida (`getchar` + `fgets`).
- Mensagens **sem acentuação** para máxima portabilidade em consol​es.
- Saída formatada e amigável.

---

## Pré-requisitos
| Ferramenta | Versão mínima | Observação                         |
| ---------- | ------------- | --------------------------------- |
| GCC / Clang| C99           | Testado em **GCC 12** e **Clang 17** |
| Make       | Opcional      | Facilita a compilação repetida     |

---

## Compilação
### GCC direto
```bash
gcc -std=c99 -Wall -Wextra -pedantic -o supertrunfo supertrunfo.c

```

## Uso
```
./supertrunfo
```
Siga as instruções interativas: informe estado, código, nome, população, área, PIB e pontos turísticos para cada carta.

## Exemplo de sessão
```
$ ./supertrunfo
Cadastro da Carta1:
Informe a letra do estado (A-H): A
Informe o codigo da carta (ex: A01): A01
Informe o nome da cidade: Salvador
Informe a populacao da cidade: 2886698
Informe a area da cidade (em km2): 693
Informe o PIB da cidade (em bilhoes): 63.3
Informe o numero de pontos turisticos da cidade: 12

Cadastro da Carta2:
Informe a letra do estado (A-H): B
Informe o codigo da carta (ex: A01): B07
Informe o nome da cidade: Recife
Informe a populacao da cidade: 1653461
Informe a area da cidade (em km2): 218
Informe o PIB da cidade (em bilhoes): 50.4
Informe o numero de pontos turisticos da cidade: 9

=====================
Dados da Carta 1:
Estado: A
Codigo: A01
Cidade: Salvador
Populacao: 2886698
Area: 693 km2
PIB: 63.30 bilhoes
Pontos Turisticos: 12

Dados da Carta 2:
Estado: B
Codigo: B07
Cidade: Recife
Populacao: 1653461
Area: 218 km2
PIB: 50.40 bilhoes
Pontos Turisticos: 9
=====================

```

## Roadmap de melhorias
### Prioridade | Ideia 
```
🔜 | Comparar atributos e definir carta vencedora
🔜 | Suporte a N cartas via vetor ou lista ligada 
🔜 | Persistência em arquivo (JSON ou CSV) 
🔜 | Modo player vs. computador com seleção aleatória
🔜 | Internacionalização (mensagens PT‐BR / EN)
🌓 | Interface TUI (ncurses) ou GUI (SDL) 
🌟 | Porta para Arduino / ESP32 para rodar em hardware real 
```

## License

[MIT](https://choosealicense.com/licenses/mit/)
