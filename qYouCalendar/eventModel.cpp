
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
            json.insert("id", QString(elements[0] + ',' + elements[1]));
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

void EventModel::removeEvent(const QString id) {
    QFile file(filename);
    QVector<QString> linesToBeReInserted;
    if (!file.open(QFile::ReadOnly  | QIODevice::Text)){
        return;
    }
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        qDebug() << line<< '\n';
        QList<QByteArray> elements = line.split(',');
        QString compare = elements[0] + "," + elements[1];
        if (compare != id){
            linesToBeReInserted.push_back(line);
        }
    }
    file.close();
    file.open(QFile::WriteOnly | QFile::Truncate | QIODevice::Text);
    QTextStream out(&file);
    for (int i = 0; i < linesToBeReInserted.size(); i++){
        out << linesToBeReInserted.at(i);
    }
}



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





