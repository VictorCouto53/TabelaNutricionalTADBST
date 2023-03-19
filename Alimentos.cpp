#include "Alimentos.h"
#include "Utils.h"
#include <sstream>
using namespace std;

Alimentos::Alimentos(std::string foodAndServing, 
  float calories,
  float caloriesFromFat,
  float totalFat,
  float totalFatDV,
  float sodium,
  float sodiumDV,
  float potassium,
  float potassiumDV,
  float totalCarbonHydrate,
  float totalCarbonHydrateDV,
  float dietaryFiber,
  float dietaryFiberDV,
  float sugars,
  float protein,
  float vitaminA,
  float vitaminC,
  float calcium,
  float iron,
  float saturatedFatDV,
  float saturatedFat,
  float cholesterolDV,
  float cholesterol)

  :m_foodAndServing(foodAndServing)
  ,m_calories(calories)
  ,m_caloriesFromFat(caloriesFromFat)
  ,m_totalFat(totalFat)
  ,m_totalFatDV(totalFatDV)
  ,m_sodium(sodium)
  ,m_sodiumDV(sodiumDV)
  ,m_potassium(potassium)
  ,m_potassiumDV(potassiumDV)
  ,m_totalCarbonHydrate(totalCarbonHydrate)
  ,m_totalCarbonHydrateDV(totalCarbonHydrateDV)
  ,m_dietaryFiber(dietaryFiber)
  ,m_dietaryFiberDV(dietaryFiberDV)
  ,m_sugars(sugars)
  ,m_protein(protein)
  ,m_vitaminA(vitaminA)
  ,m_vitaminC(vitaminC)
  ,m_calcium(calcium)
  ,m_iron(iron)
  ,m_saturatedFatDV(saturatedFatDV)
  ,m_saturatedFat(saturatedFat)
  ,m_cholesterolDV(cholesterolDV)
  ,m_cholesterol(cholesterol)
{
}

// foodAndServing
string Alimentos::Get_foodAndServing() const
{
  return m_foodAndServing;
}
void Alimentos::Set_foodAndServing(const std::string foodAndServing)
{
  m_foodAndServing = foodAndServing;
}

// calories
float Alimentos::Get_calories() const
{
  return m_calories;
}
void Alimentos::Set_calories(const float calories)
{
  m_calories = calories;
}

// caloriesFromFat
float Alimentos::Get_caloriesFromFat() const
{
  return m_caloriesFromFat;
}
void Alimentos::Set_caloriesFromFat(const float caloriesFromFat){
  m_caloriesFromFat = caloriesFromFat;
}

// totalFat
float Alimentos::Get_totalFat() const
{
  return m_totalFat;
}
void Alimentos::Set_totalFat(const float totalFat){
  m_totalFat = totalFat;
}

//totalFatDV
float Alimentos::Get_totalFatDV() const
{
  return m_totalFatDV;
}
void Alimentos::Set_totalFatDV(const float totalFatDV){
  m_totalFatDV = totalFatDV;
}

// sodium
float Alimentos::Get_sodium() const
{
  return m_sodium;
}
void Alimentos::Set_sodium(const float sodium){
  m_sodium = sodium;
}

// sodiumDV
float Alimentos::Get_sodiumDV() const
{
  return m_sodiumDV;
}
void Alimentos::Set_sodiumDV(const float sodiumDV){
  m_sodium = sodiumDV;
}

// potassium
float Alimentos::Get_potassium() const
{
  return m_potassium;
}
void Alimentos::Set_potassium(const float potassium)
{
  m_potassium = potassium;
}

// potassiumDV
float Alimentos::Get_potassiumDV() const
{
  return m_potassiumDV;
}
void Alimentos::Set_potassiumDV(const float potassiumDV)
{
  m_potassiumDV = potassiumDV;
}

// totalCarbonHydrate
float Alimentos::Get_totalCarbonHydrate() const
{
  return m_totalCarbonHydrate;
}
void Alimentos::Set_totalCarbonHydrate(const float totalCarboHydrate){
  m_totalCarbonHydrate = totalCarboHydrate;
}

// totalCarbonHydrateDV
float Alimentos::Get_totalCarbonHydrateDV() const
{
  return m_totalCarbonHydrateDV;
}
void Alimentos::Set_totalCarbonHydrateDV(const float totalCarboHydrateDV)
{
  m_totalCarbonHydrateDV = totalCarboHydrateDV;
}

// dietaryFiber
float Alimentos::Get_dietaryFiber() const
{
  return m_dietaryFiber;
}
void Alimentos::Set_dietaryFiber(const float dietaryFiber)
{
  m_dietaryFiber = dietaryFiber;
}

