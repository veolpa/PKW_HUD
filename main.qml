import QtQuick
import volvera.de

Window {
    id: mainWindow
    width: 565
    height: 300
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
            mileage_display.cur_mileage = vehicle.mileage
        }
        onRpmChanged: {
            velocity =1;
            rpm_gauge.v  = vehicle.rpm;
        }
        onConsumptionChanged: {
            consumption_gauge.rpm = vehicle.consumption
        }
        onGearChanged: {
            gear_display.cur_gear = vehicle.gear
        }
        onMileageChanged: {
            mileage_display.cur_mileage = vehicle.mileage
        }
        onCurrentTimeChanged:{
            timeDisplay.time = currentTime;
        }
    }

    VelocityGauge {
        id: v_gauge
        x: 50
        y: 50
        width: 200
        height: 200
        mwidth: width
        mheight: height
        v_max: 240
        v: 0
        isRPM: false

    }

    TimeDisplay{
        id: timeDisplay
        x:0
        y:25
        width: mainWindow.width
        height: 20
    }

    HeadingSlider{
        id: hds
        x:mainWindow.width/2 -53
        y:46
        width:mainWindow.width
        visible: true
    }
    onMy_headingChanged: {
        hds.heading_value = my_heading;
    }



    MileageDisplay{
        id: mileage_display
        x: v_gauge.x
        y: v_gauge.y + v_gauge.height - 26
        width: 200
        height: 26
        cur_mileage: vehicle.mileage

    }


    VelocityGauge {
        id: rpm_gauge
        x: v_gauge.x+v_gauge.width+60
        y: v_gauge.y
        width: v_gauge.width
        height: v_gauge.height
        mwidth: width
        mheight: height
        v_max: 8000
        v: 0
        isRPM: true

    }

    RPM_Bar_Gauge{
        id: consumption_gauge
        x: v_gauge.x + v_gauge.width + 5
        y: v_gauge.y+15
        width: 50
        height:v_gauge.height-gear_display.height-20;

        gWidth: width
        gHeight: height
        maxRpm: vehicle.maxConsumption
        rpm: vehicle.consumption
        displayConsumption: true
    }

    GearDisplay {
        id: gear_display
        x: v_gauge.x + v_gauge.width + 5
        y: v_gauge.y+v_gauge.height-height
        width:consumption_gauge.width
        height:50

        max_gears: 6
        cur_gear: 0

    }

    RearCameraDisplay{
        id: rearCameraDisplay
        anchors.fill: parent;
    }


    Item {
        id: huditem
        focus: true
        Keys.onPressed: {
            rearCameraDisplay.is_visible=false
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
                vehicle.rpm += 200;
            }

            if ( event.key === Qt.Key_Down ) {
                vehicle.rpm -= 200;
            }


            if (event.key === Qt.Key_PageUp) {
                vehicle.gear += 1;
            }
            if (event.key === Qt.Key_PageDown) {
                vehicle.gear -= 1;
                if (vehicle.gear ===-1){
                    rearCameraDisplay.is_visible=true
                    vehicle.velocity = 0;
                    vehicle.rpm = vehicle.idleRPM
                }
            }
            if (event.key === Qt.Key_R) {
                rearCameraDisplay.is_visible=true
                vehicle.velocity = 0;
                vehicle.rpm = vehicle.idleRPM
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




