//gui 담당

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>

#include "NutritionGraph.h"

class MainWindow : public QMainWindow        //창 생성
{
    Q_OBJECT

private:

    NutritionGraph graph;

    QSpinBox* heightBox;        //신체 정보
    QSpinBox* weightBox;

    QComboBox* breakfastBox;        /식사 선택
    QComboBox* lunchBox;
    QComboBox* dinnerBox;

    QLabel* resultLabel;        //결과

    QPushButton* calculateButton;

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void calculateNutrition();
};

#endif
