//Bibliotecas usadas.
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std; //Namespace standard.


//Estrutura criada para receber as informacoes vindas da tabela.
struct RegistroBolsistas {
public:
	RegistroBolsistas(
		//Recebe os valores vindos da leitura da tabela.
		int valor_menu,
		string NM_BOLSISTA,
		string CPF_BOLSISTA,
		string NM_ENTIDADE_ENSINO,
		string ME_REFERENCIA,
		int AN_REFERENCIA,
		string SG_DIRETORIA,
		string SG_SISTEMA_ORIGEM,
		int CD_MODALIDADE_SGB,
		string DS_MODALIDADE_PAGAMENTO,
		string CD_MOEDA,
		float VL_BOLSISTA_PAGAMENTO
	) {
		//Armazena os valores vindo da leitura da tabela nas variaveis criadas na estrutura.
		Valor_menu = valor_menu;
		Nm_bolsista = NM_BOLSISTA;
		Cpf_bolsista = CPF_BOLSISTA;
		Nm_entidade_ensino = NM_ENTIDADE_ENSINO;
		Me_referencia = ME_REFERENCIA;
		An_referencia = AN_REFERENCIA;
		Sg_diretoria = SG_DIRETORIA;
		Sg_sistema_origem = SG_SISTEMA_ORIGEM;
		Cd_modalidade_sgb = CD_MODALIDADE_SGB;
		Ds_modalidade_pagamento = DS_MODALIDADE_PAGAMENTO;
		Cd_moeda = CD_MOEDA;
		Vl_bolsista_pagamento = VL_BOLSISTA_PAGAMENTO;
	}
	//Realiza a impressao das informacoes caso o valor seja o mesmo armazenado na variavel valor_menu.
	void display() {

		if (Valor_menu == 1) {
			//Imprime as informações armazenadas nas variaveis.
			cout << "Nome: " << Nm_bolsista << endl;
			cout << "CPF: " << Cpf_bolsista << endl;
			cout << "Nome da entidade de ensino: " << Nm_entidade_ensino << endl;
			cout << "Valor da bolsa: " << Vl_bolsista_pagamento << endl << endl;
		}
		else if (Valor_menu == 2) {

			char salvo_i = Nm_bolsista[0]; //Armazena o primeiro caracter da string.
			char salvo_f = Nm_bolsista.back(); //Armazena o ultimo caracter da string.
			int codigo_caracter; //Armazena o codigo do caracter.
			
			//Inverte o primeiro caracter e o ultimo da string.
			replace(Nm_bolsista.begin(), Nm_bolsista.end(), Nm_bolsista[0], salvo_f);
			Nm_bolsista.resize(Nm_bolsista.size());
			Nm_bolsista.append(1, salvo_i);

			//Inverte os caracteres da string.
			reverse(Nm_bolsista.begin(), Nm_bolsista.end());

			//Codifica a string mudando cada letra pela proxima letra respectiva do alfabeto. Exemplo: a -> b
			for (int x = 0; x < Nm_bolsista.length(); x++)
			{
				codigo_caracter = int(Nm_bolsista[x]);

				if (codigo_caracter == 122)
				{
					Nm_bolsista[x] = char(97);
				}
				else if (codigo_caracter == 90)
				{
					Nm_bolsista[x] = char(65);
				}
				else if (codigo_caracter >= 65 && codigo_caracter <= 90 || codigo_caracter >= 97 && codigo_caracter <= 122)
				{
					Nm_bolsista[x] = char(codigo_caracter + 1);
				}
			}

			//Imprime as informações armazenadas nas variaveis.
			cout << "Nome: " << Nm_bolsista << endl;
			cout << "Ano: " << An_referencia << endl;
			cout << "Nome da entidade de ensino: " << Nm_entidade_ensino << endl;
			cout << "Valor da bolsa: " << Vl_bolsista_pagamento << endl << endl;
		}
	}
	//Variaveis criadas para armazenar os dados na estrutura, sendo correspondentes as variaveis dentro da funcao main.
	int Valor_menu;
	string Nm_bolsista;
	string Cpf_bolsista;
	string Nm_entidade_ensino;
	string Me_referencia;
	int An_referencia;
	string Sg_diretoria;
	string Sg_sistema_origem;
	int Cd_modalidade_sgb;
	string Ds_modalidade_pagamento;
	string Cd_moeda;
	float Vl_bolsista_pagamento;
};

