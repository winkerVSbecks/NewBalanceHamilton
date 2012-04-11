#ifndef CUSTOMWIDGET_SHOE_WIDGET_TRAIL_HPP
#define CUSTOMWIDGET_SHOE_WIDGET_TRAIL_HPP

#include <MultiWidgets/Widget.hpp>
#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/ButtonWidget.hpp>
#include <MultiWidgets/TimerDial.hpp>

namespace CustomWidget
{
  class ShoeWidgetTrail : public MultiWidgets::Widget
  {
      bool slideOn;
      int timeOfSlide;
      int timeOfStart;

  public:
    ShoeWidgetTrail(MultiWidgets::Widget * parent = 0);
    virtual ~ShoeWidgetTrail();
    void setupTheShoeWidgetTrail(float x, float y, float rot);

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
