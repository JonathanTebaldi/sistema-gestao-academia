#include <iostream>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

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
    	cout << "*(Você está muito abaixo do peso)*";
    }else if(calc > 17 && calc < 18,49){
    	cout << "*(Você está abaixo do peso)*";
	}else if(calc > 18,5 && calc < 24,99){
		cout << "**(Peso normal";		
	}else if(calc > 25 && calc < 29,99){
		cout << "*(Você está acima do peso)*";
	}else if(calc > 30 && calc < 34,99){
		cout << "*(Obesidade I)*";
	}else if(calc > 35 && calc < 39,99){
		cout << "*(Obesidade II (severa))*";
	}else{
		cout << "*(Obesidade III (mórbida))*";
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

void reorganizacaoAluno(struct idxAlunos idx[], struct idxAlunos novoidx[], struct alunos aln[], struct alunos novoAln[], int &cont){
    int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (aln[i].status == 0){
            j++;
            novoAln[j].cpf = aln[i].cpf;
            strcpy(novoAln[j].nome,aln[i].nome);
            strcpy(novoAln[j].dataNascimento,aln[i].dataNascimento);
            novoAln[j].altura = aln[i].altura;
            novoAln[j].peso = aln[i].peso;
            novoAln[j].status = 0;
            novoidx[j].cpf = novoAln[j].cpf;
            novoidx[j].end = j;
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
	int status;
};

struct idxProfessores{
	int cod;
	int end;
};


void inclusaoProfessor(struct idxProfessores idx[], struct professores prof[], int &cont, int cod){
    // inclusao do novo registro na area de dados
    prof[cont].codProf = cod;
    cout << "Nome: ";
    cin >> prof[cont].nome;
    cout << "Endereco: ";
    cin >> prof[cont].endereco;
    cout << "Telefone: ";
    cin >> prof[cont].telefone;
    // inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].cod > cod; i--){
        idx[i+1].cod = idx[i].cod;
        idx[i+1].end = idx[i].end;
    }
    idx[i+1].cod = cod;
    idx[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
}



void buscaProfessor(struct idxProfessores idx[], struct professores prof[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cod){
        cout << "\n\n Professor ja Cadastrado - nao pode ser cadastrado novamente";
        i = idx[m].end;
        cout << "\nCodigo do Professor: " << prof[i].codProf;
        cout << "\tNome: " << prof[i].nome;
        cout << "\tEndereco: " << prof[i].endereco;
        cout << "\tTelefone: " << prof[i].telefone;
    }
    else
        inclusaoProfessor(idx, prof, cont, cod);
    getch();
}

void exaustivaProfessor(struct idxProfessores idx[], struct professores prof[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (prof[i].status == 0){
            cout << "\nNome: " << prof[i].nome;
            cout << "\tEndereco: " << prof[i].endereco;
            cout << "\tTelefone: " << prof[i].telefone;
        }
    }
}

void exclusaoProfessor(struct idxProfessores idx[], struct professores prof[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && prof[i].status == 0){
        prof[i].status = 1;
        cout << "\n\n Cliente Excluido com Sucesso";
    }
    else
        cout << "Cliente nao cadastrado";
    getch();
}

void buscaAleatProf(struct idxProfessores idx[], struct professores prof[], int cont,int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cod){
        cout << "\n\n Professor Encontrado";
        i = idx[m].end;
        cout << "\nCodigo do Professor: " << prof[i].codProf;
        cout << "\tNome: " << prof[i].nome;
        cout << "\tEndereco: " << prof[i].endereco;
        cout << "\tTelefone: " << prof[i].telefone;
    }
    else
        cout << "\n\n Professor nao Encontrado";
    getch();
}


void reorganizacaoProf(struct idxProfessores idx[], struct idxProfessores novoidx[], struct professores prof[], struct professores novoProf[], int &cont){
    int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (prof[i].status == 0){
            j++;
            novoProf[j].codProf = prof[i].codProf;
            strcpy(novoProf[j].nome,prof[i].nome);
            strcpy(novoProf[j].endereco, prof[i].endereco);
            novoProf[j].telefone = prof[i].telefone;
            novoProf[j].status = 0;
            novoidx[j].cod = novoProf[j].codProf;
            novoidx[j].end = j;
        }
    }
    cont = j+1;
}

//==============================================
struct modalidades{
	int codMod;
	char descricao[50];
	int codProf;
	float precoAula;
	int limiteAlunos;
	int totalAlunos;
	int status;
};

struct idxModalidades{
	int cod;
	int end;	
};

