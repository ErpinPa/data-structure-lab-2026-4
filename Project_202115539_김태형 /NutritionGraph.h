#ifndef NUTRITIONGRAPH_H
#define NUTRITIONGRAPH_H

#include <QString>
#include <QMap>
#include <QVector>

//nutrient : 연결된 영양소 이름
//amount   : 해당 영양소 함량(g)

struct Edge
{
    QString nutrient;
    double amount;

    Edge(QString n = "", double a = 0)
        : nutrient(n), amount(a) {}
};

//음식(Food)과 영양소(Nutrient)를이분 그래프(Bipartite Graph) 형태로 저장한다.
// 캡슐화를 위해 그래프 데이터는 private으로 관리한다.
class NutritionGraph
{
private:

    // 음식 → 영양소 연결 정보 저장
    QMap<QString, QVector<Edge>> graph;

public:

    NutritionGraph();

    // 음식과 영양소를 간선으로 연결
    void addFoodNutrient(
        const QString& food,
        const QString& nutrient,
        double amount);

    // 특정 음식의 영양소 함량 조회
    double getNutrient(
        const QString& food,
        const QString& nutrient);

    // 전체 음식 목록 반환
    QStringList getFoodList() const;

    // 초기 음식 데이터 등록
    void initializeFoods();
};

#endif
