#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

class CParser
{
public:
    CParser(CLexer* pLexer);

    double parsePrimaryExpression();
    double parseMulDiv();
    double parseAddSub();

    double calculate();

private:
    CLexer* m_pLexer = nullptr;
};

#endif // PARSER_H
