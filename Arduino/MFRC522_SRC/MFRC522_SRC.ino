#include <SPI.h>
#include "MFRC522.h"    //宣告函式庫

#define SS_PIN 10   //定義SDA腳位
#define RST_PIN 9   //定義Reset腳位
MFRC522 mfrc522(SS_PIN, RST_PIN);   // 建立物件

void setup() 
{
  Serial.begin(9600);   // 宣告序列埠及速率,用以顯示回傳資料.
  SPI.begin();          // 啟動SPI
  mfrc522.PCD_Init(); // RFID初始化
  Serial.println("Scan PICC to see UID and type...");
}

void loop() 
{
  //掃描卡片
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  //掃描到卡片時顯示卡片資訊
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
