#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace std; 
#define t 4
//==============================================
struct alunos{
	long int cpf;
	char nome[30];
	char dataNascimento[11];
	float peso;
	float altura;
	int status;
};

struct idxAlunos{
	long int cpf;
	int end;
};


void inclusaoAluno(struct idxAlunos idx[], struct alunos aln[], int &cont, int cod){
    cont++;
    // inclusao do novo registro na area de dados
    aln[cont].cpf = cod;
    cout << "\nNome: ";
    cin >> aln[cont].nome;
    cout << "\nData de nascimento: ";
    cin >> aln[cont].dataNascimento;
    cout << "\nPeso: ";
    cin >> aln[cont].peso;
    cout << "\nAltura: ";
    cin >> aln[cont].altura;
    // inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].cpf > cod; i--){
        idx[i+1].cpf = idx[i].cpf;
        idx[i+1].end = idx[i].end;
    }
    idx[i+1].cpf = cod;
    idx[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
}


void buscaAluno (struct idxAlunos idx[], struct alunos aln[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cpf; m = (i + f) / 2){
        if (cod > idx[m].cpf)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cpf){
        cout << "\n\n Aluno já Cadastrado - não pode ser cadastrado novamente";
        i = idx[m].end;
        cout << "\nCpf dos alunos: " << aln[i].cpf;
        cout << "\tNome: " << aln[i].nome;
        cout << "\tData de nascimento: " << aln[i].dataNascimento;
        cout << "\tPeso: " << aln[i].peso;
        cout << "\tAltura: " << aln[i].altura;
    }
    else
        inclusaoAluno(idx, aln, cont, cod);
    getch();
}


void exaustivaAluno (struct idxAlunos idx[], struct alunos aln[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (aln[i].status == 0){
            cout << "\nNome: " << aln[i].nome;
            cout << "\tDataNascimento: " << aln[i].dataNascimento;
            cout << "\tPeso: " << aln[i].peso;
            cout << "\tAltura: " << aln[i].altura;
        }
    }
}

void exclusaoAluno(struct idxAlunos idx[], struct alunos aln[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cpf; m = (i + f) / 2){
        if (cod > idx[m].cpf)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cpf) && aln[i].status == 0){
        aln[i].status = 1;
        cout << "\n\n Cliente Excluido com Sucesso";
    }
    else
        cout << "Cliente nao cadastrado";
    getch();
}


void buscaAleatAluno(struct idxAlunos idx[], struct alunos aln[], int cont, int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cpf; m = (i + f) / 2){
        if (cod > idx[m].cpf)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cpf){
        cout << "\n\n Cliente Encontrado";
        i = idx[m].end;
        cout << "\nCPF do Cliente: " << aln[i].cpf;
        cout << "\tNome: " << aln[i].nome;
        cout << "\tData de nascimento: " << aln[i].dataNascimento;
        cout << "\tPeso: " << aln[i].peso;
        cout << "\tAltura: " << aln[i].altura;
    }
    else
        cout << "\n\n Cliente nao Encontrado";
    getch();
}
//==============================================
struct professores{
	int codProf;
	char nome[30];
	char endereco[30];
	long int telefone;
};

struct idxProfessores{
	int cod;
	int end;
};


//==============================================
struct modalidades{
	int codMod;
	char descricao[50];
	int codProf;
	float precoAula;
	int limiteAlunos;
	int totalAlunos;
};

struct idxModalidades{
	int codMod;
	int end;	
};


//==============================================
struct matriculas{
	int codMatr;
	long int cpf;
	int codMod;
	int qntdAulas;
};

struct idxMatriculas{
	int codMatr;
	int end;
};

//==============================================

int main(){
	setlocale(LC_ALL, "portuguese");
	
	int contAlunos = t + 1;
	struct alunos aluno[t] =
	{
		{57140933804, "Jonathan", "04/07/2003", 75.5, 1.80, 0}, //pos 0
		{42050277942, "Pedro", "17/02/2002" , 76.0, 1.80, 0}, //pos 1
		{37343706802, "Marcel", "05/09/1989", 90.0, 1.75, 0}//pos 2	
	};
	
	struct idxAlunos indAln[t] = 
	{
		{37343706802, 2},
		{57140933804, 0},
		{42050277942, 1}
	};
	
	int contProfessor;
	struct professores professor[t] = 
	{
		{1, "Marcelo", "Rui Barbosa 1000", 18123456789 }
	};
	
	struct idxProfessores indProf[t] = 
	{
		{1, 0}
	};
	int opcao = 30;
	while(opcao != 0){
		cout << "\n\t*** ACADEMIA POWERON ***" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Alunos:" << endl;
		cout << "[1]- Inclusão de novos alunos" << endl;
		cout << "[2]- Exclusão de alunos" << endl;
		cout << "[3]- Buscar alunos" << endl;
		cout << "[4]- Reorganização dos dados dos alunos" << endl;
		cout << "[5]- Leitura exaustiva dos alunos" << endl;
		cout << "----------------------------------------" << endl;
		cout << "[0]- Sair" << endl;
		
		cin >> opcao;
		
		switch(opcao){
			case 1:
				cout << "\tIncluir Alunos: " << endl;
				for (long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o CPF do Aluno a ser Incluído (0 para Encerrar): ";
        			cin >> codpesq;
        			if (codpesq != 0)
            			buscaAluno(indAln, aluno, contAlunos, codpesq);
    			}
				break;
			case 2:
				cout << "\tExcluir alunos: " << endl;
				for (int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o CPF do aluno a ser Excluído (0 para Encerrar): ";
        			cin >> codpesq;
       				 if (codpesq != 0)
            			exclusaoAluno(indAln, aluno, contAlunos, codpesq);
				}
				break;
			case 3:	
				cout << "\tBuscar alunos: " << endl;
				for (int codpesq = 9; codpesq != 0;){
					cout << "\n\nInforme o CPF do aluno a ser Buscado (0 para Encerrar): ";
        			cin >> codpesq;
        				if (codpesq != 0)
           					buscaAleatAluno(indAln, aluno, contAlunos, codpesq);
           		}
				break;
			case 4:
				cout << "\tReorganização dos alunos" << endl;
				break;		
			case 5:
				cout << "\tLeitura Exaustiva dos Registros";
   				exaustivaAluno(indAln,aluno,contAlunos);
				break;	
			case 0:
				cout << "Encerrando..." << endl;
				opcao = 0;
				break;
			default:
				cout << "Número inválido" << endl;
				break;		
		}		
	}
}
