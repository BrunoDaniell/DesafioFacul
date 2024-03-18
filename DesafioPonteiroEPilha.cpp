#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    const int capacidade_estacionamento = 10;
    queue<int> estacionamento;
    int numero_manobras = 0;

    char operacao;
    int placa;

    while (cin >> operacao >> placa) {
        if (operacao == 'E') { // Carro chegando
            if (estacionamento.size() < capacidade_estacionamento) {
                estacionamento.push(placa);
                cout << "Carro com placa " << placa << " estacionado." << endl;
            }
            else {
                cout << "Não há vaga para o carro com placa " << placa << "." << endl;
            }
        }
        else if (operacao == 'S') { // Carro saindo
            queue<int> temp;
            int manobras = 0;
            bool carro_encontrado = false;

            // Procura o carro e conta as manobras necessárias para retirá-lo
            while (!estacionamento.empty()) {
                if (estacionamento.front() == placa) {
                    carro_encontrado = true;
                    break;
                }
                temp.push(estacionamento.front());
                estacionamento.pop();
                manobras++;
            }

            // Recoloca os carros de volta na fila original
            while (!temp.empty()) {
                estacionamento.push(temp.front());
                temp.pop();
            }

            if (carro_encontrado) {
                cout << "Carro com placa " << placa << " saiu do estacionamento após " << manobras << " manobras." << endl;
            }
            else {
                cout << "Carro com placa " << placa << " não está no estacionamento." << endl;
            }

            numero_manobras += manobras;
        }
    }

    cout << "Total de manobras realizadas: " << numero_manobras << endl;

    return 0;
}
