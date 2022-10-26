import QtQuick

Item {
    x:0
    y:0
    width: 100
    height: 300

    Rectangle {
        //color:"transparent"
        Text{
            color:"white"
            font.family: "Courier"
            font.pointSize: 8
            text:
"Pfeil-Hoch     - Erhöhe Geschwindigkeit
                - Erhöhe Umdrehung/m
Pfeil-Runter    - Verringere Geschwindigkeit
                - Verringere Umdrehung/m
Pfeil-links     - lenke links
Pfeil-rechts    - lenke rechts
C               - switch Verbrauch/RPM -Bar
Seite-Hoch      - Gang hochschalten
Seite-Runter    - Gang runterschalten
0-6             - Gang einlegen (0 Leerlauf)
R               - Rückwertsgang/Rück-Kamera einschalten

"
        }

    }
}
