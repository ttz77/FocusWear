#include <PulseSensorPlayground.h>
#include <Adafruit_NeoPixel.h>

#define PULSE_SENSOR_PIN 9   // Pulse Sensor
#define LED_PIN 6            // LED Pin connected to Flora NeoPixel
#define NUM_LEDS 1           // Only one NeoPixel

PulseSensorPlayground pulseSensor;
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int Threshold = 980;   // Adjust this based on readings

void setup() {
   Serial.begin(9600);
   pulseSensor.analogInput(PULSE_SENSOR_PIN);
   pulseSensor.setThreshold(Threshold);
   pulseSensor.begin();

   strip.begin();
   strip.show(); // Initialize the NeoPixel to 'off'
}

unsigned long lastBeatTime = 0; // time of the last beat
const unsigned long beatTimeout = 2000; // 2 seconds

void loop() {
   int BPM = pulseSensor.getBeatsPerMinute();

   if (pulseSensor.sawStartOfBeat()) {
       lastBeatTime = millis(); // update last beat time
       Serial.print("BPM: ");
       Serial.println(BPM);

       // Expanded color range based on BPM
       if (BPM > 130) {
           setLEDColor(255, 0, 0);       // Bright Red - Very high BPM
       }
       else if (BPM > 110) {
           setLEDColor(255, 50, 0);      // Reddish Orange - High BPM
       }
       else if (BPM > 95) {
           setLEDColor(255, 100, 0);     // Orange - Active
       }
       else if (BPM > 80) {
           setLEDColor(255, 165, 0);     // Yellowish Orange - Focused
       }
       else if (BPM > 70) {
           setLEDColor(0, 255, 0);       // Green - Normal
       }
       else if (BPM > 60) {
           setLEDColor(0, 255, 255);     // Cyan - Calm
       }
       else if (BPM > 50) {
           setLEDColor(0, 128, 255);     // Light Blue - Very calm
       }
       else {
           setLEDColor(0, 0, 255);       // Blue - Resting/Very relaxed
       }
   }

   // Check if it's been too long since last beat
   if (millis() - lastBeatTime > beatTimeout) {
       setLEDColor(0, 0, 0); // Turn off LED
   }

   delay(20);
}

// Function to set LED color
void setLEDColor(int r, int g, int b) {
   strip.setPixelColor(0, strip.Color(r, g, b));  // Set color for the single NeoPixel
   strip.show();
}
