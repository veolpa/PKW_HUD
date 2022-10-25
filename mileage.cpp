#include "mileage.h"
#include "qdebug.h"

Mileage::Mileage(int p_mileage) {
    mileage = p_mileage;
    emit mileageChanged();
}

Mileage::Mileage(QString p_filename) {
    mileage_fname = p_filename;
    QFile f(mileage_fname);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "mileage file not found ! Creating it...";
        if(f.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&f);
            out << QString::number(mileage);
        } else qDebug() << "creation failed !";
    }
    f.close();
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
    else qDebug() << "file not found !";
}

Mileage::~Mileage() {
    writeMileageToFile();
}
