/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_Khudawadi_fsm(struct fsm *fsm, fsm_state_t x, fsm_state_t y)
{
	fsm_state_t s[6];
	size_t i;

	for (i = 0; i < 6; i++) {
		if (i == 0) {
			s[0] = x;
			continue;
		}

		if (i == 5) {
			s[5] = y;
			continue;
		}

		if (!fsm_addstate(fsm, &s[i])) {
			return 0;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xf0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[2], 0x91)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[3], 0x8a)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[4], 0x8b)) { return 0; }
	for (i = 0xb0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[5], i)) { return 0; }
	}
	for (i = 0x80; i <= 0xaa; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[5], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xb9; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[5], i)) { return 0; }
	}

	return 1;
}

