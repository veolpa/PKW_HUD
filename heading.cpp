#include "heading.h"

Heading::Heading(int p_heading) : heading{p_heading}
{
    emit headingChanged();
}

int  Heading::getHeading()          { return heading; }

void  Heading::setHeading(int p)    {
    heading = p;
    emit headingChanged();
}


QString Heading::to_NEWS() {
    if      (heading <= 22 )                      return QObject::tr("N");
    else if (heading <= (northeast   + 22 ))      return QObject::tr("NE");
    else if (heading <= (east        + 22 ))      return QObject::tr("E");
    else if (heading <= (southeast   + 22 ))      return QObject::tr("SE");
    else if (heading <= (south       + 22 ))      return QObject::tr("S");
    else if (heading <= (southwest   + 22 ))      return QObject::tr("SW");
    else if (heading <= (west        + 22 ))      return QObject::tr("W");
    else if (heading <= (northwest   + 22 ))      return QObject::tr("NW");
    else return QObject::tr("N");
}

//void Heading::headingChanged()
//{

//}
