#include 	<gl/gl.h>		// Header File For The OpenGL32 Library
#include 	<gl/glu.h>
#include 	<gl/glaux.h>
#include 	<math.h>
#define pigreco 3.141592f

//variabili formica
struct formica{
    
	float x;
	float y;
    float alfa;//random(0.0f,360.0f);
    bool trovato;
    bool rientro;
    bool dentro;
    int count;
};

struct nodo{
    formica formica1;
    nodo* next;
    nodo* prec;
};

typedef nodo* pnodo;

void tana(float tanax,float tanay);
int segno(float px,float py,float ax,float ay,float bx,float by);
int test(float px,float py,float ax,float ay,float bx,float by,float cx,float cy);  
void cibo(int count2,float tanax,float tanay);
float random(float a,float b);
float raggiungi(float x,float y,float px,float py);
void inizializza(formica &formica1,float tanax,float tanay);
void disegnaformica(formica formica1);
void updateformica(formica &formica1);
void elimina(pnodo &p,pnodo &testa);
void inserimento(pnodo &testa);
