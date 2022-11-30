#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QList>
#include <QObject>
#include "event.h"

class EventModel: public QObject {

    Q_OBJECT

    public:
        EventModel();

        Q_INVOKABLE QVariantList eventsForDate(const QDateTime &date);
        Q_INVOKABLE QObject* createEvent();
        Q_INVOKABLE void addEvent(const QString name, const QDateTime date, const QString startTime, const QString endTime);

       Q_INVOKABLE void removeEvent(const QString id);

        void addEvent(Event &event);

    private:
        QString filename = "EventList.txt";

};

#endif

