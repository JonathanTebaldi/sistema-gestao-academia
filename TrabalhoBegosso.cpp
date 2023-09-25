#include <iostream>
#include <conio.h>
#include <locale.h>
#include <math.h>

using namespace std; 

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


void inclusaoAluno(struct idxAlunos idx[], struct alunos aln[], int &cont, long int cod){
    
    // inclusao do novo registro na area de dados
    aln[cont].cpf = cod;
    cout << "\nNome: ";
    cin >> aln[cont].nome;
    cout << "Data de nascimento: ";
    cin >> aln[cont].dataNascimento;
    cout << "Peso: ";
    cin >> aln[cont].peso;
    cout << "Altura: ";
    cin >> aln[cont].altura;
    
    float calc;
    //calc = aln[cont].peso / (pow(aln[cont].altura,2));
    calc = aln[cont].peso / (aln[cont].altura * aln[cont].altura);
    cout << "calc = " << calc;
    if(calc < 17){
    	cout << "**(Voc� est� muito abaixo do peso)**";
    }else if(calc > 17 && calc < 18,49){
    	cout << "**(Voc� est� abaixo do peso)**";
	}else if(calc > 18,5 && calc < 24,99){
		cout << "**(Peso normal";		
	}else if(calc > 25 && calc < 29,99){
		cout << "**(Voc� est� acima do peso)**";
	}else if(calc > 30 && calc < 34,99){
		cout << "**(Obesidade I)**";
	}else if(calc > 35 && calc < 39,99){
		cout << "**(Obesidade II (severa))**";
	}else{
		cout << "**(Obesidade III (m�rbida))**";
	}
    
    
    // inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].cpf > cod; i--){
        idx[i+1].cpf = idx[i].cpf;
        idx[i+1].end = idx[i].end;
    }
    idx[i+1].cpf = cod;
    idx[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
}


