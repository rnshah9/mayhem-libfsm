/* $Id$ */

#ifndef RE_FORM_SIMPLE_LEXER_H
#define RE_FORM_SIMPLE_LEXER_H

struct lex_state;

enum lex_tok {
	TOK_SOL,
	TOK_EOL,
	TOK_QMARK,
	TOK_STAR,
	TOK_PLUS,
	TOK_DOT,
	TOK_ALT,
	TOK_SEP,
	TOK_OPEN__SUB,   TOK_CLOSE__SUB,
	TOK_OPEN__GROUP, TOK_CLOSE__GROUP,
	TOK_COUNT,
	TOK_CHAR,
	TOK_EOF,
	TOK_ERROR
};

struct lex_state *
lex_init(const char *s);

void
lex_free(struct lex_state *state);

enum lex_tok
lex_nexttoken(struct lex_state *state);

char
lex_tokval(struct lex_state *state);

#endif

