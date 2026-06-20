#include "MainWindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    setWindowTitle("Daily Nutrition Calculator");
    resize(700,600);

    QVBoxLayout* mainLayout = new QVBoxLayout;

    QGroupBox* bodyGroup =
        new QGroupBox("Body Information");

    QHBoxLayout* bodyLayout =
        new QHBoxLayout;

    heightBox = new QSpinBox;
    heightBox->setRange(100,250);
    heightBox->setValue(175);

    weightBox = new QSpinBox;
    weightBox->setRange(30,200);
    weightBox->setValue(70);

    bodyLayout->addWidget(new QLabel("Height(cm)"));
    bodyLayout->addWidget(heightBox);

    bodyLayout->addWidget(new QLabel("Weight(kg)"));
    bodyLayout->addWidget(weightBox);

    bodyGroup->setLayout(bodyLayout);

    breakfastBox = new QComboBox;
    lunchBox = new QComboBox;
    dinnerBox = new QComboBox;

    QStringList foods = graph.getFoodList();

    breakfastBox->addItems(foods);
    lunchBox->addItems(foods);
    dinnerBox->addItems(foods);

    QGroupBox* mealGroup =
        new QGroupBox("Meals");

    QVBoxLayout* mealLayout =
        new QVBoxLayout;

    mealLayout->addWidget(new QLabel("Breakfast"));
    mealLayout->addWidget(breakfastBox);

    mealLayout->addWidget(new QLabel("Lunch"));
    mealLayout->addWidget(lunchBox);

    mealLayout->addWidget(new QLabel("Dinner"));
    mealLayout->addWidget(dinnerBox);

    mealGroup->setLayout(mealLayout);

    calculateButton =
        new QPushButton("Calculate Nutrition");

    resultLabel = new QLabel;
    resultLabel->setWordWrap(true);

    connect(
        calculateButton,
        &QPushButton::clicked,
        this,
        &MainWindow::calculateNutrition);

    mainLayout->addWidget(bodyGroup);
    mainLayout->addWidget(mealGroup);
    mainLayout->addWidget(calculateButton);
    mainLayout->addWidget(resultLabel);

    centralWidget->setLayout(mainLayout);
}

void MainWindow::calculateNutrition()
{
    QString breakfast =
        breakfastBox->currentText();

    QString lunch =
        lunchBox->currentText();

    QString dinner =
        dinnerBox->currentText();

    double carb = 0;
    double protein = 0;
    double fat = 0;

    QStringList meals =
    {
        breakfast,
        lunch,
        dinner
    };

    for(const QString& meal : meals)
    {
        carb += graph.getNutrient(
            meal,"Carbohydrate");

        protein += graph.getNutrient(
            meal,"Protein");

        fat += graph.getNutrient(
            meal,"Fat");
    }

    double height =
        heightBox->value();

    double standardWeight =
        (height - 100) * 0.9;

    double recCarb =
        standardWeight * 4;

    double recProtein =
        standardWeight * 1.2;

    double recFat =
        standardWeight * 0.8;

    QString result;

    auto compare =
            [&](QString nutrient,
                double intake,
                double recommended)
    {
        double diff =
            intake - recommended;

        if(std::abs(diff) < 0.01)
        {
            result += nutrient +
                    " intake is appropriate!\n";
        }
        else if(diff > 0)
        {
            result += nutrient +
                    " is " +
                    QString::number(diff,'f',1) +
                    "g above recommended!\n";
        }
        else
        {
            result += nutrient +
                    " is " +
                    QString::number(std::abs(diff),'f',1) +
                    "g below recommended!\n";
        }
    };

    result +=
        "Total Intake\n\n";

    result +=
        "Carbohydrate : "
        + QString::number(carb)
        + "g\n";

    result +=
        "Protein : "
        + QString::number(protein)
        + "g\n";

    result +=
        "Fat : "
        + QString::number(fat)
        + "g\n\n";

    compare("Carbohydrate",
            carb,
            recCarb);

    compare("Protein",
            protein,
            recProtein);

    compare("Fat",
            fat,
            recFat);

    resultLabel->setText(result);
}
