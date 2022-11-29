/*#pragma once

#include <QList>
#include <QObject>
#include "event.h"

class EventModel: public QObject {

    Q_OBJECT

    public:
        EventModel();

        Q_INVOKABLE QList<QObject*> eventsForDate(const QDate &date);
        Q_INVOKABLE QObject* createEvent();
        Q_INVOKABLE void addEvent(const QString name, const QDateTime startDate, const QDateTime endDate);
        Q_INVOKABLE void removeEvent(const int id);

        void addEvent(Event &event);
        void removeEvent(Event &event);



};
*/


