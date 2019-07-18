#include "score.h"
#include <QFont>

Score::Score(QGraphicsTextItem *parent) : QGraphicsTextItem (parent) //all custom score objects will have a parent
{
  score = 0;
  setPlainText("Score: " + QString::number(score));
  setDefaultTextColor(Qt::blue);
  setFont(QFont("helvetica", 16));
}

void Score::increase()
{
  score++;
  setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
  return score;
}
