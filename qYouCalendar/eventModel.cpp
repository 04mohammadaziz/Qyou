
#include "eventModel.h"
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QJsonObject>

EventModel::EventModel() {
    //createConnection();
}

QVariantList EventModel::eventsForDate(const QDateTime &date) {
    QVariantList events;
    QString compareDate = date.toString("dd.MM.yyyy");
    QFile in(filename);
    if (!in.open(QFile::ReadOnly | QIODevice::Text)){
        return events;
    }
    while (!in.atEnd()) {

        QByteArray line = in.readLine();
        QList<QByteArray> elements = line.split(',');
        if (elements[0] == compareDate){
            QJsonObject json;
            json.insert("name",  QString(elements[1]));
            json.insert("startTime",  QString(elements[2]));
            json.insert("endTime", QString(elements[3]));
            events.append(json);

        }
    }


//    qInfo() << "Finished searching events" << " " << events;
//    for (int i = 0; i < events.length(); i++){
 //       qDebug() << (events[i].name());
  //  }
    return events;
}

QObject* EventModel::createEvent() {
    Event* event = new Event();
    return event;
}


void EventModel::addEvent(Event &event) {
    QFile file(filename);
    if (!file.open(QFile::Append | QIODevice::Text)){
        return;
    }
    QTextStream out(&file);
    out << event.getID() << ',' << event.startTime() << ',' << event.endTime() << '\n';
    qDebug() << event.getID()  << ',' << event.startTime() << ',' << event.endTime()  << '\n';
    file.close();
}
/*
void EventModel::removeEvent(Event &event) {

    QSqlQuery query;
    query.prepare("DELETE FROM Events WHERE EventID == :id");
    query.bindValue(":id", event.getID());

    if (!query.exec()) {
        qFatal("Delete failed");
    }
}
*/


void EventModel::addEvent(const QString name, const QDateTime date, const QString startTime, const QString endTime) {
    Event evt;
    QString id = date.toString("dd.MM.yyyy") + "," + name;
    evt.setID(id);
    evt.setName(name);
    evt.setDate(date);
    evt.setStartTime(startTime);
    evt.setEndTime(endTime);
    addEvent(evt);
}
/*
void EventModel::removeEvent(const int id) {
    Event evt;
    evt.setID(id);
    removeEvent(evt);
}
*/