void buscaAluno (struct idxAlunos idx[], struct alunos aln[], int &cont, long int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cpf; m = (i + f) / 2){
        if (cod > idx[m].cpf)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cpf){
        cout << "\n\n Aluno j? Cadastrado - n?o pode ser cadastrado novamente";
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

void exclusaoAluno(struct idxAlunos idx[], struct alunos aln[], int &cont, long int cod){
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


void buscaAleatAluno(struct idxAlunos idx[], struct alunos aln[], int cont,long int cod){
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

void reorganizacaoAluno(struct idxAlunos idx[], struct idxAlunos novoidx[], struct alunos cli[], struct alunos novocli[], int &cont){
    int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (cli[i].status == 0){
            j++;
            novocli[j].cpf = cli[i].cpf;
            strcpy (novocli[j].nome,cli[i].nome);
            strcpy (novocli[j].endereco,cli[i].endereco);
            strcpy (novocli[j].cidade,cli[i].cidade);
            strcpy (novocli[j].uf,cli[i].uf);
            novocli[j].status = 0;
            novoidx[j].codigo = novocli[j].codigo;
            novoidx[j].ender = j;
        }
    }
    cont = j+1;
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
	int const t = 4;
	setlocale(LC_ALL, "portuguese");
	
	int contAlunos = 4;
	struct alunos aluno[t] =
	{
		{57140933804, "Jonathan", "04/07/2003", 75.5, 1.80, 0}, //pos 0
		{42050277942, "Pedro", "17/02/2002" , 76.0, 1.80, 0}, //pos 1
		{37343706802, "Marcel", "05/09/1989", 90.0, 1.75, 0}//pos 2	
	};
	struct alunos alunoNovo[t];
	
	struct idxAlunos indAln[t] = 
	{
		{37343706802, 2},
		{57140933804, 0},
		{42050277942, 1}
	};
	struct idxAlunos idxAlunNovo[t];
	
	int contProfessor;
	struct professores professor[t] = 
	{
		{1, "Marcelo", "Rui Barbosa 1000", 18123456789 },
		{2, "Ricardo", "Armando Sales 300", 18997454545}
	};
	
	struct idxProfessores indProf[t] = 
	{
		{1, 0},
		{2, 1}
	};
	int opcao = 30;
	while(opcao != 0){
		cout << "\n\t*** ACADEMIA POWERON ***" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Alunos:" << endl;
		cout << "[1]- Inclus�o de novos alunos" << endl;
		cout << "[2]- Exclus�o de alunos" << endl;
		cout << "[3]- Buscar alunos" << endl;
		cout << "[4]- Reorganiza��o dos dados dos alunos" << endl;
		cout << "[5]- Leitura exaustiva dos alunos" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Professores:" << endl;
		cout << "[6]- Inclus�o de novos professores" << endl;
		cout << "[7]- Exclus�o de professores" << endl;
		cout << "[8]- Buscar professores" << endl;
		cout << "[9]- Reorganiza��o dos dados dos professores" << endl;
		cout << "[10]- Leitura exaustiva dos professores" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Modalidades" << endl;
		cout << "[11]- Inclus�o de novas modalidades" << endl;
		cout << "[12]- Exclus�o de modalidades" << endl;
		cout << "[13]- Buscar modalidades" << endl;
		cout << "[14]- Reorganiza��o dos dados das modalidades" << endl;
		cout << "[15]- Leitura exaustiva das modalidades" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Matriculas:" << endl;
		cout << "[16]- Inclus�o de novas matriculas" << endl;
		cout << "[17]- Exclus�o de matriculas" << endl;
		cout << "[18]- Buscar matriculas" << endl;
		cout << "[19]- Reorganiza��o dos dados das matriculas" << endl;
		cout << "[20]- Leitura exaustiva das matriculas" << endl;
		cout << "----------------------------------------------" << endl;
		
		cout << "[0]- Sair" << endl;
		
		cin >> opcao;
		
		switch(opcao){
			case 1:
				cout << "\tIncluir Alunos: " << endl;
				for (long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o CPF do Aluno a ser Inclu�do(01/01/2021) \n(0 para Encerrar)" << endl;
        			cin >> codpesq;
        			if (codpesq != 0)
            			buscaAluno(indAln, aluno, contAlunos, codpesq);
    			}
				break;
			case 2:
				cout << "\tExcluir alunos: " << endl;
				for (long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o CPF do aluno a ser Exclu?do (0 para Encerrar): ";
        			cin >> codpesq;
       				 if (codpesq != 0)
            			exclusaoAluno(indAln, aluno, contAlunos, codpesq);
				}
				break;
			case 3:	
				cout << "\tBuscar alunos: " << endl;
				for (long int codpesq = 9; codpesq != 0;){
					cout << "\n\nInforme o CPF do aluno a ser Buscado (0 para Encerrar): ";
        			cin >> codpesq;
        				if (codpesq != 0)
           					buscaAleatAluno(indAln, aluno, contAlunos, codpesq);
           		}
				break;
			case 4:
				cout << "\tReorganiza??o dos alunos" << endl;
				reorganizacaoAluno();
				break;		
			case 5:
				cout << "\tLeitura Exaustiva dos Registros";
   				exaustivaAluno(indAln,aluno,contAlunos);
				break;
			case 6:
				cout << "\tIncluir Professores" << endl;
				
				break;
			case 7:
				cout << "\rExcluir Professores" << endl;
				
				break;
			case 8:	
				cout << "\tBuscar Professpres" << endl;
				
				break;
			case 9:
				cout << "\tReorganiza��o dos professores" << endl;
				break;
			case 10:
				cout << "\tLeitura Exaustiva dos registros" << endl;
				break;
			case 11:
				cout << "\tIncluir Modalidades" << endl;
				
				break;
			case 12:
				cout << "\tExcluir Modalidades" << endl;
				
				break;
			case 13:	
				cout << "\tBuscar Modalidades" << endl;
				
				break;
			case 14:
				cout << "\tReorganiza��o das Modalidades" << endl;
				break;
			case 15:
				cout << "\tLeitura Exaustiva dos registros" << endl;
				break;		
			case 16:
				cout << "\tIncluir Matriculas" << endl;
				
				break;
			case 17:
				cout << "\rExcluir Matriculas" << endl;
				
				break;
			case 18:	
				cout << "\tBuscar Matriculas" << endl;
				break;
			case 19:
				cout << "\tReorganiza��o das Matriculas" << endl;
				break;
			case 20:
				cout << "\tLeitura Exaustiva dos registros" << endl;
				break;							
			case 0:
				cout << "Encerrando..." << endl;
				opcao = 0;
				break;
			default:
				cout << "N?mero inv?lido" << endl;
				break;		
		}		
	}
}
