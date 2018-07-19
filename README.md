# Weather-Station-ATtiny85

## Getting Started
The Arduino is a great micro-controller for developing your concepts into a viable prototype, as we have demonstrated time and time again at our workshops. However, moving from a prototype to a product requires something more compact. That is where the programmable ATtiny85 integrated circuit comes in. <br/>

## Prerequisites
- A Laptop
- Arduino IDE
- Basic Arduino Coding (C++)

### Components Needed
- Arduino UNO
- ATtiny 85
- DHT11 (Temprature and Humidity Sensor)
- I2C OLED Display module 
- LED 

### Setting up firmware onto the ATtiny85 using bootloader
A bootloader makes prototyping easier because the code be loaed to the microcontroller dirctly from the Arduino IDE using a basic serial connection. <br/>

**Step 1: Setup the Arduino ISP program to enable bootloader** <br/>
- Open the Sketch “ArduinoISP” from the File, Examples and ArduinoISP menus.
- Verify and upload this sketch to your Arduino <br/>
![image](https://user-images.githubusercontent.com/10446090/42948927-9d9b9774-8b81-11e8-978a-f159ba70ea36.png)
<br/>

**Step 2: Addding support compatibility for ATtiny85**  <br/>
The Arduino software does not natively support the ATtiny85 so we need to add support for it. <br/>
- Open the Preferences Dialog from the File menu.
- Put https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json into the "Additional Boards Manager URL".
- Click OK!
![image](https://user-images.githubusercontent.com/10446090/42949180-4229593e-8b82-11e8-899d-63276bce5115.png)
<br/>

**Step 3: Installing the aatiny library** <br/>
- Open the Boards Manager from the Tools, Board Menus
- Select the ATtiny from the list once the software has updated
-Search for ATtiny, either manually scrolling down the list, or typing "attiny" in the filter field.
- Click Install the (Use the latest version).

![image](https://user-images.githubusercontent.com/10446090/42949508-f2a08346-8b82-11e8-9b93-48eeb4dc88be.png)

**Step 4: Program setup** <br/>
Let’s set up the Attiny program to use the Arduino as a programmer.
- Select Arduino as ISP from the Tools, Programmer Menus
- Select ATtiny from the Tools, Board Menus
- Select ATtiny85 from the Tools, Processor Menus
- Select 8Mhz Internal from the Tools, Clock Menu

![image](https://user-images.githubusercontent.com/10446090/42949769-8ce57f7e-8b83-11e8-85ac-986186c36f8c.png)
<br/>

Now, you are ready to use your Attiny85 as a standard microcontroller.

### Circuit Diagram
![image](https://user-images.githubusercontent.com/10446090/42950593-71398e9e-8b85-11e8-92fa-d8b9241f747d.png)

- Unplug your Arduino
- Place the ATtiny Chip onto the breadboard
- Connect the ground from the Arduino to the Ground Rail
- Connect the 5V from the Arduino to pin 8 of the ATTINY
- Connect pin 4 of the chip to ground
- Place the capacitor between ground and another terminal strip (The anode of the capacitor must be connected to ground- )
- Connect the cathode of the capacitor to the Reset pin of the Arduino
- Connect a lead from the header pin 10 of the Arduino to pin 1 of the chip
- Connect Arduino Pin 11 to Pin 5 of the ATtiny85 chip
- Connect Arduino Pin 12 to Pin 6 of the ATtiny85 chip 
- Connect Arduino Pin 13 to Pin 7 of the ATtiny85 chip

### Example 
Now, Lets burn an LED blink code onto the ATtiny85 chip. <br/>
 
**Circuit Diagram** 
![image](https://user-images.githubusercontent.com/10446090/42950661-8ce47b90-8b85-11e8-9e7c-29f41d880282.png)


**Code** <br/>

- Go to File -> Example -> Basics -> Blink
- An code consists a LED blink Example
- Wherever it states "LED_BUILTIN", change it to "3" (based on the circuit diagram above we connected the led to pin number 2 of the ATtiny85 chip (ie. Analog pin3/ Digital Pin3)) <br/> 
![image](https://user-images.githubusercontent.com/10446090/42950426-0bcd7a84-8b85-11e8-9dd0-ffb247169b3e.png)
<br/>





