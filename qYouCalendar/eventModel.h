#pragma once

#include <QDate>
#include <QDateTime>
#include <QtQml>
#include <QObject>
#include <QString>
#include <QAbstractListModel>
#include "event.h"


class EventModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)
    QML_ELEMENT

public:
    EventModel(QObject *parent = nullptr);
    //Q_INVOKABLE void addEvent(QDate, int, QString, bool);
    QDate date() const;
    void setDate(const QDate &date);

    enum ContactRole {
            NameRole = Qt::UserRole,
            StartDateRole,
            EndDateRole
    };

    //QVector<Event> eventsForDate(const QDate &date);
    int rowCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

signals:
    void dateChanged();

private:
    void repopulate();
    //bool isValid() const;
    QVector<Event> m_events;
    QDate m_date;

};

