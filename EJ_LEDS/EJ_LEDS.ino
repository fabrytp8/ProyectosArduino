
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  //------------------
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  //------------------
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void loop() {
  int p1 = digitalRead(A0);
  int p2 = digitalRead(A1);
  
  if(p1==0 && p2==0){
    parpadeo();
  }else{
      if(p1==0){
        izquierda();
      }
      if(p2==0){
        derecha();
      }
  }

}
void izquierda(){
  digitalWrite(7,HIGH);  
  digitalWrite(8,HIGH);  
  digitalWrite(9,HIGH);  
  digitalWrite(10,HIGH);  
  digitalWrite(11,HIGH);  
  delay(200);
  digitalWrite(7,LOW);  
  digitalWrite(8,LOW);  
  digitalWrite(9,LOW);  
  digitalWrite(10,LOW);  
  digitalWrite(11,LOW);  
  delay(200);
}
void derecha(){
  digitalWrite(2,HIGH);  
  digitalWrite(3,HIGH);  
  digitalWrite(4,HIGH);  
  digitalWrite(5,HIGH);  
  digitalWrite(6,HIGH);  
  delay(200);
  digitalWrite(2,LOW);  
  digitalWrite(3,LOW);  
  digitalWrite(4,LOW);  
  digitalWrite(5,LOW);  
  digitalWrite(6,LOW);  
  delay(200);
}
void parpadeo(){
  digitalWrite(2,HIGH);  
  digitalWrite(3,HIGH);  
  digitalWrite(4,HIGH);  
  digitalWrite(5,HIGH);  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);  
  digitalWrite(8,HIGH);  
  digitalWrite(9,HIGH);  
  digitalWrite(10,HIGH);  
  digitalWrite(11,HIGH);  
  delay(200);
  digitalWrite(7,LOW);  
  digitalWrite(8,LOW);  
  digitalWrite(9,LOW);  
  digitalWrite(10,LOW);  
  digitalWrite(11,LOW);  
  digitalWrite(2,LOW);  
  digitalWrite(3,LOW);  
  digitalWrite(4,LOW);  
  digitalWrite(5,LOW);  
  digitalWrite(6,LOW);    
  delay(200);
  
}
