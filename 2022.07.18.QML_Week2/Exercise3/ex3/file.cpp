#include "file.h"

//Staff :: Staff()
//{
//    m_id = 1;
//    m_name = "Default name";
//    m_age = 69;
//    m_role = 0;
//}

//Staff :: Staff(int _id, QString _name, int _age, int _role)
//{
//    m_id = _id;
//    m_name = _name;
//    m_age = _age;
//    m_role = _role;
//}

//Staff :: Staff(const Staff& s)
//{
//    m_id = s.m_id;
//    m_name = s.m_name;
//    m_age = s.m_age;
//    m_role = s.m_role;
//}

StaffList :: StaffList(QObject * parent) : QAbstractListModel(parent)
{
    Q_UNUSED(parent);
    loadFromFile();
}

int StaffList :: rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

int StaffList::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 3;
}

//role = type of displaying data: text, color, icon, string...
QVariant StaffList :: data(const QModelIndex &index, int role) const
{
    if (!hasIndex(index.row(), index.column(), index.parent()))
        return {};

    const Staff &s = m_list.at(index.row());
    if (role == TYPE_NAME) return s.name;
    if (role == TYPE_AGE) return s.age;
    if (role == TYPE_ROLE) return s.role;
    return {};
}

bool StaffList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!hasIndex(index.row(), index.column(), index.parent()) || !value.isValid())
        return false;
    Staff &s = m_list[index.row()];
    if (role == TYPE_NAME)
        s.name = value.toString();
    else if (role == TYPE_AGE)
        s.age = value.toInt();
    else if (role == TYPE_ROLE)
        s.role = value.toInt();
    else
        return false;
    Q_EMIT dataChanged(index, index, { role } );
    return true;

}

QString StaffList :: getInfoAt(int pos, int type)
{
    return data(createIndex(pos, 0), type).toString();
}

void StaffList :: printAll()
{
    //populate();
    for(int i = 0; i < rowCount(); i++)
    {
        QString _name =  getInfoAt(i, TYPE_NAME);
        int _age = getInfoAt(i, TYPE_AGE).toInt();
        int _role = getInfoAt(i, TYPE_ROLE).toInt();
        qDebug() << _name << "\t" <<
                    _age << "\t" <<
                    _role;
    }
}


//Q_INVOKABLE

void StaffList::loadFromFile()
{
    QString val;
    QFile file;
    QDir::setCurrent("D:/Training/2022.07.18.QML_Week2/Exercise3/ex3");
    file.setFileName("staff.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonArray a = QJsonDocument::fromJson(val.toUtf8()).array();
    m_list.clear();
    qDebug() << "Update list from JSON";
    for(int i = 0; i < a.size(); i++)
    {
        QJsonValue json_val = a.at(i);
        QString _name =  json_val["name"].toString();
        int _age = json_val["age"].toInt();
        int _role = json_val["role"].toInt();

        qDebug() << _name << "\t" <<
                    _age << "\t" <<
                    _role;
        beginResetModel();
        m_list.append(Staff{_name, _age, _role});
        endResetModel();
    }

}

void StaffList::saveToFile()
{

    QJsonDocument d;
    QJsonArray a;
    int count = m_list.count();
    for(int i = 0; i < count; i++)
    {
        QString _name =  m_list[i].name;
        int _age = m_list[i].age;
        int _role = m_list[i].role;
        QJsonObject o;
        o.insert("name", _name); o.insert("age", _age); o.insert("role", _role);
        a.append(o);
    }
    d.setArray(a);

    QFile file;
    QDir::setCurrent("D:/Training/2022.07.18.QML_Week2/Exercise3/ex3");
    file.setFileName("staff.json");
    file.open(QIODevice::ReadWrite | /*QIODevice::Text |*/ QIODevice::Truncate);
    file.write(d.toJson());
    file.close();
}

QVariant StaffList :: getStaff(int pos)
{
    if(pos>=0 && pos < m_list.size())
    {
        QVariantMap item;
        item.insert("name", m_list.at(pos).name);
        item.insert("age", m_list.at(pos).age);
        item.insert("role", m_list.at(pos).role);
        return item;
    }
    else
        return {};
}

void StaffList::addStaff(QString _name, int _age, int _role)
{
    beginResetModel();
    m_list.append(Staff{_name, _age, _role});
    endResetModel();
    //saveToFile();
    Q_EMIT listChanged();
}

void StaffList::updateStaff(int pos, QString new_name, int new_age, int new_role)
{
    m_list.replace(pos, Staff{new_name, new_age, new_role});
    //saveToFile();
    Q_EMIT listChanged();
}
void StaffList::deleteStaff(int pos)
{
    m_list.removeAt(pos);
    //saveToFile();
    Q_EMIT listChanged();
}

//void StaffList :: clearAll()
//{
//    beginResetModel();
//    m_list.clear();
//    //Q_EMIT dataChanged()
//    endResetModel();
//}
