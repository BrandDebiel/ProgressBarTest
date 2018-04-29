#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer intervalTimer;

public slots:
    void changeProgressbar();
    void startTheTimer();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
