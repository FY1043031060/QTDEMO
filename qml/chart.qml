import QtQuick 2.0
import QtQuick.Controls 1.0
import QtCharts 2.2

Rectangle {
//    gradient: Gradient {
//        GradientStop {
//            position: 0
//            color: "#ffffff"
//        }

//        GradientStop {
//            position: 1
//            color: "#000000"
//        }
//    }
    ChartView {
         width: 400
         height: 300
         theme: ChartView.ChartThemeBrownSand
         antialiasing: true

         PieSeries {
             id: pieSeries
             PieSlice { label: "eaten"; value: 94.9 }
             PieSlice { label: "not yet eaten"; value: 5.1 }
         }
     }
//    Button {
//        id: button1
//        x: 62
//        y: 30
//        width: 126
//        height: 36
//        text: qsTr("Button")
//    }


}
