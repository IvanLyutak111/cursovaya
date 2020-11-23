#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
public slots:
    void assign();
    void download();
    void load();
private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
