#include "NutritionGraph.h"

NutritionGraph::NutritionGraph()
{
    initializeFoods();        //생성자
}

void NutritionGraph::addFoodNutrient(        //음식과 영양소 노드 연결
        const QString& food,
        const QString& nutrient,
        double amount)
{
    graph[food].push_back(
        Edge(nutrient, amount));
}

double NutritionGraph::getNutrient(        //그래프 순회
        const QString& food,
        const QString& nutrient)
{
    if(!graph.contains(food))
        return 0;

    for(const Edge& edge : graph[food])
    {
        if(edge.nutrient == nutrient)
            return edge.amount;
    }

    return 0;
}

QStringList NutritionGraph::getFoodList() const
{
    return graph.keys();
}

void NutritionGraph::initializeFoods()        //음식 등록
{
    // Western
    addFoodNutrient("Spaghetti","Carbohydrate",75);
    addFoodNutrient("Spaghetti","Protein",12);
    addFoodNutrient("Spaghetti","Fat",10);

    addFoodNutrient("Pizza","Carbohydrate",80);
    addFoodNutrient("Pizza","Protein",20);
    addFoodNutrient("Pizza","Fat",18);

    addFoodNutrient("Steak","Carbohydrate",0);
    addFoodNutrient("Steak","Protein",35);
    addFoodNutrient("Steak","Fat",20);

    addFoodNutrient("Hamburger","Carbohydrate",40);
    addFoodNutrient("Hamburger","Protein",25);
    addFoodNutrient("Hamburger","Fat",15);

    addFoodNutrient("Salad","Carbohydrate",10);
    addFoodNutrient("Salad","Protein",3);
    addFoodNutrient("Salad","Fat",2);

    // Korean
    addFoodNutrient("Bibimbap","Carbohydrate",70);
    addFoodNutrient("Bibimbap","Protein",15);
    addFoodNutrient("Bibimbap","Fat",10);

    addFoodNutrient("Bulgogi","Carbohydrate",15);
    addFoodNutrient("Bulgogi","Protein",30);
    addFoodNutrient("Bulgogi","Fat",12);

    addFoodNutrient("KimchiStew","Carbohydrate",12);
    addFoodNutrient("KimchiStew","Protein",20);
    addFoodNutrient("KimchiStew","Fat",8);

    addFoodNutrient("Samgyeopsal","Carbohydrate",0);
    addFoodNutrient("Samgyeopsal","Protein",25);
    addFoodNutrient("Samgyeopsal","Fat",35);

    addFoodNutrient("Japchae","Carbohydrate",45);
    addFoodNutrient("Japchae","Protein",10);
    addFoodNutrient("Japchae","Fat",8);

    // Japanese
    addFoodNutrient("Sushi","Carbohydrate",55);
    addFoodNutrient("Sushi","Protein",18);
    addFoodNutrient("Sushi","Fat",5);

    addFoodNutrient("Ramen","Carbohydrate",70);
    addFoodNutrient("Ramen","Protein",15);
    addFoodNutrient("Ramen","Fat",12);

    addFoodNutrient("Udon","Carbohydrate",65);
    addFoodNutrient("Udon","Protein",10);
    addFoodNutrient("Udon","Fat",5);

    addFoodNutrient("Tempura","Carbohydrate",25);
    addFoodNutrient("Tempura","Protein",15);
    addFoodNutrient("Tempura","Fat",20);

    addFoodNutrient("Donburi","Carbohydrate",75);
    addFoodNutrient("Donburi","Protein",20);
    addFoodNutrient("Donburi","Fat",10);
}
