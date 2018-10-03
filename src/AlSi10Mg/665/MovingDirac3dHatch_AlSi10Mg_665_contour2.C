/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "MovingDirac3dHatch_AlSi10Mg_665_contour2.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_AlSi10Mg_665_contour2>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_AlSi10Mg_665_contour2::MovingDirac3dHatch_AlSi10Mg_665_contour2(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_AlSi10Mg_665_contour2::addPoints()
{
  if (_t <= 0.006749118) //Before contour2 scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.006749118  && _t <= 0.007088621) //contour2 scan 1 offset: 0.00 mm
  {
  float locationX = 0.2;
  float locationY = 0.552 - (_t - 0.006749118) * 900;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.007088621  && _t <= 0.008883066) //contour2 scan 2 offset: 0.00 mm
  {
  float locationX = 0.2 + (_t - 0.007088621) * 900;
  float locationY = 0.247;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.008883066 && _t <= 0.009222569) //contour2 scan 3 offset: 0.00 mm
  {
  float locationX = 1.815;
  float locationY = 0.247 + (_t - 0.008883066) * 900;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.009222569 && _t <= 0.011017013) //contour2 scan 4 offset: 0.00 mm
  {
  float locationX = 1.815 - (_t - 0.009222569) * 900;
  float locationY = 0.552;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_AlSi10Mg_665_contour2::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
