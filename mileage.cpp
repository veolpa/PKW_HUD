#include "mileage.h"

Mileage::Mileage(int p_mileage) {
    mileage = p_mileage;

//    messageDelay = new QTimer(this);
//    messageDelay->setTimerType(Qt::CoarseTimer);

    //connect (messageDelay, &QTimer::timeout, this, &Mileage::resetMessage);

    emit mileageChanged();

}

Mileage::Mileage(QString p_filename) {
    mileage_fname = p_filename;
    QFile f(mileage_fname);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        setMessage("mileage file not found ! creating it ...");;
        if(f.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&f);
            out << QString::number(mileage);
        } else setMessage("creation failed !");
    }
    f.close();
    readMileageFromFile();
}

int Mileage::getMileage() {
    return mileage;
}
void Mileage::setMileage(int p_mileage) {
    mileage = p_mileage;
    emit mileageChanged();
}
void Mileage::addMileage(int p_mileage_delta) {
    mileage += p_mileage_delta;
    emit mileageChanged();
}

QString Mileage::getMileageFName(){
    return mileage_fname;
}

void Mileage::setMileageFName(QString p_fname){
    mileage_fname = p_fname;
    emit mileageChanged();
}

void Mileage::readMileageFromFile() {
    QFile f(mileage_fname);
    QString contents{"0"};
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in( &f );
        contents = in.readLine();
        f.close();
    }
    mileage = contents.toInt();
    emit mileageChanged();
}

void Mileage::writeMileageToFile() {
    QFile f(mileage_fname);
    QString contents = QString::number(mileage);

    if (f.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out( &f );
        out << contents;
        f.close();
    }
    else setMessage("file not found !");
}

QString Mileage::getMessage() {  return info_message; }
void Mileage::setMessage(QString p) {
//    if (p =="") {
//        info_message="";
//    } else {
//        info_message = p;
//        messageDelay->start();
//    }
//    emit newMessage();
}
void Mileage::resetMessage(){

}

Mileage::~Mileage() {
    writeMileageToFile();
}
