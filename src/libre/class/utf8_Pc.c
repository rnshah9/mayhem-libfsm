/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_Pc_fsm(struct fsm *fsm, fsm_state_t x, fsm_state_t y)
{
	fsm_state_t s[8];
	size_t i;

	for (i = 0; i < 8; i++) {
		if (i == 0) {
			s[0] = x;
			continue;
		}

		if (i == 1) {
			s[1] = y;
			continue;
		}

		if (!fsm_addstate(fsm, &s[i])) {
			return 0;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], '_')) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xe2)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[3], 0xef)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[4], 0x80)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[5], 0x81)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[3], s[4], 0xbc)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[3], s[6], 0xb8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[3], s[7], 0xb9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[1], 0xbf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[5], s[1], 0x80)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[5], s[1], 0x94)) { return 0; }
	for (i = 0xb3; i <= 0xb4; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[1], i)) { return 0; }
	}
	for (i = 0x8d; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[7], s[1], i)) { return 0; }
	}

	return 1;
}

