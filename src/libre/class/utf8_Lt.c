/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_Lt_fsm(struct fsm *fsm, fsm_state_t x, fsm_state_t y)
{
	fsm_state_t s[6];
	size_t i;

	for (i = 0; i < 6; i++) {
		if (i == 0) {
			s[0] = x;
			continue;
		}

		if (i == 3) {
			s[3] = y;
			continue;
		}

		if (!fsm_addstate(fsm, &s[i])) {
			return 0;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xc7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xe1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[3], 0x85)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[3], 0x88)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[3], 0x8b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[3], 0xb2)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[4], 0xbe)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[5], 0xbf)) { return 0; }
	for (i = 0x88; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[3], i)) { return 0; }
	}
	for (i = 0x98; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[3], i)) { return 0; }
	}
	for (i = 0xa8; i <= 0xaf; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[3], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[4], s[3], 0xbc)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[5], s[3], 0x8c)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[5], s[3], 0xbc)) { return 0; }

	return 1;
}

