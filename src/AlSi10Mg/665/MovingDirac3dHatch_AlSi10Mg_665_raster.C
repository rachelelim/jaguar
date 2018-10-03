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

#include "MovingDirac3dHatch_AlSi10Mg_665_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_AlSi10Mg_665_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_AlSi10Mg_665_raster::MovingDirac3dHatch_AlSi10Mg_665_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_AlSi10Mg_665_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000332398) //scan 1
  {
  float locationX = 0.2 + _t  * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.553 - _t * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
}
  else
  if (_t > 0.000332398  && _t <= 0.000665) //scan 2
  {
  float locationX = 0.692 - (_t - 0.000332398) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.247 + (_t - 0.000332398) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000665  && _t <= 0.000997) //scan 3
  {
  float locationX = 0.574 + (_t - 0.000665) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.553 - (_t - 0.000665) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.000997  && _t <= 0.001330) //scan 4
  {
  float locationX = 1.066 - (_t - 0.000997) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.247 + (_t - 0.000997) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001330  && _t <= 0.001662) //scan 5
  {
  float locationX = 0.948 + (_t - 0.001330) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.553 - (_t - 0.001330) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001662  && _t <= 0.001994) //scan 6
  {
  float locationX = 1.44 - (_t - 0.001662) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.247 + (_t - 0.001662) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001994  && _t <= 0.002327) //scan 7
  {
  float locationX = 1.322 + (_t - 0.001994) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.553 - (_t - 0.001994) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002327  && _t <= 0.002659) //scan 8
  {
  float locationX = 1.815 - (_t - 0.002327) * 960 * cos(45 * 3.14159 / 180);
  float locationY = 0.247 + (_t - 0.002327) * 960 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_AlSi10Mg_665_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
