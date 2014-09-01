#include "fileheader.h"


extern float tanax;
extern float tanay;


void inizializza(formica &formica1,float tanax,float tanay){

    formica1.x=tanax;
    formica1.y=tanay;
    formica1.alfa=random(0.0f,360.0f);
    formica1.trovato=false;
    formica1.rientro=false;
    formica1.count=0;
     formica1.dentro=false;

}

void elimina(pnodo &p,pnodo &testa){

if (p==testa){
                if(p->next!=NULL){
                p->next->prec=NULL;
                testa=p->next;}
                else
                testa=NULL;
             }
 else
     {
     if(p->next!=NULL)
                p->next->prec=p->prec;
     if(p->prec!=NULL)
                      p->prec->next=p->next;
     }
delete p;
}



//funzione per inserire una formica nella lista
void inserimento(pnodo &testa){
    formica formica1;
     inizializza(formica1,tanax,tanay);

if (testa==NULL)
  {
    testa= new nodo;
    testa->formica1=formica1;
    testa->next=NULL;
    testa->prec=NULL;

  }
    else{

     pnodo p=new nodo;

     p->next=testa;
     p->prec=NULL;
     testa->prec=p;

     testa=p;
     testa->formica1=formica1;

        }
}

//funzione random, restituisce un valore compreso tra a e b

float random(float a,float b){
      return (b-a)*(float)rand()/RAND_MAX+a;
      }
      
      
      
            
//le due funzioni di seguito calcolano se un punto è interno ad un triangolo
int segno(float px,float py,float ax,float ay,float bx,float by){
    float c,t;
    //t=10exp(-6);
    c=px*(ay-by)-py*(ax-bx)+ax*(by)-ay*bx;
    //if(abs(c))<t return 0;
    if(c>0) 
    return 1;
    else 
    return -1;
    }
    
int test(float px,float py,float ax,float ay,float bx,float by,float cx,float cy){
    float s1,s2,s3;

    s1=segno(ax,ay,bx,by,cx,cy)*segno(ax,ay,bx,by,px,py);
    s2=segno(bx,by,cx,cy,ax,ay)*segno(bx,by,cx,cy,px,py);
    s3=segno(cx,cy,ax,ay,bx,by)*segno(cx,cy,ax,ay,px,py);

    if(s1<0||s2<0||s3<0)
    return -1;
    else
    return 1;
    }
    
//funzione che permette di raggiungere un punto    
float raggiungi(float x,float y,float px,float py){

if(px==x)
x+=0.00000001f;
      float m=((py-y)/(px-x));
      float angolo=atan(m)/pigreco*180.0f;

if (px>x)
      return angolo;
else
    return angolo+180.0f;


      }
      
  
