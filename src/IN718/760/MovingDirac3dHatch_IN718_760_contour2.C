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

#include "MovingDirac3dHatch_IN718_760_contour2.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_IN718_760_contour2>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_IN718_760_contour2::MovingDirac3dHatch_IN718_760_contour2(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_IN718_760_contour2::addPoints()
{
  if (_t <= 0.018762383) //Before contour2 scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.018762383 && _t <= 0.019508951) //contour2 scan 1 offset: 0.00 mm
  {
  float locationX = 0.2;
  float locationY = 0.699 - (_t - 0.018762383) * 800;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.019508951 && _t <= 0.022148951) //contour2 scan 2 offset: 0.00 mm
  {
  float locationX = 0.2 + (_t - 0.019508951) * 800;
  float locationY = 0.101;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.022148951 && _t <= 0.022895518) //contour2 scan 3 offset: 0.00 mm
  {
  float locationX = 2.312;
  float locationY = 0.101 + (_t - 0.022148951) * 800;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.022895518 && _t <= 0.025535518) //contour2 scan 4 offset: 0.00 mm
  {
  float locationX = 2.312 - (_t - 0.022895518) * 800;
  float locationY = 0.699;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_IN718_760_contour2::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
