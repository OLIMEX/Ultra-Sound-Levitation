// Ultra Sound Levitation soldering kit program

void setup() {
  DDRB = 0b00000011;  // D0 D1  to be outputs
  PORTB = 0b00000010;

//  Initialize Timer1
  noInterrupts();     // Disable interrupts

  TCCR1 = 0b11000001; //CTC TOGGLE NO PRESCALER
  GTCCR = 0;
  TCNT1 = 0;
  OCR1C = 204;        // Set compare register (40kHz full wave)
  TIMSK = 0b01000000; // Enable OCIE1A compare timer interrupt
  
  interrupts();       // Enable interrupts
}

ISR(TIMER1_COMPA_vect) {
  PORTB ^= 0b00000011; // Send the value of TP to the outputs
}

void loop() { 
  OCR1C=map(analogRead(A1), 0, 960, 179, 227);
}
