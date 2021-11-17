#include <Servo.h>

Servo srv;

const int max_pos = 180;
const int min_pos =   0;
const int pos_stp =   10;

int pos = 90;

void setup() {
	Serial.println("get servo position!");
	srv.attach(10);
	Serial.begin(9600);  
}

void loop() {
	if(Serial.available() > 0) {
		char ch = Serial.read();

	if     (ch == '.') {   // '>' increase pos
		if(pos + pos_stp <= max_pos) {
			pos = pos + pos_stp;
		}
		else {
			pos = max_pos;
		}
	}    
	else if(ch == ',') {   // '<' decrease pos
		if(pos - pos_stp >= min_pos) {
			pos = pos - pos_stp;
		}
		else {
			pos = min_pos;
		}
	}

	else;

	Serial.print("servo position = ");
	Serial.println(pos);
	srv.write(pos);
	}
}
