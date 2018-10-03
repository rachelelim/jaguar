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

#include "MovingDirac3dHatch_AlSi10Mg_960_contour1.h"

template <>
InputParameters
validParams<MovingDirac3dHatch_AlSi10Mg_960_contour1>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

MovingDirac3dHatch_AlSi10Mg_960_contour1::MovingDirac3dHatch_AlSi10Mg_960_contour1(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

void
MovingDirac3dHatch_AlSi10Mg_960_contour1::addPoints()
{
  if (_t <= 0.005160) //Before contour1 scan
  {
  float locationX = 0;
  float locationY = 0;
  Point custom_point(locationX, locationY, 0);
  addPoint(custom_point);
  }
  else
  if (_t > 0.005160  && _t <= 0.005774322) //contour1 scan 1 offset: 0.02 mm
  {
  float locationX = 0.22;
  float locationY = 0.6464 - (_t - 0.005160) * 900;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.005774322  && _t <= 0.007843211) //contour1 scan 2 offset: 0.02 mm
  {
  float locationX = 0.22 + (_t - 0.005774322) * 900;
  float locationY = 0.1236;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.007843211  && _t <= 0.008457533) //contour1 scan 3 offset: 0.02 mm
  {
  float locationX = 2.082;
  float locationY = 0.1236 + (_t - 0.007843211) * 900;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
  else
  if (_t > 0.008457533  && _t <= 0.010526422) //contour1 scan 4 offset: 0.02 mm
  {
  float locationX = 2.082 - (_t - 0.008457533) * 900;
  float locationY = 0.6464;
  Point custom_point(locationX, locationY, 0.495);
  addPoint(custom_point);
  }
}

Real
MovingDirac3dHatch_AlSi10Mg_960_contour1::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
