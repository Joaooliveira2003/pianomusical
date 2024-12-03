#include <iostream> // cout ou cin ou endl
#include <conio.h> // captura as teclas getch()
#include <windows.h> // função beep()
#include <string> 

using namespace std;

void tocarNota(float frequencia, int duracao) {
    if (frequencia > 0) {
        Beep(frequencia, duracao);
    }
}

void Violao(){
    cout << "Comeca a tocar." << endl;
    cout << "tecle 'q' para encerrar e voltar ao menu principal." << endl;

    while (true){
        char tecla = getch();
        switch (tecla){
        case 'a':
            tocarNota(82, 440); //mi
            break;
        case 's':
            tocarNota(110, 440); //la
            break;
        case 'd':
            tocarNota(146, 440); //re
            break;
        case 'f':
            tocarNota(196, 440); //sol
            break;
        case 'g':
            tocarNota(246, 440); //si
            break;
        case 'h':
            tocarNota(329, 440); //mi
            break;
        case 'q':
            cout << "Encerrando o Violao virtual." << endl;
            return;
        default:
            break;
        }
    }

}

void Guitarra(){
    cout << "Comeca a tocar." << endl;
    cout << "tecle 'q' para encerrrar e voltar ao menu princinpal." << endl;

    while (true){
        char tecla = getch();

        switch (tecla){
        case 'a':
            tocarNota(82, 407); // do
            break;
        case 's':
            tocarNota(110, 307); // re
            break;
        case 'd':
            tocarNota(146, 832); // mi
            break;
        case 'f':
            tocarNota(195, 998); // fa
            break;
        case 'g':
            tocarNota(246, 942); // sol
            break;
        case 'h':
            tocarNota(329, 628); // la
            break;
        case 'q':
            cout << "ENCERRANDO A GUITARRA VIRTUAL..." << endl;
            return;
        default:
            break;
        }
    }
}

int main(){
    int option;
    while (true){
        system("cls");
        cout << "Bem vindo ao criador de trilhas sonoras" << endl;
        cout << "VAMOS ESCOLHER!!!" << endl;
        cout << "1. Violao" << endl;
        cout << "2. Guitarra" << endl;
        cout << "3. Sair" << endl;
        cout << "Informe o instrumento desejado: ";
        cin >> option;

        system("cls");

        switch (option) {
        case 1:
            Violao();
            break;
        case 2:
            Guitarra();
            break;
        case 3:
            cout << "Ate mais!!" << endl;
            return 0;
        default:
            cout << "Opção inválida. Tente novamente!" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}