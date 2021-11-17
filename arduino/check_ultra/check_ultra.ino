const int pinTrig = 4;
const int pinEcho = 5;

void setup() {
    pinMode(pinTrig, OUTPUT);
    pinMode(pinEcho, INPUT);
    Serial.begin(9600);
    Serial.println("mesure distance with HC-SR04");
}
void loop() {
    trig(); /* transmit trigger pulese */
    unsigned long echo_time = get_echoTime();
    if (echo_time != 0) {
        /*
        340(m) / 1(sec) = 2 * distance(mm) / echo_time(us)
        340,000(mm) / 1,000,000(us) = 2 * distance(mm) / echo_time(us)
        2,000,000 * distance = 340,000 * echo_time
        distance = 340,000 * echo_time / 2,000,000
        = 17 * echo_time / 100
        */
        unsigned int distance = 17 * echo_time / 100;
        Serial.print("distance = ");
        Serial.println(distance);
    }
    else Serial.println("out of range!");
    delay(200);
}

void trig(void) {
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);
}

unsigned long get_echoTime(void) {

    unsigned long echoTime = 0;

    while (digitalRead(pinEcho) == LOW);

    unsigned long startTime = micros();

    while (digitalRead(pinEcho) == HIGH);

    echoTime = micros() - startTime;
    /*
    17 * 240 / 100 = 40.8(mm), 17 * 23000 / 100 = 3910(mm)
    */
    if (echoTime >= 240 && echoTime <= 23000)
        return echoTime;
    else
        return 0;
}