int main() {

	int valor_menu = 0; //Armazena o valor numerico que sera utilizado para a aplicacao das funcionalidades.
	string lido_menu = ""; //Armazena a informacao escrita pelo usuario no menu, sendo utilizado para a deteccao de valores invalidos.

	//Repete o bloco de execucao ate que o valor "5" seja lido no valor_menu, encerrando o programa.
	while (valor_menu != 5) {

		string NM_BOLSISTA = ""; //Referente ao nome do bolsista na tabela.
		string CPF_BOLSISTA = ""; //Referente ao CPF do bolsista na tabela.
		string NM_ENTIDADE_ENSINO = ""; //Referente ao nome da entidade de ensino superior na tabela.
		string ME_REFERENCIA = ""; //Referente ao mes de referencia na tabela.
		int AN_REFERENCIA = 0; //Referente ao ano de referencia na tabela.
		string SG_DIRETORIA = ""; //Referente a sigla da diretoria na tabela.
		string SG_SISTEMA_ORIGEM = ""; //Referente a sigla do sistema de origem na tabela.
		int CD_MODALIDADE_SGB = 0; //Referente ao codigo de modalidade na tabela.
		string DS_MODALIDADE_PAGAMENTO; //Referente a descricao da modalidade de pagamento na tabela.
		string CD_MOEDA = ""; //Referente ao codigo da moeda na tabela.
		float VL_BOLSISTA_PAGAMENTO = 0; //Referente ao valor da bolsa na tabela.
		string tempString = ""; //Utilizada para fazer a conversao da string lida para as variaveis int e float.

		//Le o caminho relativo para tabela salva em formato csv.
		ifstream ifs("../br-capes-bolsistas-uab.csv");

		//Possibilita a leitura do arquivo.csv a partir de "Tabela".
		ifstream Tabela;
		Tabela.open("../br-capes-bolsistas-uab.csv");

		vector<RegistroBolsistas> bolsistas; //Cria o vetor "bolsistas" em cima da estrutura "RegistroBolsistas".

		//Pula a primeira linha da tabela, para que nao ocorra sua leitura.
		string linha = "";
		getline(Tabela, linha);
		linha = "";

		//Imprime as informacoes do menu na tela.
		cout << "---------------------MENU----------------------" << endl << endl;
		cout << "Diga a opcao que deseja:\n\n";
		cout << "1 - Consultar bolsa zero de um ano\n";
		cout << "2 - Consultar bolsistas com nome codificado\n";
		cout << "3 - Consultar media anual\n";
		cout << "4 - Ranking dos valores de bolsa\n";
		cout << "5 - Terminar programa\n\n";

		//Le o que foi inserido pelo usuario no menu.
		cin >> lido_menu;

		/*Realiza um teste para comprovar se o valor inserido no menu
		e do tipo numerico, ou seja, valido, ao tentar atribuir o valor
		a uma variavel do tipo int.
		*/
		try {
			valor_menu = atoi(lido_menu.c_str());
			if (valor_menu > 0) { //Caso o valor seja valido o codigo continua e o valor e atribuido.
			}
			else {
				throw (lido_menu);
			}
		}
		catch (string invalido_menu) { //Caso o valor seja invalido ele sera armazenado em "invalido_menu" e uma mensagem sera impressa.
			cout << "\nA opcao - " << invalido_menu << " - e invalida.\n";
		}

		//Uma serie de testes logicos e executada para ver a condicao a qual o "valor_menu" se aplica.
		if (valor_menu == 1) {

			int ano_inf; //Armazena o valor do ano que o usuario deseja visualizar.
			string ano_lido = ""; //Armazena a informacao escrita pelo usuario correspondente ao ano, sendo utilizado para a deteccao de valores invalidos.

			//Imprime na tela o texto.
			cout << "\nInforme o ano que deseja visualizar: ";

			//Le o que foi inserido pelo usuario.
			cin >> ano_lido;

			/*Realiza um teste para comprovar se o valor de ano inserido
			e do tipo numerico, ou seja, valido, ao tentar atribuir o valor
			a uma variavel do tipo int.
			*/
			try {
				ano_inf = atoi(ano_lido.c_str());
				if (ano_inf > 0) { //Caso o valor seja valido o codigo continua e o valor e atribuido.
				}
				else {
					throw (ano_lido);
				}
			}
			catch (string invalido) { //Caso o valor seja invalido ele sera armazenado em "invalido" e uma mensagem sera impressa.
				cout << "\nA opcao - " << invalido << " - e invalida.";
			}

			if (ano_inf <= 2012 || ano_inf >= 2017) { //Testa se o valor de ano armazenado esta dentro dos valores da tabela.
				cout << "\nNenhuma informacao encontrada.\n"; //Caso nao esteja imprime o seguinte texto.
			}

			/*
			Caso o valor esteja, repete o bloco abaixo ate que o ano lido na tabela e o ano inserido
			pelo usuario sejam iguais, pegando os valores de cada linha. 
			*/
			else {
				while (getline(Tabela, linha) && AN_REFERENCIA != ano_inf) {

					//Armazena os respectivos valores na tabela as variaveis.

					stringstream inputString(linha);

					getline(inputString, NM_BOLSISTA, ',');
					getline(inputString, CPF_BOLSISTA, ',');
					getline(inputString, NM_ENTIDADE_ENSINO, ',');
					getline(inputString, ME_REFERENCIA, ',');

					//Faz a conversao de string para int.
					getline(inputString, tempString, ',');
					AN_REFERENCIA = atoi(tempString.c_str());

					getline(inputString, SG_DIRETORIA, ',');
					getline(inputString, SG_SISTEMA_ORIGEM, ',');

					//Faz a conversao de string para int.
					tempString = "";
					getline(inputString, tempString, ',');
					CD_MODALIDADE_SGB = atoi(tempString.c_str());

					getline(inputString, DS_MODALIDADE_PAGAMENTO, ',');
					getline(inputString, CD_MOEDA, ',');

					//Faz a conversao de string para float.
					tempString = "";
					getline(inputString, tempString, ',');
					VL_BOLSISTA_PAGAMENTO = atof(tempString.c_str());

					/*
					Caso o ano referenciado na tabela seja igual ao inserido ao vetor
					bolsista, armazenando as informacoes do primeira bolsista do ano.
					*/
					if (AN_REFERENCIA == ano_inf) {
						RegistroBolsistas bolsista(valor_menu, NM_BOLSISTA, CPF_BOLSISTA, NM_ENTIDADE_ENSINO, ME_REFERENCIA, AN_REFERENCIA, SG_DIRETORIA, SG_SISTEMA_ORIGEM, CD_MODALIDADE_SGB, DS_MODALIDADE_PAGAMENTO, CD_MOEDA, VL_BOLSISTA_PAGAMENTO);

						bolsistas.push_back(bolsista); //Armazena o bolsista no vetor bolsistas.
					}

					linha = "";
				}

				//Leva a impressao do texto escrito na estrutura.
				for (auto bolsista : bolsistas) {
					bolsista.display();
				}

			}
		}
		else if (valor_menu == 2) {

			string nome_lido = ""; //Armazena o nome do bolsista que o usuario deseja visualizar.

			//Imprime o texto pedindo que o usuario informe o nome, armazendo-o no "nome_lido" e lendo espaços em branco.
			cout << "\nInforme, sem utilizar acentos, o nome do bolsista que deseja visualizar: ";
			cin.ignore();
			getline(cin, nome_lido);

			//Transforma todos os caracteres do nome em caracteres caixa alta.
			for_each(nome_lido.begin(), nome_lido.end(), [](char& c) {
				c = toupper(c); });

			/*
			Repete o bloco abaixo ate que o nome na tabela e o nome inserido
			pelo usuario sejam iguais, pegando os valores de cada linha.
			*/

			while (getline(Tabela, linha) && NM_BOLSISTA != nome_lido) {

				stringstream inputString(linha);

				getline(inputString, NM_BOLSISTA, ',');
				getline(inputString, CPF_BOLSISTA, ',');
				getline(inputString, NM_ENTIDADE_ENSINO, ',');
				getline(inputString, ME_REFERENCIA, ',');

				getline(inputString, tempString, ',');
				AN_REFERENCIA = atoi(tempString.c_str());

				getline(inputString, SG_DIRETORIA, ',');
				getline(inputString, SG_SISTEMA_ORIGEM, ',');

				tempString = "";
				getline(inputString, tempString, ',');
				CD_MODALIDADE_SGB = atoi(tempString.c_str());

				getline(inputString, DS_MODALIDADE_PAGAMENTO, ',');
				getline(inputString, CD_MOEDA, ',');

				tempString = "";
				getline(inputString, tempString, ',');
				VL_BOLSISTA_PAGAMENTO = atof(tempString.c_str());

				//Caso o nome do bolsista seja o mesmo do nome inserido, as informacoes sao salvas.
				if (NM_BOLSISTA == nome_lido) {
					RegistroBolsistas bolsista(valor_menu, NM_BOLSISTA, CPF_BOLSISTA, NM_ENTIDADE_ENSINO, ME_REFERENCIA, AN_REFERENCIA, SG_DIRETORIA, SG_SISTEMA_ORIGEM, CD_MODALIDADE_SGB, DS_MODALIDADE_PAGAMENTO, CD_MOEDA, VL_BOLSISTA_PAGAMENTO);

					bolsistas.push_back(bolsista);
				}

				linha = "";
			}

			//Leva a impressao do texto escrito na estrutura.
			for (auto bolsista : bolsistas) {
				bolsista.display();
			}

			//Caso o nome nao seja encontrado, a mensagem e impressa.
			if (nome_lido != NM_BOLSISTA) {
				cout << "\nNome nao encontrado.\n\n";
			}

		}
		else if (valor_menu == 3) {

			int ano_inf = 0; //Armazena o valor do ano que o usuario deseja visualizar.
			string ano_lido = ""; //Armazena a informacao escrita pelo usuario correspondente ao ano, sendo utilizado para a deteccao de valores invalidos.
			float SOMA = 0; //Armazena a soma dos valores das bolsas.
			float DIVISOR = 0; //Armazena a quantidade de vezes que um valor foi somado a "soma", para ser utilizado como divisor.

			//Imprime na tela o texto.
			cout << "\nInforme o ano que deseja visualizar: ";

			//Le o que foi inserido pelo usuario.
			cin >> ano_lido;

			/*
			Realiza um teste para comprovar se o valor de ano inserido
			e do tipo numerico, ou seja, valido, ao tentar atribuir o valor
			a uma variavel do tipo int.
			*/
			try {
				ano_inf = atoi(ano_lido.c_str());
				if (ano_inf > 0) { //Caso o valor seja valido o codigo continua e o valor e atribuido.
				}
				else {
					throw (ano_lido);
				}
			}
			catch (string invalido) { //Caso o valor seja invalido ele sera armazenado em "invalido" e uma mensagem sera impressa.
				cout << "\nA opcao - " << invalido << " - e invalida.";
			}

			if (ano_inf <= 2012 || ano_inf >= 2017) { //Testa se o valor de ano armazenado esta dentro dos valores da tabela.
				cout << "\nNenhuma informacao encontrada.\n"; //Caso nao esteja imprime o seguinte texto.
			}
			/*
			Repete o bloco abaixo ate o fim da tabela, pegando os valores de cada linha.
			*/
			else {
				while (getline(Tabela, linha)) {

					stringstream inputString(linha);

					getline(inputString, NM_BOLSISTA, ',');
					getline(inputString, CPF_BOLSISTA, ',');
					getline(inputString, NM_ENTIDADE_ENSINO, ',');
					getline(inputString, ME_REFERENCIA, ',');

					getline(inputString, tempString, ',');
					AN_REFERENCIA = atoi(tempString.c_str());

					getline(inputString, SG_DIRETORIA, ',');
					getline(inputString, SG_SISTEMA_ORIGEM, ',');

					tempString = "";
					getline(inputString, tempString, ',');
					CD_MODALIDADE_SGB = atoi(tempString.c_str());

					getline(inputString, DS_MODALIDADE_PAGAMENTO, ',');
					getline(inputString, CD_MOEDA, ',');

					tempString = "";
					getline(inputString, tempString, ',');
					VL_BOLSISTA_PAGAMENTO = atof(tempString.c_str());

					if (VL_BOLSISTA_PAGAMENTO > 0) {
					}
					else {
						getline(inputString, tempString, ',');
						VL_BOLSISTA_PAGAMENTO = atof(tempString.c_str());
					}

					//Caso o ano inserido seja o mesmo do atual salvo no ano referenciado na tabela, ele realiza a soma e aumenta o divisor, além de salvar os valores.
					if (AN_REFERENCIA == ano_inf) {

						SOMA += VL_BOLSISTA_PAGAMENTO;
						DIVISOR = DIVISOR + 1;

						RegistroBolsistas bolsista(valor_menu, NM_BOLSISTA, CPF_BOLSISTA, NM_ENTIDADE_ENSINO, ME_REFERENCIA, AN_REFERENCIA, SG_DIRETORIA, SG_SISTEMA_ORIGEM, CD_MODALIDADE_SGB, DS_MODALIDADE_PAGAMENTO, CD_MOEDA, VL_BOLSISTA_PAGAMENTO);

						bolsistas.push_back(bolsista);
					}

					linha = "";
				}

				//Realiza o calculo da media do ano e imprime na tela.
				cout << "A media das notas do ano " << ano_inf << " e: " << SOMA / DIVISOR << endl << endl;

			}
		}
		else if (valor_menu == 4) {

			float maior_valor_1 = 0; //Referente ao maior valor de bolsa na tabela.
			float maior_valor_2 = 0; //Referente ao segundo maior valor de bolsa na tabela.
			float maior_valor_3 = 0; //Referente ao terceiro maior valor de bolsa na tabela.
			string nome_maior_1 = ""; //Referente ao nome do bolsista com o maior valor de bolsa na tabela.
			string nome_maior_2 = ""; //Referente ao nome do bolsista com o segundo maior valor de bolsa na tabela.
			string nome_maior_3 = ""; //Referente ao nome do bolsista com o terceiro maior valor de bolsa na tabela.

			float menor_valor_1 = 9999; //Referente ao menor valor de bolsa na tabela.
			float menor_valor_2 = 9999; //Referente ao segundo menor valor de bolsa na tabela.
			float menor_valor_3 = 9999;  //Referente ao terceiro menor valor de bolsa na tabela.
			string nome_menor_1 = ""; //Referente ao nome do bolsista com o menor valor de bolsa na tabela.
			string nome_menor_2 = ""; //Referente ao nome do bolsista com o segundo menor valor de bolsa na tabela.
			string nome_menor_3 = ""; //Referente ao nome do bolsista com o terceiro menor valor de bolsa na tabela.

			/*
			Repete o bloco abaixo ate o fim da tabela, pegando os valores de cada linha.
			*/
			while (getline(Tabela, linha)) {

				stringstream inputString(linha);

				getline(inputString, NM_BOLSISTA, ',');
				getline(inputString, CPF_BOLSISTA, ',');
				getline(inputString, NM_ENTIDADE_ENSINO, ',');
				getline(inputString, ME_REFERENCIA, ',');

				getline(inputString, tempString, ',');
				AN_REFERENCIA = atoi(tempString.c_str());

				getline(inputString, SG_DIRETORIA, ',');
				getline(inputString, SG_SISTEMA_ORIGEM, ',');

				tempString = "";
				getline(inputString, tempString, ',');
				CD_MODALIDADE_SGB = atoi(tempString.c_str());

				getline(inputString, DS_MODALIDADE_PAGAMENTO, ',');
				getline(inputString, CD_MOEDA, ',');

				tempString = "";
				getline(inputString, tempString, ',');
				VL_BOLSISTA_PAGAMENTO = atof(tempString.c_str());

				//Armazena os maiores valores e os nomes referentes a esses valores na tabela.
				if (maior_valor_1 <= VL_BOLSISTA_PAGAMENTO) {
					if (maior_valor_2 <= maior_valor_1) {
						if (maior_valor_3 <= maior_valor_2) {
							maior_valor_3 = maior_valor_2;
							nome_maior_3 = nome_maior_2;
						}
						maior_valor_2 = maior_valor_1;
						nome_maior_2 = nome_maior_1;
					}
					maior_valor_1 = VL_BOLSISTA_PAGAMENTO;
					nome_maior_1 = NM_BOLSISTA;
				}

				//Armazena os menores valores e os nomes referentes a esses valores na tabela.
				if (menor_valor_1 >= VL_BOLSISTA_PAGAMENTO && VL_BOLSISTA_PAGAMENTO != 0) {
					if (menor_valor_2 >= menor_valor_1) {
						if (menor_valor_3 >= menor_valor_2) {
							menor_valor_3 = menor_valor_2;
							nome_menor_3 = nome_menor_2;
						}
						menor_valor_2 = menor_valor_1;
						nome_menor_2 = nome_menor_1;
					}
					menor_valor_1 = VL_BOLSISTA_PAGAMENTO;
					nome_menor_1 = NM_BOLSISTA;
				}

				RegistroBolsistas bolsista(valor_menu, NM_BOLSISTA, CPF_BOLSISTA, NM_ENTIDADE_ENSINO, ME_REFERENCIA, AN_REFERENCIA, SG_DIRETORIA, SG_SISTEMA_ORIGEM, CD_MODALIDADE_SGB, DS_MODALIDADE_PAGAMENTO, CD_MOEDA, VL_BOLSISTA_PAGAMENTO);

				bolsistas.push_back(bolsista);

				linha = "";
			}

			//Imprime os maiores valores na tabela e os bolsistas referentes a eles.
			cout << "Os alunos com os tres maiores valores de bolsa listados sao: " << endl << endl;
			cout << "1 - " << nome_maior_1 << " - " << maior_valor_1 << endl;
			cout << "2 - " << nome_maior_2 << " - " << maior_valor_2 << endl;
			cout << "3 - " << nome_maior_3 << " - " << maior_valor_3 << endl << endl;

			//Imprime os menores valores na tabela e os bolsistas referentes a eles.
			cout << "Os alunos com os tres menores valores de bolsa listados sao: " << endl << endl;
			cout << "1 - " << nome_menor_1 << " - " << menor_valor_1 << endl;
			cout << "2 - " << nome_menor_2 << " - " << menor_valor_2 << endl;
			cout << "3 - " << nome_menor_3 << " - " << menor_valor_3 << endl;

		}
		//Finaliza o programa e imprime o texto na tela.
		else if (valor_menu == 5) {
			cout << "\n\nVoce encerrou o programa, feche a janela." << endl;
			exit(0);
		}
		//Imprime a mensagem caso seja colocado um valor numerico invalido.
		else if (valor_menu != 0) {
			cout << "\nA opcao - " << valor_menu << " - e invalida.\n";
		}

	}

	return 0;
}