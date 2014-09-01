#include "fileheader.h"

//variabili campo visivo
float ax = 0.20f;
float ay = 0.20f;
float bx = 0.0f;
float by = 0.0f;
float cx = 0.20f;
float cy = -0.20f;

extern float cibox;
extern float ciboy;

extern float tanax;
extern float tanay;

extern float res;

extern bool campovisivo;

extern int count2;
//DEFINIZIONI FUNZIONI

void tana(float tanax,float tanay){
     float a=0.02f*res;
    glBegin(GL_QUADS);
		glColor3f( 0.8f, 0.5f, 0.0f );
                             glVertex2f( tanax+a, tanay+a);
                             glVertex2f( tanax-a, tanay+a);
                             glVertex2f( tanax-a, tanay-a);
                             glVertex2f( tanax+a, tanay-a);
          glEnd();
     }


void cibo(int count2,float cibox,float ciboy){
      float a=0.02f*res;
     if(count2>0){
     glBegin(GL_QUADS);
		glColor3f( 1.0f, 0.0f, 0.0f );
                              glVertex2f( cibox+a, ciboy+a);
                              glVertex2f( cibox-a, ciboy+a);
                              glVertex2f( cibox-a, ciboy-a);
                              glVertex2f( cibox+a, ciboy-a);
          glEnd();}
     }


//disegna la formica e il suo campo visivo
void disegnaformica(formica formica1){


          glPushMatrix();

          glTranslatef(formica1.x,formica1.y,0.0f);
          glRotatef(formica1.alfa, 0.0f, 0.0f, 1.0f);

          glScalef(res,res,res);

         
          if (campovisivo){
                  glBegin(GL_TRIANGLES);
                        glColor3f( 0.0f, 0.4f, 0.1f );
                           glVertex2f( ax, ay );
                           glVertex2f( bx, by );
                           glVertex2f( cx, cy );
                                glEnd();
                           }

//formica
           glBegin(GL_QUADS);
           glColor3f( 0.0f, 0.0f, 0.0f );    
                    glVertex2f( 0.0f, 0.015f );
                    glVertex2f( -0.015f, 0.0f );
                    glVertex2f( 0.0f, -0.015f );
                    glVertex2f( 0.015f, 0.0f );

                    glVertex2f( -0.01f, 0.02f );
                    glVertex2f( -0.035f, 0.0f );
                    glVertex2f( -0.01f, -0.02f );
                    glVertex2f(  0.0f, 0.0f );

                    glVertex2f( 0.02f, 0.015f );
                    glVertex2f( -0.005f, 0.0f );
                    glVertex2f( 0.02f, -0.015f );
                    glVertex2f( 0.03f, 0.0f );

if(formica1.dentro){
                               glColor3f( 1.0f, 0.0f, 0.0f );    

                    glVertex2f( 0.02f, 0.007f );
                    glVertex2f( -0.0025f, 0.0f );
                    glVertex2f( 0.02f, -0.007f );
                    glVertex2f( 0.04f, 0.0f );

                    
                    }


          glEnd();
          glPopMatrix();


     }


// aggiorna la posizione della formica
void updateformica(formica &formica1){
    
    float rad=formica1.alfa*pigreco/180.0f;
    float vettorev=0.0003;
	float vx=vettorev*cos(rad);
	float vy=vettorev*sin(rad);
    
//aggiornamento x ed y

        formica1.x+=vx;
        formica1.y+=vy;


float roa=sqrt(pow(ax,2)+pow(ay,2));    //ro del triangolo(mi serve per tener conto della rotazione
float roc=sqrt(pow(cx,2)+pow(cy,2));    //del campo visivo)



  
      if(!formica1.trovato){
                            
               //testa se il cibo è all'interno del campo visivo
    
    if(test(  cibox,  ciboy,  roa*cos(rad+pigreco/4)*res+formica1.x,  roa*sin(rad+pigreco/4)*res+formica1.y,
      bx*res+formica1.x,  by*res+formica1.y,  roc*cos(rad-pigreco/4)*res+formica1.x,  roc*sin(rad-pigreco/4)*res+formica1.y)>0)
        if(count2>0) 
        formica1.trovato=true;             
                     
        //aggiornamento alfa                              
          if(formica1.count==2){
          //aggiorno l'angolo alfa in modo abbastanza casuale
             //if(random(-1,1)<0)
               formica1.alfa+=random(-5.0f,5.0f);
             //else
                //formica1.alfa-=random(-5.0f,5.0f);

             formica1.count=0;
        }
    
      }

        else{
//cibo trovato
                    if(!formica1.dentro){
                                         if(count2>0)
                   formica1.alfa=raggiungi(formica1.x,formica1.y,cibox,ciboy);
                          
                                          else
                                          formica1.trovato=false;
        //cibo raggiunto                                  
                            if((formica1.x>cibox-0.04*res&&formica1.x<cibox+0.04*res)&&(formica1.y>ciboy-0.04*res&&formica1.y<ciboy+0.04*res)){
                   
                                 count2--;
                                 formica1.dentro=true;
                             }
                   }
                     else //la formica si trova sul cibo
                     {
                         formica1.alfa=raggiungi(formica1.x,formica1.y,tanax,tanay);
                         if((formica1.x>tanax-0.04*res &&formica1.x<tanax+0.04*res)&&(formica1.y>tanay-0.04*res&&formica1.y<tanay+0.04*res))
                                 formica1.rientro=true;
                      }
          }


//controlli sui rimbalzi
        if(formica1.x+0.045f*res>1||formica1.x-0.045*res<-1){
        vx=-vx;
        formica1.alfa=180.0f-formica1.alfa;
        }
        
        if(formica1.y+0.045f*res>1||formica1.y-0.045*res<-1){
        vy=-vy;
        formica1.alfa=-formica1.alfa;
        }


//controlla la direzione della formica e ne corregge la rotazione
        
	        formica1.count++;
}



