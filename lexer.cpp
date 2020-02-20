#include "lexer.h"

#include <QDebug>

double CLexer::getNumber() const
{
    return m_dNumber;
}

ETokenType CLexer::getNextToken()
{
    if (m_sExpression.isEmpty())
        return m_eCurrentToken = ETokenType::END;

    QChar ch = m_sExpression.front();
    m_sExpression.remove(0, 1);

    switch (ch.cell())
    {
        case '/': return m_eCurrentToken = ETokenType::DIV;
        case '*': return m_eCurrentToken = ETokenType::MUL;
        case '+': return m_eCurrentToken = ETokenType::PLUS;
        case '-': return m_eCurrentToken = ETokenType::MINUS;
        case '(': return m_eCurrentToken = ETokenType::LEFT_PAREN;
        case ')': return m_eCurrentToken = ETokenType::RIGHT_PAREN;
    }

    QString sNumber = "";
    if (ch.isDigit())
    {
        sNumber += ch;
        while (!m_sExpression.isEmpty()
               && (m_sExpression.front().isDigit()
               || m_sExpression.front() == '.'))
        {
            sNumber += m_sExpression.front();
            m_sExpression.remove(0, 1);
        }

        m_dNumber = sNumber.toDouble();

        return m_eCurrentToken = ETokenType::NUMBER;
    }
    else
    {
        qDebug() << "Error: Invalid Token.";
        exit(-1);
    }
}

ETokenType CLexer::getCurrentToken() const
{
    return m_eCurrentToken;
}

void CLexer::setExpression(const QString &sExpression)
{
    m_sExpression = sExpression.simplified();
    m_sExpression.replace(" ", "");
}
