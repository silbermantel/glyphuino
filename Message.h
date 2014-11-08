#ifndef message_h
#define message_h
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include "Glyph.h"

class Message
{
  public:
    Message(vector<Glyph> _words);
    Message();
    vector<char*> getText();
    vector<Glyph> getGlyphs();
    char* getText(int num);
    Glyph getGlyphs(int num);
    void add(Glyph g);


  private:
    vector<Glyph> words;

};

Message::Message(vector<Glyph> _words)
{
  Serial.println("message created");

}
Message::Message()
{
  Serial.println("message empty");
}

void Message::add(Glyph g) {
  words.push_back(g);
}
#endif
