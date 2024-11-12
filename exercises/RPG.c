    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    // Estrutura para arma
    typedef struct {
        char nome[50];
        int dano;
        int durabilidade;
        int bonus;
    } Arma;

    // Estrutura para jogador
    typedef struct {
        char classe[20];
        int vida;
        int forca;
        int defesa;
        int stamina;
        int restauracoesStamina; // Contador de restaurações de stamina
        Arma arma;
    } Jogador;

    // Estrutura para inimigo
    typedef struct {
        char nome[50];
        int vida;
        int forca;
    } Inimigo;

    // Funcao para rolar o dado de 20 faces
    int rolarDado() {
        return (rand() % 20) + 1;
    }

    // Funcao para pausar o programa
    void pausar() {
        printf("Pressione Enter para continuar...");
        getchar();
    }

    // Funcao para inicializar o jogador
    void inicializarJogador(Jogador *jogador) {
        int escolha;
        printf("\n=== CRIACAO DE PERSONAGEM ===\n");
        do {
            printf("Escolha a classe do seu personagem:\n");
            printf("1. Barbaro\n2. Bruxo\n3. Assassino\n4. Bardo\n5. Ladrao\n6. Ranger\n");
            printf("\nFaca sua escolha (1-6): ");
            scanf("%d", &escolha);
            getchar(); // Limpa o buffer
            
            if(escolha < 1 || escolha > 6) {
                printf("\nOpcao invalida! Por favor escolha um numero entre 1 e 6.\n");
            }
        } while(escolha < 1 || escolha > 6);

        switch(escolha) {
            case 1:
                strcpy(jogador->classe, "Barbaro");
                jogador->forca = 14; 
                jogador->defesa = 5;
                break;
            case 2:
                strcpy(jogador->classe, "Bruxo");
                jogador->forca = 7; 
                jogador->defesa = 8;
                break;
            case 3:
                strcpy(jogador->classe, "Assassino");
                jogador->forca = 9;    
                jogador->defesa = 7;
                break;
            case 4:
                strcpy(jogador->classe, "Bardo");
                jogador->forca = 8;    
                jogador->defesa = 10;
                break;
            case 5:
                strcpy(jogador->classe, "Ladrao");
                jogador->forca = 7;    
                jogador->defesa = 9;
                break;
            case 6:
                strcpy(jogador->classe, "Ranger");
                jogador->forca = 10;    
                jogador->defesa = 6;
                break;
        }
        jogador->vida = 100;
        jogador->stamina = 100;
        jogador->restauracoesStamina = 0;
        // Inicializa a arma padrao
        strcpy(jogador->arma.nome, "Espada de Madeira");
        jogador->arma.dano = 10;
        jogador->arma.durabilidade = 10;
        jogador->arma.bonus = 0;
        printf("\nClasse escolhida: %s\n", jogador->classe);
        printf("Status Inicial:\n");
        printf("Vida: %d\n", jogador->vida);
        printf("Stamina: %d\n", jogador->stamina);
        printf("Forca: %d\n", jogador->forca);
        printf("Defesa: %d\n", jogador->defesa);
    }

    // Funcao para inicializar inimigos
    void inicializarInimigos(Inimigo inimigos[]) {
        strcpy(inimigos[0].nome, "Goblin");
        inimigos[0].vida = 30;
        inimigos[0].forca = 5;

        strcpy(inimigos[1].nome, "Orc");
        inimigos[1].vida = 50;
        inimigos[1].forca = 10;

        strcpy(inimigos[2].nome, "Esqueleto");
        inimigos[2].vida = 25;
        inimigos[2].forca = 7;

        strcpy(inimigos[3].nome, "Troll");
        inimigos[3].vida = 60;
        inimigos[3].forca = 12;

        strcpy(inimigos[4].nome, "Dragao");
        inimigos[4].vida = 80;
        inimigos[4].forca = 20;

        strcpy(inimigos[5].nome, "Lich");
        inimigos[5].vida = 70;
        inimigos[5].forca = 15;
    }

    // Funcao para escolher um inimigo aleatorio
    Inimigo escolherInimigo(Inimigo inimigos[]) {
        int indice = rand() % 6;
        return inimigos[indice];
    }

    // Funcao para atualizar a arma
    void atualizarArma(Jogador *jogador) {
        if (jogador->arma.durabilidade <= 0) {
            printf("\nSua arma %s quebrou!\n", jogador->arma.nome);
            strcpy(jogador->arma.nome, "Desarmado");
            jogador->arma.dano = 8;
        }
    }

    // Funcao para exibir opcoes de ataque
    int escolherAtaque(Jogador *jogador) {
        int ataque;
        int danoBase = jogador->forca + jogador->arma.dano;
        do {
            printf("\nEscolha seu ataque:\n");
            if (strcmp(jogador->classe, "Barbaro") == 0) {
                printf("1. Ataque Fisico (Dano: %d, Custo: 10 Stamina)\n", danoBase);
                printf("2. Poder de Furia (Dano: %d, Custo: 20 Stamina)\n", (int)(danoBase * 1.5));
                printf("3. Investida (Dano: %d, Custo: 15 Stamina)\n", (int)(danoBase * 1.2));
                printf("4. Furia Berserk (Dano: %d, Custo: 25 Stamina)\n", danoBase * 2);
            } else if (strcmp(jogador->classe, "Bruxo") == 0) {
                printf("1. Bola de Fogo (Dano: %d, Custo: 10 Stamina)\n", danoBase);
                printf("2. Raio Mistico (Dano: %d, Custo: 20 Stamina)\n", (int)(danoBase * 1.5));
                printf("3. Escudo Arcano (Dano: %d, Custo: 15 Stamina)\n", (int)(danoBase * 1.2));
                printf("4. Tempestade de Energia (Dano: %d, Custo: 25 Stamina)\n", danoBase * 2);
            } else if (strcmp(jogador->classe, "Assassino") == 0) {
                printf("1. Golpe Sombrio (Dano: %d, Custo: 10 Stamina)\n", danoBase);
                printf("2. Ataque Venenoso (Dano: %d, Custo: 20 Stamina)\n", (int)(danoBase * 1.5));
                printf("3. Esquiva Rapida (Dano: %d, Custo: 15 Stamina)\n", (int)(danoBase * 1.2));
                printf("4. Corte Fatal (Dano: %d, Custo: 25 Stamina)\n", danoBase * 2);
            } else if (strcmp(jogador->classe, "Bardo") == 0) {
                printf("1. Cancao Curativa (Dano: %d, Custo: 10 Stamina)\n", danoBase);
                printf("2. Melodia Inspiradora (Dano: %d, Custo: 20 Stamina)\n", (int)(danoBase * 1.5));
                printf("3. Ritmo Acelerado (Dano: %d, Custo: 15 Stamina)\n", (int)(danoBase * 1.2));
                printf("4. Sinfonia Poderosa (Dano: %d, Custo: 25 Stamina)\n", danoBase * 2);
            } else if (strcmp(jogador->classe, "Ladrao") == 0) {
                printf("1. Ataque Rapido (Dano: %d, Custo: 10 Stamina)\n", danoBase);
                printf("2. Ataque Critico (Dano: %d, Custo: 20 Stamina)\n", (int)(danoBase * 1.5));
                printf("3. Finta (Dano: %d, Custo: 15 Stamina)\n", (int)(danoBase * 1.2));
                printf("4. Assalto (Dano: %d, Custo: 25 Stamina)\n", danoBase * 2);
            } else if (strcmp(jogador->classe, "Ranger") == 0) {
                printf("1. Tiro Preciso (Dano: %d, Custo: 10 Stamina)\n", danoBase);
                printf("2. Flecha Envenenada (Dano: %d, Custo: 20 Stamina)\n", (int)(danoBase * 1.5));
                printf("3. Armadilha (Dano: %d, Custo: 15 Stamina)\n", (int)(danoBase * 1.2));
                printf("4. Chuva de Flechas (Dano: %d, Custo: 25 Stamina)\n", danoBase * 2);
            } else {
                printf("1. Ataque Basico (Dano: %d, Custo: 10 Stamina)\n", danoBase);
                printf("2. Ataque Forte (Dano: %d, Custo: 20 Stamina)\n", (int)(danoBase * 1.5));
                printf("3. Defesa (Dano: %d, Custo: 15 Stamina)\n", (int)(danoBase * 1.2));
                printf("4. Ataque Especial (Dano: %d, Custo: 25 Stamina)\n", danoBase * 2);
            }
            printf("\nFaca sua escolha (1-4): ");
            scanf("%d", &ataque);
            getchar(); // Limpa o buffer

            if(ataque < 1 || ataque > 4) {
                printf("\nOpcao invalida! Por favor escolha um numero entre 1 e 4.\n");
            }
        } while(ataque < 1 || ataque > 4);
        
        return ataque;
    }

    // Funcao principal
    int main() {
        srand(time(NULL));
        Jogador jogador;
        Inimigo inimigos[6];
        inicializarJogador(&jogador);
        inicializarInimigos(inimigos);

        int rodada = 1;
        while(jogador.vida > 0) {
            printf("\n=== Rodada %d ===\n", rodada);
            Inimigo atual = escolherInimigo(inimigos);
            printf("Um %s apareceu!\n", atual.nome);
            printf("Vida do inimigo: %d\n", atual.vida);
            printf("Forca do inimigo: %d\n", atual.forca);

            printf("Status do Jogador:\n");
            printf("Vida: %d\n", jogador.vida);
            printf("Stamina: %d\n", jogador.stamina);

            // Opcoes para o jogador
            int escolhaAcao;
            do {
                printf("O que voce deseja fazer?\n");
                printf("1. Fugir\n");
                printf("2. Atacar\n");
                printf("\nFaca sua escolha (1-2): ");
                scanf("%d", &escolhaAcao);
                getchar(); // Limpa o buffer

                if(escolhaAcao < 1 || escolhaAcao > 2) {
                    printf("\nOpcao invalida! Por favor escolha 1 ou 2.\n");
                }
            } while(escolhaAcao < 1 || escolhaAcao > 2);

            int tentativaFuga = 0;
            if(escolhaAcao == 1) { // Fugir
                tentativaFuga = 1;
            }

            while(1) {
                if(tentativaFuga) { // Fugir
                    int rolaFuga = rolarDado();
                    printf("Voce tenta fugir... Rolou: %d\n", rolaFuga);
                    if(rolaFuga > 10) {
                        printf("Fuga bem-sucedida!\n");
                        pausar();
                        rodada++;
                        break;
                    } else {
                        printf("Falha na fuga! Voce deve lutar.\n");
                        pausar();
                        // Continue para a luta
                        tentativaFuga = 0;
                    }
                }

                // Atacar
                int ataqueEscolhido = escolherAtaque(&jogador);
                int custoStamina = 0;
                int danoJogador = 0;

                switch(ataqueEscolhido) {
                    case 1:
                        custoStamina = 10;
                        danoJogador = jogador.forca + jogador.arma.dano;
                        printf("Voce usou o Ataque 1.\n");
                        break;
                    case 2:
                        custoStamina = 20;
                        danoJogador = (jogador.forca + jogador.arma.dano) * 1.5;
                        printf("Voce usou o Ataque 2.\n");
                        break;
                    case 3:
                        custoStamina = 15;
                        danoJogador = (jogador.forca + jogador.arma.dano) * 1.2;
                        printf("Voce usou o Ataque 3.\n");
                        break;
                    case 4:
                        custoStamina = 25;
                        danoJogador = (jogador.forca + jogador.arma.dano) * 2;
                        printf("Voce usou o Ataque 4.\n");
                        break;
                }

                jogador.stamina -= custoStamina;

                // Verificar e restaurar stamina se necessário
                if(jogador.stamina <= 0 && jogador.restauracoesStamina < 5) {
                    printf("Stamina esgotada! Restaurando 50 pontos de stamina...\n");
                    jogador.stamina += 50;
                    jogador.restauracoesStamina++;
                    printf("Restauracoes restantes: %d\n", 5 - jogador.restauracoesStamina);
                }

                printf("Stamina atual: %d\n", jogador.stamina);
                pausar();

                // Defesa do inimigo
                int rolaInimigo = rolarDado();
                printf("Inimigo rola o dado para defesa: %d\n", rolaInimigo);
                if(rolaInimigo < 10) {
                    printf("Inimigo sem defesa.\n");
                } else if(rolaInimigo <=17) {
                    printf("Inimigo com defesa parcial.\n");
                    danoJogador = danoJogador * 0.6;
                } else {
                    printf("Inimigo esquiva efetiva. Ataque evitado.\n");
                    danoJogador = 0;
                }

                // Aplicar dano ao inimigo
                atual.vida -= danoJogador;
                printf("Dano causado ao %s: %d\n", atual.nome, danoJogador);
                printf("Vida restante do %s: %d\n", atual.nome, atual.vida);
                pausar();

                // Verificar se inimigo foi derrotado
                if(atual.vida <=0) {
                    printf("Inimigo %s derrotado!\n", atual.nome);
                    // Possibilidade de encontrar arma
                    int encontrouArma = rand() % 2;
                    if(encontrouArma) {
                        printf("Voce encontrou uma arma nova!\n");
                        strcpy(jogador.arma.nome, "Espada Refinada");
                        jogador.arma.dano += 5;
                        jogador.arma.durabilidade = 10;
                        printf("Nova arma: %s com dano %d e durabilidade %d\n", jogador.arma.nome, jogador.arma.dano, jogador.arma.durabilidade);
                    }
                    pausar();
                    break; // Finaliza a rodada apos derrotar o inimigo
                } else {
                    // Contra-ataque do inimigo
                    printf("Inimigo contra-ataca!\n");
                    // Player tenta se defender
                    int rolaDefesa = rolarDado();
                    printf("Voce rola o dado para defesa: %d\n", rolaDefesa);
                    int danoRecebido = atual.forca;
                    if(rolaDefesa < 10) {
                        printf("Voce nao conseguiu se defender.\n");
                    } else if(rolaDefesa <=17) {
                        printf("Voce se defendeu parcialmente.\n");
                        danoRecebido = danoRecebido * 0.6;
                    } else {
                        printf("Voce defendeu totalmente o ataque!\n");
                        danoRecebido = 0;
                    }

                    jogador.vida -= danoRecebido;
                    printf("Dano recebido: %d\n", danoRecebido);
                    printf("Vida do jogador: %d\n", jogador.vida);
                    printf("Stamina do jogador: %d\n", jogador.stamina);
                    pausar();

                    if(jogador.vida <=0) {
                        printf("Voce foi derrotado. Fim de jogo.\n");
                        return 0;
                    }
                }

                // Atualizar durabilidade da arma
                jogador.arma.durabilidade -=1;
                atualizarArma(&jogador);
                pausar();
            }

            // Sistema de upgrades a cada 3 rodadas (alterado de 5 para 3)
            if(rodada % 3 == 0) {
                int opcao;
                do {
                    printf("\n=== Sistema de Upgrades ===\n");
                    printf("1. Melhorar atributos\n2. Melhorar arma\n3. Usar forja para restaurar arma\n");
                    printf("\nFaca sua escolha (1-3): ");
                    scanf("%d", &opcao);
                    getchar(); // Limpa o buffer

                    if(opcao < 1 || opcao > 3) {
                        printf("\nOpcao invalida! Por favor escolha um numero entre 1 e 3.\n");
                    }
                } while(opcao < 1 || opcao > 3);

                if(opcao == 1) {
                    int atributo;
                    do {
                        printf("Escolha o atributo para melhorar:\n");
                        printf("1. Forca\n2. Defesa\n");
                        printf("\nFaca sua escolha (1-2): ");
                        scanf("%d", &atributo);
                        getchar(); // Limpa o buffer

                        if(atributo < 1 || atributo > 2) {
                            printf("\nOpcao invalida! Por favor escolha 1 ou 2.\n");
                        }
                    } while(atributo < 1 || atributo > 2);

                    if(atributo == 1) {
                        jogador.forca += 2;
                        printf("Forca aumentada para %d\n", jogador.forca);
                    } else {
                        jogador.defesa += 2;
                        printf("Defesa aumentada para %d\n", jogador.defesa);
                    }
                } else if(opcao == 2) {
                    printf("Melhorando a arma...\n");
                    jogador.arma.dano += 5;
                    printf("Dano da arma aumentado para %d\n", jogador.arma.dano);
                } else {
                    printf("Usando a forja para restaurar a arma...\n");
                    jogador.arma.durabilidade = 10;
                    printf("Durabilidade da arma restaurada para %d\n", jogador.arma.durabilidade);
                }
                pausar();
            }

            rodada++;
        }

        printf("Voce foi derrotado. Fim de jogo.\n");
        return 0;
    }
