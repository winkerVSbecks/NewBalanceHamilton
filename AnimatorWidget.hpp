/* COPYRIGHT
 *
 * This file is part of BackgroundAnimations.
 *
 * Copyright: Queue Media Inc, Canada, http://queuemedia.ca
 *
 * All rights reserved, 2012
 *
 * You may use this file only for purposes for which you have a
 * specific, written permission from Queue Media Inc.
 *
 * See file "BackgroundAnimations.hpp" for authors and more details.
 *
 */

#ifndef MULTIANIMATE_ANIMATOR_WIDGET_HPP
#define MULTIANIMATE_ANIMATOR_WIDGET_HPP

#include <MultiWidgets/Widget.hpp>
#include <MultiWidgets/ImageWidget.hpp>

#include <MultiWidgets/Animators.hpp>

#include <Nimble/Random.hpp>

namespace MultiAnimate {

  class AnimatorWidget : public MultiWidgets::Widget
  {

  public:
    AnimatorWidget(Widget * parent = 0);
    virtual ~AnimatorWidget();
    void create890Animation();
    void create1080Animation();
    void createMinimus1Animation();
    void createMinimus2Animation();
    void createNAnimation();
    void setupAnimations();
    float m_tCurrent;


  private:
    virtual void input(MultiWidgets::GrabManager & gm, float dt);
    virtual void update(float dt);
    Nimble::RandomUniform m_random;
    float m_tStart;

    MultiWidgets::ImageWidget * light;
    MultiWidgets::ImageWidget * v2;
    MultiWidgets::ImageWidget * lightest;
    MultiWidgets::ImageWidget * bay;
    MultiWidgets::ImageWidget * s1;
    MultiWidgets::ImageWidget * s2;
    MultiWidgets::ImageWidget * s3;
    MultiWidgets::ImageWidget * s4;

    MultiWidgets::ImageWidget * bg_1;
    MultiWidgets::ImageWidget * bg_2;
    MultiWidgets::ImageWidget * touch1;
    MultiWidgets::ImageWidget * touch2;

    MultiWidgets::ImageWidget * road;
    MultiWidgets::ImageWidget * zero;
    MultiWidgets::ImageWidget * bay2;
    MultiWidgets::ImageWidget * less1;
    MultiWidgets::ImageWidget * more;
    MultiWidgets::ImageWidget * equals;
    MultiWidgets::ImageWidget * together;
    MultiWidgets::ImageWidget * m1;
    MultiWidgets::ImageWidget * text1;

    MultiWidgets::ImageWidget * m2;
    MultiWidgets::ImageWidget * trail;

    MultiWidgets::ImageWidget * v2_2;
    MultiWidgets::ImageWidget * unlike;
    MultiWidgets::ImageWidget * p1;
    MultiWidgets::ImageWidget * p2;
    MultiWidgets::ImageWidget * p3;
    MultiWidgets::ImageWidget * p4;

    MultiWidgets::ImageWidget * n1;
    MultiWidgets::ImageWidget * n2;
    MultiWidgets::ImageWidget * t1;
    MultiWidgets::ImageWidget * t2;
    MultiWidgets::ImageWidget * nb1;
    MultiWidgets::ImageWidget * nb2;

    MultiWidgets::ImageWidget * speaker;

    bool m_inturrupt;
  };

}

#endif

