import QtQuick
import QtQuick.Window
import QtQuick.Controls.Material
import QtQuick.Layouts
//import "eventModel.h"



ApplicationWindow {
    id: window
    width: 800
    height: 600
    visible: true
    title: qsTr("Hello World")
    color: "#002452"
    property date currentDate: new Date()
    property date selectedDate: new Date(currentDate)
    property int month: currentDate.getMonth()
    property int selectedMonth: currentDate.getMonth()
    property int year: currentDate.getFullYear()
    property int day: currentDate.getDate()
    property variant months: ["January","February","March","April","May","June","July","August","September","October","November","December"]
    property bool today

    header: ToolBar {
        id: toolBar
        background: Rectangle{
            color: "#b90e31"
            implicitHeight: 40
        }


        ToolButton {
            id: backButton
            text: qsTr("<")
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                if (window.month == 0) {
                    window.year-=1
                    window.month = 11
                }
                else {
                     window.month -= 1
                }
            }
        }



        Label {
            text: months[month] + " " + year
            font.pixelSize: Qt.application.font.pixelSize * 1.25
            anchors.centerIn: parent

        }
        ToolButton {
            text: qsTr(">")
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                if (window.month == 11) {
                    window.year+=1
                    window.month = 0
                }
                else {
                    window.month += 1
                }
            }
        }
    }



    Rectangle {
        id: eventRectangle
        anchors.fill: parent
        anchors.rightMargin: 2*parent.width/3
        border.color: "#ccc"
    }
    Column{
        id: eventHeader
        Rectangle{
            id: eventButtons
            width: window.width/3
            height: window.height/10
            border.color: "#000000"
            Rectangle{
                width: parent.width/2
                height: parent.height
                anchors.left: eventButtons.left
                color: "transparent"
                Button {
                    id: addEventButton
                    text: qsTr("Add event")
                    anchors.centerIn: parent
                    onClicked: addEventPopup.open()
                }
            }

            Rectangle {
                width: parent.width/2
                height: parent.height
                anchors.right: eventButtons.right
                color: "transparent"
                Button {
                    id: removeEvent
                    text: qsTr("Remove event")
                    anchors.centerIn: parent

                }
            }


        }
        Popup {
            id: addEventPopup
            width: 400
            height: 250
            closePolicy: Popup.NoAutoClose

            Column{
                TextField{
                    id: titleField
                    placeholderText: "title"
                }

                TextField{
                    id: startTime
                    placeholderText: "Start time"
                 }


                ComboBox{
                    width: 200
                    model: ["15 minutes", "30 minutes", "45 minutes", "60 minutes", "90 minutes", "120 minutes", "180 minutes"]
                }

                Row{
                    anchors.right: parent.right
                    Button{
                       id: submitButton
                       text: "Submit"
                       onClicked: {
                         if (titleField.text === ""){
                             addEventPopup.focus = true;
                          }
                         else{
                            addEventPopup.close();
                            //eventModel.addEvent(titleField.text, )
                            console.log(titleField.text);

                         }
                       }
                    }

                   Button{
                       id: cancelButton
                       text: "Cancel"
                       onClicked: addEventPopup.close()
                   }
                }
            }


        }

        Rectangle{
            id: dateEvent
            width: window.width/3
            height: window.height/10
            //anchors.topMargin: 40
            anchors.left: window.left
            border.width: 1
            border.color: "#000000"
            //color: "#fabd0f"

            Label{
                id: eventDayLabel
                //font.bold: true
                font.pixelSize: 20
                anchors.fill: parent
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.Fit
                text:  months[selectedMonth] + " " +  day + "\n Today's Events:"
                color: "#000000"
            }
        }
        Rectangle{

            width: window.width/3
            height: 9*window.height/10
            //anchors.top: dateEvent.bottom
            anchors.left: window.left
            border.width: 1.3
            border.color: "#000000"
            //color: "#002452"

            Label{
                font.pixelSize: 20
                anchors.fill: parent
                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.Fit
                text: "Nothing "
                color: "#000000"
            }
        }


    }



    GridLayout {
        anchors.fill: parent
        anchors.leftMargin: parent.width/3
        columns: 2
        //width: (parent.width > parent.height ? parent.width * 0.6 - parent.spacing : parent.width)
        //height: (parent.height > parent.width ? parent.height * 0.6 - parent.spacing : parent.height)

        DayOfWeekRow {
            id: dayOfWeekRow
            locale: grid.locale
            delegate: Label {
                text: model.shortName
                font: dayOfWeekRow.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Layout.column: 1
            Layout.fillWidth: true
        }

        WeekNumberColumn {
            month: window.month
            year: window.year
            locale: grid.locale
            font.bold: false
            Layout.fillHeight: true
        }

        MonthGrid {
            id: grid
            month: window.month
            year: window.year
            spacing: 0

            readonly property int gridLineThickness: 1

            Layout.fillWidth: true
            Layout.fillHeight: true

            delegate: Item{
                id: gridDelegate
                //height: 100
                //width: 100

                    Rectangle{
                        id: highLights
                        width: 36
                        height: 36
                        //anchors.centerIn: gridDelegate
                        color: "transparent"
                        Label {
                            id: dayText
                            //horizontalAlignment: Text.AlignHCenter
                            anchors.centerIn: parent
                            topPadding: 4
                            opacity: month === window.month ? 1 : 0.3
                            text: model.day

                            //Layout.fillWidth: true

                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                window.day = model.date.getDate() + 1
                                window.selectedMonth = model.date.getMonth()
                                window.selectedDate = model.date.addDays(1)
                                //window.selectedDate.setDate(window.selectedDate.getDate()+1)
                                //window.selectedDate.setDate(window.selectedDate.getDate()+1)
                                console.log(selectedDate.getDate())
                            }
                            cursorShape: Qt.PointingHandCursor

                        }
                    }
                 }


            background: Item {
                x: grid.leftPadding
                y: grid.topPadding
                width: grid.availableWidth
                height: grid.availableHeight

                // Vertical lines
                   Row {
                    spacing: (parent.width - (grid.gridLineThickness * rowRepeater.model)) / rowRepeater.model

                    Repeater {
                        id: rowRepeater
                        model: 7
                        delegate: Rectangle {
                            width: 1
                            height: grid.height
                            color: "#000000"
                        }
                    }
                }

                // Horizontal lines
                Column {
                    spacing: (parent.height - (grid.gridLineThickness * columnRepeater.model)) / columnRepeater.model

                    Repeater {
                        id: columnRepeater
                        model: 6
                        delegate: Rectangle {
                            width: grid.width
                            height: 1
                            color: "#000000"
                        }
                    }
                }
            }
        }
    }

}
