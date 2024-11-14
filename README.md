# Bus-Identification-for-Blind-People-Using-RFID

### Introduction
This project, "RFID Bus Identification for Visually Impaired," aims to assist visually impaired individuals by using RFID technology to identify approaching buses. The system announces the bus destination information through a display and can trigger an audio response. Inspired by the research conducted in the paper "Bus Detection System for Blind People using RFID," this implementation uses Arduino and RFID modules for cost-effective and accessible deployment.

### Project Objectives
- Enable visually impaired individuals to recognize bus destinations independently.
- Use RFID tags to store unique bus information.
- Display bus destinations on an LCD screen and optionally trigger audio announcements.

### System Overview
The RFID Bus Identification system consists of two primary components:
1. **Bus Identification Subsystem**: Each bus is equipped with a unique RFID tag, representing different destinations.
2. **User Subsystem**: The user carries a portable RFID reader connected to an Arduino that detects and identifies buses in range. Upon identifying a bus, it displays the destination on an LCD screen and may activate an LED indicator.

The setup in this project includes:
- **Arduino Uno** as the microcontroller.
- **RFID Reader** (connected to the Arduino) for scanning bus tags.
- **LCD Screen** to display destination information.
- **LEDs** to indicate detection status visually.
  
### Hardware Components
- **Arduino Uno**
- **RFID Reader** (MFRC522 module or similar)
- **RFID Tags** representing different bus destinations
- **16x2 LCD Screen** for displaying bus destination
- **LED Indicators** for visual status notifications
- ### Code Explanation
The code includes logic to read RFID tags and match them to pre-defined tags representing different bus destinations:
- `tag1`, `tag2`, etc., store unique RFID codes for each bus destination.
- The `setup()` function initializes the LCD and serial communication.
- In the `loop()` function, the system checks for RFID input and displays the corresponding destination.

A snippet of the code is as follows:
```cpp
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
...
if (flag1) {
    lcd.clear();
    lcd.print("Bus going to Secunderabad");
}

#### System Design Flow

Create a simple flowchart or steps to explain the process:

```markdown
### System Workflow
1. Place the RFID reader near the bus entry point.
2. When a bus approaches, the RFID reader scans for tags.
3. If a recognized tag is detected, the system:
   - Displays the destination on the LCD.
   - Activates an LED indicator for visual feedback.
4. If no recognized tag is found, it displays an "Invalid Card" message.
### Example Output
- **Valid Tag**: Displays "Bus going to [Destination]"
- **Invalid Tag**: Displays "Invalid Card"
### Future Improvements
- Add audio announcements for each destination to aid users with complete visual impairment.
- Implement a database to store and retrieve dynamic bus schedules and routes.
- Extend the system to alert bus drivers of waiting visually impaired passengers.
#Diploma final year project..
Yalala Sudhanshu Varma , contact - 7396419841
