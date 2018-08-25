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

#include "MovingDirac3dHatch_case1_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_case1_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_case1_raster::MovingDirac3dHatch_case1_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_case1_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000346482) //scan 1
  {
  float locationX = 0.2 + _t  * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - _t * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000346482  && _t <= 0.00069296) //scan 2
  {
  float locationX = 0.412 - (_t - 0.000346482) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.000346482) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00069296  && _t <= 0.00103945) //scan 3
  {
  float locationX = 0.776 + (_t - 0.00069296) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - (_t - 0.00069296) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00103945  && _t <= 0.00138593) //scan 4
  {
  float locationX = 0.988 - (_t - 0.00103945) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.00103945) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00138593  && _t <= 0.00173241) //scan 5
  {
  float locationX = 1.352 + (_t - 0.00138593) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - (_t - 0.00138593) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00173241  && _t <= 0.00207889) //scan 6
  {
  float locationX = 1.564 - (_t - 0.00173241) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.00173241) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00207889  && _t <= 0.00242537) //scan 7
  {
  float locationX = 1.928 + (_t - 0.00207889) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - (_t - 0.00207889) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00242537  && _t <= 0.00277186) //scan 8
  {
  float locationX = 2.14 - (_t - 0.00242537) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.00242537) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00277186  && _t <= 0.00311834) //scan 9
  {
  float locationX = 2.504 + (_t - 0.00277186) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.506 - (_t - 0.00277186) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00311834  && _t <= 0.00346482) //scan 10
  {
  float locationX = 2.716 - (_t - 0.00311834) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.294 + (_t - 0.00311834) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  // }
  // else
  // if (_t > 0.00346482  && _t <= 0.00360242) //contour scan 1 offset: 0.02 mm
  // {
  // float locationX = 0.22;
  // float locationY = 0.486 - _t * 1250;
  // Point custom_point(locationX, locationY, 0.495);
  // addPoint(custom_point);
  // }
  // else
  // if (_t > 0.00360242  && _t <= 0.00558322) //contour scan 2 offset: 0.02 mm
  // {
  // float locationX = 0.22 + _t * 1250;
  // float locationY = 0.314;
  // Point custom_point(locationX, locationY, 0.495);
  // addPoint(custom_point);
  // }
  // else
  // if (_t > 0.00558322  && _t <= 0.00572082) //contour scan 3 offset: 0.02 mm
  // {
  // float locationX = 2.696;
  // float locationY = 0.314 + _t * 1250;
  // Point custom_point(locationX, locationY, 0.495);
  // addPoint(custom_point);
  // }
  // else
  // if (_t > 0.00572082  && _t <= 0.00770162) //contour scan 4 offset: 0.02 mm
  // {
  // float locationX = 2.696 - _t * 1250;
  // float locationY = 0.486;
  // Point custom_point(locationX, locationY, 0.495);
  // addPoint(custom_point);
  // }
  // else
  // if (_t > 0.00770162  && _t <= 0.00787122) //contour scan 1 offset: 0.0 mm
  // {
  // float locationX = 0.2;
  // float locationY = 0.506 - _t * 1250;
  // Point custom_point(locationX, locationY, 0.495);
  // addPoint(custom_point);
  // }
  // else
  // if (_t > 0.00787122  && _t <= 0.00988402) //contour scan 2 offset: 0.0 mm
  // {
  // float locationX = 0.2 + _t * 1250;
  // float locationY = 0.294;
  // Point custom_point(locationX, locationY, 0.495);
  // addPoint(custom_point);
  // }
  // else
  // if (_t > 0.00988402  && _t <= 0.01005362) //contour scan 3 offset: 0.0 mm
  // {
  // float locationX = 2.716;
  // float locationY = 0.294 + _t * 1250;
  // Point custom_point(locationX, locationY, 0.495);
  // addPoint(custom_point);
  // }
  // else
  // if (_t > 0.01005362  && _t <= 0.01206642) //contour scan 4 offset: 0.0 mm
  // {
  // float locationX = 2.716 - _t * 1250;
  // float locationY = 0.506;
  // Point custom_point(locationX, locationY, 0.495);
  // addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_case1_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
