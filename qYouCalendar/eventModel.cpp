/*
#include "eventModel.h"
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>

EventModel::EventModel() {
    //createConnection();
}

QList<QObject*> EventModel::eventsForDate(const QDate &date) {

    QList<QObject*> events;

    query.prepare("SELECT * FROM Events WHERE date(:dateobj) >= date(EventStart) AND date(:dateobj) <= date(EventEnd)");
    query.bindValue(":dateobj", date.toString("yyyy-MM-dd"));

    bool x = query.exec();

    if (!x) {
        qFatal("Query execution failed");
    }

    while (query.next()) {

//        qInfo() << query.value("EventStart") << " " << query.value("EventEnd");

        Event* curevt = new Event(this);
        curevt->setID(query.value("EventID").toInt());
        curevt->setName(query.value("EventName").toString());
        curevt->setInfo(query.value("EventInformation").toString());


        QDateTime startDate, endDate, repeats;
        startDate.setDate(query.value("EventStart").toDate());
        startDate.setTime(query.value("EventStart").toDateTime().time());
        endDate.setDate(query.value("EventEnd").toDate());
        endDate.setTime(query.value("EventEnd").toDateTime().time());
        repeats.setDate(query.value("EventRepeating").toDate());
        repeats.setTime(query.value("EventRepeating").toDateTime().time());

//        qInfo() << query.value("EventEnd") << query.value("EventEnd").toDate() << query.value("EventEnd").toDateTime().time();

        curevt->setStartDate(startDate);
        curevt->setEndDate(endDate);


        events.append(curevt);
    }

//    qInfo() << "Finished searching events" << " " << events;

    return events;
}

QObject* EventModel::createEvent() {
    Event* event = new Event();
    return event;
}


void EventModel::addEvent(Event &event) {

    QSqlQuery query;
    query.prepare("INSERT INTO Events (EventName, EventInformation, EventStart, EventEnd, EventRepeating) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(event.name());

    query.addBindValue(event.startDate().toString("yyyy-MM-dd HH:mm:ss"));
    query.addBindValue(event.endDate().toString("yyyy-MM-dd HH:mm:ss"));


    qInfo() << "::: Adding event";

    bool b = query.exec();
    qInfo() << query.executedQuery();

    if (!b) {
        qFatal("Insert failed");
    } else {

        qInfo() << "::: Data insert";
    }

}

void EventModel::removeEvent(Event &event) {

    QSqlQuery query;
    query.prepare("DELETE FROM Events WHERE EventID == :id");
    query.bindValue(":id", event.getID());

    if (!query.exec()) {
        qFatal("Delete failed");
    }
}



void EventModel::addEvent(const QString name, const QDateTime startDate, const QDateTime endDate) {
    Event evt;
    evt.setName(name);
    evt.setStartDate(startDate);
    evt.setEndDate(endDate);
    addEvent(evt);
}

void EventModel::removeEvent(const int id) {
    Event evt;
    evt.setID(id);
    removeEvent(evt);
}


*/
