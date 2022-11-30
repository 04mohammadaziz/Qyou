#include "event.h"

Event::Event(QObject* parent): QObject(parent) {}

//Event id
QString Event::getID() const {
    return evtID;
}

void Event::setID(const QString &id) {
    if (id != evtID) {
        evtID = id;
    }
    emit idChanged(evtID);
}

//Event Name
QString Event::name() const {
    return evtName;
}

void Event::setName(const QString &name) {
    if (name != evtName) {
        evtName = name;
        emit nameChanged(evtName);
    }
}

//Event date
QDateTime Event::date() const {
    return evtDate;
}

void Event::setDate(const QDateTime &date) {
    if (date != evtDate) {
        evtDate = date;
        emit dateChanged(evtDate);
    }
}

//Event start time
QString Event::startTime() const {
    return evtStartTime;
}

void Event::setStartTime(const QString &startTime) {
    if (startTime != evtStartTime) {
        evtStartTime = startTime;
        emit startTimeChanged(evtStartTime);
    }
}

//Event end time
QString Event::endTime() const {
    return evtEndTime;
}

void Event::setEndTime(const QString &endTime) {
    if (endTime != evtEndTime) {
        evtEndTime = endTime;
        emit endTimeChanged(evtEndTime);
    }
}



