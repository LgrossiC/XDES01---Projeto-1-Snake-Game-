#include <iostream>
using namespace std;
bool gameOver;
const int altura = 20;
const int largura = 20;
int x, y, frutaX, frutaY, pontos;

/* Eu quero que a cobra se mova CONSTANTEMENTE para a posição indicada
pelo jogador ao invés de fazer o usário pressionar varias vezes a 
DIRECAO que ele quer movimentar a cobra. Essas direções porém, são fixas:
Para a equerda,para a direita, para cima e para baixo.
A unica forma que encontrei na internet de fazer isso é utilizando enumeração */
enum direcao { inicio = 0, cima, baixo, esquerda, direita};
direcao dir;

void Configuraçao()
{
    gameOver = false;
    
    /* dir = inicio ( inicio = 0) para que a cobra não se mova a menos que
    começemos a move-la. */
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

}
void Usabilidade()
{

}
void Logica()
{

}
int main()
{
    Configuraçao();
    while (!gameOver)
    {
        Grafico();
        Usabilidade();
        Logica();  
    }
    return 0;
}