# Botw2d

This is a gameboy color version of Breath of the Wild.
I'm still learning and have just started making this game, so it isn't good atm.



Building

You need to have gbdk installed correctly

lcc -Wl-yp143=0x80 -o game.gbc main.c map.c tileset.c player.c hud_map.c hud_tiles.c
