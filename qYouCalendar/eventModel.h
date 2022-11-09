/*#pragma once

#include <QDate>
#include <QDateTime>
#include <QtQml>
#include <QObject>
#include <QString>

#include "event.h"


class EventModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)
    QML_ELEMENT

public:
    EventModel(QObject *parent = nullptr);

    QDate date() const;
    void setDate(const QDate &date);

    QHash<QString, int> hash;
signals:
    void dateChanged();

private:

};*/
