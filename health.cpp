#include "health.h"
#include <QFont>

Health::Health(QGraphicsTextItem * parent) : QGraphicsTextItem (parent)
{
  health = 3;
  setPlainText("Health: " + QString::number(health));
  setDefaultTextColor(Qt::red);
  setFont(QFont("helvetica", 16));
}

void Health::decrease()
{
  health--;
  setPlainText("Health: " + QString::number(health));
}

int Health::getHealth()
{
  return health;
}
