/*********************************************************************
Glyphuino. Yeah!
Idea by silbermantel
Hard- and softwarehacking by agenttoktok
Glyph-bitmapping by silbermantel
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "glyphuino_glyphs.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

char* arr_sentence_one[] = {"sample_bmp", "all_bmp", "being_human_bmp"};
int num_sentence_one = 3;
//#define num_sentence_one (sizeof(arr_sentence_one)/sizeof(char *)) //array size  

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {                
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen, but only sooooo short, i dont like those screens...  ;)
  display.display();
  delay(2);

  // Clear the buffer.
  display.clearDisplay();
  //setup done
}


void loop() {
  while (1) {
 //   for (int i = 0; i < num_sentence_one; i++) {
 //       display.drawBitmap(32, 0, arr_sentence_one[i], 64, 64, WHITE);
  display.clearDisplay();
  display.drawBitmap(32, 0, glyph_template, 64, 64, WHITE);
  display.display();
  delay(700);
      
      display.clearDisplay();
      display_glyph(32, 0, glyph_difficult, 64, 64, WHITE);
      display_glyph(32, 0, glyph_path, 64, 64, WHITE);
      display_glyph(32, 0, glyph_together, 64, 64, WHITE);
      display_glyph(32, 0, glyph_create, 64, 64, WHITE);
      display_glyph(32, 0, glyph_peace, 64, 64, WHITE);
      display_text(10, 10, "Difficult", 1, 1000);
      display_text(20, 20, "Path", 1, 1000);
      display_text(30, 30, "Together", 1, 1000);
      display_text(40, 40, "Create", 1, 1000);
      display_text(50, 50, "Peace", 1, 1000);
      display.clearDisplay();
      display.display();
      delay(500);
      display_text(10, 10, "Difficult", 1, 0);
      display_text(20, 20, "Path", 0, 0);
      display_text(30, 30, "Together", 0, 0);
      display_text(40, 40, "Create", 0, 0);
      display_text(50, 50, "Peace", 0, 0);
      delay(2000);

      display.clearDisplay();
      display_glyph(32, 0, glyph_destroy, 64, 64, WHITE);
      display_glyph(32, 0, glyph_resistance, 64, 64, WHITE);
      display_glyph(32, 0, glyph_create, 64, 64, WHITE);
      display_glyph(32, 0, glyph_peace, 64, 64, WHITE);
      display_text(10, 10, "Destroy", 1, 1000);
      display_text(20, 20, "Resistance", 1, 1000);
      display_text(30, 30, "Create", 1, 1000);
      display_text(40, 40, "Peace", 1, 1000);
      display.clearDisplay();
      display.display();
      delay(500);
      display_text(10, 10, "Destroy", 1, 0);
      display_text(20, 20, "Resistance", 0, 0);
      display_text(30, 30, "Create", 0, 0);
      display_text(40, 40, "Peace", 0, 0);
      delay(2000);

      display.clearDisplay();
      display_glyph(32, 0, glyph_destroy, 64, 64, WHITE);
      display_glyph(32, 0, glyph_resistance, 64, 64, WHITE);
      display_glyph(32, 0, glyph_defend, 64, 64, WHITE);
      display_glyph(32, 0, glyph_knowledge, 64, 64, WHITE);
      display_text(10, 10, "Destroy", 1, 1000);
      display_text(20, 20, "Resistance", 1, 1000);
      display_text(30, 30, "Defend", 1, 1000);
      display_text(40, 40, "Knowledge", 1, 1000);
      display.clearDisplay();
      display.display();
      delay(500);
      display_text(10, 10, "Destroy", 1, 0);
      display_text(20, 20, "Resistance", 0, 0);
      display_text(30, 30, "Defend", 0, 0);
      display_text(40, 40, "Knowledge", 0, 0);
      delay(2000);

      display.clearDisplay();
      display_glyph(32, 0, glyph_enlightened, 64, 64, WHITE);
      display_glyph(32, 0, glyph_improve, 64, 64, WHITE);
      display_glyph(32, 0, glyph_future, 64, 64, WHITE);
      display_text(10, 10, "Enlightened", 1, 1000);
      display_text(20, 20, "Improve", 1, 1000);
      display_text(30, 30, "Future", 1, 1000);
      display.clearDisplay();
      display.display();
      delay(500);
      display_text(10, 10, "Enlightened", 1, 0);
      display_text(20, 20, "Improve", 0, 0);
      display_text(30, 30, "Future", 0, 0);
      delay(2000);

      display.clearDisplay();
      display_glyph(32, 0, glyph_defend, 64, 64, WHITE);
      display_glyph(32, 0, glyph_portal, 64, 64, WHITE);
      display_glyph(32, 0, glyph_defend, 64, 64, WHITE);
      display_glyph(32, 0, glyph_future, 64, 64, WHITE);
      display_text(10, 10, "Defend", 1, 1000);
      display_text(20, 20, "Portal", 1, 1000);
      display_text(30, 30, "Defend", 1, 1000);
      display_text(40, 40, "Future", 1, 1000);
      display.clearDisplay();
      display.display();
      delay(500);
      display_text(10, 10, "Defend", 1, 0);
      display_text(20, 20, "Portal", 0, 0);
      display_text(30, 30, "Defend", 0, 0);
      display_text(40, 40, "Future", 0, 0);
      delay(2000);

      display.clearDisplay();
      display_glyph(32, 0, glyph_simple, 64, 64, WHITE);
      display_glyph(32, 0, glyph_truth, 64, 64, WHITE);
      display_glyph(32, 0, glyph_resistance, 64, 64, WHITE);
      display_glyph(32, 0, glyph_lie, 64, 64, WHITE);
      display_text(10, 10, "Simple", 1, 1000);
      display_text(20, 20, "Truth", 1, 1000);
      display_text(30, 30, "Resistance", 1, 1000);
      display_text(40, 40, "Lie", 1, 1000);
      display.clearDisplay();
      display.display();
      delay(500);
      display_text(10, 10, "Simple", 1, 0);
      display_text(20, 20, "Truth", 0, 0);
      display_text(30, 30, "Resistance", 0, 0);
      display_text(40, 40, "Lie", 0, 0);
      delay(2000);
//    }
  }
}

void display_glyph(const uint8_t cursor_pos, uint8_t line, const uint8_t* bmp, uint8_t h, uint8_t w, char color) {
  display.clearDisplay();
  display.drawBitmap(cursor_pos, line, glyph_template, h, w, color);
  display.display();
  delay(200);
  display.clearDisplay();
  display.drawBitmap(cursor_pos, line, bmp, h, w, color);
  display.display();
  delay(1800);
}

void display_text(const uint8_t cursor_pos_h, const uint8_t cursor_pos_w, char* text, const uint8_t clear_disp, const uint16_t delay_txt) {
  if ( clear_disp == 1 ) {
    display.clearDisplay();
  }
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(cursor_pos_h, cursor_pos_w);
  //display.clearDisplay();
  display.println(text);
  display.display();
  delay(delay_txt);
}

void testdrawline() {  
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, WHITE);
    display.display();
  }
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, WHITE);
    display.display();
  }
  delay(250);
  
  display.clearDisplay();
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, WHITE);
    display.display();
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
    display.display();
  }
  delay(250);
  
  display.clearDisplay();
  for (int16_t i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, WHITE);
    display.display();
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, WHITE);
    display.display();
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, WHITE);
    display.display();
  }
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, WHITE); 
    display.display();
  }
  delay(250);
}

void testscrolltext(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("scroll");
  display.display();
 
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}
