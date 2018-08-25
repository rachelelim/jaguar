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

#include "MovingDirac3d_overhang_a.h"

template <>
InputParameters
validParams<MovingDirac3d_overhang_a>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3d_overhang_a::MovingDirac3d_overhang_a(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

// The process parameters are 200 mm/s and 50W Hatch = 100 µm
void
MovingDirac3d_overhang_a::addPoints()
{
  // Add a point from the input file
  // layer 1
  if (_t <= 0.014) //scan 1
  {
  float locationX = _t * 200 + 0.1;
  float locationY = 0.1;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.014  && _t <= 0.028) //scan 2
  {
  float locationX = (_t - 0.014) * 200 + 0.1;
  float locationY = 0.2;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.028  && _t <= 0.042) //scan 3
  {
  float locationX = (_t - 0.028) * 200 + 0.1;
  float locationY = 0.3;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.042  && _t <= 0.056) //scan 4
  {
  float locationX = (_t - 0.042) * 200 + 0.1;
  float locationY = 0.4;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.056  && _t <= 0.070) //scan 5
  {
  float locationX = (_t - 0.056) * 200 + 0.1;
  float locationY = 0.5;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.070  && _t <= 0.084) //scan 6
  {
  float locationX = (_t - 0.070) * 200 + 0.1;
  float locationY = 0.6;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.084  && _t <= 0.098) //scan 7
  {
  float locationX = (_t - 0.084) * 200 + 0.1;
  float locationY = 0.7;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.098  && _t <= 0.112) //scan 8
  {
  float locationX = (_t - 0.098) * 200 + 0.1;
  float locationY = 0.8;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.112  && _t <= 0.126) //scan 9
  {
  float locationX = (_t - 0.112) * 200 + 0.1;
  float locationY = 0.9;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.126  && _t <= 0.140) //scan 10
  {
  float locationX = (_t - 0.126) * 200 + 0.1;
  float locationY = 1.0;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.140  && _t <= 0.154) //scan 11
  {
  float locationX = (_t - 0.140) * 200 + 0.1;
  float locationY = 1.1;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.154  && _t <= 0.168) //scan 12
  {
  float locationX = (_t - 0.154) * 200 + 0.1;
  float locationY = 1.2;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.168  && _t <= 0.182) //scan 13
  {
  float locationX = (_t - 0.168) * 200 + 0.1;
  float locationY = 1.3;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.182  && _t <= 0.196) //scan 14
  {
  float locationX = (_t - 0.182) * 200 + 0.1;
  float locationY = 1.4;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.196  && _t <= 0.210) //scan 15
  {
  float locationX = (_t - 0.196) * 200 + 0.1;
  float locationY = 1.5;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.210  && _t <= 0.224) //scan 16
  {
  float locationX = (_t - 0.210) * 200 + 0.1;
  float locationY = 1.6;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.224  && _t <= 0.238) //scan 17
  {
  float locationX = (_t - 0.224) * 200 + 0.1;
  float locationY = 1.7;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.238  && _t <= 0.252) //scan 18
  {
  float locationX = (_t - 0.238) * 200 + 0.1;
  float locationY = 1.8;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.252  && _t <= 0.266) //scan 19
  {
  float locationX = (_t - 0.252) * 200 + 0.1;
  float locationY = 1.9;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.266  && _t <= 0.280) //scan 20
  {
  float locationX = (_t - 0.266) * 200 + 0.1;
  float locationY = 2.0;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.280  && _t <= 0.294) //scan 21
  {
  float locationX = (_t - 0.280) * 200 + 0.1;
  float locationY = 2.1;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.294  && _t <= 0.308) //scan 22
  {
  float locationX = (_t - 0.294) * 200 + 0.1;
  float locationY = 2.2;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.308  && _t <= 0.322) //scan 23
  {
  float locationX = (_t - 0.308) * 200 + 0.1;
  float locationY = 2.3;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.322  && _t <= 0.336) //scan 24
  {
  float locationX = (_t - 0.322) * 200 + 0.1;
  float locationY = 2.4;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.336  && _t <= 0.350) //scan 25
  {
  float locationX = (_t - 0.336) * 200 + 0.1;
  float locationY = 2.5;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.350  && _t <= 0.364) //scan 26
  {
  float locationX = (_t - 0.350) * 200 + 0.1;
  float locationY = 2.6;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.364  && _t <= 0.378) //scan 27
  {
  float locationX = (_t - 0.364) * 200 + 0.1;
  float locationY = 2.7;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.378  && _t <= 0.392) //scan 28
  {
  float locationX = (_t - 0.378) * 200 + 0.1;
  float locationY = 2.8;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  if (_t > 0.392  && _t <= 0.406) //scan 29
  {
  float locationX = (_t - 0.392) * 200 + 0.1;
  float locationY = 2.9;
  Point custom_point(locationX, locationY, 0.2);
  addPoint(custom_point);
  }
  else
  //layer 2
  if (_t > 0.406  && _t <= 0.420) //scan 1
  {
  float locationY = (_t - 0.406) * 200 + 0.1;
  float locationX = 0.1;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.420  && _t <= 0.434) //scan 2
  {
  float locationY = (_t - 0.420) * 200 + 0.1;
  float locationX = 0.2;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.434  && _t <= 0.448) //scan 3
  {
  float locationY = (_t - 0.434) * 200 + 0.1;
  float locationX = 0.3;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.448  && _t <= 0.462) //scan 4
  {
  float locationY = (_t - 0.448) * 200 + 0.1;
  float locationX = 0.4;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.462  && _t <= 0.476) //scan 5
  {
  float locationY = (_t - 0.462) * 200 + 0.1;
  float locationX = 0.5;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.476  && _t <= 0.490) //scan 6
  {
  float locationY = (_t - 0.476) * 200 + 0.1;
  float locationX = 0.6;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.490  && _t <= 0.504) //scan 7
  {
  float locationY = (_t - 0.490) * 200 + 0.1;
  float locationX = 0.7;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.504  && _t <= 0.518) //scan 8
  {
  float locationY = (_t - 0.504) * 200 + 0.1;
  float locationX = 0.8;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.518  && _t <= 0.532) //scan 9
  {
  float locationY = (_t - 0.518) * 200 + 0.1;
  float locationX = 0.9;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.532  && _t <= 0.546) //scan 10
  {
  float locationY = (_t - 0.532) * 200 + 0.1;
  float locationX = 1.0;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  if (_t > 0.546  && _t <= 0.560) //scan 11
  {
  float locationY = (_t - 0.546) * 200 + 0.1;
  float locationX = 1.1;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.560  && _t <= 0.574) //scan 12
  {
  float locationY = (_t - 0.560) * 200 + 0.1;
  float locationX = 1.2;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.574  && _t <= 0.588) //scan 13
  {
  float locationY = (_t - 0.574) * 200 + 0.1;
  float locationX = 1.3;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.588  && _t <= 0.602) //scan 14
  {
  float locationY = (_t - 0.588) * 200 + 0.1;
  float locationX = 1.4;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.602  && _t <= 0.616) //scan 15
  {
  float locationY = (_t - 0.602) * 200 + 0.1;
  float locationX = 1.5;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.616  && _t <= 0.630) //scan 16
  {
  float locationY = (_t - 0.616) * 200 + 0.1;
  float locationX = 1.6;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.630  && _t <= 0.644) //scan 17
  {
  float locationY = (_t - 0.630) * 200 + 0.1;
  float locationX = 1.7;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.644  && _t <= 0.658) //scan 18
  {
  float locationY = (_t - 0.644) * 200 + 0.1;
  float locationX = 1.8;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.658  && _t <= 0.672) //scan 19
  {
  float locationY = (_t - 0.658) * 200 + 0.1;
  float locationX = 1.9;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.672  && _t <= 0.686) //scan 20
  {
  float locationY = (_t - 0.672) * 200 + 0.1;
  float locationX = 2.0;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  if (_t > 0.686  && _t <= 0.700) //scan 21
  {
  float locationY = (_t - 0.686) * 200 + 0.1;
  float locationX = 2.1;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.700  && _t <= 0.714) //scan 22
  {
  float locationY = (_t - 0.700) * 200 + 0.1;
  float locationX = 2.2;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.714  && _t <= 0.728) //scan 23
  {
  float locationY = (_t - 0.714) * 200 + 0.1;
  float locationX = 2.3;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.728  && _t <= 0.742) //scan 24
  {
  float locationY = (_t - 0.728) * 200 + 0.1;
  float locationX = 2.4;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.742  && _t <= 0.756) //scan 25
  {
  float locationY = (_t - 0.742) * 200 + 0.1;
  float locationX = 2.5;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.756  && _t <= 0.770) //scan 26
  {
  float locationY = (_t - 0.756) * 200 + 0.1;
  float locationX = 2.6;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.770  && _t <= 0.784) //scan 27
  {
  float locationY = (_t - 0.770) * 200 + 0.1;
  float locationX = 2.7;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.784  && _t <= 0.798) //scan 28
  {
  float locationY = (_t - 0.784) * 200 + 0.1;
  float locationX = 2.8;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
  else
  if (_t > 0.798  && _t <= 0.812) //scan 29
  {
  float locationY = (_t - 0.798) * 200 + 0.1;
  float locationX = 2.9;
  Point custom_point(locationX, locationY, 0.23);
  addPoint(custom_point);
  }
}

Real
MovingDirac3d_overhang_a::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
