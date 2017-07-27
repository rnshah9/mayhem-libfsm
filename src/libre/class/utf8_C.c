/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
utf8_C_fsm(const struct fsm_options *opt)
{
	struct fsm *fsm;
	size_t i;

	struct fsm_state *s[31] = { 0 };

	fsm = fsm_new(opt);
	if (fsm == NULL) {
		return NULL;
	}

	for (i = 0; i < 31; i++) {
		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			goto error;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xc2)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xd8)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[3], 0xdb)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[4], 0xdc)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[5], 0xe0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[6], 0xe1)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[7], 0xe2)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[8], 0xee)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[9], 0xef)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[10], 0xf0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[11], 0xf3)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[12], 0xf4)) { goto error; }
	for (i = 0x00; i <= 0x1f; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[13], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[0], s[13], '\177')) { goto error; }
	for (i = 0x80; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[1], s[13], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[1], s[13], 0xad)) { goto error; }
	for (i = 0x80; i <= 0x85; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[13], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[2], s[13], 0x9c)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[3], s[13], 0x9d)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[4], s[13], 0x8f)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[5], s[14], 0xa3)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[6], s[15], 0xa0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[7], s[26], 0x80)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[7], s[27], 0x81)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[8], s[16], 0x80)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[19], 0xa3)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[19], 0xbb)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[9], s[20], 0xbf)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[10], s[21], 0x91)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[10], s[22], 0x9b)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[10], s[23], 0x9d)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[11], s[8], 0xb0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[11], s[17], 0xbf)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[11], s[28], 0xa0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[8], 0x80)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[12], s[17], 0x8f)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[14], s[13], 0xa2)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[15], s[13], 0x8e)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[16], s[13], 0x80)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[17], s[18], 0xbf)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[18], s[13], 0xbd)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[19], s[13], 0xbf)) { goto error; }
	for (i = 0xb9; i <= 0xbb; i++) {
		if (!fsm_addedge_literal(fsm, s[20], s[13], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[21], s[18], 0x82)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[22], s[24], 0xb2)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[23], s[25], 0x85)) { goto error; }
	for (i = 0xa0; i <= 0xa3; i++) {
		if (!fsm_addedge_literal(fsm, s[24], s[13], i)) { goto error; }
	}
	for (i = 0xb3; i <= 0xba; i++) {
		if (!fsm_addedge_literal(fsm, s[25], s[13], i)) { goto error; }
	}
	for (i = 0x8b; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[26], s[13], i)) { goto error; }
	}
	for (i = 0xaa; i <= 0xae; i++) {
		if (!fsm_addedge_literal(fsm, s[26], s[13], i)) { goto error; }
	}
	for (i = 0xa0; i <= 0xa4; i++) {
		if (!fsm_addedge_literal(fsm, s[27], s[13], i)) { goto error; }
	}
	for (i = 0xa6; i <= 0xaf; i++) {
		if (!fsm_addedge_literal(fsm, s[27], s[13], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[28], s[29], 0x80)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[28], s[30], 0x81)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[29], s[13], 0x81)) { goto error; }
	for (i = 0xa0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[29], s[13], i)) { goto error; }
	}
	for (i = 0x80; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[30], s[13], i)) { goto error; }
	}

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[13], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}
