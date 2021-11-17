const unsigned int buzz = 12;

// 5566553055332005566553053231
// 123313565012331356506536532212355
// 532155505321666064327770554231005321555053216660643255556542105033303330351230444433332221205
//
//  c  d  e  f  g  a  b  c
//  1  2  3  4  5  6  7  8
//
const int notes[] = { 262, 294, 330, 349, 392, 440, 494, 580 };
//const char codes[] = { C,   D,   E,   F,   G,   A,   B,   C   };
const char codes[] = "CDEFGABC";
const int tempo = 100;

void setup() { 
  Serial.begin(9600);
  Serial.println(">> play music~ <<");
} 

void loop() {
  if(Serial.available() > 0)
  {
    char ch = Serial.read();

    player(ch, tempo);
  }
}

void player(char ch, int tm)
{
  if(ch >= '1' && ch <= '8')    // if(ch >= 49 && ch <= 56)
  {
    Serial.print(codes[(ch-'0')-1]);
    Serial.print(" ");
    tone (buzz, notes[(ch-'0')-1]);
    delay(tm);
  }
  else if(ch == '0')
  {
    delay(tm);
    Serial.println();
  }
  else;
  
  noTone(buzz);
}
