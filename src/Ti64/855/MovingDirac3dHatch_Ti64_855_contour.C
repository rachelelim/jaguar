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

#include "MovingDirac3dHatch_Ti64_855_contour.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_Ti64_855_contour>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_Ti64_855_contour::MovingDirac3dHatch_Ti64_855_contour(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_Ti64_855_contour::addPoints()
{
  if (_t <= 0.005239) //Before contour scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.005239  && _t <= 0.005651903) //contour scan 1 offset: 0.02 mm
  {
  float locationX = 0.22;
  float locationY = 0.658 - (_t - 0.005239) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.005651903 && _t <= 0.007677503) //contour scan 2 offset: 0.02 mm
  {
  float locationX = 0.22 + (_t - 0.005651903) * 1250;
  float locationY = 0.142;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.007677503 && _t <= 0.008090075) //contour scan 3 offset: 0.02 mm
  {
  float locationX = 2.752;
  float locationY = 0.142 + (_t - 0.007677503) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.008090075 && _t <= 0.010115675) //contour scan 4 offset: 0.02 mm
  {
  float locationX = 2.752 - (_t - 0.008090075) * 1250;
  float locationY = 0.658;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.010115675 && _t <= 0.010560247) //contour scan 1 offset: 0.0 mm
  {
  float locationX = 0.2;
  float locationY = 0.678 - (_t - 0.010115675) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.010560247 && _t <= 0.012617847) //contour scan 2 offset: 0.0 mm
  {
  float locationX = 0.2 + (_t - 0.010560247) * 1250;
  float locationY = 0.122;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.012617847 && _t <= 0.013062419) //contour scan 3 offset: 0.0 mm
  {
  float locationX = 2.772;
  float locationY = 0.122 + (_t - 0.012617847) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.013062419 && _t <= 0.015120019) //contour scan 4 offset: 0.0 mm
  {
  float locationX = 2.772 - (_t - 0.013062419) * 1250;
  float locationY = 0.678;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_Ti64_855_contour::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
