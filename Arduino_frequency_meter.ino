#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);
#define pulse_ip 3
int ontime,offtime,duty;
float freq,period;
   
void setup()
{
  pinMode(pulse_ip,INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Freq:");
  lcd.setCursor(0,1); 
  lcd.print("Duty:");  
}
void loop()
{
   ontime = pulseIn(pulse_ip,HIGH);
   offtime = pulseIn(pulse_ip,LOW);
   period = ontime+offtime;
   freq = 1000000.0/period;
   duty = (ontime/period)*100; 
   if(period==0){ 
    freq=0;
    
    }
   lcd.setCursor(5,0);
   lcd.print("           ");
   lcd.setCursor(5,0);
   if(freq<1000){ 
   lcd.print(freq);
   lcd.print("Hz");
   }else if(freq>999|freq<1000000){ 
   lcd.print(freq/1000);
   lcd.print("KHz");
   }else if(freq>999999|freq<1000000000){ 
   lcd.print(freq/1000000);
   lcd.print("MHz");
   }
   lcd.setCursor(6,1);
   lcd.print("           ");
   lcd.setCursor(6,1);
   lcd.print(duty); 
   lcd.print('%'); 
   delay(1000);
}
