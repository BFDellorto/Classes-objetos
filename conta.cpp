#include <iostream>
using namespace std;

class Cliente{
        public:
        int cpf;
        string nome;

        void setNome(string novo_nome);
        string getNome();
        void setCPF(int novo_cpf);
        int getCPF();

};

void Cliente::setNome(string novo_nome){
        this->nome = novo_nome;
}
string Cliente::getNome(){
        return this->nome;
}
void Cliente::setCPF(int novo_cpf){
        this->cpf = novo_cpf;
}
int Cliente::getCPF(){
        return this->cpf;
}

class Agencia{
        public:
        int num;
        string banco;

        void setBanco(string novo_banco);
        string getBanco();
        void setNUM(int novo_num);
        int getNUM(); 
};

void Agencia::setBanco(string novo_banco){
        this->banco = novo_banco;
}
string Agencia::getBanco(){
        return this->banco;
}
void Agencia::setNUM(int novo_num){
        this->num = novo_num;
}
int Agencia::getNUM(){
        return this->num;
}

class Conta{
        public:
        Agencia AG;
        Cliente titular;
        int saldo;
        static int num_contas;

        Conta();
        void sacar(int gold);
        void depositar(int gold);
        void transferir(int gold, Conta* userY);
};
int Conta::num_contas = 0;
Conta::Conta(){
        this->num_contas++;
}

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
        Cliente joao, maria;
        Agencia B1, B2;
        Conta X, Y;
        joao.setNome("Joao Nascimento"); joao.setCPF(696969);
        maria.setNome("Maria PedroS"); maria.setCPF(123456);

        B1.setBanco("Banco do capeta"); B1.setNUM(666);
        B2.setBanco("Banco divino"); B2.setNUM(999);

        X.AG = B1; X.titular = joao; X.saldo = 9999;
        Y.AG = B2; Y.titular = maria; Y.saldo = 6666;
        X.depositar(500);
        X.transferir(800, &Y);

        cout << "Numero de contas: " << Conta::num_contas << endl;
        cout << X.AG.getBanco() << " " << X.AG.getNUM() << endl;
        cout << X.titular.getNome() << " " << X.titular.getCPF() << endl;
        cout << "Saldo: " << X.saldo << endl;
        cout << endl;
        cout << Y.AG.getBanco() << " " << Y.AG.getNUM() << endl;
        cout << Y.titular.getNome() << " " << Y.titular.getCPF() << endl;
        cout << "Saldo: " << Y.saldo << endl;



}
