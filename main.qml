import QtQuick
import volvera.de

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    color: "black"

    property int my_heading


    Vehicle {
        id : vehicle
        velocity: 0
        rpm: 0
        maxRPM: 8000
        consumption: 0
        maxConsumption: 30
        gear: 0
        maxGear: 6

        onVelocityChanged: {
            v_gauge.v = velocity;
        }
        onRpmChanged: {
            rpm_bars.rpm = vehicle.rpm;
            rpm_gauge.v = vehicle.rpm;
        }
        onConsumptionChanged: {
            consumption_gauge.rpm = vehicle.consumption
        }
        onGearChanged: {
            gear_rec.curr_gear = vehicle.gear
        }
    }


    Rectangle{
        id: gear_rec
        x: 650
        y:0
        width: 50
        height: 50
        Text {
            id: gear_rec_text
            anchors.fill: parent
            text: ""
        }

        property int max_gears: vehicle.maxGear
        property int curr_gear: vehicle.gear
        onCurr_gearChanged: {
            if (vehicle.gear === 0) gear_rec_text.text = "leer";
            else if (vehicle.gear ===-1) gear_rec_text.text = "R";
            else gear_rec_text.text = vehicle.gear;
        }
    }



    HeadingSlider{
        id: hds
        x:0
        y:0
    }


    RPM_Bar_Gauge{
        id: consumption_gauge
        x: 90
        y:0
        width: 50
        height:200;

        gWidth: width
        gHeight: height
        maxRpm: vehicle.maxConsumption
        rpm: vehicle.consumption
        displayConsumption: true
    }

    RPM_Bar_Gauge{
        id: rpm_bars
        x: 150
        y:0
        width: 50
        height:200;

        gWidth: width
        gHeight: height
        maxRpm: vehicle.maxRPM
        rpm: vehicle.rpm
        displayConsumption: false
    }


    VelocityGauge {
        id: v_gauge
        x: 220
        y: 0
        width: 200
        height: 200
        mwidth: width
        mheight: height
        v_max: 240
        v: 0

    }

    VelocityGauge {
        id: rpm_gauge
        x: 440
        y: 0
        width: 200
        height: 200
        mwidth: width
        mheight: height
        v_max: 8000
        v: 0

    }


    onMy_headingChanged: {
        hds.heading_value = my_heading;
    }





    Item {
        id: huditem
        focus: true
        Keys.onPressed: {
            if ( event.key === Qt.Key_Left )
            {
                if (mainWindow.my_heading <= 0)  mainWindow.my_heading=359;
                else mainWindow.my_heading = mainWindow.my_heading-1;
            }
            if ( event.key === Qt.Key_Right )
            {
                if (mainWindow.my_heading >= 359 ) mainWindow.my_heading=0;
                else mainWindow.my_heading = mainWindow.my_heading+1;
            }
            if ( event.key === Qt.Key_Up ) {
                vehicle.velocity += 5;
                vehicle.rpm += 200;

                //vehicle.consumption += 0.2
                //rpm_gauge.v += 200
                //consumption_gauge.rpm = consumption_gauge.rpm + 200
            }

            if ( event.key === Qt.Key_Down ) {
                vehicle.velocity -= 5;
                vehicle.rpm -= 200;

                //vehicle.consumption -= 200
                //rpm_gauge.v -= 200
                //consumption_gauge.rpm = consumption_gauge.rpm -200;
            }
            if ( event.key === Qt.Key_C ) {
                rpm_gauge.displayConsumption = !rpm_gauge.displayConsumption
            }

            if (event.key === Qt.Key_PageUp) {
                vehicle.gear += 1;
            }
            if (event.key === Qt.Key_PageDown) {
                vehicle.gear -= 1;
            }
            if (event.key === Qt.Key_R) {
                vehicle.gear=-1;
            }
            if (event.key === Qt.Key_0) {
                vehicle.gear=0;
            }
            if (event.key === Qt.Key_1) {
                vehicle.gear=1;
            }
            if (event.key === Qt.Key_2) {
                vehicle.gear=2;
            }
            if (event.key === Qt.Key_3) {
                vehicle.gear=3;
            }
            if (event.key === Qt.Key_4) {
                vehicle.gear=4;
            }
            if (event.key === Qt.Key_5) {
                vehicle.gear=5;
            }
            if (event.key === Qt.Key_6) {
                vehicle.gear=6;
            }
            if (event.key === Qt.Key_7) {
                vehicle.gear=7;
            }
            if (event.key === Qt.Key_8) {
                vehicle.gear=8;
            }
        }
    }

}




