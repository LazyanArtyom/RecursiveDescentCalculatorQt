#ifndef CALCULATORWIDGET_H
#define CALCULATORWIDGET_H

#include "lexer.h"
#include "parser.h"

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class CCalculatorWidget : public QWidget
{
    Q_OBJECT
public:
    CCalculatorWidget(QWidget* pParent = nullptr);
    ~CCalculatorWidget();

    void setExpression(QString const& sExpression);
    double calculate();

protected:
    void setupUi();

public slots:
    void onBtnClicked();

private:
    CLexer*  m_pLexer = nullptr;
    CParser* m_pParser = nullptr;

    QPushButton* m_pbtnOk = nullptr;
    QLineEdit*   m_ptxtDisplay = nullptr;
    QLineEdit*   m_ptxtExpression = nullptr;
};

#endif // CALCULATORWIDGET_H
