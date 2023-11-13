#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fun();


private slots:
    void on_play_pause_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QGridLayout *palyaelemek;
    QGridLayout *vezerloelemek;
};
#endif // MAINWINDOW_H
