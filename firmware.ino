#include <Arduino.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <WiFi.h>
#include <SpotifyEsp32.h>
#include <SPI.h>

#define TFT_CS 5
#define TFT_RST 4
#define TFT_DC 2
#define TFT_SCLK 18
#define TFT_MOSI 23

char* SSID = "WIFI_SSID";
const char* PASSWORD = "WIFI_PASS";

const char* CLIENT_ID = "CLIENT_ID";
const char* CLIENT_SECRET = "CLIENT_SECRET";

Spotify sp(CLIENT_ID, CLIENT_SECRET);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

String lastTrack = "";
String lastArtist = "";

unsigned long songStartTime = 0;
int fakeDuration = 180000; // 3 mins

#define SPOTIFY_GREEN 0x07E0

void drawSpotifyLogo(int x, int y) {
    tft.fillCircle(x, y, 8, SPOTIFY_GREEN);
    tft.drawFastHLine(x - 4, y - 2, 8, ST77XX_BLACK);
    tft.drawFastHLine(x - 3, y, 6, ST77XX_BLACK);
    tft.drawFastHLine(x - 2, y + 2, 4, ST77XX_BLACK);
}

void drawControls(bool isPlaying) {
    int y = 110;

    tft.drawCircle(40, y, 10, ST77XX_WHITE);
    tft.fillTriangle(36, y, 44, y - 6, 44, y + 6, ST77XX_WHITE);

    tft.drawCircle(80, y, 10, ST77XX_WHITE);

    if (isPlaying) {
        tft.fillRect(76, y - 6, 3, 12, ST77XX_WHITE);
        tft.fillRect(82, y - 6, 3, 12, ST77XX_WHITE);
    } else {
        tft.fillTriangle(76, y - 6, 76, y + 6, 86, y, ST77XX_WHITE);
    }

    tft.drawCircle(120, y, 10, ST77XX_WHITE);
    tft.fillTriangle(124, y, 116, y - 6, 116, y + 6, ST77XX_WHITE);
}

void drawUI(String track, String artist) {
    tft.fillScreen(ST77XX_BLACK);

    drawSpotifyLogo(12, 12);

    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(1);
    tft.setCursor(35, 5);
    tft.print(track);

    tft.setTextColor(ST77XX_CYAN);
    tft.setCursor(35, 20);
    tft.print(artist);

    tft.drawRect(10, 90, 140, 5, ST77XX_WHITE);
    drawControls(sp.is_playing());

    songStartTime = millis();
}

void updateProgressBar() {
    unsigned long elapsed = millis() - songStartTime;

    if (elapsed > fakeDuration) {
        songStartTime = millis(); // reset
        elapsed = 0;
    }

    int barWidth = map(elapsed, 0, fakeDuration, 0, 140);

    tft.fillRect(10, 90, 140, 5, ST77XX_BLACK);
    tft.drawRect(10, 90, 140, 5, ST77XX_WHITE);
    tft.fillRect(10, 90, barWidth, 5, SPOTIFY_GREEN);
}

void setup() {
    Serial.begin(115200);

    tft.initR(INITR_BLACKTAB);
    tft.setRotation(1);
    tft.fillScreen(ST77XX_BLACK);

    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    tft.fillScreen(ST77XX_BLACK);
    tft.setTextColor(SPOTIFY_GREEN);
    tft.setTextSize(1);
    tft.setCursor(35, 5);
    tft.print("hii tanishkaa");

    sp.begin();
    tft.setTextColor(ST77XX_WHITE);
    tft.setCursor(35, 20);
    tft.print("Authenticate?");
    while (!sp.is_auth()) {
        sp.handle_client();
    }

    Serial.println("Authenticated");
}

void loop() {
    String track = sp.current_track_name();
    String artist = sp.current_artist_names();

    if (track != lastTrack && track != "null" && !track.isEmpty()) {
        lastTrack = track;
        lastArtist = artist;

        drawUI(track, artist);
    }
}
