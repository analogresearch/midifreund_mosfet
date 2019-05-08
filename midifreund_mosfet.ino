#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE()

byte midi_channel;
byte program;

void handler_note_on(byte channel, byte note, byte velocity)
{
  digitalWrite(13, HIGH);
  switch (note) {
    case 36:  //C2
      digitalWrite(A0, HIGH);
      break;
    case 38:
      digitalWrite(A1, HIGH);
      break;
    case 40:
      digitalWrite(A2, HIGH);
      break;
    case 41:
      digitalWrite(A3, HIGH);
      break;
    case 43:
      digitalWrite(A4, HIGH);
      break;
    case 45:
      digitalWrite(A5, HIGH);
      break;
    case 47:
      digitalWrite(9, HIGH);
      break;
    case 48:
      digitalWrite(8, HIGH);
      break;
  }
}

void handler_note_off(byte channel, byte note, byte velocity)
{
  digitalWrite(13, LOW);
  switch (note) {
    case 36:  //C2
      digitalWrite(A0, LOW);
      break;
    case 38:
      digitalWrite(A1, LOW);
      break;
    case 40:
      digitalWrite(A2, LOW);
      break;
    case 41:
      digitalWrite(A3, LOW);
      break;
    case 43:
      digitalWrite(A4, LOW);
      break;
    case 45:
      digitalWrite(A5, LOW);
      break;
    case 47:
      digitalWrite(9, LOW);
      break;
    case 48:
      digitalWrite(8, LOW);
      break;
  }
}

void set_address() { // MIDI Schalter auslesen
  midi_channel = !digitalRead(2) + (!digitalRead(3) << 1) + (!digitalRead(4) << 2 ) + (!digitalRead(5) << 3);
  if (midi_channel == 0) midi_channel = 16;
}

void set_program() { // Programmschalter auslesen
  program = !digitalRead(6) + (!digitalRead(7) << 1);
}

void setup() {

  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  set_address();
  set_program();

  MIDI.setHandleNoteOn(handler_note_on);
  MIDI.setHandleNoteOff(handler_note_off);
  MIDI.begin(midi_channel);
}

void loop() {
  MIDI.read();
}
