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

#include "MovingDirac3dHatch.h"

template <>
InputParameters
validParams<MovingDirac3dHatch>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch::MovingDirac3dHatch(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.00025) //scan 1
  {
  float locationX = 0.2;
  float locationY = _t * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00025  && _t <= 0.00050) //scan 2
  {
  float locationX = 0.4;
  float locationY = (_t - 0.00025) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00050  && _t <= 0.00075) //scan 3
  {
  float locationX = 0.6;
  float locationY = (_t - 0.00050) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00075  && _t <= 0.00100) //scan 4
  {
  float locationX = 0.8;
  float locationY = (_t - 0.00075) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00100  && _t <= 0.00125) //scan 5
  {
  float locationX = 1.0;
  float locationY = (_t - 0.00100) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00125  && _t <= 0.00150) //scan 6
  {
  float locationX = 1.2;
  float locationY = (_t - 0.00125) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00150  && _t <= 0.00175) //scan 7
  {
  float locationX = 1.4;
  float locationY = (_t - 0.00150) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00175  && _t <= 0.00200) //scan 8
  {
  float locationX = 1.6;
  float locationY = (_t - 0.00175) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00200  && _t <= 0.00225) //scan 9
  {
  float locationX = 1.8;
  float locationY = (_t - 0.00200) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00225  && _t <= 0.00250) //scan 10
  {
  float locationX = 2.0;
  float locationY = (_t - 0.00225) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00250  && _t <= 0.00275) //scan 11
  {
  float locationX = 2.2;
  float locationY = (_t - 0.00250) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00275  && _t <= 0.00300) //scan 12
  {
  float locationX = 2.4;
  float locationY = (_t - 0.00275) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00300  && _t <= 0.00325) //scan 13
  {
  float locationX = 2.6;
  float locationY = (_t - 0.00300) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
  else
  if (_t > 0.00325  && _t <= 0.00350) //scan 14
  {
  float locationX = 2.8;
  float locationY = (_t - 0.00325) * 1200 + 0.15;
  Point custom_point(locationX, locationY, 0.595);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
