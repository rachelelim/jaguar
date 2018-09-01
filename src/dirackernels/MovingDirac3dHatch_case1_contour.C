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

#include "MovingDirac3dHatch_case1_contour.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_case1_contour>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_case1_contour::MovingDirac3dHatch_case1_contour(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_case1_contour::addPoints()
{
  if (_t <= 0.002248564) //Before contour scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002248564  && _t <= 0.002386164) //contour scan 1 offset: 0.02 mm
  {
  float locationX = 0.22;
  float locationY = 0.486 - (_t - 0.002248564) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002386164  && _t <= 0.004366964) //contour scan 2 offset: 0.02 mm
  {
  float locationX = 0.22 + (_t - 0.002386164) * 1250;
  float locationY = 0.314;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.004366964  && _t <= 0.004504564) //contour scan 3 offset: 0.02 mm
  {
  float locationX = 2.696;
  float locationY = 0.314 + (_t - 0.004366964) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.004504564  && _t <= 0.006485364) //contour scan 4 offset: 0.02 mm
  {
  float locationX = 2.696 - (_t - 0.004504564) * 1250;
  float locationY = 0.486;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.006485364  && _t <= 0.006654964) //contour scan 1 offset: 0.0 mm
  {
  float locationX = 0.2;
  float locationY = 0.506 - (_t - 0.006485364) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.006654964  && _t <= 0.008667764) //contour scan 2 offset: 0.0 mm
  {
  float locationX = 0.2 + (_t - 0.006654964) * 1250;
  float locationY = 0.294;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.008667764  && _t <= 0.008837364) //contour scan 3 offset: 0.0 mm
  {
  float locationX = 2.716;
  float locationY = 0.294 + (_t - 0.008667764) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.008837364  && _t <= 0.010850164) //contour scan 4 offset: 0.0 mm
  {
  float locationX = 2.716 - (_t - 0.008837364) * 1250;
  float locationY = 0.506;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_case1_contour::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
