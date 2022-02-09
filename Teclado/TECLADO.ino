#include <LiquidCrystal.h>
#include <LiquidCrystal.h>
                //RS  E   D4  D5  D6  D7
LiquidCrystal lcd(24, 25, 26, 27, 28, 29);
int f1,f2,f3,f4,tecla,dato,salir,x,num=0,opera,aux,aux1;
byte x1[10]={0xC0,249,164,176,153,146,131,248,128,152};
int mil=7,cent=8,dec=9,uni=1;
int datos;
void setup() {
  lcd.begin(16,2);
  lcd.clear();//borra info lcd
  lcd.print("hola mundo");
  DDRC=0B11110000;
  PORTC=0B11111111;
  DDRB=255;PORTB=0B11111111;
  DDRK=255;
  pinMode(37,INPUT_PULLUP);
  pinMode(36,INPUT_PULLUP);
  pinMode(35,INPUT_PULLUP);
  pinMode(34,INPUT_PULLUP);
  pres();
  delay(1000);
  menu_lcd_7seg();
  
}

void loop() {
  dato=0;
  teclado();
  switch(dato){
    //***********************************************************************************
    case 1://lcd*************************************************************************
            menu_lcd();
            salir=0;
            while(salir==0){
              dato=0;
              teclado();
              if(dato==10){salir=1;}
              switch(dato){
                case 1: menu_cal_lcd();
                        salir=0;dato=16;datos=0;num=0;
                        while(salir==0){
                          teclado();
                          lcd.setCursor(0,1);
                          lcd.print(datos);
                          lcd.print("   ");
                          if(dato==15){
                            lcd.setCursor(15,1);
                            lcd.print("+");
                            opera=1;
                            aux=datos;num=0;dato=16;
                          }
                          if(dato==11){
                            lcd.setCursor(15,1);
                            lcd.print("=");
                            if(opera==1){datos=datos+aux;}
                            //-
                            //*
                            ///
                            dato=16;
                          }
                          if(dato<10){
                            num++;
                            if(num==1){datos=dato;}
                            if(num==2){datos=datos*10+dato;}
                            if(num==3){datos=datos*10+dato;}
                            if(num==4){datos=datos*10+dato;num=0;}
                            dato=16;
                          }
          
                          if (dato==10){salir=1;}
                        }
                        menu_lcd();
                        salir=0;dato=16;
                        break;

                case 2: menu_rect_7seg();//crear y cambiar por lcd
                        salir=0;dato=16;
                        while(salir==0){
                          teclado();
                          //Aquí su código
                          
                          if (dato==10){salir=1;}
                        }
                        menu_lcd();
                        salir=0;dato=16;
                        break;

                case 3: menu_trect_7seg();//crear y cambiar por lcd
                        salir=0;dato=16;
                        while(salir==0){
                          teclado();
                          //Aquí su código

                          
                          if (dato==10){salir=1;}
                        }
                        salir=0;dato=16;
                        menu_lcd();
                        break;
              }
            }
            menu_lcd_7seg();
            dato=16;
            salir=0;
            break;
            
            //**************************************************************************
    case 2://7segmentos*****************************************************************
            menu_7seg();
            salir=0;
            while(salir==0){
              dato=0;
              teclado();
              if(dato==10){salir=1;}
              switch(dato){
                case 1: menu_cal_7seg();
                        salir=0;dato=16;datos=0;num=0;
                        while(salir==0){
                          teclado();
                          separa();
                          barrido();
                          if(dato==15){
                            lcd.setCursor(15,1);
                            lcd.print("+");
                            opera=1;
                            aux=datos;num=0;dato=16;
                          }
                          if(dato==11){
                            lcd.setCursor(15,1);
                            lcd.print("=");
                            if(opera==1){datos=datos+aux;}
                            //-
                            //*
                            ///
                            dato=16;
                          }
                          if(dato<10){
                            num++;
                            if(num==1){datos=dato;}
                            if(num==2){datos=datos*10+dato;}
                            if(num==3){datos=datos*10+dato;}
                            if(num==4){datos=datos*10+dato;num=0;}
                            dato=16;
                          }
          
                          if (dato==10){salir=1;}
                        }
                        menu_7seg();
                        salir=0;dato=16;
                        break;

                case 2: menu_rect_7seg();
                        salir=0;dato=16;
                        while(salir==0){
                          teclado();
                          //Aquí su código
                          
                          if (dato==10){salir=1;}
                        }
                        menu_7seg();
                        salir=0;dato=16;
                        break;

                case 3: menu_trect_7seg();
                        salir=0;dato=16;
                        while(salir==0){
                          teclado();
                          //Aquí su código

                          
                          if (dato==10){salir=1;}
                        }
                        salir=0;dato=16;
                        menu_7seg();
                        break;
              }
            }
            menu_lcd_7seg();
            dato=16;
            salir=0;
            break;
  }
}
void menu_lcd(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("   menu LCD   ");
  lcd.setCursor(0,1);
  lcd.print("1cal 2rec 3trec"); 
}
void menu_cal_lcd(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("calculadora lcd ");
  lcd.setCursor(0,1);
  lcd.print("                ");  
}

