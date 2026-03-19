spotify diplay that shows currently playing spotify track using esp32, says "hi [my name]" on startup, working on adding buttons to the code.
i built this project because i've wanted to get into hardware for really long now, and this one seemed fairly easy compared to the other starter projects, and it looked cute too.

<img width="912" height="572" alt="image" src="https://github.com/user-attachments/assets/9899726c-cad2-44c9-aadc-6425c90f528c" />
<img width="899" height="559" alt="image" src="https://github.com/user-attachments/assets/600eb169-d909-4d75-8c6d-fd35dddd7e4b" />
<img width="840" height="508" alt="image" src="https://github.com/user-attachments/assets/59654fe8-2ed5-4c05-b6e9-e55418753fa5" />

Wiring:
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

BOM:
| Name              | Purpose                                  | Cost Per Item (USD) | Quantity | Total (USD) | Link                                              | Distributor |
|-------------------|------------------------------------------|---------------------|----------|-------------|---------------------------------------------------|-------------|
| 3D Printed Case   | The physical body of the Spotify display | 5.26                | 1        | 5.26        | https://robu.in/product/3d-printing-service/      | Robu        |
