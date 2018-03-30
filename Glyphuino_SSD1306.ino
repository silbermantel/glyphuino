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

    #include <SPI.h>
    #include <Wire.h>
    #include <Adafruit_GFX.h>
    #include <Adafruit_SSD1306.h>
    #include "adafruit_1306_128x64.h"
    #include "Glyph.h"
    #include "knownglyphs.h"
    #include "Messages.h"

    #if (SSD1306_LCDHEIGHT != 64)
    #error("Height incorrect, please fix Adafruit_SSD1306.h!");
    #endif
    glyph message[] ={newGlyph(G_ALL), newGlyph(__EMPTY), newGlyph(__EMPTY), newGlyph(__EMPTY), newGlyph(__EMPTY)};

    #define GLYPHTIME 1000
    #define TEXTTIME 1000
    #define LINETIME 0
    #define GRIDTIME 300
    void setup() {
    	Serial.begin(9600);
	display.begin(OLED_INIT_STR); // initialize with the I2C addr 0x3D (for the 128x64)
	display.display();
	delay(2);
	// Clear the buffer.
	display.clearDisplay();
	//setup done
        Serial.println(F("Glyphuino is set up nicely"));
 /*       showText(12, 12,"GLYPHUINO", 1, 1000,2);

        showText(22, 32, "v0.1.0", 0, 1000,2);

        showText(12, 52, " by silbermantel", 0, 1000,1);
        */
    }

    void loop() {
    	display.clearDisplay();
    	drawGrid();
    	display.display();
    	goBlinky(3);

    	setMessage(M_silbermantel01);
    	Serial.println(F("going once"));
    	setMessage(M_silbermantel02);

    	setMessage(M_silbermantel03);

    	setMessage(M_silbermantel04);


    }












    void goBlinky(int num)
    {
    	for (int i = 0; i < num; i++) {
    		display.invertDisplay(true);
    		delay(200); 
    		display.invertDisplay(false);
    		delay(500);
    	}
    	Serial.println(F("blinkety blink"));
    }

    void showMessage(glyph *g_arr, int len, bool showtrans,bool showmess) {

    	int i = 1;
    	char emptyID[16];
    	strcpy(emptyID,"x");
    	int xpos=0;

    	for (i = 0; i < len; i++) {
    		if(strcmp(g_arr[i].nodes, emptyID) != 0)
    		{
    			display.clearDisplay();
    			drawGrid();
    			showGlyph(g_arr[i]);
    			delay(GLYPHTIME);
    			xpos=(OLED_WIDTH/2)-(strlen(g_arr[i].word)/2)*OLED_WIDTH/(OLED_CPL/2);
    			showText(xpos,rows[2] , g_arr[i].word, 1, TEXTTIME,2);}

    		}
    		display.clearDisplay();
    		for (i = 0; i < len; i++) {
    			if(strcmp(g_arr[i].nodes, emptyID) != 0)
    			showText(i * 10+15, i * 10, g_arr[i].word, 0, TEXTTIME/5,1);
    		}

    		delay(GLYPHTIME);
    		return;
    	}

    	void showText(const uint8_t cursor_pos_h, const uint8_t cursor_pos_w,
    		char* text, const uint8_t clear_disp, const uint16_t delay_txt,const uint8_t tSize) {
    		if (clear_disp == 1) {
    			display.clearDisplay();
    		}
    		display.setTextSize(tSize);
    		display.setTextColor(WHITE);
    		display.setCursor(cursor_pos_h, cursor_pos_w);
	//display.clearDisplay();
	display.println(text);
	display.display();
	delay(delay_txt);
}

void showGlyph(glyph g) {

	int x1 = getXcoordinate(g.nodes[0]);
	int y1 = getYcoordinate(g.nodes[0]);

	int x2 = 0;
	int y2 = 0;
	
	for (int i = 1; g.nodes[i] != 0; i++) {

		x2 = getXcoordinate(g.nodes[i]);
		y2 = getYcoordinate(g.nodes[i]);
		display.drawLine(x1, y1, x2, y2, WHITE);
		
		display.display();
		x1 = x2;
		y1 = y2;
		x2 = 0;
		y2 = 0;
		delay(LINETIME);
	}

}

void drawAnker(const int anker[]) {
	int centerx = anker[0];
	int centery = anker[1];

	//upper
	display.drawLine(centerx - 1, centery - 1, centerx + 1, centery - 1, WHITE);
	//left
	display.drawLine(centerx - 1, centery - 1, centerx - 1, centery + 1, WHITE);
	//right
	display.drawLine(centerx + 1, centery - 1, centerx + 1, centery + 1, WHITE);
	//lower
	display.drawLine(centerx - 1, centery + 1, centerx + 1, centery + 1, WHITE);
}

void drawGrid() {
	drawAnker(ankerK);
	drawAnker(ankerP);
	drawAnker(ankerN);
	drawAnker(ankerA);
	drawAnker(ankerE);
	drawAnker(ankerT);
	drawAnker(ankerO);
	drawAnker(ankerI);
	drawAnker(ankerM);
	drawAnker(ankerB);
	drawAnker(ankerS);
	display.display();
}


void setMessage(char *nodes0, char *word0, char *nodes1, char *word1,char *nodes2, char *word2,char *nodes3, char *word3,char *nodes4, char *word4){
	message[0]=newGlyph(nodes0, word0);
	message[1]=newGlyph(nodes1, word1);
	message[2]=newGlyph(nodes2, word2);
	message[3]=newGlyph(nodes3, word3);
	message[4]=newGlyph(nodes4, word4);
	showMessage(message, sizeof(message) / sizeof(glyph),true,true);
}

void setMessage(char *nodes1, char *word1,char *nodes2, char *word2,char *nodes3, char *word3,char *nodes4, char *word4){
	setMessage(nodes1, word1,nodes2, word2,nodes3, word3,nodes4, word4,__EMPTY);
}

void setMessage(char *nodes1, char *word1,char *nodes2, char *word2,char *nodes3, char *word3){
	setMessage(nodes1, word1,nodes2, word2,nodes3, word3,__EMPTY);
}
void setMessage(char *nodes1, char *word1,char *nodes2, char *word2){
	setMessage(nodes1, word1,nodes2, word2,__EMPTY,__EMPTY,__EMPTY);
}
void setMessage(char *nodes1, char *word1){
	setMessage(nodes1, word1,__EMPTY,__EMPTY,__EMPTY,__EMPTY);
} 

