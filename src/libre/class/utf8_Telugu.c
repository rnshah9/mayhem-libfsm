/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_Telugu_fsm(struct fsm *fsm, fsm_state_t x, fsm_state_t y)
{
	fsm_state_t s[5];
	size_t i;

	for (i = 0; i < 5; i++) {
		if (i == 0) {
			s[0] = x;
			continue;
		}

		if (i == 4) {
			s[4] = y;
			continue;
		}

		if (!fsm_addstate(fsm, &s[i])) {
			return 0;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xe0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[2], 0xb0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[3], 0xb1)) { return 0; }
	for (i = 0x80; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0x85; i <= 0x8c; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0x8e; i <= 0x90; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0x92; i <= 0xa8; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0xaa; i <= 0xb9; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0xbd; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x84; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0x86; i <= 0x88; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0x8a; i <= 0x8d; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0x95; i <= 0x96; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0x98; i <= 0x9a; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0xa0; i <= 0xa3; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0xa6; i <= 0xaf; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0xb8; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}

	return 1;
}

