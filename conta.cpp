#include <iostream>
#include <vector>
#include <typeinfo>
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

class ClientePJ{
        public:
        int cnpj;
        string nome;

        void setNome(string novo_nome);
        string getNome();
        void setCNPJ(int novo_cnpj);
        int getCNPJ();

};

void ClientePJ::setNome(string novo_nome){
        this->nome = novo_nome;
}
string ClientePJ::getNome(){
        return this->nome;
}
void ClientePJ::setCNPJ(int novo_cnpj){
        this->cnpj = novo_cnpj;
}
int ClientePJ::getCNPJ(){
        return this->cnpj;
}

template <class C>
class Fila{
        public:
        vector<C> pessoa;

        void getClientes();
        void setClientes(C newPessoa);
};

template<> void Fila<Cliente>::getClientes(){
        for(int i=0; i<pessoa.size(); i++){
                cout << this->pessoa[i].getNome() << endl;
        }
}
template<> void Fila<ClientePJ>::getClientes(){
        for(int i=0; i<pessoa.size(); i++){
                cout << this->pessoa[i].getNome() << endl;
        }
}

template <class C> void Fila<C>::setClientes(C newPessoa){
        pessoa.push_back(newPessoa);
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
        ClientePJ umbrella, aperture;
        Fila<Cliente> ordemP;
        Fila<ClientePJ> ordemJ;
        Agencia B1, B2;
        Conta X, Y;
        joao.setNome("Joao Nascimento"); joao.setCPF(696969);
        maria.setNome("Maria PedroS"); maria.setCPF(123456);
        umbrella.setNome("Umbrella corp"); umbrella.setCNPJ(100001);
        aperture.setNome("Aperture Science"); aperture.setCNPJ(424242);

        ordemJ.setClientes(umbrella);
        ordemJ.setClientes(aperture);
        ordemP.setClientes(joao);
        ordemP.setClientes(maria);
        ordemP.getClientes();
        ordemJ.getClientes();
        /*B1.setBanco("Banco do capeta"); B1.setNUM(666);
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
        cout << "Saldo: " << Y.saldo << endl;*/


        return 0;
}
