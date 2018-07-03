// Pong - Fatec Zona Sul

#include "LedControl.h"

byte MSG[8*20];

byte SPACE[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000  
};

// código do nº1
byte a[8] = {
  B00000000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010100,
  B00011000,
  B00010000,  
};

// código do nº2
byte b[8] = {
  B00000000,
  B00111110,
  B00000100,
  B00001000,
  B00010000,
  B01000010,
  B01000010,
  B00111100
};

byte F[8] = {
  B00000000,
  B00000010,
  B00000010,
  B00000010,
  B00111110,
  B00000010,
  B00111110,
  B00000000
};

byte A[8] = {
  B00000000,
  B01000010,
  B01000010,
  B01111110,
  B01000010,
  B00100100,
  B00011000,
  B00000000  
};

byte T[8] = {
  B00000000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00111110,
  B00000000 
};

byte E[8] = {
  B00000000,
  B01111110,
  B00000010,
  B00000010,
  B01111110,
  B00000010,
  B01111110,
  B00000000  
};

byte C[8] = {
  B00000000,
  B01111100,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B01111100,
  B00000000  
};


byte Z[8] = {
  B00000000,
  B01111110,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01111110,
  B00000000  
};


byte O[8] = {
  B00000000,
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100,
  B00000000  
};

byte N[8] = {
  B00000000,
  B01000010,
  B01100010,
  B01010010,
  B01001010,
  B01000110,
  B01000010,
  B00000000 
};

byte S[8] = {
  B00000000,
  B00111110,
  B01000000,
  B01000000,
  B01111110,
  B00000010,
  B00000010,
  B01111100  
};

byte U[8] = {
  B00000000,
  B01111110,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00000000  
};

byte L[8] = {
  B00000000,
  B01111110,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000000  
};

byte J[8] = {
  B00000000,
  B00001100,
  B00010010,
  B00010010,
  B00010000,
  B00010000,
  B01111110,
  B00000000
};

byte G[8] = {
  B00000000,
  B01111100,
  B01000010,
  B01001010,
  B01111010,
  B00000010,
  B01111100,
  B00000000  
};

byte D[8] = {
  B00000000,
  B00111110,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111110,
  B00000000
};

byte H[8] = {
  B01000010,
  B01000010,
  B01000010,
  B01111110,
  B01000010,
  B01000010,
  B01000010,
  B00000000  
};

byte R[8] = {
  B00000000,
  B01000010,
  B00100010,
  B00010010,
  B00111110,
  B01000010,
  B00111110,
  B00000000  
};

byte V[8] = {
  B00000000,
  B00011000,
  B00100100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00000000
};
 
int som = 13;

#define N_c 261
#define N_d 294
#define N_e 329
#define N_f 349
#define N_g 391
#define N_gS 415
#define N_a 440
#define N_aS 455
#define N_b 466
#define N_cH 523
#define N_cSH 554
#define N_dH 587
#define N_dSH 622
#define N_eH 659
#define N_fH 698
#define N_fSH 740
#define N_gH 784
#define N_gSH 830
#define N_aH 880

int adc_col;
int adc_linha; 
int row_bar = 0;
 
LedControl MatrizPong=LedControl(49,51,53,2);   // (DIN,CLK,CS,nº de matrizes)
int Ponto_J1 = 0;
int OLD_Ponto_J1 = 0;

int Ponto_J2 = 0;
int OLD_Ponto_J2 = 0;

int X = 0,OLD_X,sensor;
int Y = 0,OLD_Y,sensor2;

int barra1 = 3;
int OLD_barra1;
int barra2 = 4;
int OLD_barra2;

int linha,col;
int ac,al;

int cnt = 0;

boolean INTRO_SHOWED = false;

int dly;

int botao  = 8;
boolean botaoAnt = false;
boolean botaoAtu = false;

int botao2 = 9;
boolean botao2Ant = false;
boolean botao2Atu = false;

int botao3  = 3;
boolean botao3Ant = false;
boolean botao3Atu = false;

int botao4 = 2;
boolean botao4Ant = false;
boolean botao4Atu = false;

