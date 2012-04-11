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

#include "AnimatorWidget.hpp"
#include "Global.hpp"
#include <MultiWidgets/Animators.hpp>
#include <MultiWidgets/ImageWidget.hpp>
#include <MultiWidgets/FadeAnimator.hpp>

#include <MultiWidgets/AfterIdleOperator.hpp>

#include <math.h>

#define PI 3.14159265


namespace MultiAnimate {

  AnimatorWidget::AnimatorWidget(Widget * parent)
      : Widget(parent),
      m_random(Radiant::TimeStamp::getTime()), // Use time as the random seed
      m_tStart(Radiant::TimeStamp::getTime()),
      m_tCurrent(Radiant::TimeStamp::getTime()),
        m_inturrupt(false)
  {}

  float tt;


  AnimatorWidget::~AnimatorWidget() {}

  void AnimatorWidget::create890Animation()
  {
      // Remove any old operators.
      s1->clearOperators();
      s2->clearOperators();
      s3->clearOperators();
      s4->clearOperators();
      v2->clearOperators();
      lightest->clearOperators();
      bay->clearOperators();
      light->clearOperators();

      //RESET POSITIONS:
      s1->setLocation(-1920,1080);
      s2->setLocation(-1920,1080);
      s3->setLocation(-1920,0);
      s4->setLocation(-1678,540);

      v2->setLocation(1812+1004*cos(PI/3),1156+1004*sin(PI/3));
      lightest->setLocation(1812+1074*cos(PI/3),1156+1074*sin(PI/3));
      bay->setLocation(1812+1004*cos(PI/3),1156+1004*sin(PI/3));
      light->setLocation(948+1584*cos(1.30899694),-1584*sin(1.30899694));

      // Animate the location of the shoes in hands:
      MultiWidgets::AnimatorVector2f * a1 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a2 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a3 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a4 = new MultiWidgets::AnimatorVector2f("location");

      // Animate the texts
      MultiWidgets::AnimatorVector2f * a5 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a6 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a7 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a8 = new MultiWidgets::AnimatorVector2f("location");

      a4->smoothEndAnimation(0.4, Nimble::Vector2(-1678,540), Nimble::Vector2(0,540),100);
      a4->addKey(2.0f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.7f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.5f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.3f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.9f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.3f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.9f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.5f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.1f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      a4->addKey(1.0f, Nimble::Vector2(0,540));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,540), Nimble::Vector2(0,540),100);
      s4->addOperator(a4);

      a8->addKey(0.0f, light->location());
      a8->addKey(0.5, light->location());
      a8->bouncyAnimation(0.4, Nimble::Vector2(948+1584*cos(1.30899694),-1584*sin(1.30899694)),
                            Nimble::Vector2(948,0),100);
      light->addOperator(a8);

      a3->addKey(0.0f, s3->location());
      a3->addKey(0.9f, s3->location());
      a3->smoothEndAnimation(0.7, Nimble::Vector2(-1920,0), Nimble::Vector2(0,0),100);
      a3->addKey(1.3f, Nimble::Vector2(0,0));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a3->addKey(1.5f, Nimble::Vector2(0,0));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a3->addKey(1.1f, Nimble::Vector2(0,0));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a3->addKey(1.9f, Nimble::Vector2(0,0));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a3->addKey(1.5f, Nimble::Vector2(0,0));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a3->addKey(1.1f, Nimble::Vector2(0,0));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a3->addKey(1.9f, Nimble::Vector2(0,0));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a3->addKey(2.5f, Nimble::Vector2(0,0));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      s3->addOperator(a3);

      a1->addKey(0.0f, s1->location());
      a1->addKey(1.7f, s1->location());
      a1->smoothEndAnimation(0.7, Nimble::Vector2(-1920,1080), Nimble::Vector2(0,1080),100);
      a1->addKey(1.9f, Nimble::Vector2(0,1080));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a1->addKey(1.5f, Nimble::Vector2(0,1080));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a1->addKey(1.9f, Nimble::Vector2(0,1080));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a1->addKey(1.7f, Nimble::Vector2(0,1080));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a1->addKey(1.3f, Nimble::Vector2(0,1080));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a1->addKey(1.0f, Nimble::Vector2(0,1080));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a1->addKey(1.9f, Nimble::Vector2(0,1080));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a1->addKey(1.5f, Nimble::Vector2(0,1080));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      s1->addOperator(a1);

      a2->addKey(0.0f, s2->location());
      a2->addKey(1.2f, s2->location());
      a2->smoothEndAnimation(0.5, Nimble::Vector2(-1920,1080), Nimble::Vector2(0,1080),100);
      a2->addKey(1.65f, Nimble::Vector2(0,1080));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a2->addKey(1.5f, Nimble::Vector2(0,1080));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a2->addKey(1.1f, Nimble::Vector2(0,1080));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a2->addKey(1.9f, Nimble::Vector2(0,1080));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a2->addKey(1.5f, Nimble::Vector2(0,1080));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a2->addKey(1.3f, Nimble::Vector2(0,1080));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a2->addKey(1.7f, Nimble::Vector2(0,1080));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a2->addKey(1.7f, Nimble::Vector2(0,1080));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      s2->addOperator(a2);

