# RFID Bus Identification for Visually Impaired

### Introduction
This project, **"RFID Bus Identification for Visually Impaired,"** is a simple, Arduino-based RFID system that identifies bus destinations to assist visually impaired individuals. The system detects RFID tags on buses, displays bus destination information on an LCD, and provides visual feedback with LEDs for easy identification.

### Project Objectives
- Enable visually impaired individuals to identify bus destinations independently.
- Use RFID tags for bus identification and display corresponding information on an LCD screen.
- Provide LED indicators for visual confirmation of bus detection.

### System Overview
The RFID Bus Identification system is built to offer easy deployment and use:
1. **Bus Identification Subsystem**: Each bus has a unique RFID tag representing a specific destination.
2. **User Subsystem**: A portable RFID reader connected to an Arduino identifies and displays bus destinations on an LCD screen.

#### Hardware Components
- **Arduino Uno**
- **RFID Reader** (e.g., MFRC522 or similar)
- **RFID Tags** for buses
- **16x2 LCD Screen** for displaying destination information
- **LED Indicators** for visual feedback on detection

### Code Explanation
The code includes logic to read RFID tags and match them to pre-defined tags representing different bus destinations:
- `tag1`, `tag2`, etc., store unique RFID codes for each bus destination.
- The `setup()` function initializes the LCD and sets up serial communication and LED pins.
- In the `loop()` function, the system checks for RFID input, matches it to stored tags, and displays the corresponding destination on the LCD.

#### Code Snippet
Here’s a snippet of the code:
```cpp
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Predefined RFID tags and destinations
char tag1[] = "2C00EE86DC98"; 
char tag2[] = "2C00FF24EC1B"; 
// Additional tags...

void setup() {
    lcd.begin(16, 2);
    Serial.begin(9600);
    pinMode(8, OUTPUT); // LED for Bus 1
    pinMode(9, OUTPUT); // LED for Bus 2
    // Additional pins...
}

void loop() {
    lcd.clear();
    lcd.print("Place card......");
    if (Serial.available()) {
        // Read RFID tag and match with predefined tags
        if (matchTag(input, tag1)) {
            lcd.clear();
            lcd.print("Bus going to Secunderabad");
            digitalWrite(8, HIGH); // Activate LED
        }
        // Additional tag checks...
    }
}
### System Workflow
1. **Tag Detection**: The RFID reader scans for bus tags.
2. **Match Verification**: The system matches the scanned tag with predefined tag IDs.
3. **Output Display**: Upon a match:
   - The destination displays on the LCD.
   - The corresponding LED lights up to indicate detection.
4. **Invalid Tag Handling**: If no match is found, it displays "Invalid Card."

### Example Output
- **Valid Tag**: Displays "Bus going to [Destination]" and activates the corresponding LED.
- **Invalid Tag**: Displays "Invalid Card."

### Future Improvements
- **Audio Announcements**: Implement audio output for detected destinations.
- **Dynamic Updates**: Integrate a database to update bus schedules and routes.
- **Driver Alerts**: Notify drivers of visually impaired passengers waiting at the station.

### References
YALALA SUDHANSHU VARMA
### contact
7396419841
