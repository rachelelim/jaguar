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

#include "MovingDirac3dHatch_Ti64_760_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_Ti64_760_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_Ti64_760_raster::MovingDirac3dHatch_Ti64_760_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_Ti64_760_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000546) //scan 1
  {
  float locationX = 0.2 + _t  * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.631 - _t * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000546  && _t <= 0.001091) //scan 2
  {
  float locationX = 0.951 - (_t - 0.000546) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.169 + (_t - 0.000546) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001091 && _t <= 0.001637) //scan 3
  {
  float locationX = 0.776 + (_t - 0.001091) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.631 - (_t - 0.001091) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001637 && _t <= 0.002182) //scan 4
  {
  float locationX = 1.527 - (_t - 0.001637) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.169 + (_t - 0.001637) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002182 && _t <= 0.002728) //scan 5
  {
  float locationX = 1.352 + (_t - 0.002182) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.631 - (_t - 0.002182) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002728 && _t <= 0.003273) //scan 6
  {
  float locationX = 2.103 - (_t - 0.002728) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.169 + (_t - 0.002728) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003273  && _t <= 0.003819) //scan 7
  {
  float locationX = 1.928 + (_t - 0.003273) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.631 - (_t - 0.003273) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003819  && _t <= 0.004364) //scan 8
  {
  float locationX = 2.679 - (_t - 0.003819) * 1200 * cos(45 * 3.14159 / 180);
  float locationY = 0.169 + (_t - 0.003819) * 1200 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_Ti64_760_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
