#ifndef CUSTOMWIDGET_SHOE_WIDGET_1080_HPP
#define CUSTOMWIDGET_SHOE_WIDGET_1080_HPP

#include <MultiWidgets/Widget.hpp>
#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/ButtonWidget.hpp>
#include <MultiWidgets/TimerDial.hpp>

namespace CustomWidget
{
  class ShoeWidget1080 : public MultiWidgets::Widget
  {
      bool slideOn;
      int timeOfSlide;
      int timeOfStart;

  public:
    ShoeWidget1080(MultiWidgets::Widget * parent = 0);
    virtual ~ShoeWidget1080();
    void setupTheShoeWidget1080(float x, float y, float rot);

  private:
    virtual void input(MultiWidgets::GrabManager & gm, float dt);
    virtual void processMessage(const char * id, Radiant::BinaryData & data);
    virtual void update(float dt);

    MultiWidgets::ImageWidget * bg;
    MultiWidgets::ButtonWidget * win;
    MultiWidgets::ImageWidget * killer;
    MultiWidgets::TimerDial * ti;
  };
}

#endif
