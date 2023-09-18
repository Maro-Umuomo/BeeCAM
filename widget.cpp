#include "widget.h"
#include "ui_widget.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <DuLibVlcWrapper.h>
#include <thread>

using namespace DuarteCorporation;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4)"));
    mMediaPlayer1 = new DuLibVlcWrapper(this);
    mMediaPlayer2 = new DuLibVlcWrapper(this);

    //QString cam1File = "qrc:/sdp/CAM1.sdp";
    //QString cam2File = "qrc:/sdp/CAM2.sdp";
    //QString cam1File = "qrc:/sdp/metapreview.mp4";
    //QString cam2File = "qrc:/sdp/metapreview.mp4";

    QString cam1File = "C:/Users/OUmu/Downloads/CodeBase/Qt/BeeCam3/sdp/metapreview.mp4";//CAM1.sdp";
    QString cam2File = "C:/Users/OUmu/Downloads/CodeBase/Qt/BeeCam3/sdp/metapreview.mp4";//CAM1.sdp";


    //QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files(.mp4"));

    mVideoWidget1 = new QVideoWidget(this);
    mVideoWidget2 = new QVideoWidget(this);

    mVideoWidget1->setGeometry(5, 14, ui->cam1->width() - 20, ui->cam1->height() - 20);
    mVideoWidget2->setGeometry(5, 14, ui->cam2->width() - 20, ui->cam2->height() - 20);

    mVideoWidget1->setParent(ui->cam1);
    mVideoWidget2->setParent(ui->cam2);

    mMediaPlayer1->setVideoOutput(mVideoWidget1);
    mMediaPlayer2->setVideoOutput(mVideoWidget2);

    auto L = static_cast<QHBoxLayout *>(layout());
    L->insertWidget(0, mVideoWidget1);
    L->insertWidget(1, mVideoWidget2);

    mMediaPlayer1->setMedia(QUrl::fromLocalFile(cam1File));
    mMediaPlayer2->setMedia(QUrl::fromLocalFile(cam2File));

    mMediaPlayer1->play();
    mMediaPlayer2->play();

    for (int i = 0; i < 7; ++i)
    {
        qDebug() << "Is Media1 playing?:" << mMediaPlayer1->isPlaying();
        qDebug() << "Is Media2 playing?:" << mMediaPlayer2->isPlaying();

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}

Widget::~Widget()
{
    delete ui;
}

