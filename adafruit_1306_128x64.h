/*
	Glyphuino, an arduino project to display glyphs on wearable displays
    Copyright (C) 2015  agent silbermantel

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef display_h
#define display_h


/*
product: https://www.adafruit.com/products/326

Data ->  Analog 4
Clk  ->  Analog 5
Rst  ->  Digital 4 (defined in OLED_RESET)
Vin  ->  3.3V
Gnd  ->  Gnd



*/

#define OLED_CPL 21
#define OLED_HEIGHT 64
#define OLED_WIDTH 128
#define OLED_RESET 4
#define OLED_INIT_STR SSD1306_SWITCHCAPVCC, 0x3D
Adafruit_SSD1306 display(OLED_RESET);

const int cols []= {
  39,53,OLED_WIDTH/2,75,89
};
const int rows []=  {
  4,16,24,OLED_HEIGHT/2,40,48,60
};

#endif
