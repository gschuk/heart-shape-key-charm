// Correct ATtiny84A pin aliases for ATtinyCore
#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5   //PWM
#define PA6 6   //PWM
#define PA7 7   //PWM
#define PB2 8   //PWM
#define PB1 9
#define PB0 10
#define PB3 11

void setup() {
  // put your setup code here, to run once:
  pinMode(PA0, OUTPUT);
  pinMode(PA1, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);
  pinMode(PA4, OUTPUT);
  pinMode(PA5, OUTPUT);
  pinMode(PA6, OUTPUT);
  pinMode(PA7, OUTPUT);
  pinMode(PB0, OUTPUT);
  pinMode(PB1, OUTPUT);
  pinMode(PB2, OUTPUT);
  pinMode(PB3, OUTPUT);

  digitalWrite(PA0, LOW);
  digitalWrite(PA1, LOW);
  digitalWrite(PA2, LOW);
  digitalWrite(PA3, LOW);
  digitalWrite(PA4, LOW);
  digitalWrite(PA5, LOW);
  digitalWrite(PA6, LOW);
  digitalWrite(PA7, LOW);

  digitalWrite(PB0, LOW);
  digitalWrite(PB1, LOW);
  digitalWrite(PB2, LOW);
  digitalWrite(PB3, LOW);

  digitalWrite(PA5, HIGH); // PWM: 0 = off, 255 = full on
  digitalWrite(PA6, HIGH); // PWM: 0 = off, 255 = full on
  digitalWrite(PA7, HIGH); // PWM: 0 = off, 255 = full on
  digitalWrite(PB2, HIGH);
  digitalWrite(PB2, HIGH); // PWM: 0 = off, 255 = full on
  delay(1000);
}

void std_blink(unsigned int times = 1, unsigned int delay_twice = 500){
  digitalWrite(PA0, LOW);
  digitalWrite(PA1, LOW);
  digitalWrite(PA2, LOW);
  digitalWrite(PA3, LOW);
  digitalWrite(PA4, LOW);
  digitalWrite(PA5, LOW);
  digitalWrite(PA6, LOW);
  digitalWrite(PA7, LOW);

  digitalWrite(PB0, LOW);
  digitalWrite(PB1, LOW);
  digitalWrite(PB2, LOW);
  digitalWrite(PB3, LOW);

  for (int i = 0; i < times; i++){
    digitalWrite(PA5, HIGH); // PWM: 0 = off, 255 = full on
    digitalWrite(PA6, HIGH); // PWM: 0 = off, 255 = full on
    digitalWrite(PA7, HIGH); // PWM: 0 = off, 255 = full on
    digitalWrite(PB2, HIGH);
    digitalWrite(PB2, HIGH); // PWM: 0 = off, 255 = full on
    delay(delay_twice);
    digitalWrite(PA5, LOW); // PWM: 0 = off, 255 = full on
    digitalWrite(PA6, LOW); // PWM: 0 = off, 255 = full on
    digitalWrite(PA7, LOW); // PWM: 0 = off, 255 = full on
    digitalWrite(PB2, LOW);
    digitalWrite(PB2, LOW); // PWM: 0 = off, 255 = full on
    delay(delay_twice);
  }

}

void fade_in(unsigned int delay_each_step = 10){
  digitalWrite(PA0, LOW);
  digitalWrite(PA1, LOW);
  digitalWrite(PA2, LOW);
  digitalWrite(PA3, LOW);
  digitalWrite(PA4, LOW);
  digitalWrite(PB0, LOW);
  digitalWrite(PB1, LOW);
  digitalWrite(PB3, LOW);
  for (int value = 0; value <= 255; value++) {
    analogWrite(PA5, value); // PWM: 0 = off, 255 = full on
    analogWrite(PA6, value); // PWM: 0 = off, 255 = full on
    analogWrite(PA7, value); // PWM: 0 = off, 255 = full on
    analogWrite(PB2, value); // PWM: 0 = off, 255 = full on
    delay(delay_each_step);
  }
}

void fade_out(unsigned int delay_each_step = 10){
  digitalWrite(PA0, LOW);
  digitalWrite(PA1, LOW);
  digitalWrite(PA2, LOW);
  digitalWrite(PA3, LOW);
  digitalWrite(PA4, LOW);
  digitalWrite(PB0, LOW);
  digitalWrite(PB1, LOW);
  digitalWrite(PB3, LOW);
  for (int value = 255; value >= 0; value--) {
    analogWrite(PA5, value); // PWM: 0 = off, 255 = full on
    analogWrite(PA6, value); // PWM: 0 = off, 255 = full on
    analogWrite(PA7, value); // PWM: 0 = off, 255 = full on
    analogWrite(PB2, value); // PWM: 0 = off, 255 = full on
    delay(delay_each_step);
  }
}

