#ifndef __ALIMENTOS_H__
#define __ALIMENTOS_H__

#include <string>

class Alimentos
{
public:
  Alimentos(std::string foodAndServing, 
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
  float dietaryFiberDV ,
  float sugars,
  float protein,
  float vitaminA,
  float vitaminC,
  float calcium,
  float iron,
  float saturatedFatDV,
  float saturatedFat,
  float cholesterolDV,
  float cholesterol);
  ~Alimentos();

  void CopyDataFrom(const Alimentos* node);

  std::string Get_foodAndServing() const;
  void Set_foodAndServing(const std::string foodAndServing);

  float Get_calories() const;
  void Set_calories(const float calories);

  float Get_caloriesFromFat() const;
  void   Set_caloriesFromFat(const float caloriesFromFat);

  float Get_totalFat() const;
  void Set_totalFat(const float totalFat);

  float Get_totalFatDV() const;
  void Set_totalFatDV(const float totalFatDV);

  float Get_sodium() const;
  void Set_sodium(const float sodium);

  float Get_sodiumDV() const;
  void Set_sodiumDV(const float sodiumDV);

  float Get_potassium() const;
  void Set_potassium(const float potassium);

  float Get_potassiumDV() const;
  void Set_potassiumDV(const float potassiumDV);

  float Get_totalCarbonHydrate() const;
  void Set_totalCarbonHydrate(const float totalCarbonHydrate);

  float Get_totalCarbonHydrateDV() const;
  void Set_totalCarbonHydrateDV(const float totalCarbonHydrateDV);

  float Get_dietaryFiber() const;
  void Set_dietaryFiber(const float dietaryFiber);

  float Get_dietaryFiberDV() const;
  void Set_dietaryFiberDV(const float dietaryFiberDV);

  float Get_sugars() const;
  void Set_sugars(const float sugars);

  float Get_protein() const;
  void Set_protein(const float protein);

  float Get_vitaminA() const;
  void Set_vitaminA(const float vitaminA);

  float Get_vitaminC() const;
  void Set_vitaminC(const float vitaminC);

  float Get_calcium() const;
  void Set_calcium(const float calcium);

  float Get_iron() const;
  void Set_iron(const float iron);

  float Get_saturatedFatDV() const;
  void Set_saturatedFatDV(const float saturatedFatDV);

  float Get_saturatedFat() const;
  void Set_saturatedFat(const float saturatedFat);

  float Get_cholesterolDV() const;
  void Set_cholesterolDV(const float cholesterolDV);

  float Get_cholesterol() const;
  void Set_cholesterol(const float cholesterol);

  std::string ShowNutrionalValues();

private:
  std::string m_foodAndServing;
  float m_calories;
  float m_caloriesFromFat;
  float m_totalFat;
  float m_totalFatDV;
  float m_sodium;
  float m_sodiumDV;
  float m_potassium;
  float m_potassiumDV;
  float m_totalCarbonHydrate;
  float m_totalCarbonHydrateDV;
  float m_dietaryFiber;
  float m_dietaryFiberDV;
  float m_sugars;
  float m_protein;
  float m_vitaminA;
  float m_vitaminC;
  float m_calcium;
  float m_iron;
  float m_saturatedFatDV;
  float m_saturatedFat;
  float m_cholesterolDV;
  float m_cholesterol;
};

#endif