#include <LiquidCrystal.h> 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

char tag1[] = "2C00EE86DC98"; 
char tag2[] = "2C00FF24EC1B"; 
char tag3[] = "2C00EEB4B3C5"; 
char tag4[] = "2C00EEAC3957"; 
char tag5[] = "2C00EE988ED4"; 
char input[12];

int count = 0;
int c = 0, a = 0, b = 0, d = 0, e = 0, f = 0;

boolean flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

void setup() {
    lcd.begin(16, 2);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);

    lcd.clear();
    lcd.print(" RFID BUS ");
    delay(1000);
}

void loop() {
    lcd.clear();
    lcd.print("Place card......");
    digitalWrite(13, HIGH);
    delay(1500);
    digitalWrite(13, LOW);

    flag1 = flag2 = flag3 = flag4 = flag5 = 0;

    if (Serial.available()) {
        count = 0;
        while (Serial.available() && count < 12) {
            input[count] = Serial.read();
            count++;
            delay(5);
        }

        if (count == 12) {
            count = 0;
            flag1 = flag2 = flag3 = flag4 = flag5 = 1;

            while (count < 12 && flag1) {
                if (input[count] != tag1[count]) flag1 = 0;
                count++;
            }
            count = 0;

            while (count < 12 && flag2) {
                if (input[count] != tag2[count]) flag2 = 0;
                count++;
            }
            count = 0;

            while (count < 12 && flag3) {
                if (input[count] != tag3[count]) flag3 = 0;
                count++;
            }
            count = 0;

            while (count < 12 && flag4) {
                if (input[count] != tag4[count]) flag4 = 0;
                count++;
            }
            count = 0;

            while (count < 12 && flag5) {
                if (input[count] != tag5[count]) flag5 = 0;
                count++;
            }

            if (flag1) {
                a = 1; c++;
                lcd.clear();
                lcd.print("Bus going to");
                lcd.setCursor(0, 1);
                lcd.print("Secunderabad");
                delay(300);
                digitalWrite(8, HIGH);
                delay(1500);
                digitalWrite(8, LOW);
            } else if (flag2) {
                b = 1; c++;
                lcd.clear();
                lcd.print("Bus going to");
                lcd.setCursor(0, 1);
                lcd.print("Charminar");
                delay(300);
                digitalWrite(9, HIGH);
                delay(1500);
                digitalWrite(9, LOW);
            } else if (flag3) {
                d = 1; c++;
                lcd.clear();
                lcd.print("Bus going to");
                lcd.setCursor(0, 1);
                lcd.print("Koti");
                delay(300);
                digitalWrite(10, HIGH);
                delay(1500);
                digitalWrite(10, LOW);
            } else if (flag4) {
                e = 1; c++;
                lcd.clear();
                lcd.print("Bus going to");
                lcd.setCursor(0, 1);
                lcd.print("Uppal");
                delay(300);
                digitalWrite(11, HIGH);
                delay(1500);
                digitalWrite(11, LOW);
            } else if (flag5) {
                f = 1; c++;
                lcd.clear();
                lcd.print("Bus going to");
                lcd.setCursor(0, 1);
                lcd.print("Mehdipatnam");
                delay(300);
                digitalWrite(12, HIGH);
                delay(1500);
                digitalWrite(12, LOW);
            } else {
                lcd.clear();
                lcd.print("Invalid Card");
                delay(1500);
            }
        }
    }
}
