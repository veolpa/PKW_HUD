import QtQuick
import volvera.de

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    color: "black"

    property int my_heading
    property double my_velocity

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
        maxRpm: 8000
        rpm: 650
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
        maxRpm: 8000
        rpm: 650
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


//    onMy_velocityChanged: {
//
//    }


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
                my_velocity += 5;
                v_gauge.v += 5;
                rpm_gauge.v += 200
                rpm_bars.rpm = rpm_bars.rpm + 200;
                consumption_gauge.rpm = consumption_gauge.rpm + 200
            }

            if ( event.key === Qt.Key_Down ) {
                my_velocity -= 5;
                v_gauge.v -= 5;
                rpm_gauge.v -= 200
                rpm_bars.rpm = rpm_bars.rpm-200;
                consumption_gauge.rpm = consumption_gauge.rpm -200;
            }
            if ( event.key === Qt.Key_C ) {
                rpm_gauge.displayConsumption = !rpm_gauge.displayConsumption
            }
        }
    }

}




