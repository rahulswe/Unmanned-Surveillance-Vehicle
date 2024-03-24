/**
 * MIT License
 * 
 * Copyright (c) 2024 Rahul Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <SoftwareSerial.h>

#define M1A 5
#define M1B 9
#define M2A 4
#define M2B 10

SoftwareSerial BT(3,2);

void fw();
void bw();
void left();
void right();
void stop();

void setup() 
{
    TCCR1B = (TCCR1B & 0b11111000) | 0x04;
    BT.begin(9600);
    Serial.begin(9600);
    pinMode(M1A,OUTPUT);
    pinMode(M1B,OUTPUT);
    pinMode(M2A,OUTPUT);
    pinMode(M2B,OUTPUT);
}

void loop() 
{
    if(BT.available()){
        char input = BT.read();
        Serial.println(input);

        switch (input)
        {
        case '1':
            bw();
            break;
        case '2':
            fw();
            break;
        case '3':
            left();
            break;
        case '4':
            right();
            break;
        case '0':
            stop();
            break;
        }
    }
}

void bw()
{
    digitalWrite(M1A,0);
    analogWrite(M1B,225);
    digitalWrite(M2A,0);
    analogWrite(M2B,255);
}

void fw()
{
    digitalWrite(M1A,1);
    analogWrite(M1B,(255 - 255));
    digitalWrite(M2A,0);
    analogWrite(M2B,(255 - 255));
}

void left()
{
    digitalWrite(M1A,0);
    analogWrite(M1B,100);
    digitalWrite(M2A,1);
    analogWrite(M2B,(255 - 75));
}

void right()
{
    digitalWrite(M1A,1);
    analogWrite(M1B,(255 - 75));
    digitalWrite(M2A,0);
    analogWrite(M2B,100);
}

void stop()
{
    digitalWrite(M1A,0);
    analogWrite(M1B,0);
    digitalWrite(M2A,0);
    analogWrite(M2B,0);
}