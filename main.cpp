#include <iostream>
using namespace std;
bool gameOver;
const int altura = 20;
const int largura = 20;
int x, y, frutaX, frutaY, pontos;

void Configuraçao()
{
    gameOver = false;
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