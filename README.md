# TNTimer
Counter-Strike LED explosive time indicator implemented using Game State Integration with C and Arduino

```
./bombtimer
usage: port
```

![Real Example](https://shane-brown.ca/img/865031b.jpg)

## Dependencies
```
arduino-serial - https://github.com/todbot/arduino-serial
json-c - https://github.com/json-c/json-c
onion - https://github.com/davidmoreno/onion
```

## Installation
* Clone repository ```git clone https://github.com/SajeOne/BombTimer/BombTimer.git```
* Install dependencies(can be done through your individual package manager. Ex. pacman, apt, dnf)
* Build project: run ```make``` in cloned directory
* Add gamestate cfg file to CSGOs config directory ```Steam/steamapps/common/Counter-Strike Global Offensive/csgo/cfg```
* Open ```ArduinoTimer``` in Arduino IDE, build and deploy to arduino
* Run the application ```./bombtimer <SERIAL_PORT> Ex. ./bombtimer /dev/ttyUSB0```
