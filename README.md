

# Super Trunfo C 📇⚔️  
Mini‐jogo em linha de comando que cadastra **duas cartas** de cidades brasileiras e exibe seus atributos.  
Feito na linguagem **C** , sem dependências externas.

---

## 📑 Índice
1. Visão geral
2. Funcionalidades
3. Pré-requisitos
4. Compilação
5. Uso  
6. Exemplo de sessão
7. Comparação entre cartas
8. Versão 2.0
9. Roadmap de melhorias
10. Licença
11. Autor
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

## Comparação entre Cartas

Após o cadastro das duas cartas, o programa calcula dois indicadores adicionais:

- Densidade populacional = população ÷ área
- PIB per capita = (PIB em R$) ÷ população

Nesta versão, a comparação é feita com base exclusivamente na densidade populacional, e vence a carta com a menor densidade. A ideia é representar uma cidade “mais tranquila” como vencedora neste cenário.
A saída no terminal indica o nome da cidade, seu valor de densidade e qual carta venceu a disputa.
```
⚠️ Esta lógica pode ser facilmente modificada no código para priorizar outro atributo (como maior PIB, mais pontos turísticos, etc.), ou até tornar isso uma escolha dinâmica do jogador em futuras versões.

```

## Versão 2.0
A nova versão do Super Trunfo implementa comparações múltiplas e dinâmicas entre cartas, oferecendo uma jogabilidade mais rica e lógica mais refinada:

✅ Funcionalidades adicionadas
Escolha de 2 atributos diferentes para comparação, com menu interativo que remove o primeiro atributo escolhido da segunda seleção.

Comparação automática baseada nas seguintes regras:

Para todos os atributos numéricos, o maior valor vence.

Para densidade populacional, o menor valor vence (exceção que representa cidades menos sobrecarregadas).

Cálculo da soma dos dois atributos escolhidos para definir o vencedor final.

Tratamento completo de empates, com mensagem clara.

Interface de seleção via switch, com default para tratar erros de entrada.

Uso do operador ternário para tornar o código mais conciso nas decisões.

Código modularizado: uso da função preencherCarta() para entrada de dados, com limpeza do stdin via getchar() para evitar bugs de entrada.

 ### Exemplo de uso da nova lógica:
```
Escolha o primeiro atributo para comparar:
1. Populacao
2. Area
3. PIB
4. Pontos Turisticos
5. Densidade Populacional
> 3

Escolha o segundo atributo (diferente do anterior):
1. Populacao
2. Area
4. Pontos Turisticos
5. Densidade Populacional
> 5

=== Resultado da Comparação ===
Atributo 1: PIB → Carta 1: 60.50 | Carta 2: 50.30 → Carta 1 vence
Atributo 2: Densidade Populacional → Carta 1: 4200.00 | Carta 2: 3200.00 → Carta 2 vence

Soma dos pontos:
Carta 1: 60.50 + 4200.00 = 4260.50
Carta 2: 50.30 + 3200.00 = 3250.30

🎉 Vencedora: Carta 1 (São Paulo)
```

## Roadmap de melhorias
### Prioridade | Ideia 
```
🔜 | Suporte a N cartas via vetor ou lista ligada 
🔜 | Persistência em arquivo (JSON ou CSV) 
🔜 | Modo player vs. computador com seleção aleatória
🔜 | Internacionalização (mensagens PT‐BR / EN)
🌓 | Interface TUI (ncurses) ou GUI (SDL) 
🌟 | Porta para Arduino / ESP32 para rodar em hardware real 
```
👨‍💻 Autor

💻 Desenvolvido por Gabriel Moreira<br>
👨‍🎓 Estudante de programação em Javascript, Typescript, Python e Desenvolvedor Web.<br>
Este programa foi criado com o intuito de realizar um trabalho da Faculdade.

## License

[MIT](https://choosealicense.com/licenses/mit/)
