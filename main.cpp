#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h> //sleep

#define esc 27

using namespace std;

bool gameOver;
const int altura = 20;
const int largura = 20;
int cabecaX, cabecaY, frutaX, frutaY, pontos, escolha, record;
int corpoX[100], corpoY[100];
int nCorpo;

FILE *f;

/* Eu quero que a cobra se mova CONSTANTEMENTE para a posicao indicada pelo jogador ao inves de fazer o usurio pressionar varias vezes a DIRECAO que ele
quer movimentar a cobra. Essas direcoes porem, sao fixas: Para a equerda,para a direita, para cima e para baixo. A unica forma que encontrei na internet
de fazer isso e utilizando enumeracao */
enum direcao
{
    inicio = 0,
    cima,
    baixo,
    esquerda,
    direita
};
direcao dir;

void Configuracao()
{
    gameOver = false;

    /* dir = inicio ( inicio = 0) para que a cobra nao se mova a menos que comecemos a move-la. */
    dir = inicio;

    /* definicao da posicao inicial da cabeca cobra no meio da tela */
    cabecaX = altura / 2;
    cabecaY = largura / 2;

    /* definicao de posicoes aleatorias para as frutas */
    frutaX = rand() % altura;
    frutaY = rand() % largura;
    pontos = 0;
}

void Grafico()
{
    /* e necessario utilizar o comando "cls" dentro do console para nao imprimir um mapa atras do outro */
    system("cls");

    cout << "Pontos: " << pontos << endl;
    cout << "Record: " << record << endl;

    /* loop "for" para borda de cima do mapa*/
    for (int l = 0; l < largura + 2; l++)
        cout << "#";
    cout << endl;

    /* loop "for" para bordas laterais do mapa*/
    for (int h = 0; h < altura; h++)
    {
        for (int l = 0; l < largura; l++)
        {
            if (l == 0)
                cout << "#";

            /* se a posicao for igual a posicao da cabeca da cobra: cout cabeca da cobra "O" */
            if (h == cabecaY && l == cabecaX)
                cout << "O";

            /* se a posicao for igual a posicao da fruta: cout fruta "F" */
            else if (h == frutaY && l == frutaX)
                cout << "F";

            else
            {
                bool print = false;
                for (int iCorpo = 0; iCorpo < nCorpo; iCorpo++)
                {
                    if (corpoX[iCorpo] == l && corpoY[iCorpo] == h)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (l == largura - 1)
                cout << "#";
        }
        cout << endl;
    }

    /* loop "for" para borda de baixo do mapa*/
    for (int l = 0; l < largura + 2; l++)
        cout << "#";
    cout << endl;
}

void Logica()
{

    /* O rabo da cobra é composto por vários segmentos que devem seguir o movimento da cabeça.
    O primeiro segmento segue o movimento da cabeça
    O segundo segmento segue o movimento do primeiro segmento e assim por diante.*/
    int xAnterior = corpoX[0];
    int yAnterior = corpoY[0];
    int Anterior2x, Anterior2y;
    corpoX[0] = cabecaX;
    corpoY[0] = cabecaY;

    for (int i = 1; i < nCorpo; i++)
    {
        Anterior2x = corpoX[i];
        Anterior2y = corpoY[i];
        corpoX[i] = xAnterior;
        corpoY[i] = yAnterior;
        xAnterior = Anterior2x;
        yAnterior = Anterior2y;
    }

    /* verifica se alguma tecla foi pressionada e retorna 1 caso sim e 0 caso nao.*/
    if (kbhit())
    {
        /*

        retorna o valor 1 para tecla pressionada

        switch para as seguintes teclas:
        w -> cima
        a -> esquerda
        s -> baixo
        d -> direita

        */
        switch (_getch())
        {
        /* define o valor da enum "dir" para "esquerda"*/
        case 'a':
            dir = esquerda;
            break;
        /* define o valor da enum "dir" para "direita"*/
        case 'd':
            dir = direita;
            break;
        /* define o valor da enum "dir" para "cima"*/
        case 'w':
            dir = cima;
            break;
        /* define o valor da enum "dir" para "baixo"*/
        case 's':
            dir = baixo;
            break;
        /* define o valor de gameOver para true para finalizar o jogo*/
        case esc:
            gameOver = true;
            break;
        }
    }

    /* switch na "enum dir" para que, por exemplo, se o valor atribuido a "enum dir" for "esquerda" o valor x (que define a posicao da cabeca da cobra)
    vai receber x-1, ou seja vai movimentar uma casa para a esquerda e assim por diante... */
    switch (dir)
    {
    case esquerda:
        cabecaX--;
        break;

    case direita:
        cabecaX++;
        break;

    case cima:
        cabecaY--;
        break;

    case baixo:
        cabecaY++;
        break;
    }

    /* GAMEOVER se bater nas paredes */
    if (cabecaX > largura || cabecaX < 0 || cabecaY > altura || cabecaY < 0)
        gameOver = true;

    /* GAMEOVER se bater no corpo */
    for (int i = 0; i < nCorpo; i++)
        if (corpoX[i] == cabecaX && corpoY[i] == cabecaY)
            gameOver = true;

    /* Se a posicao da cabeca da cobra for igual a posicao da fruta:
    - mais um ponto
    - fruta aparece em outro local do mapa
    - tamanho do corpo aumenta */

    if (cabecaX == frutaX && cabecaY == frutaY)
    {
        pontos += 1;
        frutaX = rand() % altura;
        frutaY = rand() % largura;
        nCorpo++;
    }
}

int main()
{
    f = fopen("record.txt", "r");
    fscanf(f, "%d", &record);
    fclose(f);

    Configuracao();

    /* menu que permite o jogador "fechar" ou "jogar" o jogo. esse menu precisa aparecer sempre que o jogo finalizar,
    permitindo que o usuario jogue novamente sem ter que compilar o codigo multiplas vezes. */

    do
    {
        cout << "\n1 - Jogar\n";

        cout << "\n0 - Fechar jogo\n";

        cin >> escolha;

        switch (escolha)
        {

        case 1:
            f = fopen("record.txt", "r");
            fscanf(f, "%d", &record);
            fclose(f);
            /* e preciso setar "gameOver = false" para permitir que o jogador jogue novamente sem precisar fechar a aplicacao */
            (gameOver = false);

            /* redefinindo a posicao da cabeca da cobra, da fruta e a pontuacao caso o jogador jogue novamente */
            cabecaX = altura / 2;
            cabecaY = largura / 2;
            pontos = 0;
            frutaX = rand() % altura;
            frutaY = rand() % largura;
            nCorpo = 0;

            while (!gameOver)
            {
                /* estrutura condicional "enquanto" para que enquanto o jogo nao esteja em "gameOver" a funcaoo Configuracaoo chame as outras funcoes necesserias */
                Grafico();
                Logica();
                Sleep(10);
            }

            if (pontos > record)
            {
                printf("\nNOVO RECORD !!!\n\n");
                system("pause");
                f = fopen("record.txt", "w");
                fprintf(f, "%d", pontos);
                fclose(f);
            }

        case 2:
            f = fopen("record.txt", "r");
            fprintf(f, "%d", record);
            fclose(f);

            break;

        case 0:
            printf("\nObrigado por jogar :)");
            return 0;
        }
    } while (escolha != 0);
}
