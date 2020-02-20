#ifndef LEXER_H
#define LEXER_H

#include <QString>

enum ETokenType
{
    END, NUMBER, LEFT_PAREN = '(', RIGHT_PAREN = ')',
    PLUS = '+', MINUS = '-', MUL = '*', DIV = '/'
};

class CLexer
{
public:
    double getNumber() const;
    ETokenType getNextToken();
    ETokenType getCurrentToken() const;

    void setExpression(QString const& sExpression);

private:
    double     m_dNumber;
    QString    m_sExpression;
    ETokenType m_eCurrentToken;
};

#endif // LEXER_H
