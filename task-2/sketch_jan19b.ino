int lightD1 = 0;
int lightD25 = 13;
int movePinD1 = 1;
int movePinD2 = 2;
int movePinD3 = 4;
int movePinD4 = 7;
int movePinD5 = 8;

int lightValue = 0;
int brightConst = 300; //контстанта освещённости
void setup() {

  pinMode (lightD1, OUTPUT);
  pinMode (lightD25, OUTPUT);
  pinMode (movePinD1, INPUT);
  pinMode (movePinD2, INPUT);
  pinMode (movePinD3, INPUT);
  pinMode (movePinD4, INPUT);
  pinMode (movePinD5, INPUT);
}
void loop() {
  lightValue = analogRead(A0);  
  movePinD1 = digitalRead(1);
  movePinD2 = digitalRead(2);
  movePinD3 = digitalRead(4);
  movePinD4 = digitalRead(7);
  movePinD5 = digitalRead(8); 

  if (lightValue < brightConst){
    // День
    if(movePinD1 == HIGH){
        digitalWrite (lightD1, HIGH); //вкл
        delay(500); //ожидание
    }
    else{
      digitalWrite (lightD1, LOW); // выкл 1 светодиод 
      digitalWrite (lightD25, LOW); // выкл 2 светодиод 
    }
  }
  else{
    // Ночь 
    if(movePinD1 == HIGH || movePinD2 == HIGH || movePinD3 == HIGH || movePinD4 == HIGH || movePinD5 == HIGH){
        digitalWrite (lightD1, HIGH); // вкл 1 этаж
        digitalWrite (lightD25, HIGH); // вкл  свет на 2-5 этажах
        delay(500); //ожидание
    }else{
        digitalWrite (lightD1, LOW); 
        digitalWrite (lightD25, LOW); 
    }
  }
}
