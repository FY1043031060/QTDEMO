#ifndef QTEST_H
#define QTEST_H

#include <QObject>

class QTest : public QObject
{
    Q_OBJECT
public:
    explicit QTest(QObject *parent = 0);

signals:

public slots:
};

#endif // QTEST_H