void inclusaoModalidade(struct idxModalidades idx[], struct modalidades mod[], int &cont, int cod){  
    // inclusao do novo registro na area de dados
    mod[cont].codMod = cod;
    cout << "\nCodigo da Modalidade: ";
    cin >> mod[cont].codMod;
    cout << "\nCodigo do Professor: ";
    cin >> mod[cont].codProf;
    cout << "\tDescricao: ";
    cin >> mod[cont].descricao;
    cout << "\tPreco da aula: ";
    cin >> mod[cont].precoAula;
    cout << "\tLimite de Alunos: ";
    cin >> mod[cont].limiteAlunos;
    cout << "\tTotal de Alunos: ";
    cin >> mod[cont].totalAlunos;
    // inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].cod > cod; i--){
        idx[i+1].cod = idx[i].cod;
        idx[i+1].end = idx[i].end;
    }
    idx[i+1].cod = cod;
    idx[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
}

void buscaModalidade(struct idxModalidades idx[], struct modalidades mod[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cod){
        cout << "\n\n Modalidade ja Cadastrada - nao pode ser cadastrado novamente";
        i = idx[m].end;
        cout << "\nCodigo da Modalidade: " << mod[i].codMod;
        cout << "\nCodigo do Professor: " << mod[i].codProf;
        cout << "\tDescricao: " << mod[i].descricao;
        cout << "\tPreco da aula: " << mod[i].precoAula;
        cout << "\tLimite de Alunos: " << mod[i].limiteAlunos;
        cout << "\tTotal de Alunos: " << mod[i].totalAlunos;
    }
    else
        inclusaoModalidade(idx, mod, cont, cod);
    getch();
}

void exclusaoModalidade(struct idxModalidades idx[], struct modalidades mod[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && mod[i].status == 0){
        mod[i].status = 1;
        cout << "\n\n Cliente Excluido com Sucesso";
    }
    else
        cout << "Cliente nao cadastrado";
    getch();
}

void buscaAleatMod(struct idxModalidades idx[], struct modalidades mod[], int cont,int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cod){
        cout << "\n\n Modalidade Encontrada";
        i = idx[m].end;
        cout << "\nCodigo da modalidade: " << mod[i].codProf;
        cout << "\tDescricao: " << mod[i].descricao;
        cout << "\tCodigo do professor: " << mod[i].codProf;
        cout << "\tPreco da aula: " << mod[i].precoAula;
        cout << "\tLimite de alunos: " << mod[i].limiteAlunos;
        cout << "\tTotal de alunos: " << mod[i].totalAlunos;
    }
    else
        cout << "\n\n Modalidade nao Encontrado";
    getch();
}

void reorganizacaoMod(struct idxModalidades idx[], struct idxModalidades novoidx[], struct modalidades mod[], struct modalidades novoMod[], int &cont){
    int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (mod[i].status == 0){
            j++;
            novoMod[j].codMod = mod[i].codMod;
            strcpy(novoMod[j].descricao,mod[i].descricao);
            novoMod[j].codProf = mod[i].codProf;
            novoMod[j].precoAula = mod[i].precoAula;
            novoMod[j].limiteAlunos = mod[i].limiteAlunos;
            novoMod[j].totalAlunos = mod[i].totalAlunos;
            novoMod[j].status = 0;
            novoidx[j].cod = novoMod[j].codMod;
            novoidx[j].end = j;
        }
    }
    cont = j+1;
}

void exaustivaModalidade(struct idxModalidades idx[], struct modalidades mod[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].end;
        if (mod[i].status == 0){
        	cout << "\nCodigo da modalidade" << mod[i].codMod;
            cout << "\nCodigo do professor: " << mod[i].codProf;
            cout << "\nDescricao: " << mod[i].descricao;
            cout << "\nPreco da aula: " << mod[i].precoAula;
            cout << "\nLimite de alunos: " << mod[i].limiteAlunos;
            cout << "\nTotal de alunos: " << mod[i].totalAlunos << endl;
        }
    }
}

//==============================================
struct matriculas{
	int codMatr;
	long int cpf;
	int codMod;
	int qntdAulas;
	int status;
};

struct idxMatriculas{
	int cod;
	int end;
};


void inclusaoMatricula(struct idxMatriculas idx[], struct matriculas mat[], int &cont, int cod){  
    // inclusao do novo registro na area de dados
    mat[cont].codMatr = cod;
    cout << "\nCodigo da Matricula: ";
    cin >> mat[cont].codMatr;
    cout << "\nCPF do aluno: ";
    cin >> mat[cont].cpf;
    cout << "\tCodigo da modalidade: ";
    cin >> mat[cont].codMod;
    cout << "\tQuantidade de aulas: ";
    cin >> mat[cont].qntdAulas;
    // inclusao na area de indices
    int i;
    for (i = cont - 1; idx[i].cod > cod; i--){
        idx[i+1].cod = idx[i].cod;
        idx[i+1].end = idx[i].end;
    }
    idx[i+1].cod = cod;
    idx[i+1].end = cont;
    cout << "\n\nInclusao realizada com Sucesso";
    cont++;
}

