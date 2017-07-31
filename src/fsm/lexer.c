/* Generated by lx */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include LX_HEADER

static enum lx_token z0(struct lx *lx);
static enum lx_token z1(struct lx *lx);
static enum lx_token z2(struct lx *lx);
static enum lx_token z3(struct lx *lx);

#if __STDC_VERSION__ >= 199901L
inline
#endif
static int
lx_getc(struct lx *lx)
{
	int c;

	assert(lx != NULL);
	assert(lx->lgetc != NULL);

	if (lx->c != EOF) {
		c = lx->c, lx->c = EOF;
	} else {
		c = lx->lgetc(lx);
		if (c == EOF) {
			return EOF;
		}
	}

	lx->end.byte++;
	lx->end.col++;

	if (c == '\n') {
		lx->end.line++;
		lx->end.col = 1;
	}

	return c;
}

#if __STDC_VERSION__ >= 199901L
inline
#endif
static void
lx_ungetc(struct lx *lx, int c)
{
	assert(lx != NULL);
	assert(lx->c == EOF);

	lx->c = c;

	if (lx->pop != NULL) {
		lx->pop(lx);
	}

	lx->end.byte--;
	lx->end.col--;

	if (c == '\n') {
		lx->end.line--;
		lx->end.col = 0; /* XXX: lost information */
	}
}

int
lx_fgetc(struct lx *lx)
{
	assert(lx != NULL);
	assert(lx->opaque != NULL);

	return fgetc(lx->opaque);
}

int
lx_dynpush(struct lx *lx, char c)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	if (t->p == t->a + t->len) {
		size_t len;
		char *tmp;

		if (t->len == 0) {
			assert(LX_DYN_LOW > 0);
			len = LX_DYN_LOW;
		} else {
			len = t->len * LX_DYN_FACTOR;
			if (len < t->len) {
				errno = ERANGE;
				return -1;
			}
		}

		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->p   = tmp + (t->p - t->a);
		t->a   = tmp;
		t->len = len;
	}

	assert(t->p != NULL);
	assert(t->a != NULL);

	*t->p++ = c;

	return 0;
}

void
lx_dynpop(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);
	assert(t->a != NULL);
	assert(t->p >= t->a);

	if (t->p == t->a) {
		return;
	}

	t->p--;
}

int
lx_dynclear(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	if (t->len > LX_DYN_HIGH) {
		size_t len;
		char *tmp;

		len = t->len / LX_DYN_FACTOR;

		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->a   = tmp;
		t->len = len;
	}

	t->p = t->a;

	return 0;
}

