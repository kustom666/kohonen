

/* structure de coordonn�e 2D pour affichage*/
typedef struct {
  double x,y;
} Point;




void draw_text(float x, float y, const char *fmt, ...);


/* Prototypes */
void affichage();
void clavier(unsigned char touche,int x,int y);
void reshape(int x,int y);
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);
void idle();

