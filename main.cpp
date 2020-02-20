#include <QApplication>

#include "calculatorwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CCalculatorWidget oCalcWidget;
    oCalcWidget.show();

    return a.exec();
}
