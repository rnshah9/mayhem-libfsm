/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_Pe_fsm(struct fsm *fsm, fsm_state_t x, fsm_state_t y)
{
	fsm_state_t s[23];
	size_t i;

	for (i = 0; i < 23; i++) {
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

	if (!fsm_addedge_literal(fsm, s[0], s[1], ')')) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], ']')) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '}')) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xe0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[3], 0xe1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[4], 0xe2)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[5], 0xe3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[6], 0xef)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[12], 0xbc)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[3], s[22], 0x9a)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[14], 0x81)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[15], 0x82)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[16], 0x8c)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[17], 0x9d)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[18], 0x9f)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[19], 0xa6)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[20], 0xa7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[21], 0xb8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[5], s[13], 0x80)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[6], s[7], 0xb4)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[6], s[8], 0xb8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[6], s[9], 0xb9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[6], s[10], 0xbc)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[6], s[11], 0xbd)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[7], s[1], 0xbe)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[8], s[1], 0x98)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[8], s[1], 0xb6)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[8], s[1], 0xb8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[8], s[1], 0xba)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[8], s[1], 0xbc)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[8], s[1], 0xbe)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[9], s[1], 0x80)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[9], s[1], 0x82)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[9], s[1], 0x84)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[9], s[1], 0x88)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[9], s[1], 0x9a)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[9], s[1], 0x9c)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[9], s[1], 0x9e)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[10], s[1], 0x89)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[10], s[1], 0xbd)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[11], s[1], 0x9d)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[11], s[1], 0xa0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[11], s[1], 0xa3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[12], s[1], 0xbb)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[12], s[1], 0xbd)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x89)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x8b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x8d)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x8f)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x91)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x95)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x97)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x99)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[1], 0x9b)) { return 0; }
	for (i = 0x9e; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[13], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[14], s[1], 0x86)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[1], 0xbe)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[1], 0x8e)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[16], s[1], 0x89)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[16], s[1], 0x8b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[16], s[1], 0xaa)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[1], 0xa9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[1], 0xab)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[1], 0xad)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[1], 0xaf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[1], 0xb1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[1], 0xb3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[1], 0xb5)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[1], 0x86)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[1], 0xa7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[1], 0xa9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[1], 0xab)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[1], 0xad)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[1], 0xaf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x84)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x86)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x88)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x8a)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x8c)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x8e)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x90)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x92)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x94)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x96)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[1], 0x98)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[20], s[1], 0x99)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[20], s[1], 0x9b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[20], s[1], 0xbd)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[21], s[1], 0xa3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[21], s[1], 0xa5)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[21], s[1], 0xa7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[21], s[1], 0xa9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[22], s[1], 0x9c)) { return 0; }

	return 1;
}

