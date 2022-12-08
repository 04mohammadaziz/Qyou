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
    title: qsTr("qYou Calendar")
    color: "#002452"
    property date currentDate: new Date()
    property date selectedDate: new Date(currentDate)
    property int month: currentDate.getMonth()
    property int selectedMonth: currentDate.getMonth()
    property int year: currentDate.getFullYear()
    property int day: currentDate.getDate()
    property var val
    property string startTime
    property string endTime
    property string events: "No events for today"
    property string deleteEvents
    property variant months: ["January","February","March","April","May","June","July","August","September","October","November","December"]
    property bool today

    function formatText(count, modelData) {
        var data = modelData;
        return data.toString().length < 2 ? "0" + data : data;
    }

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
                    onClicked: {
                        if (val[0] !== undefined){
                            deleteEventPopup.open();
                        }
                        else {
                            deleteEventDialog.open()
                        }
                    }
                }
            }
        }
        Dialog {
            id: deleteEventDialog
            title: "No event exists for this date"
            modal: true
            standardButtons: Dialog.Ok
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

                Row{

                    Tumbler {
                        id: startHourTumbler
                        model: 24
                        height: 50
                        visibleItemCount: 3
                        delegate: Text{
                            text: formatText(Tumbler.tumbler.count, modelData)
                            color: startHourTumbler.visualFocus ? startHourTumbler.palette.highlight : startHourTumbler.palette.text
                            font: startHourTumbler.font
                            opacity: 1.0 - Math.abs(Tumbler.displacement) / (startHourTumbler.visibleItemCount / 2)
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                    Tumbler {
                        id: startMinuteTumbler
                        model: 60
                        height: 50
                        visibleItemCount: 3
                        delegate: Text{
                            text: formatText(Tumbler.tumbler.count, modelData)
                            color: startMinuteTumbler.visualFocus ? startMinuteTumbler.palette.highlight : startMinuteTumbler.palette.text
                            font: startMinuteTumbler.font
                            opacity: 1.0 - Math.abs(Tumbler.displacement) / (startMinuteTumbler.visibleItemCount / 2)
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                    Label{
                        anchors.topMargin: 30
                        verticalAlignment: Text.AlignVCenter
                        text: " to "
                    }

                    Tumbler {
                        id: endHourTumbler
                        model: 24
                        height: 50
                        visibleItemCount: 3
                        delegate: Text{
                            text: formatText(Tumbler.tumbler.count, modelData)
                            color: endHourTumbler.visualFocus ? endHourTumbler.palette.highlight : endHourTumbler.palette.text
                            font: endHourTumbler.font
                            opacity: 1.0 - Math.abs(Tumbler.displacement) / (endHourTumbler.visibleItemCount / 2)
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                    Tumbler {
                        id: endMinuteTumbler
                        model: 60
                        height: 50
                        visibleItemCount: 3
                        delegate: Text{
                            text: formatText(Tumbler.tumbler.count, modelData)
                            color: endMinuteTumbler.visualFocus ? endMinuteTumbler.palette.highlight : endMinuteTumbler.palette.text
                            font: endMinuteTumbler.font
                            opacity: 1.0 - Math.abs(Tumbler.displacement) / (endMinuteTumbler.visibleItemCount / 2)
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
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

                            var startHour = startHourTumbler.currentIndex.toString().length < 2 ? "0" + startHourTumbler.currentIndex : startHourTumbler.currentIndex;
                            var startMinute = startMinuteTumbler.currentIndex.toString().length < 2 ? "0" + startMinuteTumbler.currentIndex : startMinuteTumbler.currentIndex;
                            var endHour = endHourTumbler.currentIndex.toString().length < 2 ? "0" + endHourTumbler.currentIndex : endHourTumbler.currentIndex;
                            var endMinute = endMinuteTumbler.currentIndex.toString().length < 2 ? "0" + endMinuteTumbler.currentIndex : endMinuteTumbler.currentIndex;
                            startTime = startHour + ":" + startMinute;
                            endTime = endHour + ":" + endMinute;
                            eventModel.addEvent(titleField.text, selectedDate, startTime, endTime);
                             titleField.text === "";
                            //console.log(titleField.text);

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

        Popup {
            id: deleteEventPopup
            width: 400
            height: 250
            closePolicy: Popup.NoAutoClose



            Column{
                Label{
                    id: deleteEventsLabel
                    text: events + "Select a number to delete : "
                }

                TextField{
                    id: removeEventField
                    placeholderText: "Number"
                }

                Row{
                    anchors.right: parent.right
                    Button{
                       id: deleteButton
                       text: "Delete item"
                       onClicked: {
                         if (removeEventField.text === ""){
                             deleteEventPopup.focus = true;
                          }
                         else{
                            deleteEventPopup.close();
                            let remove = removeEventField.text -1;
                            //console.log(remove);
                            //console.log(window.val[0].id);
                            eventModel.removeEvent(val[remove].id);
                         }
                       }
                    }

                   Button{
                       id: cancelDeleteButton
                       text: "Cancel"
                       onClicked: deleteEventPopup.close()
                   }
                }
            }


        }

        Rectangle{
            id: dateEvent
            width: window.width/3
            height: window.height/15
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
                text:  months[selectedMonth] + " " + day
                color: "#000000"
            }
        }
        /*
        Rectangle{
            width: window.width/3
            height: window.height/15
            //anchors.topMargin: 40
            anchors.left: window.left
            border.width: 1
            border.color: "#000000"
            Label{
                //font.bold: true
                font.pixelSize: 20
                anchors.fill: parent
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.Fit
                text:  "Today's events:"
                color: "#000000"
            }
        }
        */
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
                text: "Today's events: \n" +events
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
		color: "#FFFFFF"
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
            delegate: Text{
                color: "#002452"
            }
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
                            color: "#FFFFFF"
                            //Layout.fillWidth: true

                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                window.selectedDate = new Date(model.date.setDate(model.date.getDate()+1))
                                window.day = window.selectedDate.getDate()
                                selectedMonth = window.selectedDate.getMonth()
                                val = eventModel.eventsForDate(selectedDate)
                                events = "";
                                if (val[0] !== undefined){
                                    for (let i = 0; i < val.length; i++){
                                        //console.log(i+1);
                                        events += (parseInt(i, 10)+1  + " " + val[i].name + " " + val[i].startTime + " " + val[i].endTime);
                                    }
                                }
                                else {
                                    events = "No events for today"
                                }


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
