# 機械手臂分類機 

本專案為大學畢業專題作品，開發一套結合感測器與六軸機械手臂的自動分類系統。使用 ESP32 控制模組與 Raspberry Pi 網頁後台進行分類設定、資料查詢與手臂控制，模擬智慧工廠中自動搬運分類的應用場景。

## 專案介紹

- 顏色感測分類：使用 TCS3200 感測器辨識物體顏色，自動對應分類設定
- 機械手臂操作：六軸機械手臂負責搬運物體至指定區域
- 網頁後台管理：Raspberry Pi 架設後台，提供分類設定、歷史查詢、手臂微調等功能
- 無線通訊：ESP32 與 Pi 間透過 Wi-Fi 網路通訊


## 使用元件與工具

| 硬體 | 說明 |
|------|------|
| ESP32 | 控制手臂與感測器，處理資料與動作 |
| Raspberry Pi 4 | 架設網頁後台、MariaDB 與通訊管理 |
| TCS3200 | 顏色感測器 |
| PCA9685 | 伺服馬達 PWM 控制板 |
| 步進馬達 TB6600 | 控制 X 軸滑軌前後移動 |

## 成果展示



- [展示影片連結]功能一(https://youtu.be/G8WawodzkJs)功能二(https://youtu.be/M52aFezsBK4)
- [專題報告下載](https://drive.google.com/file/d/1__6PtWzh0T0ztAjbpPK73f6mYNrndXor/view?usp=sharing)
- [專題海報下載](https://drive.google.com/file/d/1JzMXmr2Y9ytDjuiVh3vep23jVI9iC1ux/view?usp=sharing)
