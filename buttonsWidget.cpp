#include "buttonsWidget.h"

void ButtonsWidget::configureSlider(QSlider *slider, int leftBound, int rightBound, int startPos, int tickInt)
{
    slider->resize(22, 300);
    slider->setRange(leftBound, rightBound);
    slider->setValue(startPos);
    slider->setTickPosition(QSlider::TicksBelow);
    slider->setTickInterval(tickInt);
}

ButtonsWidget::ButtonsWidget(Widget *openGLwidget, QWidget *parent) : QWidget(parent)
{
    setGeometry(950, 50, 300, 700);

    QFont font( "Times", 10, QFont::Bold);

    xAxis_sldr = new QSlider(Qt::Horizontal);
    yAxis_sldr = new QSlider(Qt::Horizontal);
    zAxis_sldr = new QSlider(Qt::Horizontal);
    xAxisCamera_sldr = new QSlider(Qt::Horizontal);
    yAxisCamera_sldr = new QSlider(Qt::Horizontal);
    zAxisCamera_sldr = new QSlider(Qt::Horizontal);
    materialReflection_sldr = new QSlider(Qt::Horizontal);
    pyramidRotation_sldr = new QSlider(Qt::Horizontal);
    scale_sldr = new QSlider(Qt::Horizontal);

    configureSlider(xAxis_sldr, -180, 180, 0, 45);
    configureSlider(yAxis_sldr, -180, 180, 0, 45);
    configureSlider(zAxis_sldr, -180, 180, 0, 45);
    configureSlider(xAxisCamera_sldr, -45, 45, 0, 15);
    configureSlider(yAxisCamera_sldr, -45, 45, 0, 15);
    configureSlider(zAxisCamera_sldr, -45, 45, 0, 15);
    configureSlider(materialReflection_sldr, 0, 100, 0, 10);
    configureSlider(pyramidRotation_sldr, -180, 180, 0, 45);
    configureSlider(scale_sldr, 0, 20, 5, 10);

    connect(xAxis_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getxAxisState);
    connect(yAxis_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getyAxisState);
    connect(zAxis_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getzAxisState);
    connect(xAxisCamera_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getxAxisCameraState);
    connect(yAxisCamera_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getyAxisCameraState);
    connect(zAxisCamera_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getzAxisCameraState);
    connect(materialReflection_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getMaterialReflection);
    connect(pyramidRotation_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getPyramidState);
    connect(scale_sldr, &QSlider::valueChanged, openGLwidget, &Widget::getScaleState);

    xAxis_lbl = new QLabel("Rotate scene by X axis");
    yAxis_lbl = new QLabel("Rotate scene by Y axis");
    zAxis_lbl = new QLabel("Rotate scene by Z axis");
    xAxisCamera_lbl = new QLabel("Rotate camera by X axis");
    yAxisCamera_lbl = new QLabel("Rotate camera by Y axis");
    zAxisCamera_lbl = new QLabel("Rotate camera by Z axis");
    materialReflection_lbl = new QLabel("Teapot material reflection control");
    pyramidRotation_lbl = new QLabel("Rotate pyramids");
    scale_lbl = new QLabel("Scale");
    xAxis_lbl->setFont(font);
    yAxis_lbl->setFont(font);
    zAxis_lbl->setFont(font);
    xAxisCamera_lbl->setFont(font);
    yAxisCamera_lbl->setFont(font);
    zAxisCamera_lbl->setFont(font);
    materialReflection_lbl->setFont(font);
    pyramidRotation_lbl->setFont(font);
    scale_lbl->setFont(font);

    lighting_chbx = new QCheckBox("Toggle diffuse lighting");
    pyramidsMovement_chbx = new QCheckBox("Toggle pyramids auto-rotating");
    pointLighting_chbx = new QCheckBox("Toggle point lighting");
    teapotTexture_chbx = new QCheckBox("Toggle teapot colorful texture");
    pyramidsTexture_chbx = new QCheckBox("Toggle pyramids colorful texture");
    lighting_chbx->setFont(font);
    lighting_chbx->setChecked(true);
    pointLighting_chbx->setFont(font);
    pyramidsMovement_chbx->setFont(font);
    teapotTexture_chbx->setFont(font);
    pyramidsTexture_chbx->setFont(font);
    connect(lighting_chbx, &QCheckBox::stateChanged, openGLwidget, &Widget::getLightingState);
    connect(pointLighting_chbx, &QCheckBox::stateChanged, openGLwidget, &Widget::getPointLightingState);
    connect(pyramidsMovement_chbx, &QCheckBox::stateChanged, openGLwidget, &Widget::getPyramidsMovementState);
    connect(teapotTexture_chbx, &QCheckBox::stateChanged, openGLwidget, &Widget::getTeapotTextureState);
    connect(pyramidsTexture_chbx, &QCheckBox::stateChanged, openGLwidget, &Widget::getPyramidsTextureState);

    layout = new QVBoxLayout;
    layout->addWidget(xAxis_lbl);
    layout->addWidget(xAxis_sldr);
    layout->addWidget(yAxis_lbl);
    layout->addWidget(yAxis_sldr);
    layout->addWidget(zAxis_lbl);
    layout->addWidget(zAxis_sldr);
    layout->addWidget(xAxisCamera_lbl);
    layout->addWidget(xAxisCamera_sldr);
    layout->addWidget(yAxisCamera_lbl);
    layout->addWidget(yAxisCamera_sldr);
    layout->addWidget(zAxisCamera_lbl);
    layout->addWidget(zAxisCamera_sldr);
    layout->addWidget(pyramidRotation_lbl);
    layout->addWidget(pyramidRotation_sldr);
    layout->addWidget(materialReflection_lbl);
    layout->addWidget(materialReflection_sldr);
    layout->addWidget(scale_lbl);
    layout->addWidget(scale_sldr);
    layout->addWidget(lighting_chbx);
    layout->addWidget(pointLighting_chbx);
    layout->addWidget(pyramidsMovement_chbx);
    layout->addWidget(teapotTexture_chbx);
    layout->addWidget(pyramidsTexture_chbx);
    setLayout(layout);
}
