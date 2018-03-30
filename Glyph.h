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

#ifndef glyphs_h
#define glyphs_h
#include "anker.h"

typedef struct glyph {
    char nodes[16];
    char word[16];
} glyph;


glyph newGlyph(char *nodes, char *word){
	glyph g;
	strcpy(g.word,word);
	strcpy(g.nodes,nodes);
	return g;
}

int getXcoordinate(char c){
   int rValue= 0;
  
  switch (c)
    {
      case 'k':
        rValue=ankerK[0];
        break;
      case 'p':
         rValue=ankerP[0];       
        break;
      case 'n':
                rValue=ankerN[0];
        break;
      case 'a':
                rValue=ankerA[0];
        break;
      case 'e':
                rValue=ankerE[0];
        break;
      case 't':
                rValue=ankerT[0];
        break;
      case 'o':
                rValue=ankerO[0];
        break;
      case 'i':
                rValue=ankerI[0];
        break;
      case 'm':
                rValue=ankerM[0];
        break;
      case 'b':
                rValue=ankerB[0];
        break;
      case 's':
                rValue=ankerS[0];
        break;
    }
    return rValue;
}

int getYcoordinate(char c){
   int rValue= 0;
  
  switch (c)
    {
      case 'k':
        rValue=ankerK[1];
        break;
      case 'p':
         rValue=ankerP[1];       
        break;
      case 'n':
                rValue=ankerN[1];
        break;
      case 'a':
                rValue=ankerA[1];
        break;
      case 'e':
                rValue=ankerE[1];
        break;
      case 't':
                rValue=ankerT[1];
        break;
      case 'o':
                rValue=ankerO[1];
        break;
      case 'i':
                rValue=ankerI[1];
        break;
      case 'm':
                rValue=ankerM[1];
        break;
      case 'b':
                rValue=ankerB[1];
        break;
      case 's':
                rValue=ankerS[1];
        break;
    }
        return rValue;

}

#endif
