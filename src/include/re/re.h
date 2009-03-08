/* $Id$ */

#ifndef RE_H
#define RE_H

struct re;

enum re_form {
/* TODO:
	RE_GLOB,
	RE_ERE,
	RE_BRE,
	RE_PLAN9,
	RE_PCRE,
*/
	RE_SIMPLE
};

enum re_cflags {
	RE_ICASE   = (1 << 0),
	RE_NEWLINE = (1 << 1)
};

enum re_eflags {
	RE_NOTBOL  = (1 << 0),
	RE_NOTEOL  = (1 << 1)
};

enum re_err {
	RE_ESUCCESS,
	RE_ENOMEM,
	RE_EBADFORM,

	/* Syntax errors */
	RE_EXSUB,
	RE_EXTERM,
	RE_EXGROUP,
	RE_EXITEM,
	RE_EXCOUNT,
	RE_EXALTS,
	RE_EXEOF
};

/* TODO: make a new empty regexp */
struct re *
re_new_empty(void);

void
re_free(struct re *re);

/* TODO: compile a string of the given form */
struct re *
re_new_comp(enum re_form form, const char *s, void *opaque,
	enum re_cflags cflags, enum re_err *err);

const char *
re_strerror(enum re_err err);

/* TODO: merge a new re into an existing re. returns opaque of new->re */
/* TODO: opaque is associated with the new re */
void *
re_merge(struct re *re, const struct re *new, void *opaque);

/* TODO: a convenience interface in the spirit of strtol() which parses between delimiters (and escapes accordingly) */

/* TODO: match a string. returns opaque of the re which matches (whichever match is the best match) */
void *
re_exec(const struct re *re, const char *s, enum re_eflags eflags);

#endif

