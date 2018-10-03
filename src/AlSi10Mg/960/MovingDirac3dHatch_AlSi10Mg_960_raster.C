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

#include "MovingDirac3dHatch_AlSi10Mg_960_raster.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_AlSi10Mg_960_raster>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_AlSi10Mg_960_raster::MovingDirac3dHatch_AlSi10Mg_960_raster(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_AlSi10Mg_960_raster::addPoints()
{
  // Add a point from the input file
  if (_t <= 0.000645) //scan 1
  {
  float locationX = 0.2 + _t  * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6964 - _t * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
}
  else
  if (_t > 0.000645  && _t <= 0.001290) //scan 2
  {
  float locationX = 0.980 - (_t - 0.000645) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1036 + (_t - 0.000645) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001290  && _t <= 0.001935) //scan 3
  {
  float locationX = 0.574 + (_t - 0.001290) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6964 - (_t - 0.001290) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.001935  && _t <= 0.002580) //scan 4
  {
  float locationX = 1.354 - (_t - 0.001935) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1036 + (_t - 0.001935) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.002580  && _t <= 0.003225) //scan 5
  {
  float locationX = 0.948 + (_t - 0.002580) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6964 - (_t - 0.002580) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003225  && _t <= 0.003870) //scan 6
  {
  float locationX = 1.728 - (_t - 0.003225) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1036 + (_t - 0.003225) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003870  && _t <= 0.004515) //scan 7
  {
  float locationX = 1.322 + (_t - 0.003870) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.6964 - (_t - 0.003870) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.004515  && _t <= 0.005160) //scan 8
  {
  float locationX = 2.102 - (_t - 0.004515) * 1300 * cos(45 * 3.14159 / 180);
  float locationY = 0.1036 + (_t - 0.004515) * 1300 * sin(45 * 3.14159 / 180);
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_AlSi10Mg_960_raster::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
