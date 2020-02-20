#include "calculatorwidget.h"

#include <QBoxLayout>

CCalculatorWidget::CCalculatorWidget(QWidget *pParent) : QWidget(pParent)
{
    setupUi();
}

CCalculatorWidget::~CCalculatorWidget()
{
    delete m_pLexer;
    delete m_pParser;
}

void CCalculatorWidget::setExpression(const QString &sExpression)
{
    m_pLexer->setExpression(sExpression);
}

double CCalculatorWidget::calculate()
{
    return m_pParser->calculate();
}

void CCalculatorWidget::setupUi()
{
    m_pLexer = new CLexer();
    m_pParser = new CParser(m_pLexer);

    QVBoxLayout* pVMainLayout = new QVBoxLayout();
    pVMainLayout->setSpacing(0);
    setLayout(pVMainLayout);

    m_ptxtDisplay = new QLineEdit();
    m_ptxtDisplay->setMinimumSize(300, 70);
    m_ptxtDisplay->setDisabled(true);
    m_ptxtDisplay->setText("0");
    pVMainLayout->addWidget(m_ptxtDisplay);

    QHBoxLayout* pHLayout = new QHBoxLayout();
    pVMainLayout->addLayout(pHLayout);

    m_ptxtExpression = new QLineEdit();
    m_ptxtExpression->setMinimumSize(250, 60);
    m_ptxtExpression->setPlaceholderText("Set Expression");
    pHLayout->addWidget(m_ptxtExpression);

    m_pbtnOk = new QPushButton("OK");
    m_pbtnOk->setMinimumSize(70, 70);
    pHLayout->addWidget(m_pbtnOk);

    connect(m_pbtnOk, &QPushButton::clicked, this, &CCalculatorWidget::onBtnClicked);

    setStyleSheet("color: black; font-size: 30px; padding: 5px");
}

void CCalculatorWidget::onBtnClicked()
{
    setExpression(m_ptxtExpression->text());
    m_ptxtDisplay->setText(QString::number(calculate()));
}
