#ifndef CENTERFRAME_H
#define CENTERFRAME_H
//本类是一个窗口容器，内含左侧绘图区和右侧功能区，集中管理用户的绘图指令, 并将参数传递给DrawWidget类，使之能够正确绘图
#include <QFrame>
#include <common.h>

class QVBoxLayout;
class QHBoxLayout;
class DrawWidget;
class QGroupBox;
class QPushButton;
class QLineEdit;

class CenterFrame : public QFrame
{
    Q_OBJECT
public:
    explicit CenterFrame(QWidget *parent=0);
    DrawWidget* insideWidget() const;
protected:
    void createUserCommandArea();
    void createUI();
    void updateButtonStatus();
public slots:
    void setPenStyle(int penStyle);
    void setPenWidth(int width=1);
    void setPenColor(QColor color);
    void clearPaint();
protected slots:
    void on_btnRectClicked();
    void on_btnEllipseClicked();
    void on_btnLineClicked();
    void on_btnTriangleClicked();
    void on_btnDiamondClicked();
    void on_btnPhotoClicked();
    void on_btnTextClicked();
    void on_edtTextEdited(const QString &text);
private:
    QVBoxLayout* vLayout;
    QHBoxLayout* hLayout;
    DrawWidget* drawWidget;
    QGroupBox* group;
    QPushButton* btnRect;
    QPushButton* btnEllipse;
    QPushButton* btnLine;
    QPushButton* btnTriangle;
    QPushButton* btnDiamond;
    QPushButton* btnPhoto;
    QPushButton* btnText;
    QLineEdit* edtText;
};

#endif // CENTERFRAME_H