void buscaMatricula(struct idxMatriculas idx[], struct matriculas mat[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].cod){
        cout << "\n\n Modalidade ja Cadastrada - nao pode ser cadastrado novamente";
        i = idx[m].end;
        cout << "\nCodigo da Matricula: " << mat[i].codMatr;
        cout << "\nCPF do aluno: " << mat[i].cpf;
        cout << "\tCodigo da Modalidade: " << mat[i].codMod;
        cout << "\tQuantidade de aulas: " << mat[i].qntdAulas;
    }
    else
        inclusaoMatricula(idx, mat, cont, cod);
    getch();
}


void exclusaoMatricula(struct idxMatriculas idx[], struct matriculas mat[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].cod; m = (i + f) / 2){
        if (cod > idx[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idx[m].end;
    if ((cod == idx[m].cod) && mat[i].status == 0){
        mat[i].status = 1;
        cout << "\n\n Matricula excluida com Sucesso";
    }
    else
        cout << "Matricula nao cadastrada";
    getch();
}
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
	
	int contProfessor = t;
	struct professores professor[t] = 
	{
		{1, "Marcelo", "Rui Barbosa 1000", 18123456789 },
		{2, "Ricardo", "Armando Sales 300", 18997454545}
	};
	struct professores professorNovo[t];
	
	struct idxProfessores indProf[t] = 
	{
		{1, 0},
		{2, 1}
	};
	struct idxProfessores idxProfNovo[t];
	
	int contModalidade = t;
	struct modalidades modalidade[t] = {
		{1, "Boxe", 1, 89.90, 20,  10},
		{2, "Musculacao", 2, 99.90, 500,  458},
		{3, "Karatê", 3, 89.90, 20, 13},
		{}
	};
	struct modalidades modalidadeNovo[t];
	
	struct idxModalidades idxMod[t] = {
		{1, 3},
		{2, 2},
		{3, 1}
	};
	struct idxModalidades idxModNovo[t];
	
	int contMatricula = t;
	struct matriculas matricula[t] = {
		{1, 57140933804, 2},
		{2, 42050277942, 1},
		{3, 37343706802, 3}
	};
	
	struct idxMatriculas idxMat[t] = {
		{2, 1},
		{3, 2},
		{1, 0}	
	};
	
	int opcao = 30;
	while(opcao != 0){
		cout << "\n\t** ACADEMIA POWERON **" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Alunos:" << endl;
		cout << "[1]- Inclusão de novos alunos" << endl;
		cout << "[2]- Exclusão de alunos" << endl;
		cout << "[3]- Buscar alunos" << endl;
		cout << "[4]- Reorganização dos dados dos alunos" << endl;
		cout << "[5]- Leitura exaustiva dos alunos" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Professores:" << endl;
		cout << "[6]- Inclusão de novos professores" << endl;
		cout << "[7]- Exclusão de professores" << endl;
		cout << "[8]- Buscar professores" << endl;
		cout << "[9]- Reorganização dos dados dos professores" << endl;
		cout << "[10]- Leitura exaustiva dos professores" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Modalidades" << endl;
		cout << "[11]- Inclusão de novas modalidades" << endl;
		cout << "[12]- Exclusão de modalidades" << endl;
		cout << "[13]- Buscar modalidades" << endl;
		cout << "[14]- Reorganização dos dados das modalidades" << endl;
		cout << "[15]- Leitura exaustiva das modalidades" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Matriculas:" << endl;
		cout << "[16]- Inclusão de novas matriculas" << endl;
		cout << "[17]- Exclusão de matriculas" << endl;
		cout << "[18]- Buscar matriculas" << endl;
		cout << "[19]- Reorganização dos dados das matriculas" << endl;
		cout << "[20]- Leitura exaustiva das matriculas" << endl;
		cout << "----------------------------------------------" << endl;
		
		cout << "[0]- Sair" << endl;
		
		cin >> opcao;
		
		switch(opcao){
			case 1:
				cout << "\tIncluir Aluno: " << endl;
				for(long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o CPF do Aluno a ser Incluído(01/01/2021) \n(0 para Encerrar)" << endl;
        			cin >> codpesq;
        			if (codpesq != 0)
            			buscaAluno(indAln, aluno, contAlunos, codpesq);
    			}
				break;
			case 2:
				cout << "\tExcluir aluno: " << endl;
				for(int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o CPF do aluno a ser Exclu?do (0 para Encerrar): ";
        			cin >> codpesq;
       				 if (codpesq != 0)
            			exclusaoAluno(indAln, aluno, contAlunos, codpesq);
				}
				break;
			case 3:	
				cout << "\tBuscar aluno: " << endl;
				for(long int codpesq = 9; codpesq != 0;){
					cout << "\n\nInforme o CPF do aluno a ser Buscado (0 para Encerrar): ";
        			cin >> codpesq;
        				if (codpesq != 0)
           					buscaAleatAluno(indAln, aluno, contAlunos, codpesq);
           		}
				break;
			case 4:
				cout << "\tReorganizacao dos alunos" << endl;
				reorganizacaoAluno(indAln, idxAlunNovo, aluno, alunoNovo, contAlunos);
				break;		
			case 5:
				cout << "\tLeitura Exaustiva dos Registros";
   				exaustivaAluno(indAln,aluno,contAlunos);
				break;
			case 6:
				cout << "\tIncluir Professor" << endl;
				for(long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o codigo do professor a ser Incluído (0 para Encerrar)" << endl;
        			cin >> codpesq;
        			if (codpesq != 0)
            			buscaProfessor(indProf, professor, contProfessor, codpesq);
    			}
				break;
			case 7:
				cout << "\rExcluir Professor" << endl;
				for(long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o codigo do Professor a ser excluido (0 para Encerrar): ";
        			cin >> codpesq;
       				 if (codpesq != 0)
            			exclusaoProfessor(indProf, professor, contProfessor, codpesq);
				}
				break;
			case 8:	
				cout << "\tBuscar Professor" << endl;
				for(int codpesq = 9; codpesq != 0;){
					cout << "\n\nInforme o codigo do professor a ser Buscado (0 para Encerrar): ";
        			cin >> codpesq;
        				if (codpesq != 0)
           					buscaAleatProf(indProf, professor, contProfessor, codpesq);
           		}
				break;
			case 9:
				cout << "\tReorganização dos professores" << endl;
				reorganizacaoProf(indProf, idxProfNovo, professor, professorNovo, contProfessor);
				break;
			case 10:
				cout << "\tLeitura Exaustiva dos registros" << endl;
				exaustivaProfessor(indProf,professor,contProfessor);
				break;
			case 11:
				cout << "\tIncluir Modalidade" << endl;
				for(long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o codigo do professor a ser Incluído (0 para Encerrar)" << endl;
        			cin >> codpesq;
        			if (codpesq != 0)
            			buscaModalidade(idxMod, modalidade, contModalidade, codpesq);
    			}
				break;
			case 12:
				cout << "\tExcluir Modalidade" << endl;
				for(long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o codigo do Modalidade a ser excluido (0 para Encerrar): ";
        			cin >> codpesq;
       				 if (codpesq != 0)
            			exclusaoModalidade(idxMod, modalidade, contModalidade, codpesq);
				}
				break;
			case 13:	
				cout << "\tBuscar Modalidade" << endl;
				for(int codpesq = 9; codpesq != 0;){
					cout << "\n\nInforme o codigo da Modalidade a ser Buscado (0 para Encerrar): ";
        			cin >> codpesq;
        				if (codpesq != 0)
           					buscaAleatMod(idxMod, modalidade, contModalidade, codpesq);
           		}
				break;
			case 14:
				cout << "\tReorganização das Modalidades" << endl;
				reorganizacaoMod(idxMod, idxModNovo, modalidade, modalidadeNovo, contModalidade);
				break;
			case 15:
				cout << "\tLeitura Exaustiva dos registros" << endl;
				exaustivaModalidade(idxMod,modalidade,contModalidade);
				break;		
			case 16:
				cout << "\tIncluir Matriculas" << endl;
				for(long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o codigo do professor a ser Incluído (0 para Encerrar)" << endl;
        			cin >> codpesq;
        			if (codpesq != 0)
            			buscaMatricula(idxMat, matricula, contMatricula, codpesq);
    			}
				break;
			case 17:
				cout << "\tExcluir Matriculas" << endl;
				for(long int codpesq = 9; codpesq != 0;){
        			cout << "\n\nInforme o codigo da matricula a ser excluida (0 para Encerrar): ";
        			cin >> codpesq;
       				 if (codpesq != 0)
            			exclusaoMatricula(idxMat, matricula, contMatricula, codpesq);
				}
				break;
			case 18:	
				cout << "\tBuscar Matriculas" << endl;
				break;
			case 19:
				cout << "\tReorganização das Matriculas" << endl;
				break;
			case 20:
				cout << "\tLeitura Exaustiva dos registros" << endl;
				break;							
			case 0:
				cout << "Encerrando..." << endl;
				opcao = 0;
				break;
			default:
				cout << "Numero invalido" << endl;
				break;		
		}		
	}
}
