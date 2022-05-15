# Setup Arduino IDE

## 1. Download Arduino IDE

- https://www.arduino.cc/en/software

## 2. Setup IDE to code on ESP8266 microcontroller

1. Open Arduino IDE
2. Click on "Arduino" (or "File" on Windows) in the toolbar
3. Click on "Preferences"
4. Set the following value in the "Additional Boards Manager URLs" input:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

5. Click on "OK"
6. Click on "Tools" in the toolbar
7. Click on "Board" -> "Boards Manager"
8. Set the following value in the search input:

```
ESP8266
```

9. Click on "Download"
10. Click on "Close"
11. Click on "Tools" in the toolbar
12. Click on "Board" -> "ESP8266 Boards (3.0.0)" -> "LOLIN(WEMOS) D1 R2 & mini"

## 3. Check that everything is OK

1. Click on "File" in the toolbar
2. Click on "Examples" -> "ESP8266" -> "Blink"
3. Click on the upload button
4. See the ESP8266's LED blink !