void menu_lcd_7seg(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("     menu       ");
  lcd.setCursor(0,1);
  lcd.print("1.-lcd  2.-7seg ");  
}  
void menu_7seg(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("   menu 7seg   ");
  lcd.setCursor(0,1);
  lcd.print("1cal 2rec 3trec");  
}  
void menu_cal_7seg(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print(" calculadora    ");
  lcd.setCursor(0,1);
  lcd.print("  7segmentos    ");  
}  
void menu_rect_7seg(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("  rectangulo    ");
  lcd.setCursor(0,1);
  lcd.print(" 7segmentos     ");  
}
void menu_trect_7seg(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print(" tr rectangulo  ");
  lcd.setCursor(0,1);
  lcd.print(" 7segmentos     ");  
}

void calculadora(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("  calculadora   ");
  lcd.setCursor(0,1);
  lcd.print("                ");  
}
void contador(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("    contador    ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}
void pres(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("      info      ");
  lcd.setCursor(0,1);
  lcd.print("      info      ");
}
void menu(){
  lcd.clear();
  delay(500); 
  lcd.setCursor(0,0);
  lcd.print("   oper mat     ");
  lcd.setCursor(0,1);
  lcd.print("1.cnt 2.cal 3.pr");
}


void teclado(){
  tecla=16;
  PORTC=0B11101111;
  leer_filas();
  if(f1==0){tecla=7;}
  if(f2==0){tecla=4;}
  if(f3==0){tecla=1;}
  if(f4==0){tecla=10;}
  PORTC=0B11011111;
  leer_filas();
  if(f1==0){tecla=8;}
  if(f2==0){tecla=5;}
  if(f3==0){tecla=2;}
  if(f4==0){tecla=0;}
  PORTC=0B10111111;
  leer_filas();
  if(f1==0){tecla=9;}
  if(f2==0){tecla=6;}
  if(f3==0){tecla=3;}
  if(f4==0){tecla=11;}
  PORTC=0B01111111;
  leer_filas();
  if(f1==0){tecla=12;}
  if(f2==0){tecla=13;}
  if(f3==0){tecla=14;}
  if(f4==0){tecla=15;}
  if(tecla<16){
    dato=tecla;
    delay(300);
  }
  
}
void leer_filas(){
  f1=digitalRead(37);
  f2=digitalRead(36);
  f3=digitalRead(35);
  f4=digitalRead(34);
}
void barrido(){
  PORTB=0B11111110;
  PORTK=x1[mil];
  delay(50);
  PORTB=0B11111101;
  PORTK=x1[cent];
  delay(50);
  PORTB=0B11111011;
  PORTK=x1[dec];
  delay(50);
  PORTB=0B11110111;
  PORTK=x1[uni];
  delay(50);
  
}
void separa(){
 mil=datos/1000;
 cent=datos-mil*1000;
 aux1=cent;
 cent=cent/100;
 dec=aux1-cent*100;
 aux1=dec;
 dec=dec/10;
 uni=aux1-dec*10;
}
