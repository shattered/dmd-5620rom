/* */
/*									*/
/*	Copyright (c) 1985,1986,1987,1988,1989,1990,1991,1992   AT&T	*/
/*			All Rights Reserved				*/
/*									*/
/*	  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T.		*/
/*	    The copyright notice above does not evidence any		*/
/*	   actual or intended publication of such source code.		*/
/*									*/
/* */
#include <dmd.h>

/*
 * Commonly used cursors and textures
 */
#undef T_background
Texture T_background = {
#define T_background ST_background
         0x11111111, 0x44444444, 0x11111111, 0x44444444,
         0x11111111, 0x44444444, 0x11111111, 0x44444444,
         0x11111111, 0x44444444, 0x11111111, 0x44444444,
         0x11111111, 0x44444444, 0x11111111, 0x44444444,
         0x11111111, 0x44444444, 0x11111111, 0x44444444,
         0x11111111, 0x44444444, 0x11111111, 0x44444444,
         0x11111111, 0x44444444, 0x11111111, 0x44444444,
         0x11111111, 0x44444444, 0x11111111, 0x44444444,
};
#undef MCur_clock
Texture16 MCur_clock = {
#define MCur_clock SC_clock
	 0x03C0, 0x3420, 0x37E0, 0x13C0,
	 0x17F0, 0x1868, 0x2074, 0x20D4,
	 0x418A, 0x430A, 0x430A, 0x418A,
	 0x2094, 0x201C, 0x787E, 0x67F6,
};

#undef MCur_skull
Texture16 MCur_skull = {
#define MCur_skull SC_skull
	0x0000, 0x0000, 0x0000, 0xC003,
	0xE7E7, 0x3FFC, 0x0FF0, 0x0DB0,
	0x07E0, 0x0660, 0x37EC, 0xE427,
	0xC3C3, 0x0000, 0x0000, 0x0000,
};

#undef MCur_sweep
Texture16 MCur_sweep = {
#define MCur_sweep SC_sweep
	0x43FF, 0xE001, 0x7001, 0x3801,
	0x1D01, 0x0F01, 0x8701, 0x8F01,
	0x8001, 0x8001, 0x8001, 0x8001,
	0x8001, 0x8001, 0x8001, 0xFFFF,
};

#undef MCur_target1
Texture16 MCur_target1 = {
#define MCur_target1 SC_target
	 0x07E0, 0x1FF8, 0x399C, 0x63C6,
	 0x6FF6, 0xCDB3, 0xD99B, 0xFFFF,
	 0xFFFF, 0xD99B, 0xCDB3, 0x6FF6,
	 0x63C6, 0x399C, 0x1FF8, 0x07E0,
};


#undef MCur_cup
Texture16 MCur_cup = {
#define MCur_cup SC_cup
	 0x0100, 0x00E0, 0x0010, 0x03E0,
	 0x0400, 0x0FE0, 0x123C, 0x1FE2,
	 0x101A, 0x101A, 0x1002, 0x103C,
	 0x1810, 0x6FEC, 0x4004, 0x3FF8,
};

#undef MCur_deadmouse
Texture16 MCur_deadmouse = {
#define MCur_deadmouse SC_deadmouse
	0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0008, 0x0084, 0x0442,
	0x0441, 0xFFE1, 0x4FF1, 0x3FFE,
	0x17F0, 0x03E0, 0x0000, 0x0000,
};

/* Textures */

#undef C_crosshair
Texture16 C_crosshair = {
#define C_crosshair SC_crosshair
	 0x0100, 0x0100, 0x0100, 0x0100,
	 0x0100, 0x0100, 0x0000, 0xFC7E,
	 0x0000, 0x0100, 0x0100, 0x0100,
	 0x0100, 0x0100, 0x0100, 0x0000,
};
#undef C_arrows
Texture16 C_arrows = {
#define C_arrows SC_arrows
	 0xFC3F, 0xFC3F, 0xE00F, 0xD81B,
	 0xCC33, 0xC663, 0x02C0, 0x0380,
	 0x0380, 0xC640, 0xCC63, 0xD833,
	 0xF01B, 0xE007, 0xFC3F, 0xFC3F,
};
#undef C_confirm
Texture16 C_confirm = {
#define C_confirm SC_confirm
	0x000E, 0x061B, 0x0241, 0x72C3,
	0xDB86, 0x8B0C, 0x8BC0, 0xDA6C,
	0x766C, 0x0000, 0x0001, 0x0003,
	0x94A6, 0x632C, 0x6318, 0x9490,
};

#undef T_grey 
Texture T_grey = {
#define T_grey ST_grey
	 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x55555555,
	 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x55555555,
	 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x55555555,
	 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x55555555,
	 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x55555555,
	 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x55555555,
	 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x55555555,
	 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x55555555,
};

#undef   T_lightgrey 
Texture  T_lightgrey = {
#define T_lightgrey ST_lightgrey
	 0x22222222, 0x88888888, 0x22222222, 0x88888888,
	 0x22222222, 0x88888888, 0x22222222, 0x88888888,
	 0x22222222, 0x88888888, 0x22222222, 0x88888888,
	 0x22222222, 0x88888888, 0x22222222, 0x88888888,
	 0x22222222, 0x88888888, 0x22222222, 0x88888888,
	 0x22222222, 0x88888888, 0x22222222, 0x88888888,
	 0x22222222, 0x88888888, 0x22222222, 0x88888888,
	 0x22222222, 0x88888888, 0x22222222, 0x88888888,
};

#undef   T_darkgrey 
Texture  T_darkgrey = {
#define T_darkgrey ST_darkgrey
	 0xDDDDDDDD, 0x77777777, 0xDDDDDDDD, 0x77777777,
	 0xDDDDDDDD, 0x77777777, 0xDDDDDDDD, 0x77777777,
	 0xDDDDDDDD, 0x77777777, 0xDDDDDDDD, 0x77777777,
	 0xDDDDDDDD, 0x77777777, 0xDDDDDDDD, 0x77777777,
	 0xDDDDDDDD, 0x77777777, 0xDDDDDDDD, 0x77777777,
	 0xDDDDDDDD, 0x77777777, 0xDDDDDDDD, 0x77777777,
	 0xDDDDDDDD, 0x77777777, 0xDDDDDDDD, 0x77777777,
	 0xDDDDDDDD, 0x77777777, 0xDDDDDDDD, 0x77777777,
};

#undef   T_checks 
Texture  T_checks = {
#define T_checks ST_checks  
	 0xCCCCCCCC, 0xCCCCCCCC, 0x33333333, 0x33333333,
	 0xCCCCCCCC, 0xCCCCCCCC, 0x33333333, 0x33333333,
	 0xCCCCCCCC, 0xCCCCCCCC, 0x33333333, 0x33333333,
	 0xCCCCCCCC, 0xCCCCCCCC, 0x33333333, 0x33333333,
	 0xCCCCCCCC, 0xCCCCCCCC, 0x33333333, 0x33333333,
	 0xCCCCCCCC, 0xCCCCCCCC, 0x33333333, 0x33333333,
	 0xCCCCCCCC, 0xCCCCCCCC, 0x33333333, 0x33333333,
	 0xCCCCCCCC, 0xCCCCCCCC, 0x33333333, 0x33333333,
};

#undef   T_white 
Texture  T_white = {
#define T_white ST_white   
	 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

#undef   T_black 
Texture  T_black = {
#define T_black ST_black   
	 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
};