      a5->addKey(0.0f, v2->location());
      a5->addKey(2.1, v2->location());
      a5->bouncyAnimation(0.2, Nimble::Vector2(1812+1004*cos(PI/3),1156+1004*sin(PI/3)),
                            Nimble::Vector2(1812,1156),100);
      v2->addOperator(a5);

      a6->addKey(0.0f, lightest->location());
      a6->addKey(2.5, lightest->location());
      a6->bouncyAnimation(0.2, Nimble::Vector2(1812+1074*cos(PI/3),1156+1074*sin(PI/3)),
                            Nimble::Vector2(1812,1156),125);
      lightest->addOperator(a6);

      a7->addKey(0.0f, bay->location());
      a7->addKey(3.0, bay->location());
      a7->bouncyAnimation(0.2, Nimble::Vector2(1812+1004*cos(PI/3),1156+1004*sin(PI/3)),
                          Nimble::Vector2(1812,1156),125);
      bay->addOperator(a7);


      a1->reset();
      a2->reset();
      a3->reset();
      a4->reset();
      a6->reset();
      a7->reset();
      a8->reset();
  }


  void AnimatorWidget::create1080Animation()
  {
      // Remove any old operators.
      p1->clearOperators();
      p2->clearOperators();
      p3->clearOperators();
      p4->clearOperators();
      v2_2->clearOperators();
      unlike->clearOperators();
      bay->clearOperators();
      light->clearOperators();

      //RESET POSITIONS:
      p1->setLocation(-1920,0);
      p2->setLocation(-1920,1080-1136/2);
      p3->setLocation(-1920,1080);
      p4->setLocation(-1920,1080);

      v2_2->setLocation(1396+1280*cos(PI/3),1080+1280*sin(PI/3));
      unlike->setLocation(1812+1074*cos(PI/3),1156+1074*sin(PI/3));
      bay->setLocation(1812+1004*cos(PI/3),1156+1004*sin(PI/3));
      light->setLocation(948+1584*cos(1.30899694),-1584*sin(1.30899694));

      // Animate the location of the shoes in hands:
      MultiWidgets::AnimatorVector2f * a1 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a2 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a3 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a4 = new MultiWidgets::AnimatorVector2f("location");

      // Animate the texts
      MultiWidgets::AnimatorVector2f * a5 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a6 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a7 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a8 = new MultiWidgets::AnimatorVector2f("location");

      //a2->addKey(0.0f, p2->location());
      //a2->addKey(1.2f, p2->location());
      a2->smoothEndAnimation(0.4, Nimble::Vector2(-1920,512), Nimble::Vector2(0,512),100);
      a2->addKey(2.6f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      a2->addKey(0.7f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      a2->addKey(1.5f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      a2->addKey(1.1f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      a2->addKey(1.0f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      a2->addKey(1.7f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      a2->addKey(0.6f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      a2->addKey(1.1f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      a2->addKey(0.7f, Nimble::Vector2(0,512));
      a2->bouncyAnimation(0.4, Nimble::Vector2(50,512), Nimble::Vector2(0,512),100);
      p2->addOperator(a2);


      a3->addKey(0.0f, p3->location());
      a3->addKey(2.5f, p3->location());
      a3->smoothEndAnimation(0.7, Nimble::Vector2(-1920,1080), Nimble::Vector2(0,1080),100);
      a3->addKey(1.0f, Nimble::Vector2(0,1080));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a3->addKey(1.7f, Nimble::Vector2(0,1080));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a3->addKey(1.5f, Nimble::Vector2(0,1080));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a3->addKey(1.3f, Nimble::Vector2(0,1080));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a3->addKey(1.9f, Nimble::Vector2(0,1080));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a3->addKey(1.5f, Nimble::Vector2(0,1080));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a3->addKey(1.2f, Nimble::Vector2(0,1080));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a3->addKey(1.0f, Nimble::Vector2(0,1080));
      a3->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      p3->addOperator(a3);

      a8->addKey(0.0f, light->location());
      a8->addKey(0.5, light->location());
      a8->bouncyAnimation(0.4, Nimble::Vector2(948+1584*cos(1.30899694),-1584*sin(1.30899694)),
                            Nimble::Vector2(948,0),100);
      light->addOperator(a8);

      a1->addKey(0.0f, p1->location());
      a1->addKey(1.3f, p1->location());
      a1->smoothEndAnimation(0.7, Nimble::Vector2(-1920,0), Nimble::Vector2(0,0),100);
      a1->addKey(1.3f, Nimble::Vector2(0,0));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a1->addKey(1.1f, Nimble::Vector2(0,0));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a1->addKey(1.9f, Nimble::Vector2(0,0));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a1->addKey(1.7f, Nimble::Vector2(0,0));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a1->addKey(1.3f, Nimble::Vector2(0,0));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a1->addKey(1.1f, Nimble::Vector2(0,0));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a1->addKey(1.9f, Nimble::Vector2(0,0));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      a1->addKey(1.3f, Nimble::Vector2(0,0));
      a1->bouncyAnimation(0.4, Nimble::Vector2(50,0), Nimble::Vector2(0,0),100);
      p1->addOperator(a1);

      a4->addKey(0.0f, p2->location());
      a4->addKey(1.7f, p2->location());
      a4->smoothEndAnimation(0.7, Nimble::Vector2(-1920,1080), Nimble::Vector2(0,1080),100);
      a4->addKey(1.5f, Nimble::Vector2(0,1080));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a4->addKey(1.7f, Nimble::Vector2(0,1080));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a4->addKey(1.3f, Nimble::Vector2(0,1080));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a4->addKey(1.9f, Nimble::Vector2(0,1080));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a4->addKey(1.5f, Nimble::Vector2(0,1080));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      a4->addKey(1.6f, Nimble::Vector2(0,1080));
      a4->bouncyAnimation(0.4, Nimble::Vector2(50,1080), Nimble::Vector2(0,1080),100);
      p4->addOperator(a4);


      a5->addKey(0.0f, v2_2->location());
      a5->addKey(2.1, v2_2->location());
      a5->bouncyAnimation(0.2, Nimble::Vector2(1812+1280*cos(PI/3),1156+1280*sin(PI/3)),
                            Nimble::Vector2(1812,1156),100);
      v2_2->addOperator(a5);

      a6->addKey(0.0f, unlike->location());
      a6->addKey(2.5, unlike->location());
      a6->bouncyAnimation(0.2, Nimble::Vector2(1812+1074*cos(PI/3),1156+1074*sin(PI/3)),
                            Nimble::Vector2(1812,1156),125);
      unlike->addOperator(a6);

      a7->addKey(0.0f, bay->location());
      a7->addKey(3.0, bay->location());
      a7->bouncyAnimation(0.2, Nimble::Vector2(1812+1004*cos(PI/3),1156+1004*sin(PI/3)),
                          Nimble::Vector2(1812,1156),125);
      bay->addOperator(a7);


      a1->reset();
      a2->reset();
      a3->reset();
      a4->reset();
      a6->reset();
      a7->reset();
      a8->reset();
  }



  void AnimatorWidget::createMinimus1Animation()
  {
      // Remove any old operators.
      road->clearOperators();
      zero->clearOperators();
      bay2->clearOperators();
      less1->clearOperators();
      more->clearOperators();
      equals->clearOperators();
      together->clearOperators();
      m1->clearOperators();
      text1->clearOperators();

      //RESET POSITIONS:
      together->setScale(1);

      less1->setLocation(2160*cos(PI/3),2160*sin(PI/3));
      more->setLocation(-2160*cos(PI/3),-2160*sin(PI/3));
      text1->setLocation(699-2160*cos(PI/3),-2160*sin(PI/3));
      road->setLocation(1920+1100*cos(PI/3),1082+1100*cos(PI/3));
      zero->setLocation(1920+1100*cos(PI/3),1082+1100*cos(PI/3));
      bay2->setLocation(1760+1100*cos(PI/3),1082+1100*cos(PI/3));
      together->setLocation(-1920,0);

      text1->setColor(255,255,255,255);
      equals->setColor(255,255,255,255);
      more->setColor(255,255,255,255);
      less1->setColor(255,255,255,255);
      //m1->setColor(0,0,0,0);

      MultiWidgets::AnimatorVector2f * a1 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a2 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::FadeAnimator * a3 = new MultiWidgets::FadeAnimator();
      MultiWidgets::AnimatorVector2f * a4 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a5 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a6 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a7 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a8 = new MultiWidgets::AnimatorVector2f("location");

      MultiWidgets::AnimatorScale * a9 = new MultiWidgets::AnimatorScale();
      MultiWidgets::FadeAnimator * a10 = new MultiWidgets::FadeAnimator();
      MultiWidgets::AnimatorVector2f * a11 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::FadeAnimator * a12 = new MultiWidgets::FadeAnimator();


      a1->bouncyAnimation(0.2, Nimble::Vector2(2160*cos(PI/3),2160*sin(PI/3)),
                          Nimble::Vector2(0,0),100);
      less1->addOperator(a1);

      a2->bouncyAnimation(0.2, Nimble::Vector2(-2160*cos(PI/3),-2160*sin(PI/3)),
                          Nimble::Vector2(1257,1080),100);
      more->addOperator(a2);


      a3->fadeIn(equals, 0.1, 0.1);


      a4->addKey(0.0f, text1->location());
      a4->addKey(0.5, text1->location());
      a4->bouncyAnimation(0.2, Nimble::Vector2(699-2160*cos(PI/3),-2160*sin(PI/3)),
                          Nimble::Vector2(699,0),100);
      text1->addOperator(a4);

      a8->addKey(0.0f, together->location());
      a8->addKey(2.0, together->location());
      a8->smoothAnimation(0, Nimble::Vector2(-1920,0), Nimble::Vector2(612,0));
      together->addOperator(a8);


      a9->addKey(0.0, together->scale());
      a9->addKey(2.2, together->scale());
      a9->smoothAnimation(0.5, 1, 0.568);
      together->addOperator(a9);

      a11->addKey(0.0f, together->location());
      a11->addKey(2.2, together->location());
      a11->smoothAnimation(0.5, Nimble::Vector2(612,0), Nimble::Vector2(1140.3,-26.8));
      together->addOperator(a11);

      a10->fadeOut(less1,0, 2);
      a10->fadeOut(more,0, 2);
      a10->fadeOut(equals,0, 2);
      a10->fadeOut(text1, 0, 2);

      a12->fadeIn(m1, 0.4, 2.3);

      a5->addKey(0.0f, road->location());
      a5->addKey(2.8, road->location());
      a5->bouncyAnimation(0.2, Nimble::Vector2(1920+1100*cos(PI/3),1082+1100*cos(PI/3)),
                          Nimble::Vector2(1920,1082),100);
      road->addOperator(a5);


      a6->addKey(0.0f, zero->location());
      a6->addKey(3.1, zero->location());
      a6->bouncyAnimation(0.2, Nimble::Vector2(1920+1100*cos(PI/3),1082+1100*cos(PI/3)),
                          Nimble::Vector2(1920,1082),100);
      zero->addOperator(a6);

      a7->addKey(0.0f, bay2->location());
      a7->addKey(3.4, bay2->location());
      a7->bouncyAnimation(0.2, Nimble::Vector2(1760+1100*cos(PI/3),1082+1100*cos(PI/3)),
                          Nimble::Vector2(1760,1082),100);
      bay2->addOperator(a7);


      a1->reset();
      a2->reset();
      a3->reset();
      a4->reset();
      a5->reset();
      a6->reset();
      a7->reset();
      a8->reset();
      a9->reset();
      a10->reset();
      a11->reset();
      a12->reset();
  }


  void AnimatorWidget::createMinimus2Animation()
  {
      // Remove any old operators.
      trail->clearOperators();
      zero->clearOperators();
      bay2->clearOperators();
      less1->clearOperators();
      more->clearOperators();
      equals->clearOperators();
      together->clearOperators();
      m2->clearOperators();
      text1->clearOperators();

      //RESET POSITIONS:
      together->setScale(1);

      less1->setLocation(2160*cos(PI/3),2160*sin(PI/3));
      more->setLocation(-2160*cos(PI/3),-2160*sin(PI/3));
      text1->setLocation(699-2160*cos(PI/3),-2160*sin(PI/3));
      trail->setLocation(1920+1100*cos(PI/3),1082+1100*cos(PI/3));
      zero->setLocation(1920+1100*cos(PI/3),1082+1100*cos(PI/3));
      bay2->setLocation(1760+1100*cos(PI/3),1082+1100*cos(PI/3));
      together->setLocation(-1920,0);

      text1->setColor(255,255,255,255);
      equals->setColor(255,255,255,255);
      more->setColor(255,255,255,255);
      less1->setColor(255,255,255,255);
      //m2->setColor(0,0,0,0);

      MultiWidgets::AnimatorVector2f * a1 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a2 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::FadeAnimator * a3 = new MultiWidgets::FadeAnimator();
      MultiWidgets::AnimatorVector2f * a4 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a5 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a6 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a7 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a8 = new MultiWidgets::AnimatorVector2f("location");

      MultiWidgets::AnimatorScale * a9 = new MultiWidgets::AnimatorScale();
      MultiWidgets::FadeAnimator * a10 = new MultiWidgets::FadeAnimator();
      MultiWidgets::AnimatorVector2f * a11 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::FadeAnimator * a12 = new MultiWidgets::FadeAnimator();


      a1->bouncyAnimation(0.2, Nimble::Vector2(2160*cos(PI/3),2160*sin(PI/3)),
                          Nimble::Vector2(0,0),100);
      less1->addOperator(a1);

      a2->bouncyAnimation(0.2, Nimble::Vector2(-2160*cos(PI/3),-2160*sin(PI/3)),
                          Nimble::Vector2(1257,1080),100);
      more->addOperator(a2);


      a3->fadeIn(equals, 0.1, 0.1);


      a4->addKey(0.0f, text1->location());
      a4->addKey(0.5, text1->location());
      a4->bouncyAnimation(0.2, Nimble::Vector2(699-2160*cos(PI/3),-2160*sin(PI/3)),
                          Nimble::Vector2(699,0),100);
      text1->addOperator(a4);

      a8->addKey(0.0f, together->location());
      a8->addKey(2.0, together->location());
      a8->smoothAnimation(0, Nimble::Vector2(-1920,0), Nimble::Vector2(612,0));
      together->addOperator(a8);


      a9->addKey(0.0, together->scale());
      a9->addKey(2.2, together->scale());
      a9->smoothAnimation(0.5, 1, 0.568);
      together->addOperator(a9);

      a11->addKey(0.0f, together->location());
      a11->addKey(2.2, together->location());
      a11->smoothAnimation(0.5, Nimble::Vector2(612,0), Nimble::Vector2(1140.3,-26.8));
      together->addOperator(a11);

      a10->fadeOut(less1,0, 2);
      a10->fadeOut(more,0, 2);
      a10->fadeOut(equals,0, 2);
      a10->fadeOut(text1, 0, 2);

      a12->fadeIn(m2, 0.4, 2.3);

      a5->addKey(0.0f, trail->location());
      a5->addKey(2.8, trail->location());
      a5->bouncyAnimation(0.2, Nimble::Vector2(1920+1100*cos(PI/3),1082+1100*cos(PI/3)),
                          Nimble::Vector2(1920,1082),100);
      trail->addOperator(a5);


      a6->addKey(0.0f, zero->location());
      a6->addKey(3.1, zero->location());
      a6->bouncyAnimation(0.2, Nimble::Vector2(1920+1100*cos(PI/3),1082+1100*cos(PI/3)),
                          Nimble::Vector2(1920,1082),100);
      zero->addOperator(a6);

      a7->addKey(0.0f, bay2->location());
      a7->addKey(3.4, bay2->location());
      a7->bouncyAnimation(0.2, Nimble::Vector2(1760+1100*cos(PI/3),1082+1100*cos(PI/3)),
                          Nimble::Vector2(1760,1082),100);
      bay2->addOperator(a7);


      a1->reset();
      a2->reset();
      a3->reset();
      a4->reset();
      a5->reset();
      a6->reset();
      a7->reset();
      a8->reset();
      a9->reset();
      a10->reset();
      a11->reset();
      a12->reset();
  }

  void AnimatorWidget::createNAnimation()
  {
      // Remove any old operators
      n1->clearOperators();
      n2->clearOperators();
      nb1->clearOperators();
      nb2->clearOperators();
      t1->clearOperators();
      t2->clearOperators();

      //RESET POSITIONS:
      nb1->setLocation(0,0);
      nb2->setLocation(2532-495,2160-540);
      t1->setLocation(1920-612+1000*0.276,-1000*0.96123);
      //t1->setLocation(1920-614,-553);
      //t2->setLocation(612,2160);
      t2->setLocation(612-1000*0.276,2160+1000*0.96123);


      MultiWidgets::FadeAnimator * a1 = new MultiWidgets::FadeAnimator();
      //MultiWidgets::AnimatorVector2f * a2 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a3 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorScale * a2 = new MultiWidgets::AnimatorScale();
      MultiWidgets::AnimatorScale * a4 = new MultiWidgets::AnimatorScale();
      //MultiWidgets::AnimatorVector2f * a4 = new MultiWidgets::AnimatorVector2f("location");
      MultiWidgets::AnimatorVector2f * a5 = new MultiWidgets::AnimatorVector2f("location");

      a1->fadeIn(n1, 0.5, 1.0);
      a1->fadeIn(n2, 0.5, 1.0);

      a2->addKey(0.0, 0);
      a2->addKey(2.1, 0);
      a2->bouncyAnimation(0.3, 0, 1, 75);
      a2->addKey(0.5, 1);
      a2->bouncyAnimation(0.3, 1.5, 1, 75);
      a2->addKey(0.5, 1);
      a2->bouncyAnimation(0.3, 1.5, 1, 75);
      a2->addKey(0.5, 1);
      a2->bouncyAnimation(0.3, 1.5, 1, 75);
      a2->addKey(0.5, 1);
      a2->bouncyAnimation(0.3, 1.5, 1, 75);
      a2->addKey(0.5, 1);
      a2->bouncyAnimation(0.3, 1.5, 1, 75);
      a2->addKey(0.5, 1);
      a2->bouncyAnimation(0.3, 1.5, 1, 75);
      a2->addKey(0.5, 1);
      a2->bouncyAnimation(0.3, 1.5, 1, 75);
      a2->addKey(0.5, 1);
      a2->bouncyAnimation(0.3, 1.5, 1, 75);
      nb1->addOperator(a2);

      a3->addKey(0.0f, t1->location());
      a3->addKey(1.8, t1->location());
      a3->bouncyAnimation(0.3, t1->location(), Nimble::Vector2(1920-612,-75),150);
      t1->addOperator(a3);

      a4->addKey(0.0f, 0);
      a4->addKey(2.1, 0);
      a4->bouncyAnimation(0.3, 0, 1, 75);
      a4->addKey(0.5, 1);
      a4->bouncyAnimation(0.3, 1.5, 1, 75);
      a4->addKey(0.5, 1);
      a4->bouncyAnimation(0.3, 1.5, 1, 75);
      a4->addKey(0.5, 1);
      a4->bouncyAnimation(0.3, 1.5, 1, 75);
      a4->addKey(0.5, 1);
      a4->bouncyAnimation(0.3, 1.5, 1, 75);
      a4->addKey(0.5, 1);
      a4->bouncyAnimation(0.3, 1.5, 1, 75);
      a4->addKey(0.5, 1);
      a4->bouncyAnimation(0.3, 1.5, 1, 75);
      a4->addKey(0.5, 1);
      a4->bouncyAnimation(0.3, 1.5, 1, 75);
      a4->addKey(0.5, 1);
      a4->bouncyAnimation(0.3, 1.5, 1, 75);
      nb2->addOperator(a4);

      a5->addKey(0.0f, t2->location());
      a5->addKey(1.8, t2->location());
      a5->bouncyAnimation(0.3, t2->location(), Nimble::Vector2(612,2160-685+75),150);
      t2->addOperator(a5);

      a1->reset();
      a2->reset();
      a3->reset();
      a4->reset();
      a5->reset();
  }

  void AnimatorWidget::setupAnimations()
  {
/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////SETUP 890//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
      light = new MultiWidgets::ImageWidget(this);
      light->load("890/animation/light.png");
      light->setSize(1584,992);
      light->setLocation(948,0);
      light->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);
//      light->setDepth(-1);
//      light->raiseFlag(MultiWidgets::Widget::LOCK_DEPTH);

      v2 = new MultiWidgets::ImageWidget(this);
      v2->load("890/animation/v2.png");
      v2->setSize(720,1004);
      v2->setLocation(1812,1156);
      v2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      lightest = new MultiWidgets::ImageWidget(this);
      lightest->load("890/animation/lightest.png");
      lightest->setSize(720,1004);
      lightest->setLocation(1812,1156);
      lightest->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      bay = new MultiWidgets::ImageWidget(this);
      bay->load("890/animation/bay.png");
      bay->setSize(720,1004);
      bay->setLocation(1812,1156);
      bay->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      s1 = new MultiWidgets::ImageWidget(this);
      s1->load("890/animation/1.png");
      s1->setSize(1920,1080);
      s1->setLocation(-1920,1080);
      s1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      s2 = new MultiWidgets::ImageWidget(this);
      s2->load("890/animation/2.png");
      s2->setSize(1920,1080);
      s2->setLocation(-1920,1080);
      s2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      s3 = new MultiWidgets::ImageWidget(this);
      s3->load("890/animation/3.png");
      s3->setSize(1920,1080);
      s3->setLocation(-1920,0);
      s3->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);


      s4 = new MultiWidgets::ImageWidget(this);
      s4->load("890/animation/4.png");
      s4->setSize(1678,959);
      s4->setLocation(-1678,540);
      s4->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      bg_1 = new MultiWidgets::ImageWidget(this);
      bg_1->load("N/n1.png");
      bg_1->setLocation(0,0);
      bg_1->setSize(1920,1080);
      bg_1->setDepth(-3);
      bg_1->hide();
      bg_1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      bg_2 = new MultiWidgets::ImageWidget(this);
      bg_2->load("N/n2.png");
      bg_2->setLocation(550,1080);
      bg_2->setSize(1920,1080);
      bg_2->setDepth(-3);
      bg_2->hide();
      bg_2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      speaker = new MultiWidgets::ImageWidget(this);
      speaker->load("misc/speaker.png");
      speaker->setLocation(1266-600, 1080-600);
      speaker->setSize(600,600);
      speaker->setDepth(-2);
      speaker->hide();
      speaker->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      touch1 = new MultiWidgets::ImageWidget(this);
      touch1->load("N/touch1.png");
      touch1->setLocation(0,0);
      touch1->setSize(1920,1080);
      touch1->setDepth(-1);
      touch1->hide();
      touch1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      touch2 = new MultiWidgets::ImageWidget(this);
      touch2->load("N/touch2.png");
      touch2->setLocation(612,1080);
      touch2->setSize(1920,1080);
      touch2->setDepth(-1);
      touch2->hide();
      touch2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);


/////////////////////////////////////////////////////////////////////////////
//////////////////////////////////SETUP 1080/////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
      v2_2 = new MultiWidgets::ImageWidget(this);
      v2_2->load("1080/animation/1080.png");
      v2_2->setSize(720,1004);
      v2_2->setLocation(1396+1080*cos(PI/3),1080+1080*sin(PI/3));
      v2_2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      unlike = new MultiWidgets::ImageWidget(this);
      unlike->load("1080/animation/unlike.png");
      unlike->setSize(720,1004);
      unlike->setLocation(1812+1074*cos(PI/3),1156+1074*sin(PI/3));
      unlike->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);


      p1 = new MultiWidgets::ImageWidget(this);
      p1->load("1080/animation/1.png");
      p1->setSize(880,1080);
      p1->setLocation(0,0);
      p1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      p2 = new MultiWidgets::ImageWidget(this);
      p2->load("1080/animation/2.png");
      p2->setSize(1765,1136);
      p2->setLocation(0,1080+1136/2);
      p2->setDepth(2);
      p2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      p3 = new MultiWidgets::ImageWidget(this);
      p3->load("1080/animation/3.png");
      p3->setSize(1681,1081);
      p3->setLocation(-1920,0);
      p3->setDepth(1);
      p3->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      p4 = new MultiWidgets::ImageWidget(this);
      p4->load("1080/animation/4.png");
      p4->setSize(1681,1081);
      p4->setLocation(0,1080);
      p4->setDepth(2);
      p4->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);


/////////////////////////////////////////////////////////////////////////////
////////////////////////////////SETUP MINIMUS////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
      m1 = new MultiWidgets::ImageWidget(this);
      m1->load("minimus/animation/m1.png");
      m1->setSize(2532,2160);
      m1->setLocation(0,0);
      m1->setDepth(0);
      m1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      road = new MultiWidgets::ImageWidget(this);
      road->load("minimus/animation/road.png");
      road->setSize(615,1078);
      road->setLocation(1920,1082);
      road->setDepth(1);
      road->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      zero = new MultiWidgets::ImageWidget(this);
      zero->load("minimus/animation/zero.png");
      zero->setSize(615,1078);
      zero->setLocation(1920,1082);
      zero->setDepth(1);
      zero->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      bay2 = new MultiWidgets::ImageWidget(this);
      bay2->load("890/animation/bay.png");
      bay2->setSize(890,1004);
      bay2->setLocation(1812,1156);
      bay2->setDepth(1);
      bay2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      less1 = new MultiWidgets::ImageWidget(this);
      less1->load("minimus/animation/less.png");
      less1->setSize(1922,1080);
      less1->setLocation(0,0);
      less1->setDepth(1);
      less1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      more = new MultiWidgets::ImageWidget(this);
      more->load("minimus/animation/more.png");
      more->setSize(1275, 631);
      more->setLocation(1257,1080);
      more->setDepth(1);
      more->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      equals = new MultiWidgets::ImageWidget(this);
      equals->load("minimus/animation/equals.png");
      equals->setSize(873,1308);
      equals->setLocation(1047,0);
      equals->setDepth(1);
      equals->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);


      together = new MultiWidgets::ImageWidget(this);
      together->load("minimus/animation/together.png");
      together->setSize(1307,1761);
      together->setLocation(612,0);
      together->setDepth(1);
      together->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      text1 = new MultiWidgets::ImageWidget(this);
      text1->load("minimus/animation/text.png");
      text1->setSize(1221,1704);
      text1->setLocation(699,0);
      text1->setDepth(1);
      text1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      m2 = new MultiWidgets::ImageWidget(this);
      m2->load("minimus/animation/m2.png");
      m2->setSize(2532,2160);
      m2->setLocation(0,0);
      m2->setDepth(0);
      m2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      trail = new MultiWidgets::ImageWidget(this);
      trail->load("minimus/animation/trail.png");
      trail->setSize(615,1078);
      trail->setLocation(1920,1082);
      trail->setDepth(1);
      trail->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

/////////////////////////////////////////////////////////////////////////////
///////////////////////////////////SETUP N///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
      n1 = new MultiWidgets::ImageWidget(this);
      n1->load("N/n1.png");
      n1->setSize(1920,1080);
      n1->setLocation(0,0);
      n1->setDepth(1);
      n1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      n2 = new MultiWidgets::ImageWidget(this);
      n2->load("N/n2.png");
      n2->setSize(1920,1080);
      n2->setLocation(550,1080);
      n2->setDepth(1);
      n2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      t1 = new MultiWidgets::ImageWidget(this);
      t1->load("N/tag1.png");
      t1->setSize(614,553);
      t1->setLocation(1920-614,0);
      t1->setDepth(2);
      t1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      t2 = new MultiWidgets::ImageWidget(this);
      t2->load("N/tag2.png");
      t2->setSize(680,685);
      t2->setLocation(612,2160-685);
      t2->setDepth(2);
      t2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      nb1 = new MultiWidgets::ImageWidget(this);
      nb1->load("N/nb1.png");
      nb1->setSize(594,541);
      nb1->setLocation(0,0);
      nb1->setDepth(2);
      nb1->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);

      nb2 = new MultiWidgets::ImageWidget(this);
      nb2->load("N/nb2.png");
      nb2->setSize(495,540);
      nb2->setLocation(2532-495,2160-540);
      nb2->setDepth(2);
      nb2->setInputFlags(MultiAnimate::AnimatorWidget::INPUT_NONE);


/////////////////////////////////////////////////////////////////////////////
////////////////////////HIDE STUFF TO BEGIN WITH/////////////////////////////
/////////////////////////////////////////////////////////////////////////////
      road->hide();
      zero->hide();
      bay2->hide();
      less1->hide();
      more->hide();
      equals->hide();
      together->hide();
      m1->hide();
      text1->hide();

      m2->hide();
      trail->hide();

      v2_2->hide();
      p1->hide();
      p2->hide();
      p3->hide();
      p4->hide();
      unlike->hide();

      n1->hide();
      n2->hide();
      t1->hide();
      t2->hide();
      nb1->hide();
      nb2->hide();



    //RUN THE ANIMATION ONCE
    create890Animation();
    //create1080Animation();
    //createMinimus1Animation();
  }

  void AnimatorWidget::input(MultiWidgets::GrabManager & gm, float dt)
 {
   Widget::input(gm, dt);

   if(noActiveWidgets==0)
   {
       m_inturrupt = false;
   }

   if(noActiveWidgets>0 && !m_inturrupt)
   {
       s1->clearOperators();
       s2->clearOperators();
       s3->clearOperators();
       s4->clearOperators();
       v2->clearOperators();
       lightest->clearOperators();
       bay->clearOperators();
       light->clearOperators();

       road->clearOperators();
       zero->clearOperators();
       bay2->clearOperators();
       less1->clearOperators();
       more->clearOperators();
       equals->clearOperators();
       together->clearOperators();
       m1->clearOperators();
       text1->clearOperators();

       m2->clearOperators();
       trail->clearOperators();

       v2_2->clearOperators();
       unlike->clearOperators();
       p1->clearOperators();
       p2->clearOperators();
       p3->clearOperators();
       p4->clearOperators();

       n1->clearOperators();
       n2->clearOperators();
       t1->clearOperators();
       t2->clearOperators();
       nb1->clearOperators();
       nb2->clearOperators();

       s1->hide();
       s2->hide();
       s3->hide();
       s4->hide();
       v2->hide();
       lightest->hide();
       bay->hide();
       light->hide();

       road->hide();
       zero->hide();
       bay2->hide();
       less1->hide();
       more->hide();
       equals->hide();
       together->hide();
       m1->hide();
       text1->hide();

       m2->hide();
       trail->hide();

       v2_2->hide();
       unlike->hide();
       p1->hide();
       p2->hide();
       p3->hide();
       p4->hide();

       n1->hide();
       n2->hide();
       t1->hide();
       t2->hide();
       nb1->hide();
       nb2->hide();

       bg_1->show();
       bg_2->show();
       touch1->show();
       touch2->show();
       speaker->show();

       m_inturrupt = true;
   }

   if(noActiveWidgets>0 && m_inturrupt)
   {
       //You Work Is Done....Chill Out For A Bit.
   }
 }

  void AnimatorWidget::update(float dt)
  {
      Widget::update(dt);

      tt += 1;

//      if(tt>400 && tt<500 && !m_inturrupt)
//      {
//          v2_2->show();
//          p1->show();
//          p2->show();
//          p3->show();
//          p4->show();
//          unlike->show();
//          bay->show();
//          light->show();

//          s1->hide();
//          s2->hide();
//          s3->hide();
//          s4->hide();

//          v2->hide();
//          lightest->hide();
//          light->hide();
//          bay->hide();

//        n1->show();
//        n2->show();
//        t1->show();
//        t2->show();
//        nb1->show();
//        nb2->show();

//          tt=0;
//          create890Animation();
//      }

//N
      if(tt>400 && tt<600 && !m_inturrupt)
      {
          n1->show();
          n2->show();
          t1->show();
          t2->show();
          nb1->show();
          nb2->show();

          s1->hide();
          s2->hide();
          s3->hide();
          s4->hide();
          v2->hide();
          lightest->hide();
          bay->hide();
          light->hide();

          bg_1->hide();
          bg_2->hide();
          touch1->hide();
          touch2->hide();
          speaker->hide();

          createNAnimation();
          tt=601;
      }

//Minimus 1
      if(tt>800 && tt<1000 && !m_inturrupt)
      {
          road->show();
          zero->show();
          bay2->show();
          less1->show();
          more->show();
          equals->show();
          together->show();
          m1->show();
          text1->show();

          bg_1->hide();
          bg_2->hide();
          touch1->hide();
          touch2->hide();
          speaker->hide();

          n1->hide();
          n2->hide();
          t1->hide();
          t2->hide();
          nb1->hide();
          nb2->hide();

          createMinimus1Animation();
          tt=1001;
      }

//N
      if(tt>1200 && tt<1400 && !m_inturrupt)
      {
          n1->show();
          n2->show();
          t1->show();
          t2->show();
          nb1->show();
          nb2->show();

          bg_1->hide();
          bg_2->hide();
          touch1->hide();
          touch2->hide();
          speaker->hide();

          road->hide();
          zero->hide();
          bay2->hide();
          less1->hide();
          more->hide();
          equals->hide();
          together->hide();
          m1->hide();
          text1->hide();

          tt=1401;
          createNAnimation();
      }

//1080
      if(tt>1600 && tt<1800 && !m_inturrupt)
      {
          p1->show();
          p2->show();
          p3->show();
          p4->show();
          v2_2->show();
          unlike->show();
          bay->show();
          light->show();

          bg_1->hide();
          bg_2->hide();
          touch1->hide();
          touch2->hide();
          speaker->hide();

          n1->hide();
          n2->hide();
          t1->hide();
          t2->hide();
          nb1->hide();
          nb2->hide();

          tt=1801;
          create1080Animation();
      }

//N
      if(tt>2200 && tt<2400 && !m_inturrupt)
      {
          n1->show();
          n2->show();
          t1->show();
          t2->show();
          nb1->show();
          nb2->show();

          p1->hide();
          p2->hide();
          p3->hide();
          p4->hide();
          v2_2->hide();
          unlike->hide();
          bay->hide();
          light->hide();

          bg_1->hide();
          bg_2->hide();
          touch1->hide();
          touch2->hide();
          speaker->hide();

          tt=2401;
          createNAnimation();
      }

//Minimus 2
      if(tt>2600 && tt<2800 && !m_inturrupt)
      {

          zero->show();
          bay2->show();
          less1->show();
          more->show();
          equals->show();
          together->show();
          text1->show();
          trail->show();
          m2->show();

          bg_1->hide();
          bg_2->hide();
          touch1->hide();
          touch2->hide();
          speaker->hide();

          n1->hide();
          n2->hide();
          t1->hide();
          t2->hide();
          nb1->hide();
          nb2->hide();

          tt=2801;
          createMinimus2Animation();
      }

//N
      if(tt>3000 && tt<3200 && !m_inturrupt)
      {
          n1->show();
          n2->show();
          t1->show();
          t2->show();
          nb1->show();
          nb2->show();

          zero->hide();
          bay2->hide();
          less1->hide();
          more->hide();
          equals->hide();
          together->hide();
          text1->hide();
          trail->hide();
          m2->hide();

          bg_1->hide();
          bg_2->hide();
          touch1->hide();
          touch2->hide();
          speaker->hide();

          tt=3201;
          createNAnimation();
      }

//890
      if(tt>3400 && !m_inturrupt)
      {
          s1->show();
          s2->show();
          s3->show();
          s4->show();
          v2->show();
          lightest->show();
          bay->show();
          light->show();

          bg_1->hide();
          bg_2->hide();
          touch1->hide();
          touch2->hide();
          speaker->hide();

          n1->hide();
          n2->hide();
          t1->hide();
          t2->hide();
          nb1->hide();
          nb2->hide();

          tt=0;
          create890Animation();
      }

  }

}
