#ifndef BUTTONSWIDGET_H
#define BUTTONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include "widget.h"

class ButtonsWidget : public QWidget
{
    Q_OBJECT

    QSlider *xAxis_sldr;
    QSlider *yAxis_sldr;
    QSlider *zAxis_sldr;
    QSlider *xAxisCamera_sldr;
    QSlider *yAxisCamera_sldr;
    QSlider *zAxisCamera_sldr;
    QSlider *materialReflection_sldr;
    QSlider *pyramidRotation_sldr;
    QSlider *scale_sldr;

    QLabel *xAxis_lbl;
    QLabel *yAxis_lbl;
    QLabel *zAxis_lbl;
    QLabel *xAxisCamera_lbl;
    QLabel *yAxisCamera_lbl;
    QLabel *zAxisCamera_lbl;
    QLabel *materialReflection_lbl;
    QLabel *pyramidRotation_lbl;
    QLabel *scale_lbl;

    QCheckBox *lighting_chbx;
    QCheckBox *pointLighting_chbx;
    QCheckBox *pyramidsMovement_chbx;
    QCheckBox *teapotTexture_chbx;
    QCheckBox *pyramidsTexture_chbx;

    QVBoxLayout *layout;

    void configureSlider(QSlider*, int, int, int, int);

public:
    ButtonsWidget(Widget *, QWidget *parent = 0);
};

#endif // BUTTONSWIDGET_H
