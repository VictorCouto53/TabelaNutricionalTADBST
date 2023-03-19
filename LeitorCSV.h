#ifndef LEITORCSV_CPP
#define LEITORCSV_CPP
#include <vector>
#include <fstream>
#include "BST.h"
using namespace std;

void lerCSV(const string&arquivo, vector<vector<string> >&tabela)
{
  ifstream t(arquivo);
  string csvConteudo((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
  bool as(false);
  bool linhanova(false);
  string campo;
  vector<string> line;
  tabela.clear();

  string::const_iterator achar = csvConteudo.begin();
  while (achar != csvConteudo.end())
  {
    switch (*achar)
    {
      case '"':
        linhanova = false;
        as = !as;
        break;
      case ',':
        linhanova = false;
        if (as){
          campo += *achar;
        }else
        {
          line.push_back(campo);
          campo.clear();
        }
        break;
      case '\n':
      case '\r':
        if (as){
          campo += *achar;
        }else
        {
          if (!linhanova)
          {
            line.push_back(campo);
            tabela.push_back(line);
            campo.clear();
            line.clear();
            linhanova = true;
          }
        }
        break;
      default:
        linhanova = false;
        campo.push_back(*achar);
        break;
    }
    achar++;
  }
  if (!campo.empty())
  {
    line.push_back(campo);
  }
  if (!line.empty()){
    tabela.push_back(line);
  }
}


void insertAlimentos(BST* arv)
{
  vector<vector<string>> tabela;
  Alimentos* alimento;
  NodeBST* node;
  //dataset_corrigido
  lerCSV("dataset.csv", tabela);
  for(int i=1; i<tabela.size(); i++)
  {
    alimento = new Alimentos(
    tabela[i][0],
    stof(tabela[i][1]),
    stof(tabela[i][2]),
    stof(tabela[i][3]),
    stof(tabela[i][4]),
    stof(tabela[i][5]),
    stof(tabela[i][6]),
    stof(tabela[i][7]),
    stof(tabela[i][8]),
    stof(tabela[i][9]),
    stof(tabela[i][10]),
    stof(tabela[i][11]),
    stof(tabela[i][12]),
    stof(tabela[i][13]),
    stof(tabela[i][14]),
    stof(tabela[i][15]),
    stof(tabela[i][16]),
    stof(tabela[i][17]),
    stof(tabela[i][18]),
    stof(tabela[i][19]),
    stof(tabela[i][20]),
    stof(tabela[i][21]),
    stof(tabela[i][22]));
    node = arv -> Insert(alimento);
  }
}

#endif
