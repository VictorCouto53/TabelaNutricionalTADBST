#include "BST.h"
#include "LeitorCSV.h"
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
using namespace std;

void aliData(BST *arvore, list<string> lista) 
{
  NodeBST *node;
  list<NodeBST *> listaInfo{};
  cout << "Informações das suas refeicoes: \n\n";
  for (auto it = lista.begin(); it != lista.end();
       ++it)
  {
    node = arvore->Search(*it);

    if (node == nullptr) {
      cout << "O alimento " << *it << " não foi encontrado!\n\n";
      continue;
    }
    listaInfo.push_back(node);
  }

  float caloriess = 0;
  float caloriesFromFats = 0;
  float totalFats = 0;
  float totalFatDVs = 0;
  float sodiums = 0;
  float sodiumDVs = 0;
  float potassiums = 0;
  float potassiumDVs = 0;
  float totalCarbonHydrates = 0;
  float totalCarbonHydrateDVs = 0;
  float dietaryFibers = 0;
  float dietaryFiberDVs = 0;
  float sugarss = 0;
  float proteins = 0;
  float vitaminAs = 0;
  float vitaminCs = 0;
  float calciums = 0;
  float irons = 0;
  float saturatedFatDVs = 0;
  float saturatedFats = 0;
  float cholesterolDVs = 0;
  float cholesterols = 0;

  for (NodeBST *x : listaInfo) 
  {
    caloriess += x->GetData()->Get_calories();
    caloriesFromFats += x->GetData()->Get_caloriesFromFat();
    totalFats += x->GetData()->Get_totalFat();
    totalFatDVs += x->GetData()->Get_totalFatDV();
    sodiums += x->GetData()->Get_sodium();
    sodiumDVs += x->GetData()->Get_sodiumDV();
    potassiums += x->GetData()->Get_potassium();
    potassiumDVs += x->GetData()->Get_potassiumDV();
    totalCarbonHydrates += x->GetData()->Get_totalCarbonHydrate();
    totalCarbonHydrateDVs += x->GetData()->Get_totalCarbonHydrateDV();
    dietaryFibers += x->GetData()->Get_dietaryFiber();
    dietaryFiberDVs += x->GetData()->Get_dietaryFiberDV();
    sugarss += x->GetData()->Get_sugars();
    proteins += x->GetData()->Get_protein();
    vitaminAs += x->GetData()->Get_vitaminA();
    vitaminCs += x->GetData()->Get_vitaminC();
    calciums += x->GetData()->Get_calcium();
    irons += x->GetData()->Get_iron();
    saturatedFatDVs += x->GetData()->Get_saturatedFatDV();
    saturatedFats += x->GetData()->Get_saturatedFat();
    cholesterolDVs += x->GetData()->Get_cholesterolDV();
    cholesterols += x->GetData()->Get_cholesterol();
  }

  cout << "Valores nutricionas das suas refeições"
       << "\n"
       << "├─"
       << "Calories: " << caloriess << "g"
       << "\n"
       << "├─"
       << "Calories from fat: " << caloriesFromFats << "g"
       << "\n"
       << "├─"
       << "Total fat: " << totalFats << "g"
       << "\n"
       << "├─"
       << "Total fat(daily values): " << totalFatDVs << "%"
       << "\n"
       << "├─"
       << "Sodium: " << sodiums << "mg"
       << "\n"
       << "├─"
       << "Sodium(daily values): " << sodiumDVs << "%"
       << "\n"
       << "├─"
       << "Potassium: " << potassiums << "mg"
       << "\n"
       << "├─"
       << "Potassium(daily values): " << potassiumDVs << "%"
       << "\n"
       << "├─"
       << "Total carbon hydrate: " << totalCarbonHydrates << "g"
       << "\n"
       << "├─"
       << "Total carbon hydrate(daily values): " << totalCarbonHydrateDVs << "%"
       << "\n"
       << "├─"
       << "Dietary fiber: " << dietaryFibers << "mg"
       << "\n"
       << "├─"
       << "Dietary fiber(daily values): " << dietaryFiberDVs << "%"
       << "\n"
       << "├─"
       << "Sugars: " << sugarss << "g"
       << "\n"
       << "├─"
       << "Protein: " << proteins << "g"
       << "\n"
       << "├─"
       << "Vitamin A(daily values): " << vitaminAs << "%"
       << "\n"
       << "├─"
       << "Vitamin C(daily values): " << vitaminCs << "%"
       << "\n"
       << "├─"
       << "Calcium(daily values): " << calciums << "%"
       << "\n"
       << "├─"
       << "Iron(daily values): " << irons << "%"
       << "\n"
       << "├─"
       << "Saturated fat(daily values): " << saturatedFatDVs << "%"
       << "\n"
       << "├─"
       << "Saturated fat: " << saturatedFats << "g"
       << "\n"
       << "├─"
       << "Cholesterol(daily values): " << cholesterolDVs << "%"
       << "\n"
       << "└─"
       << "Cholesterol: " << cholesterols << "mg"
       << "\n\n";
}

void preencherLista(BST *arvore) 
{
  list<string>
      lista{};
  string alimento;
  cout << "\n\n" << arvore->TraverseInOrder() << "\n\n";
  cout << "\nDigite p para parar\n";

  while (alimento != "p") 
  {
    cout << "\nNome do alimento: \n";
    cin >> alimento;
    lista.push_back(alimento);
  }
  lista.pop_back();
  aliData(arvore, lista);
}

void procurarAlimento(BST *arvore) 
{
  std::string alimento;
  NodeBST *res;

  cout << "\n" << arvore->TraverseInOrder() << "\n";
  cout << "\nQual alimento deseja procurar?: ";
  cin >> alimento;

  res = arvore->Search(alimento);

  if (res == nullptr) {
    cout << "\nAlimento não encontrado!\n";
    return;
  }

  cout << res->GetData()->ShowNutrionalValues() << "\n\n";
}

void setmenu() 
{
  cout << "||=================================================||\n"
       << "||             "
       << "Bem vindo ao programa"
       << "               ||\n"
       << "||=================================================||\n"
       << "||       "
       << "Opções do programa:"
       << "                       ||\n"
       << "||       ├─"
       << "[1]: Informe os alimentos consumidos"
       << "    ||\n"
       << "||       ├─"
       << "[2]: Detalhes nutricionais do alimento"
       << "  ||\n"
       << "||       ├─"
       << "[3]: Árvore em Pré Ordem"
       << "                ||\n"
       << "||       ├─"
       << "[4]: Árvore em Ordem"
       << "                    ||\n"
       << "||       ├─"
       << "[5]: Árvore em Pós Ordem"
       << "                ||\n"
       << "||       └─"
       << "[0]: Sair"
       << "                               ||\n"
       << "||=================================================||\n";
}

int main() 
{
  BST *arvore = new BST();
  insertAlimentos(arvore);

  int alt = -1;
  while (alt != 0) 
  {
    setmenu();
    cout << "\nEscolha sua opção.\n";
    cin >> alt;
    if (alt < 0 || alt > 5)
      cout << "Opção inválida!\n\n";
    switch (alt) 
    {
    case 1:
      preencherLista(arvore);
      break;
    case 2:
      procurarAlimento(arvore);
      break;
    case 3:
      cout << arvore->TraversePreOrder() << "\n\n";
      break;
    case 4:
      cout << arvore->TraverseInOrder() << "\n\n";
      break;
    case 5:
      cout << arvore->TraversePostOrder() << "\n\n";
      break;
    }
  }
  return 0;
}