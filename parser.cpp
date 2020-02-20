#include "parser.h"

#include <QDebug>

CParser::CParser(CLexer *pLexer) : m_pLexer(pLexer) {}

double CParser::parsePrimaryExpression()
{
    m_pLexer->getNextToken();

    switch(m_pLexer->getCurrentToken())
    {
        case ETokenType::NUMBER:
        {
            double dNumber = m_pLexer->getNumber();
            m_pLexer->getNextToken();
            return dNumber;
        }

        case ETokenType::MINUS:
            return -parsePrimaryExpression();

        case ETokenType::LEFT_PAREN:
        {
            double dResult = parseAddSub();
            if (m_pLexer->getCurrentToken() != ETokenType::RIGHT_PAREN)
            {
                qDebug() << "Error: missing brackets.";
                exit(-1);
            }
            m_pLexer->getNextToken();
            return dResult;
        }

        default:
            qDebug() << "Error: exprected primary expression.";
            exit(-1);
    }
}

double CParser::parseMulDiv()
{
    double dResult = parsePrimaryExpression();

    while (true)
    {
        switch (m_pLexer->getCurrentToken())
        {
            case ETokenType::MUL:
                dResult *= parsePrimaryExpression();
                break;

            case ETokenType::DIV:
            {
                double dTemp = parsePrimaryExpression();
                if (dTemp != 0.0)
                {
                    dResult /= dTemp;
                    break;
                }
                else
                {
                    qDebug() << "Error: division by zero.";
                    exit(-1);
                }
            }

            default:
                return dResult;
        }
    }
}

double CParser::parseAddSub()
{
    double dResult = parseMulDiv();

    while (true)
    {
        switch (m_pLexer->getCurrentToken())
        {
            case ETokenType::PLUS:
                dResult += parseMulDiv();
                break;

            case ETokenType::MINUS:
                dResult -= parseMulDiv();
                break;

            default:
                return dResult;
        }
    }
}

double CParser::calculate()
{
    return parseAddSub();
}
