- The source code has been taken from this project: https://github.com/WatchWinder/ArduinoWatchWinder
It has been updated to fit on an Uno (instead of Mega2560), accommodate IDE 1.8.6 and 2018 libraries. Had to move to a different menu library in particular.

- Most comments and description are on tab 1 of the core ino file
- save_presets_eeprom.ino needs to be run once only before uploading the core programme on the Uno board.
It writes presets for TPD and DIR into EEPROM for two watches; see comments in the ino file.
- Pin 10 is used for LED built into the Activate slot button, it turns on when slot is active. This is optional and not shown on schematics.
- PCF2584-based backpack must be soldered to an LCD 20x4 (not 16x2), th latter not shown on schematics.

Apologies for any unconventional programming decisions.
Please read "readme" for the source project before asking any questions.

If needed, please write to alexarefiev@gmail.com

Good luck!
