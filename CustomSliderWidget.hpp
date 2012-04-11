/* COPYRIGHT
 *
 * This file is part of CustomWidget.
 *
 * Copyright: MultiTouch Oy, Finland, http://multitouch.fi
 *
 * All rights reserved, 2007-2010
 *
 * You may use this file only for purposes for which you have a
 * specific, written permission from MultiTouch Oy.
 *
 * See file "CustomWidget.hpp" for authors and more details.
 *
 */


#ifndef CUSTOMWIDGET_CUSTOM_SLIDER_WIDGET_HPP
#define CUSTOMWIDGET_CUSTOM_SLIDER_WIDGET_HPP

#include <MultiWidgets/Widget.hpp>

namespace CustomWidget
{

  /** This is widget that changes color as the user puts his/her hand
      on top of the widget.

  */
  class CustomSliderWidget : public MultiWidgets::Widget
  {
  public:
    CustomSliderWidget(MultiWidgets::Widget * parent = 0);
    virtual ~CustomSliderWidget();
    void makeSlider(bool Ath, const char * path);

  protected:
//    virtual void processFingers(MultiWidgets::GrabManager & gm,
//                                MultiWidgets::FingerArray & fingers,
//                                float dt);
//    virtual void singleTap(MultiWidgets::GrabManager & input);
//    virtual void processMessage(const char * id, Radiant::BinaryData & data);
  };

}

#endif
