# Memory Game
## Description
An arduino minigame where the player has to memorize sequences increasing in length. The sequence will be first shown by the board by lighting up bulbs in order. Then the player will have to press the corresponding buttons. If the player pressed the correct sequence, then the game continues by updating the sequence with another bulb, thus reentering the game loop. 

The bulbs come in 3 different colors (red, yellow and green).

## Schematics
![Image](https://github.com/user-attachments/assets/74390ece-9bb7-4e7b-9909-78910c5a2e94)

## Pre-requisites
- Uno R3 board https://docs.arduino.cc/hardware/uno-rev3/ (with USB cable)
- full-size breadboard
- 3 push-down buttons [https://theorycircuit.com/arduino-projects/simple-arduino-push-button-switch-tutorial/] [https://www.aliexpress.com/item/4001361256214.html?src=google&pdp_npi=4%40dis!RON!27.67!26.78!!!!!%40!12000029333287871!ppc!!!&src=google&albch=shopping&acnt=298-731-3000&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&&albagn=888888&&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=en4001361256214&ds_e_product_merchant_id=106342227&ds_e_product_country=RO&ds_e_product_language=en&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=21564641029&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=CjwKCAjw5PK_BhBBEiwAL7GTPe5nNFOblzIyBQH3hhpK0cfZYikYPT9T8fezfGwRWJzO866YIyScWxoC6K8QAvD_BwE]
- wires(15 male-to-male) [https://www.yamanelectronics.com/types-of-jumper-wires/] [https://sigmanortec.ro/40-Fire-Dupont-20cm-Tata-Tata-p210851325?SubmitCurrency=1&id_currency=2&gad_source=1&gclid=CjwKCAjw5PK_BhBBEiwAL7GTPcDj8u5V5EtAaPcDHJX4pWdJVPvcnfAqNqh6IfUKo4gw64JH1q4K1xoChPsQAvD_BwE]
- 3 220 ohm resistors [https://protosupplies.com/product/resistor-220-5/]
- 3 leds (preferably red yellow and green) [https://www.tme.eu/ro/details/l-53id/led-uri-tht-rotunde/kingbright-electronic/?brutto=1&currency=RON&utm_source=google&utm_medium=cpc&utm_campaign=RUMUNIA%20[PLA]%20CSS&gad_source=1&gclid=CjwKCAjw5PK_BhBBEiwAL7GTPZWPG0DPEeJqIAdMkB7nMUWyMTqz53punxL3gw_bmMHYNopd09E7NxoCIxMQAvD_BwE]


## 🛠️ Set-up and Build
###  Components and Wiring

- **Buttons (x4):**
  - Connect one side of each button to **digital pins 2, 3, 4** (one pin per button).
  - Connect the other side of each button to the **GND rail** on the breadboard.

- **LEDS:**
  - Connect the **anode** to **a resistor** and then to **a pin** (10 for green, 11 for yellow, 12 for red, the order is not mandatory).
  - Connect the **catode** to the **GND rail** on the breadboard.

> ✅ The breadboard's power rails are connected to the Arduino's **5V** and **GND** pins to supply power to all components properly.
While more complicated to wire, having the bulbs close to their respective buttons is encouraged.
### We do not use any additional libraries. 

Write the code in this repo into the standard Arduino IDE (https://www.arduino.cc/en/software), verify it and connect the board.
## ▶️ Running
Upload the program to the Arduino UNO. The mini-game starts by itself.

### 1.  Sequence
- The first sequence consists of a single led
- All the leds appearing in the sequence will be lit up in order
- After passing each level, the sequence extends with another random led

### 2. User input
- The user has to press the buttons in the order specified by the leds
- For example, if the red led lights up then the user will have to press the button closest to the red led
- Correctly reproducing the sequence automatically sends the user to the next level
- Making a mistake ends the game 

### 3. Game over
- All leds light up simultaneously 3 times
- The game restarts from a sequence of length 1



