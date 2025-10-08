#ifndef _LEXER_H
#define _LEXER_H

enum OP_ASS {
	N_ASSOC,
	L_ASSOC,
	R_ASSOC,
};

enum OP_PREC {
	P_PRN = 0,
	P_ADD = 1,
	P_SUB = 1,
	P_MUL = 2,
	P_DIV = 2,
	P_MOD = 2,
	P_POW = 3
};

enum TOK_TYPE {
	T_VAL,
	T_VAR,
	T_OPEN_PAREN,
	T_CLOSE_PAREN,
	T_ADD,
	T_SUB,
	T_MUL,
	T_DIV,
	T_MOD,
	T_POW,
};

struct operator_t {
	int op;
	enum OP_PREC prec;
	enum OP_ASS ass;
	double (*eval)(double a, double b);
};

struct operator_t op[] = {
	{'^', P_POW,  R_ASSOC, _pow},
	{'*', P_MUL,  L_ASSOC, _mul},
	{'/', P_DIV,  L_ASSOC, _div},
	{'%', P_MOD,  L_ASSOC, _mod},
	{'+', P_ADD,  L_ASSOC, _add},
	{'-', P_SUB,  L_ASSOC, _sub},
	{'(', P_PRN,  N_ASSOC, NULL},
	{')', P_PRN,  N_ASSOC, NULL}
};

struct Token {
	enum TOK_TYPE type;
	double val;
	char var;
	enum OP_PREC prec;
	enum OP_ASS  ass;
	double (*eval)(double a, double b);
};

// Return mallocated array of chars
char *slurp_file(char *, size_t *);

// Lexical Analysis on the in-fix notation to malloced token array
struct Token *lex(char *, size_t);

#endif _LEXER_H