void
lx_dynfree(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	free(t->a);
}
static enum lx_token
z0(struct lx *lx)
{
	int c;

	enum {
		NONE, S0, S1, S2
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = NONE;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (state == NONE) {
			state = S0;
		}

		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* start */
			switch ((unsigned char) c) {
			case '\x00':
			case '\x01':
			case '\x02':
			case '\x03':
			case '\x04':
			case '\x05':
			case '\x06':
			case '\a':
			case '\b':
			case '\t':
			case '\n':
			case '\v':
			case '\f':
			case '\r':
			case '\x0e':
			case '\x0f':
			case '\x10':
			case '\x11':
			case '\x12':
			case '\x13':
			case '\x14':
			case '\x15':
			case '\x16':
			case '\x17':
			case '\x18':
			case '\x19':
			case '\x1a':
			case '\x1b':
			case '\x1c':
			case '\x1d':
			case '\x1e':
			case '\x1f':
			case ' ':
			case '!':
			case '"':
			case '#':
			case '$':
			case '%':
			case '&': state = S1; continue;
			case '\'': state = S2; continue;
			case '(':
			case ')':
			case '*':
			case '+':
			case ',':
			case '-':
			case '.':
			case '\x2f':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case ':':
			case ';':
			case '<':
			case '=':
			case '>':
			case '?':
			case '@':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '[':
			case '\\':
			case ']':
			case '^':
			case '_':
			case '`':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case '{':
			case '|':
			case '}':
			case '~':
			case '\x7f':
			case 0x80:
			case 0x81:
			case 0x82:
			case 0x83:
			case 0x84:
			case 0x85:
			case 0x86:
			case 0x87:
			case 0x88:
			case 0x89:
			case 0x8a:
			case 0x8b:
			case 0x8c:
			case 0x8d:
			case 0x8e:
			case 0x8f:
			case 0x90:
			case 0x91:
			case 0x92:
			case 0x93:
			case 0x94:
			case 0x95:
			case 0x96:
			case 0x97:
			case 0x98:
			case 0x99:
			case 0x9a:
			case 0x9b:
			case 0x9c:
			case 0x9d:
			case 0x9e:
			case 0x9f:
			case 0xa0:
			case 0xa1:
			case 0xa2:
			case 0xa3:
			case 0xa4:
			case 0xa5:
			case 0xa6:
			case 0xa7:
			case 0xa8:
			case 0xa9:
			case 0xaa:
			case 0xab:
			case 0xac:
			case 0xad:
			case 0xae:
			case 0xaf:
			case 0xb0:
			case 0xb1:
			case 0xb2:
			case 0xb3:
			case 0xb4:
			case 0xb5:
			case 0xb6:
			case 0xb7:
			case 0xb8:
			case 0xb9:
			case 0xba:
			case 0xbb:
			case 0xbc:
			case 0xbd:
			case 0xbe:
			case 0xbf:
			case 0xc0:
			case 0xc1:
			case 0xc2:
			case 0xc3:
			case 0xc4:
			case 0xc5:
			case 0xc6:
			case 0xc7:
			case 0xc8:
			case 0xc9:
			case 0xca:
			case 0xcb:
			case 0xcc:
			case 0xcd:
			case 0xce:
			case 0xcf:
			case 0xd0:
			case 0xd1:
			case 0xd2:
			case 0xd3:
			case 0xd4:
			case 0xd5:
			case 0xd6:
			case 0xd7:
			case 0xd8:
			case 0xd9:
			case 0xda:
			case 0xdb:
			case 0xdc:
			case 0xdd:
			case 0xde:
			case 0xdf:
			case 0xe0:
			case 0xe1:
			case 0xe2:
			case 0xe3:
			case 0xe4:
			case 0xe5:
			case 0xe6:
			case 0xe7:
			case 0xe8:
			case 0xe9:
			case 0xea:
			case 0xeb:
			case 0xec:
			case 0xed:
			case 0xee:
			case 0xef:
			case 0xf0:
			case 0xf1:
			case 0xf2:
			case 0xf3:
			case 0xf4:
			case 0xf5:
			case 0xf6:
			case 0xf7:
			case 0xf8:
			case 0xf9:
			case 0xfa:
			case 0xfb:
			case 0xfc:
			case 0xfd:
			case 0xfe:
			case 0xff: state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. "\'" */
			lx_ungetc(lx, c); return lx->z = z3, TOK_LABEL;
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case NONE: return TOK_EOF;
	case S1: return TOK_CHAR;
	case S2: return TOK_LABEL;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z1(struct lx *lx)
{
	int c;

	enum {
		NONE, S0, S1, S2, S3, S4, S5, S6, S7
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = NONE;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (state == NONE) {
			state = S0;
		}

		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S0: /* start */
			switch ((unsigned char) c) {
			case '\x00':
			case '\x01':
			case '\x02':
			case '\x03':
			case '\x04':
			case '\x05':
			case '\x06':
			case '\a':
			case '\b':
			case '\t':
			case '\n':
			case '\v':
			case '\f':
			case '\r':
			case '\x0e':
			case '\x0f':
			case '\x10':
			case '\x11':
			case '\x12':
			case '\x13':
			case '\x14':
			case '\x15':
			case '\x16':
			case '\x17':
			case '\x18':
			case '\x19':
			case '\x1a':
			case '\x1b':
			case '\x1c':
			case '\x1d':
			case '\x1e':
			case '\x1f':
			case ' ':
			case '!': state = S1; continue;
			case '"': state = S2; continue;
			case '#':
			case '$':
			case '%':
			case '&':
			case '\'':
			case '(':
			case ')':
			case '*':
			case '+':
			case ',':
			case '-':
			case '.':
			case '\x2f':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case ':':
			case ';':
			case '<':
			case '=':
			case '>':
			case '?':
			case '@':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '[': state = S1; continue;
			case '\\': state = S3; continue;
			case ']':
			case '^':
			case '_':
			case '`':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case '{':
			case '|':
			case '}':
			case '~':
			case '\x7f':
			case 0x80:
			case 0x81:
			case 0x82:
			case 0x83:
			case 0x84:
			case 0x85:
			case 0x86:
			case 0x87:
			case 0x88:
			case 0x89:
			case 0x8a:
			case 0x8b:
			case 0x8c:
			case 0x8d:
			case 0x8e:
			case 0x8f:
			case 0x90:
			case 0x91:
			case 0x92:
			case 0x93:
			case 0x94:
			case 0x95:
			case 0x96:
			case 0x97:
			case 0x98:
			case 0x99:
			case 0x9a:
			case 0x9b:
			case 0x9c:
			case 0x9d:
			case 0x9e:
			case 0x9f:
			case 0xa0:
			case 0xa1:
			case 0xa2:
			case 0xa3:
			case 0xa4:
			case 0xa5:
			case 0xa6:
			case 0xa7:
			case 0xa8:
			case 0xa9:
			case 0xaa:
			case 0xab:
			case 0xac:
			case 0xad:
			case 0xae:
			case 0xaf:
			case 0xb0:
			case 0xb1:
			case 0xb2:
			case 0xb3:
			case 0xb4:
			case 0xb5:
			case 0xb6:
			case 0xb7:
			case 0xb8:
			case 0xb9:
			case 0xba:
			case 0xbb:
			case 0xbc:
			case 0xbd:
			case 0xbe:
			case 0xbf:
			case 0xc0:
			case 0xc1:
			case 0xc2:
			case 0xc3:
			case 0xc4:
			case 0xc5:
			case 0xc6:
			case 0xc7:
			case 0xc8:
			case 0xc9:
			case 0xca:
			case 0xcb:
			case 0xcc:
			case 0xcd:
			case 0xce:
			case 0xcf:
			case 0xd0:
			case 0xd1:
			case 0xd2:
			case 0xd3:
			case 0xd4:
			case 0xd5:
			case 0xd6:
			case 0xd7:
			case 0xd8:
			case 0xd9:
			case 0xda:
			case 0xdb:
			case 0xdc:
			case 0xdd:
			case 0xde:
			case 0xdf:
			case 0xe0:
			case 0xe1:
			case 0xe2:
			case 0xe3:
			case 0xe4:
			case 0xe5:
			case 0xe6:
			case 0xe7:
			case 0xe8:
			case 0xe9:
			case 0xea:
			case 0xeb:
			case 0xec:
			case 0xed:
			case 0xee:
			case 0xef:
			case 0xf0:
			case 0xf1:
			case 0xf2:
			case 0xf3:
			case 0xf4:
			case 0xf5:
			case 0xf6:
			case 0xf7:
			case 0xf8:
			case 0xf9:
			case 0xfa:
			case 0xfb:
			case 0xfc:
			case 0xfd:
			case 0xfe:
			case 0xff: state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_ungetc(lx, c); return TOK_CHAR;

		case S2: /* e.g. """ */
			lx_ungetc(lx, c); return lx->z = z3, TOK_LABEL;

		case S3: /* e.g. "\\" */
			switch ((unsigned char) c) {
			case '"': state = S4; continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': state = S5; continue;
			case '\\': state = S4; continue;
			case 'f': state = S4; continue;
			case 'n': state = S4; continue;
			case 'r': state = S4; continue;
			case 't': state = S4; continue;
			case 'v': state = S4; continue;
			case 'x': state = S6; continue;
			default:  lx_ungetc(lx, c); return TOK_CHAR;
			}

		case S4: /* e.g. "\\f" */
			lx_ungetc(lx, c); return TOK_ESC;

		case S5: /* e.g. "\\0" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7': continue;
			default:  lx_ungetc(lx, c); return TOK_OCT;
			}

		case S6: /* e.g. "\\x" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': state = S7; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S7: /* e.g. "\\xa" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F': continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f': continue;
			default:  lx_ungetc(lx, c); return TOK_HEX;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case NONE: return TOK_EOF;
	case S1: return TOK_CHAR;
	case S2: return TOK_LABEL;
	case S3: return TOK_CHAR;
	case S4: return TOK_ESC;
	case S5: return TOK_OCT;
	case S7: return TOK_HEX;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z2(struct lx *lx)
{
	int c;

	enum {
		NONE, S0, S1, S2
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = NONE;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (state == NONE) {
			state = S0;
		}

		switch (state) {
		case S0:
		case S1:
		case S2:
			break;

		default:
			if (lx->push != NULL) {
				if (-1 == lx->push(lx, c)) {
					return TOK_ERROR;
				}
			}
			break;

		}

		switch (state) {
		case S0: /* start */
			switch ((unsigned char) c) {
			case '\x00':
			case '\x01':
			case '\x02':
			case '\x03':
			case '\x04':
			case '\x05':
			case '\x06':
			case '\a':
			case '\b':
			case '\t': state = S1; continue;
			case '\n': state = S2; continue;
			case '\v':
			case '\f':
			case '\r':
			case '\x0e':
			case '\x0f':
			case '\x10':
			case '\x11':
			case '\x12':
			case '\x13':
			case '\x14':
			case '\x15':
			case '\x16':
			case '\x17':
			case '\x18':
			case '\x19':
			case '\x1a':
			case '\x1b':
			case '\x1c':
			case '\x1d':
			case '\x1e':
			case '\x1f':
			case ' ':
			case '!':
			case '"':
			case '#':
			case '$':
			case '%':
			case '&':
			case '\'':
			case '(':
			case ')':
			case '*':
			case '+':
			case ',':
			case '-':
			case '.':
			case '\x2f':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case ':':
			case ';':
			case '<':
			case '=':
			case '>':
			case '?':
			case '@':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '[':
			case '\\':
			case ']':
			case '^':
			case '_':
			case '`':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case '{':
			case '|':
			case '}':
			case '~':
			case '\x7f':
			case 0x80:
			case 0x81:
			case 0x82:
			case 0x83:
			case 0x84:
			case 0x85:
			case 0x86:
			case 0x87:
			case 0x88:
			case 0x89:
			case 0x8a:
			case 0x8b:
			case 0x8c:
			case 0x8d:
			case 0x8e:
			case 0x8f:
			case 0x90:
			case 0x91:
			case 0x92:
			case 0x93:
			case 0x94:
			case 0x95:
			case 0x96:
			case 0x97:
			case 0x98:
			case 0x99:
			case 0x9a:
			case 0x9b:
			case 0x9c:
			case 0x9d:
			case 0x9e:
			case 0x9f:
			case 0xa0:
			case 0xa1:
			case 0xa2:
			case 0xa3:
			case 0xa4:
			case 0xa5:
			case 0xa6:
			case 0xa7:
			case 0xa8:
			case 0xa9:
			case 0xaa:
			case 0xab:
			case 0xac:
			case 0xad:
			case 0xae:
			case 0xaf:
			case 0xb0:
			case 0xb1:
			case 0xb2:
			case 0xb3:
			case 0xb4:
			case 0xb5:
			case 0xb6:
			case 0xb7:
			case 0xb8:
			case 0xb9:
			case 0xba:
			case 0xbb:
			case 0xbc:
			case 0xbd:
			case 0xbe:
			case 0xbf:
			case 0xc0:
			case 0xc1:
			case 0xc2:
			case 0xc3:
			case 0xc4:
			case 0xc5:
			case 0xc6:
			case 0xc7:
			case 0xc8:
			case 0xc9:
			case 0xca:
			case 0xcb:
			case 0xcc:
			case 0xcd:
			case 0xce:
			case 0xcf:
			case 0xd0:
			case 0xd1:
			case 0xd2:
			case 0xd3:
			case 0xd4:
			case 0xd5:
			case 0xd6:
			case 0xd7:
			case 0xd8:
			case 0xd9:
			case 0xda:
			case 0xdb:
			case 0xdc:
			case 0xdd:
			case 0xde:
			case 0xdf:
			case 0xe0:
			case 0xe1:
			case 0xe2:
			case 0xe3:
			case 0xe4:
			case 0xe5:
			case 0xe6:
			case 0xe7:
			case 0xe8:
			case 0xe9:
			case 0xea:
			case 0xeb:
			case 0xec:
			case 0xed:
			case 0xee:
			case 0xef:
			case 0xf0:
			case 0xf1:
			case 0xf2:
			case 0xf3:
			case 0xf4:
			case 0xf5:
			case 0xf6:
			case 0xf7:
			case 0xf8:
			case 0xf9:
			case 0xfa:
			case 0xfb:
			case 0xfc:
			case 0xfd:
			case 0xfe:
			case 0xff: state = S1; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "a" */
			lx_ungetc(lx, c); return lx->z(lx);

		case S2: /* e.g. "\n" */
			lx_ungetc(lx, c); return lx->z = z3, lx->z(lx);
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case NONE: return TOK_EOF;
	case S1: return TOK_EOF;
	case S2: return TOK_EOF;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z3(struct lx *lx)
{
	int c;

	enum {
		NONE, S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, 
		S10, S11, S12, S13, S14, S15, S16, S17, S18, S19, 
		S20
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = NONE;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (state == NONE) {
			state = S0;
		}

		switch (state) {
		case S1:
		case S2:
		case S3:
		case S4:
			break;

		default:
			if (lx->push != NULL) {
				if (-1 == lx->push(lx, c)) {
					return TOK_ERROR;
				}
			}
			break;

		}

		switch (state) {
		case S0: /* start */
			switch ((unsigned char) c) {
			case '\t':
			case '\n': state = S1; continue;
			case '\r': state = S1; continue;
			case ' ': state = S1; continue;
			case '"': state = S2; continue;
			case '#': state = S3; continue;
			case '\'': state = S4; continue;
			case ',': state = S5; continue;
			case '-': state = S6; continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case ';': state = S8; continue;
			case '?': state = S9; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd': state = S7; continue;
			case 'e': state = S10; continue;
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r': state = S7; continue;
			case 's': state = S11; continue;
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S1: /* e.g. "\t" */
			switch ((unsigned char) c) {
			case '\t':
			case '\n': continue;
			case '\r': continue;
			case ' ': continue;
			default:  lx_ungetc(lx, c); return lx->z(lx);
			}

		case S2: /* e.g. """ */
			lx_ungetc(lx, c); return lx->z = z1, lx->z(lx);

		case S3: /* e.g. "#" */
			lx_ungetc(lx, c); return lx->z = z2, lx->z(lx);

		case S4: /* e.g. "\'" */
			lx_ungetc(lx, c); return lx->z = z0, lx->z(lx);

		case S5: /* e.g. "," */
			lx_ungetc(lx, c); return TOK_COMMA;

		case S6: /* e.g. "-" */
			switch ((unsigned char) c) {
			case '>': state = S12; continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S7: /* e.g. "a" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': continue;
			case '_': continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S8: /* e.g. ";" */
			lx_ungetc(lx, c); return TOK_SEP;

		case S9: /* e.g. "?" */
			lx_ungetc(lx, c); return TOK_ANY;

		case S10: /* e.g. "e" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm': state = S7; continue;
			case 'n': state = S13; continue;
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S11: /* e.g. "s" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's': state = S7; continue;
			case 't': state = S16; continue;
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S12: /* e.g. "->" */
			lx_ungetc(lx, c); return TOK_TO;

		case S13: /* e.g. "en" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a':
			case 'b':
			case 'c': state = S7; continue;
			case 'd': state = S14; continue;
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S14: /* e.g. "end" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case ':': state = S15; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S15: /* e.g. "end:" */
			lx_ungetc(lx, c); return TOK_END;

		case S16: /* e.g. "st" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a': state = S17; continue;
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S17: /* e.g. "sta" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q': state = S7; continue;
			case 'r': state = S18; continue;
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S18: /* e.g. "star" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's': state = S7; continue;
			case 't': state = S19; continue;
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S19: /* e.g. "start" */
			switch ((unsigned char) c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': state = S7; continue;
			case ':': state = S20; continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z': state = S7; continue;
			case '_': state = S7; continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z': state = S7; continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S20: /* e.g. "start:" */
			lx_ungetc(lx, c); return TOK_START;
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case NONE: return TOK_EOF;
	case S1: return TOK_EOF;
	case S2: return TOK_EOF;
	case S3: return TOK_EOF;
	case S4: return TOK_EOF;
	case S5: return TOK_COMMA;
	case S7: return TOK_IDENT;
	case S8: return TOK_SEP;
	case S9: return TOK_ANY;
	case S10: return TOK_IDENT;
	case S11: return TOK_IDENT;
	case S12: return TOK_TO;
	case S13: return TOK_IDENT;
	case S14: return TOK_IDENT;
	case S15: return TOK_END;
	case S16: return TOK_IDENT;
	case S17: return TOK_IDENT;
	case S18: return TOK_IDENT;
	case S19: return TOK_IDENT;
	case S20: return TOK_START;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

const char *
lx_name(enum lx_token t)
{
	switch (t) {
	case TOK_COMMA: return "COMMA";
	case TOK_SEP: return "SEP";
	case TOK_ANY: return "ANY";
	case TOK_TO: return "TO";
	case TOK_IDENT: return "IDENT";
	case TOK_END: return "END";
	case TOK_START: return "START";
	case TOK_CHAR: return "CHAR";
	case TOK_HEX: return "HEX";
	case TOK_OCT: return "OCT";
	case TOK_ESC: return "ESC";
	case TOK_LABEL: return "LABEL";
	case TOK_EOF:     return "EOF";
	case TOK_ERROR:   return "ERROR";
	case TOK_UNKNOWN: return "UNKNOWN";
	default: return "?";
	}
}

const char *
lx_example(enum lx_token (*z)(struct lx *), enum lx_token t)
{
	assert(z != NULL);

	if (z == z0) {
		switch (t) {
		case TOK_CHAR: return "a";
		case TOK_LABEL: return "\'";
		default: goto error;
		}
	} else
	if (z == z1) {
		switch (t) {
		case TOK_CHAR: return "a";
		case TOK_HEX: return "\\xa";
		case TOK_OCT: return "\\0";
		case TOK_ESC: return "\\f";
		case TOK_LABEL: return "\"";
		default: goto error;
		}
	} else
	if (z == z2) {
		switch (t) {
		default: goto error;
		}
	} else
	if (z == z3) {
		switch (t) {
		case TOK_COMMA: return ",";
		case TOK_SEP: return ";";
		case TOK_ANY: return "?";
		case TOK_TO: return "->";
		case TOK_IDENT: return "a";
		case TOK_END: return "end:";
		case TOK_START: return "start:";
		default: goto error;
		}
	}

error:

	errno = EINVAL;
	return NULL;
}

void
lx_init(struct lx *lx)
{
	static const struct lx lx_default;

	assert(lx != NULL);

	*lx = lx_default;

	lx->c = EOF;
	lx->z = z3;

	lx->end.byte = 0;
	lx->end.line = 1;
	lx->end.col  = 1;
}

enum lx_token
lx_next(struct lx *lx)
{
	enum lx_token t;

	assert(lx != NULL);
	assert(lx->z != NULL);

	if (lx->lgetc == NULL) {
		return TOK_EOF;
	}

	t = lx->z(lx);

	if (lx->push != NULL) {
		if (-1 == lx->push(lx, '\0')) {
			return TOK_ERROR;
		}
	}

	return t;
}