// dietaryFiberDV
float Alimentos::Get_dietaryFiberDV() const
{
  return m_dietaryFiberDV;
}
void Alimentos::Set_dietaryFiberDV(const float dietaryFiberDV)
{
  m_dietaryFiberDV = dietaryFiberDV;
}

// sugars
float Alimentos::Get_sugars() const
{
  return m_sugars;
}
void Alimentos::Set_sugars(const float sugars)
{
  m_sugars = sugars;
}

// protein
float Alimentos::Get_protein() const
{
  return m_protein;
}
void Alimentos::Set_protein(const float protein)
{
  m_protein = protein;
}

// vitaminA
float Alimentos::Get_vitaminA() const
{
  return m_vitaminA;
}
void Alimentos::Set_vitaminA(const float vitaminA)
{
  m_vitaminA = vitaminA;
}

// vitaminC
float Alimentos::Get_vitaminC() const
{
  return m_vitaminC;
}
void Alimentos::Set_vitaminC(const float vitaminC)
{
  m_vitaminC = vitaminC;
}

// calcium
float Alimentos::Get_calcium() const
{
  return m_calcium;
}
void Alimentos::Set_calcium(const float calcium)
{
  m_calcium = calcium;
}

// iron
float Alimentos::Get_iron() const
{
  return m_iron;
}
void Alimentos::Set_iron(const float iron)
{
  m_iron = iron;
}

// saturatedFatDV
float Alimentos::Get_saturatedFatDV() const
{
  return m_saturatedFatDV;
}
void Alimentos::Set_saturatedFatDV(const float saturatedFatDV)
{
  m_saturatedFatDV = saturatedFatDV;
}

// saturatedFat
float Alimentos::Get_saturatedFat() const
{
  return m_saturatedFat;
}
void Alimentos::Set_saturatedFat(const float saturatedFat)
{
  m_saturatedFat = saturatedFat;
}

// cholesterolDV
float Alimentos::Get_cholesterolDV() const
{
  return m_cholesterolDV;
}
void Alimentos::Set_cholesterolDV(const float cholesterolDV)
{
  m_cholesterolDV = cholesterolDV;
}

// cholesterol
float Alimentos::Get_cholesterol() const
{
  return m_cholesterol;
}
void Alimentos::Set_cholesterol(const float cholesterol)
{
  m_cholesterol = cholesterol;
}

std::string Alimentos::ShowNutrionalValues()
{
  std::ostringstream oss;
  oss << Get_foodAndServing() << "\n"
  << "├─" << "Calories: " << Get_calories() << "g" << "\n"
  << "├─" << "Calories from fat: " << Get_caloriesFromFat() << "g" << "\n"
  << "├─" << "Total fat: " << Get_totalFat() << "g" << "\n"
  << "├─" << "Total fat(daily values): " << Get_totalFatDV() << "%" << "\n"
  << "├─" << "Sodium: " << Get_sodium() << "mg" << "\n"
  << "├─" << "Sodium(daily values): " << Get_sodiumDV() << "%" << "\n"
  << "├─" << "Potassium: " << Get_potassium() << "mg" << "\n"
  << "├─" << "Potassium(daily values): " << Get_potassiumDV() << "%" << "\n"
  << "├─" << "Total carbon hydrate: " << Get_totalCarbonHydrate() << "g" << "\n"
  << "├─" << "Total carbon hydrate(daily values): " << Get_totalCarbonHydrateDV() << "%" << "\n"
  << "├─" << "Dietary fiber: " << Get_dietaryFiber() << "mg" << "\n"
  << "├─" << "Dietary fiber(daily values): " << Get_dietaryFiberDV() << "%" << "\n"
  << "├─" << "Sugars: " << Get_sugars() << "g" << "\n"
  << "├─" << "Protein: " << Get_protein() << "g" << "\n"
  << "├─" << "Vitamin A(daily values): " << Get_vitaminA() << "%" << "\n"
  << "├─" << "Vitamin C(daily values): " << Get_vitaminC() << "%" << "\n"
  << "├─" << "Calcium(daily values): " << Get_calcium() << "%" << "\n"
  << "├─" << "Iron(daily values): " << Get_iron() << "%" << "\n"
  << "├─" << "Saturated fat(daily values): " << Get_saturatedFatDV() << "%" << "\n"
  << "├─" << "Saturated fat: " << Get_saturatedFat() << "g" << "\n"
  << "├─" << "Cholesterol(daily values): " << Get_cholesterolDV() << "%" << "\n"
  << "└─" << "Cholesterol: " << Get_cholesterol() << "g" << "\n";

  return oss.str();
}