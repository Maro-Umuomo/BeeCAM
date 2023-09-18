#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QMediaPlayer;
class QVideoWidget;

namespace DuarteCorporation
{
class DuLibVlcWrapper;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    //QMediaPlayer* mMediaPlayer1;
    //QMediaPlayer* mMediaPlayer2;
    QVideoWidget* mVideoWidget1;
    QVideoWidget* mVideoWidget2;
    DuarteCorporation::DuLibVlcWrapper* mMediaPlayer1;
    DuarteCorporation::DuLibVlcWrapper* mMediaPlayer2;

};
#endif // WIDGET_H
