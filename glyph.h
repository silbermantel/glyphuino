
typedef struct glyph {
    char nodes[16];
    char word[16];
} glyph;

/*
              k
   p                       n
        a            e
              t
        o            i
   m                       b 
              s

do_glyph() defines the mapping between these letters and the nodes 1-11 in
your original coding:

              1
   2                       3
        4            5
              6
        7            8
   9                       10
             11

*/


#define G_ABANDON "netoms"
#define G_ADAPT "itop"
#define G_ADVANCE "mak"
#define G_AFTER "tenbit"
#define G_AGAIN "maotei"
#define G_REPEAT "maotei"
#define G_ALL "bnkpmsb"
#define G_ANSWER "aeit"
/* ... etc ...*/

/* only defines that are actually named somewhere will get compiled into
the program.  thus you have about 32 bytes for each used glyph. */

/* initialize new glyph struct */
glyph new_glyph(char *word, char *nodes);

/* send message (glyph and english word array) out to the world */
void do_message(glyph *glyph_arr, int length, int delay, int loop);

/* call glyph display function for a glyph struct */
void do_glyph(glyph g);

/* write english word to the screen (you'll have to override this) */
void print_word(char *word);

/* take an array of node indices (1-11) and display them with appropriate 
   vertices, in sequence, if you want. */
void light_up_glyph(int *nodes);
