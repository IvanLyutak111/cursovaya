#ifndef MAINWINDOW_FIRST_H
#define MAINWINDOW_FIRST_H

#include <QMainWindow>

namespace Ui {
class MainWindow_first;
}

class MainWindow_first : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_first(QWidget *parent = nullptr);
    ~MainWindow_first();
public slots:
    void go1();
    void go2();
private:
    Ui::MainWindow_first *ui;
};

#endif // MAINWINDOW_FIRST_H
