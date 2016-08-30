#ifndef GLOBAL_H
#define GLOBAL_H
#include "qstring.h"

class Global{
protected:
   static Global * m_pInstance;
public:
   static Global * Instance();

QString getmystring();

void setmystring(const QString & val);

protected:
    QString m_mystring;

private:
    Global();

};

#endif // GLOBAL_H
