# ESP8266 Remote Control

Sebuah program untuk mengendalikan mobil remot melalui WiFi AP dan dengan protokol HTTP Request.

### WiFi Configurations

```
SSID      : RC Rockcrawler King
Password  : 123456788
```

### HTTP Request

```
IP Address  : 192.168.4.1
Path        : /
Method      : GET
Query       : State
```

##### Query Functions

| Query | Description                                                         |
| ----- | ------------------------------------------------------------------- |
| F     | Fungsi untuk menggerakkan mobil remot ke depan                      |
| B     | Fungsi untuk menggerakkan mobil remot ke belakang                   |
| R     | Fungsi untuk membelokkan roda depan ke kanan                        |
| L     | Fungsi untuk membelokkan roda depan ke kiri                         |
| I     | Fungsi untuk menggerakkan roda ke depan sekaligus belok ke kanan    |
| G     | Fungsi untuk menggerakkan roda ke depan sekaligus belok ke kiri     |
| J     | Fungsi untuk menggerakkan roda ke belakang sekaligus belok ke kanan |
| H     | Fungsi untuk menggerakkan roda ke belakang sekaligus belok ke kiri  |
| S     | Stop                                                                |

### Pin

| Name    | Pin |
| ------- | --- |
| Input 1 | 14  |
| Input 2 | 12  |
| Input 3 | 13  |
| Input 4 | 15  |
