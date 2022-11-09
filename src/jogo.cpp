#include "../include/carta.hpp"
#include "../include/baralho.hpp"
#include "../include/jogador.hpp"
#include "../include/bot.hpp"
#include "../include/humano.hpp"
#include "../include/rodada.hpp"
#include "../include/menu.hpp"
#include "../include/jogo.hpp"

/**DEBUG
#include "baralho.cpp"
#include "bot.cpp"
#include "carta.cpp"
#include "humano.cpp"
#include "jogador.cpp"
#include "menu.cpp"
#include "rodada.cpp"**/

#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

void Jogo::novoJogo()
{
    // inicializa o menu do jogo e cadastra o usuario
    Menu menuJogo;
    menuJogo.cadastroUsuario();

    // se quiser visualizar o ranking digita 1, se quiser iniciar a partida digite 2
    int proxPasso;
    std::cout << "Se quiser visualizar o ranking digite 1, se quiser iniciar a partida digite 2: ";
    std::cin >> proxPasso;
    // se o usuario digitar um valor invalido vai repetir a msg
    while (proxPasso != 1 || proxPasso != 2)
    {
        std::cout << "Numero invalido! " << std::endl;
        std::cout << "Se quiser visualizar o ranking digite 1, se quiser iniciar a partida digite 2: ";
        std::cin >> proxPasso;
    }
    if (proxPasso == 1)
    {
        menuJogo.ranking();
        std::cout << "Se quiser iniciar a partida digite 2: ";
        std::cin >> proxPasso;
    }
    else
    {
        menuJogo.limparTela();
        std::cout << "O jogo irá iniciar!";
    }

    if (proxPasso == 2)
    {
        menuJogo.limparTela();
        std::cout << "O jogo irá iniciar!";

        // inicializa o baralho completo e prepara a mao de cada jogador
        Baralho baralhoDaQueda;
        baralhoDaQueda.inicializarBaralhoCompleto();
        baralhoDaQueda.inicializarMaoJogadores();

        // constroi os jogadores atribuindo nome, mao e id da dupla
        Humano usuario = Humano(menuJogo._nomeUsuario, baralhoDaQueda.getMaoJogador1(), 1);
        Bot bot1 = Bot("Bot1", baralhoDaQueda.getMaoJogador2(), 1);
        Bot bot2 = Bot("Bot2", baralhoDaQueda.getMaoJogador3(), 2);
        Bot bot3 = Bot("Bot3", baralhoDaQueda.getMaoJogador4(), 2);

        // inicializacao da rodada
        Rodada rodadaAtual;

        menuJogo.limparTela();

        int quemIniciaJogando = 0;
        int idJogadorMaiorCarta;
        // 0 usuario inicia, 1 bot2 incia, 2 bot1 incia, 3 bot3 incia
        if (quemIniciaJogando == 0)
        {
            int indiceCartaEscolhida;
            std::cout << "Escolha a primeira carta para jogar:" << std::endl;
            std::cout << "Digite 0 para escolher a primeira carta, 1 para escolher a segunda ou 2 para a terceira" << std::endl;
            // imprime as opcoes de carta do jogador
            usuario.imprimeCartasJogador();
            std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******

            // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
            rodadaAtual.inserirCartaDupla1(usuario.jogarCarta(indiceCartaEscolhida));

            std::cout << "Bot2 (dupla adversaria) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla2(bot2.jogarCarta());

            std::cout << "Bot1 (minha dupla) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla1(bot1.jogarCarta());

            std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla2(bot3.jogarCarta());

            // checagem de qual dupla ganhou a queda
            rodadaAtual.checagemVitoriaParcial();

            // fazer funcao na classe rodada para checar o id de quem tacou a maior carta
            // idJogadorMaiorCarta = rodadaAtual.getIdQuemTacouMaiorCarta();

            // continua a rodada enquanto nenhuma dupla tiver ganhado a md3
            while (rodadaAtual.getVitoriasParciaisDupla1() != 2 && rodadaAtual.getVitoriasParciaisDupla2() != 2)
            {
                // fazer logica para começar jogando agr quem tacou a maior carta
                if (idJogadorMaiorCarta == 0)
                {
                    // aqui teria a logica inicial do quemIniciaJogando = 0
                }
                else if (idJogadorMaiorCarta == 1)
                {
                    // aqui teria a logica inicial do quemIniciaJogando = 1
                }
                else if (idJogadorMaiorCarta == 2)
                {
                    // aqui teria a logica inicial do quemIniciaJogando = 2
                }
                else if (idJogadorMaiorCarta == 3)
                {
                    // aqui teria a logica inicial do quemIniciaJogando = 3
                }
            }
            quemIniciaJogando = 1;
            // reseta o baralho adicionando novamente todas as cartas e prepara a mao de cada jogador
            baralhoDaQueda.resetarBaralhoEMaoJogadores();
        }
        else if (quemIniciaJogando == 1)
        {
            // aqui no inicio vamo ter que chamar as funcoes setMao de cada jogador para dar as cartas novas para eles
            std::cout << "Bot2 (dupla adversaria) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla2(bot2.jogarCarta());

            std::cout << "Bot1 (minha dupla) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla1(bot1.jogarCarta());

            std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla2(bot3.jogarCarta());

            int indiceCartaEscolhida;
            std::cout << "Escolha a primeira carta para jogar:" << std::endl;
            std::cout << "Digite 0 para escolher a primeira carta, 1 para escolher a segunda ou 2 para a terceira" << std::endl;
            // imprime as opcoes de carta do jogador
            usuario.imprimeCartasJogador();
            std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
            // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
            rodadaAtual.inserirCartaDupla1(usuario.jogarCarta(indiceCartaEscolhida));

            // checagem de qual dupla ganhou a queda
            rodadaAtual.checagemVitoriaParcial();

            // reseta o baralho adicionando novamente todas as cartas e prepara a mao de cada jogador
            baralhoDaQueda.resetarBaralhoEMaoJogadores();

            quemIniciaJogando = 2;
        }
        else if (quemIniciaJogando == 2)
        {
            std::cout << "Bot1 (minha dupla) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla1(bot1.jogarCarta());

            std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla2(bot3.jogarCarta());

            int indiceCartaEscolhida;
            std::cout << "Escolha a primeira carta para jogar:" << std::endl;
            std::cout << "Digite 0 para escolher a primeira carta, 1 para escolher a segunda ou 2 para a terceira" << std::endl;
            // imprime as opcoes de carta do jogador
            usuario.imprimeCartasJogador();
            std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
            // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
            rodadaAtual.inserirCartaDupla1(usuario.jogarCarta(indiceCartaEscolhida));

            std::cout << "Bot2 (dupla adversaria) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla2(bot2.jogarCarta());

            // checagem de qual dupla ganhou a queda
            rodadaAtual.checagemVitoriaParcial();

            // reseta o baralho adicionando novamente todas as cartas e prepara a mao de cada jogador
            baralhoDaQueda.resetarBaralhoEMaoJogadores();

            quemIniciaJogando = 3;
        }
        else if (quemIniciaJogando == 3)
        {
            std::cout << "Bot3 (dupla adversaria) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla2(bot3.jogarCarta());

            int indiceCartaEscolhida;
            std::cout << "Escolha a primeira carta para jogar:" << std::endl;
            std::cout << "Digite 0 para escolher a primeira carta, 1 para escolher a segunda ou 2 para a terceira" << std::endl;
            // imprime as opcoes de carta do jogador
            usuario.imprimeCartasJogador();
            std::cin >> indiceCartaEscolhida; // ****** TEM QUE TRATAR OS ERROS POSSIVEIS DAQUI ******
            // insere na classe rodada a carta que foi escolhida pelo jogador, tira essa carta da mao do jogador
            rodadaAtual.inserirCartaDupla1(usuario.jogarCarta(indiceCartaEscolhida));

            std::cout << "Bot2 (dupla adversaria) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla2(bot2.jogarCarta());

            std::cout << "Bot1 (minha dupla) vai jogar..." << std::endl;
            rodadaAtual.inserirCartaDupla1(bot1.jogarCarta());

            // checagem de qual dupla ganhou a queda
            rodadaAtual.checagemVitoriaParcial();

            // reseta o baralho adicionando novamente todas as cartas e prepara a mao de cada jogador
            baralhoDaQueda.resetarBaralhoEMaoJogadores();

            quemIniciaJogando = 0;
        }
    }
}