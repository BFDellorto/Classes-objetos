#include <iostream>
using namespace std;

class Conta{
        public:
        int num;
        string nome;
        int saldo;
        void sacar(int gold);
        void depositar(int gold);
        void transferir(int gold, Conta* userY);
};

void Conta::sacar(int gold){
        this->saldo -= gold;
}

void Conta::depositar(int gold){
        this->saldo += gold;
}
void Conta::transferir(int gold, Conta* userY){
        this->sacar(gold);
        (*userY).depositar(gold);
}

int main(){
        Conta X, Y;
        X.num = 666;
        X.nome = "Lucifer";
        X.saldo = 3200;
        Y.num = 142;
        Y.nome = "Divindade";
        Y.saldo = 5000;

        X.depositar(500);
        X.transferir(800, &Y);
        cout << X.nome << " " << X.num << " " << X.saldo << endl;
        cout << Y.nome << " " << Y.num << " " << Y.saldo << endl;

}
