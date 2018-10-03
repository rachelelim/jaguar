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

#include "MovingDirac3dHatch_Ti64_760_contour.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_Ti64_760_contour>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_Ti64_760_contour::MovingDirac3dHatch_Ti64_760_contour(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_Ti64_760_contour::addPoints()
{
  if (_t <= 0.004364) //Before contour scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.004364  && _t <= 0.004702583) //contour scan 1 offset: 0.02 mm
  {
  float locationX = 0.22;
  float locationY = 0.611 - (_t - 0.004364) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.0047025833 && _t <= 0.006653783) //contour scan 2 offset: 0.02 mm
  {
  float locationX = 0.22 + (_t - 0.004702583) * 1250;
  float locationY = 0.189;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.006653783 && _t <= 0.006992103) //contour scan 3 offset: 0.02 mm
  {
  float locationX = 2.659;
  float locationY = 0.189 + (_t - 0.006653783) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.006992103 && _t <= 0.008943303) //contour scan 4 offset: 0.02 mm
  {
  float locationX = 2.659 - (_t - 0.006992103) * 1250;
  float locationY = 0.611;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.008943303 && _t <= 0.009313623) //contour scan 1 offset: 0.0 mm
  {
  float locationX = 0.2;
  float locationY = 0.631 - (_t - 0.008943303) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.009313623 && _t <= 0.011296823) //contour scan 2 offset: 0.0 mm
  {
  float locationX = 0.2 + (_t - 0.009313623) * 1250;
  float locationY = 0.169;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.011296823 && _t <= 0.011667143) //contour scan 3 offset: 0.0 mm
  {
  float locationX = 2.679;
  float locationY = 0.169 + (_t - 0.011296823) * 1250;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.011667143 && _t <= 0.013650343) //contour scan 4 offset: 0.0 mm
  {
  float locationX = 2.679 - (_t - 0.011667143) * 1250;
  float locationY = 0.631;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_Ti64_760_contour::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
