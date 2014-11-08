#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "glyph.h"

    

glyph new_glyph(char *word, char *nodes){
	glyph g;
	strcpy(g.word,word);
	strcpy(g.nodes,nodes);
	return g;
}

void do_glyph(glyph g){
	int i;
	int order[16];
	char dict[128];
    /*
                  k
       p                       n
            a            e
                  t
            o            i
       m                       b 
                  s
    
       do_glyph() defines the mapping between these letters and the nodes 1-11 
       in your original coding.
     */

	/* gives an indexed position for each character in "nodes", corresponding
	   to the index you set up to begin with, then calls the code to light it
       up, based on your original indices.
	 */
	dict['k']=1;
	dict['p']=2;
	dict['n']=3;
	dict['a']=4;
	dict['e']=5;
	dict['t']=6;
	dict['o']=7;
	dict['i']=8;
	dict['m']=9;
	dict['b']=10;
	dict['s']=11;

	
	for(i=0;g.nodes[i]!=0;i++){
		/* go through each character in "nodes", assigning a node index
		   until you get to 0, which is the customary terminal character
		   for C strings.  in C, characters enclosed in single quotes are 
		   actually 8bit ints: 'a'==97 and 'z'==122. (i think...)
		 */
		order[i]=(int)(dict[g.nodes[i]]);
	}
	order[i]=0;
	light_up_glyph(order); /* light_up_glyph() needs to take an array 
							  of ints, and light up the glyph according
							  to your node indices */
	return;
}

void do_message(glyph * g_arr, int len, int delay, int loop){
	int i=1;
	while(loop?i:i--){
		for(i=0;i<len;i++){
			do_glyph(g_arr[i]);
			print_word(g_arr[i].word); /* this needs to print your word */
			/*sleep(delay);*/
		}
	}
	return;
}

int main(void){
	glyph message[3]={
		new_glyph("abandon", G_ABANDON),
		new_glyph("after", G_AFTER),
		new_glyph("all", G_ALL)
	};
	do_message(message, 3, 1, 0);
	return;
}

/* replace this with your code */
void print_word(char *word){
	printf("%s\n",word);
	return;
}

/* replace this with your code */
void light_up_glyph(int *o){
    /* the last index should be zero (0), to signify the end of the 
       glyph.  otherwise things get hinkie. */
	int i=0;
	while(o[i++]) printf("%d, ",o[i]);
	printf("\n");
	return;
}