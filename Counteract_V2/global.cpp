#include "global.h"
#include "qstring.h"

Global * Global::m_pInstance = NULL;
Global * Global::Instance(){
    if(!m_pInstance){
        m_pInstance = new Global();
    }
    return m_pInstance;
}

Global::Global(){

}
QString Global::getmystring(){
    return m_mystring;
}
void Global::setmystring(const QString & str){
    m_mystring = str;
}