void setup() {

  Serial.begin(9600);

//ativa os pinos
  pinMode(som, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(botao2, INPUT);
  pinMode(botao3, INPUT);
  pinMode(botao4, INPUT);

//ativando primeira matriz
  MatrizPong.shutdown(0,false);
  MatrizPong.setIntensity(0,8);
  MatrizPong.clearDisplay(0);

//ativando segunda matriz
  MatrizPong.shutdown(1,false);
  MatrizPong.setIntensity(1,8);
  MatrizPong.clearDisplay(1);



  mensagem_inicial();
 
   loose();

   if(Ponto_J1 == 5) winner();
   if(Ponto_J2 == 5) winner2();

   dly = 700;

// serve para ligar os leds das barras do Pong
// (linha, coluna, estado). Estado true(1) é ligado. Estado false(0) é desligado   
   setLED(15,barra1,true);setLED(15,barra1+1,true);setLED(15,barra1+2,true);
   setLED1(0,barra2,true);setLED1(0,barra2+1,true);setLED1(0,barra2+2,true);
   
   OLD_barra1 = -1;
   OLD_barra2 = -1;

   adc_col = 1;
   adc_linha = 1;

   ac = adc_col;
   al = adc_linha;

//posição inicial da bola
   if(Ponto_J1 != OLD_Ponto_J1)
   {
      OLD_Ponto_J1 = Ponto_J1;
      linha = 14;
      col = random(8);
      al = -adc_linha;

   }
   else if(Ponto_J2 != OLD_Ponto_J2)
   {
      OLD_Ponto_J2 = Ponto_J2;
      linha = 1;
      col = random(8);
      al = adc_linha;

   }
   else
   {
   linha = 7+random(1);
   col = random(8);
   }    
}




void loop() 
{ 
   botaoAtu = digitalRead(botao);
   if (botaoAtu && !botaoAnt)
   {
    barra1 = barra1 - 1;
    
   }
   botaoAnt = botaoAtu;

   botao2Atu = digitalRead(botao2);
   if (botao2Atu && !botao2Ant)
   {
    barra1 = barra1 + 1;
    
   }
   botao2Ant = botao2Atu;

    botao3Atu = digitalRead(botao3);
   if (botao3Atu && !botao3Ant)
   {
    barra2 = barra2 - 1;
    
   }
   botao3Ant = botao3Atu;

   botao4Atu = digitalRead(botao4);
   if (botao4Atu && !botao4Ant)
   {
    barra2 = barra2 + 1;
    
   }
   botao4Ant = botao4Atu;
   
   if(barra1 <= 0) barra1 = 1;
   if(barra1 >= 7) barra1 = 6;
   
   if(barra2 <= 0) barra2 = 1;
   if(barra2 >= 7) barra2 = 6;
   sensor = analogRead(A1);

   
// condição para mover a barra debaixo
   if(barra1 != OLD_barra1)
   {
      OLD_barra1 = barra1;

// apaga a linha que a barra está
      setROW(15,0x00);   
// ascende a barra na sua nova localização
      setLED(15,barra1-1,true);setLED(15,barra1,true);setLED(15,barra1+1,true);
   }

   if(barra2 != OLD_barra2)
   {
      OLD_barra2 = barra2;

// apaga a linha que a barra está
      setROW(0,0x00);   
// ascende a barra na sua nova localização
      setLED1(0,barra2-1,true);setLED1(0,barra2,true);setLED1(0,barra2+1,true);
   }
  

   if(cnt == 0) 
   {
     setLED(linha,col,false);
     setLED1(linha,col,false);

// condições para quando a bola bater na parede, mudar de direção
     if(col == 7) {ac = -adc_col;tone(som,226,16);};
     if(col == 0) {ac = adc_col;tone(som,226,16);};
     
     if(dly <= 170) dly = 190;

     if(linha == 1)
     {
        if(col == barra2 || col == barra2+1 & ac < 0) {al = adc_linha;tone(som,459,96);dly-=5;}
        else if(col == barra2 || col == barra2-1 && ac > 0) {al = adc_linha;tone(som,459,96);dly-=5;}
        else if(col == barra2-2 && ac > 0) {al = adc_linha; ac = -adc_col;tone(som,459,96);dly-=5;}
        else if(col == barra2+2 && ac < 0) {al = adc_linha; ac = adc_col;tone(som,459,96);dly-=5;};
     }

     if(linha == 14)
     {
        if(col == barra1 || col == barra1+1 & ac < 0) {al = -adc_linha;tone(som,459,96);dly-=5;}
        else if(col == barra1 || col == barra1-1 && ac > 0) {al = -adc_linha;tone(som,459,96);dly-=5;}
        else if(col == barra1-2 && ac > 0) {al = -adc_linha; ac = -adc_col;tone(som,459,96);dly-=5;}
        else if(col == barra1+2 && ac < 0) {al = -adc_linha; ac = adc_col;tone(som,459,96);dly-=5;};
     }
     
     linha += al;
     col += ac;

     if(col == 8) col = 7;
     if(col == -1) col = 0;

     setLED(linha,col,true);

     if(linha == 15) { Ponto_J2++; setup();};

     if(linha == 0) { Ponto_J1++; setup();};

     
   }
   
   cnt++;
   if(cnt == dly) cnt = 0;
}

// funções que ascendem os Leds das barras do Pong
void setLED(int linha,int coluna, boolean state)
{
    int disp=0;
    if(linha > 7) {linha = linha-8;disp=1;};
    MatrizPong.setLed(disp,linha,coluna,state); 
}

void setLED1(int linha,int coluna, boolean state)
{
    int disp=0;
    if(linha > 7) {linha = linha-8;disp=1;};
    MatrizPong.setLed(disp,linha,coluna,state); 
}

// função para apagar a barra, quando ela for movida
void setROW(int r,char ch)
{
   int disp = 0;
   if(r > 7) {r = r - 8; disp=1;};   
   MatrizPong.setRow(disp,r,ch);
}

// funções para os sons
void beep (unsigned char som, int frequencyInHertz, long timeInMilliseconds)
{ 
    int x;   
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
 
    for(linha = 0;linha<16;linha++) setROW(linha,0xFF);

    for (x=0;x<loopTime;x++)   
    {    
        digitalWrite(som,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(som,LOW);
        delayMicroseconds(delayAmount);
    }    
    
    MatrizPong.clearDisplay(0);
    MatrizPong.clearDisplay(1);    

    delay(20);
    //a little delay to make all notes sound separate
}  

  void march()
{    
    beep(som, N_a, 500); 
    beep(som, N_a, 500);     
    beep(som, N_a, 500); 
    beep(som, N_f, 350); 
    beep(som, N_cH, 150);
    
    beep(som, N_a, 500);
    beep(som, N_f, 350);
    beep(som, N_cH, 150);
    beep(som, N_a, 1000);
    //first bit
    
    beep(som, N_eH, 500);
    beep(som, N_eH, 500);
    beep(som, N_eH, 500);    
    beep(som, N_fH, 350); 
    beep(som, N_cH, 150);
    
    beep(som, N_gS, 500);
    beep(som, N_f, 350);
    beep(som, N_cH, 150);
    beep(som, N_a, 1000);
    //second bit...    
}

// funções de exibir palavras na matriz
void CopiarLetra(byte *ch,int pos)
{
    int i;
    for(i = 0;i<8;i++) *(MSG+i+(pos*8)) = *(ch+i);
}

void showMSG(int qtde,int tempo)
{
   MatrizPong.clearDisplay(0);
   MatrizPong.clearDisplay(1);

   int idx;   
   for(idx = 0; idx < 8*qtde;idx ++)
   {
      for(linha = 0;linha<16;linha++) setROW(linha,*(MSG+linha+idx));
      delay(tempo); 
   }

  MatrizPong.clearDisplay(0);
  MatrizPong.clearDisplay(1);
 
}

void mensagem_inicial()
{    
    if(INTRO_SHOWED == false)
  {
     CopiarLetra(SPACE,0);
     CopiarLetra(SPACE,1);
     
     CopiarLetra(F,2);
     CopiarLetra(A,3);
     CopiarLetra(T,4);   
     CopiarLetra(E,5);
     CopiarLetra(C,6);
     
     CopiarLetra(SPACE,7); 
     
     CopiarLetra(Z,8);
     CopiarLetra(O,9);
     CopiarLetra(N,10);
     CopiarLetra(A,11);

     CopiarLetra(S,13);
     CopiarLetra(U,14);
     CopiarLetra(L,15);

     CopiarLetra(SPACE,16);
     CopiarLetra(SPACE,17);

     showMSG(17,50); 

     INTRO_SHOWED = true;
   }     
}

// funções para quando alguém ganhar
void winner()
{
     CopiarLetra(SPACE,0);
     CopiarLetra(SPACE,1);
     
     CopiarLetra(J,2);
     CopiarLetra(a,3);

     CopiarLetra(SPACE,4);

     CopiarLetra(V,5);
     CopiarLetra(E,6);
     CopiarLetra(N,7);
     CopiarLetra(C,8);
     CopiarLetra(E,9);
     CopiarLetra(U,10);
     
     CopiarLetra(SPACE,11);
     CopiarLetra(SPACE,12);
     
     showMSG(12,80); 

     Ponto_J1 = 0;
     Ponto_J2 = 0;

     barra1 = 3;
     barra2 = 4;
     
     march();
     setup();   
}

void winner2()
{
     CopiarLetra(SPACE,0);
     CopiarLetra(SPACE,1);
     
     CopiarLetra(J,2);
     CopiarLetra(b,3);

     CopiarLetra(SPACE,4);

     CopiarLetra(V,5);
     CopiarLetra(E,6);
     CopiarLetra(N,7);
     CopiarLetra(C,8);
     CopiarLetra(E,9);
     CopiarLetra(U,10);
     
     CopiarLetra(SPACE,11);
     CopiarLetra(SPACE,12);
     
     showMSG(12,80); 

     Ponto_J1 = 0;
     Ponto_J2 = 0;

     barra1 = 3;
     barra2 = 4;
     
     march();
     setup();   
}

// função para quando perder
void loose()
{
    delay(80);
    for(linha = 0;linha<16;linha++)
    {
       setROW(linha,0xFF);
       tone(som,linha*500,100);
       delay(20);       
    } 

    delay(130);
    
    for(linha = 15;linha>=0;linha--)
    {
       setROW(linha,0x00);
       tone(som,linha*500,100);
       delay(20);       
    } 
          
}
