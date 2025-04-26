# FocusWear
Mindful tech for everyday focus

FocusWear is a smart-shirt that gives you ambient, real-time feedback on your physiological state—without screens, sounds, or distracting notifications.
A tiny Pulse Sensor sewn into the shirt measures your heart rate which lights up a NeoPixel RGB LED. Colors shift from calming blues to alert reds, prompting you to stay relaxed, maintain focus, or step back before stress spikes.

## Libraries used:

PulseSensorPlayground: Reads raw PPG data from the Pulse Sensor, filters noise, and outputs a stable BPM value.

Adafruit Neopixel: Drives the single RGB LED with simple setPixelColor() calls, enabling smooth color fades and low-power operation.

## Setup instructions:

Setup instructions: how to install dependencies, connect hardware, and run the system
### 1 . Hardware 

Adafruit Flora (or any 3.3 V-logic Arduino-compatible board)

Pulse Sensor (PulseSensor.com) 

Single NeoPixel (e.g., Adafruit Flora NeoPixel v2)

3.7 V Li-Po battery (≥500 mAh) + USB-C charging module

Conductive thread & fabric-safe insulation tape

### 2 . Wiring 

- Connect Neopixel to pin 6, 3.3V, and Ground on Arduino
- Connect Pulse sensor to pin 9, 3.3V, and Ground on Arduino

### 3 . Software  

```bash
# 1 . Install libraries
Sketch → Include Library → Manage Libraries…
  • Search “PulseSensorPlayground” → Install  
  • Search “Adafruit NeoPixel”     → Install

# 2 . Select board & port
Tools → Board → Adafruit Flora  
Tools → Port  → (your USB port)

# 3 . Flash the firmware
Upload FocusWear.ino

```

## Usage instructions:
Usage instructions: how to interact with your TUI

1. Wear the shirt and lightly touch the pulse sensor with fingertip.

2. Power up – toggle the Arduino Flora on.

3. Glance-only feedback – the single NeoPixel near the sleeve edge shows your current heart-rate zone:

BPM range | LED color | Meaning
> 130 | Bright Red | Very high – take a break!
111 – 130 | Reddish-Orange | High stress
96 – 110 | Orange | Active / elevated
81 – 95 | Yellow-Orange | Focused
71 – 80 | Green | Normal
61 – 70 | Cyan | Calm
51 – 60 | Light Blue | Very calm
≤ 50 | Blue | Resting / relaxed


If you want to personalize, can switch the colors and the thresholds for different colors for the heart rate in the loop() code. 

``` bash
// Example: raise the "Focused" threshold
else if (BPM > 90) {            // was 80
    setLEDColor(255, 165, 0);   // Yellow-Orange
}
```

## Credits:
Created by Lauren Young, Tenzin Yangchen, and Tina Zhong.
Code revisions with ChatGPT. 

