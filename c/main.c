#include <gb/gb.h>
#include <gb/cgb.h>
#include "map.h"
#include "tileset.h"
#include "player.h"
#include "hud_map.h"
#include "hud_tiles.h"

INT8 p[2];
INT8 up;
INT8 down;
INT8 left;
INT8 right;


UWORD palette[] = {
	0, RGB_BLUE, RGB_DARKBLUE, RGB_BLACK,
	//RGB(30, 28, 20), RGB(31, 3, 0), RGB(1, 11, 13), RGB_BLACK
};
UWORD p_palette[] = {
	0, RGB(30, 28, 20), RGB(6, 4, 12), RGB_BLACK
};

void performantdelay(UINT8 numloops){
	UINT8 i;
	for(i = 0; i < numloops; i++)
	{
		wait_vbl_done();
	}
	

}

void main(){
	p[0] = 75;
	p[1] = 75;
	set_bkg_data(0, 37, tiles);

	set_bkg_tiles(0, 0, 20, 18, map);
	set_bkg_palette(0, 3, palette);
	
	SPRITES_8x16;
	set_sprite_data(0, 32, player);
	set_sprite_tile(0, 0);
	set_sprite_tile(1, 2);
	set_sprite_palette(0, 3, p_palette);

	move_sprite(0, p[0], p[1]);
	move_sprite(1, p[0] + 8, p[1]);	

	set_win_data(37, 9, hud_tiles);
	set_win_tiles(0, 0, 20, 18, hud_map);
	move_win(8, 128);
	
	SHOW_SPRITES;
	SHOW_BKG;
	SHOW_WIN;
	
	while(1){
		if(joypad() & J_DOWN){
			p[1] += 1;
			if (down <= 8 && down > 4) {
				set_sprite_tile(0, 0);
				set_sprite_tile(1, 2);
			}else if (down <= 4) {
				set_sprite_tile(0, 4);
				set_sprite_tile(1, 6);
			}else {
				down = 0;
			}
			down++;
			up = 0;
			left = 0;
			right = 0;

			move_sprite(0, p[0], p[1]);
			move_sprite(1, p[0] + 8, p[1]);
		}
		if(joypad() & J_UP){
			p[1] -= 1;
			if (up <= 8 && up > 4) {
				set_sprite_tile(0, 24);
				set_sprite_tile(1, 26);
			}else if (up <= 4) {
				set_sprite_tile(0, 28);
				set_sprite_tile(1, 30);
			}else {
				up = 0;
			}
			down = 0;
			up++;
			left = 0;
			right = 0;

			move_sprite(0, p[0], p[1]);
			move_sprite(1, p[0] + 8, p[1]);
		}
		if(joypad() & J_RIGHT){
			p[0] += 1;
			if (right <= 8 && right > 4) {
				set_sprite_tile(0, 8);
				set_sprite_tile(1, 10);
			}else if (right <= 4) {
				set_sprite_tile(0, 12);
				set_sprite_tile(1, 14);
			}else {
				right = 0;
			}
			down = 0;
			up = 0;
			left = 0;
			right++;

			move_sprite(0, p[0], p[1]);
			move_sprite(1, p[0] + 8, p[1]);
		}
		if(joypad() & J_LEFT){
			p[0] -= 1;
			if (left <= 8 && left > 4) {
				set_sprite_tile(0, 20);
				set_sprite_tile(1, 22);
			}else if (left <= 4) {
				set_sprite_tile(0, 16);
				set_sprite_tile(1, 18);
			}else {
				left = 0;
			}

			down = 0;
			up = 0;
			left++;
			right = 0;

			move_sprite(0, p[0], p[1]);
			move_sprite(1, p[0] + 8, p[1]);
		}
		performantdelay(3);
		
	}


}
