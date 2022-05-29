#include <iostream>
using namespace std;
bool gameOver;

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