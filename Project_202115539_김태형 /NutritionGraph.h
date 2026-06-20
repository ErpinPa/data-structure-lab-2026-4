#ifndef NUTRITIONGRAPH_H
#define NUTRITIONGRAPH_H

#include <QString>
#include <QMap>
#include <QVector>

struct Edge
{
    QString nutrient;
    double amount;

    Edge(QString n = "", double a = 0)
        : nutrient(n), amount(a) {}
};

class NutritionGraph
{
private:
    QMap<QString, QVector<Edge>> graph;

public:
    NutritionGraph();

    void addFoodNutrient(
        const QString& food,
        const QString& nutrient,
        double amount);

    double getNutrient(
        const QString& food,
        const QString& nutrient);

    QStringList getFoodList() const;

    void initializeFoods();
};

#endif
