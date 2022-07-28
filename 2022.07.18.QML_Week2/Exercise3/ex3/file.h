#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QDebug>
#include <QQmlComponent>
#include <QQuickView>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QAbstractListModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDir>

//class Staff
//{
//    //The Q_OBJECT macro must appear in the private section of a
//    //class definition that declares its own signals and slots
//    //or that uses other services provided by Qt's meta-object system.
////    Q_OBJECT

////    //used to declare property in classes that inherit QObject
////    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
////    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
////    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
////    Q_PROPERTY(int role READ role WRITE setRole NOTIFY roleChanged)


//public:
//    enum ROLE {
//        ROLE_BA,
//        ROLE_TESTER,
//        ROLE_DEV,
//        ROLE_LEADER
//    };

//    enum COL {
//        COL_ID,
//        COL_NAME,
//        COL_AGE,
//        COL_ROLE
//    };

//    Staff();
//    Staff(int _id, QString _name, int _age, int _role);
//    Staff(const Staff &s);



//    int id() const { return m_id; }
//    void setId (int _id)
//    {
//        m_id = _id;
//        // Q_EMIT sends signal from c++ side to qml side
//        // to notify change
//        //Q_EMIT idChanged();
//    }

//    QString name() const { return m_name; }
//    void setName(QString _name)
//    {
//        m_name = _name;
//        // Q_EMIT sends signal from c++ side to qml side
//        // to notify change
//        //Q_EMIT nameChanged();
//    }

//    int age() const { return m_age; }
//    void setRole(int _age)
//    {
//        m_age = _age;
//        // Q_EMIT sends signal from c++ side to qml side
//        // to notify change
//        //Q_EMIT ageChanged();
//    }

//    int role() const { return m_role; }
//    void setAge(int _role)
//    {
//        m_role = _role;
//        // Q_EMIT sends signal from c++ side to qml side
//        // to notify change
//       // Q_EMIT roleChanged();
//    }


////public slots:


////Q_SIGNALS:
////    void idChanged();
////    void nameChanged();
////    void ageChanged();
////    void roleChanged();

//public:
//    int m_id, m_age, m_role;
//    QString m_name;
//};

struct Staff
{
    QString name;
    int age;
    int role;
};

enum INFO_TYPE
{
    TYPE_NAME = Qt::UserRole + 1,
    TYPE_AGE,
    TYPE_ROLE
};

class StaffList : public QAbstractListModel
{

    Q_OBJECT

    Q_PROPERTY(int cid READ cid WRITE setCid NOTIFY cidChanged)
    Q_PROPERTY(QList<Staff> list READ list WRITE setList NOTIFY listChanged)
public:
    StaffList(QObject * parent = 0);

    int cid() const { return m_cid; }
    void setCid (int _cid)
    {
        m_cid = _cid;
        Q_EMIT cidChanged();
    }
    QList<Staff> list() { return m_list; }
    void setList(QList<Staff> _list)
    {
        m_list = _list;
        Q_EMIT listChanged();
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    void printAll();
    void sortList();
    QString getInfoAt(int pos, int type);

    Q_INVOKABLE QVariant getStaff(int pos);
    Q_INVOKABLE void loadFromFile();
    Q_INVOKABLE void saveToFile();
    Q_INVOKABLE void addStaff(QString name, int age, int role);
    Q_INVOKABLE void updateStaff(int pos, QString new_name, int new_age, int new_role);
    Q_INVOKABLE void deleteStaff(int pos);
    //Q_INVOKABLE void clearAll();

protected:
    QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> types;
        types[TYPE_NAME] = "name";
        types[TYPE_AGE] = "age";
        types[TYPE_ROLE] = "role";
        return types;
    }

public slots:


Q_SIGNALS:
    void cidChanged();
    void listChanged();
private:
    QList<Staff> m_list;
    int m_cid;
};

#endif // FILE_H
