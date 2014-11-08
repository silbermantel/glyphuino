/*********************************************************************
 * Glyphuino. Yeah!
 * Idea by silbermantel
 * Hard- and softwarehacking by agenttoktok
 * Glyph-bitmapping by silbermantel
 *********************************************************************/
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Glyph.h"
#include "anker.h"
#include "Message.h"


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
#define DELAYTIMER 700
vector<string> strings;

//void drawGlyph(Glyph g);
Message incoming;


void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.display();
  delay(2);

  // Clear the buffer.
  display.clearDisplay();
  //setup done
  vector<int> pattern;
  pattern.push_back(3);
  pattern.push_back(9);
  pattern.push_back(11);
  //  Glyph myglyph("abandon", pattern) ;
  incoming.add(Glyph("abandon", pattern));
}


void loop() {



  display.clearDisplay();
  delay(50);
  drawGrid();
  display.display();
  delay(DELAYTIMER);
  //  drawGlyph(myglyph);
  display.display();
  delay(DELAYTIMER);

}


void showMessage(Message current) {
  vector<Glyph> g = current.getGlyphs();
  for (int i = 0; i < g.size(); i++)
  {  
    drawGlyph(g[i]);
    showTranslation(g[i],i);
    textbuffer.push_back(g[i].getTitle());
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
  drawAnker(anker1);
  drawAnker(anker2);
  drawAnker(anker3);
  drawAnker(anker4);
  drawAnker(anker5);
  drawAnker(anker6);
  drawAnker(anker7);
  drawAnker(anker8);
  drawAnker(anker9);
  drawAnker(anker10);
  drawAnker(anker11);
}


void drawGlyph(Glyph g) {
  int source [] = {
    0, 0
  };
  int target [] = {
    0, 0
  };

  vector<int> steps = g.getSteps();

  for (int i = 0; i <= steps.size(); i++)
  {
    memcpy(target, source, sizeof(source));
    //   Serial.println(steps[i]);
    switch (steps[i])
    {
      case 1:
        memcpy(source, anker1, sizeof(anker1));
        break;
      case 2:
        memcpy(source, anker2, sizeof(anker2));
        break;
      case 3:
        memcpy(source, anker3, sizeof(anker3));
        break;
      case 4:
        memcpy(source, anker4, sizeof(anker4));
        break;
      case 5:
        memcpy(source, anker5, sizeof(anker5));
        break;
      case 6:
        memcpy(source, anker6, sizeof(anker6));
        break;
      case 7:
        memcpy(source, anker7, sizeof(anker7));
        break;
      case 8:
        memcpy(source, anker8, sizeof(anker8));
        break;
      case 9:
        memcpy(source, anker9, sizeof(anker9));
        break;
      case 10:
        memcpy(source, anker10, sizeof(anker10));
        break;
      case 11:
        memcpy(source, anker11, sizeof(anker11));

        break;
    }



    Serial.print(source[0]);
    Serial.print("x");
    Serial.print(source[1]);
    Serial.print("->");
    Serial.print(target[0]);
    Serial.print("x");
    Serial.println(target[1]);
    if (i > 0)
      display.drawLine(source[0], source[1], target[0], target[1], WHITE);


  }
  display.display();


}
void showTranslation(Glyph g, int count) {
  int spacer = 10;
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(spacer * count, spacer * count);
  display.println(g.getTitle());
  display.display();
  delay(20);

}
