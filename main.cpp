#include <iostream>

using namespace std;
bool gameOver;
const int altura = 20;
const int largura = 20;
int x, y, frutaX, frutaY, pontos, escolha;

/* Eu quero que a cobra se mova CONSTANTEMENTE para a posição indicada pelo jogador ao invés de fazer o usário pressionar varias vezes a DIRECAO que ele   
quer movimentar a cobra. Essas direções porém, são fixas: Para a equerda,para a direita, para cima e para baixo. A unica forma que encontrei na internet 
de fazer isso é utilizando enumeração */
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

    /* dir = inicio ( inicio = 0) para que a cobra não se mova a menos que começemos a move-la. */
    dir = inicio;

    /* definição da posição inicial da cabeça cobra no meio da tela */
    x = altura / 2;
    y = largura / 2;

    /* definição de posições aleatórias para as frutas */
    frutaX = rand() % altura;
    frutaY = rand() % largura;
    pontos = 0;
}

void Grafico()
{
    /* é necessário utilizar o comando "cls" dentro do console para não imprimir um mapa atrás do outro */
    system("cls");


    /* loop "for" para borda de cima do mapa*/
    for (int l = 0; l < largura; l++)
    cout << "#";
    cout << endl;

    /* loop "for" para bordas laterais do mapa*/
    for (int h = 0; h < altura; h++)
    {
        for (int l = 0; l < largura; l++)
        {
            if (l == 0)
                cout << "#";
            
            /* se a posição for igual a posição da cabeça da cobra: cout cabeça da cobra "O" */
            if (h == y && l == x)
                cout << "O";
            
            /* se a posição for igual a posição da fruta: cout fruta "F" */
            else if (h == frutaY && l == frutaX)
                cout << "F";
            
            /* se a posição =! (x,y) && (frutaX, frutaY): cout espaço em branco " " */
            else    
                cout << " ";

            if (l == largura - 1)
                cout << "#";
        }
        cout << endl;
    }

    /* loop "for" para borda de baixo do mapa*/
    for (int l = 0; l < largura; l++)
        cout << "#";
        cout << endl;
}

void Usabilidade()
{

}
void Logica()
{

}
int main()
{


    /* menu que permite o jogador "fechar" ou "jogar" o jogo. esse menu precisa aparecer sempre que o jogo finalizar, 
    permitindo que o usuário jogue novamente sem ter que compilar o código múltiplas vezes. */
    
    
    cout << "1 - Jogar\n";
    cout << "2 - Ranking\n";
    cout << "0 - Fechar jogo\n"; 
    
    
    cin >> escolha;

    switch(escolha)
    {
        case 0: 
            cout << "Obrigado por jogar :)";
            return 0;
        case 1:
            cout << "teste";
            break;
        case 2:
            cout << "RANKING";
            break;
    }

    Configuracao();
    
    /* estrutura condicional "enquanto" para que enquanto o jogo não esteja em "gameOver" a função Configuração chame as outras funções necessárias */
    while (!gameOver)
    {
        Grafico();
        Usabilidade();
        Logica();
    }
    return 0;
}