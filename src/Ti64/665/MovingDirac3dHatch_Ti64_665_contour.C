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

#include "MovingDirac3dHatch_Ti64_665_contour.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_Ti64_665_contour>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_Ti64_665_contour::MovingDirac3dHatch_Ti64_665_contour(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_Ti64_665_contour::addPoints()
{
  if (_t <= 0.003489) //Before contour scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003489  && _t <= 0.003753263) //contour scan 1 offset: 0.02 mm
  {
  float locationX = 0.22;
  float locationY = 0.565 - (_t - 0.003489) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003753263 && _t <= 0.005630063) //contour scan 2 offset: 0.02 mm
  {
  float locationX = 0.22 + (_t - 0.003753263) * 1250;
  float locationY = 0.235;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.005630063 && _t <= 0.005894131) //contour scan 3 offset: 0.02 mm
  {
  float locationX = 2.566;
  float locationY = 0.235 + (_t - 0.005630063) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.005894131 && _t <= 0.007770931) //contour scan 4 offset: 0.02 mm
  {
  float locationX = 2.566 - (_t - 0.005894131) * 1250;
  float locationY = 0.565;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.007770931 && _t <= 0.008066999) //contour scan 1 offset: 0.0 mm
  {
  float locationX = 0.2;
  float locationY = 0.585 - (_t - 0.007770931) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.008066999 && _t <= 0.009975799) //contour scan 2 offset: 0.0 mm
  {
  float locationX = 0.2 + (_t - 0.008066999) * 1250;
  float locationY = 0.215;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.009975799 && _t <= 0.010271867) //contour scan 3 offset: 0.0 mm
  {
  float locationX = 2.586;
  float locationY = 0.215 + (_t - 0.009975799) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.010271867 && _t <= 0.012180667) //contour scan 4 offset: 0.0 mm
  {
  float locationX = 2.586 - (_t - 0.010271867) * 1250;
  float locationY = 0.585;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_Ti64_665_contour::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
