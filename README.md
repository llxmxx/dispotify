<h1>Dispotify</h1>

<h6>What is this? </h6>spotify diplay that shows currently playing spotify track using esp32. it says "hi [my name]" on startup, loads after authentication to the track name and artist, the progress bar is a fake, working on adding functioning buttons to the code. the spotify logo is drawn and hence looks offbrand.
<h6>Why this project? </h6>i built this project because i've wanted to get into hardware for really long now, and this one seemed fairly easy compared to the other starter projects, and it looked cute too.

<h6>3D Model: </h6>
<img width="912" height="572" alt="image" src="https://github.com/user-attachments/assets/9899726c-cad2-44c9-aadc-6425c90f528c" />
<img width="899" height="559" alt="image" src="https://github.com/user-attachments/assets/600eb169-d909-4d75-8c6d-fd35dddd7e4b" />
<img width="840" height="508" alt="image" src="https://github.com/user-attachments/assets/59654fe8-2ed5-4c05-b6e9-e55418753fa5" />

<h6>Wiring:</h6>
| TFT Pin | ESP32 Pin |
|--------|----------|
| VCC    | 3V3      |
| GND    | GND      |
| CS     | D5       |
| CLK    | D18      |
| DIN    | D23      |
| DC     | D2       |
| RST    | D4       |
| BL     | 3V3      |

<h6>BoM:</h6>
| Name | Purpose | Cost Per Item (USD) | Quantity | Total (USD) | Link | Distributor |
|------|---------|---------------------|----------|-------------|------|-------------|
| 3D Printed Case | The physical body of the spotify display | 5.18 | 1 | 5.18 | https://robu.in/product/3d-printing-service/ | Robu |
| ESP32 | its used to connect to wi-fi and fetch data from spotify | 0.00 | 1 | 0.00 | | Robu |
| 1.8" TFT Display | it displays the song currently playing along w its artist, and a basic ui | 0.00 | 1 | 0.00 | | Robu|
| Breadboard | used to connect components without soldering | 0.00 | 1 | 0.00 | | Amazon |

