#ifndef COMMON_H
#define COMMON_H


namespace ST {
enum ShapeType {//绘制形状的枚举变量
    None         = 0x00,      //曲线
    Line         = 0x01<<0,   //直线
    Rectangle    = 0x01<<1,   //矩型
    Ellipse      = 0x01<<2,   //圆形
    Triangle     = 0x01<<3,   //三角形
    Diamond      = 0x01<<4,   //菱形
    Text         = 0x01<<5,   //文本
    TypeMask     = 0x0f,       //mask蒙版
    Photo        =0x01<<6
};
}

#define BACKGROUND_COLOR Qt::white
#define FOREGROUND_COLOR Qt::red
#endif // COMMON_H
