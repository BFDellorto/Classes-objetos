#include <iostream>
#include <vector>
using namespace std;

class Funcionario{
	private:
        string nome;
        int salario;
        string dataAdm;
        string departamento;
        public:
        string getNome(){
                return this->nome;
        }
        void setNome(string newNome){
                this->nome = newNome;
        }

        int getSalario(){
                return this->salario;
        }
        void setSalario(int newSalario){
                this->salario = newSalario;
        }

        string getDataAdm(){
                return dataAdm;
        }
        void setDataAdm(string newDataAdm){
                this->dataAdm = newDataAdm;
        }

        string getDept(){
                return departamento;
        }
        void setDept(string newDept){
                this->departamento = newDept;
        }
};


class Empresa{
	private:
        string nome;
        string CNPJ;
        public:
        string getNome(){
                return nome;
        }
        void setNome(string newNome){
                this->nome = newNome;
        }

        string getCNPJ(){
                return CNPJ;
        }
        void setCNPJ(string newCNPJ){
                this->CNPJ = newCNPJ;
        }
};


int main(){
        Empresa Umbrella;
        vector<Funcionario> funcs;
        Funcionario newFunc;
        int num, i, j=0;
        string comando, word;

        Umbrella.setNome("Umbrella corp");
        Umbrella.setCNPJ("666");
        cout << "Quantos funcionarios? (Digite 0 para modo automatico)" << endl;
        cin >> j;
        cin.ignore();
        if(j==0){
                newFunc.setNome("Joao");
                newFunc.setSalario(1500);
                newFunc.setDataAdm("01/04/1995");
                newFunc.setDept("Virus development");
                funcs.push_back(newFunc);

                newFunc.setNome("Marta");
                newFunc.setSalario(3200);
                newFunc.setDataAdm("29/02/2004");
                newFunc.setDept("World domination efforts");
                funcs.push_back(newFunc);

                newFunc.setNome("Chris");
                newFunc.setSalario(1300);
                newFunc.setDataAdm("06/06/2006");
                newFunc.setDept("Security");
                funcs.push_back(newFunc);

                newFunc.setNome("Jordan");
                newFunc.setSalario(4500);
                newFunc.setDataAdm("25/12/2007");
                newFunc.setDept("World domination efforts");
                funcs.push_back(newFunc);

                newFunc.setNome("Bellarose");
                newFunc.setSalario(1700);
                newFunc.setDataAdm("11/11/2011");
                newFunc.setDept("Virus development");
                funcs.push_back(newFunc);
        }
        for(i=0;i<j;i++){
                cout << "Nome do funcionario " << i+1 << endl;
                getline(cin, word);
                newFunc.setNome(word);
                cout << "Salario do funcionario " << i+1 << endl;
                cin >> num;
                cin.ignore();
                newFunc.setSalario(num);
                cout << "Data de entrada do funcionario " << i+1 << endl;
                getline(cin, word);
                newFunc.setDataAdm(word);
                cout << "Departamento do funcionario " << i+1 << endl;
                getline(cin, word);
                newFunc.setDept(word);
                funcs.push_back(newFunc);
        }
        while(1){
                cout << "Digite comando: <mostrar> <aumento> <exit>" << endl;
                getline(cin, comando);
                if(comando == "exit"){
                        break;
                }
                if(comando == "mostrar"){
                        for(i=0;i<funcs.size();i++){
                                word = funcs[i].getNome();
                                cout << "Nome: " << word << endl;
                                num = funcs[i].getSalario();
                                cout << "Salario: " << num << endl;
                                word = funcs[i].getDataAdm();
                                cout << "Data de adimissao: " << word << endl;
                                word = funcs[i].getDept();
                                cout << "Departamento: " << word << endl;
                                cout << endl;
                        }
                }
                if(comando == "aumento"){
                        cout << "Digite o departamento para receber o aumento de 10%" << endl;
                        getline(cin, comando);
                        for(i=0;i<funcs.size();i++){
                                if(comando == funcs[i].getDept()){
                                        num = funcs[i].getSalario();
                                        funcs[i].setSalario(num*1.1);
                                }
                        }
                }

        }

        return 0;
}
