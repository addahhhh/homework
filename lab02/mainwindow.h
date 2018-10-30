#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include"centerframe.h"
class QLabel;//线
class QComboBox;//下拉框
class QSpinBox;//上下选择框
class QToolButton;//工具栏
class QToolBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createToolBar();
public slots:
    void penStyleChangged(int index=0);
    void penColorChangged();

private:
    CenterFrame *centerFrame;
    QLabel *styleLabel;//线形
    QComboBox *styleComboBox;//线形选择框
    QLabel *widthLabel;//线宽
    QSpinBox *widthSpinBox;//线宽微调框
    QToolButton *colorBtn;
    QToolButton *clearBtn;
    QToolButton *photoBtn;
};

#endif // MAINWINDOW_H
