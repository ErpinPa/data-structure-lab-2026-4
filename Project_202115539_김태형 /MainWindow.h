#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>

#include "NutritionGraph.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    NutritionGraph graph;

    QSpinBox* heightBox;
    QSpinBox* weightBox;

    QComboBox* breakfastBox;
    QComboBox* lunchBox;
    QComboBox* dinnerBox;

    QLabel* resultLabel;

    QPushButton* calculateButton;

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void calculateNutrition();
};

#endif
