#ifndef glyphgenerator_h
#define glyphgenerator_h

#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;


class Glyph
{
  public:
    Glyph(char* _title, vector<int> _steps);
    vector<int> getSteps();
    void setSteps(vector<int> steps);
    char* getTitle();

  private:
    char* title;
    vector<int> steps ;
};

Glyph::Glyph(char _title[], vector<int> _steps)
{
  memcpy(title,_title,sizeof(_title));
  setSteps(_steps);
}

vector<int> Glyph::getSteps()
{
  return steps;
}
void  Glyph::setSteps(vector<int> _steps)
{

  steps = _steps;

}

char* Glyph::getTitle() {

  return title;
}

bool CompareCaseInsensitive(string strFirst, string strSecond)
{
  // Convert both strings to upper case by transfrom() before compare.
  transform(strFirst.begin(), strFirst.end(), strFirst.begin(), toupper);
  transform(strSecond.begin(), strSecond.end(), strSecond.begin(), toupper);
  if (strFirst == strSecond) return true; else return false;
}

#endif