void heartbeat(unsigned int times, int pwm_val){
    analogWrite(PA5, pwm_val); // PWM: 0 = off, 255 = full on
    analogWrite(PA6, pwm_val); // PWM: 0 = off, 255 = full on
    analogWrite(PA7, pwm_val); // PWM: 0 = off, 255 = full on
    analogWrite(PB2, pwm_val); // PWM: 0 = off, 255 = full on
  for(int i = 0; i < times; i++){
        digitalWrite(PA0, LOW);
        digitalWrite(PA1, LOW);
        digitalWrite(PA2, LOW);
        digitalWrite(PA3, LOW);
        digitalWrite(PA4, LOW);
        digitalWrite(PB0, LOW);
        digitalWrite(PB1, LOW);
        digitalWrite(PB3, LOW);
        delay(150);

        digitalWrite(PA0, HIGH);
        digitalWrite(PA1, HIGH);
        digitalWrite(PA2, HIGH);
        digitalWrite(PA3, HIGH);
        digitalWrite(PA4, HIGH);
        digitalWrite(PB0, HIGH);
        digitalWrite(PB1, HIGH);
        digitalWrite(PB3, HIGH);
        delay(150);
        delay(700);

        digitalWrite(PA0, LOW);
        digitalWrite(PA1, LOW);
        digitalWrite(PA2, LOW);
        digitalWrite(PA3, LOW);
        digitalWrite(PA4, LOW);
        digitalWrite(PB0, LOW);
        digitalWrite(PB1, LOW);
        digitalWrite(PB3, LOW);
        delay(150);

        digitalWrite(PA0, HIGH);
        digitalWrite(PA1, HIGH);
        digitalWrite(PA2, HIGH);
        digitalWrite(PA3, HIGH);
        digitalWrite(PA4, HIGH);
        digitalWrite(PB0, HIGH);
        digitalWrite(PB1, HIGH);
        digitalWrite(PB3, HIGH);
        delay(150);
  }
}

void ring_dimming(unsigned int delay_each_step = 10){
  int steps_per_phase = 255/3;
  digitalWrite(PA0, LOW);
  digitalWrite(PA1, HIGH);
  digitalWrite(PA2, LOW);
  digitalWrite(PA3, HIGH);
  digitalWrite(PA4, LOW);
  digitalWrite(PB0, HIGH);
  digitalWrite(PB1, HIGH);
  digitalWrite(PB3, HIGH);
  int phase1 = 0, phase2 = 255, phase3 = 255;


  phase1 = 0;
  phase2 = 255;
  phase3 = 255;
  for (int i = 0; i < 255; i++){
    analogWrite(PA7, phase1++); //phase1: rising
    analogWrite(PA6, phase2); //phase2: holding
    analogWrite(PA5, phase3--); //phase3: falling
    delay(delay_each_step);
  }

  phase1 = 0;
  phase2 = 255;
  phase3 = 255;
  digitalWrite(PB1, LOW);
  digitalWrite(PA4, HIGH);
  for (int i = 0; i < 255; i++){
    analogWrite(PB2, phase1++); //phase1: rising
    analogWrite(PA7, phase2); //phase2: holding
    analogWrite(PA6, phase3--); //phase3: falling
    delay(delay_each_step);
  }
  phase1 = 0;
  phase2 = 255;
  phase3 = 255;
  digitalWrite(PA3, LOW);
  digitalWrite(PA2, HIGH);
  for (int i = 0; i < 255; i++){
    analogWrite(PA5, phase1++); //phase1: rising
    analogWrite(PB2, phase2); //phase2: holding
    analogWrite(PA7, phase3--); //phase3: falling
    delay(delay_each_step);
  }
  phase1 = 0;
  phase2 = 255;
  phase3 = 255;
  digitalWrite(PA1, LOW);
  digitalWrite(PA0, HIGH);
  for (int i = 0; i < 255; i++){
    analogWrite(PA6, phase1++); //phase1: rising
    analogWrite(PA5, phase2); //phase2: holding
    analogWrite(PB2, phase3--); //phase3: falling
    delay(delay_each_step);
  }

  phase1 = 0;
  phase2 = 255;
  phase3 = 255;
  digitalWrite(PB0, LOW);
  digitalWrite(PB1, HIGH);
  for (int i = 0; i < 255; i++){
    analogWrite(PA7, phase1++); //phase1: rising
    analogWrite(PA6, phase2); //phase2: holding
    analogWrite(PA5, phase3--); //phase3: falling
    delay(delay_each_step);
  }

  phase1 = 0;
  phase2 = 255;
  phase3 = 255;
  digitalWrite(PA4, LOW);
  digitalWrite(PA3, HIGH);
  for (int i = 0; i < 255; i++){
    analogWrite(PA5, phase1++); //phase1: rising
    analogWrite(PA7, phase2); //phase2: holding
    analogWrite(PA6, phase3--); //phase3: falling
    delay(delay_each_step);
  }

  phase1 = 0;
  phase2 = 255;
  phase3 = 255;
  digitalWrite(PA2, LOW);
  digitalWrite(PA1, HIGH);
  for (int i = 0; i < 255; i++){
    analogWrite(PA6, phase1++); //phase1: rising
    analogWrite(PA5, phase2); //phase2: holding
    analogWrite(PA7, phase3--); //phase3: falling
    delay(delay_each_step);
  }
}

void loop() {
  std_blink(5);
  ring_dimming(1);
  ring_dimming(1);
  ring_dimming(1);
  ring_dimming(1);
  ring_dimming(1);
  ring_dimming(1);
  ring_dimming(5);
  ring_dimming(5);
  ring_dimming(5);
  ring_dimming(5);
  ring_dimming(5);
  ring_dimming(5);
  heartbeat(20, 50);
  fade_in(5);
  fade_out(5);
  fade_in();
  fade_out();
  heartbeat(20, 50);
  fade_in(1);
  fade_out(1);
  fade_in(1);
  fade_out(1);
  ring_dimming(10);
  ring_dimming(10);
  ring_dimming(10);
  heartbeat(20, 50);
}
