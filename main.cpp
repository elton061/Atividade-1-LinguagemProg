#include <iostream>
#include <math.h>
#include <string>
#include <fstream>


using namespace std;

void porcentagem();
void JurosSimples();
void JurosCompostos();
void escrever_no_arquivo();
int importa_nomes(string nome[70], int idade[70]);
void lista(int idade[70], string nome[70], int limit);
void imc();
void raiz();
void diagonal();

int main()
{
   int opcao, idade[70], limitador;
   string nome[70];

   cout << "1) Porcentagem. \n2) Juros simples. \n3) Juros compostos. \n4) Salvar nomes e idades em um arquivo .txt \n5) Listar nomes e idade salvos nos arquivos.\n6) Calculo de IMC."
   << "\n7) Calcular Raiz de um numero.\n8) Cria uma matriz e mostra valores da diagonal principal e secundaria.\n\n";

   cout << "Digite o numero correspondente a opcao desejada: ";
   cin >> opcao;

   switch(opcao)
   {
      case 1:
         porcentagem();
         break;

      case 2:
         JurosSimples();
         break;

      case 3:
         JurosCompostos();
         break;

      case 4:
         escrever_no_arquivo();
         break;

      case 5:
         limitador = importa_nomes(nome, idade);
         lista(idade, nome, limitador);
         break;

      case 6:
         imc();
         break;

      case 7:
         raiz();
         break;

      case 8:
         diagonal();
         break;

   }
   return 0;
}

void porcentagem (){

   double numero, porcentagem, result;

   cout << "\n\nDigite um numero: ";
   cin >> numero;
   cout << "Digite a porcentagem que deseja calcular: ";
   cin >> porcentagem;

   result = numero * porcentagem / 100;

   cout << porcentagem << " % de " << numero << " e igual a " << result << endl;
}

void JurosSimples(){

   double capital, taxa, tempo, resultado;

   cout << "\nOBS: Use a mesma unidade de tempo entre a taxa de juros e o tempo de aplicacao!\n";

   cout << "\nDigite o capital inicial: ";
   cin >> capital;
   cout << "Digite a taxa de juros: ";
   cin >> taxa;
   cout << "Digite o tempo de aplicacao: ";
   cin >> tempo;

   resultado = capital * taxa / 100 * tempo;

   cout << "\nO montante final da aplicacao e = R$" << capital + resultado << " e o juros neste periodo foi = R$" << resultado << endl;
}

void JurosCompostos(){

   double capital, taxa, tempo, resultado;

   cout << "\nOBS: Use a mesma unidade de tempo entre a taxa de juros e o tempo de aplicacao!\n";

   cout << "\nDigite o capital inicial: ";
   cin >> capital;
   cout << "Digite a taxa de juros: ";
   cin >> taxa;
   cout << "Digite o tempo de aplicacao: ";
   cin >> tempo;

   resultado = capital * pow((taxa / 100.0 + 1.0), tempo);

   cout << "\nO montante final da aplicacao e = R$" << resultado << " e o juros neste periodo foi = R$" << resultado - capital << endl;
}

void escrever_no_arquivo(){

   string nomes;
   int idades;
   char resp = 's';

   ofstream nome;
   nome.open("lista_nomes.txt", ios::app);

   ofstream idade;
   idade.open("idades.txt", ios::app);

   while(resp == 's' || resp == 'S')
   {
      cin.ignore();
      cout << "\nDigite um nome: ";
      getline(cin, nomes);
      nome << nomes << "\n";

      cout << "Digite a idade: ";
      cin >> idades;
      idade << idades << "\n";

      cout << "Deseja adicionar mais alguma pessoa? [s/n]";
      cin >> resp;
   }
   cout << endl;

   nome.close();
   idade.close();
}

int importa_nomes(string nome[70], int idade[70]){

   int i=0, limitador = 0;
   string linha;

   ifstream nomes;
   nomes.open("lista_nomes.txt");
   while(getline(nomes,linha))
   {
      nome[i] = linha;
      i++;
   }

   limitador = i;
   nomes.close();

   i=0;
   ifstream idades;
   idades.open("idades.txt");
   while(idades >> idade[i])
      i++;

   idades.close();

   return limitador;
}

void lista(int idade[70],  string nome[70], int limit){
   cout << "\nNome\t\t\t\tidade\n";

   for(int i=0; i < limit; i++)
   {
      cout << nome[i] << "\t\t\t\t" << idade[i] << "\n";
   }
   cout << endl;
}

void imc(){

   float peso, altura, imc;
   string status;

   cout << "\nDigite a sua altura em metros: ";
   cin >> altura;
   cout << "\nDigite o seu peso em kg: ";
   cin >> peso;

   if(altura > 4.0) // converte para metros caso o usuario coloque cm.
      altura /= 100.0;

   imc = peso / (altura * altura);

   if(imc < 18.6)
      status = "Abaixo do peso";
   else if(imc <= 24.9)
      status = "Normal";
   else if(imc <= 29.9)
      status = "levemente acima do peso";
   else if(imc <= 34.9)
      status = "Obesidade grau 1";
   else if(imc <= 39.9)
      status = "Obesidade grau 2(severa)";
   else
      status = "Obesidade grau 3(morbida)";

   cout << "\nAltura = " << altura << " metros\nPeso = " << peso << " kg\nIMC = " << imc << "\nClassificacao = " << status << endl;
}

void raiz(){

   double numero, resultado;
   int grau;

   cout << "\nDigite um numero: ";
   cin >> numero;

   cout << "Digite o grau da raiz que deseja calcular: ";
   cin >> grau;

   resultado = pow(numero, 1.0/(double)grau);

   cout << "\nResultado = " << resultado << endl;
}

void diagonal(){

   double matriz[3][3];
   int i, j;

   cout << "\nPreencha uma matriz 3x3 com valores reais. \n";

   for(i=0; i < 3; i++)
   {
      for(j=0; j < 3; j++)
      {
         cout << "\nLinha " << i+1 << " coluna " << j+1 << ":   ";
         cin >> matriz[i][j];
      }
   }

   cout << "\n\n";
   for(i = 0; i < 3; i++)
   {
      for(j = 0; j < 3; j++)
      {
         cout << "\t" << matriz[i][j] << "\t";
      }
      cout << "\n\n\n";
   }

   j=0;
   cout << "Valores da diagonal principal: ";
   for(i = 0; i < 3; i++)
   {
      cout << matriz[i][j];

      if(i < 2)
         cout << ", ";

      j++;
   }

   j=2;
   cout << "\nValores da diagonal secundaria: ";
   for(i=0; i < 3; i++)
   {
       cout << matriz[i][j];

       if(i < 2)
          cout << ", ";

       j--;
   }
   cout << endl;
}
