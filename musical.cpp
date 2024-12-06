#include <iostream> // cout, cin, endl
#include <conio.h> // captura teclas com getch()
#include <windows.h> // função Beep()
#include <vector>
#include <fstream>

using namespace std;

struct Nota {
    float frequencia;
    int duracao;
};

void tocarNota(int frequencia, int duracao) {
    if (frequencia > 0) {
        Beep(frequencia, duracao);
    }
}

void salvarMusica(const vector<Nota>& musica, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (const auto& nota : musica) {
            arquivo << nota.frequencia << " " << nota.duracao << endl;
        }
        arquivo.close();
        cout << "Música salva em \"" << nomeArquivo << "\"!" << endl;
    } else {
        cout << "Erro ao salvar a música." << endl;
    }
    system("pause");
}

void tocarMusica(const vector<Nota>& musica) {
    for (const auto& nota : musica) {
        tocarNota(nota.frequencia, nota.duracao);
    }
}

void carregarMusica(vector<Nota>& musica, const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        Nota nota;
        while (arquivo >> nota.frequencia >> nota.duracao) {
            musica.push_back(nota);
        }
        arquivo.close();
    }
}

void violao() {
    vector<Nota> musica;
    cout << "Comece a tocar. Tecle 'q' para encerrar e salvar a música." << endl;

    while (true) {
        char tecla = getch();
        Nota nota = {0, 440}; 

        switch (tecla) {
        case 'a':
            nota.frequencia = 82; // Mi grave
            break;
        case 's':
            nota.frequencia = 110; // Lá
            break;
        case 'd':
            nota.frequencia = 146; // Ré
            break;
        case 'f':
            nota.frequencia = 196; // Sol
            break;
        case 'g':
            nota.frequencia = 246; // Si
            break;
        case 'h':
            nota.frequencia = 329; // Mi agudo
            break;
        case 'q':
            cout << "Encerrando o violão virtual." << endl;
            salvarMusica(musica, "Violao.txt");
            return;
        default:
            continue;
        }

        tocarNota(nota.frequencia, nota.duracao);
        musica.push_back(nota);
    }
}

void guitarra() {
    vector<Nota> musica;
    cout << "Comece a tocar. Tecle 'q' para encerrar e salvar a música." << endl;

    while (true) {
        char tecla = getch();
        Nota nota = {0, 440};

        switch (tecla) {
        case 'a':
            nota.frequencia = 82; // Dó
            break;
        case 's':
            nota.frequencia = 110; // Ré
            break;
        case 'd':
            nota.frequencia = 146; // Mi
            break;
        case 'f':
            nota.frequencia = 195; // Fá
            break;
        case 'g':
            nota.frequencia = 246; // Sol
            break;
        case 'h':
            nota.frequencia = 329; // Lá
            break;
        case 'q':
            cout << "Encerrando a guitarra virtual." << endl;
            salvarMusica(musica, "Guitarra.txt");
            return;
        default:
            continue;
        }

        tocarNota(nota.frequencia, nota.duracao);
        musica.push_back(nota);
    }
}

void reproduzirMusica() {
    vector<Nota> musica;
    int opcao;

    cout << "Escolha a música salva para tocar:" << endl;
    cout << "1. Violão" << endl;
    cout << "2. Guitarra" << endl;
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao) {
    case 1:
        carregarMusica(musica, "Violao.txt");
        if (!musica.empty()) {
            cout << "Tocando musica do violao..." << endl;
            tocarMusica(musica);
        } else {
            cout << "Nenhuma música salva encontrada para o violão." << endl;
        }
        break;
    case 2:
        carregarMusica(musica, "Guitarra.txt");
        if (!musica.empty()) {
            cout << "Tocando musica da guitarra..." << endl;
            tocarMusica(musica);
        } else {
            cout << "Nenhuma musica salva encontrada para a guitarra." << endl;
        }
        break;
    default:
        cout << "Opcaoo invalida." << endl;
        break;
    }

    system("pause");
}

int main() {
    int option;
    while (true) {
        system("cls");
        cout << "Bem-vindo ao criador de trilhas sonoras" << endl;
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Violão" << endl;
        cout << "2. Guitarra" << endl;
        cout << "3. Reproduzir música salva" << endl;
        cout << "4. Sair" << endl;
        cout << "Opcao: ";
        cin >> option;

        system("cls");

        switch (option) {
        case 1:
            violao();
            break;
        case 2:
            guitarra();
            break;
        case 3:
            reproduzirMusica();
            break;
        case 4:
            cout << "Saindo... Ate mais!" << endl;
            return 0;
        default:
            cout << "Opcao invalida. Tente novamente!" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}
