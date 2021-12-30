#!/bin/bash

cp keymap.c ../qmk_firmware/keyboards/ergodox_ez/keymaps/peteraltosaar/keymap.c
cd ../qmk_firmware
make ergodox_ez:peteraltosaar
#rm keyboards/ergodox_ez/keymaps/peteraltosaar/keymap.c
cd -
