<!---

This file is used to generate your project datasheet. Please fill in the information below and delete any unused
sections.

You can also include images in this folder and reference them in the markdown. Each image must be less than
512 kb in size, and the combined size of all images must be less than 1 MB.
-->

## How it works

This implementation of tetris is split into 4 modules. The top module calls the
other modules. The input buffer takes `ui_in` and buffers it's bits. The VGA
graphics module implements vga graphics. The valid placement module moves the
active piece according to the transformation type, then checks if it collides
with the field.

## How to test

Simply compile the testbench in `./tb/`. It was writte in SDL3 and displays
the VGA output.

## External hardware

The VGA Pmod is used.

## pinout

| Pin | Signal | Pin | Signal |
| :-: | :----: | :-: | :----: |
| top row    | | bottom row | |
| 1   | R1     | 7   | R0     |
| 2   | G1     | 8   | G0     |
| 3   | B1     | 9   | B0     |
| 4   | VS     | 10  | HS     |
| 5   | GND    | 11  | GND    |
| 6   | VCC    | 12  | VCC    |
