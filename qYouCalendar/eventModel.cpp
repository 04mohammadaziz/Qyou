#include "eventModel.h"
#include <QTextStream>
EventModel::EventModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void EventModel::setDate(const QDate &date){
    if (date == m_date)
        return;

    m_date = date;

    emit dateChanged();
}

QDate EventModel::date() const{
    return m_date;
}

int EventModel::rowCount(const QModelIndex &) const{
    return m_events.size();
}

QVariant EventModel::data(const QModelIndex &index, int role) const{
    if (!checkIndex(index, CheckIndexOption::IndexIsValid))
        return QVariant();

    switch(role) {
    case NameRole: return m_events.at(index.row()).name;
    case StartDateRole: return m_events.at(index.row()).startDate;
    case EndDateRole: return m_events.at(index.row()).endDate;
    default: return QVariant();
    }
}

QHash<int, QByteArray> EventModel::roleNames() const{
    static const QHash<int, QByteArray> roles {
        { NameRole, "name" },
        { StartDateRole, "startDate" },
        { EndDateRole, "endDate" }
    };
    return roles;
}
/*Q_INVOKABLE void EventModel::addEvent(const QDate date, int len, QString name, bool repeat){
    QFile outputFile("eventFile");
    if (outputFile.open(QFile::WriteOnly)){
        QTextStream out(&outputFile);
        out << date.toString("d,M,yyyy") << len << name << repeat << '\n';
     }
     outputFile.close();
     return;
}*/

/*QVector<Event> EventModel::eventsForDate(const QDate &date){
    QVector<Event> events;


    return events;
}*/

