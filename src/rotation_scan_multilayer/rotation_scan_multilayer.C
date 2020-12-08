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

#include "rotation_scan_multilayer.h"

template <>
InputParameters
validParams<rotation_scan_multilayer>()
{
  InputParameters params = validParams<DiracKernel>();
  params.addRequiredParam<Real>("value", "The value of the point source");
  params.addRequiredParam<Point>("point", "The x,y,z coordinates of the point");
  return params;
}

rotation_scan_multilayer::rotation_scan_multilayer(const InputParameters & parameters)
  : DiracKernel(parameters), _value(getParam<Real>("value")), _point(getParam<Point>("point"))
{
}

// The process parameters are 960 mm/s and 285 W Hatch = 110 µm
void
rotation_scan_multilayer::addPoints()
{
  // Add a point from the input file
  // layer 1
  if (_t <= 0.003) //scan 1
  {
  float locationX = _t * 960 + 0.06;
  float locationY = 0.07;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.003  && _t <= 0.006) //scan 2
  {
  float locationX = - (_t - 0.003) * 960 + 2.94;
  float locationY = 0.18;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.006  && _t <= 0.009) //scan 3
  {
  float locationX = (_t - 0.006) * 960 + 0.06;
  float locationY = 0.29;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.009  && _t <= 0.012) //scan 4
  {
  float locationX = - (_t - 0.009) * 960 + 2.94;
  float locationY = 0.4;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.012  && _t <= 0.015) //scan 5
  {
  float locationX = (_t - 0.012) * 960 + 0.06;
  float locationY = 0.51;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.015  && _t <= 0.018) //scan 6
  {
  float locationX = - (_t - 0.015) * 960 + 2.94;
  float locationY = 0.62;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.018  && _t <= 0.021) //scan 7
  {
  float locationX = (_t - 0.018) * 960 + 0.06;
  float locationY = 0.73;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.021  && _t <= 0.024) //scan 8
  {
  float locationX = - (_t - 0.021) * 960 + 2.94;
  float locationY = 0.84;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.024  && _t <= 0.027) //scan 9
  {
  float locationX = (_t - 0.024) * 960 + 0.06;
  float locationY = 0.95;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.027  && _t <= 0.030) //scan 10
  {
  float locationX = - (_t - 0.027) * 960 + 2.94;
  float locationY = 1.06;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.030  && _t <= 0.033) //scan 11
  {
  float locationX = (_t - 0.030) * 960 + 0.06;
  float locationY = 1.17;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.033  && _t <= 0.036) //scan 12
  {
  float locationX = - (_t - 0.033) * 960 + 2.94;
  float locationY = 1.28;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.036  && _t <= 0.039) //scan 13
  {
  float locationX = (_t - 0.036) * 960 + 0.06;
  float locationY = 1.39;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.039  && _t <= 0.042) //scan 14
  {
  float locationX = - (_t - 0.039) * 960 + 2.94;
  float locationY = 1.5;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.042  && _t <= 0.045) //scan 15
  {
  float locationX = (_t - 0.042) * 960 + 0.06;
  float locationY = 1.61;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.045  && _t <= 0.048) //scan 16
  {
  float locationX = - (_t - 0.045) * 960 + 2.94;
  float locationY = 1.72;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.048  && _t <= 0.051) //scan 17
  {
  float locationX = (_t - 0.048) * 960 + 0.06;
  float locationY = 1.83;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.051  && _t <= 0.054) //scan 18
  {
  float locationX = - (_t - 0.051) * 960 + 2.94;
  float locationY = 1.94;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.054  && _t <= 0.057) //scan 19
  {
  float locationX = (_t - 0.054) * 960 + 0.06;
  float locationY = 2.05;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.057  && _t <= 0.060) //scan 20
  {
  float locationX = - (_t - 0.057) * 960 + 2.94;
  float locationY = 2.16;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.060  && _t <= 0.063) //scan 21
  {
  float locationX = (_t - 0.060) * 960 + 0.06;
  float locationY = 2.27;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.063  && _t <= 0.066) //scan 22
  {
  float locationX = - (_t - 0.063) * 960 + 2.94;
  float locationY = 2.38;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.066  && _t <= 0.069) //scan 23
  {
  float locationX = (_t - 0.066) * 960 + 0.06;
  float locationY = 2.49;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.069  && _t <= 0.072) //scan 24
  {
  float locationX = - (_t - 0.069) * 960 + 2.94;
  float locationY = 2.6;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.072  && _t <= 0.075) //scan 25
  {
  float locationX = (_t - 0.072) * 960 + 0.06;
  float locationY = 2.71;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.075  && _t <= 0.078) //scan 26
  {
  float locationX = - (_t - 0.075) * 960 + 2.94;
  float locationY = 2.82;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else
  if (_t > 0.078  && _t <= 0.081) //scan 27
  {
  float locationX = (_t - 0.078) * 960 + 0.06;
  float locationY = 2.93;
  Point custom_point(locationX, locationY, 0.232);
  addPoint(custom_point);
  }
  else

  //layer 2
  if (_t > 0.081  && _t <= 0.084) //scan 1
  {
  float locationY =(_t - 0.081) * 960 + 0.06;
  float locationX = 0.07;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.084  && _t <= 0.087) //scan 2
  {
  float locationY = - (_t - 0.084) * 960 + 2.94;
  float locationX = 0.18;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.087  && _t <= 0.090) //scan 3
  {
  float locationY = (_t - 0.087) * 960 + 0.06;
  float locationX = 0.29;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.090  && _t <= 0.093) //scan 4
  {
  float locationY = - (_t - 0.090) * 960 + 2.94;
  float locationX = 0.4;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.093  && _t <= 0.096) //scan 5
  {
  float locationY = (_t - 0.093) * 960 + 0.06;
  float locationX = 0.51;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.096  && _t <= 0.099) //scan 6
  {
  float locationY = - (_t - 0.096) * 960 + 2.94;
  float locationX = 0.62;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.099  && _t <= 0.102) //scan 7
  {
  float locationY = (_t - 0.099) * 960 + 0.06;
  float locationX = 0.73;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.102  && _t <= 0.105) //scan 8
  {
  float locationY = - (_t - 0.102) * 960 + 2.94;
  float locationX = 0.84;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.105  && _t <= 0.108) //scan 9
  {
  float locationY = (_t - 0.105) * 960 + 0.06;
  float locationX = 0.95;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.108  && _t <= 0.111) //scan 10
  {
  float locationY = - (_t - 0.108) * 960 + 2.94;
  float locationX = 1.06;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.111  && _t <= 0.114) //scan 11
  {
  float locationY = (_t - 0.111) * 960 + 0.06;
  float locationX = 1.17;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.114  && _t <= 0.117) //scan 12
  {
  float locationY = - (_t - 0.114) * 960 + 2.94;
  float locationX = 1.28;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.117  && _t <= 0.120) //scan 13
  {
  float locationY = (_t - 0.117) * 960 + 0.06;
  float locationX = 1.39;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.120  && _t <= 0.123) //scan 14
  {
  float locationY = - (_t - 0.120) * 960 + 2.94;
  float locationX = 1.5;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.123  && _t <= 0.126) //scan 15
  {
  float locationY = (_t - 0.123) * 960 + 0.06;
  float locationX = 1.61;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.126  && _t <= 0.129) //scan 16
  {
  float locationY = - (_t - 0.126) * 960 + 2.94;
  float locationX = 1.72;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.129  && _t <= 0.132) //scan 17
  {
  float locationY = (_t - 0.129) * 960 + 0.06;
  float locationX = 1.83;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.132  && _t <= 0.135) //scan 18
  {
  float locationY = - (_t - 0.132) * 960 + 2.94;
  float locationX = 1.94;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.135  && _t <= 0.138) //scan 19
  {
  float locationY = (_t - 0.135) * 960 + 0.06;
  float locationX = 2.05;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.138  && _t <= 0.141) //scan 20
  {
  float locationY = - (_t - 0.138) * 960 + 2.94;
  float locationX = 2.16;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.141  && _t <= 0.144) //scan 21
  {
  float locationY = (_t - 0.141) * 960 + 0.06;
  float locationX = 2.27;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.144  && _t <= 0.147) //scan 22
  {
  float locationY = - (_t - 0.144) * 960 + 2.94;
  float locationX = 2.38;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.147  && _t <= 0.150) //scan 23
  {
  float locationY = (_t - 0.147) * 960 + 0.06;
  float locationX = 2.49;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.150  && _t <= 0.153) //scan 24
  {
  float locationY = - (_t - 0.150) * 960 + 2.94;
  float locationX = 2.6;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.153  && _t <= 0.156) //scan 25
  {
  float locationY = (_t - 0.153) * 960 + 0.06;
  float locationX = 2.71;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.156  && _t <= 0.159) //scan 26
  {
  float locationY = - (_t - 0.156) * 960 + 2.94;
  float locationX = 2.82;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else
  if (_t > 0.159  && _t <= 0.162) //scan 27
  {
  float locationY = (_t - 0.159) * 960 + 0.06;
  float locationX = 2.93;
  Point custom_point(locationX, locationY, 0.272);
  addPoint(custom_point);
  }
  else

  //layer3
  if (_t > 0.162  && _t <= 0.165) //scan 1
  {
  float locationX = - (_t - 0.162) * 960 + 2.94;
  float locationY = 0.07;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.165  && _t <= 0.168) //scan 2
  {
  float locationX = (_t - 0.165) * 960 + 0.06;
  float locationY = 0.18;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.168  && _t <= 0.171) //scan 3
  {
  float locationX = - (_t - 0.168) * 960 + 2.94;
  float locationY = 0.29;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.171  && _t <= 0.174) //scan 4
  {
  float locationX = (_t - 0.171) * 960 + 0.06;
  float locationY = 0.4;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.174  && _t <= 0.177) //scan 5
  {
  float locationX = - (_t - 0.174) * 960 + 2.94;
  float locationY = 0.51;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.177  && _t <= 0.180) //scan 6
  {
  float locationX = (_t - 0.177) * 960 + 0.06;
  float locationY = 0.62;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.180  && _t <= 0.183) //scan 7
  {
  float locationX = - (_t - 0.180) * 960 + 2.94;
  float locationY = 0.73;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.183  && _t <= 0.186) //scan 8
  {
  float locationX = (_t - 0.183) * 960 + 0.06;
  float locationY = 0.84;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.186  && _t <= 0.189) //scan 9
  {
  float locationX = - (_t - 0.186) * 960 + 2.94;
  float locationY = 0.95;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.189  && _t <= 0.192) //scan 10
  {
  float locationX = (_t - 0.189) * 960 + 0.06;
  float locationY = 1.06;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.192  && _t <= 0.195) //scan 11
  {
  float locationX = - (_t - 0.192) * 960 + 2.94;
  float locationY = 1.17;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.195  && _t <= 0.198) //scan 12
  {
  float locationX = (_t - 0.195) * 960 + 0.06;
  float locationY = 1.28;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.198  && _t <= 0.201) //scan 13
  {
  float locationX = - (_t - 0.198) * 960 + 2.94;
  float locationY = 1.39;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.201  && _t <= 0.204) //scan 14
  {
  float locationX = (_t - 0.201) * 960 + 0.06;
  float locationY = 1.5;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.204  && _t <= 0.207) //scan 15
  {
  float locationX = - (_t - 0.204) * 960 + 2.94;
  float locationY = 1.61;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.207  && _t <= 0.210) //scan 16
  {
  float locationX = (_t - 0.207) * 960 + 0.06;
  float locationY = 1.72;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.210  && _t <= 0.213) //scan 17
  {
  float locationX = - (_t - 0.210) * 960 + 2.94;
  float locationY = 1.83;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.213  && _t <= 0.216) //scan 18
  {
  float locationX = (_t - 0.213) * 960 + 0.06;
  float locationY = 1.94;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.216  && _t <= 0.219) //scan 19
  {
  float locationX = - (_t - 0.216) * 960 + 2.94;
  float locationY = 2.05;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.219  && _t <= 0.222) //scan 20
  {
  float locationX = (_t - 0.219) * 960 + 0.06;
  float locationY = 2.16;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.222  && _t <= 0.225) //scan 21
  {
  float locationX = - (_t - 0.222) * 960 + 2.94;
  float locationY = 2.27;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.225  && _t <= 0.228) //scan 22
  {
  float locationX = (_t - 0.225) * 960 + 0.06;
  float locationY = 2.38;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.228  && _t <= 0.231) //scan 23
  {
  float locationX = - (_t - 0.228) * 960 + 2.94;
  float locationY = 2.49;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.231  && _t <= 0.234) //scan 24
  {
  float locationX = (_t - 0.231) * 960 + 0.06;
  float locationY = 2.6;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.234  && _t <= 0.237) //scan 25
  {
  float locationX = - (_t - 0.234) * 960 + 2.94;
  float locationY = 2.71;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.237  && _t <= 0.240) //scan 26
  {
  float locationX = (_t - 0.237) * 960 + 0.06;
  float locationY = 2.82;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else
  if (_t > 0.240  && _t <= 0.243) //scan 27
  {
  float locationX = - (_t - 0.240) * 960 + 2.94;
  float locationY = 2.93;
  Point custom_point(locationX, locationY, 0.312);
  addPoint(custom_point);
  }
  else

  //layer 4
  if (_t > 0.243  && _t <= 0.246) //scan 1
  {
  float locationY = - (_t - 0.243) * 960 + 2.94;
  float locationX = 0.07;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.246  && _t <= 0.249) //scan 2
  {
  float locationY = (_t - 0.246) * 960 + 0.06;
  float locationX = 0.18;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.249  && _t <= 0.252) //scan 3
  {
  float locationY = - (_t - 0.249) * 960 + 2.94;
  float locationX = 0.29;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.252  && _t <= 0.255) //scan 4
  {
  float locationY = (_t - 0.252) * 960 + 0.06;
  float locationX = 0.4;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.255  && _t <= 0.258) //scan 5
  {
  float locationY = - (_t - 0.255) * 960 + 2.94;
  float locationX = 0.51;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.258  && _t <= 0.261) //scan 6
  {
  float locationY = (_t - 0.258) * 960 + 0.06;
  float locationX = 0.62;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.261  && _t <= 0.264) //scan 7
  {
  float locationY = - (_t - 0.261) * 960 + 2.94;
  float locationX = 0.73;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.264  && _t <= 0.267) //scan 8
  {
  float locationY = (_t - 0.264) * 960 + 0.06;
  float locationX = 0.84;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.267  && _t <= 0.270) //scan 9
  {
  float locationY = - (_t - 0.267) * 960 + 2.94;
  float locationX = 0.95;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.270  && _t <= 0.273) //scan 10
  {
  float locationY = (_t - 0.270) * 960 + 0.06;
  float locationX = 1.06;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.273  && _t <= 0.276) //scan 11
  {
  float locationY = - (_t - 0.273) * 960 + 2.94;
  float locationX = 1.17;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.276  && _t <= 0.279) //scan 12
  {
  float locationY = (_t - 0.276) * 960 + 0.06;
  float locationX = 1.28;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.279  && _t <= 0.282) //scan 13
  {
  float locationY = - (_t - 0.279) * 960 + 2.94;
  float locationX = 1.39;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.282  && _t <= 0.285) //scan 14
  {
  float locationY = (_t - 0.282) * 960 + 0.06;
  float locationX = 1.5;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.285  && _t <= 0.288) //scan 15
  {
  float locationY = - (_t - 0.285) * 960 + 2.94;
  float locationX = 1.61;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.288  && _t <= 0.291) //scan 16
  {
  float locationY = (_t - 0.288) * 960 + 0.06;
  float locationX = 1.72;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.291  && _t <= 0.294) //scan 17
  {
  float locationY = - (_t - 0.291) * 960 + 2.94;
  float locationX = 1.83;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.294  && _t <= 0.297) //scan 18
  {
  float locationY = (_t - 0.294) * 960 + 0.06;
  float locationX = 1.94;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.297  && _t <= 0.300) //scan 19
  {
  float locationY = - (_t - 0.297) * 960 + 2.94;
  float locationX = 2.05;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.300  && _t <= 0.303) //scan 20
  {
  float locationY = (_t - 0.300) * 960 + 0.06;
  float locationX = 2.16;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.303  && _t <= 0.306) //scan 21
  {
  float locationY = - (_t - 0.303) * 960 + 2.94;
  float locationX = 2.27;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.306  && _t <= 0.309) //scan 22
  {
  float locationY = (_t - 0.306) * 960 + 0.06;
  float locationX = 2.38;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.309  && _t <= 0.312) //scan 23
  {
  float locationY = - (_t - 0.309) * 960 + 2.94;
  float locationX = 2.49;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.312  && _t <= 0.315) //scan 24
  {
  float locationY = (_t - 0.312) * 960 + 0.06;
  float locationX = 2.6;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.315  && _t <= 0.318) //scan 25
  {
  float locationY = - (_t - 0.315) * 960 + 2.94;
  float locationX = 2.71;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.318  && _t <= 0.321) //scan 26
  {
  float locationY = (_t - 0.318) * 960 + 0.06;
  float locationX = 2.82;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else
  if (_t > 0.321  && _t <= 0.324) //scan 27
  {
  float locationY = - (_t - 0.321) * 960 + 2.94;
  float locationX = 2.93;
  Point custom_point(locationX, locationY, 0.352);
  addPoint(custom_point);
  }
  else

  //layer5
  if (_t > 0.324  && _t <= 0.327) //scan 1
  {
  float locationX = (_t - 0.324) * 960 + 0.06;
  float locationY = 0.07;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.327  && _t <= 0.330) //scan 2
  {
  float locationX = - (_t - 0.327) * 960 + 2.94;
  float locationY = 0.18;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.330  && _t <= 0.333) //scan 3
  {
  float locationX = (_t - 0.330) * 960 + 0.06;
  float locationY = 0.29;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.333  && _t <= 0.336) //scan 4
  {
  float locationX = - (_t - 0.333) * 960 + 2.94;
  float locationY = 0.4;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.336  && _t <= 0.339) //scan 5
  {
  float locationX = (_t - 0.336) * 960 + 0.06;
  float locationY = 0.51;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.339  && _t <= 0.342) //scan 6
  {
  float locationX = - (_t - 0.339) * 960 + 2.94;
  float locationY = 0.62;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.342  && _t <= 0.345) //scan 7
  {
  float locationX = (_t - 0.342) * 960 + 0.06;
  float locationY = 0.73;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.345  && _t <= 0.348) //scan 8
  {
  float locationX = - (_t - 0.345) * 960 + 2.94;
  float locationY = 0.84;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.348  && _t <= 0.351) //scan 9
  {
  float locationX = (_t - 0.348) * 960 + 0.06;
  float locationY = 0.95;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.351  && _t <= 0.354) //scan 10
  {
  float locationX = - (_t - 0.351) * 960 + 2.94;
  float locationY = 1.06;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.354  && _t <= 0.357) //scan 11
  {
  float locationX = (_t - 0.354) * 960 + 0.06;
  float locationY = 1.17;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.357  && _t <= 0.360) //scan 12
  {
  float locationX = - (_t - 0.357) * 960 + 2.94;
  float locationY = 1.28;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.360  && _t <= 0.363) //scan 13
  {
  float locationX = (_t - 0.360) * 960 + 0.06;
  float locationY = 1.39;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.363  && _t <= 0.366) //scan 14
  {
  float locationX = - (_t - 0.363) * 960 + 2.94;
  float locationY = 1.5;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.366  && _t <= 0.369) //scan 15
  {
  float locationX = (_t - 0.366) * 960 + 0.06;
  float locationY = 1.61;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.369  && _t <= 0.372) //scan 16
  {
  float locationX = - (_t - 0.369) * 960 + 2.94;
  float locationY = 1.72;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.372  && _t <= 0.375) //scan 17
  {
  float locationX = (_t - 0.372) * 960 + 0.06;
  float locationY = 1.83;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.375  && _t <= 0.378) //scan 18
  {
  float locationX = - (_t - 0.375) * 960 + 2.94;
  float locationY = 1.94;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.378  && _t <= 0.381) //scan 19
  {
  float locationX = (_t - 0.378) * 960 + 0.06;
  float locationY = 2.05;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.381  && _t <= 0.384) //scan 20
  {
  float locationX = - (_t - 0.381) * 960 + 2.94;
  float locationY = 2.16;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.384  && _t <= 0.387) //scan 21
  {
  float locationX = (_t - 0.384) * 960 + 0.06;
  float locationY = 2.27;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.387  && _t <= 0.390) //scan 22
  {
  float locationX = - (_t - 0.387) * 960 + 2.94;
  float locationY = 2.38;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.390  && _t <= 0.393) //scan 23
  {
  float locationX = (_t - 0.390) * 960 + 0.06;
  float locationY = 2.49;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.393  && _t <= 0.396) //scan 24
  {
  float locationX = - (_t - 0.393) * 960 + 2.94;
  float locationY = 2.6;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.396  && _t <= 0.399) //scan 25
  {
  float locationX = (_t - 0.396) * 960 + 0.06;
  float locationY = 2.71;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.399  && _t <= 0.402) //scan 26
  {
  float locationX = - (_t - 0.399) * 960 + 2.94;
  float locationY = 2.82;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
  else
  if (_t > 0.402  && _t <= 0.405) //scan 27
  {
  float locationX = (_t - 0.402) * 960 + 0.06;
  float locationY = 2.93;
  Point custom_point(locationX, locationY, 0.392);
  addPoint(custom_point);
  }
}

Real
rotation_scan_multilayer::computeQpResidual()
{
  // This is negative because it's a forcing function that has been brought over to the left side
  return -_test[_i][_qp] * _value;
}
